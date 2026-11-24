#!/usr/bin/env python3
"""Emit fixed C++ operations and direct labels from Ghidra's raw instruction p-code.
No x86 opcode decoder is emitted. Unsupported semantics fail generation explicitly.
Current scope is the separately exported instruction set, not the full DSP engine.
"""
import argparse,collections,hashlib,json
from pathlib import Path
SHA='fe5f50d2213cfdd072c98cd4083d92bf24d9dc5ea8115b25a64cc8df08ed9969'
def number(v):return int(v['offset'],16)
def const(n):return 'SlU(0x%xULL)'%n

def value(v):
 s=v['space'];o=number(v);n=v['size']
 if s=='const':return const(o)
 if s=='register':return 'sl_get<%d>(c.reg,sizeof(c.reg),0x%x,c)'%(n,o)
 if s=='unique':return 'sl_get<%d>(c.temp,sizeof(c.temp),0x%x,c)'%(n,o)
 if s=='ram':return 'sl_get<%d>(c.memory,c.memory_size,0x%x,c)'%(n,o)
 raise ValueError('Unsupported input space '+s)
def assign(v,expression):
 s=v['space'];o=number(v);n=v['size'];arrays={'register':('c.reg','sizeof(c.reg)'),'unique':('c.temp','sizeof(c.temp)'),'ram':('c.memory','c.memory_size')}
 if s not in arrays:raise ValueError('Unsupported output space '+s)
 a,z=arrays[s];return 'sl_put<%d>(%s,%s,0x%x,%s,c);'%(n,a,z,o,expression)
def fp(v):
 if v['size'] not in [4,8]:raise ValueError('Unsupported arithmetic float format: '+str(v['size']))
 return 'sl_float<%s>(%s)'%('float' if v['size']==4 else 'double',value(v))

def quotient_width(ins,op):
 # The x86 p-code divides at twice the destination width, then truncates.
 # Recover the architectural width from that SUBPIECE rather than dropping #DE.
 for later in ins['pcode']:
  if later['op']=='SUBPIECE' and later['inputs'][0]==op['output'] and number(later['inputs'][1])==0:
   return later['output']['size']*8
 return op['output']['size']*8

