#!/usr/bin/env python3
"""Differential test of statically emitted C++ against original i386 instructions.
Host buffer access and log10 are explicit shared adapters; not a whole-plugin test.
"""
import argparse,collections,ctypes,hashlib,json,math,random,struct,sys
from pathlib import Path
from unicorn import Uc,UC_ARCH_X86,UC_MODE_32,UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_MXCSR,UC_X86_REG_FPSW,UC_X86_REG_FPTAG,UC_X86_REG_FP0
ROOT=Path(__file__).resolve().parents[1];sys.path.insert(0,str(ROOT/'scripts'))
from compare_audio import read_wav
SHA='17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12'
f32=lambda x:struct.unpack('<f',struct.pack('<f',x))[0]
pf=lambda xs:struct.pack('<'+'f'*len(xs),*xs)
u32=lambda b:struct.unpack('<I',b)[0]

def ext80(value):
 bits=struct.unpack('<Q',struct.pack('<d',value))[0];sign=bits>>63;exponent=(bits>>52)&0x7ff;fraction=bits&((1<<52)-1)
 if exponent==0x7ff:return struct.pack('<QH',((1<<63)|(fraction<<11)),(sign<<15)|0x7fff)
 if not exponent:
  if not fraction:return struct.pack('<QH',0,sign<<15)
  leading=fraction.bit_length()-1;mantissa=fraction<<(63-leading);e=leading-1074
 else:mantissa=((1<<52)|fraction)<<11;e=exponent-1023
 return struct.pack('<QH',mantissa,(sign<<15)|(e+16383))

class Native:
 CB=ctypes.CFUNCTYPE(None,ctypes.c_void_p,ctypes.c_uint32,ctypes.c_void_p)
 def __init__(self,lib,image):
  self.l=lib;self.hooks=[];self.callback_error=None
  lib.sl_create.argtypes=[ctypes.c_size_t];lib.sl_create.restype=ctypes.c_void_p
  lib.sl_destroy.argtypes=[ctypes.c_void_p]
  for name in ['sl_mem_read','sl_mem_write','sl_reg_read','sl_reg_write']:
   fn=getattr(lib,name);fn.argtypes=[ctypes.c_void_p,ctypes.c_uint32,ctypes.c_void_p,ctypes.c_size_t];fn.restype=ctypes.c_int
  lib.sl_hook.argtypes=[ctypes.c_void_p,ctypes.c_uint32,self.CB,ctypes.c_void_p];lib.sl_hook.restype=ctypes.c_int
  lib.sl_set_pc.argtypes=[ctypes.c_void_p,ctypes.c_uint32]
  lib.sl_push_double_return.argtypes=[ctypes.c_void_p,ctypes.c_double]
  for name in ['sl_get_pc','sl_get_fault','sl_coverage_count']:
   getattr(lib,name).argtypes=[ctypes.c_void_p];getattr(lib,name).restype=ctypes.c_uint32
  lib.sl_get_steps.argtypes=[ctypes.c_void_p];lib.sl_get_steps.restype=ctypes.c_uint64
  lib.sl_run.argtypes=[ctypes.c_void_p,ctypes.c_uint32,ctypes.c_uint32,ctypes.c_uint64];lib.sl_run.restype=ctypes.c_int
  self.c=lib.sl_create(0x800000)
  if not self.c:raise MemoryError()
  self.write(0,image)
 def close(self):
  if self.c:self.l.sl_destroy(self.c);self.c=None
 def write(self,a,b):
  if self.l.sl_mem_write(self.c,a,b,len(b)):raise ValueError('Native memory write out of range')
 def read(self,a,n):
  b=ctypes.create_string_buffer(n)
  if self.l.sl_mem_read(self.c,a,b,n):raise ValueError('Native memory read out of range')
  return b.raw
 def regwrite(self,a,b):
  if self.l.sl_reg_write(self.c,a,b,len(b)):raise ValueError('Native register write out of range')
 def esp(self):
  b=ctypes.create_string_buffer(4);self.l.sl_reg_read(self.c,0x10,b,4);return u32(b.raw)
 def setesp(self,sp):self.regwrite(0x10,struct.pack('<I',sp))
 def ret(self):
  sp=self.esp();pc=u32(self.read(sp,4));self.setesp(sp+4);self.l.sl_set_pc(self.c,pc)
 def fpreturn(self,value):self.l.sl_push_double_return(self.c,value)
 def hook(self,address,function):
  @self.CB
  def callback(user,at,cpu):
   try:function(at)
   except Exception as e:self.callback_error=e;self.l.sl_set_pc(self.c,0x500100)
  self.hooks.append(callback)
  if self.l.sl_hook(self.c,address,callback,None):raise ValueError('Native callback limit')
 def run(self,entry,args):
  self.callback_error=None;sp=0x70f000;self.write(sp,struct.pack('<I'+'I'*len(args),0x500100,*args));self.setesp(sp)
  result=self.l.sl_run(self.c,entry,0x500100,30_000_000)
  if self.callback_error:raise self.callback_error
  if result:raise RuntimeError('Native fault %d at 0x%x after %d steps'%(result,self.l.sl_get_pc(self.c),self.l.sl_get_steps(self.c)))

