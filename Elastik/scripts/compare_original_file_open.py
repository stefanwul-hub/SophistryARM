#!/usr/bin/env python3
"""Original i386 reader selection, file open and metadata versus native C++.

The GN exception frames/setjmp, factories, object primitives and filename
partner finder are explicit bindings. No sample reader body is substituted
silently: this corpus tests control/ownership; the pipeline corpus tests audio.
"""
import argparse
import hashlib
import itertools
import json
import math
from pathlib import Path
import random
import struct
from original_cache_oracle import OriginalCacheOracle, STACK, RETURN
from legacy_image import SHA
from native_probe import NativeProbe
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import (UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,
    UC_X86_REG_EBP,UC_X86_REG_EBX,UC_X86_REG_ESI,UC_X86_REG_EDI,UC_X86_REG_EFLAGS,UC_X86_REG_MXCSR)

FILE,READERS,VT,PATHS,PATHVT=0x540000,0x550000,0x553000,0x554000,0x555000
EXCEPTION,EXCVT,CLASS,CLASSVT,KEYS,WAVE=0x556000,0x556100,0x556400,0x556500,0x557000,0x558000
NODES=0x560000
def pack(v):return struct.pack('<'+'i'*len(v),*((x+(1<<31))%(1<<32)-(1<<31) for x in v))
def base(name,entry=1):
    h=[0]*48;h[0]=entry;h[3:13]=[77,2,313,0x14,7,13,9,9,14,15]
    h[13:24]=[1,1,0,1,0x10,257,2,1,0x10,257,2]
    h[24:32]=[2,0,2,2]*2;h[34:41]=[1,3,2,44,2,257,1]
    return dict(name=name,h=h,rates=[123.5,44100.0,44100.0])
def fixtures():
    for statuses in itertools.product([0,1,2,4],repeat=4):
        c=base('factory-'+''.join(map(str,statuses)),0);c['h'][24:28]=statuses;yield c
    for mask in range(16):
        c=base(f'factory-null-autorelease-{mask}',0);c['h'][24:28]=[2,2,2,0];c['h'][32]=mask;yield c
    for bad in [0,1,2]:
        c=base(f'open-assertion-{bad}');c['h'][1]=bad==1;c['h'][2]=9 if bad==2 else 0;yield c
    for channels in [0,1,2,0x101,0x104]:
        for present,exists,side in itertools.product([0,1],[0,1],[0,1,2,-1]):
            c=base(f'open-ch{channels:x}-partner{present}-exists{exists}-side{side}');c['h'][13:17]=[present,exists,side,channels];yield c
    for field,values in [(8,[0,11,13]),(11,[0,11,12,14]),(12,[0,11,12,15])]:
        for side,v in itertools.product([0,1],values):
            c=base(f'path-replace-field{field}-side{side}-old{v}');c['h'][field]=v;c['h'][15]=side;yield c
    rates=[0.0,-0.0,44100.0,48000.0,math.inf,-math.inf,math.nan,44100.000000001]
    for a,b in itertools.product(rates,rates):
        c=base(f'exact-rate-{a}-{b}');c['rates'][1:]=[a,b];yield c
    for field in [21,22,20]:
        for value in [0,1,2,17,256,257,258,0x104]:
            c=base(f'pair-field{field}-value{value}');c['h'][field]=value;yield c
    for primary in [False,True]:
        for statuses in itertools.product([0,1,2,4],repeat=3):
            c=base(f'open-{"primary" if primary else "partner"}-statuses{statuses}');at=24 if primary else 28;c['h'][at:at+4]=list(statuses)+[0];yield c
    for entry in [2,3]:
        for source,mask,destination in itertools.product([0,1],range(8),[0,1]):
            if entry==3 and not destination:continue
            c=base(f'metadata-entry{entry}-source{source}-mask{mask}-dest{destination}',entry);c['h'][34]=source;c['h'][35]=mask;c['h'][40]=destination;yield c
    for width,channels,offset,frames in itertools.product([0,1,2,3,4,8],[-2,-1,1,2,4],[0,1,43,44,81,-44,0x7fffffff],[-1,0,257,0x7fffffff]):
        c=base(f'wave-meta-width{width}-ch{channels}-offset{offset}-frames{frames}',3);c['h'][36:40]=[width,offset,channels,frames];yield c

