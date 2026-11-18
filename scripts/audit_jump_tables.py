#!/usr/bin/env python3
"""Audit original executable coverage; static evidence is not exhaustive behavior proof."""
from pathlib import Path
import argparse,os
ROOT=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();output=args.output.resolve();output.parent.mkdir(parents=True,exist_ok=True);os.chdir(ROOT)
import json,gzip,sys,bisect,struct,collections
from legacy_image import LegacyImage
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from capstone.x86 import X86_OP_REG,X86_OP_MEM,X86_OP_IMM,X86_REG_EBX
p=output.parent;image=LegacyImage(Path('reference/Sophistry.i386').read_bytes());raw=bytes(image.mapped());md=Cs(CS_ARCH_X86,CS_MODE_32);md.detail=True
from lift_pcode_chunks import rows as corrected_rows
rows=[j for _,j in corrected_rows(Path('analysis/lifter-full/instructions.jsonl.gz'),Path('analysis/lifter-full/integration-additions-cp032.jsonl'),Path('analysis/lifter-full/excluded-misaligned-cp032.json'))]
known={int(r['address'],16) for r in rows};pcs=sorted(known);by={int(r['address'],16):r for r in rows};fns=json.loads(Path('analysis/lifter-full/functions.json').read_text());fns.sort(key=lambda x:int(x['address'],16));starts=[int(f['address'],16) for f in fns];tables=[];other=[];uncertain=[]

def ebx_base(entry):
 bx=None;seen=False
 for ins in md.disasm(raw[entry:entry+100],entry):
  if ins.mnemonic=='call' and ins.operands[0].type==X86_OP_IMM:
   pc=ins.operands[0].imm
   if raw[pc:pc+4]==b'\x8b\x1c\x24\xc3':bx=ins.address+ins.size;seen=True;continue
  if seen:
   if ins.mnemonic in ['add','sub'] and ins.operands[0].type==X86_OP_REG and ins.operands[0].reg==X86_REG_EBX and ins.operands[1].type==X86_OP_IMM:
    bx=(bx+(ins.operands[1].imm if ins.mnemonic=='add' else -ins.operands[1].imm))&0xffffffff;continue
   return bx
 return bx

for index,pc in enumerate(pcs):
 r=by[pc]
 if not any(o['op']=='BRANCHIND' for o in r['pcode']):continue
 jump=next(md.disasm(raw[pc:pc+r['length']],pc));previous=[]
 for q in pcs[max(0,index-36):index]:
  i=next(md.disasm(raw[q:q+by[q]['length']],q));previous.append(i)
 relative=len(previous)>=2 and previous[-1].mnemonic=='add' and len(previous[-1].operands)==2 and previous[-1].operands[1].type==X86_OP_REG and previous[-1].operands[1].reg==X86_REG_EBX
 load=previous[-2] if relative else previous[-1] if previous else None
 if load is None or load.mnemonic!='mov' or len(load.operands)!=2 or load.operands[1].type!=X86_OP_MEM or load.operands[1].mem.scale!=4 or not load.operands[1].mem.index:
  other.append({'pc':hex(pc),'asm':r['asm']});continue
 mem=load.operands[1].mem
 if mem.base!=X86_REG_EBX or not relative:
  uncertain.append({'pc':hex(pc),'asm':r['asm'],'load':load.op_str,'reason':'not the EBX-relative switch pattern'});continue
 fn=fns[bisect.bisect_right(starts,pc)-1];base=ebx_base(int(fn['address'],16))
 if base is None:uncertain.append({'pc':hex(pc),'reason':'PIC base not recovered','function':fn});continue
 bound=None
 # Prefer a range branch into this exact dispatch block. A nearby compare
 # can belong to a different arm, as in CKeyboard2 at 0x94465.
 for k,branch in enumerate(previous):
  if k==0 or branch.mnemonic not in ['jbe','jb'] or not branch.operands or branch.operands[0].type!=X86_OP_IMM or branch.operands[0].imm!=load.address:continue
  cmp=previous[k-1]
  if cmp.mnemonic=='cmp' and cmp.operands[0].type==X86_OP_REG and cmp.operands[0].reg==mem.index and cmp.operands[1].type==X86_OP_IMM:
   bound=cmp.operands[1].imm+(1 if branch.mnemonic=='jbe' else 0);break
 if bound is None:
  for k,branch in enumerate(previous):
   if k==0 or branch.mnemonic not in ['ja','jae'] or branch.address+branch.size!=load.address:continue
   cmp=previous[k-1]
   if cmp.mnemonic=='cmp' and cmp.operands[0].type==X86_OP_REG and cmp.operands[0].reg==mem.index and cmp.operands[1].type==X86_OP_IMM:
    bound=cmp.operands[1].imm+(1 if branch.mnemonic=='ja' else 0);break
 table=(base+mem.disp)&0xffffffff;length=bound;inferred=False
 if length is None:
  inferred=True;length=0
  for n in range(513):
   target=(base+struct.unpack_from('<i',raw,table+4*n)[0])&0xffffffff
   if not any(s['address']<=target<s['address']+s['size'] for s in image.sections if s['flags']&0x80000400):break
   length+=1
 targets=[(base+struct.unpack_from('<i',raw,table+4*n)[0])&0xffffffff for n in range(length)]
 missing=[hex(t) for t in targets if t not in known]
 tables.append({'jump':hex(pc),'function':fn['name'],'function_entry':fn['address'],'pic_base':hex(base),'table':hex(table),'dispatch_load':hex(load.address),'index_register':md.reg_name(mem.index),'entries':length,'length_inferred_from_valid_code_targets':inferred,'targets':[hex(t) for t in targets],'missing_targets':missing})
result={'source_sha256':__import__('hashlib').sha256(Path('reference/Sophistry.i386').read_bytes()).hexdigest(),'scope':'Independent original-byte EBX-relative switch-table target audit; indirect virtual calls checked separately','tables':tables,'other_indirect_jumps':other,'unclassified_table_patterns':uncertain,'missing_target_count':sum(len(r['missing_targets']) for r in tables)}
result['passed']=not uncertain and not result['missing_target_count']
output.write_text(json.dumps(result,indent=2)+'\n');print('tables',len(tables),'other indirect',len(other),'uncertain',len(uncertain),'missing',result['missing_target_count']);print('uncertain',uncertain[:8]);print('missing',[(t['jump'],t['missing_targets']) for t in tables if t['missing_targets']]);print('inferred',[(t['jump'],t['entries']) for t in tables if t['length_inferred_from_valid_code_targets']])

if not result['passed']:raise SystemExit(1)
