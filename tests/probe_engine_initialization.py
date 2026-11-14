#!/usr/bin/env python3
"""Probe original global/constructor control flow with explicitly limited host adapters.
This is not an AU, a completed engine host, or an audio-rendering test.
"""
import argparse,collections,ctypes,ctypes.util,hashlib,json,struct,sys,math
from pathlib import Path
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_EIP
from compare_lifted_dsp import Native,Original
ROOT=Path(__file__).resolve().parents[1];sys.path.insert(0,str(ROOT/'scripts'))
from legacy_image import LegacyImage
class HostedNative(Native):
 # Yield at an unbound import and service it through an explicit host adapter.
 # The guest CPU and stack are retained; no original x86 bytes are decoded.
 external_driver=True
 def run(self,entry,args):
  self.callback_error=None;sp=0x70f000;self.write(sp,struct.pack('<'+'I'*(len(args)+1),0x500100,*args));self.setesp(sp)
  remaining=30_000_000
  while remaining>0:
   result=self.l.sl_run(self.c,entry,0x500100,remaining)
   remaining-=self.l.sl_get_steps(self.c)
   if not result:return
   pc=self.l.sl_get_pc(self.c)
   if result!=3 or pc not in self.external_host.names:raise RuntimeError(f'Native fault {result} at 0x{pc:x}')
   self.external_host.callback(pc);entry=self.l.sl_get_pc(self.c)
  raise RuntimeError('Native instruction budget exceeded')
