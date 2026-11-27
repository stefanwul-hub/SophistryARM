#!/usr/bin/env python3
"""Compare original i386 timer control with native C++, using explicit GN/OS bindings.

All six selected original timer functions execute unchanged. Event delivery is
invoked by the fixture, not wall-clock scheduling. GN temporary pools/actions,
opaque retain/release/autorelease and OS event-loop APIs are test boundaries.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from original_cache_oracle import OriginalCacheOracle
from native_probe import NativeProbe
from legacy_image import SHA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP

TIMER,VTABLE,POOL,ACTION=0x550000,0x551000,0x552000,0x553000
CALLBACK,DISPATCH,CONTEXT,CANCEL_TRAMP=0x500b40,0x500b50,0x554000,0x501200
TIMES=[0.0,0.2,0.125,1.0,3.75,1e-6]
OBJECTS={1:TIMER,2:0x555000,3:0x556000,4:0x557000,5:0x558000,6:ACTION,7:POOL,9:CONTEXT}
def pack(v):return struct.pack('<'+'i'*len(v),*v)
def op(k,*v):return [k,*v]+[0]*(5-len(v))


def fixtures():
    for repeat in [0,1,2,255]:
        for time in range(len(TIMES)):
            for behavior in [0,1,2,3,4]:
                yield dict(name=f'callback-repeat{repeat}-time{time}-behavior{behavior}',h=[0,0,0,0,0,0,0,0,0],ops=[op(1,repeat,time,behavior),op(5,1),op(5,0),op(4),op(3),op(3),op(6)])
        for behavior in [0,1,2,3,4]:
            for prior_name,prior_handler in [(0,0),(2,4),(3,5)]:
                yield dict(name=f'action-repeat{repeat}-behavior{behavior}-prior{prior_name}-{prior_handler}',
                           h=[0,0,prior_name,prior_handler,1,0,0,0,0],ops=[op(2,2,4,repeat,1,behavior),op(5,1),op(5,0),op(4),op(3),op(6)])
    for active in [0,1,2]:
        for handle in [0,1]:
            for name,handler in [(0,0),(2,0),(0,4),(2,4)]:
                for first in [3,4,5,6]:
                    yield dict(name=f'initial-active{active}-handle{handle}-objects{name}-{handler}-op{first}',
                               h=[active,0,name,handler,1,handle,0,0,0],ops=[op(first),op(5,1),op(3),op(6)])
    for name,handler in [(2,4),(3,4),(2,5),(3,5)]:
        yield dict(name=f'restart-action-same-or-changed-{name}-{handler}',h=[0,0,0,0,0,0,0,0,0],
                   ops=[op(2,2,4,1,1,0),op(3),op(2,name,handler,1,2,0),op(4),op(3),op(1,0,3,0),op(4),op(6)])


class TimerOracle(OriginalCacheOracle):
    def __init__(self,binary):
        super().__init__(binary)
        for at,method in [(0x500b00,lambda *x:self.object_op(1)),(0x500b10,lambda *x:self.object_op(2)),
                          (0x500b20,lambda *x:self.object_op(3)),(CALLBACK,self.callback),(DISPATCH,self.dispatch),
                          (0x84aa2,lambda *x:self.finish(0x559000)),(0x83b04,self.register),(0x83b2e,self.unregister),
                          (0x1e688,self.construct),(0x13158c,self.construct),(0x2dfa6,self.initialize),
                          (0x1e860,self.begin_pool),(0x131b4a,self.make_action),(0x59c92,lambda *x:self.finish(0x55a000)),(0x59f14,self.after)]:
            self.uc.hook_add(UC_HOOK_CODE,method,begin=at,end=at)
        self.import_handlers.update(_NewEventLoopTimerUPP=self.upp,_GetCurrentEventLoop=lambda:self.finish(0x55b000),
                                    _InstallEventLoopTimer=self.install,_RemoveEventLoopTimer=self.remove,__Znwm=self.new)
        self.put(VTABLE+0x40,0x500b00,0x500b10,0x500b20);self.put(VTABLE+0x1b0,DISPATCH)
        for p in OBJECTS.values():self.put(p,VTABLE)
        # Callback-side cancellation re-enters original code using its actual
        # stack rather than recursively resetting the emulator call frame.
        code=b'\x68'+struct.pack('<I',TIMER)+b'\xe8'+struct.pack('<i',0x6f75c-(CANCEL_TRAMP+10))+b'\x83\xc4\x04\xc3'
        self.uc.mem_write(CANCEL_TRAMP,code)

    def token(self,p):
        if not p:return 0
        if p in self.handles:return self.handles[p]
        for k,v in OBJECTS.items():
            if p==v:return k
        raise ValueError(f'Unknown pointer {p:#x}')
    def pointer(self,k):return OBJECTS[k] if k else 0
    def record(self,code,*values):
        self.trace.append([code,*values,*([0]*(5-len(values))),self.uc.mem_read(TIMER+0x10,1)[0],self.uc.mem_read(TIMER+0x11,1)[0],self.token(self.word(TIMER+0x14)),self.token(self.word(TIMER+0x18))])
    def object_op(self,operation):
        p,=self.arguments(1)
        if p==POOL and operation==2:self.record(7,7)
        else:self.record(1,operation,self.token(p))
        self.finish(p)
    def upp(self):
        fn,=self.arguments(1);assert fn==0x6fa3c;self.finish(fn)
    def install(self):
        args=self.arguments(9);loop,low,high,ilow,ihigh,upp,timer,dest=args[:8]
        assert loop==0x55b000 and upp==0x6fa3c and timer==TIMER
        self.handle_count+=1;handle=0x560000+self.handle_count*16;self.handles[handle]=100+self.handle_count
        self.record(2,*[struct.unpack('<i',struct.pack('<I',v))[0] for v in (low,high,ilow,ihigh)],100+self.handle_count)
        self.put(dest,handle);self.finish(0)
    def remove(self):p,=self.arguments(1);self.record(3,self.token(p));self.finish(0)
    def register(self,*unused):
        registry,fn,timer=self.arguments(3);assert (registry,fn,timer)==(0x559000,0x6f9be,TIMER);self.record(4,1);self.finish()
    def unregister(self,*unused):
        registry,fn,timer=self.arguments(3);assert (registry,fn,timer)==(0x559000,0x6f9be,TIMER);self.record(5,1);self.finish()
    def new(self):
        size,=self.arguments(1);assert size in (20,40);self.finish(POOL if size==20 else ACTION)
    def construct(self,*unused):p,=self.arguments(1);self.put(p,VTABLE);self.finish()
    def initialize(self,*unused):p,=self.arguments(1);self.finish(p)
    def begin_pool(self,*unused):p,capacity=self.arguments(2);assert p==POOL;self.record(6,capacity,7);self.finish()
    def make_action(self,*unused):p,name=self.arguments(2);assert p==ACTION;self.record(8,self.token(name),6);self.finish()
    def after(self,*unused):self.record(11);self.finish()
    def mutate(self,behavior,action):
        if behavior==1:self.uc.reg_write(UC_X86_REG_EIP,CANCEL_TRAMP);return
        if behavior==2:self.put(TIMER+0x1c,CALLBACK if action else 0,CONTEXT if action else 0)
        elif behavior==3:self.put(TIMER+0x18,0)
        elif behavior==4:self.put(TIMER+0x14,0)
        self.finish()
    def callback(self,*unused):
        context,=self.arguments(1);assert context==CONTEXT;self.record(10,9);self.mutate(self.callback_behavior,False)
    def dispatch(self,*unused):
        handler,action=self.arguments(2);self.record(9,self.token(handler),self.token(action));self.mutate(self.dispatch_behavior,True)
    def snapshot(self):
        return pack([self.token(self.word(TIMER+0xc)),self.uc.mem_read(TIMER+0x10,1)[0],self.uc.mem_read(TIMER+0x11,1)[0],
                     self.token(self.word(TIMER+0x14)),self.token(self.word(TIMER+0x18)),int(self.word(TIMER+0x1c)!=0),self.token(self.word(TIMER+0x20))])
    def execute(self,case):
        h=case['h'];self.trace=[];self.handles={0x560000:100};self.handle_count=0;self.callback_behavior=h[6];self.dispatch_behavior=h[7]
        self.uc.mem_write(TIMER,bytes(0x24));self.put(TIMER,VTABLE);self.put(TIMER+0xc,0x560000 if h[5] else 0)
        self.uc.mem_write(TIMER+0x10,bytes([h[0],h[1]]));self.put(TIMER+0x14,self.pointer(h[2]),self.pointer(h[3]),CALLBACK if h[4] else 0,CONTEXT if h[4] else 0)
        answer=b''
        for k,a,b,c,d,e in case['ops']:
            if k==1:self.callback_behavior=c;self.call_packed(0x6fdb4,struct.pack('<IIIdI',TIMER,CALLBACK,CONTEXT,TIMES[b],a))
            elif k==2:self.dispatch_behavior=e;self.call_packed(0x6faba,struct.pack('<IIIdI',TIMER,self.pointer(a),self.pointer(b),TIMES[d],c))
            elif k==3:self.call(0x6f75c,TIMER)
            elif k==4:self.call(0x6f80a,TIMER)
            elif k==5:self.uc.mem_write(0x3d432c,bytes([a]));self.call(0x6fa3c,0x560000,TIMER)
            elif k==6:self.call(0x6f96c,TIMER)
            else:raise ValueError(k)
            answer+=self.snapshot()
        return answer+pack([len(self.trace)])+b''.join(pack(row) for row in self.trace)


def compare(binary,runner,prefix,platform):
    oracle=TimerOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=events=0
    for case in fixtures():
        case['h'][-1]=len(case['ops']);data=pack(case['h'])+b''.join(pack(row) for row in case['ops']);expected=oracle.execute(case);actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA007-native');folder.mkdir(parents=True,exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]: (folder/f'failing-timer-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)))
            raise ValueError(f'Timer mismatch {case["name"]}: exit={actual.returncode} byte={at} expected={expected[at:at+16].hex()} native={actual.stdout[at:at+16].hex()}')
        total+=len(expected);events+=len(oracle.trace)
        cases.append(dict(name=case['name'],operations=len(case['ops']),trace_events=len(oracle.trace),all_bytes_match=True,sha256=hashlib.sha256(expected).hexdigest()))
    probe.close()
    return dict(checkpoint='ELA007',scope='Callback/action timer start, cancel, fire, event suspension and cleanup; state and boundary order',
                original_i386_sha256=SHA,compiled_platform=platform,fixture_count=len(cases),compared_bytes=total,platform_trace_events=events,
                all_cases_match_bit_for_bit=True,boundaries_adapted=['Carbon current-loop timer APIs','GN cleanup registry','opaque retain/release/autorelease',
                  'temporary GN pools and action objects','callback/action bodies','GN after-dispatch flush'],
                autorelease_calls_and_pool_order_compared=True,actual_GN_reference_counting_and_pool_drain_tested=False,
                actual_os_scheduling_tested=False,complete_engine_built=False,macos_audio_unit_validated=False,cases=cases)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[])
    p.add_argument('--platform',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform)
    a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:v for k,v in r.items() if k not in ['cases','boundaries_adapted']},indent=2))
