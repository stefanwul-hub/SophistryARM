#!/usr/bin/env python3
"""Execute original GNFile data/memory/fork control versus native C++."""
import argparse,hashlib,itertools,json,struct
from pathlib import Path
from original_cache_oracle import OriginalCacheOracle,STACK,RETURN
from native_probe import NativeProbe
from legacy_image import SHA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_EFLAGS
FILE,DATA,VT,STORAGE,OUT,COUNT=0x540000,0x541000,0x542000,0x550000,0x580000,0x590000
def pack(v):return struct.pack('<'+'i'*len(v),*((x+(1<<31))%(1<<32)-(1<<31) for x in v))
def signed(v):return (v+(1<<31))%(1<<32)-(1<<31)
def op(k,a=0,b=0,c=0):return [k,a,b,c]
def fixture(name,ops,data=1,fork=0,pos=0,read=0,get=0,set_=0,actual=-1):
    return dict(name=name,h=[data,fork,pos,64,64,37,7,1,read,get,set_,actual,len(ops),0,85,1],ops=ops)
def fixtures():
    yield fixture('bind-data-retain-same-null-and-recover',[op(1,1),op(3,17),op(1,1),op(1,2),op(3,9),op(1,0),op(4),op(1,2),op(1,1)])
    for first,count in itertools.product([-1,0,1,63,64,65,0x7fffffff],[0,1,17,64,65,256]):
        # Avoid the original wrapped positive memcpy from an inaccessible
        # INT_MAX pointer; query/zero-count/clip cases still exercise that state.
        if first==0x7fffffff and count>0:continue
        yield fixture(f'memory-first{first}-count{count}',[op(2,count),op(4),op(5),op(2,1)],pos=first)
    for mask,count in itertools.product(range(8),[-1,0,17]):yield fixture(f'read-assertions-mask{mask}-count{count}',[op(2,count,mask)])
    for data,fork in itertools.product([0,1],[0,1,-1,-32768]):
        for offset in [-1,0,63,64,0x7fffffff]:yield fixture(f'seek-data{data}-fork{fork}-offset{offset}',[op(3,offset),op(4),op(5)],data=data,fork=fork)
    for k in [3,4,5]:yield fixture(f'null-file-method{k}',[op(k,1,1) if k==3 else op(k,1)])
    for fork,count,error,actual in itertools.product([1,-32768],[0,1,17],[0,-39,-1],[0,1,7,-1]):
        yield fixture(f'fork-read-{fork}-count{count}-err{error}-actual{actual}',[op(2,count),op(4)],data=0,fork=fork,read=error,actual=actual)
    for get,set_ in itertools.product([0,-1,-39],[0,-1,-39]):yield fixture(f'fork-position-errors-get{get}-set{set_}',[op(4),op(3,91),op(4),op(5),op(4)],data=0,fork=3,get=get,set_=set_)
    for lo,hi in [(0,0),(-1,0),(17,1),(0,-1),(-1,0x7fffffff)]:yield fixture(f'fork-position-low{lo}-high{hi}',[op(10,lo,hi),op(4),op(5)],data=0,fork=5)
    yield fixture('closed-read-preserves-requested-count',[op(2,17),op(2,0),op(4),op(5)],data=0)