class Host:
 MATH32={'expf','powf','sinf','cosf','tanf','sqrtf','logf','log10f','floorf','ceilf','fabsf','atan2f','fmodf'}
 SUPPORTED={'__Znwm','__Znam','__ZdlPv','__ZdaPv','_malloc','_calloc','_realloc','_free',
  '_memcpy','_memmove','_memset','_memcmp','_bzero','_strlen','_strcpy','_strncpy','_strcmp','_strncmp',
  '___cxa_atexit','_OSAtomicAdd32Barrier',
  '_pthread_mutexattr_init','_pthread_mutexattr_settype','_pthread_mutexattr_destroy',
  '_pthread_mutex_init','_pthread_mutex_destroy','_pthread_mutex_lock','_pthread_mutex_trylock','_pthread_mutex_unlock',
  '_sin','_cos','_tan','_atan','_asin','_acos','_log','_log10','_exp','_pow','_sqrt','_floor','_ceil','_fabs','_atan2','_fmod',
  '_CMOpenProfile','_CGColorSpaceCreateDeviceRGB','_CFBundleGetBundleWithIdentifier','_atexit','<vst-host>',
  '__keymgr_get_and_lock_processwide_ptr_2','__keymgr_set_and_unlock_processwide_ptr','_dlopen','_random','_srandom','_srand','_rand','_time','_gettimeofday','_mach_timebase_info','_mach_absolute_time'}
 SUPPORTED|={'_'+name for name in MATH32}
 def __init__(self,backend,image):
  self.b=backend;self.names={x['address']:x['name'] for x in image.stubs};self.names[0x70000000]='<vst-host>'
  self.heap=0x800000;self.allocations={};self.frees=set();self.calls=collections.Counter();self.destructors=[];self.last_import=None
  self.mutex_attributes={};self.mutexes={};self.opaque_handles={};self.unavailable_bundles=[]
  self.process_keys={};self.locked_keys=set();self.unavailable_libraries=[]
  self.seed_random(1)
  self.rand_seed=1
  self.clock=1794675600 # Fixed current task date: 2026-11-14 17:00 UTC, test inputs only.
  self.monotonic_ticks=0
  self.libm=ctypes.CDLL(ctypes.util.find_library('m'));self.math32={}
  for name in self.MATH32:
   fn=getattr(self.libm,name);fn.argtypes=[ctypes.c_float]*(2 if name in ['powf','atan2f','fmodf'] else 1);fn.restype=ctypes.c_float;self.math32[name]=fn
  if isinstance(backend,Original):
   def callback(uc,pc,size,user):self.callback(pc)
   backend.uc.hook_add(UC_HOOK_CODE,callback,begin=0x103000,end=0x1037e3);self.original_hook=callback
   backend.uc.mem_map(0x70000000,0x1000);backend.hook(0x70000000,self.callback)
  elif getattr(backend,'external_driver',False):backend.external_host=self
  else:
   for at,name in self.names.items():
    if name in self.SUPPORTED:backend.hook(at,self.callback)
 def word(self,address):return struct.unpack('<I',self.b.read(address,4))[0]
 def seed_random(self,seed):
  seed=seed&0xffffffff or 1;self.random_state=[seed];value=seed if seed<0x80000000 else seed-(1<<32)
  for _ in range(30):value=(16807*value)%2147483647;self.random_state.append(value)
  self.random_front=3;self.random_rear=0
  for _ in range(310):self.next_random()
 def next_random(self):
  value=(self.random_state[self.random_front]+self.random_state[self.random_rear])&0xffffffff
  self.random_state[self.random_front]=value
  self.random_front=(self.random_front+1)%31;self.random_rear=(self.random_rear+1)%31
  return value>>1
 def put(self,address,value):self.b.write(address,struct.pack('<I',value&0xffffffff))
 def alloc(self,n):
  if n>0x2000000 or self.heap+max(n,1)+16>0x3e00000:raise MemoryError('Guest heap limit')
  p=self.heap;self.heap+=(max(n,1)+15)&~15;self.allocations[p]=n;return p
 def string(self,p,limit=65536):
  data=bytearray()
  for block in range(0,limit,256):
   raw=self.b.read(p+block,min(256,limit-block))
   if b'\0' in raw:return bytes(data)+raw.split(b'\0',1)[0]
   data.extend(raw)
  raise ValueError('Unterminated guest string')
 def callback(self,pc):
  name=self.names.get(pc);self.last_import={'address':hex(pc),'name':name};self.calls[name]+=1
  if name not in self.SUPPORTED:raise RuntimeError('Unimplemented host import '+str(name))
  sp=self.b.esp();arg=lambda i:self.word(sp+4+4*i);result=0;floating=None;integer64=None
  if name in ['__Znwm','__Znam','_malloc']:result=self.alloc(arg(0))
  elif name=='_calloc':
   n=arg(0)*arg(1);result=self.alloc(n);self.b.write(result,b'\0'*n)
  elif name=='_realloc':
   p,n=arg(0),arg(1);result=self.alloc(n)
   if p:
    if p not in self.allocations or p in self.frees:raise ValueError('Invalid realloc token')
    self.b.write(result,self.b.read(p,min(n,self.allocations[p])));self.frees.add(p)
  elif name in ['__ZdlPv','__ZdaPv','_free']:
   p=arg(0)
   if p:
    if p not in self.allocations or p in self.frees:raise ValueError('Invalid free token '+hex(p))
    self.frees.add(p)
  elif name in ['_memcpy','_memmove']:
   result=arg(0);self.b.write(result,self.b.read(arg(1),arg(2)))
  elif name in ['_memset','_bzero']:
   result=arg(0);value=arg(1)&255 if name=='_memset' else 0;n=arg(2) if name=='_memset' else arg(1)
   if n>0x2000000:raise ValueError('Unexpected memset size')
   self.b.write(result,bytes([value])*n)
  elif name=='_memcmp':
   a,b=self.b.read(arg(0),arg(2)),self.b.read(arg(1),arg(2));result=next((x-y for x,y in zip(a,b) if x!=y),0)
  elif name=='_strlen':result=len(self.string(arg(0)))
  elif name=='_strcpy':result=arg(0);self.b.write(result,self.string(arg(1))+b'\0')
  elif name=='_strncpy':
   result=arg(0);n=arg(2)
   if n>0x100000:raise ValueError('Unexpected strncpy size')
   raw=self.b.read(arg(1),n).split(b'\0',1)[0];self.b.write(result,raw+b'\0'*(n-len(raw)))
  elif name in ['_strcmp','_strncmp']:
   n=arg(2) if name=='_strncmp' else 65536
   if n>65536:raise ValueError('Unexpected string comparison size')
   a=self.string(arg(0))[:n];b=self.string(arg(1))[:n]
   result=next((x-y for x,y in zip(a+b'\0',b+b'\0') if x!=y),0)
  elif name=='___cxa_atexit':self.destructors.append([arg(i) for i in range(3)])
  elif name=='_atexit':self.destructors.append([arg(0),0,0])
  elif name=='_OSAtomicAdd32Barrier':
   # This harness owns a single guest CPU; no concurrent VM access is allowed.
   result=(arg(0)+self.word(arg(1)))&0xffffffff;self.put(arg(1),result)
  elif name=='_pthread_mutexattr_init':self.mutex_attributes[arg(0)]=0
  elif name=='_pthread_mutexattr_settype':
   if arg(0) not in self.mutex_attributes or arg(1) not in [0,1,2]:result=22
   else:self.mutex_attributes[arg(0)]=arg(1)
  elif name=='_pthread_mutexattr_destroy':
   if arg(0) not in self.mutex_attributes:result=22
   else:del self.mutex_attributes[arg(0)]
  elif name=='_pthread_mutex_init':
   if arg(1) and arg(1) not in self.mutex_attributes:result=22
   else:self.mutexes[arg(0)]={'type':self.mutex_attributes.get(arg(1),0),'depth':0}
  elif name in ['_pthread_mutex_lock','_pthread_mutex_trylock']:
   mutex=self.mutexes.get(arg(0))
   if mutex is None:result=22
   elif mutex['depth'] and mutex['type']!=2:
    if name=='_pthread_mutex_trylock':result=16
    elif mutex['type']==1:result=11 # Darwin EDEADLK
    else:raise RuntimeError('A blocking mutex cannot progress in this single-CPU initialization probe')
   else:mutex['depth']+=1
  elif name=='_pthread_mutex_unlock':
   mutex=self.mutexes.get(arg(0))
   if mutex is None:result=22
   elif not mutex['depth']:result=1
   else:mutex['depth']-=1
  elif name=='_pthread_mutex_destroy':
   mutex=self.mutexes.get(arg(0))
   if mutex is None:result=22
   elif mutex['depth']:result=16
   else:del self.mutexes[arg(0)]
  elif name[1:] in ['sin','cos','tan','atan','asin','acos','log','log10','exp','pow','sqrt','floor','ceil','fabs','atan2','fmod']:
   count=2 if name in ['_pow','_atan2','_fmod'] else 1
   args=struct.unpack('<'+'d'*count,self.b.read(sp+4,8*count))
   floating=float(getattr(math,name[1:])(*args))
  elif name[1:] in self.MATH32:
   count=2 if name in ['_powf','_atan2f','_fmodf'] else 1
   args=struct.unpack('<'+'f'*count,self.b.read(sp+4,4*count));floating=self.math32[name[1:]](*args)
  elif name=='_CMOpenProfile':
   # Explicit test scenario: no system ColorSync profile is available in Linux.
   # Exercise the original error/fallback branch, without patching its code.
   self.put(arg(0),0);result=-4200
  elif name=='_CGColorSpaceCreateDeviceRGB':
   result=self.alloc(16);self.opaque_handles[result]={'type':'CGColorSpace','model':'DeviceRGB'}
  elif name=='_CFBundleGetBundleWithIdentifier':
   ptr=arg(0);isa,flags,data,length=struct.unpack('<4I',self.b.read(ptr,16))
   identifier=self.b.read(data,length).decode('utf8')
   if identifier!='com.apple.CoreGraphics':raise RuntimeError('Unimplemented bundle registry lookup '+identifier)
   self.unavailable_bundles.append(identifier);result=0 # Explicit Linux test environment: no Apple framework bundle.
  elif name=='<vst-host>':
   opcode=arg(1)
   if opcode==1:result=2400
   elif opcode==2:result=0x536f7033
   elif opcode==16:result=48000
   elif opcode==17:result=512
   elif opcode in [32,33]:
    self.b.write(arg(4),b'Sophistry checkpoint host\0');result=1
   elif opcode==34:result=1
   # VST2 defines 0 for unsupported optional host requests.
  elif name=='__keymgr_get_and_lock_processwide_ptr_2':
   key=arg(0)
   if key in self.locked_keys:raise RuntimeError('Process key already locked')
   self.locked_keys.add(key);self.put(arg(1),self.process_keys.get(key,0))
  elif name=='__keymgr_set_and_unlock_processwide_ptr':
   key=arg(0)
   if key not in self.locked_keys:result=22
   else:self.process_keys[key]=arg(1);self.locked_keys.remove(key)
  elif name=='_dlopen':
   path=self.string(arg(0)).decode('utf8')
   if path!='/usr/lib/libSystem.B.dylib':raise RuntimeError('Unimplemented dynamic library '+path)
   self.unavailable_libraries.append(path);result=0 # The original Apple library is absent in this Linux test host.
  elif name=='_random':result=self.next_random()
  elif name=='_srandom':self.seed_random(arg(0))
  elif name=='_srand':self.rand_seed=arg(0)
  elif name=='_rand':
   # Park-Miller generator used by Darwin's FreeBSD rand.c, with its zero-seed rule.
   self.rand_seed=(16807*(self.rand_seed or 123459876))%2147483647;result=self.rand_seed
  elif name=='_time':
   result=self.clock
   if arg(0):self.put(arg(0),result)
  elif name=='_gettimeofday':
   if arg(0):self.b.write(arg(0),struct.pack('<II',self.clock,0))
   if arg(1):self.b.write(arg(1),b'\0'*8)
  elif name=='_mach_timebase_info':self.b.write(arg(0),struct.pack('<II',1,1))
  elif name=='_mach_absolute_time':
   self.monotonic_ticks+=1000;integer64=self.monotonic_ticks;result=integer64&0xffffffff
  if integer64 is not None:
   high=integer64>>32
   if isinstance(self.b,Original):self.b.uc.reg_write(UC_X86_REG_EDX,high)
   else:self.b.regwrite(8,struct.pack('<I',high))
  if floating is not None:self.b.fpreturn(floating)
  if isinstance(self.b,Original):self.b.uc.reg_write(UC_X86_REG_EAX,result&0xffffffff)
  else:self.b.regwrite(0,struct.pack('<I',result&0xffffffff))
  self.b.ret()
