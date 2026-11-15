#!/usr/bin/env python3
"""Compare original SysGlo serialization using public, deliberately invalid inputs.
No real licence is accepted by this tool and no preferences are written.
"""
import argparse, ctypes, hashlib, json, struct
from pathlib import Path
from probe_au_render import RenderHost, HostedNative, Original, ROOT, LegacyImage

def run(library, output):
 image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes())
 backend=HostedNative(ctypes.CDLL(str(library.resolve())),bytes(image.mapped()),0x4000000) if library else Original(bytes(image.mapped()),0x4000000)
 host=RenderHost(backend,image);outer=0x200000-0xec;sysglo=0x200000+0xb4;cases=[]
 def call(pc,*args):backend.run(pc,list(args));return host.eax()
 try:
  for pc in image.initializers:call(pc)
  call(0x48b0,outer,0x70001000)
  for offset,value in [(0,0xf2048),(8,0xf21a8),(0xe4,0xf21b4),(0xec,0xf2208)]:host.put(outer+offset,value)
  call(0xa6a2a,outer);call(0x2918,outer)
  key=host.string(sysglo+0x1d4).decode();assert key=='SophistrySysGlo'
  for label in ['default','deliberately-invalid-test-input']:
   if label!='default':
    backend.write(0x5e0000,b'INVALID-TEST-ONLY\0');call(0x12c66,sysglo,0,1,0x5e0000)
   descriptor=host.word(sysglo+0x120);vtable=host.word(descriptor)
   size=call(host.word(vtable+8),descriptor,0);assert 12<=size<=4096
   buffer=host.alloc(size+1);call(host.word(vtable+12),descriptor,buffer,0);data=backend.read(buffer,size)
   tag,declared,index=struct.unpack_from('<III',data);assert tag==0x53595053 and declared==size and index==0
   cases.append({'case':label,'bytes':size,'sha256':hashlib.sha256(data).hexdigest(),'original_tag':'SYPS','declared_size_matches':True})
  result={'scope':'Original SysGlo parameter serializer only; default and public invalid test string, no licence validation or persistence','backend':'static C++' if library else 'original i386 / Unicorn','preference_key':key,'cases':cases,'writes_to_preferences':False}
  output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(result,indent=2)+'\n');return result
 finally:backend.close()

if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--library',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args();print(json.dumps(run(a.library,a.output),indent=2))
