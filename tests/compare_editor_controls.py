#!/usr/bin/env python3
"""Compare original i386 editor paths/parameters to their static C++ execution."""
import argparse,hashlib,json,math,struct,subprocess
from pathlib import Path
from probe_au_render import RenderHost,Original,LegacyImage,ROOT
from unicorn.x86_const import UC_X86_REG_FP0,UC_X86_REG_FPSW,UC_X86_REG_FPTAG,UC_X86_REG_EIP

class EditorOriginal(Original):
 def run(self,entry,args):
  # Loop-sample restoration integrates the complete public 334,664-frame file.
  sp=0x70f000;self.write(sp,struct.pack('<I'+'I'*len(args),0x500100,*args));self.setesp(sp)
  self.uc.emu_start(entry,0x500100,count=200_000_000)
  if self.uc.reg_read(UC_X86_REG_EIP)!=0x500100:raise RuntimeError('Original editor execution budget exceeded at 0x%x'%self.uc.reg_read(UC_X86_REG_EIP))

class EditorHost(RenderHost):
 def __init__(self,b,image):super().__init__(b,image);self.lines=[];self.point=None
 def callback(self,pc):
  name=self.names.get(pc)
  if name not in ['_CGContextBeginPath','_CGContextMoveToPoint','_CGContextAddLineToPoint','_CGContextDrawPath']:return super().callback(pc)
  sp=self.b.esp();arg=lambda n:self.word(sp+4+4*n)
  if arg(0):raise ValueError('Unexpected reference drawing context')
  if name=='_CGContextBeginPath':self.point=None
  elif name in ['_CGContextMoveToPoint','_CGContextAddLineToPoint']:
   p=struct.unpack('<ff',self.b.read(sp+8,8))
   if name=='_CGContextAddLineToPoint' and self.point is not None:self.lines.append((*self.point,*p,self.word(0x5b0240)))
   self.point=p
  self.b.ret()

