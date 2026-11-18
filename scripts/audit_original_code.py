#!/usr/bin/env python3
"""Audit original executable coverage; static evidence is not exhaustive behavior proof."""
from pathlib import Path
import argparse,os
ROOT=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--switch-audit',type=Path,required=True);args=parser.parse_args();args.switch_audit=args.switch_audit.resolve();output=args.output.resolve();output.parent.mkdir(parents=True,exist_ok=True);os.chdir(ROOT)
import gzip,json,re,hashlib,collections,sys
from legacy_image import LegacyImage
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
p=output.parent;image=LegacyImage(Path('reference/Sophistry.i386').read_bytes());raw=bytes(image.mapped());known={};direct=[];fall=[];counts=collections.Counter()
from lift_pcode_chunks import rows
for _,j in rows(Path('analysis/lifter-full/instructions.jsonl.gz'),Path('analysis/lifter-full/integration-additions-cp032.jsonl'),Path('analysis/lifter-full/excluded-misaligned-cp032.json')):
 pc=int(j['address'],16);assert pc not in known;known[pc]=(j['length'],j['asm']);counts.update(o['op'] for o in j['pcode'])
 exit_always=False
 for o in j['pcode']:
  if o['op'] in ['BRANCH','CALL','CBRANCH'] and o['inputs'][0]['space']=='ram':direct.append({'from':hex(pc),'target':hex(int(o['inputs'][0]['offset'],16)),'kind':o['op']})
  if o['op'] in ['BRANCHIND','RETURN','CALLOTHER'] or o['op']=='BRANCH' and o['inputs'][0]['space']=='ram':exit_always=True
 if not exit_always:fall.append((pc,pc+j['length']))
imports={a for a in image.imports} if hasattr(image,'imports') else set()
layout=json.loads(Path('analysis/legacy-image-layout.json').read_text());fi=layout['function_imports'];print('Import metadata type',type(fi).__name__)
if isinstance(fi,list):
 for x in fi:
  for k in ['address','stub_address','stub']:
   if k in x:imports.add(int(str(x[k]),0) if str(x[k]).startswith('0x') else int(x[k]))
else:
 for k,v in fi.items():
  try:imports.add(int(k,0))
  except (ValueError,TypeError):pass
entries=[json.loads(line) for line in Path('analysis/ghidra/function-index.jsonl').read_text().splitlines() if line]
internal=[r for r in entries if int(r['address'],16)<0x103000];missing_functions=[r for r in internal if int(r['address'],16) not in known]
vtables=json.loads(Path('analysis/vtables.json').read_text());vt=set()
for group in vtables:
 for table in group['tables']:
  vt.update(int(v,0) for v in table['functions'] if v and int(v,0)<0x103000)
missing_vtables=sorted(v for v in vt if v not in known)
missing_direct=[r for r in direct if int(r['target'],16) not in known and int(r['target'],16) not in imports]
missing_fall=[{'from':hex(a),'target':hex(b),'asm':known[a][1]} for a,b in fall if b not in known and b not in imports]
md=Cs(CS_ARCH_X86,CS_MODE_32);bad=[]
for pc,(n,asm) in known.items():
 decoded=next(md.disasm(raw[pc:pc+n],pc,count=1),None)
 if not decoded or decoded.size!=n:bad.append({'pc':hex(pc),'ghidra_length':n,'asm':asm,'capstone':(decoded.mnemonic+' '+decoded.op_str) if decoded else None,'capstone_size':decoded.size if decoded else None})
compiled={}
for f in sorted(Path('src/lifter/whole').glob('Unit*.cpp')):
 for match in re.finditer(r'^L_([0-9a-f]+):',f.read_text(),re.M):
  pc=int(match[1],16);assert pc not in compiled;compiled[pc]=f.name
result={'source_sha256':hashlib.sha256(Path('reference/Sophistry.i386').read_bytes()).hexdigest(),'detected_instructions':len(known),'compiled_labels':len(compiled),'missing_emitted_labels':[hex(a) for a in sorted(set(known)-set(compiled))],'extra_labels':[hex(a) for a in sorted(set(compiled)-set(known))],'internal_functions_in_index':len(internal),'missing_function_entries':missing_functions,'vtable_internal_targets':len(vt),'missing_vtable_targets':[hex(v) for v in missing_vtables],'direct_edges':len(direct),'missing_direct_targets':missing_direct,'fallthrough_edges':len(fall),'missing_fallthrough_targets':missing_fall,'capstone_length_disagreements':bad,'import_addresses':len(imports)}

nonreturn=[];table_data=[];unresolved=[]
name_for={r['address']:r['name'] for r in fi}
switch=json.loads(args.switch_audit.read_text()) if args.switch_audit else None
if switch and switch['source_sha256']!=result['source_sha256']:raise ValueError('Wrong switch-audit provenance')
ranges=[(int(t['table'],0),int(t['table'],0)+4*t['entries']) for t in switch['tables']] if switch else []
for gap in missing_fall:
 pc=int(gap['from'],0);target=int(gap['target'],0)
 imported=next((name_for.get(int(e['target'],0)) for e in direct if int(e['from'],0)==pc and e['kind']=='CALL'),None)
 if imported=='___cxa_throw':nonreturn.append(gap)
 elif any(a<=pc<b and a<=target<b for a,b in ranges):table_data.append(gap)
 else:unresolved.append(gap)
result.update({'classified_nonreturning_calls':nonreturn,'classified_inline_table_bytes':table_data,'unresolved_executable_fallthroughs':unresolved,'inventory_is_not_exhaustive_behavior_proof':True})


manifest=json.loads(Path('src/lifter/whole/manifest.json').read_text())
file_mismatches=[]
for record in manifest['generated_files']:
 file=Path('src/lifter/whole')/record['name']
 if hashlib.sha256(file.read_bytes()).hexdigest()!=record['sha256']:file_mismatches.append(record['name'])
dispatch=Path('src/lifter/whole/Dispatch.cpp').read_text()
body=re.search(r'static const unsigned short sl_pc_units\[\]\s*=\s*\{(.*?)\};',dispatch,re.S).group(1)
pc_units=[int(value) for value in body.split(',') if value.strip()]
map_bad=[];map_count=0
for pc,value in enumerate(pc_units):
 expected=int(compiled[pc][4:-4])+1 if pc in compiled else 0
 if value!=expected:
  map_count+=1
  if len(map_bad)<16:map_bad.append({'pc':hex(pc),'expected':expected,'actual':value})
result.update({'generated_files_verified':len(manifest['generated_files']),'generated_file_hash_mismatches':file_mismatches,'pc_lookup_entries':len(pc_units),'pc_lookup_mismatch_count':map_count,'pc_lookup_mismatch_examples':map_bad})
result['passed']=not any([result['missing_emitted_labels'],result['extra_labels'],missing_functions,missing_vtables,missing_direct,unresolved,bad,file_mismatches,map_count])

output.write_text(json.dumps(result,indent=2)+'\n')
print({k:len(v) if isinstance(v,list) else v for k,v in result.items()});print('Missing direct',missing_direct[:12]);print('Missing fallthrough',missing_fall[:12]);print('Missing function',missing_functions[:5]);print('Missing vtables',missing_vtables[:10]);print('Decoder disagreements',bad[:5])

if not result['passed']:raise SystemExit(1)