def probe(library,output,construct=False,open_effect=False):
 image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes())
 backend=HostedNative(ctypes.CDLL(str(library.resolve())),bytes(image.mapped()),0x4000000) if library else Original(bytes(image.mapped()),0x4000000)
 host=Host(backend,image);completed=[];error=None;stage='global initialization';constructed=False;opened=False
 try:
  for at in image.initializers:backend.run(at,[]);completed.append(hex(at))
  if construct:
   stage='Kaja constructor';backend.run(0x4e876,[0x200000,0x70000000]);constructed=True
  if open_effect:
   if not constructed:raise ValueError('--open requires --construct')
   stage='VST effOpen';backend.run(host.word(0x200024),[0x200020,0,0,0,0,0]);opened=True
 except Exception as e:error=str(e)
 pc=backend.l.sl_get_pc(backend.c) if isinstance(backend,Native) else backend.uc.reg_read(UC_X86_REG_EIP)
 r={'scope':'Global initialization progress with a limited explicit host; not a complete synth or native Audio Unit',
  'backend':'statically emitted C++' if library else 'original i386 / Unicorn','completed_initializers':len(completed),'total_initializers':len(image.initializers),
  'completed_entries':completed,'error':error,'stage':stage,'Kaja_constructor_returned':constructed,'effOpen_returned':opened,'stopped_pc':hex(pc),'last_import':host.last_import,
  'unhandled_import':host.names.get(pc),'host_import_calls':dict(host.calls),'heap_bytes_reserved':host.heap-0x800000,
  'allocator':'bounded deterministic guest bump allocator; freed tokens tracked, no reuse; test-only','test_time_epoch':host.clock,
  'engine_object_sha256':hashlib.sha256(backend.read(0x200000,0x340000)).hexdigest(),
  'guest_heap_sha256':hashlib.sha256(backend.read(0x800000,host.heap-0x800000)).hexdigest(),
  'effect_fields':{'magic':hex(host.word(0x200020)),'dispatcher':hex(host.word(0x200024)),'num_programs':host.word(0x200034),'num_parameters':host.word(0x200038),'unique_id':hex(host.word(0x200068))} if constructed else None,
  'registered_destructors':len(host.destructors),'guest_mutexes':host.mutexes,'mutex_adapter':'single-CPU state machine; no concurrent guest access; blocking operations stop the probe','math_adapter':'Python/Linux math; not original Apple i386 libm','random_adapter':'Frozen BSD degree-31 stream, initial seed 1; shared test inputs, not an original-OS random capture','graphics_adapter':'Explicit unavailable-ColorSync-profile and CoreGraphics-bundle scenario; DeviceRGB is an opaque test handle, no rendering','unavailable_framework_bundles':host.unavailable_bundles,'unavailable_dynamic_libraries':host.unavailable_libraries,'original_global_destructor_registration_complete':False,'global_memory_sha256':hashlib.sha256(backend.read(0xe2000,0x104000-0xe2000)).hexdigest(),
  'full_engine_initialized':False,'preset_restored':False,'audio_rendered':False}
 output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(r,indent=2)+'\n')
 backend.close();return r
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--library',type=Path);p.add_argument('--output',type=Path,required=True);p.add_argument('--construct',action='store_true');p.add_argument('--open',action='store_true');n=p.parse_args()
 r=probe(n.library,n.output,n.construct,n.open);print(json.dumps({k:r[k] for k in ['backend','completed_initializers','total_initializers','stage','Kaja_constructor_returned','effOpen_returned','error','stopped_pc','last_import','unhandled_import','heap_bytes_reserved','effect_fields']},indent=2))
