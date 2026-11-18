#!/usr/bin/env python3
"""Capture original i386 state for recovered code and original switch dispatches.

Only integer instructions and read/write test arenas are executed. No licence,
preferences, sample bank or musical render is used. SLIP0002 includes memory
outputs, so recovered stores are checked as well as registers and branch PCs.
"""
import argparse,collections,gzip,hashlib,json,random,struct,sys
from pathlib import Path
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32
from unicorn.x86_const import (UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_EBX,UC_X86_REG_ESP,UC_X86_REG_EBP,UC_X86_REG_ESI,UC_X86_REG_EDI,UC_X86_REG_EFLAGS,UC_X86_REG_EIP)
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'scripts'))
from legacy_image import LegacyImage
from lift_pcode_chunks import rows
GP={0:UC_X86_REG_EAX,4:UC_X86_REG_ECX,8:UC_X86_REG_EDX,12:UC_X86_REG_EBX,16:UC_X86_REG_ESP,20:UC_X86_REG_EBP,24:UC_X86_REG_ESI,28:UC_X86_REG_EDI}
REG_OFFSETS={'eax':0,'ecx':4,'edx':8,'ebx':12,'esp':16,'ebp':20,'esi':24,'edi':28}
FLAGS={0x200:0,0x202:2,0x206:6,0x207:7,0x20b:11}
word=lambda n:struct.pack('<I',n&0xffffffff)

def generate(output,tables):
 image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes());raw=bytes(image.mapped());u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0,0x800000);u.mem_write(0,raw)
 instructions={int(j['address'],16):j for _,j in rows(ROOT/'analysis/lifter-full/instructions.jsonl.gz',ROOT/'analysis/lifter-full/integration-additions-cp032.jsonl',ROOT/'analysis/lifter-full/excluded-misaligned-cp032.json')}
 fixture=bytearray(b'SLIP0002'+word(0));rng=random.Random(308032);groups=collections.Counter();count=0
 def capture(entry,stop,registers,memory,outputs,group,instructions_count=1):
  nonlocal count
  flags=2;segments=[]
  for offset,reg in GP.items():
   value=registers.get(offset,0);u.reg_write(reg,value);segments.append((offset,word(value)))
  for offset,bit in FLAGS.items():
   value=rng.randrange(2);flags|=value<<bit;segments.append((offset,bytes([value])))
  u.reg_write(UC_X86_REG_EFLAGS,flags)
  for at,data in memory:u.mem_write(at,data)
  u.emu_start(entry,stop,count=instructions_count)
  if u.reg_read(UC_X86_REG_EIP)!=stop:raise AssertionError('Original control flow did not reach expected stop')
  expected=[(0,offset,word(u.reg_read(reg))) for offset,reg in GP.items()]
  expected += [(0,offset,bytes([(u.reg_read(UC_X86_REG_EFLAGS)>>bit)&1])) for offset,bit in FLAGS.items()]
  expected += [(1,at,bytes(u.mem_read(at,size))) for at,size in outputs]
  fixture.extend(struct.pack('<6I',entry,stop,0,len(segments),len(memory),len(expected)))
  for items in [segments,memory]:
   for at,data in items:fixture.extend(struct.pack('<II',at,len(data))+data)
  for kind,at,data in expected:fixture.extend(struct.pack('<III',kind,at,len(data))+data)
  count+=1;groups[group]+=1
 values=[0,1,0x7fffffff,0x80000000,0xffffffff,0xffffc734,0xffffc733,0x12345678]+[rng.getrandbits(32) for _ in range(56)]
 recovered=[0x184d4,0x184d7,0x23f70,0x23f73,0x23f78,0x23f7b,0x54534,0x54539]
 for pc in recovered:
  for value in values:
   regs={o:rng.getrandbits(32) for o in GP};regs.update({16:0x70f000,20:0x230100,24:0x220000,0:value});memory=[(0x22000c,word(value)),(0x230108,word(value)),(0x230090,word(~value)),(0x70f008,word(~value)),(0x70f00c,word(~value))]
   stores={0x184d7:[(0x70f008,4)],0x23f78:[(0x230090,4)],0x23f7b:[(0x70f00c,4)]}
   stop=0x54479 if pc==0x54539 else pc+instructions[pc]['length']
   capture(pc,stop,regs,memory,stores.get(pc,[]),'recovered-instruction')
 for table in tables['tables']:
  entry=int(table['dispatch_load'],0);index_offset=REG_OFFSETS[table['index_register']]
  for index,target in enumerate(table['targets']):
   regs={o:0 for o in GP};regs.update({16:0x70f000,20:0x230100,12:int(table['pic_base'],0),index_offset:index})
   capture(entry,int(target,0),regs,[],[],'original-switch-dispatch',3)
 struct.pack_into('<I',fixture,8,count);output.parent.mkdir(parents=True,exist_ok=True)
 with output.open('wb') as stream:
  with gzip.GzipFile(filename='',mode='wb',fileobj=stream,mtime=0) as z:z.write(fixture)
 return {'scope':'Original i386 execution; all recovered integer instructions plus original EBX-relative switch dispatches; no licence or musical audio','cases':count,'groups':dict(groups),'recovered_instructions':[{'address':hex(pc),'asm':instructions[pc]['asm']} for pc in recovered],'switch_tables':len(tables['tables']),'registers_compared':list(REG_OFFSETS),'flags_compared':['CF','PF','ZF','SF','OF'],'memory_store_outputs_compared':True,'fixture_bytes':len(fixture),'fixture_sha256':hashlib.sha256(fixture).hexdigest(),'gzip_bytes':output.stat().st_size,'gzip_sha256':hashlib.sha256(output.read_bytes()).hexdigest(),'full_synth_tested':False}

if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--tables',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--report',type=Path,required=True);a=p.parse_args();r=generate(a.output,json.loads(a.tables.read_text()));a.report.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
