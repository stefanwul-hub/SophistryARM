#!/usr/bin/env python3
"""Emit a large static lift as bounded C++ compilation units, with no x86 decoder."""
import argparse,array,bisect,collections,gzip,hashlib,json,re
from pathlib import Path
from lift_pcode_cpp import emit,SHA
def rows(path,additions=None,exclusions=None):
 excluded=set();found=set()
 if exclusions:
  correction=json.loads(exclusions.read_text())
  if correction['original_sha256']!=SHA:raise ValueError('Wrong listing-correction provenance')
  excluded={int(a,0) for a in correction['addresses']}
 extra={}
 if additions:
  for line in additions.read_bytes().splitlines(keepends=True):
   ins=json.loads(line);address=int(ins['address'],16)
   if address in extra:raise ValueError('Duplicate additional instruction')
   if address in excluded:raise ValueError('An instruction cannot be both added and excluded')
   extra[address]=(line,ins)
 opener=gzip.open if path.suffix=='.gz' else open
 with opener(path,'rb') as f:
  for line in f:
   if line.strip():
    ins=json.loads(line);address=int(ins['address'],16)
    if address in excluded:found.add(address);continue
    if address in extra:raise ValueError('Additional instruction overlaps base archive')
    for pc in sorted(list(extra)):
     if pc<address:yield extra.pop(pc)
    yield line,ins
 for pc in sorted(extra):yield extra[pc]
 if found!=excluded:raise ValueError('Listing correction did not match the base instruction archive')
