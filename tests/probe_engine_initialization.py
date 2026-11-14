#!/usr/bin/env python3
"""Probe original initialization/state/render paths with explicit host adapters.
This diagnostic harness is not a native Audio Unit or a complete platform host.
"""
import argparse,array,collections,ctypes,ctypes.util,hashlib,json,struct,sys,math,re
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
  '_memcpy','_memmove','_memset','_memcmp','_bzero','_strlen','_strcpy','_strncpy','_strcmp','_strncmp','_strcasecmp','_strncasecmp','_strstr','_strchr','_strrchr','_strdup',
  '___cxa_atexit','_OSAtomicAdd32Barrier',
  '_pthread_mutexattr_init','_pthread_mutexattr_settype','_pthread_mutexattr_destroy',
  '_pthread_mutex_init','_pthread_mutex_destroy','_pthread_mutex_lock','_pthread_mutex_trylock','_pthread_mutex_unlock',
  '_sin','_cos','_tan','_atan','_asin','_acos','_log','_log10','_exp','_pow','_sqrt','_floor','_ceil','_fabs','_atan2','_fmod',
  '_CMOpenProfile','_CGColorSpaceCreateDeviceRGB','_CFBundleGetBundleWithIdentifier','_atexit','<vst-host>',
  '__keymgr_get_and_lock_processwide_ptr_2','__keymgr_set_and_unlock_processwide_ptr','_dlopen','_random','_srandom','_srand','_rand','_time','_gettimeofday','_mach_timebase_info','_mach_absolute_time',
  '_GetMainEventLoop','_NewEventLoopTimerUPP','_InstallEventLoopTimer','_RemoveEventLoopTimer','_DisposeEventLoopTimerUPP','_SetEventLoopTimerNextFireTime',
  '_fopen','_fclose','_fread','_fseek','_ftell','_rewind','_feof','_ferror','_clearerr','_fflush','_fgetc','_getc','_fgets','_fgetpos','_fsetpos',
  '_AudioConverterNew','_AudioConverterFillComplexBuffer','_AudioConverterDispose','<converter-input-return>','_FSFindFolder',
  '_CFStringCreateWithCString','_CFStringCreateCopy','_CFStringGetLength','_CFStringGetCString','_CFStringGetCStringPtr','_CFStringCompare',
  '_CFStringGetSystemEncoding','_CFStringGetTypeID','_CFGetTypeID','_CFRetain','_CFRelease',
  '_CFPreferencesCopyAppValue','_CFPreferencesCopyValue','_CFPreferencesGetAppBooleanValue','_CFPreferencesGetAppIntegerValue','_CFPreferencesAppSynchronize',
  '_sprintf','_snprintf','_vsprintf','_vsnprintf','_opendir','___error','_atol','_atoi',
  '_CFArrayCreateMutable','_CFArrayAppendValue','_CFArrayGetValueAtIndex','_CFArrayGetCount','_CFArrayCreateCopy'}
 SUPPORTED|={'_'+name for name in MATH32}
 def __init__(self,backend,image):
  self.b=backend;self.names={x['address']:x['name'] for x in image.stubs};self.names[0x70000000]='<vst-host>';self.names[0x70000100]='<converter-input-return>'
  self.heap=0x800000;self.allocations={};self.frees=set();self.calls=collections.Counter();self.destructors=[];self.last_import=None
  self.mutex_attributes={};self.mutexes={};self.opaque_handles={};self.unavailable_bundles=[]
  self.process_keys={};self.locked_keys=set();self.unavailable_libraries=[]
  self.seed_random(1)
  self.rand_seed=1
  self.clock=1794675600 # Fixed current task date: 2026-11-14 17:00 UTC, test inputs only.
  self.monotonic_ticks=0
  self.sample_rate=44100;self.block_size=512;self.sample_position=0;self.time_info=0
  self.event_loop=0;self.timer_upps={};self.timers={}
  self.files={};self.opened_reference_files=[];self.file_requests=[];self.missing_directories=[];self.errno_pointer=0;self.private_preferences=None
  self.converters={};self.pending_converters=[];self.conversion_records=[]
  self.libm=ctypes.CDLL(ctypes.util.find_library('m'));self.math32={}
  for name in self.MATH32:
   fn=getattr(self.libm,name);fn.argtypes=[ctypes.c_float]*(2 if name in ['powf','atan2f','fmodf'] else 1);fn.restype=ctypes.c_float;self.math32[name]=fn
  if isinstance(backend,Original):
   def callback(uc,pc,size,user):self.callback(pc)
   backend.uc.hook_add(UC_HOOK_CODE,callback,begin=0x103000,end=0x1037e3);self.original_hook=callback
   backend.uc.mem_map(0x70000000,0x1000);backend.hook(0x70000000,self.callback);backend.hook(0x70000100,self.callback)
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
 def eax(self):
  if isinstance(self.b,Original):return self.b.uc.reg_read(UC_X86_REG_EAX)
  raw=ctypes.create_string_buffer(4);self.b.l.sl_reg_read(self.b.c,0,raw,4);return struct.unpack('<I',raw.raw)[0]
 def setpc(self,pc):
  if isinstance(self.b,Original):self.b.uc.reg_write(UC_X86_REG_EIP,pc)
  else:self.b.l.sl_set_pc(self.b.c,pc)
 def cf_string(self,token):
  obj=self.opaque_handles.get(token)
  if obj and obj['type']=='CFString':return obj['value']
  if not token:raise ValueError('NULL CFString')
  isa,flags,data,length=struct.unpack('<4I',self.b.read(token,16))
  if length>65536 or flags not in [0x7c8,0x7d0]:raise ValueError('Unknown CFString token '+hex(token))
  return self.b.read(data,length*(2 if flags==0x7d0 else 1)).decode('utf-16-le' if flags==0x7d0 else 'utf8')
 def new_cf_string(self,text):
  token=self.alloc(16);self.opaque_handles[token]={'type':'CFString','value':text,'refs':1};return token
 def encoding(self,value):
  if value==0x08000100:return 'utf8'
  if value==0:return 'mac_roman'
  if value==0x0600:return 'ascii'
  raise ValueError('Unsupported CFString encoding '+hex(value))
 def formatted(self,fmt,address):
  result=[];at=0
  def take(n):
   nonlocal address
   raw=self.b.read(address,n);address+=n;return raw
  pattern=re.compile(r'%([-+ #0]*)(\*|\d*)(?:\.(\*|\d*))?(hh|ll|h|l|z|t|j|L)?([diuoxXfFeEgGcsp%])')
  while at<len(fmt):
   if fmt[at]!='%':result.append(fmt[at]);at+=1;continue
   match=pattern.match(fmt,at)
   if not match:raise ValueError('Unsupported printf format '+repr(fmt[at:at+16]))
   flags,width,precision,length,kind=match.groups();at=match.end()
   if kind=='%':result.append('%');continue
   stars=[]
   for value in [width,precision]:
    if value=='*':stars.append(struct.unpack('<i',take(4))[0])
   spec='%'+flags+width+('' if precision is None else '.'+precision)+kind
   if kind=='s':value=self.string(struct.unpack('<I',take(4))[0]).decode('latin1')
   elif kind in 'fFeEgG':
    if length=='L':raise ValueError('long double printf is not implemented')
    value=struct.unpack('<d',take(8))[0]
   else:
    n=8 if length in ['ll','j'] else 4;value=int.from_bytes(take(n),'little',signed=kind in 'di')
    if kind=='p':spec='%#x'
    if kind=='c':value&=255
   result.append(spec%tuple(stars+[value]))
  raw=''.join(result).encode('latin1')
  if len(raw)>0x100000:raise ValueError('Oversized printf result')
  return raw
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
  elif name in ['_atol','_atoi']:
   text=self.string(arg(0)).decode('ascii');match=re.match(r'\s*([+-]?\d+)',text);value=int(match.group(1)) if match else 0
   if value>0x7fffffff or value<-(1<<31):
    if not self.errno_pointer:self.errno_pointer=self.alloc(4)
    self.put(self.errno_pointer,34);value=max(-(1<<31),min(0x7fffffff,value))
   result=value
  elif name=='_strlen':result=len(self.string(arg(0)))
  elif name=='_strcpy':result=arg(0);self.b.write(result,self.string(arg(1))+b'\0')
  elif name=='_strdup':
   raw=self.string(arg(0))+b'\0';result=self.alloc(len(raw));self.b.write(result,raw)
  elif name=='_strstr':
   where=self.string(arg(0)).find(self.string(arg(1)));result=arg(0)+where if where>=0 else 0
  elif name in ['_strchr','_strrchr']:
   raw=self.string(arg(0))+b'\0';needle=bytes([arg(1)&255])
   where=raw.find(needle) if name=='_strchr' else raw.rfind(needle);result=arg(0)+where if where>=0 else 0
  elif name=='_strncpy':
   result=arg(0);n=arg(2)
   if n>0x100000:raise ValueError('Unexpected strncpy size')
   raw=self.b.read(arg(1),n).split(b'\0',1)[0];self.b.write(result,raw+b'\0'*(n-len(raw)))
  elif name in ['_strcmp','_strncmp','_strcasecmp','_strncasecmp']:
   n=arg(2) if name in ['_strncmp','_strncasecmp'] else 65536
   if n>65536:raise ValueError('Unexpected string comparison size')
   a=self.string(arg(0))[:n];b=self.string(arg(1))[:n]
   if name in ['_strcasecmp','_strncasecmp']:a=a.lower();b=b.lower()
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
  elif name=='_opendir':
   # The test namespace contains asset aliases only, no mounted Mac directories.
   path=self.string(arg(0)).replace(b'\\',b'/').replace(b':',b'/')
   self.missing_directories.append(path.rstrip(b'/').rsplit(b'/',1)[-1].decode('utf8','replace'))
   if not self.errno_pointer:self.errno_pointer=self.alloc(4)
   self.put(self.errno_pointer,2);result=0 # Darwin ENOENT.
  elif name=='___error':
   if not self.errno_pointer:self.errno_pointer=self.alloc(4)
   result=self.errno_pointer
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
   elif opcode==16:result=self.sample_rate
   elif opcode==17:result=self.block_size
   elif opcode==7:
    if not self.time_info:self.time_info=self.alloc(88)
    beat=self.sample_position/self.sample_rate*2
    flags=0x2f02|(1 if self.sample_position==0 else 0)
    self.b.write(self.time_info,struct.pack('<8d6i',self.sample_position,self.sample_rate,self.sample_position/self.sample_rate*1e9,beat,120.0,math.floor(beat/4)*4,0.0,0.0,4,4,0,0,0,flags));result=self.time_info
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
  elif name=='_GetMainEventLoop':
   if not self.event_loop:self.event_loop=self.alloc(16)
   result=self.event_loop
  elif name=='_NewEventLoopTimerUPP':
   result=self.alloc(16);self.timer_upps[result]=arg(0)
  elif name=='_InstallEventLoopTimer':
   if arg(0)!=self.event_loop or arg(5) not in self.timer_upps:raise ValueError('Invalid event-loop timer arguments')
   delay,interval=struct.unpack('<dd',self.b.read(sp+8,16));timer=self.alloc(16)
   self.timers[timer]={'delay':delay,'interval':interval,'callback':self.timer_upps[arg(5)],'userdata':arg(6)}
   self.put(arg(7),timer)
  elif name=='_RemoveEventLoopTimer':
   if arg(0) not in self.timers:result=-50
   else:del self.timers[arg(0)]
  elif name=='_DisposeEventLoopTimerUPP':
   if arg(0) not in self.timer_upps:raise ValueError('Unknown timer UPP')
   del self.timer_upps[arg(0)]
  elif name=='_SetEventLoopTimerNextFireTime':
   if arg(0) not in self.timers:result=-50
   else:self.timers[arg(0)]['delay']=struct.unpack('<d',self.b.read(sp+8,8))[0]
  elif name=='_fopen':
   path=self.string(arg(0)).decode('utf8','replace');mode=self.string(arg(1)).decode('ascii')
   basename=path.replace('\\','/').replace(':','/').rsplit('/',1)[-1]
   self.file_requests.append({'basename':basename,'mode':mode})
   if mode not in ['r','rb']:raise RuntimeError('Only read-only reference files are available in this host')
   choices=list((ROOT/'reference/Samples').glob('*'))+list((ROOT/'reference/Presets').glob('*'))
   candidates=[p for p in choices if p.name.casefold()==basename.casefold()]
   if len(candidates)==1:
    data=candidates[0].read_bytes();result=self.alloc(256)
    self.files[result]={'data':data,'position':0,'eof':False,'error':False,'name':candidates[0].name}
    self.opened_reference_files.append({'file':candidates[0].name,'bytes':len(data),'sha256':hashlib.sha256(data).hexdigest()})
  elif name=='_fclose':
   if arg(0) not in self.files:result=-1
   else:del self.files[arg(0)];self.frees.add(arg(0))
  elif name=='_fread':
   dst,size,count,handle=[arg(i) for i in range(4)]
   if handle not in self.files:raise ValueError('Unknown FILE token')
   f=self.files[handle];n=size*count
   if n>0x2000000:raise ValueError('Oversized fread')
   raw=f['data'][f['position']:f['position']+n];self.b.write(dst,raw);f['position']+=len(raw);f['eof']=len(raw)<n
   result=len(raw)//size if size else 0
  elif name in ['_fseek','_rewind','_fsetpos']:
   handle=arg(0)
   if handle not in self.files:raise ValueError('Unknown FILE token')
   f=self.files[handle]
   if name=='_rewind':position=0
   elif name=='_fsetpos':position=struct.unpack('<q',self.b.read(arg(1),8))[0]
   else:
    offset=arg(1);offset=offset if offset<0x80000000 else offset-(1<<32)
    bases={0:0,1:f['position'],2:len(f['data'])}
    if arg(2) not in bases:raise ValueError('Unknown seek origin')
    position=bases[arg(2)]+offset
   if position<0:result=-1
   else:f['position']=position;f['eof']=False
  elif name in ['_ftell','_fgetpos','_feof','_ferror','_clearerr','_fflush','_fgetc','_getc','_fgets']:
   handle=arg(2) if name=='_fgets' else arg(0)
   if name=='_fflush' and not handle:result=0
   else:
    if handle not in self.files:raise ValueError('Unknown FILE token')
    f=self.files[handle]
    if name=='_ftell':result=f['position']
    elif name=='_fgetpos':self.b.write(arg(1),struct.pack('<q',f['position']))
    elif name=='_feof':result=int(f['eof'])
    elif name=='_ferror':result=int(f['error'])
    elif name=='_clearerr':f['eof']=False;f['error']=False
    elif name in ['_fgetc','_getc']:
     if f['position']>=len(f['data']):result=-1;f['eof']=True
     else:result=f['data'][f['position']];f['position']+=1
    elif name=='_fgets':
     n=arg(1)
     if not n or f['position']>=len(f['data']):result=0;f['eof']=True
     else:
      raw=f['data'][f['position']:f['position']+n-1].split(b'\n',1)[0]
      end=f['position']+len(raw)
      if len(raw)<n-1 and end<len(f['data']) and f['data'][end:end+1]==b'\n':raw+=b'\n'
      self.b.write(arg(0),raw+b'\0');f['position']+=len(raw);result=arg(0)
  elif name=='_AudioConverterNew':
   source=struct.unpack('<d8I',self.b.read(arg(0),40));destination=struct.unpack('<d8I',self.b.read(arg(1),40))
   # This fixture needs PCM16 packed stereo -> float32 noninterleaved stereo,
   # at equal rates (the original passes zero for both rate fields).
   if not (source[1]==destination[1]==0x6c70636d and source[0]==destination[0] and source[6]==destination[6]==2 and source[7]==16 and source[2]&4 and not source[2]&1 and source[3]==source[5]==4 and source[4]==1 and destination[2]==0x29 and destination[7]==32 and destination[3]==destination[5]==4 and destination[4]==1):
    raise RuntimeError('Unsupported converter formats in the limited PCM reference adapter: '+repr((source,destination)))
   token=self.alloc(32);self.converters[token]={'source':source,'destination':destination};self.put(arg(2),token)
  elif name=='_FSFindFolder':
   # Explicit limited test filesystem: no macOS support/preferences folders.
   if arg(3):self.b.write(arg(3),b'\0'*80)
   result=-43 # fnfErr; no host folders are created.
  elif name=='_CFStringCreateWithCString':result=self.new_cf_string(self.string(arg(1)).decode(self.encoding(arg(2))))
  elif name=='_CFStringCreateCopy':result=self.new_cf_string(self.cf_string(arg(1)))
  elif name=='_CFStringGetLength':result=len(self.cf_string(arg(0)).encode('utf-16-le'))//2
  elif name=='_CFStringGetCString':
   raw=self.cf_string(arg(0)).encode(self.encoding(arg(3)))+b'\0'
   if len(raw)<=arg(2):self.b.write(arg(1),raw);result=1
  elif name=='_CFStringGetCStringPtr':result=0 # A legal CF implementation may require copying.
  elif name=='_CFStringCompare':
   a=self.cf_string(arg(0));b=self.cf_string(arg(1))
   if arg(2)&1:a=a.casefold();b=b.casefold()
   result=(a>b)-(a<b)
  elif name=='_CFStringGetSystemEncoding':result=0
  elif name=='_CFArrayCreateMutable':
   result=self.alloc(16);self.opaque_handles[result]={'type':'CFArray','value':[],'refs':1}
  elif name=='_CFArrayAppendValue':
   obj=self.opaque_handles.get(arg(0))
   if not obj or obj['type']!='CFArray':raise ValueError('Unknown CFArray token')
   token=arg(1);obj['value'].append(token)
   if token in self.opaque_handles:self.opaque_handles[token]['refs']+=1
  elif name in ['_CFArrayGetValueAtIndex','_CFArrayGetCount','_CFArrayCreateCopy']:
   obj=self.opaque_handles.get(arg(1) if name=='_CFArrayCreateCopy' else arg(0))
   if not obj or obj['type']!='CFArray':raise ValueError('Unknown CFArray token')
   if name=='_CFArrayGetValueAtIndex':result=obj['value'][arg(1)]
   elif name=='_CFArrayGetCount':result=len(obj['value'])
   else:
    result=self.alloc(16);self.opaque_handles[result]={'type':'CFArray','value':list(obj['value']),'refs':1}
    for token in obj['value']:
     if token in self.opaque_handles:self.opaque_handles[token]['refs']+=1
  elif name=='_CFStringGetTypeID':result=7
  elif name=='_CFGetTypeID':
   self.cf_string(arg(0));result=7
  elif name=='_CFRetain':
   result=arg(0)
   if result in self.opaque_handles:self.opaque_handles[result]['refs']=self.opaque_handles[result].get('refs',1)+1
  elif name=='_CFRelease':
   token=arg(0)
   if token in self.opaque_handles:
    obj=self.opaque_handles[token];obj['refs']=obj.get('refs',1)-1
    if obj['refs']==0:del self.opaque_handles[token]
   else:self.cf_string(token) # Constant CFStrings are immortal.
  elif name in ['_CFPreferencesCopyAppValue','_CFPreferencesCopyValue']:
   # Private preferences, when explicitly supplied, remain in process memory.
   if self.private_preferences is not None and self.cf_string(arg(1))=='com.linplug.Sophistry':
    value=self.private_preferences.get(self.cf_string(arg(0)))
    if value is not None:
     if not isinstance(value,str):raise ValueError('Unsupported non-string legacy preference')
     result=self.new_cf_string(value)
  elif name in ['_CFPreferencesGetAppBooleanValue','_CFPreferencesGetAppIntegerValue']:
   if arg(2):self.b.write(arg(2),b'\0')
   result=0
  elif name=='_CFPreferencesAppSynchronize':result=1
  elif name in ['_sprintf','_snprintf','_vsprintf','_vsnprintf']:
   bounded=name in ['_snprintf','_vsnprintf'];variable=name in ['_vsprintf','_vsnprintf']
   fmt_index=2 if bounded else 1;fmt=self.string(arg(fmt_index)).decode('latin1')
   arguments=arg(fmt_index+1) if variable else sp+4*(fmt_index+2)
   raw=self.formatted(fmt,arguments);result=len(raw)
   if bounded:
    n=arg(1)
    if n:self.b.write(arg(0),raw[:n-1]+b'\0')
   else:self.b.write(arg(0),raw+b'\0')
  elif name=='_AudioConverterDispose':
   if arg(0) not in self.converters:raise ValueError('Unknown converter')
   del self.converters[arg(0)]
  elif name=='_AudioConverterFillComplexBuffer':
   if self.pending_converters:raise RuntimeError('Nested converter operation')
   if arg(0) not in self.converters:raise ValueError('Unknown converter')
   count=self.word(arg(3));request=self.alloc(64)
   self.put(request,count);self.put(request+4,1);self.put(request+20,0)
   context={'parent_sp':sp,'converter':arg(0),'callback':arg(1),'userdata':arg(2),'out_count':arg(3),'output':arg(4),'request':request,'frames':count}
   self.pending_converters.append(context)
   child_sp=sp-0x1000
   self.b.write(child_sp,struct.pack('<6I',0x70000100,arg(0),request,request+4,request+20,arg(2)))
   self.b.setesp(child_sp);self.setpc(arg(1));return # Guest callback executes as normal lifted/original code.
  elif name=='<converter-input-return>':
   if not self.pending_converters:raise RuntimeError('Unexpected converter continuation')
   context=self.pending_converters.pop();status=self.eax()
   if not status:
    request=context['request'];input_list=request+4
    count=min(context['frames'],self.word(request))
    raw_size=self.word(input_list+8);raw_pointer=self.word(input_list+12)
    count=min(count,raw_size//4);raw=self.b.read(raw_pointer,count*4)
    samples=array.array('h');samples.frombytes(raw)
    source=self.converters[context['converter']]['source']
    if (bool(source[2]&2))!=(sys.byteorder=='big'):samples.byteswap()
    output=context['output']
    if self.word(output)!=2:raise ValueError('Unexpected converter output buffer count')
    outputs=[]
    for channel in range(2):
     if self.word(output+4+12*channel)!=1 or self.word(output+8+12*channel)<count*4:raise ValueError('Invalid converter output buffer')
     data=array.array('f',(v/32768.0 for v in samples[channel::2])).tobytes()
     self.b.write(self.word(output+12+12*channel),data);self.put(output+8+12*channel,len(data));outputs.append(hashlib.sha256(data).hexdigest())
    self.put(context['out_count'],count)
    self.conversion_records.append({'callback':hex(context['callback']),'frames':count,'source_bytes_sha256':hashlib.sha256(raw).hexdigest(),'output_float32_channel_sha256':outputs,'adapter':'Exact PCM16 / 32768; no resampling; original guest input callback executed'})
   self.b.setesp(context['parent_sp']);result=status
  if integer64 is not None:
   high=integer64>>32
   if isinstance(self.b,Original):self.b.uc.reg_write(UC_X86_REG_EDX,high)
   else:self.b.regwrite(8,struct.pack('<I',high))
  if floating is not None:self.b.fpreturn(floating)
  if isinstance(self.b,Original):self.b.uc.reg_write(UC_X86_REG_EAX,result&0xffffffff)
  else:self.b.regwrite(0,struct.pack('<I',result&0xffffffff))
  self.b.ret()
def probe(library,output,construct=False,open_effect=False,preset=None,missing_listing=None,inspect_state=False,render_seconds=0,au_callback=False,private_registration=None,private_preferences=None):
 image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes())
 backend=HostedNative(ctypes.CDLL(str(library.resolve())),bytes(image.mapped()),0x4000000) if library else Original(bytes(image.mapped()),0x4000000)
 host=Host(backend,image);host.private_preferences=private_preferences;private_mode=private_registration is not None or private_preferences is not None
 completed=[];error=None;stage='global initialization';constructed=False;opened=False
 missing=set();trace_hook=None
 if missing_listing:
  if library:raise ValueError('Missing-code tracing requires the original i386 backend')
  known=set()
  with missing_listing.open() as f:
   for line in f:known.add(int(json.loads(line)['address'],16))
  def trace(uc,pc,size,user):
   if pc<0x103000 and pc not in known:missing.add(pc)
  trace_hook=backend.uc.hook_add(UC_HOOK_CODE,trace)
 preset_returned=False;preset_result=None;preset_info=None
 state_info=None;status_observations=[]
 render_info=None
 def observe(label):
  # Inspect state without changing initialization, MIDI, or registration checks.
  status_observations.append({'stage':label,'bytes_at_object_cfc4':backend.read(0x200000+0xcfc4,24).hex()})
 def return_word():
  if isinstance(backend,Native):
   value=ctypes.create_string_buffer(4);backend.l.sl_reg_read(backend.c,0,value,4);return struct.unpack('<I',value.raw)[0]
  return backend.uc.reg_read(UC_X86_REG_EAX)
 try:
  if private_mode and inspect_state:raise ValueError('Private input mode disables state dumps')
  for at in image.initializers:backend.run(at,[]);completed.append(hex(at))
  if construct:
   stage='Kaja constructor';backend.run(0x4e876,[0x200000,0x273c if au_callback else 0x70000000]);constructed=True;observe('constructor')
  if open_effect:
   if not constructed:raise ValueError('--open requires --construct')
   stage='VST effOpen';backend.run(host.word(0x200024),[0x200020,0,0,0,0,0]);opened=True;observe('effOpen')
  if private_registration is not None:
   if not opened:raise ValueError('Private registration input requires --construct --open')
   raw=private_registration.encode('utf8')
   if not raw or len(raw)>319:raise ValueError('Invalid registration input length')
   if backend.read(0x200000+0xb4+0x315,1)!=b'\0':raise ValueError('Registration setter would persist preferences')
   stage='private registration input through original SysGlo setter'
   backend.write(0x5e0000,raw+b'\0');backend.run(0x12c66,[0x200000+0xb4,0,1,0x5e0000]);backend.write(0x5e0000,b'\0'*(len(raw)+1))
  if preset:
   if not opened:raise ValueError('--preset requires --construct --open')
   raw=preset.read_bytes();index=1
   if preset.suffix.lower()=='.aupreset':
    import plistlib
    chunk=plistlib.loads(raw)['vstdata'];index=0
   else:
    if raw[:4]!=b'CcnK' or raw[8:12]!=b'FPCh':raise ValueError('Expected an FXP program chunk')
    length=struct.unpack_from('>I',raw,56)[0]
    if len(raw)!=60+length:raise ValueError('Unexpected FXP size')
    chunk=raw[60:]
   preset_info={'file':preset.name,'file_sha256':hashlib.sha256(raw).hexdigest(),'chunk_bytes':len(chunk),'program_index_flag':index}
   stage='VST setChunk';backend.write(0x600000,chunk)
   backend.run(host.word(0x200024),[0x200020,24,index,len(chunk),0x600000,0]);preset_returned=True
   preset_result=return_word();observe('setChunk')
  if inspect_state:
   if not opened:raise ValueError('--inspect requires --construct --open')
   dispatcher=host.word(0x200024);stage='VST getProgramName'
   backend.write(0x5f0100,b'\0'*256);backend.run(dispatcher,[0x200020,5,0,0,0x5f0100,0])
   program=backend.read(0x5f0100,256).split(b'\0',1)[0].decode('utf8','replace')
   stage='VST getChunk';host.put(0x5f0000,0);backend.run(dispatcher,[0x200020,23,1,0,0x5f0000,0])
   length=return_word();pointer=host.word(0x5f0000)
   if length>0x2000000 or (length and not pointer):raise ValueError('Invalid serialized program chunk')
   data=backend.read(pointer,length) if length else b''
   output.with_suffix('.chunk').write_bytes(data)
   state_info={'program_name':program,'serialized_program_bytes':length,'serialized_program_sha256':hashlib.sha256(data).hexdigest()}
  if render_seconds:
   if not preset_returned:raise ValueError('--render requires a loaded preset')
   if render_seconds<=0 or render_seconds>30:raise ValueError('Render duration must be between 0 and 30 s')
   dispatcher=host.word(0x200024);rate=host.sample_rate;block=host.block_size
   stage='VST sample rate/block/mains'
   rate_bits=struct.unpack('<I',struct.pack('<f',rate))[0]
   backend.run(dispatcher,[0x200020,10,0,0,0,rate_bits])
   backend.run(dispatcher,[0x200020,11,0,block,0,0])
   backend.run(dispatcher,[0x200020,12,0,1,0,0])
   observe('mains on')
   # Restore after the first activation, which can initialize the default bank.
   backend.write(0x600000,chunk);backend.run(dispatcher,[0x200020,24,index,len(chunk),0x600000,0]);observe('setChunk after activation')
   channels=host.word(0x200040);input_channels=host.word(0x20003c)
   if channels<1 or channels>16 or input_channels>16:raise ValueError('Unexpected render channel count')
   inputs=host.alloc(max(1,input_channels)*4);outputs=host.alloc(channels*4)
   output_buffers=[host.alloc(block*4) for _ in range(channels)]
   for c,p in enumerate(output_buffers):host.put(outputs+4*c,p)
   for c in range(input_channels):
    p=host.alloc(block*4);backend.write(p,b'\0'*(block*4));host.put(inputs+4*c,p)
   event=host.alloc(32);events=host.alloc(16);host.put(events,1);host.put(events+4,0);host.put(events+8,event);host.put(events+12,0)
   def midi(status,delta=0):
    backend.write(event,struct.pack('<6I4s4B',1,32,delta,0,0,0,bytes([status,60,100 if status==0x90 else 0,0]),0,0,0,0))
    backend.run(dispatcher,[0x200020,25,0,0,events,0])
   stage='VST MIDI note-on';midi(0x90);observe('MIDI note-on')
   processor=host.word(0x200070);total=int(rate*render_seconds);off=min(total,int(2*rate));audio=[bytearray() for _ in range(channels)]
   peaks=[0.0]*channels;sums=[0.0]*channels
   for frame in range(0,total,block):
    n=min(block,total-frame);host.sample_position=frame;stage='VST render frame '+str(frame)
    if frame<=off<frame+n:midi(0x80,off-frame)
    for p in output_buffers:backend.write(p,b'\0'*(block*4))
    backend.run(processor,[0x200020,inputs,outputs,n])
    if frame==0:observe('first audio block')
    for c,p in enumerate(output_buffers):
     raw=backend.read(p,n*4);audio[c].extend(raw)
     for (value,) in struct.iter_unpack('<f',raw):
      if not math.isfinite(value):raise ValueError('Non-finite rendered audio')
      peaks[c]=max(peaks[c],abs(value));sums[c]+=value*value
    if frame//block%128==0:print('Rendered frames:',frame+n,'/',total,flush=True)
   interleaved=bytearray(total*channels*4)
   for frame in range(total):
    for c in range(channels):interleaved[(frame*channels+c)*4:(frame*channels+c+1)*4]=audio[c][frame*4:frame*4+4]
   fmt=struct.pack('<HHIIHH',3,channels,rate,rate*channels*4,channels*4,32)
   wave=b'RIFF'+struct.pack('<I',36+len(interleaved))+b'WAVEfmt '+struct.pack('<I',16)+fmt+b'data'+struct.pack('<I',len(interleaved))+interleaved
   wav_path=output.with_suffix('.wav');wav_path.write_bytes(wave)
   render_info={'sample_rate':rate,'block_frames':block,'frames':total,'channels':channels,'peak_per_channel':peaks,'rms_per_channel':[math.sqrt(s/total) for s in sums],'pcm_float32_sha256':hashlib.sha256(interleaved).hexdigest(),'signal_above_minus_100_dbfs':any(x>1e-5 for x in peaks),'signal_check':'Peak must exceed 1e-5 (-100 dBFS); denormal-prevention offsets do not establish synthesis','note':60,'velocity':100,'note_off_frame':off,'host_callback':'original AU zero-return stub at 0x273c' if au_callback else 'synthetic VST host'}
   stage='render completed'
   if not render_info['signal_above_minus_100_dbfs']:raise RuntimeError('Rendered output stays below -100 dBFS; synthesis is not verified')
 except Exception as e:error=str(e).replace(private_registration,'<redacted>') if private_registration else str(e)
 pc=backend.l.sl_get_pc(backend.c) if isinstance(backend,Native) else backend.uc.reg_read(UC_X86_REG_EIP)
 r={'scope':'Global initialization progress with a limited explicit host; not a complete synth or native Audio Unit',
  'backend':'statically emitted C++' if library else 'original i386 / Unicorn','completed_initializers':len(completed),'total_initializers':len(image.initializers),
  'completed_entries':completed,'error':error,'stage':stage,'Kaja_constructor_returned':constructed,'effOpen_returned':opened,'preset_input':preset_info,'setChunk_returned':preset_returned,'setChunk_result':preset_result,'state_inspection':state_info,'status_observations':status_observations,'render':render_info,'stopped_pc':hex(pc),'last_import':host.last_import,
  'unhandled_import':host.names.get(pc),'host_import_calls':dict(host.calls),'heap_bytes_reserved':host.heap-0x800000,
  'allocator':'bounded deterministic guest bump allocator; freed tokens tracked, no reuse; test-only','test_time_epoch':host.clock,
  'engine_object_sha256':None if private_mode else hashlib.sha256(backend.read(0x200000,0x340000)).hexdigest(),
  'guest_heap_sha256':None if private_mode else hashlib.sha256(backend.read(0x800000,host.heap-0x800000)).hexdigest(),
  'private_registration_input':private_registration is not None,
  'private_local_preferences':private_preferences is not None,
  'effect_fields':{'magic':hex(host.word(0x200020)),'dispatcher':hex(host.word(0x200024)),'num_programs':host.word(0x200034),'num_parameters':host.word(0x200038),'num_inputs':host.word(0x20003c),'num_outputs':host.word(0x200040),'process_replacing':hex(host.word(0x200070)),'unique_id':hex(host.word(0x200068))} if constructed else None,
  'registered_destructors':len(host.destructors),'guest_mutexes':host.mutexes,'mutex_adapter':'single-CPU state machine; no concurrent guest access; blocking operations stop the probe','math_adapter':'Python/platform math; not original Apple i386 libm','random_adapter':'Frozen BSD degree-31 stream, initial seed 1; shared test inputs, not an original-OS random capture','graphics_adapter':'Explicit unavailable-ColorSync-profile and CoreGraphics-bundle scenario; DeviceRGB is an opaque test handle, no rendering','unavailable_framework_bundles':host.unavailable_bundles,'unavailable_dynamic_libraries':host.unavailable_libraries,'original_global_destructor_registration_complete':False,'global_memory_sha256':None if private_mode else hashlib.sha256(backend.read(0xe2000,0x104000-0xe2000)).hexdigest(),
  'event_loop_adapter':'Registered timers only; no GUI events or timer callbacks pumped during initialization','registered_timers':host.timers,
  'filesystem_adapter':'Only provided reference assets, resolved by unique case-insensitive basename; read-only in-memory FILE objects; no mounted Mac directory namespace','file_requests':host.file_requests,'opened_reference_files':host.opened_reference_files,'unavailable_directory_basenames':host.missing_directories,
  'audio_conversion_adapter':'Restricted exact PCM16 stereo to float32 stereo, same rate; not original Apple AudioConverter execution','audio_conversions':host.conversion_records,
  'executed_code_missing_from_listing':[hex(pc) for pc in sorted(missing)],
  'full_engine_initialized':False,'preset_restored':False,'audio_rendered':False}
 output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(r,indent=2)+'\n')
 backend.close();return r
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--library',type=Path);p.add_argument('--output',type=Path,required=True);p.add_argument('--construct',action='store_true');p.add_argument('--open',action='store_true');p.add_argument('--preset',type=Path);p.add_argument('--missing-listing',type=Path);p.add_argument('--inspect',action='store_true');p.add_argument('--render',type=float,default=0);p.add_argument('--au-callback',action='store_true');p.add_argument('--registration-from-stdin',action='store_true');p.add_argument('--local-mac-preferences',action='store_true');n=p.parse_args()
 private_preferences=None
 if n.local_mac_preferences:
  if n.registration_from_stdin:p.error('Choose local preferences or registration input')
  if sys.platform!='darwin':p.error('Local preferences require macOS')
  import subprocess,plistlib
  prefs=subprocess.run(['/usr/bin/defaults','export','com.linplug.Sophistry','-'],stdout=subprocess.PIPE,stderr=subprocess.PIPE,check=False)
  private_preferences=plistlib.loads(prefs.stdout) if prefs.returncode==0 else {}
 serial_input=sys.stdin.readline().rstrip('\r\n') if n.registration_from_stdin else None
 r=probe(n.library,n.output,n.construct,n.open,n.preset,n.missing_listing,n.inspect,n.render,n.au_callback,serial_input,private_preferences);print(json.dumps({k:r[k] for k in ['backend','completed_initializers','total_initializers','stage','Kaja_constructor_returned','effOpen_returned','setChunk_returned','setChunk_result','state_inspection','render','error','stopped_pc','last_import','unhandled_import','heap_bytes_reserved','effect_fields','executed_code_missing_from_listing']},indent=2))
 sys.exit(1 if r['error'] else 0)