def emit(ins,op,j,known):
 kind=op['op'];iv=op['inputs'];out=op['output'];a=[value(v) for v in iv];expr=None
 if kind in ['COPY','INT_ZEXT']:expr=a[0]
 elif kind=='INT_SEXT':expr='SlU(sl_signed(%s,%d))'%(a[0],iv[0]['size']*8)
 elif kind in ['INT_ADD','INT_SUB','INT_MULT','INT_AND','INT_OR','INT_XOR','INT_EQUAL','INT_NOTEQUAL','INT_LESS','INT_LESSEQUAL']:
  symbol={'INT_ADD':'+','INT_SUB':'-','INT_MULT':'*','INT_AND':'&','INT_OR':'|','INT_XOR':'^','INT_EQUAL':'==','INT_NOTEQUAL':'!=','INT_LESS':'<','INT_LESSEQUAL':'<='}[kind];expr='(%s %s %s)'%(a[0],symbol,a[1])
 elif kind in ['INT_SLESS','INT_SLESSEQUAL']:
  expr='(sl_signed(%s,%d) %s sl_signed(%s,%d))'%(a[0],iv[0]['size']*8,'<' if kind=='INT_SLESS' else '<=',a[1],iv[1]['size']*8)
 elif kind=='INT_CARRY':expr='(((%s+%s)&sl_mask(%d))<%s)'%(a[0],a[1],iv[0]['size']*8,a[0])
 elif kind in ['INT_SCARRY','INT_SBORROW']:
  sign='(SlU(1)<<%d)'%(iv[0]['size']*8-1)
  if kind=='INT_SCARRY':expr='(((%s^(%s+%s))&(%s^(%s+%s))&%s)!=0)'%(a[0],a[0],a[1],a[1],a[0],a[1],sign)
  else:expr='(((%s^%s)&(%s^(%s-%s))&%s)!=0)'%(a[0],a[1],a[0],a[0],a[1],sign)
 elif kind=='INT_NEGATE':expr='(~%s)'%a[0]
 elif kind=='INT_2COMP':expr='(SlU(0)-%s)'%a[0]
 elif kind=='BOOL_NEGATE':expr='(!%s)'%a[0]
 elif kind in ['BOOL_OR','BOOL_AND','BOOL_XOR']:
  expr='(bool(%s) %s bool(%s))'%(a[0],{'BOOL_OR':'||','BOOL_AND':'&&','BOOL_XOR':'!='}[kind],a[1])
 elif kind=='POPCOUNT':expr='sl_popcount(%s)'%a[0]
 elif kind=='SUBPIECE':expr='sl_rshift(%s,8*%s)'%(a[0],a[1])
 elif kind=='PIECE':expr='(sl_lshift(%s,%d)|%s)'%(a[0],iv[1]['size']*8,a[1])
 elif kind=='INT_LEFT':expr='sl_lshift(%s,%s)'%(a[0],a[1])
 elif kind=='INT_RIGHT':expr='sl_rshift(%s,%s)'%(a[0],a[1])
 elif kind=='INT_SRIGHT':expr='sl_sright(%s,%s,%d)'%(a[0],a[1],iv[0]['size']*8)
 elif kind in ['INT_DIV','INT_REM','INT_SDIV','INT_SREM']:
  if iv[0]['size']>8 or iv[1]['size']>8:raise ValueError('Unsupported division input wider than 64 bits')
  expression='sl_divide(c,%s,%s,%d,%d,%s,%s)'%(a[0],a[1],iv[0]['size']*8,quotient_width(ins,op),'true' if kind in ['INT_SDIV','INT_SREM'] else 'false','true' if kind in ['INT_REM','INT_SREM'] else 'false')
  return '{const SlU result=%s;if(c.fault)return int(c.fault);%s}'%(expression,assign(out,'result'))
 elif kind=='LOAD':
  if number(iv[0])!=0x1a1:raise ValueError('Non-RAM LOAD')
  expr='sl_get<%d>(c.memory,c.memory_size,SlU32(%s),c)'%(out['size'],a[1])
 elif kind=='STORE':
  if number(iv[0])!=0x1a1:raise ValueError('Non-RAM STORE')
  return 'sl_put<%d>(c.memory,c.memory_size,SlU32(%s),%s,c);'%(iv[2]['size'],a[1],a[2])
 elif kind in ['FLOAT_ADD','FLOAT_SUB','FLOAT_MULT','FLOAT_DIV']:
  symbol={'FLOAT_ADD':'+','FLOAT_SUB':'-','FLOAT_MULT':'*','FLOAT_DIV':'/'}[kind];expr='sl_bits(%s %s %s)'%(fp(iv[0]),symbol,fp(iv[1]))
 elif kind in ['FLOAT_EQUAL','FLOAT_NOTEQUAL','FLOAT_LESS','FLOAT_LESSEQUAL']:
  symbol={'FLOAT_EQUAL':'==','FLOAT_NOTEQUAL':'!=','FLOAT_LESS':'<','FLOAT_LESSEQUAL':'<='}[kind];expr='(%s %s %s)'%(fp(iv[0]),symbol,fp(iv[1]))
 elif kind=='FLOAT_NAN':expr='__builtin_isnan(%s)'%fp(iv[0])
 elif kind=='FLOAT2FLOAT':
  if iv[0]['size']==10 and out['size'] in [4,8]:expr='sl_ext80_to_f%d(%%s)'%(out['size']*8)%a[0]
  elif iv[0]['size'] in [4,8] and out['size']==10:expr='sl_fp_to_ext80(%s,%d)'%(a[0],iv[0]['size'])
  elif iv[0]['size'] in [4,8] and out['size'] in [4,8]:expr='sl_bits(static_cast<%s>(%s))'%('float' if out['size']==4 else 'double',fp(iv[0]))
  else:raise ValueError('Unsupported FLOAT2FLOAT sizes')
 elif kind=='INT2FLOAT':
  if out['size']==10 and iv[0]['size']<=8:expr='sl_integer_to_ext80(%s,%d)'%(a[0],iv[0]['size']*8)
  elif out['size'] in [4,8]:expr='sl_bits(static_cast<%s>(sl_signed(%s,%d)))'%('float' if out['size']==4 else 'double',a[0],iv[0]['size']*8)
  else:raise ValueError('Unsupported INT2FLOAT output')
 elif kind=='FLOAT_SQRT':
  if out['size'] not in [4,8] or iv[0]['size']!=out['size']:raise ValueError('Unsupported FLOAT_SQRT format')
  expr='sl_sqrt_f%d(%s)'%(out['size']*8,a[0])
 elif kind=='CALLOTHER':
  # Preserve traps / unsupported platform semantics explicitly. In particular,
  # LOCK is not silently discarded in a VM that has no shared-memory protocol.
  userop=op.get('userop')
  if userop in ['swi','out']:return 'c.fault=8;return 8; // explicit x86 trap / privileged I/O'
  if userop in ['LOCK','UNLOCK']:return 'c.fault=10;return 10; // unsupported shared-memory atomic instruction'
  raise ValueError('Unsupported userop '+str(userop))
 elif kind=='TRUNC':
  if iv[0]['size'] not in [4,8] or out['size'] not in [4,8]:raise ValueError('Unsupported float truncation')
  expr='sl_trunc_fp(%s,%d,%d)'%(a[0],iv[0]['size'],out['size']*8)
 elif kind in ['BRANCH','CBRANCH','CALL']:
  target=iv[0]
  if target['space']=='const':dest='goto P_%s_%d;'%(ins['address'],j+(number(target) if number(target)<1<<(target['size']*8-1) else number(target)-(1<<(target['size']*8))))
  elif target['space']=='ram':
   addr=number(target);dest='goto L_%x;'%addr if addr in known else 'c.pc=0x%x;goto dispatch;'%addr
  else:raise ValueError('Unsupported direct flow target')
  return ('if(%s){%s}'%(a[1],dest)) if kind=='CBRANCH' else dest
 elif kind in ['BRANCHIND','CALLIND','RETURN']:return 'c.pc=SlU32(%s);goto dispatch;'%a[0]
 else:raise ValueError('Unsupported p-code operation '+kind)
 if out is None:raise ValueError('Missing p-code result')
 return assign(out,expr)

