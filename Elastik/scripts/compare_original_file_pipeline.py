#!/usr/bin/env python3
"""Open WAVE -> lazy cache -> refill -> provider -> voice, without sample stubs.

Container metadata and cache audio are derived by the real original code, or
by translated native routines. Only GN/OS primitives, other-format rejection
for WAVE-only fixtures, allocation, mutex and manual timer dispatch are bound.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from compare_original_wave import WaveOracle, WAVE,IO,PATH,FILE,IOVT,PATHVT,OBJVT,BUFFER,serialize,pack
from compare_original_sample_file import (FILE as SAMPLE_FILE,HANDLE,VOICE,KEY,RANGE,NEXT,THREAD,MUTEX,MUTEX_VT,LOCK,UNLOCK)
from original_cache_oracle import CACHE,STACK,RETURN
from wave_fixtures import fixtures as wave_fixtures
from native_probe import NativeProbe
from legacy_image import SHA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import (UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,
    UC_X86_REG_EBP,UC_X86_REG_EBX,UC_X86_REG_ESI,UC_X86_REG_EDI,UC_X86_REG_EFLAGS,UC_X86_REG_MXCSR)

AIFF,AIFFVT,TIMER,KEYARRAY,EXCEPTION,EXCVT,CLASS,CLASSVT,DEST=0x572000,0x573000,0x574000,0x575000,0x576000,0x576100,0x576400,0x576500,0x577000
OUT=0x2c00000
def fixtures(wave):
    selected=[]
    for c in wave_fixtures(wave):
        name=c['name']
        if (name.startswith('pcm-') and '-frames257-extra0' in name
            or name.startswith('compressed-wave-tag') and '-first1-count1' in name
            or name in ['cue-count3-before-dataTrue','smpl-loops3-data0-before-dataFalse','instrument-and-acid-flags2-root60-beforeFalse']
            or name.startswith('embedded-original-wave-first')):
            selected.append(c)
    for c in selected:
        for direction in [0,1]:
            first=c['h'][12]
            if direction and first<17:first=17
            yield dict(name=c['name']+f'-direction{direction}',raw=c['raw'],
                h=[len(c['raw']),17,first,min(direction,1),direction,1,0,c['h'][14],0,2,0,1])
    base=next(c for c in selected if c['name']=='pcm-tag1-bits16-ch2-frames257-extra0')
    for timer,repeat,loop,direction in [(0,1,0,0),(0,5,1,0),(1,1,0,1),(1,5,1,1)]:
        yield dict(name=f'cache-idempotent-timer{timer}-repeat{repeat}-wrapped{loop}-direction{direction}',raw=base['raw'],h=[len(base['raw']),17,201,1,direction,1,0,257,timer,repeat,loop,0])

class PipelineOracle(WaveOracle):
    def __init__(self,binary):
        super().__init__(binary)
        callbacks={0x2447c2:self.construct_aiff,0x24940e:self.construct_wave,0x218aa6:self.construct_cache,
            0x2dc66:lambda *x:self.finish(),0x2dfe2:self.retain_any,0x2dffc:lambda *x:self.finish(),0x2e0bc:self.identity,
            0xbea2:self.push_frame,0xbec0:self.pop_frame,0x500f10:self.unsupported,
            0x500f20:lambda *x:self.finish(CLASS),0x500f30:lambda *x:self.finish(1),
            0x500f40:lambda *x:self.finish(CACHE),0x70218:self.timer,0x1ac468:lambda *x:self.finish(0),
            0x64024:self.contains,0x2a364:self.key_at,0x410a8:lambda *x:self.finish(THREAD),
            LOCK:lambda *x:self.mutex(25),UNLOCK:lambda *x:self.mutex(26)}
        for at,fn in callbacks.items():self.uc.hook_add(UC_HOOK_CODE,fn,begin=at,end=at)
        self.import_handlers['_setjmp']=self.setjmp
        self.put(AIFF,AIFFVT);self.put(AIFFVT+0x48,0x500e00);self.put(AIFFVT+0x1a4,0x500f10)
        self.put(EXCEPTION,EXCVT);self.put(EXCVT+0x1ac,0x500f20);self.put(CLASS,CLASSVT);self.put(CLASSVT+0x88,0x500f30)
        self.put(TIMER,0x578000);self.put(0x578040,0x2dfe2)
    def new(self):
        n,=self.arguments(1)
        if n==0x38:self.finish(AIFF)
        elif n==0x840:self.finish(WAVE)
        elif n==0x58:self.finish(CACHE)
        else:super().new()
    def construct_aiff(self,*unused):self.record(24,0);self.finish()
    def construct_wave(self,*unused):self.record(24,1);self.finish()
    def construct_cache(self,*unused):
        self.constructs+=1;self.record(24,2);self.put(CACHE,0x3a1f28)
        self.put(CACHE+0x18,0x4000);self.put(CACHE+0x2c,TIMER if self.pipeline_h[8] else 0);self.finish()
    def retain_any(self,*unused):
        p,=self.arguments(1)
        if p==TIMER:self.record(22)
        self.finish(p)
    def push_frame(self,*unused):p,=self.arguments(1);self.exception_frames.append(p);self.finish()
    def pop_frame(self,*unused):p,=self.arguments(1);assert self.exception_frames.pop()==p;self.finish()
    def setjmp(self):
        p,=self.arguments(1);sp=self.uc.reg_read(UC_X86_REG_ESP);regs=[UC_X86_REG_EBP,UC_X86_REG_EBX,UC_X86_REG_ESI,UC_X86_REG_EDI]
        self.jumps[p]=(sp,self.word(sp)&0xffffffff,{r:self.uc.reg_read(r) for r in regs});self.finish()
    def unsupported(self,*unused):
        p=self.exception_frames.pop();sp,ret,regs=self.jumps[p];self.put(p+0x4c,EXCEPTION)
        for r,v in regs.items():self.uc.reg_write(r,v)
        self.uc.reg_write(UC_X86_REG_ESP,sp+4);self.uc.reg_write(UC_X86_REG_EIP,ret);self.uc.reg_write(UC_X86_REG_EAX,1)
    def contains(self,*unused):d,key=self.arguments(2);self.finish(int(self.n(key)['value'].decode('latin1') in self.n(d)['value']))
    def key_at(self,*unused):p,index=self.arguments(2);assert p==KEYARRAY;self.finish(self.keys[index])
    def count(self,*unused):
        p,=self.arguments(1)
        if p==KEYARRAY:self.finish(2)
        else:super().count()
    def allocate_dvi(self,*unused):
        n,=self.arguments(1)
        if self.cache_setup:
            step=self.allocation_step;kind=[1,2,3,5][step];count=self.word(CACHE+0x20) if step<2 else self.word(CACHE+0x24) if step==2 else n
            assert n==count*{1:8,2:4,3:12,5:1}[kind]
            self.record(20,kind,count,int(self.word(SAMPLE_FILE+0xc)==CACHE),self.word(CACHE+0x1c));self.allocation_step+=1;self.finish(self.alloc(n))
        elif self.cache_fill and self.word(self.uc.reg_read(UC_X86_REG_ESP))==0x2182b9:
            self.record(23,n,self.word(CACHE+0x1c));p=self.alloc(n);self.uc.mem_write(p,struct.pack('<f',0.03125)*(n//4));self.finish(p)
        else:super().allocate_dvi()
    def timer(self,*unused):
        cb,data,lo,hi,repeat=self.arguments(5);assert cb==0x217fd0 and data==CACHE and struct.pack('<II',lo,hi)==struct.pack('<d',0.2) and repeat==1
        self.record(21,200,1);self.finish(TIMER)
    def mutex(self,event):self.record(event);self.finish()
    def diagnostic(self,*unused):
        p,=self.arguments(1);text=self.cstring(p)
        if text==b'getSamplesOfChannelForRange failed':self.finish()
        elif text.startswith(b'GNSoundFileCache: buffer unnderrun'):
            args=self.arguments(5);self.record(30,2,*args[1:4]);self.finish()
        else:super().diagnostic()
    def reset_voice(self,h,n):
        self.uc.mem_write(VOICE,bytes(0x140));self.uc.mem_write(KEY,bytes(0x120));self.put(VOICE+0x98,KEY)
        self.put(VOICE+0x9c,n//2 if h[10] else 0,n//4 if h[10] else n-1);self.put(VOICE+0xb0,-7)
        self.put(KEY+0x8c,HANDLE);self.put(KEY+0x58,h[5],h[4]);self.uc.mem_write(VOICE+0x91,bytes([h[6]]))
        ramps=[1.0,0.25 if h[11] else 1.0,0.03125 if h[11] else 0.0]*2+[0.0,1.0,0.0]*2
        self.uc.mem_write(VOICE+0x110,struct.pack('<6f',*ramps[:6]));self.uc.mem_write(VOICE+0xf8,struct.pack('<6f',*ramps[6:]));self.put(NEXT,0x12345678);self.put(RANGE,-11,-13)
    def execute(self,case):
        h=case['h'];self.pipeline_h=h;self.exception_frames=[];self.jumps={};self.cache_setup=False;self.cache_fill=False;self.constructs=0
        # Initialize only GN/allocator fixtures. Mode 2 performs no WAVE open
        # or decode; both operations below execute through the original file.
        setup=dict(raw=case['raw'],h=[2,len(case['raw']),0,1,-1,-1,0,0,0,0,0,0,0,0,h[7],0])
        super().execute(setup);self.trace=[];self.put(CACHE,*([0]*24));self.put(SAMPLE_FILE,*([0]*32));self.put(HANDLE,*([0]*16));self.put(THREAD,*([0]*64));self.put(0x3d9074,0,0)
        target=self.node(1,{});self.put(SAMPLE_FILE+0x48,target);self.put(PATHVT+0x40,0x500e00,0x500e00)
        self.keys=[self.node(5,b'chunks'),self.node(5,b'privateChunks')];self.put(0x3d9084,KEYARRAY)
        self.put(0x3d4a90,MUTEX);self.put(MUTEX,MUTEX_VT);self.put(MUTEX_VT+0x1a4,LOCK);self.put(MUTEX_VT+0x1ac,UNLOCK)
        self.call(0x1adbb6,SAMPLE_FILE,PATH);assert not self.error
        self.put(WAVE+0xc,h[7],BUFFER);self.uc.mem_write(BUFFER,b'\xa5'*h[7])
        self.cache_setup=True;self.allocation_step=0
        for i in range(h[9]):self.call(0x1ac9dc,SAMPLE_FILE)
        self.cache_setup=False
        client=self.call(0x2182e0,CACHE);self.put(HANDLE+0xc,SAMPLE_FILE,client)
        n=self.word(WAVE+0x28);records=[]
        for i in range(3):
            if i==1:
                self.cache_fill=True;self.audio_active=True;self.call(0x218d5e,CACHE);self.audio_active=False;self.cache_fill=False
            self.uc.mem_write(0x3d4a48,bytes([i==2]));self.reset_voice(h,n);self.uc.mem_write(OUT,struct.pack('<f',0.03125)*(h[1]+16));self.audio_active=True
            result=self.call(0x152664,VOICE,OUT,h[3],h[2],h[1],NEXT,RANGE);self.audio_active=False
            header=[result,self.word(NEXT),self.word(RANGE),self.word(RANGE+4),self.word(VOICE+0xb0),self.uc.mem_read(CACHE+0x30,1)[0],self.word(client+4),self.word(client+8)]
            records.append(pack(header)+bytes(self.uc.mem_read(VOICE+0x110,24))+bytes(self.uc.mem_read(VOICE+0xf8,24))+bytes(self.uc.mem_read(OUT,(h[1]+16)*4)))
        assert not self.exception_frames and self.word(THREAD+0x28)==0
        capacity=self.word(CACHE+0x20);slots=self.word(CACHE+0x1c);blocks=self.word(CACHE+0x10)
        header=[0,self.word(SAMPLE_FILE+0x20),self.word(SAMPLE_FILE+0x10),self.word(SAMPLE_FILE+0x14),n,int(bool(self.word(SAMPLE_FILE+0xc))),capacity,self.word(CACHE+0x24),self.word(CACHE+0x44),slots,self.uc.mem_read(CACHE+0x30,1)[0],self.word(0x3d9078),int(bool(self.word(CACHE+0x2c))),self.constructs]
        answer=pack(header)+bytes(self.uc.mem_read(SAMPLE_FILE+0x18,8))+serialize(self.n(target))+b''.join(records)
        answer+=pack([self.word(blocks+i*8) for i in range(capacity)])+bytes(self.uc.mem_read(self.word(CACHE+0x14),capacity*4))
        answer+=b''.join(bytes(self.uc.mem_read(self.word(blocks+i*8+4),self.word(CACHE+0x18))) for i in range(slots))
        return answer+pack([len(self.trace)])+b''.join(pack(row) for row in self.trace)
    def call_packed(self,address,packed):
        self.error=0;self.uc.mem_write(STACK,struct.pack('<I',RETURN)+packed);self.uc.reg_write(UC_X86_REG_ESP,STACK);self.uc.reg_write(UC_X86_REG_EFLAGS,2);self.uc.reg_write(UC_X86_REG_MXCSR,0x1f80)
        self.uc.emu_start(address,RETURN,count=50000000)
        if not self.error and self.uc.reg_read(UC_X86_REG_EIP)!=RETURN:raise ValueError(f'Original {address:#x} did not return')
        return self.uc.reg_read(UC_X86_REG_EAX)

def compare(binary,runner,prefix,platform,wave):
    oracle=PipelineOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=0
    for case in fixtures(wave):
        try:expected=oracle.execute(case)
        except Exception as e:raise RuntimeError(f'Original pipeline failed at {case["name"]}: {e}') from e
        data=pack(case['h'])+case['raw'];actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA010-native');folder.mkdir(exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]:(folder/f'failing-pipeline-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)))
            raise ValueError(f'Pipeline mismatch {case["name"]} exit={actual.returncode} byte={at} expected={expected[at:at+24].hex()} native={actual.stdout[at:at+24].hex()}')
        total+=len(expected);cases.append(dict(name=case['name'],source_sha256=hashlib.sha256(case['raw']).hexdigest(),cache_slots=struct.unpack_from('<i',expected,36)[0],trace_events=len(oracle.trace),all_bytes_match=True,sha256=hashlib.sha256(expected).hexdigest()))
    probe.close();return dict(checkpoint='ELA010',original_i386_sha256=SHA,compiled_platform=platform,scope='WAVE bytes through original factory/file open, lazy cache creation, cold read, refill, cached voice and direct voice',fixture_count=len(cases),compared_bytes=total,all_cases_match_bit_for_bit=True,header_derived_metadata_substituted=False,decoded_samples_substituted=False,initial_cache_audio_supplied=False,original_reader_factory_executed=True,original_file_open_executed=True,original_lazy_cache_creation_executed=True,original_refill_and_provider_and_voice_chunk_executed=True,voice_reads_per_case=3,original_mono_partner_finder_ported=False,other_format_readers_ported=False,boundaries_adapted=['GN constructors/init/autorelease and retain/release','AIFF open classified unsupported for WAVE-only fixtures','GN metadata primitives and key array','GN exception frames/setjmp','byte file I/O','allocator and cache sample memory initialization','mutex/TLS primitives','timer factory and manual sequential refill dispatch','partner filename finder returns no partner in this corpus','voice failure diagnostic outside DSP API'],actual_GN_runtime_validated=False,actual_macos_execution=False,thread_concurrency_validated=False,complete_voice_engine_built=False,macos_audio_unit_validated=False,automatic_fixture_retries=0,cases=cases)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--wave',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform,a.wave);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k] for k in ['fixture_count','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']},indent=2))