class Original:
 def __init__(self,image):
  self.uc=u=Uc(UC_ARCH_X86,UC_MODE_32);u.mem_map(0,0x800000);u.mem_write(0,image);self.hooks=[]
  u.reg_write(UC_X86_REG_MXCSR,0x1f80);u.reg_write(UC_X86_REG_FPSW,0);u.reg_write(UC_X86_REG_FPTAG,0xffff)
 def close(self):pass
 def write(self,a,b):self.uc.mem_write(a,b)
 def read(self,a,n):return bytes(self.uc.mem_read(a,n))
 def esp(self):return self.uc.reg_read(UC_X86_REG_ESP)
 def setesp(self,v):self.uc.reg_write(UC_X86_REG_ESP,v)
 def ret(self):
  sp=self.esp();pc=u32(self.read(sp,4));self.setesp(sp+4);self.uc.reg_write(UC_X86_REG_EIP,pc)
 def fpreturn(self,value):
  # Simulate the x87 return ABI: the callee pushes its double result to ST(0).
  status=self.uc.reg_read(UC_X86_REG_FPSW);top=(((status>>11)&7)-1)&7
  mantissa,exponent=struct.unpack('<QH',ext80(value));self.uc.reg_write(UC_X86_REG_FP0+top,(mantissa,exponent))
  self.uc.reg_write(UC_X86_REG_FPSW,(status&~0x3800)|(top<<11));tag=self.uc.reg_read(UC_X86_REG_FPTAG);self.uc.reg_write(UC_X86_REG_FPTAG,tag&~(3<<(2*top)))
 def hook(self,address,function):
  def call(uc,at,size,user):function(at)
  self.hooks.append(call);self.uc.hook_add(UC_HOOK_CODE,call,begin=address,end=address)
 def run(self,entry,args):
  sp=0x70f000;self.write(sp,struct.pack('<I'+'I'*len(args),0x500100,*args));self.setesp(sp);self.uc.emu_start(entry,0x500100,count=30_000_000)
  if self.uc.reg_read(UC_X86_REG_EIP)!=0x500100:raise RuntimeError('Original execution budget exceeded')

class Host:
 def __init__(self,backend):
  self.b=backend;self.input=[0x220000,0x230000];self.output=[0x240000,0x250000];self.math_calls=0;self.math_trace=[]
  for address in [0x500000,0x500010,0x500020,0x500030,0x500040,0x103311,0x103181,0x10300a]:backend.hook(address,self.callback)
 def put(self,a,v):self.b.write(a,struct.pack('<I',v))
 def callback(self,at):
  sp=self.b.esp()
  if at in [0x103311,0x103181]:
   raw=self.b.read(sp+4,8 if at==0x103311 else 16)
   result=math.log10(struct.unpack('<d',raw)[0]) if at==0x103311 else math.pow(*struct.unpack('<dd',raw))
   self.math_trace.append((at,raw,struct.pack('<d',result)));self.b.fpreturn(result);self.math_calls+=1
  elif at in [0x500000,0x500010,0x500030,0x500040]:
   out=at in [0x500000,0x500030];self.put(u32(self.b.read(sp+8,4)),(self.output if out else self.input)[0])
   if at in [0x500030,0x500040]:self.put(u32(self.b.read(sp+12,4)),(self.output if out else self.input)[1])
  self.b.ret()
 def init(self,channels,n,source,initial,controls,mode,enabled=True,in_place=False):
  self.b.write(0x200000,b'\0'*0xc000)
  self.input=[0x220000,0x230000];self.output=self.input if in_place else [0x240000,0x250000]
  self.put(0x200000,0x206000);self.put(0x2060cc,0xc14e4)
  self.put(0x200010,0x207000);self.put(0x207000,0x208000)
  self.put(0x200118,0x209000);self.put(0x209000,0x20a000);self.put(0x200124,0x20b000 if enabled else 0)
  self.put(0x208034,0x500010);self.put(0x208038,0x500040)
  self.put(0x20a028,0x500000);self.put(0x20a02c,0x500030);self.put(0x20a040,0x500020);self.put(0x20a044,0x500020)
  self.b.write(0x207026,bytes([int(channels==1),int(channels==2)]));self.b.write(0x20015c,b'\1')
  for c in range(channels):self.b.write(self.input[c],pf(source[c]))
  for c in range(2):
   if not in_place:self.b.write(self.output[c],pf(initial[c]))
  for i,values in enumerate(controls):
   pointer=0x260000+0x1000*i;self.b.write(pointer,pf(values));self.put(0x2001e8+i*4,pointer)
  self.b.write(0x204318,struct.pack('<ff',0.0,1.0));self.b.write(0x204324,struct.pack('<f',1.0));self.put(0x20432c,mode&0xffffffff)
 def result(self,n):return self.b.read(self.output[0],4*n)+self.b.read(self.output[1],4*n)

