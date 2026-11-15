#!/usr/bin/env python3
"""Construct the original AU object and query its layout without macOS registration."""
import argparse,ctypes,json,struct,sys
from pathlib import Path
from probe_engine_initialization import Host,HostedNative,Original,ROOT,LegacyImage

class AUPlatformHost(Host):
 def callback(self,pc):
  name=self.names.get(pc)
  if name not in ['_Gestalt','_DecrementAtomic','_IncrementAtomic','_CompareAndSwap']:
   return super().callback(pc)
  self.last_import={'address':hex(pc),'name':name};self.calls[name]+=1
  sp=self.b.esp();arg=lambda n:self.word(sp+4+4*n);result=0
  if name=='_Gestalt':
   # Explicit emulated Intel Mac capabilities: SSE2 and x86-64 available.
   selector=arg(0);features={0x78383666:1<<26,0x78383661:1}
   if selector not in features:raise ValueError('Unsupported Gestalt selector '+hex(selector))
   self.put(arg(1),features[selector])
  elif name in ['_DecrementAtomic','_IncrementAtomic']:
   # Carbon atomics return the value before modification.
   result=self.word(arg(0));self.put(arg(0),result+(-1 if name=='_DecrementAtomic' else 1))
  else:
   result=int(self.word(arg(2))==arg(0))
   if result:self.put(arg(2),arg(1))
  if isinstance(self.b,Original):
   from unicorn.x86_const import UC_X86_REG_EAX
   self.b.uc.reg_write(UC_X86_REG_EAX,result&0xffffffff)
  else:self.b.regwrite(0,struct.pack('<I',result&0xffffffff))
  self.b.ret()

def run(library,output):
 image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes());b=HostedNative(ctypes.CDLL(str(library.resolve())),bytes(image.mapped()),0x4000000) if library else Original(bytes(image.mapped()),0x4000000)
 h=AUPlatformHost(b,image);stage='initializers';error=None;scopes=[];formats=[];supported=[]
 try:
  for pc in image.initializers:b.run(pc,[])
  stage='original AU constructor';b.run(0x48b0,[0x200000,0x70001000])
  # The derived-vtable assignments are the exact stores in AUCronoXEntry.
  for at,value in [(0,0xf2048),(8,0xf21a8),(0xe4,0xf21b4),(0xec,0xf2208)]:h.put(0x200000+at,value)
  stage='original AU element creation';b.run(0xa6a2a,[0x200000])
  for scope in [0,1,2]:
   start,end=h.word(0x200000+0x28+scope*20),h.word(0x200000+0x2c+scope*20)
   if end<start or (end-start)%4 or end-start>128:raise ValueError('Invalid AU scope vector')
   elements=[]
   for at in range(start,end,4):
    pointer=h.word(at);entry={'address':hex(pointer)}
    if scope in [1,2]:
     raw=struct.unpack('<d8I',b.read(pointer+0x34,40));entry['default_format']={'sample_rate':raw[0],'format_id':hex(raw[1]),'flags':hex(raw[2]),'bytes_per_packet':raw[3],'frames_per_packet':raw[4],'bytes_per_frame':raw[5],'channels':raw[6],'bits':raw[7]}
    elements.append(entry)
   scopes.append({'scope':scope,'elements':elements,'count':len(elements)})
  stage='original supported channel configurations';b.run(0x833b0,[0x200000,0x600000]);count=h.eax();pointer=h.word(0x600000)
  supported=[{'inputs':a,'outputs':c} for a,c in struct.iter_unpack('<hh',b.read(pointer,count*4))]
  for scope in [0,1,2]:
   for channels in [1,2,4,6,8]:
    fmt=struct.pack('<d8I',44100,0x6c70636d,0x29,4,1,4,channels,32,0);b.write(0x600100,fmt);b.run(0x833ce,[0x200000,scope,0,0x600100]);formats.append({'scope':scope,'channels':channels,'accepted':bool(h.eax())})
  stage='completed'
 except Exception as e:error=str(e)
 r={'scope':'Original AU constructor and element layout in an explicit platform fixture; no system AU registration or audio rendering','backend':'static C++' if library else 'original i386 / Unicorn','stage':stage,'error':error,'last_import':h.last_import,'scopes':scopes,'supported_channel_configurations':supported,'format_checks':formats,'host_calls':dict(h.calls)}
 output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(r,indent=2)+'\n');b.close();return r
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--library',type=Path);p.add_argument('--output',type=Path,required=True);n=p.parse_args();r=run(n.library,n.output);print(json.dumps(r,indent=2));sys.exit(1 if r['error'] else 0)
