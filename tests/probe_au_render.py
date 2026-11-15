#!/usr/bin/env python3
"""Render through the original i386 AU framework in an explicit platform fixture.

This is not Apple's AudioComponent runtime. It preserves the original AU
constructor, stream negotiation, MIDI queue, DoRender and processing methods.
Private input stays in memory and is passed to the unchanged SysGlo setter.
"""
import argparse, ctypes, hashlib, json, math, plistlib, struct, sys
from pathlib import Path
from probe_au_layout import AUPlatformHost, HostedNative, Original, ROOT, LegacyImage

class RenderHost(AUPlatformHost):
 def __init__(self, backend, image):
  super().__init__(backend, image)
  for address, name in [(0x70000200,'<au-beat-tempo>'),(0x70000210,'<au-musical-location>'),(0x70000220,'<au-transport>')]:
   self.names[address]=name
   if isinstance(backend,Original):backend.hook(address,self.callback)
 def callback(self,pc):
  name=self.names.get(pc)
  if name not in ['___dynamic_cast','_pthread_self','_pthread_equal','_CFBundleGetMainBundle','_AUEventListenerNotify','_AUParameterListenerNotify','<au-beat-tempo>','<au-musical-location>','<au-transport>']:
   return super().callback(pc)
  self.last_import={'address':hex(pc),'name':name};self.calls[name]+=1
  sp=self.b.esp();arg=lambda n:self.word(sp+4+4*n);result=0
  if name.startswith('<au-'):result=-50 # Host has no musical/transport callbacks in this fixture.
  elif name=='_pthread_self':result=0x70003000
  elif name=='_pthread_equal':result=int(arg(0)==arg(1))
  elif name=='___dynamic_cast' and arg(0):
   source=self.string(self.word(arg(1)+4)).decode();target=self.string(self.word(arg(2)+4)).decode();vtable=self.word(arg(0));info=self.word(vtable-4)
   if source!='9AUElement' or target!='11AUIOElement' or self.word(vtable-8)!=0 or arg(3) not in [0,0xffffffff]:raise ValueError('Unsupported AU RTTI cast')
   kind=self.string(self.word(info+4)).decode()
   if kind!='9AUElement':
    parents={'17LPAUOutputElement':'15AUOutputElement','16LPAUInputElement':'14AUInputElement','15AUOutputElement':'11AUIOElement','14AUInputElement':'11AUIOElement','11AUIOElement':'9AUElement'}
    while kind!='9AUElement':
     expected=parents.get(kind)
     if expected is None:raise ValueError('Unsupported original AU class '+kind)
     info=self.word(info+8);kind=self.string(self.word(info+4)).decode()
     if kind!=expected:raise ValueError('Unexpected AU RTTI inheritance')
    result=arg(0)
  if isinstance(self.b,Original):
   from unicorn.x86_const import UC_X86_REG_EAX
   self.b.uc.reg_write(UC_X86_REG_EAX,result&0xffffffff)
  else:self.b.regwrite(0,struct.pack('<I',result&0xffffffff))
  self.b.ret()

