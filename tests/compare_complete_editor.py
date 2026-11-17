#!/usr/bin/env python3
"""Differential execution of recovered UI data and module IO, without a licence.

Platform-only Nav/FS adapters use virtual files. All module serialization,
parameter conversion, hit testing, and program restoration execute original
instructions under Unicorn and are compared to the static C++ engine.
"""
import argparse, hashlib, json, math, struct, subprocess
from pathlib import Path
from compare_editor_controls import EditorOriginal, EditorHost
from probe_au_render import LegacyImage, ROOT
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_FP0, UC_X86_REG_FPSW, UC_X86_REG_FPTAG

class ModuleHost(EditorHost):
 def __init__(self,b,image):
  super().__init__(b,image);self.selected='';self.save=False;self.written={};self.refs={};self.description={};self.confirm=False;self.alerts=set()
 def callback(self,pc):
  name=self.names.get(pc);sp=self.b.esp();a=lambda i:self.word(sp+4+i*4);result=0
  if name=='_CreateStandardAlert' and self.confirm:
   assert a(0)==2;token=self.alloc(16);self.alerts.add(token);self.put(a(4),token)
  elif name=='_RunStandardAlert' and a(0) in self.alerts:
   self.alerts.remove(a(0));self.b.write(a(2),struct.pack('<H',1))
  elif name=='_usleep':self.monotonic_ticks+=a(0)*1000 # deterministic, no audio thread
  elif name=='_GetDblTime':result=30
  elif name in ['_NewNavEventUPP','_NewNavObjectFilterUPP']:result=self.alloc(16)
  elif name in ['_DisposeNavEventUPP','_DisposeNavObjectFilterUPP','_NavDialogRun','_NavDialogDispose','_NavCompleteSave','_CFPreferencesSetValue']:pass
  elif name=='_CFPreferencesSynchronize':result=1
  elif name=='_NavGetDefaultDialogCreationOptions':self.b.write(a(0),bytes(66))
  elif name in ['_NavCreateChooseFileDialog','_NavCreatePutFileDialog']:
   self.save=name=='_NavCreatePutFileDialog';out=a(5 if self.save else 6);self.put(out,self.alloc(16))
   options=a(0);context=a(4 if self.save else 5)
   self.description={'save':self.save,'title':self.cf_string(self.word(options+14)), 'extensions':[self.cf_string(t).lower() for t in self.opaque_handles[self.word(context)]['value']]}
  elif name=='_NavDialogGetReply':
   reply=a(1);self.b.write(reply,bytes(256))
   if self.selected:
    self.b.write(reply+2,b'\1\1');token=self.alloc(16);self.refs[token]=str(Path(self.selected).parent) if self.save else self.selected
    self.put(reply+6,0x66737266);self.put(reply+10,token);self.put(reply+24,self.new_cf_string(Path(self.selected).name))
  elif name=='_NavDisposeReply':
   if self.word(a(0)+24):self.opaque_handles.pop(self.word(a(0)+24),None)
   self.b.write(a(0),bytes(256))
  elif name=='_AEGetNthPtr':
   self.b.write(a(5),bytes(80));self.put(a(5),self.word(a(0)+4));self.put(a(7),80)
  elif name=='_FSPathMakeRef':result=-43 # no remembered Mac folder mounted in this fixture
  elif name=='_FSRefMakePath':
   text=self.refs[self.word(a(0))].encode();assert len(text)<a(2);self.b.write(a(1),text+b'\0')
  elif name in ['_FSMakeFSRefUnicode','_FSCreateFileUnicode']:
   out=a(5 if name=='_FSCreateFileUnicode' else 4);token=self.alloc(16);self.refs[token]=self.selected;self.b.write(out,bytes(80));self.put(out,token)
  elif name=='_CFURLCreateWithString':result=self.new_cf_string(self.cf_string(a(1)))
  elif name=='_CFURLCreateCopyAppendingPathExtension':result=self.new_cf_string(self.cf_string(a(1))+'.'+self.cf_string(a(2)))
  elif name=='_CFURLGetString':result=a(0)
  elif name=='_CFStringGetCharacters':
   raw=self.cf_string(a(0)).encode('utf-16-le');self.b.write(a(3),raw[a(1)*2:(a(1)+a(2))*2])
  elif name=='_CFNumberCreate':
   assert a(1) in [3,10];result=self.alloc(16);self.opaque_handles[result]={'type':'CFNumber','value':self.word(a(2)),'refs':1}
  elif name=='_fopen' and (self.string(a(1)) in [b'w',b'wb'] or self.string(a(0)).decode() in self.written):
   path=self.string(a(0)).decode();mode=self.string(a(1));result=self.alloc(256)
   self.files[result]={'data':bytearray() if mode in [b'w',b'wb'] else self.written[path], 'position':0,'eof':False,'error':False,'name':Path(path).name,'output':path if mode in [b'w',b'wb'] else None}
  elif name=='_fwrite':
   f=self.files[a(3)];n=a(1)*a(2);raw=self.b.read(a(0),n);pos=f['position'];f['data'][pos:pos+n]=raw;f['position']+=n;result=a(2)
  elif name=='_fclose' and self.files.get(a(0),{}).get('output'):
   f=self.files.pop(a(0));self.written[f['output']]=bytes(f['data']);self.frees.add(a(0))
  else:return super().callback(pc)
  self.b.uc.reg_write(UC_X86_REG_EAX,result&0xffffffff);self.b.ret()