class FileOpenOracle(OriginalCacheOracle):
    def __init__(self,binary):
        super().__init__(binary)
        bindings={0x2dfa6:self.initialize,0x500f00:self.autorelease,0x500f10:self.open_reader,
            0x500f20:lambda *x:self.object_op(1),0x500f30:lambda *x:self.object_op(2),
            0x500f40:lambda *x:self.getter(1),0x500f50:self.rate,0x500f60:lambda *x:self.getter(3),
            0x500f70:lambda *x:self.getter(4),0x500f80:lambda *x:self.getter(5),0x500f90:self.metadata,
            0x1ac468:self.partner,0x500fa0:self.exists,0xbea2:self.push_frame,0xbec0:self.pop_frame,
            0x500fb0:lambda *x:self.finish(CLASS),0x500fc0:lambda *x:self.finish(int(self.exctype==2)),
            0x500fd0:self.rethrow,0xbf34:self.raise_error,0xbfd6:self.raise_error,0xa930:lambda *x:self.finish(0),
            0x33b90:self.string,0x29ddc:lambda *x:self.finish(2),0x2a364:self.key_at,
            0x500fe0:self.source,0x64024:self.contains,0x64626:self.get,0x66284:self.set,0x858da:self.integer}
        for addr,fn in bindings.items():self.uc.hook_add(UC_HOOK_CODE,fn,begin=addr,end=addr)
        for fmt,addr in enumerate([0x2447c2,0x24940e,0x243c6a,0x247652]):
            self.uc.hook_add(UC_HOOK_CODE,lambda *x,fmt=fmt:self.construct(fmt),begin=addr,end=addr)
        self.import_handlers.update(__Znwm=self.new,_setjmp=self.setjmp)
        for off,addr in [(0x40,0x500f20),(0x44,0x500f30),(0x48,0x500f00),(0x1a4,0x500f10),
                         (0x1ac,0x500f70),(0x1b0,0x500f60),(0x1b4,0x500f40),(0x1b8,0x500f50),
                         (0x1bc,0x500f80),(0x1c0,0x500fe0),(0x1c4,0x500f90)]:self.put(VT+off,addr)
        self.put(PATHVT+0x40,0x500f20,0x500f30);self.put(PATHVT+0x1d0,0x500fa0)
        self.put(EXCEPTION,EXCVT);self.put(EXCVT+0x1a8,0x500fd0,0x500fb0);self.put(CLASS,CLASSVT);self.put(CLASSVT+0x88,0x500fc0)
        # Return original-style x87 double, while the code hook only observes.
        self.uc.mem_write(0x500f50,bytes.fromhex('8b442404dd8000010000c3'))
    def record(self,*v):self.trace.append(list(v)+[0]*(6-len(v)))
    def ptr(self,n):
        if not n:return 0
        if 1<=n<=9:return READERS+(n-1)*0x200
        if 11<=n<=15:return PATHS+(n-11)*0x100
        return NODES+n*0x100
    def token(self,p):
        if not p:return 0
        if READERS<=p<READERS+9*0x200:return (p-READERS)//0x200+1
        if PATHS<=p<PATHS+5*0x100:return (p-PATHS)//0x100+11
        if NODES<=p<NODES+0x4000:return (p-NODES)//0x100
        raise ValueError(f'Unknown object {p:x}')
    def new(self):
        size,=self.arguments(1);self.newsize=size;self.current_format=[56,2112,52,48].index(size)
        self.finish(self.ptr(self.phase*4+self.current_format+1))
    def construct(self,fmt):
        p,=self.arguments(1);n=self.phase*4+fmt+1;p2=self.ptr(n)
        assert p==p2
        self.record(1,fmt,n,self.newsize);self.put(p2,VT);self.finish(p2)
        # Original constructor returns EAX=this. Subsequent init receives EAX;
        # allocating distinct fixed identities here adapts only GN allocation.
    def initialize(self,*unused):
        p,=self.arguments(1)
        n=self.phase*4+self.current_format+1;assert p==self.ptr(n)
        self.record(2,n);self.finish(p)
    def autorelease(self,*unused):
        p,=self.arguments(1);n=self.token(p);v=0 if self.h[32+self.phase]&(1<<((n-1)%4)) else n;self.record(3,n,v);self.finish(self.ptr(v))
    def open_reader(self,*unused):
        p,path=self.arguments(2);n=self.token(p);status=self.h[24+(n-1)//4*4+(n-1)%4];self.record(4,n,self.token(path),status)
        if not status:self.finish();return
        frame=self.frames.pop();sp,ret,registers=self.jumps[frame];self.put(frame+0x4c,EXCEPTION);self.exctype=status
        for r,v in registers.items():self.uc.reg_write(r,v)
        self.uc.reg_write(UC_X86_REG_ESP,sp+4);self.uc.reg_write(UC_X86_REG_EIP,ret);self.uc.reg_write(UC_X86_REG_EAX,1)
    def push_frame(self,*unused):p,=self.arguments(1);self.frames.append(p);self.finish()
    def pop_frame(self,*unused):p,=self.arguments(1);assert self.frames.pop()==p;self.finish()
    def setjmp(self):
        frame,=self.arguments(1);sp=self.uc.reg_read(UC_X86_REG_ESP);registers=[UC_X86_REG_EBP,UC_X86_REG_EBX,UC_X86_REG_ESI,UC_X86_REG_EDI]
        self.jumps[frame]=(sp,self.word(sp)&0xffffffff,{r:self.uc.reg_read(r) for r in registers});self.finish()
    def rethrow(self,*unused):self.error=self.exctype;self.uc.emu_stop()
    def raise_error(self,*unused):
        p,=self.arguments(1);name=self.strings.get(p,b'');self.error=3 if name==b'GNAssertionException' else 2;self.uc.emu_stop()
    def object_op(self,op):p,=self.arguments(1);self.record(5,op,self.token(p));self.finish(p)
    def getter(self,prop):
        p,=self.arguments(1);n=self.token(p);field={1:16,3:17,4:19,5:18}[prop]+(4 if n>4 else 0);value=self.h[field];self.record(6,prop,n,value);self.finish(value)
    def rate(self,*unused):
        p,=self.arguments(1);n=self.token(p);value=self.rates[1 if n<=4 else 2];bits=struct.unpack('<ii',struct.pack('<d',value));self.record(6,2,n,*bits)
    def metadata(self,*unused):p,d=self.arguments(2);self.record(7,self.token(p),self.token(d));self.finish()
    def partner(self,*unused):p,side,flags=self.arguments(3);assert flags==0;self.put(side,self.h[15]);self.phase=1;n=12 if self.h[13] else 0;self.record(8,self.token(p),self.h[15],n);self.finish(self.ptr(n))
    def exists(self,*unused):p,=self.arguments(1);self.record(9,self.token(p),self.h[14]);self.finish(self.h[14])
    def cstring(self,p):return bytes(self.uc.mem_read(p,256)).split(b'\0',1)[0]
    def string(self,*unused):
        p,=self.arguments(1);s=self.cstring(p);k={b'chunks':1,b'privateChunks':2,b'Melodyne1WaveSampleCount':3}.get(s,4)
        result=KEYS+k*0x100;self.strings[result]=s;self.finish(result)
    def key_at(self,*unused):p,index=self.arguments(2);assert p==KEYS;self.finish(KEYS+(index+1)*0x100)
    def key(self,p):return {b'chunks':1,b'privateChunks':2,b'Melodyne1WaveSampleCount':3}[self.strings[p]]
    def source(self,*unused):n=21 if self.h[34] else 0;self.record(10,n);self.finish(self.ptr(n))
    def contains(self,*unused):d,key=self.arguments(2);k=self.key(key);yes=(self.h[35]>>(k-1))&1;self.record(11,self.token(d),k,yes);self.finish(yes)
    def get(self,*unused):d,key=self.arguments(2);k=self.key(key);n=21+k;self.record(12,self.token(d),k,n);self.finish(self.ptr(n))
    def set(self,*unused):d,v,key=self.arguments(3);k=self.key(key);n=self.token(v);assert d;self.record(13,self.token(d),k,n);self.destination[3 if k==3 else k-1]=self.integer_value if k==3 else n;self.finish()
    def integer(self,*unused):value,=self.arguments(1);value=struct.unpack('<i',struct.pack('<I',value))[0];self.integer_value=value;self.record(14,value,25);self.finish(self.ptr(25))
    def execute(self,c):
        self.h=h=c['h'];self.rates=c['rates'];self.phase=0;self.trace=[];self.frames=[];self.jumps={};self.error=0;self.exctype=0;self.strings={KEYS+0x100:b'chunks',KEYS+0x200:b'privateChunks'};self.destination=[26,27,24,-999]
        self.uc.mem_write(FILE,bytes(0x100));self.uc.mem_write(WAVE,bytes(0x100));self.put(WAVE,VT)
        for n in range(1,10):self.put(self.ptr(n),VT);self.uc.mem_write(self.ptr(n)+0x100,struct.pack('<d',self.rates[1 if n<=4 else 2]))
        for n in range(11,16):self.put(self.ptr(n),PATHVT)
        for off,value in [(0x54,h[2]),(0x5c,h[9]),(0x60,h[10]),(0x50,h[8]),(0x6c,h[11]),(0x70,h[12])]:self.put(FILE+off,self.ptr(value))
        self.put(FILE+0x14,h[3]);self.put(FILE+0x4c,h[4]);self.put(FILE+0x24,h[5]);self.put(FILE+0x20,h[6]);self.put(FILE+0x10,h[7]);self.put(FILE+0x48,self.ptr(20) if h[40] else 0);self.uc.mem_write(FILE+0x18,struct.pack('<d',self.rates[0]))
        self.put(0x3d9084,KEYS);result=0
        if h[0]==0:result=self.call(0x219202,self.ptr(11))
        elif h[0]==1:self.call(0x1adbb6,0 if h[1] else FILE,self.ptr(11))
        else:
            self.put(VT+0x1bc,0x249a3c);self.uc.mem_write(WAVE+0x1a,struct.pack('<h',h[38]));self.put(WAVE+0x20,h[36]);self.put(WAVE+0x28,h[39]);self.put(WAVE+0x30,h[37]);self.call(0x219a4c if h[0]==2 else 0x249f1e,WAVE,self.ptr(20) if h[40] else 0);self.put(VT+0x1bc,0x500f80)
        header=[self.error,self.token(result) if h[0]==0 and not self.error else 0]+[self.token(self.word(FILE+off)) for off in [0x54,0x5c,0x60,0x50,0x6c,0x70]]+[self.word(FILE+off) for off in [0x14,0x20,0x10,0x4c,0x24]]+self.destination+[int(bool(self.word(FILE+0x54))),0,0]
        assert not self.frames
        return pack(header)+bytes(self.uc.mem_read(FILE+0x18,8))+pack([len(self.trace)])+b''.join(pack(row) for row in self.trace)
    def call_packed(self,address,packed):
        self.uc.mem_write(STACK,struct.pack('<I',RETURN)+packed);self.uc.reg_write(UC_X86_REG_ESP,STACK);self.uc.reg_write(UC_X86_REG_EFLAGS,2);self.uc.reg_write(UC_X86_REG_MXCSR,0x1f80);self.uc.emu_start(address,RETURN,count=500000)
        if not self.error and self.uc.reg_read(UC_X86_REG_EIP)!=RETURN:raise ValueError('Original call did not finish')
        return self.uc.reg_read(UC_X86_REG_EAX)

def compare(binary,runner,prefix,platform):
    oracle=FileOpenOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=0
    for case in fixtures():
        try:expected=oracle.execute(case)
        except Exception as e:raise RuntimeError(f'Original failed {case["name"]}: {e}') from e
        data=pack(case['h'])+struct.pack('<3d',*case['rates']);actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA010-native');folder.mkdir(exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]: (folder/f'failing-open-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)))
            raise ValueError(f'File open mismatch {case["name"]} exit={actual.returncode} byte={at} expected={expected[at:at+24].hex()} native={actual.stdout[at:at+24].hex()}')
        total+=len(expected);cases.append(dict(name=case['name'],mode=case['h'][0],status=struct.unpack_from('<i',expected)[0],trace_events=len(oracle.trace),sha256=hashlib.sha256(expected).hexdigest(),all_bytes_match=True))
    probe.close();return dict(checkpoint='ELA010',scope='Original reader factory, file opening/pairing and metadata projection',original_i386_sha256=SHA,compiled_platform=platform,fixture_count=len(cases),compared_bytes=total,all_cases_match_bit_for_bit=True,automatic_fixture_retries=0,boundaries_adapted=['GN allocation/constructor/init/autorelease','GN exception context/setjmp and exception class test','reader virtual metadata getters/open callback','GN retain/release','partner filename heuristic/path existence','GN key/value metadata primitives and constant key array'],actual_sample_decoding_tested_in_this_corpus=False,actual_GN_runtime_validated=False,complete_engine_built=False,macos_audio_unit_validated=False,cases=cases)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k] for k in ['fixture_count','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']},indent=2))
