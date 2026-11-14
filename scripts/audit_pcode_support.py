#!/usr/bin/env python3
"""Audit emitter coverage without claiming that untested machine code works."""
import argparse,collections,json,sys
from pathlib import Path
from lift_pcode_cpp import emit

def audit(source):
 known=set()
 with source.open() as f:
  for line in f:known.add(int(json.loads(line)['address'],16))
 counts=collections.Counter();unsupported=collections.Counter();examples={};floats=collections.Counter();users=collections.Counter();spaces=collections.Counter();maxima=collections.defaultdict(int)
 total=0;failed_instructions=0;emittable=0;guards=[]
 with source.open() as f:
  for line in f:
   ins=json.loads(line);failed=False
   for j,op in enumerate(ins['pcode']):
    total+=1;counts[op['op']]+=1
    if op.get('userop'):
     users[op['userop']]+=1
     if op['userop'] in ['swi','out','LOCK','UNLOCK']:guards.append({'address':ins['address'],'asm':ins['asm'],'userop':op['userop'],'semantics':'terminal fault; shared-memory atomic behavior unavailable' if op['userop'] in ['LOCK','UNLOCK'] else 'terminal x86 trap / privileged I/O guard'})
    if op['op'].startswith('FLOAT') or op['op'] in ['INT2FLOAT','TRUNC']:floats[(op['op'],op['output']['size'] if op['output'] else 0,tuple(v['size'] for v in op['inputs']))]+=1
    for v in ([op['output']] if op['output'] else [])+op['inputs']:
     spaces[v['space']]+=1
     if v['space'] in ['register','unique']:maxima[v['space']]=max(maxima[v['space']],int(v['offset'],16)+v['size'])
    try:
     if any(v['size']>16 for v in ([op['output']] if op['output'] else [])+op['inputs']):raise ValueError('Value wider than 128 bits')
     emit(ins,op,j,known);emittable+=1
    except ValueError as e:
     reason=str(e);unsupported[reason]+=1;failed=True;examples.setdefault(reason,{'address':ins['address'],'asm':ins['asm'],'operation':op})
   failed_instructions+=failed
 return {'scope':'Static syntax/feature audit only; not a complete lift or execution test','instructions':len(known),'pcode_operations':total,'currently_emittable_operations':emittable,'instructions_with_unsupported_operations':failed_instructions,'unsupported_counts':dict(unsupported),'unsupported_examples':examples,'operation_counts':dict(counts),'float_variants':[{'op':k[0],'output_bytes':k[1],'input_bytes':k[2],'count':v} for k,v in floats.items()],'userops':dict(users),'terminal_guard_operations':guards,'instructions_with_terminal_guards':len({g['address'] for g in guards}),'spaces':dict(spaces),'storage_bytes_required':dict(maxima),'full_engine_lifted':False,'full_engine_executed':False}
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('source',type=Path);p.add_argument('--output',type=Path,required=True);n=p.parse_args();r=audit(n.source);n.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k] for k in ['instructions','pcode_operations','currently_emittable_operations','instructions_with_unsupported_operations','unsupported_counts','userops','storage_bytes_required']},indent=2))