def compare(engine,output):
 output.mkdir(parents=True,exist_ok=True);prefix=output/'native'
 native_run=subprocess.run([str(engine.resolve()),str(ROOT/'reference/Presets/lightgarden 02 BT.FXP'),str(ROOT/'reference/Samples'),str(prefix.resolve())],capture_output=True,text=True)
 (output/'native.log').write_text(native_run.stdout+native_run.stderr)
 if native_run.returncode:raise RuntimeError(native_run.stderr)
 native=json.loads(native_run.stdout);rows=json.loads(Path(str(prefix)+'-metadata.json').read_text())
 image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes());b=EditorOriginal(bytes(image.mapped()),0x4000000);h=ModuleHost(b,image);obj=0x200000;outer=obj-0xec
 call=lambda pc,*a:(b.run(pc,list(a)),h.eax())[1]
 def resolve(tag):
  call(0x1cb52,obj,tag,0x5d1900,0x5d1904,0x5d1908);return struct.unpack('<3I',b.read(0x5d1900,12))
 def edit(tag,value):
  value=struct.unpack('<f',struct.pack('<f',value))[0];module,index,part=resolve(tag)
  call(0x1cc86,obj,tag,struct.unpack('<I',struct.pack('<f',value))[0])
  if tag==647 and b.read(module+0x15c,1)==b'\0':b.write(0x5d1a00,b'Arpeggiator\0');call(0xb5a12,obj+0x44f4,module,part,call(0x1d28c,obj,tag),0x5d1a00)
 def restore(path=None):
  raw=(path if path else ROOT/'reference/Presets/lightgarden 02 BT.FXP').read_bytes()[60:];b.write(0x600000,raw);assert call(h.word(obj+0x24),obj+0x20,24,1,len(raw),0x600000,0)==len(raw)
 def normalized(pc,args):
  status=b.uc.reg_read(UC_X86_REG_FPSW);tags=b.uc.reg_read(UC_X86_REG_FPTAG);previous=[b.uc.reg_read(UC_X86_REG_FP0+i) for i in range(8)]
  call(pc,*args);top=(b.uc.reg_read(UC_X86_REG_FPSW)>>11)&7;mant,exponent=b.uc.reg_read(UC_X86_REG_FP0+top)
  val=0.0 if mant==0 else math.ldexp(mant,(exponent&0x7fff)-16383-63)*(-1 if exponent&0x8000 else 1)
  for i,v in enumerate(previous):b.uc.reg_write(UC_X86_REG_FP0+i,v)
  b.uc.reg_write(UC_X86_REG_FPSW,status);b.uc.reg_write(UC_X86_REG_FPTAG,tags)
  return struct.unpack('<f',struct.pack('<f',val))[0]
 def check_metadata(case):
  for row in [r for r in rows if r['case']==case]:
   tag=row['tag'];assert tag!=765;b.write(0x5d2200,bytes(28));call(0x1ce0e,obj,tag,0x5d2200)
   kind,lo,hi,default,labels,width,curve=struct.unpack('<4i3I',b.read(0x5d2200,28))
   expected={k:v for k,v in zip(['kind','minimum','maximum','default'],[kind,lo,hi,default])}
   value=call(0x1d28c,obj,tag);expected['value']=value if value<2**31 else value-2**32
   for key,pc,limit in [('name_hex',0x1d640,31),('text_hex',0x1ceb2 if kind==7 else 0x1d532,127)]:
    b.write(0x5d4000,bytes(4096));call(pc,obj,tag,0x5d4000,127) if pc==0x1d532 else call(pc,obj,tag,0x5d4000)
    expected[key]=h.string(0x5d4000)[:limit].hex()
   expected['choices']=[b.read(labels+i*width,width).split(b'\0',1)[0][:63].hex() for i in range(hi-lo+1)] if kind==2 and labels else []
   for k,v in expected.items():
    if row[k]!=v:raise ValueError(f'Case {case}, original control {tag}, {k} differs')
   n=normalized(h.word(h.word(obj)+0x2b4),[obj,tag]);actual=row['normalized'];ulp=abs(struct.unpack('<I',struct.pack('<f',n))[0]-struct.unpack('<I',struct.pack('<f',actual))[0])
   if ulp>2:raise ValueError(f'Normalized original control {tag} differs by {ulp} ULP')
   errors.append(ulp)
 checks=[];errors=[]
 def exact(name,data):
  actual=Path(str(prefix)+name).read_bytes()
  if actual!=data:
   (output/('original'+name)).write_bytes(data);raise ValueError(f'Original {name} differs (lengths {len(data)}/{len(actual)})')
  checks.append({'file':name,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest(),'byte_exact':True})
 try:
  for pc in image.initializers:call(pc)
  call(0x48b0,outer,0x70001000)
  for off,v in [(0,0xf2048),(8,0xf21a8),(0xe4,0xf21b4),(0xec,0xf2208)]:h.put(outer+off,v)
  call(0xa6a2a,outer);call(0x2918,outer);restore()
  cases=[None]*9+[(766+g if g<2 else 772+g,t/(3 if g<2 else 2)) for g in range(4) for t in range(4 if g<2 else 3)]+[(213+s,t/11) for s in range(6) for t in range(12)]+[(606,i/3) for i in range(4)]+[(605,i/4) for i in range(5)]
  assert len(cases)==native['pages_and_modes']
  for case,change in enumerate(cases):
   if change:edit(*change)
   check_metadata(case)
  print(len(rows),'original control records and choices matched',flush=True);restore()
  for tag in range(643,648):
   for operation in range(2):
    previous=call(0x1d28c,obj,tag);module,index,part=resolve(tag);h.selected='';edit(tag,operation/4)
    assert h.description['extensions']==['mod'] and h.description['save']==bool(operation)
    store=h.word(module+0x120);params=h.word(h.word(store+0x1c)+4*part);call(0x109c8,params+0x70*index,previous)
  for tag in range(643,648):
   path=str(prefix.resolve())+f'-module{tag}.mod';h.selected=path;edit(tag,.25);exact(f'-module{tag}.mod',h.written[path])
   edit(96 if tag==643 else 13+tag-644 if tag<647 else 649,.25);edit(tag,0)
  for operation in [4,5]:
   previous=call(0x1d28c,obj,610);module,index,part=resolve(610);h.selected='';edit(610,operation/6)
   store=h.word(module+0x120);params=h.word(h.word(store+0x1c)+4*part);call(0x109c8,params+0x70*index,previous)
  h.selected=str(prefix.resolve())+'-midi.mod';edit(610,5/6);exact('-midi.mod',h.written[h.selected]);edit(610,4/6)
  h.selected=''
  for menu,parameter in [(643,96),(644,13)]:edit(parameter,.75);edit(menu,.5);edit(parameter,.25);edit(menu,.75)
  b.write(0x5d6000,bytes(4096));call(0x1ceb2,obj,648,0x5d6000);sequence=bytearray(h.string(0x5d6000));assert len(sequence)==258;sequence[2]=61;sequence[3]=101;b.write(0x5d6000,bytes(sequence)+b'\0');call(0x1cf16,obj,648,0x5d6000)
  edit(647,.5)
  b.write(0x5d6000,bytes(4096));call(0x1ceb2,obj,648,0x5d6000);seq=bytearray(h.string(0x5d6000));seq[2]=73;b.write(0x5d6000,bytes(seq)+b'\0');call(0x1cf16,obj,648,0x5d6000);edit(647,.75)
  b.write(0x5f0100,bytes(256));call(h.word(obj+0x24),obj+0x20,5,0,0,0x5f0100,0);h.put(0x5f0000,0);n=call(h.word(obj+0x24),obj+0x20,23,1,0,0x5f0000,0);exact('-actions.program',b.read(h.word(0x5f0000),n))
  keyboard=0x5a0000;result=0x5a0800;keys=bytearray();b.write(keyboard,bytes(0x900))
  for off,v in [(0x4dc,126),(0x4b8,3),(0x4c8,18),(0x4d0,10),(0x4d4,60),(0x4d8,13)]:h.put(keyboard+off,v)
  for y in [0,30,59,60,94]:
   for x in range(648):assert call(0x942d0,keyboard,x,y,result);keys+=struct.pack('<3I',1,h.word(result+8),h.word(result+12))
  exact('-keys.bin',keys)
  ctl=0x59c000;rect=ctl+0x200;point=ctl+0x220;controls=json.loads((ROOT/'analysis/recovered-editor-layout.json').read_text())['controls'];knobs=bytearray()
  for kind in ['Dial','Drawbar','ThinSlider','Scrollbar']:
   spec=next(c for c in controls if c['kind']==kind and (kind!='Dial' or c['tag']==114));width,height=spec['width'],spec['height']
   b.write(ctl,bytes(0x300));b.write(rect,struct.pack('<4I',0,0,width,height))
   if kind=='Dial':
    call(0x5886,ctl,rect,0,114,0,0,struct.unpack('<I',struct.pack('<f',300))[0],0);values=h.word(ctl+0x90);current=normalized(h.word(h.word(obj)+0x2b4),[obj,114]);row=next(r for r in rows if r['tag']==114)
    linear=struct.unpack('<f',struct.pack('<f',(row['default']-row['minimum'])/(row['maximum']-row['minimum'])))[0]
    call(0x1ce0e,obj,114,0x5d2200);curve=struct.unpack('<f',b.read(0x5d2200+24,4))[0]
    default=struct.unpack('<f',struct.pack('<f',math.log(math.exp(curve)*linear-linear+1)))[0]/curve if abs(curve)>.01 else linear
    b.write(values+4,struct.pack('<f',default));b.write(values+12,struct.pack('<f',current));entry=0x5a12
   else:
    values=ctl+0x240;h.put(ctl+0x90,values);h.put(ctl+16,width);h.put(ctl+20,height);h.put(ctl+0xc8,width);h.put(ctl+0xcc,height)
    b.write(values+12,struct.pack('<f',normalized(h.word(h.word(obj)+0x2b4),[obj,spec['tag']])))
    if kind=='Drawbar':h.put(ctl+0xc4,spec['extra'][0]//2);h.put(ctl+0xcc,height-spec['extra'][0]//2);entry=0x8089a
    elif kind=='ThinSlider':b.write(ctl+0xd8,b'\1');h.put(ctl+0xdc,spec['extra'][0]);h.put(ctl+0xe0,spec['extra'][1]);entry=0x8b04
    else:
     b.write(ctl+0xd4,b'\1');h.put(ctl+0xd8,spec['extra'][1]);b.write(values+36,struct.pack('<f',normalized(h.word(h.word(obj)+0x2b4),[obj,spec['extra'][0]])));entry=0x80cf0
   for y in range(-8,41,4):
    for x in range(-8,41,4):b.write(point,struct.pack('<2i',x,y));knobs+=struct.pack('<f',min(1,max(0,normalized(entry,[ctl,point]))))
  exact('-knobs.bin',knobs)
  restore(ROOT/'tests/fixtures/loop-preview.fxp')
  for tag,target in [(950,1024),(952,4096),(954,32000),(956,8000)]:
   module,index,part=resolve(tag);store=h.word(module+0x120);parameter=h.word(h.word(store+0x1c)+part*4)+index*0x70;previous=call(0x1d28c,obj,tag)
   call(0x109c8,parameter,target);n=normalized(h.word(h.word(obj)+0x2b4),[obj,tag]);call(0x109c8,parameter,previous);edit(tag,n)
  b.write(0x5f0100,bytes(256));call(h.word(obj+0x24),obj+0x20,5,0,0,0x5f0100,0);h.put(0x5f0000,0);n=call(h.word(obj+0x24),obj+0x20,23,1,0,0x5f0000,0);exact('-loop-edited.program',b.read(h.word(0x5f0000),n))
  controls=json.loads((ROOT/'analysis/recovered-editor-layout.json').read_text())['controls']
  for command in [2,3,4,41,42,43]:
   restore()
   if command<10:edit(766,1/3);b.write(0x5d6000,b'BT_cronox18.wav\0');call(0x1cf16,obj,713,0x5d6000)
   spec=next(c for c in controls if c['kind']=='Action' and c['extra'][0]==command and (c['extra'][1]==0 if command<10 else c['extra'][2]==0));args=[v&0xffffffff for v in spec['extra']]
   h.confirm=command in [4,43];assert call(0x4de48,obj,*args,0);h.confirm=False
   b.write(0x5f0100,bytes(256));call(h.word(obj+0x24),obj+0x20,5,0,0,0x5f0100,0);h.put(0x5f0000,0);n=call(h.word(obj+0x24),obj+0x20,23,1,0,0x5f0000,0);exact(f'-sample-action{command}.program',b.read(h.word(0x5f0000),n))

 finally:b.close()
 report={'passed':True,'scope':'Original i386 execution vs statically translated C++; public data, no registration or musical audio','native':native,'control_records':len(rows),'maximum_normalized_ulp':max(errors),'files':checks,'mac_appkit_executed':False}
 (output/'comparison.json').write_text(json.dumps(report,indent=2)+'\n');return report

if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--engine',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();print(json.dumps(compare(a.engine,a.output),indent=2))
