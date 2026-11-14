#!/usr/bin/env python3
"""Compare newly supported primitives against actual original i386 instructions."""
import argparse,collections,ctypes,hashlib,json,random,struct,sys
from pathlib import Path
from unicorn import UcError
from unicorn.x86_const import (
 UC_X86_REG_EAX,UC_X86_REG_ECX,UC_X86_REG_EDX,UC_X86_REG_EBP,
 UC_X86_REG_EFLAGS,UC_X86_REG_XMM1,UC_X86_REG_MXCSR,UC_X86_REG_FPSW,
 UC_X86_REG_FPTAG,UC_X86_REG_FP0)
from compare_lifted_dsp import Native,Original,ext80,SHA
ROOT=Path(__file__).resolve().parents[1]
GP={0:UC_X86_REG_EAX,4:UC_X86_REG_ECX,8:UC_X86_REG_EDX,0x14:UC_X86_REG_EBP}
FLAGS={0x200:0,0x202:2,0x204:4,0x206:6,0x207:7,0x20b:11}
word=lambda x:struct.pack('<I',x&0xffffffff)
def run(library,report_path):
 image=(ROOT/'reference/Sophistry.i386').read_bytes()
 if hashlib.sha256(image).hexdigest()!=SHA:raise ValueError('Wrong original binary')
 rows=[json.loads(l) for l in (ROOT/'analysis/lifter-primitives/instructions.jsonl').read_text().splitlines()]
 by_addr={int(i['address'],16):i for i in rows}
 by_asm={i['asm']:int(i['address'],16) for i in rows}
 lib=ctypes.CDLL(str(library.resolve()));native=Native(lib,image);original=Original(image);u=original.uc
 hardware=lib.sl_test_divide_oracle
 hardware.argtypes=[ctypes.c_uint32,ctypes.c_uint32,ctypes.c_uint32,ctypes.c_int,ctypes.POINTER(ctypes.c_uint32),ctypes.POINTER(ctypes.c_uint32)]
 hardware.restype=ctypes.c_int
 rng=random.Random(308009);counts=collections.Counter();fixture=bytearray(b'SLIP0001'+word(0));cases=0;traps=0;hardware_cases=0;unicorn_corner_skips=0
 def get(offset,size):
  if offset in GP:return word(u.reg_read(GP[offset]))
  if offset in FLAGS:return bytes([(u.reg_read(UC_X86_REG_EFLAGS)>>FLAGS[offset])&1])
  if offset==0x1240:return u.reg_read(UC_X86_REG_XMM1).to_bytes(16,'little')
  if 0x1100<=offset<=0x1170:
   top=(u.reg_read(UC_X86_REG_FPSW)>>11)&7
   return struct.pack('<QH',*u.reg_read(UC_X86_REG_FP0+((top+(offset-0x1100)//16)&7)))
  raise ValueError('Unsupported oracle register')
 def check(address,regs,memory,outputs,group):
  nonlocal cases,traps,hardware_cases,unicorn_corner_skips,original,u
  # A fresh CPU avoids Unicorn retaining an exception state across DIV tests.
  if by_addr[address]['asm'].startswith(('IDIV ','DIV ')):
   original=Original(image);u=original.uc
  native.regwrite(0,b'\0'*0x2000)
  for reg in GP.values():u.reg_write(reg,0)
  u.reg_write(UC_X86_REG_MXCSR,0x1f80);u.reg_write(UC_X86_REG_FPSW,0);u.reg_write(UC_X86_REG_FPTAG,0xc000)
  flags=2
  for offset,data in regs:
   native.regwrite(offset,data)
   if offset in GP:u.reg_write(GP[offset],int.from_bytes(data,'little'))
   elif offset in FLAGS:flags|=int.from_bytes(data,'little')<<FLAGS[offset]
   elif offset==0x1240:u.reg_write(UC_X86_REG_XMM1,int.from_bytes(data,'little'))
   elif 0x1100<=offset<=0x1170:u.reg_write(UC_X86_REG_FP0+(offset-0x1100)//16,struct.unpack('<QH',data))
   else:raise ValueError('Unsupported input register')
  u.reg_write(UC_X86_REG_EFLAGS,flags)
  for at,data in memory:native.write(at,data);original.write(at,data)
  stop=address+by_addr[address]['length'];fault=0;hardware_result=None
  if by_addr[address]['asm'].startswith(('IDIV ','DIV ')):
   inputs=dict(regs);low=int.from_bytes(inputs[0],'little');high=int.from_bytes(inputs[8],'little')
   denominator=int.from_bytes(memory[0][1],'little');is_signed=by_addr[address]['asm'].startswith('IDIV ')
   q=ctypes.c_uint32();r=ctypes.c_uint32()
   fault=hardware(low,high,denominator,int(is_signed),ctypes.byref(q),ctypes.byref(r))
   if fault==77:raise RuntimeError('A native x86 division oracle is required to create these reference fixtures')
   hardware_result={0:word(q.value),8:word(r.value)};hardware_cases+=1;traps+=bool(fault)
   # Unicorn 2.1.4 kills its host with SIGFPE for INT64_MIN / -1.
   # Use the real x86 instruction oracle for this corner instead of hiding it.
   skip=is_signed and low==0 and high==0x80000000 and denominator==0xffffffff
   if skip:unicorn_corner_skips+=1
   else:
    unicorn_fault=0
    try:u.emu_start(address,stop,count=1)
    except UcError:unicorn_fault=9
    if unicorn_fault!=fault:raise AssertionError(f'Hardware / Unicorn divide exception differs: {high:x}:{low:x} / {denominator:x}, signed={is_signed}, hardware={fault}, unicorn={unicorn_fault}')
    for offset,value in hardware_result.items():
     if get(offset,4)!=value:raise AssertionError('Hardware / Unicorn divide value differs')
  else:u.emu_start(address,stop,count=1)
  actual=native.l.sl_run(native.c,address,stop,1000)
  if actual!=fault:raise AssertionError(f'{group} at {address:x}: native fault {actual}, original {fault}')
  expected=[]
  for offset,size in outputs:
   value=hardware_result[offset] if hardware_result is not None else get(offset,size);b=ctypes.create_string_buffer(size)
   native.l.sl_reg_read(native.c,offset,b,size)
   if value!=b.raw:raise AssertionError(f'{group} at {address:x} reg {offset:x}: {b.raw.hex()} != {value.hex()} inputs {regs}')
   expected.append((offset,value))
  if not fault and native.l.sl_get_steps(native.c)!=1:raise AssertionError('Single-instruction stop was not honored')
  fixture.extend(struct.pack('<6I',address,stop,fault,len(regs),len(memory),len(expected)))
  for segments in [regs,memory,expected]:
   for at,data in segments:fixture.extend(struct.pack('<II',at,len(data))+data)
  cases+=1;counts[group]+=1
 def flag_inputs():return [(at,bytes([rng.randrange(2)])) for at in FLAGS]
 values=[0,1,2,0x7fffffff,0x80000000,0xfffffffe,0xffffffff]+[rng.getrandbits(32) for _ in range(1024)]
 for x in values:
  regs=[(0,word(x))]+flag_inputs()
  check(0x1f63,regs,[],[(0,4)]+[(a,1) for a in [0x200,0x202,0x206,0x207,0x20b]],'sar-immediate')
 for _ in range(2048):
  x=rng.getrandbits(32);shift=rng.choice([0,1,2,15,31,32,33,63,255]);masked=shift&31
  fields=list(FLAGS) if masked==0 else [0x200,0x202,0x206,0x207]+([0x20b] if masked==1 else [])
  check(0x2dae4,[(0,word(x)),(4,word(shift))]+flag_inputs(),[],[(0,4)]+[(a,1) for a in fields],'sar-cl')
 signed=[(a,b) for a in [-(1<<63),-(1<<31)-1,-(1<<31),-1,0,1,(1<<31)-1,1<<31,(1<<63)-1] for b in [-(1<<31),-3,-1,0,1,3,(1<<31)-1]]
 signed += [(rng.randrange(-(1<<63),1<<63),rng.randrange(-(1<<31),1<<31)) for _ in range(2048)]
 for a,b in signed:
  check(0x762f,[(0,word(a)),(8,word(a>>32)),(0x14,word(0x600100))],[(0x6000c0,word(b))],[(0,4),(8,4)],'signed-divide')
 unsigned=[(a,b) for a in [0,1,0xffffffff,1<<32,(1<<64)-1] for b in [0,1,2,0x80000000,0xffffffff]]
 unsigned += [(rng.getrandbits(64),rng.getrandbits(32)) for _ in range(2048)]
 for a,b in unsigned:
  check(0xae22f,[(0,word(a)),(8,word(a>>32)),(0x14,word(0x600100))],[(0x6000f4,word(b))],[(0,4),(8,4)],'unsigned-divide')
 sqrt_values=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,0x3f800000,0x40000000,0xbf800000,0x7f7fffff,0x7f800000,0xff800000,0x7fc12345,0xffc12345,0x7f812345,0xff812345]
 sqrt_values += [rng.getrandbits(32) for _ in range(4096)]
 for bits in sqrt_values:
  xmm=word(bits)+rng.getrandbits(96).to_bytes(12,'little')
  check(0x7ec24,[(0x1240,xmm)],[],[(0x1240,16)],'sqrtss')
 for asm in ['FLDZ','FLD1']:
  for _ in range(128):
   regs=[(0x1100+i*16,ext80(rng.uniform(-100,100))) for i in range(8)]
   check(by_asm[asm],regs,[],[(0x1100+i*16,10) for i in range(8)],asm.lower())
 differential_cases=cases
 # These are explicit terminal guard checks, not claimed as equivalent to LOCK.
 guards=[]
 for address,fault in [(0x12fb8,8),(0x23f4c,10),(0x4debc,8),(0x4dec0,8)]:
  stop=address+by_addr[address]['length']
  if native.l.sl_run(native.c,address,stop,1000)!=fault:raise AssertionError('Terminal guard failed')
  fixture.extend(struct.pack('<6I',address,stop,fault,0,0,0));cases+=1
  guards.append({'address':hex(address),'asm':by_addr[address]['asm'],'terminal_fault':fault})
 struct.pack_into('<I',fixture,8,cases)
 report_path.parent.mkdir(parents=True,exist_ok=True)
 fixture_path=report_path.with_suffix('.fixtures');fixture_path.write_bytes(fixture)
 result={'scope':'Isolated original instructions; not full-engine DSP','differential_cases':differential_cases,'groups':dict(counts),'original_divide_exception_cases':traps,'division_hardware_oracle_cases':hardware_cases,'unicorn_host_sigfpe_corner_cases_checked_with_hardware_only':unicorn_corner_skips,'mismatches':0,'explicit_terminal_guard_cases':guards,'fixture_cases':cases,'fixture_sha256':hashlib.sha256(fixture).hexdigest(),'fixture_bytes':len(fixture),'rounding_mode':'nearest-even/default MXCSR; exception flags not modeled','full_engine_tested':False}
 report_path.write_text(json.dumps(result,indent=2)+'\n');native.close();original.close();return result
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('library',type=Path);p.add_argument('--output',type=Path,required=True);n=p.parse_args();print(json.dumps(run(n.library,n.output),indent=2))
