#!/usr/bin/env python3
"""Run original module descriptor control flow, intercepting parameter constructors.
This recovers serialization field kinds/names; it does not run a synth or prove AU IDs.
The initializer hooks replace allocation/default math and record call arguments.
"""
import argparse,hashlib,json,struct
from pathlib import Path
from unicorn import Uc,UcError,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EAX,UC_X86_REG_EIP
SHA='17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12'
KINDS={0x11652:1,0x10218:2,0x11728:3,0x117e2:4,0x118be:5,0x10290:6,0x10f72:7,0x10318:8}
def signed(v):return v if v<0x80000000 else v-0x100000000
class Capture:
 def __init__(self,image,table):
  self.u=u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0,0x1000000);u.mem_write(0,image)
  self.array=0x600000;self.obj=0x200000;self.pset=0x500000;self.arg=0x210000;self.fields={};self.finalized=False
  self.put(self.obj,int(table,16)+8);self.put(self.obj+0x120,self.pset);self.put(self.obj+0x124,self.pset)
  self.put(self.obj+0x1d4,2);self.put(self.arg,self.pset)
  self.put(self.pset,0xe6bc8);self.put(self.pset+4,self.array);self.put(self.pset+8,1);self.put(self.pset+0xc,0);self.put(self.pset+0x18,2048);self.put(self.pset+0x1c,0x520000)
  for i in range(128):self.put(0x520000+4*i,self.array)
  for at in list(KINDS)+[0x11c32,0x11b84,0x1042e]:u.hook_add(UC_HOOK_CODE,self.hook,begin=at,end=at)
  u.hook_add(UC_HOOK_CODE,self.external,begin=0x103000,end=0x1037e3)
 def put(self,a,x):self.u.mem_write(a,struct.pack('<I',x))
 def get(self,a):return struct.unpack('<I',self.u.mem_read(a,4))[0]
 def string(self,a):
  if a==0:return ''
  b=bytes(self.u.mem_read(a,4096)).split(b'\0')[0]
  return b.decode('utf8','replace')
 def ret(self,value=0):
  sp=self.u.reg_read(UC_X86_REG_ESP);target=self.get(sp);self.u.reg_write(UC_X86_REG_EAX,value);self.u.reg_write(UC_X86_REG_ESP,sp+4);self.u.reg_write(UC_X86_REG_EIP,target)
 def hook(self,u,at,size,user):
  if at==0x11b84:
   self.finalized=True;u.emu_stop();return
  if at in KINDS:
   sp=u.reg_read(UC_X86_REG_ESP);arg=[self.get(sp+4+i*4) for i in range(10)];p=arg[0]
   if not (self.array<=p<self.array+2048*112) or (p-self.array)%112:raise ValueError('Descriptor target outside synthetic parameter array: '+hex(p))
   kind=KINDS[at];index=(p-self.array)//112
   f={'index':index,'name':self.string(arg[1]),'kind':kind,'initializer':hex(at),'unit':self.string(arg[2]) if kind in [1,2] else 'dB' if kind==5 else ''}
   if kind==1:f.update(min=signed(arg[4]),max=signed(arg[5]),decimals=arg[6],default=signed(arg[7]))
   elif kind==2:
    f.update(min=signed(arg[3]),max=signed(arg[4]),width=arg[5],default=signed(arg[6]),options=self.string(arg[7]))
   elif kind in [3,4]:f.update(min=signed(arg[2]),max=signed(arg[3]),default=signed(arg[5] if kind==4 else arg[4]))
   elif kind==5:f.update(min=signed(arg[2]),max=signed(arg[3]),default=signed(arg[4]))
   elif kind==6:f['default']=arg[2]
   elif kind==8:f['array_length']=arg[2]
   self.fields[index]=f
  self.ret()
 def external(self,u,at,size,user):raise ValueError('Unimplemented external during descriptor extraction: '+hex(at))
 def run(self,address):
  self.finalized=False
  sp=0xf00000;self.u.mem_write(sp,struct.pack('<IIII',0xfff000,self.obj,self.arg,1));self.u.reg_write(UC_X86_REG_ESP,sp)
  self.u.emu_start(int(address,16),0xfff000,count=3_000_000)
  if not self.finalized and self.u.reg_read(UC_X86_REG_EIP)!=0xfff000:raise ValueError('Descriptor did not return within instruction budget')

def recover(root):
 image=(root/'reference/Sophistry.i386').read_bytes()
 if hashlib.sha256(image).hexdigest()!=SHA:raise ValueError('Wrong original')
 mods=json.loads((root/'analysis/module-descriptor-map.json').read_text());tables=json.loads((root/'analysis/vtables.json').read_text());byname={t['name']:t for t in tables};result=[]
 for mod in mods:
  c=Capture(image,byname[mod['class']]['tables'][0]['address']);item=dict(mod)
  try:
   for fn in mod['config_functions']:c.run(fn)
   item['extraction_ok']=True
  except Exception as e:item.update(extraction_ok=False,error=str(e))
  count=max(c.fields,default=-1)+1
  item['fields']=[c.fields.get(i,{'index':i,'name':'uninitialized/reserved','kind':0,'assumption':'original zero-initialized Parameter default; not an AU parameter ID'}) for i in range(count)]
  result.append(item)
 return {'scope':'Original descriptor control flow with synthetic parameter storage and constructor hooks; field names/types only; no synth execution, no AU IDs','original_sha256':SHA,'modules':result}
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--root',type=Path,default=Path(__file__).resolve().parents[1]);p.add_argument('--output',type=Path);n=p.parse_args();r=recover(n.root)
 out=n.output or n.root/'analysis/parameter-schemas.json';out.write_text(json.dumps(r,indent=2)+'\n')
 print(json.dumps({'modules':len(r['modules']),'ok':sum(x['extraction_ok'] for x in r['modules']),'fields':sum(len(x['fields']) for x in r['modules']),'failed':[{'class':x['class'],'error':x.get('error')} for x in r['modules'] if not x['extraction_ok']]},indent=2))