def generate(source,output,chunk_size,layout=None,update=False,additions=None,exclusions=None):
 provenance=json.loads((source.parent/'provenance.json').read_text())
 if provenance['sha256']!=SHA:raise ValueError('Wrong original binary provenance')
 if chunk_size<16 or chunk_size>2048:raise ValueError('Choose 16..2048 instructions per unit')
 output.mkdir(parents=True,exist_ok=True)
 if any(output.iterdir()) and not update:raise ValueError('Use a new, empty output directory')
 if update and (not layout or layout.resolve()!=(output/'manifest.json').resolve()):raise ValueError('Updates must reuse the existing output manifest layout')
 addresses=[];raw_hash=hashlib.sha256();last=-1;maxima={'register':0,'unique':0}
 for raw,ins in rows(source,additions,exclusions):
  address=int(ins['address'],16)
  if address<=last or address>=0x103000:raise ValueError('Unsorted, duplicate or import-stub address')
  addresses.append(address);last=address;raw_hash.update(raw)
  for op in ins['pcode']:
   for v in ([op['output']] if op['output'] else [])+op['inputs']:
    if v['space'] in maxima:maxima[v['space']]=max(maxima[v['space']],int(v['offset'],16)+v['size'])
 if not addresses:raise ValueError('No instructions')
 starts=None
 if layout:
  previous=json.loads(layout.read_text())
  starts=previous.get('layout_starts')
  if starts is None:
   starts=[]
   for i in range(previous['compilation_units']):
    with (layout.parent/f'Unit{i:04d}.cpp').open() as f:
     for line in f:
      match=re.search(r'case 0x([0-9a-f]+):goto',line)
      if match:starts.append(int(match[1],16));break
   if len(starts)!=previous['compilation_units']:raise ValueError('Cannot recover previous unit boundaries')
  starts[0]=0
  unit_for=lambda address,index:max(0,bisect.bisect_right(starts,address)-1)
  units=len(starts)
 else:
  units=(len(addresses)+chunk_size-1)//chunk_size
  starts=[addresses[i*chunk_size] for i in range(units)];starts[0]=0
  unit_for=lambda address,index:index//chunk_size
 if units>65535:raise ValueError('Unit map exceeds 16-bit index')
 pc_map=array.array('H',[0])*(addresses[-1]+1)
 for index,pc in enumerate(addresses):pc_map[pc]=unit_for(pc,index)+1
 names=[f'Unit{i:04d}.cpp' for i in range(units)];counts=collections.Counter();guards=[];sizes=[]
 def write_unit(index,instructions):
  known={int(i['address'],16) for i in instructions}
  lines=['// Generated static p-code lift; original i386 SHA-256: '+SHA,
         '#include "LifterRuntime.h"',f'int sl_unit_{index:04d}(SlCpu& c){{',
         'goto dispatch;','dispatch:','if(c.fault||c.pc==c.stop)return int(c.fault);','switch(c.pc){']
  lines += [f'case 0x{pc:x}:goto L_{pc:x};' for pc in sorted(known)]
  lines += ['default:return 0;}']
  for ins in instructions:
   addr=int(ins['address'],16)
   lines += [f'L_{addr:x}:{{ // {ins["asm"]}',f'c.pc=0x{addr:x};if(!sl_tick(c))return int(c.fault);']
   for j,op in enumerate(ins['pcode']):
    counts[op['op']]+=1
    if op['op']=='CALLOTHER':guards.append({'address':ins['address'],'asm':ins['asm'],'userop':op.get('userop')})
    lines += [f'P_{ins["address"]}_{j}:;',emit(ins,op,j,known)]
   lines += [f'P_{ins["address"]}_{len(ins["pcode"])}:;']
   next_pc=addr+ins['length']
   lines += [f'goto L_{next_pc:x};' if next_pc in known else f'c.pc=0x{next_pc:x};goto dispatch;','}']
  lines += ['}']
  path=output/names[index];text='\n'.join(lines)+'\n'
  if not update or not path.exists() or path.read_text()!=text:path.write_text(text)
  sizes.append(len(instructions))
 group=[];unit=0
 for index,(_,ins) in enumerate(rows(source,additions,exclusions)):
  key=unit_for(int(ins['address'],16),index)
  if key!=unit:
   write_unit(unit,group);group=[];unit=key
  group.append(ins)
 if group:write_unit(unit,group)
 dispatch=output/'Dispatch.cpp'
 with dispatch.open('w') as f:
  f.write('// Generated PC-to-compiled-unit lookup; no x86 opcode decoder.\n#include "LifterRuntime.h"\n')
  f.write(f'static_assert(sizeof(((SlCpu*)0)->reg)>={maxima["register"]},"register file too small");\n')
  f.write(f'static_assert(sizeof(((SlCpu*)0)->temp)>={maxima["unique"]},"temporary storage too small");\n')
  for i in range(units):f.write(f'int sl_unit_{i:04d}(SlCpu&);\n')
  f.write('static const unsigned short sl_pc_units[]={\n')
  for start in range(0,len(pc_map),32):f.write(','.join(str(x) for x in pc_map[start:start+32])+',\n')
  f.write('};\nusing SlUnit=int(*)(SlCpu&);\nstatic const SlUnit sl_units[]={\n')
  f.write(',\n'.join(f'sl_unit_{i:04d}' for i in range(units))+'\n};\n')
  f.write('''int sl_execute(SlCpu& c,SlU32 entry,SlU32 stop,SlU64 limit){
c.pc=entry;c.stop=stop;c.steps=0;c.limit=limit;c.fault=0;
for(;;){
 if(c.fault||c.pc==c.stop)return int(c.fault);
 unsigned unit=c.pc<sizeof(sl_pc_units)/sizeof(sl_pc_units[0])?sl_pc_units[c.pc]:0;
 if(unit){
  SlU32 previous=c.pc;SlU64 steps=c.steps;
  sl_units[unit-1](c);
  if(c.pc==previous&&c.steps==steps&&!c.fault&&c.pc!=c.stop){c.fault=3;return 3;}
  continue;
 }
 if(!sl_tick(c))return int(c.fault);
 bool handled=false;
 for(SlU32 h=0;h<c.hook_count;++h){
  if(c.hooks[h].address==c.pc){c.hooks[h].function(c.hooks[h].user,c.pc,&c);handled=true;break;}
 }
 if(!handled){c.fault=3;return 3;}
}
}
''')
 names.append('Dispatch.cpp')
 result={'scope':'Statically emitted detected internal instructions; emission is not whole-engine execution proof',
  'original_sha256':SHA,'input_raw_sha256':raw_hash.hexdigest(),'instruction_count':len(addresses),
  'additional_instructions_filename':additions.name if additions else None,
  'excluded_instruction_addresses':json.loads(exclusions.read_text())['addresses'] if exclusions else [],
  'pcode_operation_count':sum(counts.values()),'operation_counts':dict(counts),'compilation_units':units,
  'instructions_per_unit':sizes,'layout_starts':starts,'register_bytes_required':maxima['register'],'temporary_bytes_required':maxima['unique'],
  'pc_map_entries':len(pc_map),'x86_decoder_in_runtime':False,'terminal_guard_operations':guards,
  'full_engine_initialized':False,'full_preset_rendered':False,
  'limitations':['Host imports and initialization not implemented by code generation','Four detected instructions contain terminal trap/privileged-I/O or unsupported LOCK guards','Rounding fixed to nearest-even/default environment; full x86 exception state not modeled'],
  'generated_files':[{'name':n,'bytes':(output/n).stat().st_size,'sha256':hashlib.sha256((output/n).read_bytes()).hexdigest()} for n in names]}
 (output/'manifest.json').write_text(json.dumps(result,indent=2)+'\n')
 return result
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('source',type=Path);p.add_argument('output',type=Path);p.add_argument('--chunk-instructions',type=int,default=512);p.add_argument('--reuse-layout',type=Path);p.add_argument('--update',action='store_true');p.add_argument('--additions',type=Path);p.add_argument('--exclude-addresses',type=Path);n=p.parse_args()
 r=generate(n.source,n.output,n.chunk_instructions,n.reuse_layout,n.update,n.additions,n.exclude_addresses);print(json.dumps({k:r[k] for k in ['instruction_count','pcode_operation_count','compilation_units','terminal_guard_operations']},indent=2))
