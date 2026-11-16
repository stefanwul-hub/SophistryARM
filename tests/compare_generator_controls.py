#!/usr/bin/env python3
"""Compare edited public program bytes to original i386 normalized setters."""
import argparse,hashlib,json,struct,subprocess
from pathlib import Path
from probe_au_render import RenderHost,Original,LegacyImage,ROOT

def compare(engine,output):
 output.mkdir(parents=True,exist_ok=True)
 state=ROOT/'reference/Presets/lightgarden 02 BT.FXP';assets=ROOT/'reference/Samples'
 prefix=output/'native'
 result=subprocess.run([str(engine.resolve()),str(state),str(assets),str(prefix)],stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
 (output/'native.log').write_text(result.stdout+result.stderr)
 if result.returncode:raise RuntimeError(result.stderr)
 native=json.loads(result.stdout)
 image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes())
 backend=Original(bytes(image.mapped()),0x4000000);h=RenderHost(backend,image)
 obj=0x200000;outer=obj-0xec
 def call(pc,*a):backend.run(pc,list(a));return h.eax()
 def dispatch(op,index=0,value=0,pointer=0):return call(h.word(obj+0x24),obj+0x20,op,index,value,pointer,0)
 def save(program):
  if program:
   backend.write(0x5f0100,bytes(256));dispatch(5,pointer=0x5f0100)
  h.put(0x5f0000,0);n=dispatch(23,int(program),pointer=0x5f0000)
  return backend.read(h.word(0x5f0000),n)
 def restore(chunk,program):
  backend.write(0x600000,chunk)
  if not program:backend.write(outer+0x32b434,b'\1')
  try:
   if dispatch(24,int(program),len(chunk),0x600000)!=len(chunk):raise ValueError('Original rejected the program/bank')
  finally:
   if not program:backend.write(outer+0x32b434,b'\0')
 def edit(tag,value):call(0x1cc86,obj,tag,struct.unpack('<I',struct.pack('<f',value))[0])
 rows=[]
 try:
  for pc in image.initializers:call(pc)
  call(0x48b0,outer,0x70001000)
  for offset,value in [(0,0xf2048),(8,0xf21a8),(0xe4,0xf21b4),(0xec,0xf2208)]:h.put(outer+offset,value)
  call(0xa6a2a,outer);call(0x2918,outer)
  restore(state.read_bytes()[60:],True)
  for g in range(4):
   maximum=3 if g<2 else 2;selector=766+g if g<2 else 772+g
   for kind in range(maximum+1):
    edit(selector,kind/maximum)
    replay=json.loads(Path(str(prefix)+'-inputs.json').read_text())[len(rows)]
    if replay['generator']!=g or replay['type']!=kind:raise ValueError('Native replay case order differs')
    for tag,value in replay['edits']:edit(tag,value)
    original=save(True);path=Path(str(prefix)+f'-g{g}-type{kind}.program');actual=path.read_bytes()
    if actual!=original:
     first=next((i for i,(a,b) in enumerate(zip(actual,original)) if a!=b),min(len(actual),len(original)))
     raise ValueError(f'Generator {g+1} type {kind}: bytes differ at {first} / sizes {len(actual)},{len(original)}')
    transitions=[];bank=save(False)
    for transition in range(3):
     if transition:restore(bank,False);bank=save(False)
     native_bank=Path(str(prefix)+f'-g{g}-type{kind}.bank{transition}').read_bytes()
     if native_bank!=bank:raise ValueError(f'Generator{g+1} type{kind} bank transition{transition} differs from original')
     transitions.append({'transition':transition,'bytes':len(bank),'sha256':hashlib.sha256(bank).hexdigest(),'byte_exact':True})
    rows.append({'generator':g+1,'type':kind,'serialized_program_bytes':len(original),'sha256':hashlib.sha256(original).hexdigest(),'byte_exact':True,'bank_transitions':transitions})
    print(f'Generator {g+1}, type {kind}: original and native program bytes identical',flush=True)
 finally:backend.close()
 report={'passed':True,'scope':'Original i386 vs standalone translated normalized editor controls and bank recall; public fixture, no licence or musical audio','native':native,'cases':rows}
 (output/'comparison.json').write_text(json.dumps(report,indent=2)+'\n')
 return report
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--engine',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();compare(a.engine,a.output)