class ByteFileOracle(OriginalCacheOracle):
    def __init__(self,binary):
        super().__init__(binary)
        for at,fn in [(0x500c00,lambda *x:self.object_op(1)),(0x500c10,lambda *x:self.object_op(2)),(0x27b4e,self.lock),(0x278d6,self.length),(0x27abc,self.bytes),(0x33b90,lambda *x:self.finish(1)),(0xbfd6,self.raise_error),(0xa930,lambda *x:self.finish(0))]:self.uc.hook_add(UC_HOOK_CODE,fn,begin=at,end=at)
        self.import_handlers.update(_FSReadFork=self.read_fork,_FSGetForkPosition=self.get_position,_FSSetForkPosition=self.set_position);self.put(VT+0x40,0x500c00,0x500c10)
    def event(self,*v):self.trace.append(list(v)+[0]*(6-len(v)))
    def id(self,p):return (p-DATA)//0x100+1 if p else 0
    def ptr(self,n):return DATA+(n-1)*0x100 if n else 0
    def object_op(self,op):p,=self.arguments(1);n=self.id(p);self.event(1,op,n);self.refs[n-1]+=1 if op==1 else -1;self.finish(p)
    def lock(self,*unused):
        p,=self.arguments(1);n=self.id(p);self.event(2,n)
        if not n:self.error=4;self.uc.emu_stop()
        else:self.locked[n-1]=1;self.finish()
    def length(self,*unused):p,=self.arguments(1);n=self.id(p);self.event(3,n,self.h[3+n]);self.finish(self.h[3+n])
    def bytes(self,*unused):p,=self.arguments(1);n=self.id(p);self.event(4,n);self.finish(STORAGE+(n-1)*0x1000+16)
    def raise_error(self,*unused):self.error=4;self.uc.emu_stop()
    def read_fork(self):
        fork,origin,lo,hi,wanted,out,count=self.arguments(7);fork=signed(fork);actual=wanted if self.h[11]<0 else min(self.h[11],wanted);actual=max(0,actual)
        if actual:self.uc.mem_write(out,bytes(((self.fork_position+i)*13)&255 for i in range(actual)))
        self.fork_position=(self.fork_position+actual)&0xffffffffffffffff;self.put(count,actual);self.event(5,fork,wanted,actual,self.h[8]);self.finish(self.h[8])
    def get_position(self):fork,out=self.arguments(2);fork=signed(fork);self.uc.mem_write(out,struct.pack('<Q',self.fork_position));self.event(6,fork,self.fork_position&0xffffffff,self.fork_position>>32,self.h[9]);self.finish(self.h[9])
    def set_position(self):
        fork,origin,lo,hi=self.arguments(4);fork=signed(fork);self.event(7,fork,origin,signed(lo),self.h[10])
        if not self.h[10]:self.fork_position=(self.fork_end+signed(lo))&0xffffffffffffffff if origin==2 else lo
        self.finish(self.h[10])
    def call_(self,addr,*args):
        self.error=0;self.uc.mem_write(STACK,struct.pack('<I',RETURN)+pack(args));self.uc.reg_write(UC_X86_REG_ESP,STACK);self.uc.reg_write(UC_X86_REG_EFLAGS,2);self.uc.emu_start(addr,RETURN,count=500000)
        if not self.error and self.uc.reg_read(UC_X86_REG_EIP)!=RETURN:raise ValueError('Original did not return')
        return self.uc.reg_read(UC_X86_REG_EAX)
    def execute(self,c):
        self.h=h=list(c['h']);self.trace=[];self.refs=[1,1];self.locked=[0,0];self.fork_position=(h[6]&0xffffffff)|((h[7]&0xffffffff)<<32);self.fork_end=(h[14]&0xffffffff)|((h[15]&0xffffffff)<<32);self.uc.mem_write(FILE,bytes(0x80));self.put(FILE+0xc,self.ptr(h[0]));self.uc.mem_write(FILE+0x10,struct.pack('<h',h[1]));self.put(FILE+0x1c,h[2],h[3])
        for n in [1,2]:self.put(self.ptr(n),VT);self.uc.mem_write(STORAGE+(n-1)*0x1000,b'\xa5'*16+bytes((j*37+n*19)&255 for j in range(h[3+n]))+b'\xa5'*16)
        answer=b''
        for k,a,b,d in c['ops']:
            self.error=0;value=count=0;payload=b''
            if k==1:self.call_(0x17f8a0,FILE,self.ptr(a))
            elif k==2:
                count=a;size=max(a,256)+32;self.uc.mem_write(OUT,b'\xa5'*size);self.put(COUNT,a);value=self.call_(0x17f918,0 if b&1 else FILE,0 if b&2 else OUT+16,0 if b&4 else COUNT);value=value&255 if not self.error else 0;count=self.word(COUNT);payload=bytes(self.uc.mem_read(OUT,size))
            elif k==3:self.call_(0x180c72,0 if b else FILE,a)
            elif k==4:value=self.call_(0x180a68,0 if a else FILE);value=value if not self.error else 0
            elif k==5:value=self.call_(0x180b54,0 if a else FILE);value=value if not self.error else 0
            elif k==6:self.h[8:11]=[a,b,d]
            elif k==7:self.h[11]=a
            elif k==8:self.put(FILE+0xc,self.ptr(a));self.put(FILE+0x1c,b,d)
            elif k==9:self.uc.mem_write(FILE+0x10,struct.pack('<h',a))
            elif k==10:self.fork_position=(a&0xffffffff)|((b&0xffffffff)<<32)
            else:raise ValueError('Unknown operation')
            answer+=pack([self.error,value,count,self.id(self.word(FILE+0xc)),struct.unpack('<h',self.uc.mem_read(FILE+0x10,2))[0],self.word(FILE+0x1c),self.word(FILE+0x20),self.fork_position&0xffffffff,self.fork_position>>32,*self.refs,*self.locked,len(payload)])+payload
        return answer+pack([len(self.trace)])+b''.join(pack(e) for e in self.trace)

def compare(binary,runner,prefix,platform):
    oracle=ByteFileOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=0
    for c in fixtures():
        expected=oracle.execute(c);data=pack(c['h'])+b''.join(pack(o) for o in c['ops']);actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA012-native');folder.mkdir(exist_ok=True)
            for label,content in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]:(folder/f'failing-byte-file-{label}.bin').write_bytes(content)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)));raise ValueError(f'Byte file mismatch {c["name"]}: exit={actual.returncode} byte={at} expected={expected[at:at+20].hex()} native={actual.stdout[at:at+20].hex()}')
        total+=len(expected);cases.append(dict(name=c['name'],sha256=hashlib.sha256(expected).hexdigest(),all_bytes_match=True))
    probe.close();return dict(checkpoint='ELA012',original_i386_sha256=SHA,compiled_platform=platform,fixture_count=len(cases),compared_bytes=total,all_cases_match_bit_for_bit=True,automatic_fixture_retries=0,boundaries_adapted=['GN data reference/lock/length/bytes primitives','FSReadFork/FSGetForkPosition/FSSetForkPosition','GN assertion to status'],actual_macos_fork_io_validated=False,actual_GN_reference_counting_validated=False,complete_engine_built=False,audio_unit_validated=False,cases=cases)
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k] for k in ['fixture_count','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']},indent=2))