def generate(source,output):
 provenance=json.loads((source.parent/'provenance.json').read_text())
 if provenance['sha256']!=SHA:raise ValueError('Wrong original provenance')
 data=[json.loads(l) for l in source.read_text().splitlines()];known={int(i['address'],16) for i in data};opcounts=collections.Counter()
 lines=['// Generated from raw Ghidra instruction p-code; not decompiler pseudo-C.','// Source SHA-256: '+SHA,'#include "LifterRuntime.h"','int sl_execute(SlCpu& c,SlU32 entry,SlU32 stop,SlU64 limit){','c.pc=entry;c.stop=stop;c.steps=0;c.limit=limit;c.fault=0;goto dispatch;','dispatch:','if(c.pc==c.stop)return int(c.fault);','if(c.fault)return int(c.fault);','switch(c.pc){']
 lines+=['case 0x%x:goto L_%x;'%(a,a) for a in sorted(known)]
 lines+=['default:break;}','if(!sl_tick(c))return int(c.fault);','for(SlU32 h=0;h<c.hook_count;++h){if(c.hooks[h].address==c.pc){c.hooks[h].function(c.hooks[h].user,c.pc,&c);goto dispatch;}}','c.fault=3;return 3;']
 for i in data:
  addr=int(i['address'],16);lines+=['L_%x: { // %s'%(addr,i['asm']),'c.pc=0x%x;if(!sl_tick(c))return int(c.fault);'%addr]
  # P-code local branches use relative offsets into this instruction's op array.
  for j,op in enumerate(i['pcode']):
   opcounts[op['op']]+=1;lines.append('P_%s_%d:;'%(i['address'],j));lines.append(emit(i,op,j,known))
  lines.append('P_%s_%d:;'%(i['address'],len(i['pcode'])))
  nextaddr=addr+i['length'];lines.append('goto L_%x;'%nextaddr if nextaddr in known else 'c.pc=0x%x;goto dispatch;'%nextaddr);lines.append('}')
 lines.append('}')
 output.write_text('\n'.join(lines)+'\n')
 report={'scope':'Static C++ emission of the separately exported instruction set; not complete DSP engine','original_sha256':SHA,'instruction_count':len(data),'pcode_operation_count':sum(opcounts.values()),'operations':dict(opcounts),'generated_cpp_sha256':hashlib.sha256(output.read_bytes()).hexdigest(),'unsupported_operations':[],'x86_decoder_in_runtime':False,'uses_fixed_control_flow_labels':True,'requires_host_callbacks':True,'floating_environment':'nearest-even, no fast-math, no contraction; x87 arithmetic beyond exact IEEE-to-ext80 / ext80-to-IEEE storage conversions unsupported'}
 report['terminal_guard_operations']=[{'address':ins['address'],'asm':ins['asm'],'userop':op.get('userop')} for ins in data for op in ins['pcode'] if op['op']=='CALLOTHER']
 output.with_suffix('.json').write_text(json.dumps(report,indent=2)+'\n');return report
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('source',type=Path);p.add_argument('output',type=Path);n=p.parse_args();print(json.dumps(generate(n.source,n.output),indent=2))