def run(library,state,channels,seconds,output,registration=None,preferences=None):
 image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes())
 backend=HostedNative(ctypes.CDLL(str(library.resolve())),bytes(image.mapped()),0x4000000) if library else Original(bytes(image.mapped()),0x4000000)
 h=RenderHost(backend,image);h.private_preferences=preferences;outer=0x200000-0xec;obj=0x200000;stage='initializers';error=None;rendered=0;peaks=[];sums=[];wav=None;accepted=False
 def call(pc,*args):backend.run(pc,list(args));return h.eax()
 def checked(pc,*args):
  status=call(pc,*args)
  if status:raise RuntimeError('Original AU error '+hex(status)+' at '+hex(pc))
 raw=state.read_bytes()
 if state.suffix.lower()=='.aupreset':chunk=plistlib.loads(raw)['vstdata'];program=0
 else:
  if raw[:4]!=b'CcnK' or raw[8:12]!=b'FPCh' or struct.unpack_from('>I',raw,56)[0]!=len(raw)-60:raise ValueError('Invalid FXP')
  chunk=raw[60:];program=1
 def restore():
  backend.write(0x600000,chunk)
  if not program:backend.write(outer+0x32b434,b'\x01')
  try:
   if call(h.word(obj+0x24),obj+0x20,24,program,len(chunk),0x600000,0)!=len(chunk):raise RuntimeError('Incomplete state restoration')
  finally:
   if not program:backend.write(outer+0x32b434,b'\0')
 try:
  for pc in image.initializers:call(pc)
  stage='AU constructor';call(0x48b0,outer,0x70001000)
  for offset,value in [(0,0xf2048),(8,0xf21a8),(0xe4,0xf21b4),(0xec,0xf2208)]:h.put(outer+offset,value)
  call(0xa6a2a,outer);call(0x2918,outer)
  for offset,token in [(0xcc,0x70000200),(0xd0,0x70000210),(0xd4,0x70000220)]:h.put(outer+offset,token)
  if registration is not None:
   key=registration.encode('utf8')
   if not key or len(key)>319 or backend.read(obj+0xb4+0x315,1)!=b'\0':raise ValueError('Invalid private registration lifecycle')
   backend.write(0x5e0000,key+b'\0');call(0x12c66,obj+0xb4,0,1,0x5e0000);backend.write(0x5e0000,b'\0'*(len(key)+1));del key
  stage='restore state';restore()
  stage='AU stream format and maximum frames';call(h.word(obj+0x24),obj+0x20,10,0,0,0,struct.unpack('<I',struct.pack('<f',44100))[0])
  backend.write(0x5da000,struct.pack('<d8I',44100,0x6c70636d,0x29,4,1,4,channels,32,0));checked(0xa81f0,outer,8,2,0,0x5da000,40)
  call(h.word(obj+0x24),obj+0x20,11,0,512,0,0);h.put(0x5da100,512);checked(0xa81f0,outer,14,0,0,0x5da100,4)
  stage='AU initialization';checked(0xa65d4,outer);restore();accepted=backend.read(obj+0xcfc8,1)!=b'\0'
  buffers=[h.alloc(512*4) for _ in range(channels)];total=int(44100*seconds);audio=[bytearray() for _ in range(channels)];peaks=[0.0]*channels;sums=[0.0]*channels
  stage='AU note on';call(0x36f0,outer,0x90,0,60,100,0)
  for frame in range(0,total,512):
   n=min(512,total-frame);stage='AU render frame '+str(frame)
   if frame<=88200<frame+n:call(0x36f0,outer,0x80,0,60,0,88200-frame)
   backend.write(0x5d9000,struct.pack('<dQ40xII',frame,0,1,0));h.put(0x5d8f00,0);h.put(0x5d8000,channels)
   for c,p in enumerate(buffers):backend.write(p,b'\0'*2048);backend.write(0x5d8004+c*12,struct.pack('<III',1,n*4,p))
   checked(0xa7014,outer,0x5d8f00,0x5d9000,0,n,0x5d8000)
   for c,p in enumerate(buffers):
    data=backend.read(p,n*4);audio[c].extend(data)
    for (v,) in struct.iter_unpack('<f',data):
     if not math.isfinite(v):raise RuntimeError('Non-finite audio')
     peaks[c]=max(peaks[c],abs(v));sums[c]+=v*v
   rendered+=n
  pcm=bytearray(total*channels*4)
  for i in range(total):
   for c in range(channels):pcm[(i*channels+c)*4:(i*channels+c+1)*4]=audio[c][i*4:i*4+4]
  fmt=struct.pack('<HHIIHH',3,channels,44100,44100*channels*4,channels*4,32);wav=b'RIFF'+struct.pack('<I',36+len(pcm))+b'WAVEfmt '+struct.pack('<I',16)+fmt+b'data'+struct.pack('<I',len(pcm))+pcm
  stage='completed'
 except Exception as e:error=str(e).replace(registration,'<redacted>') if registration else str(e)
 output.parent.mkdir(parents=True,exist_ok=True)
 if wav:output.with_suffix('.wav').write_bytes(wav)
 result={'scope':'Original AU framework in explicit platform fixture, not Apple AudioComponent integration','backend':'static C++' if library else 'original i386 / Unicorn','stage':stage,'error':error,'channels':channels,'frames':rendered,'sample_rate':44100,'maximum_frames':512,'registration_accepted':accepted,'private_registration_input':registration is not None,'private_local_preferences':preferences is not None,'signal_above_minus_100_dbfs':any(p>1e-5 for p in peaks),'peak_per_channel':peaks,'rms_per_channel':[math.sqrt(s/rendered) for s in sums] if rendered else [],'wav_sha256':hashlib.sha256(wav).hexdigest() if wav else None,'host_calls':dict(h.calls),'last_import':h.last_import}
 output.write_text(json.dumps(result,indent=2)+'\n');backend.close();return result

if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--library',type=Path);p.add_argument('--state',type=Path,required=True);p.add_argument('--channels',type=int,choices=[2,6],default=2);p.add_argument('--seconds',type=float,default=3);p.add_argument('--output',type=Path,required=True);p.add_argument('--registration-from-stdin',action='store_true');p.add_argument('--local-mac-preferences',action='store_true');a=p.parse_args()
 if not 0<a.seconds<=30:p.error('seconds must be in (0,30]')
 key=None
 if a.registration_from_stdin:
  key=sys.stdin.readline().rstrip('\r\n')
  if not key or len(key.encode('utf8'))>319:p.error('Invalid private input length')
 prefs=None
 if a.local_mac_preferences:
  if a.registration_from_stdin or sys.platform!='darwin':p.error('Choose local Mac preferences or private stdin')
  import subprocess
  exported=subprocess.run(['/usr/bin/defaults','export','com.linplug.Sophistry','-'],stdout=subprocess.PIPE,stderr=subprocess.PIPE,check=False)
  prefs=plistlib.loads(exported.stdout) if exported.returncode==0 else {}
 result=run(a.library,a.state,a.channels,a.seconds,a.output,key,prefs);print(json.dumps(result,indent=2));sys.exit(1 if result['error'] else 0)