def run(root,library,output):
 image=(root/'reference/Sophistry.i386').read_bytes()
 if hashlib.sha256(image).hexdigest()!=SHA:raise ValueError('Wrong original')
 lib=ctypes.CDLL(str(library.resolve()));native=Native(lib,image);original=Original(image);hosts=[Host(original),Host(native)]
 rng=random.Random(308);mismatches=[];cases=0;samples=0;compared_bytes=0;fixtures=[]
 output.parent.mkdir(parents=True,exist_ok=True)
 _,real=read_wav(root/'reference/Samples/BT_cronox18.wav')
 def check(case_id,entry,args,n,state_size,initial_segments,regions=None):
  nonlocal cases,samples,compared_bytes
  start=len(hosts[0].math_trace);nstart=len(hosts[1].math_trace)
  for h in hosts:h.b.run(entry,args)
  trace=hosts[0].math_trace[start:]
  if trace!=hosts[1].math_trace[nstart:]:raise RuntimeError("Shared math adapter traces differ")
  regions=regions or [(hosts[0].output[0],4*n),(hosts[0].output[1],4*n),(0x200000,state_size)]
  expected_segments=[]
  for address,size in regions:
   expected=original.read(address,size);actual=native.read(address,size);expected_segments.append((address,expected));compared_bytes+=size
   if expected!=actual:
    offset=next(i for i,(a,b) in enumerate(zip(expected,actual)) if a!=b)
    mismatches.append({'case':case_id,'region':hex(address),'byte_offset':offset,'expected_hex':expected[max(0,offset-8):offset+16].hex(),'actual_hex':actual[max(0,offset-8):offset+16].hex()})
    if len(mismatches)>=5:raise RuntimeError('Five differential failures: '+json.dumps(mismatches))
  fixtures.append({'entry':entry,'args':args,'initial':initial_segments,'expected':expected_segments,'math_trace':trace})
  cases+=1;samples+=2*n
 # Generated saturation is compared separately from the manually translated kernel.
 for channels in [1,2]:
  for ip in [False,True]:
   for n in [0,1,7,8,17,64,257]:
    for a in [0.0,0.5,1.0]:
     source=[[f32(rng.uniform(-2,2)) for i in range(n)] for c in range(channels)];initial=[[f32(rng.uniform(-.1,.1)) for i in range(n)] for c in range(2)]
     for h in hosts:
      h.init(channels,n,source,initial,[[],[],[],[]],0,in_place=ip)
      h.b.write(0x2001e0,struct.pack('<ff',f32(a),f32(1.001-f32(a))))
     seg=[(0x200000,original.read(0x200000,0xc000))]+[(p,original.read(p,n*4)) for p in sorted(set(hosts[0].input+hosts[0].output))]
     check('satur-%d-%s-%d-%s'%(channels,ip,n,a),0x73fb0,[0x200000,n],n,0x210,seg)
 # Four filter modes, mono/stereo input, boundary/control-rate sizes and real WAV material.
 for channels in [1,2]:
  for mode in [-1,0,1,2]:
   for n in [0,1,7,8,9,32,64,257]:
    controls=[[f32(v) for v in row] for row in [[.08+.9*rng.random() for i in range((n+7)//8)],[.95*rng.random() for i in range((n+7)//8)],[.05+.05*rng.random() for i in range((n+7)//8)],[-.8+1.6*rng.random() for i in range((n+7)//8)]]]
    source=[[real[((20000+i)*2+c)%len(real)] for i in range(n)] for c in range(channels)]
    initial=[[f32(rng.uniform(-.01,.01)) for i in range(n)] for c in range(2)]
    for h in hosts:h.init(channels,n,source,initial,controls,mode)
    seg=[(0x200000,original.read(0x200000,0xc000))]+[(p,original.read(p,n*4)) for p in hosts[0].input+hosts[0].output]+[(0x260000+i*0x1000,pf(v)) for i,v in enumerate(controls)]
    check('filter-%d-%d-%d'%(channels,mode,n),0x7a1ac,[0x200000,n],n,0x4330,seg)
 # Actual sample preparation through the original selected routines.
 sr,channels,frames=read_wav(root/'reference/Samples/BT_cronox18.wav')[0]
 wave=0x2001d8;left=0x300000;right=0x480000;table=0x280000
 for h in hosts:
  h.init(2,0,[[],[]],[[],[]],[[],[],[],[]],0)
  h.b.write(left,pf(real[0::2]));h.b.write(right,pf(real[1::2]))
  h.put(wave+0x210,sr);h.put(wave+0x21c,left);h.put(wave+0x220,right);h.put(wave+0x22c,frames)
 seg=[(0x200000,original.read(0x200000,0xc000)),(left,original.read(left,frames*4)),(right,original.read(right,frames*4))]
 check('sample-stereo-to-mono',0xaf2b2,[wave],0,0x500,seg,[(left,frames*4),(0x200000,0x500)])
 seg=[(0x200000,original.read(0x200000,0xc000)),(left,original.read(left,frames*4))]
 check('sample-normalize',0x32430,[wave,left,frames],0,0x500,seg,[(left,frames*4),(0x200000,0x500)])
 mono_sha=hashlib.sha256(original.read(left,frames*4)).hexdigest()
 for h in hosts:h.put(0x2001d4,table);h.b.write(table,b'\0'*(32768+1024))
 seg=[(0x200000,original.read(0x200000,0xc000)),(left,original.read(left,frames*4)),(table,original.read(table,32768+1024))]
 check('schrader-prepare-64-tables',0x8de6a,[0x200000,0,60,0,frames-1],0,0x500,seg,[(table,32768+1024),(0x200000,0x500)])
 table_sha=hashlib.sha256(original.read(table,32768)).hexdigest()
 (output.parent/'schrader-wavetables-reference.bin').write_bytes(original.read(table,32768))
 # Exercise the table player with explicit synthetic modulation/routing, not a full preset graph.
 for routing in [0,1,2]:
  for voice in [0,4]:
   for n in [0,1,7,8,129,257]:
    controls=[[f32(.4) for i in range((n+7)//8)],[f32(0.) for i in range((n+7)//8)],[f32(-.1+.2*rng.random()) for i in range((n+7)//8)],[]]
    for h in hosts:
     h.init(1,n,[[f32(.9+.2*rng.random()) for i in range(n)]],[[0.]*n,[0.]*n],controls,0)
    # Both hosts must receive identical modulation input.
    native.write(0x220000,original.read(0x220000,n*4))
    for h in hosts:
     h.put(0x2001dc,routing);h.b.write(0x2001e8,struct.pack('<f',1.));h.put(0x200218,table)
     h.put(0x2001f8,0x260000);h.put(0x2001fc,0x261000);h.put(0x200200,0x262000)
     h.b.write(0x20021c+voice*8,struct.pack('<d',127.5));h.b.write(0x200244+voice*8,struct.pack('<d',63.9))
     h.b.write(0x20026c,struct.pack('<d',261.6255653005986*128/sr));h.b.write(0x20027c,struct.pack('<d',512/frames));h.put(0x200288,0x290000);h.b.write(0x290000,pf([1.]*max(n,1)))
    seg=[(0x200000,original.read(0x200000,0xc000)),(0x220000,original.read(0x220000,n*4)),(0x240000,b'\0'*(n*4)),(0x250000,b'\0'*(n*4)),(table,original.read(table,32768+1024)),(0x290000,original.read(0x290000,4*max(n,1)))]+[(0x260000+i*0x1000,pf(v)) for i,v in enumerate(controls)]
    check('schrader-player-%d-%d-%d'%(routing,voice,n),0x38f48,[0x200000,n,voice],n,0x300,seg)
 # Continuous three-second isolated Schrader probe; no envelope/filter/effects chain.
 render_ref=[];render_cpp=[];canonical=original.read(table,32768+1024);total=3*sr
 for h in hosts:
  h.init(1,256,[[1.]*256],[[0.]*256,[0.]*256],[[],[],[],[]],0)
  h.put(0x2001dc,0);h.b.write(0x2001e8,struct.pack('<f',1.));h.put(0x200218,table)
  h.put(0x2001f8,0x260000);h.put(0x2001fc,0x261000);h.put(0x200200,0x262000)
  h.b.write(0x20021c,struct.pack('<d',0.));h.b.write(0x200244,struct.pack('<d',0.))
  h.b.write(0x20026c,struct.pack('<d',261.6255653005986*128/sr));h.b.write(0x20027c,struct.pack('<d',512/frames));h.put(0x200288,0x290000);h.b.write(0x290000,pf([1.]*256));h.b.write(table,canonical)
 for start in range(0,total,256):
  n=min(256,total-start);control=[[.4]*((n+7)//8),[0.]*((n+7)//8),[0.]*((n+7)//8)]
  for h in hosts:
   h.b.write(0x240000,b'\0'*(n*4));h.b.write(0x250000,b'\0'*(n*4))
   for i,v in enumerate(control):h.b.write(0x260000+i*0x1000,pf(v))
  seg=[(0x200000,original.read(0x200000,0xc000 if start==0 else 0x300)),(0x240000,b'\0'*(n*4)),(0x250000,b'\0'*(n*4))]+[(0x260000+i*0x1000,pf(v)) for i,v in enumerate(control)]
  if start==0:seg +=[(table,canonical),(0x290000,original.read(0x290000,1024))]
  check('continuous-schrader-%d'%start,0x38f48,[0x200000,n,0],n,0x300,seg)
  render_ref.extend(struct.unpack('<'+'f'*n,original.read(0x240000,n*4)));render_cpp.extend(struct.unpack('<'+'f'*n,native.read(0x240000,n*4)))
 def write_wave(path,values):
  data=pf(values);fmt=struct.pack('<HHIIHH',3,1,sr,sr*4,4,32);body=b'WAVE'+b'fmt '+struct.pack('<I',len(fmt))+fmt+b'fact'+struct.pack('<II',4,len(values))+b'data'+struct.pack('<I',len(data))+data;path.write_bytes(b'RIFF'+struct.pack('<I',len(body))+body)
 audio=output.parent/'audio';audio.mkdir(exist_ok=True)
 write_wave(audio/'schrader-root60-original-instructions.wav',render_ref);write_wave(audio/'schrader-root60-lifted-cpp.wav',render_cpp)
 if max(abs(x) for x in render_ref)<=1e-8:raise RuntimeError('Schrader audio probe is silent')
 report={'scope':'Selected statically lifted saturation, filter, sample preparation and Schrader routines; not full DSP engine or AU','original_sha256':SHA,'cases':cases,'compared_audio_samples':samples,'compared_bytes':compared_bytes,'continuous_schrader_frames':total,'continuous_schrader_sample_rate':sr,'bit_exact_audio_and_object_state':not mismatches,'mismatches':mismatches,'native_executed_instruction_addresses':lib.sl_coverage_count(native.c),'exported_instructions':sum(1 for _ in (root/'analysis/lifter-all/instructions.jsonl').open()),'shared_host_math_calls_in_original':hosts[0].math_calls,'shared_host_math_calls_in_lift':hosts[1].math_calls,'sample_source':'BT_cronox18.wav','normalized_mono_sample_sha256':mono_sha,'schrader_64_tables_sha256':table_sha,'x86_runtime_decoder_in_lift':False,'host_math_note':'Both executions use Python math.log10/math.pow and a no-op free for host-owned buffers through explicit ABI adapters; original Apple libm and file decoder have not been executed','architecture_executed':'Linux x86_64 C++ build','apple_silicon_executed':False,'project_reopening_tested':False}
 output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(report,indent=2)+'\n')
 # Binary fixture captures the actual input segments and original expected outputs.
 path=output.with_suffix('.fixtures');data=bytearray(b'SLFT0003'+struct.pack('<I',len(fixtures)))
 for f in fixtures:
  data+=struct.pack('<III',f['entry'],len(f['args']),len(f['initial']))+struct.pack('<'+'I'*len(f['args']),*f['args'])
  for address,blob in f['initial']:data+=struct.pack('<II',address,len(blob))+blob
  data+=struct.pack('<I',len(f['expected']))
  for address,blob in f['expected']:data+=struct.pack('<II',address,len(blob))+blob
  data+=struct.pack('<I',len(f['math_trace']))
  for address,arg,result in f['math_trace']:data+=struct.pack('<II',address,len(arg))+arg+result
 path.write_bytes(data);native.close();return report
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('library',type=Path);p.add_argument('--root',type=Path,default=ROOT);p.add_argument('--output',type=Path,required=True);n=p.parse_args();print(json.dumps(run(n.root,n.library,n.output),indent=2))
