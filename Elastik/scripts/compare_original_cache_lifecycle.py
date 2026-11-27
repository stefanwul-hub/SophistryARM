#!/usr/bin/env python3
"""Execute pinned i386 cache lifecycle against the translated native routines.

Only GN allocation/free, opaque-object retention and timer factory/cancel are
boundaries. Original field initialization, sizes, client scans, sample metadata
getters and PCM-width lookup execute unchanged. No OS scheduling is simulated.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
from original_cache_oracle import OriginalCacheOracle, CACHE, STACK
from native_probe import NativeProbe
from legacy_image import SHA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP

FILE, READER, VTABLE, DELEGATE, TIMER = 0x540000, 0x541000, 0x542000, 0x543000, 0x544000
SCRATCH, SCRATCH_BYTES = 0x3d9074, 0x3d9078
def pack(v): return struct.pack('<'+'i'*len(v), *v)
def op(k,a=0,b=0,c=0): return [k,a,b,c]


def fixtures():
    rng=random.Random(0xe1a007)
    yield dict(name='initializer-preserves-unspecified-fields',h=[9,2,127,131,0x44,1,0,0],ops=[op(1)])
    yield dict(name='cleanup-without-arrays',h=[9,2,127,131,0x44,1,0,0],ops=[op(1),op(11,1),op(7),op(7),op(8),op(8),op(9)])
    for block in [7,64,1024,65536]:
        for slots in [0,1,3]:
            for clients in [1,4,0]:
                operations=[op(1),op(10,slots),op(2,block*5+block//2,clients,block),op(7),op(7)]
                operations += [op(4),op(6,0,7,9),op(4),op(5,0),op(4),op(8),op(7),op(11,1),op(9)]
                yield dict(name=f'allocate-block{block}-slots{slots}-clients{clients}',h=[9,2,127,131,0x44,1,0,0],ops=operations)
    for block in [65536,1048576]:
        yield dict(name=f'default-cache-size-block{block}',h=[9,1,127,131,0x44,1,0,0],ops=[op(1),op(2,0,3,block),op(9)])
    # Literal widths recovered independently in ELA004, including 24-bit,
    # float64 width-only and unsupported-format zero. Not a WAV format tag.
    widths={0x10:2,0x11:3,0x12:4,0x13:4,0x14:8,0x43:1,0x44:4,0x45:1,0x777:0}
    for fmt in widths:
        for channels in [1,2,0x104]:
            for known,reader in [(127,1),(0,1),(0,0)]:
                # Empty files take the original 2GiB sizing branch; using four
                # channels bounds that fixture's table memory.
                if not known and not reader and channels==1: continue
                width=widths[fmt]
                target=16384*(channels&255)*width
                scratch=rng.choice([0,max(0,target//2),target,target+32])
                operations=[op(1),op(3),op(4),op(4),op(6,0,5,6),op(5,0),op(4),op(7),op(9)]
                yield dict(name=f'configure-fmt{fmt:x}-ch{channels:x}-known{known}-reader{reader}-scratch{scratch}',
                           h=[9,channels,known,131,fmt,reader,scratch,0],ops=operations)
    for fmt in [0x10,0x11,0x14,0x45,0x777]:
        for channels in [1,2,0x104]:
            target=16384*(channels&255)*widths[fmt]
            for mode,scratch in [('absent',0),('smaller',target//2),('equal',target),('larger',target+32)]:
                yield dict(name=f'scratch-{mode}-fmt{fmt:x}-ch{channels:x}',h=[9,channels,127,131,fmt,1,scratch,0],
                           ops=[op(1),op(3),op(3),op(9)])
    for slots in [0,1,3]:
        yield dict(name=f'cleanup-owner-cleared-during-cancel-slots{slots}',h=[9,2,127,131,0x44,1,0,0],
                   ops=[op(1),op(10,slots),op(2,1024,4,64),op(7),op(12,1),op(9)])
    for seed in range(20):
        operations=[op(1),op(2,17*8,3,17)]; count=0
        for i in range(40):
            if count and rng.randrange(3)==0: operations.append(op(5,rng.randrange(count)))
            else:
                operations.append(op(4));count+=1
                # Preallocate enough physical client records for all requests.
        operations[1][2]=48
        operations += [op(7),op(8),op(9)]
        yield dict(name=f'client-reuse-sequence{seed}',h=[9,2,127,131,0x44,1,0,0],ops=operations)


class LifecycleOracle(OriginalCacheOracle):
    def __init__(self,binary):
        super().__init__(binary);self.uc.mem_map(0x800000,0x4000000)
        for at,fn in [(0xaecc,self.allocate),(0xb122,self.release),(0x70218,self.timer),
                      (0x6f75c,self.cancel),(0xacae,self.warning),(0x2df76,lambda *x:self.finish())]:
            self.uc.hook_add(UC_HOOK_CODE,fn,begin=at,end=at)
        for at,operation in [(0x500a00,1),(0x500a10,2)]:
            self.uc.hook_add(UC_HOOK_CODE,lambda *x,operation=operation:self.object_op(operation),begin=at,end=at)
        self.uc.hook_add(UC_HOOK_CODE,self.frame_count,begin=0x500a20,end=0x500a20)
        self.put(VTABLE+0x40,0x500a00,0x500a10);self.put(VTABLE+0x1bc,0x500a20)
        self.put(DELEGATE,VTABLE);self.put(TIMER,VTABLE);self.put(READER,VTABLE)

    def record(self,*v):self.trace.append(list(v)+[0]*(6-len(v)))
    def token(self,p):
        p&=0xffffffff
        if not p:return 0
        if p==DELEGATE:return -2
        if p==TIMER:return -3
        return self.tokens.get(p,-1)
    def allocate_memory(self,kind,count,physical=None):
        if physical is None:physical=count+(4 if kind==3 else 0)
        size=physical*{1:8,2:4,3:12}.get(kind,1)
        result=self.heap;self.heap+=(size+15)//16*16+16
        if self.heap>=0x4800000:raise ValueError('Fixture heap bound')
        self.uc.mem_write(result,b'\xa5'*size);self.allocations.append((result,kind,count));self.tokens[result]=len(self.allocations)
        return result
    def allocate(self,*unused):
        requested,=self.arguments(1);step=self.allocation_step;slots=self.word(CACHE+0x1c)
        if step==0:kind,count=1,self.word(CACHE+0x20)
        elif step==1:kind,count=2,self.word(CACHE+0x20)
        elif step<2+slots:kind,count=4,self.word(CACHE+0x18)
        elif step==2+slots:kind,count=3,self.word(CACHE+0x24)
        else:kind,count=5,requested
        assert requested==count*{1:8,2:4,3:12}.get(kind,1)
        result=self.allocate_memory(kind,count);self.record(1,kind,count,len(self.allocations),slots,self.word(CACHE+0x24))
        self.allocation_step+=1;self.finish(result)
    def release(self,*unused):
        pointer,=self.arguments(1);ret=self.word(self.uc.reg_read(UC_X86_REG_ESP))
        if ret==0x217f34:kind=1
        elif ret==0x217f3f:kind=2
        elif ret==0x217f4a:kind=3
        elif ret==0x217f69:kind=4
        else:kind=5
        self.record(2,kind,self.token(pointer));self.finish()
    def object_op(self,operation):
        pointer,=self.arguments(1);self.record(3,operation,self.token(pointer));self.finish(pointer)
    def warning(self,*unused):
        pointer,=self.arguments(1);assert bytes(self.uc.mem_read(pointer,64)).split(b'\0')[0]==b'GNFileCache: To many file requesters.'
        self.record(4,1);self.finish()
    def timer(self,*unused):
        function,data,low,high,repeat=self.arguments(5)
        assert (function,data,struct.pack('<II',low,high),repeat)==(0x217fd0,CACHE,struct.pack('<d',0.2),1)
        self.record(5,200,1);self.finish(TIMER)
    def cancel(self,*unused):
        pointer,=self.arguments(1);self.record(6,self.token(pointer))
        if self.cancel_clears_owner:self.put(CACHE+0x2c,0)
        self.finish()
    def frame_count(self,*unused):self.record(8,self.case['h'][3]);self.finish(self.case['h'][3])
    def snapshot(self,result):
        w=self.word;c=CACHE
        header=[result,*[self.token(w(c+x)) for x in (0x10,0x14,0x40)],w(c+0x1c),w(c+0x18),w(c+0x20),w(c+0x24),w(c+0x44),w(c+0x4c),w(c+0x50),w(c+0x54),
                self.uc.mem_read(c+0x30,1)[0],self.uc.mem_read(c+0x31,1)[0],self.uc.mem_read(c+0x3c,1)[0],
                self.token(w(c+0xc)),self.token(w(c+0x2c)),self.token(w(SCRATCH)),w(SCRATCH_BYTES),int(w(c+0x48)!=0)]
        b=pack(header)+bytes(self.uc.mem_read(c+0x34,8))
        if w(c+0x10):
            b+=b''.join(pack([w(w(c+0x10)+i*8),self.token(w(w(c+0x10)+i*8+4))]) for i in range(w(c+0x20)))
        if w(c+0x14):b+=bytes(self.uc.mem_read(w(c+0x14),w(c+0x20)*4))
        if w(c+0x40):b+=bytes(self.uc.mem_read(w(c+0x40),w(c+0x24)*12))
        return b
    def execute(self,case):
        self.case=case;h=case['h'];self.trace=[];self.heap=0x800000;self.allocations=[];self.tokens={};self.cancel_clears_owner=False
        self.uc.mem_write(CACHE,bytes(0x60));self.put(CACHE,0x3a1d68);self.put(CACHE+0xc,DELEGATE)
        self.put(CACHE+0x18,h[0]);self.put(CACHE+0x44,3,0,-71,37,5)
        self.uc.mem_write(CACHE+0x30,b'\x09\x03');self.uc.mem_write(CACHE+0x3c,b'\x07');self.uc.mem_write(CACHE+0x34,struct.pack('<d',0.125))
        self.uc.mem_write(FILE,bytes(0x60));self.put(FILE+0x14,h[1]);self.put(FILE+0x20,h[4],h[2]);self.put(FILE+0x54,READER if h[5] else 0)
        self.put(SCRATCH,self.allocate_memory(5,h[6]) if h[6] else 0,h[6]);answer=b''
        for k,a,b,c in case['ops']:
            result=0
            if k==1:self.call(0x217cd2,CACHE)
            elif k==2:self.put(CACHE+0x18,c);self.allocation_step=0;self.call(0x217db8,CACHE,a,b)
            elif k==3:self.allocation_step=0;self.call(0x218b82,CACHE,FILE)
            elif k==4:result=(self.call(0x2182e0,CACHE)-self.word(CACHE+0x40))//12
            elif k==5:self.call(0x2183d2,CACHE,self.word(CACHE+0x40)+a*12)
            elif k==6:self.put(self.word(CACHE+0x40)+a*12+4,b,c)
            elif k==7:self.call(0x217fe2,CACHE)
            elif k==8:self.call(0x21803c,CACHE)
            elif k==9:self.call(0x217edc,CACHE)
            elif k==10:self.put(CACHE+0x1c,a)
            elif k==11:self.put(CACHE+0xc,DELEGATE if a else 0)
            elif k==12:self.cancel_clears_owner=bool(a)
            else:raise ValueError(k)
            answer+=self.snapshot(result)
        return answer+pack([len(self.trace)])+b''.join(pack(row) for row in self.trace)


def compare(binary,runner,prefix,platform):
    oracle=LifecycleOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=events=0
    for case in fixtures():
        case['h'][-1]=len(case['ops']);data=pack(case['h'])+b''.join(pack(row) for row in case['ops']);expected=oracle.execute(case)
        actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA007-native');folder.mkdir(parents=True,exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]: (folder/f'failing-lifecycle-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)))
            raise ValueError(f'Lifecycle mismatch {case["name"]}: exit={actual.returncode} byte={at} expected={expected[at:at+16].hex()} native={actual.stdout[at:at+16].hex()}')
        total+=len(expected);events+=len(oracle.trace)
        cases.append(dict(name=case['name'],operations=len(case['ops']),trace_events=len(oracle.trace),all_bytes_match=True,sha256=hashlib.sha256(expected).hexdigest()))
    probe.close()
    return dict(checkpoint='ELA007',scope='Cache initialization/allocation/configuration, client lifecycle, timer ownership and cleanup',
                original_i386_sha256=SHA,compiled_platform=platform,fixture_count=len(cases),compared_bytes=total,platform_trace_events=events,
                all_cases_match_bit_for_bit=True,allocator_client_padding_compared=True,unused_slot_pointers_normalized=True,
                boundaries_adapted=['GN allocation/free','opaque object retention','timer creation/cancel','reader frame metadata callback','GN base cleanup'],
                actual_GN_capacity_warning_runtime_tested=False,actual_os_scheduling_tested=False,concurrent_cache_mutation_tested=False,complete_engine_built=False,macos_audio_unit_validated=False,cases=cases)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[])
    p.add_argument('--platform',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform)
    a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:v for k,v in r.items() if k not in ['cases','boundaries_adapted']},indent=2))