def compare(engine,output):
 output.mkdir(parents=True,exist_ok=True);prefix=output/'native'
 run=subprocess.run([str(engine.resolve()),str(ROOT/'reference/Presets/lightgarden 02 BT.FXP'),str(ROOT/'reference/Samples'),str(ROOT/'tests/fixtures/loop-preview.fxp'),str(prefix)],stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
 (output/'native.log').write_text(run.stdout+run.stderr)
 if run.returncode:raise RuntimeError(run.stderr)
 native=json.loads(run.stdout)
 image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes());b=EditorOriginal(bytes(image.mapped()),0x4000000);h=EditorHost(b,image);h.asset_directories=[ROOT/'reference/Samples'];obj=0x200000;outer=obj-0xec
 call=lambda pc,*a:(b.run(pc,list(a)),h.eax())[1]
 def restore(path):
  raw=path.read_bytes()[60:];b.write(0x600000,raw)
  if call(h.word(obj+0x24),obj+0x20,24,1,len(raw),0x600000,0)!=len(raw):raise ValueError('Reference rejected editor fixture')
 def normalized(tag):
  status=b.uc.reg_read(UC_X86_REG_FPSW);tags=b.uc.reg_read(UC_X86_REG_FPTAG);previous=[b.uc.reg_read(UC_X86_REG_FP0+i) for i in range(8)]
  call(h.word(h.word(obj)+0x2b4),obj,tag)
  top=(b.uc.reg_read(UC_X86_REG_FPSW)>>11)&7;mant,exponent=b.uc.reg_read(UC_X86_REG_FP0+top)
  val=0.0 if mant==0 else math.ldexp(mant,(exponent&0x7fff)-16383-63)*(-1 if exponent&0x8000 else 1)
  for i,v in enumerate(previous):b.uc.reg_write(UC_X86_REG_FP0+i,v)
  b.uc.reg_write(UC_X86_REG_FPSW,status);b.uc.reg_write(UC_X86_REG_FPTAG,tags)
  return struct.unpack('<f',struct.pack('<f',val))[0]
 def save_program():
  b.write(0x5f0100,bytes(256));call(h.word(obj+0x24),obj+0x20,5,0,0,0x5f0100,0)
  h.put(0x5f0000,0);n=call(h.word(obj+0x24),obj+0x20,23,1,0,0x5f0000,0);return b.read(h.word(0x5f0000),n)
 def setup(width,height,norm):
  ctl=0x5b0000;ctx=0x5b0200;b.write(ctl,bytes(0x3000));h.lines=[];h.point=None
  for at,v in [(ctl+8,0),(ctl+12,0),(ctl+16,width),(ctl+20,height),(ctl+0x90,0x5b0400),(ctl+0xa4,6),(ctl+0xc4,0xfff0f0f0),(ctx+0x3c,1),(ctx+0x40,0xfff0f0f0)]:h.put(at,v)
  for i,n in enumerate(norm):b.write(0x5b0400+i*24+12,struct.pack('<f',n))
 def check(name,width,height,frames=0,rate=0):
  raw=struct.pack('<6I',1,width,height,len(h.lines),frames,rate)+b''.join(struct.pack('<4fI',*p) for p in h.lines)+bytes((512-len(h.lines))*20)
  actual=Path(str(prefix)+'-'+name+'.bin').read_bytes()
  if raw!=actual:
   first=next((i for i,(a,c) in enumerate(zip(raw,actual)) if a!=c),min(len(raw),len(actual)))
   (output/(name+'-original.bin')).write_bytes(raw)
   raise ValueError(f'Original {name} drawing differs at byte {first}')
  return {'name':name,'byte_exact':True,'segments':len(h.lines),'bytes':len(raw),'sha256':hashlib.sha256(raw).hexdigest()}
 report={}
 try:
  for pc in image.initializers:call(pc)
  call(0x48b0,outer,0x70001000)
  for off,v in [(0,0xf2048),(8,0xf21a8),(0xe4,0xf21b4),(0xec,0xf2208)]:h.put(outer+off,v)
  call(0xa6a2a,outer);call(0x2918,outer);restore(ROOT/'reference/Presets/lightgarden 02 BT.FXP')
  metadata=json.loads(Path(str(prefix)+'-metadata.json').read_text());max_normal_error=0.0;max_ulp=0
  for row in metadata:
   tag=row['tag'];b.write(0x5d4000,bytes(4096));call(0x1d640,obj,tag,0x5d4000);name=h.string(0x5d4000).decode('mac_roman')[:31]
   b.write(0x5d4000,bytes(4096));call(0x1d532,obj,tag,0x5d4000,127);text=h.string(0x5d4000).decode('mac_roman');value=call(0x1d28c,obj,tag);value=value if value<0x80000000 else value-0x100000000
   if (name,text,value)!=(row['name'],row['text'],row['value']):raise ValueError(f'Control{tag} original metadata/value differs')
   expected=normalized(tag);max_normal_error=max(max_normal_error,abs(expected-row['normalized']));max_ulp=max(max_ulp,abs(struct.unpack('<I',struct.pack('<f',expected))[0]-struct.unpack('<I',struct.pack('<f',row['normalized']))[0]))
  if max_ulp>2:raise ValueError(f'Original normalized editor values differ by {max_ulp} ULP')
  drawings=[]
  pairs=[(585,586,40),(587,588,40),(589,590,40),(591,592,40),(593,594,40),(595,596,40),(597,598,60),(599,600,60)]
  for i,(x,y,width) in enumerate(pairs):
   nx,ny=normalized(x),normalized(y);setup(width,width,[nx,ny]);xx=int(struct.unpack('<f',struct.pack('<f',width*struct.unpack('<f',struct.pack('<f',.9999))[0]))[0]*nx);yy=width-int(struct.unpack('<f',struct.pack('<f',width*struct.unpack('<f',struct.pack('<f',.9999))[0]))[0]*ny)-1
   call(0x729d2,0x5b0000,0x5b0200,xx,yy,1);call(0x729d2,0x5b0000,0x5b0200,xx,yy,0);drawings.append(check('xy'+str(i),width,width))
  programs=[]
  for i,edits in enumerate(json.loads(Path(str(prefix)+'-inputs.json').read_text())):
   for tag,n in edits:call(0x1cc86,obj,tag,struct.unpack('<I',struct.pack('<f',n))[0])
   raw=save_program();actual=Path(str(prefix)+f'-edited{i}.program').read_bytes()
   if raw!=actual:raise ValueError(f'Edited Main/Filter program {i} differs')
   programs.append({'case':i,'bytes':len(raw),'byte_exact':True,'sha256':hashlib.sha256(raw).hexdigest()})
  restore(ROOT/'tests/fixtures/loop-preview.fxp');wave=h.word(obj+0x32b070);frames=h.word(wave+0x22c);rate=h.word(wave+0x210)
  norm=[normalized(tag) for tag in [812,814,816,832,946,948]];setup(316,92,norm)
  for at,v in [(0x5b00b0,316),(0x5b00c8,obj+0x32b070),(0x5b00d0,0x5b1000),(0x5b00d4,0x5b2000),(0x5b00d8,1),(0x5b00e0,frames),(0x5b00bc,0xfff0f5f0),(0x5b00c0,0xff646464),(0x5b00c4,0xff7df578)]:h.put(at,v)
  b.write(0x5b00dc,struct.pack('<f',rate));b.write(0x5b00e8,struct.pack('<f',frames/rate))
  call(0x81258,0x5b0000,0x5b3000,0x5b3010);first=struct.unpack('<f',b.read(0x5b3000,4))[0];last=struct.unpack('<f',b.read(0x5b3010,4))[0];span=struct.unpack('<f',struct.pack('<f',last-first))[0]
  b.write(0x5b0300,struct.pack('<4I',0,0,316,92));call(0x8231e,0x5b0000,0x5b0200,0x5b0300,struct.unpack('<I',struct.pack('<f',first))[0],struct.unpack('<I',struct.pack('<f',span))[0]);drawings.append(check('wave',316,92,frames,rate))
  report={'passed':True,'scope':'Original i386 editor/getter/setter/path generation vs static C++; public fixtures, no licence or musical audio','native':native,'control_records_equal':len(metadata),'maximum_normalized_difference_from_json_decimal':max_normal_error,'maximum_normalized_float32_ulp_difference':max_ulp,'drawings':drawings,'edited_programs':programs,'native_cocoa_execution_tested':False}
 finally:b.close()
 (output/'comparison.json').write_text(json.dumps(report,indent=2)+'\n');return report
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--engine',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();compare(a.engine,a.output)
