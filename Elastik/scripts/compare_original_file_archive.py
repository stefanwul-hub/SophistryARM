#!/usr/bin/env python3
"""Pinned original GNFA parser/member/data code versus translated C++.

Names/objects, allocator, raw I/O, mutex, path resolution, GNFile base fallback
and the optional delegate are explicit bindings. No user bank is required.
"""
import argparse
import hashlib
import itertools
import json
from pathlib import Path
import random
import struct
from original_cache_oracle import OriginalCacheOracle,STACK,RETURN
from legacy_image import SHA
from native_probe import NativeProbe
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_EFLAGS,UC_X86_REG_MXCSR

CORE,PATH,MEMBER,OWNER,MUTEX,MUTEXVT=0x540000,0x541000,0x541100,0x541200,0x541300,0x541400
IOS,IOVT,CLONEPATH,PATHVT,DELEGATE,DELEGATEVT=0x542000,0x543000,0x544000,0x544100,0x544400,0x544500
DESC,OUT,NAMES,DATAOBJS=0x580000,0x2800000,0x900000,0xa00000
BUILTIN=Path('reference/original-payload/Library/Audio/Plug-Ins/Components/Elastik.component/Contents/Resources/Elastik.elastik')
ARCHIVE_SHA='9b4aca313f9ba24da8c4c2b2473f4023ca9a3efcd009d117644c3a46e2be0f84'
def pack(v):return struct.pack('<'+'i'*len(v),*((x+(1<<31))%(1<<32)-(1<<31) for x in v))
def signed(v):return (v+(1<<31))%(1<<32)-(1<<31)
def op(kind,a=0,b=0,c=0):return [kind,a,b,c]
def record(name,data=b'',*,length=None,storage=None,size=556,flags=0,parent=0,field6=0,field7=0,timestamp=0):
    units=name.encode('utf-16-be','surrogatepass') if isinstance(name,str) else name
    if len(units)>510:raise ValueError('Fixture name must be terminated in 256 units')
    return struct.pack('>IIQQIII',size,flags,len(data) if length is None else length,len(data) if storage is None else storage,field6,field7,parent)+units.ljust(512,b'\0')+struct.pack('>Q',timestamp)
def archive(entries,*,layout=1,version=0,header_bytes=20):
    if layout:
        at=header_bytes+556*len(entries);records=[];payload=[]
        for name,data,options in entries:
            options=dict(options);options.setdefault('storage',at);records.append(record(name,data,**options));payload.append(data);at+=len(data)
        body=b''.join(records+payload)
    else:body=b''.join(record(name,data,**options)+data for name,data,options in entries)
    return b'GNFA'+struct.pack('>4I',header_bytes,version,layout,len(entries))+b'\x91'*max(0,header_bytes-20)+body
def fixture(name,raw,ops=(),*,maximum=-1,fail=-1,read_ok=1,readonly=0,clone=0,clone_ok=1,force_shared=0,delegate=0,file_bytes=None):
    n=len(raw) if file_bytes is None else file_bytes
    h=[len(raw),0,n&0xffffffff,n>>32,readonly,maximum,fail,read_ok,11,17,clone,clone_ok,force_shared,delegate,91,92,93,len(ops),0,0,0,0,0,0]
    return dict(name=name,raw=raw,h=h,ops=list(ops))
def fixtures(builtin):
    rng=random.Random(0xe1a011)
    base=archive([('root',b'',dict(length=0x8000000000000001)),('file.wav',bytes(range(64)),dict(parent=1,field6=0x11223344,field7=0xaabbccdd)),('Info.plist',b'<plist/>',dict(parent=1))])
    for n in range(20):yield fixture(f'header-short-{n}',base[:n])
    for magic in [b'GNFA',b'GNF0',b'\0\0\0\0',b'AFNG']:
        for size,version,layout,count in itertools.product([0,19,20,24],[0,1,0xffffffff],[0,1,7],[0,1]):
            raw=magic+struct.pack('>4I',size,version,layout,count)+b'\0'*max(0,size-20)+(record('',length=0,storage=0) if count else b'')
            yield fixture(f'header-{magic.hex()}-size{size}-version{version}-layout{layout}-count{count}',raw)
    for layout in [0,1,0x80000000]:
        for readonly in [0,1]:
            for names in [[''],['root','sample.wav'],['éclair','\U0001f3b9','a'*255],['\ud800x','\udfff','東京']]:
                entries=[(name,rng.randbytes(i+3),dict(flags=0x10203040+i,field6=0xaabbcc00+i,field7=0x77889900+i,timestamp=0x123456789abcdef0+i,parent=max(0,i))) for i,name in enumerate(names)]
                raw=archive(entries,layout=layout,version=0xfedcba98,header_bytes=24)
                yield fixture(f'entries-layout{layout:x}-readonly{readonly}-names{[n.encode("unicode_escape").decode() for n in names]}',raw,readonly=readonly)
    for fail in [0,1,2,3,4]:yield fixture(f'header-read-failure-{fail}',base,fail=fail)
    for maximum in [0,1,19,20,21,555,556]:yield fixture(f'header-short-read-limit-{maximum}',base,maximum=maximum)
    for cut in [20,21,575,576,577,1131,1132,1687]:yield fixture(f'directory-cut-{cut}',base[:cut])
    for file_bytes in [0,19,20,575,576,577,1131,1132,0x100000000]:yield fixture(f'directory-declared-filebytes-{file_bytes}',base,file_bytes=file_bytes)
    for layout in [0,1]:
        for size,storage in itertools.product([0,1,555,556,557,0xffffffff],[0,1,17,0x100000000,0xffffffffffffffff]):
            raw=b'GNFA'+struct.pack('>4I',20,0,layout,2)+record('first',b'',size=size,storage=storage)+record('second',b'',storage=0)
            # Positions may point into a record: original reads it and derives
            # counts/names. Keep these arithmetic cases to a single next read
            # failure to avoid interpreting arbitrary unterminated UTF16.
            yield fixture(f'directory-step-layout{layout}-size{size}-storage{storage:x}',raw,fail=2)
    for shared,clone,force in [(1,0,0),(1,1,1),(0,1,0)]:
        for first in [-1,0,1,63,64,65,0x7fffffff]:
            for count in [0,1,17,64,65]:
                operations=[op(9,2),op(1),op(3,first),op(2,count),op(2,3),op(4),op(2,1)]
                yield fixture(f'member-shared{shared}-first{first}-count{count}',base,operations,clone=clone,force_shared=force)
    for maximum,ok in itertools.product([-4,-2,-1,0,1,7],[0,1]):
        for shared in [False,True]:
            operations=[op(9,2),op(10,1,shared),op(11,0),op(8,maximum,ok),op(2,17),op(2,7)]
            yield fixture(f'member-result-limit{maximum}-ok{ok}-shared{shared}',base,operations)
    for length in [0,1,0x80000000,0x100000003,0x7fffffffffffffff,0x8000000000000001,0xffffffffffffffff]:
        raw=archive([('edge',b'abcdef',dict(length=length,field6=0x11223344,field7=0xaabbccdd))])
        operations=[op(5,0),op(6,0),op(5,1),op(6,1),op(10,1,1),op(11,-2,0),op(2,1),op(11,-1,-1),op(2,3),op(4)]
        if length not in [0x80000000,0x7fffffffffffffff]:operations+=[op(7,1)]
        yield fixture(f'length-bits-{length:x}',raw,operations)
    for delegate in [0,1,2]:
        for maximum,ok in itertools.product([-1,0,1,17,64],[0,1]):
            operations=[op(5,2),op(6,2),op(8,maximum,ok),op(7,2)]
            yield fixture(f'data-delegate{delegate}-limit{maximum}-ok{ok}',base,operations,delegate=delegate)
    for closed,unresolved in itertools.product([0,1],[0,1]):
        operations=[op(9,2,unresolved),op(12,not closed),op(5,2),op(6,2),op(10,1,1),op(2,7),op(3,3),op(4)]
        yield fixture(f'path-closed{closed}-unresolved{unresolved}',base,operations)
    for clone_ok in [0,1]:
        yield fixture(f'bind-clone-ok{clone_ok}',base,[op(9,2),op(1)],clone=1,clone_ok=clone_ok)
    yield fixture('base-memory-fallback',base,[op(10,0),op(3,-1),op(3,3),op(2,17),op(4),op(2,1)])
    original=builtin.read_bytes();assert hashlib.sha256(original).hexdigest()==ARCHIVE_SHA
    for clone in [0,1]:
        for index in [1,2,3]:
            operations=[op(5,index),op(6,index),op(7,index)]
            if index!=1:operations+=[op(9,index),op(1),op(3,0),op(2,707036 if index==2 else 96),op(2,1),op(4)]
            yield fixture(f'builtin-index{index}-clone{clone}',original,operations,clone=clone)

class ArchiveOracle(OriginalCacheOracle):
    def __init__(self,binary):
        super().__init__(binary);self.uc.mem_map(0x800000,0x3000000)
        bindings={0x500b00:self.seek,0x500b10:self.read,0x500b20:self.position,0x500b30:self.retain,
            0x500b40:self.can_clone,0x500b50:self.path,0x500b60:self.open_path,
            0x500b70:lambda *x:self.mutex(7),0x500b80:lambda *x:self.mutex(8),0xdf8d2:self.resolve,
            0xaecc:self.allocate_entries,0x332e2:lambda *x:self.finish(),0x2dfa6:self.identity,0x3788a:self.create_name,
            0x33b90:self.string,0xbf34:self.raise_error,0xbfd6:self.raise_error,0xa930:lambda *x:self.finish(0),
            0x28308:self.allocate_data,0x27b4e:self.data_lock,0x27abc:self.data_bytes,0x27bec:self.data_unlock,
            0x500b90:self.decode,0x17f918:self.base_read}
        for at,fn in bindings.items():self.uc.hook_add(UC_HOOK_CODE,fn,begin=at,end=at)
        self.import_handlers['__Znwm']=self.new
        for off,at in [(0x40,0x500b30),(0x1ac,0x500b10),(0x1b8,0x500b20),(0x1c0,0x500b00),(0x1c4,0x500b40),(0x1a8,0x500b50)]:self.put(IOVT+off,at)
        self.put(PATHVT+0x248,0x500b60);self.put(CLONEPATH,PATHVT);self.put(MUTEX,MUTEXVT);self.put(MUTEXVT+0x1a4,0x500b70);self.put(MUTEXVT+0x1ac,0x500b80);self.put(DELEGATE,DELEGATEVT);self.put(DELEGATEVT+4,0x500b90)
    def event(self,*v):self.trace.append(list(v)+[0]*(6-len(v)))
    def identity(self,*unused):p,=self.arguments(1);self.finish(p)
    def new(self):n,=self.arguments(1);assert n==32;self.names+=1;self.finish(NAMES+self.names*0x100)
    def create_name(self,*unused):p,units,n=self.arguments(3);self.event(6,n);self.finish()
    def allocate_entries(self,*unused):n,=self.arguments(1);count=self.word(CORE+0x10);assert 0<=count<=128 and n==count*576;self.capacity=count;self.event(5,count);self.uc.mem_write(DESC,b'\xa5'*n);self.finish(DESC)
    def stream_index(self,p):index=(p-IOS)//0x100;assert 0<=index<2;return index
    def seek(self,*unused):p,at=self.arguments(2);i=self.stream_index(p);self.positions[i]=signed(at);self.event(1,i,signed(at));self.finish()
    def read_raw(self,i,out,count_at):
        wanted=self.word(count_at);at=self.positions[i];actual=0
        if wanted<0:actual=wanted
        elif self.maximum<-1:actual=self.maximum+1
        elif 0<=at<len(self.raw):actual=min(len(self.raw)-at,wanted);actual=min(actual,self.maximum) if self.maximum>=0 else actual
        if actual>0:self.uc.mem_write(out,self.raw[at:at+actual])
        ok=int(bool(self.read_ok) and self.reads!=self.fail);self.event(2,i,at,wanted,actual,ok);self.reads+=1;self.positions[i]=signed(at+actual);self.put(count_at,actual);return ok
    def read(self,*unused):p,out,count=self.arguments(3);self.finish(self.read_raw(self.stream_index(p),out,count))
    def position(self,*unused):p,=self.arguments(1);i=self.stream_index(p);self.event(3,i,self.positions[i]);self.finish(self.positions[i])
    def retain(self,*unused):p,=self.arguments(1);self.event(4,self.stream_index(p));self.finish(p)
    def can_clone(self,*unused):p,=self.arguments(1);i=self.stream_index(p);self.event(14,i,self.h[10]);self.finish(self.h[10])
    def path(self,*unused):p,=self.arguments(1);self.event(15,self.stream_index(p));self.finish(CLONEPATH)
    def open_path(self,*unused):self.event(16,0,self.h[11]);self.finish(IOS+0x100 if self.h[11] else 0)
    def mutex(self,k):self.event(k);self.finish()
    def resolve(self,*unused):self.event(10,self.word(PATH+0x14),int(bool(self.word(PATH+0x18))));self.finish()
    def string(self,*unused):p,=self.arguments(1);s=bytes(self.uc.mem_read(p,256)).split(b'\0')[0];self.error_strings[0x570000]=s;self.finish(0x570000)
    def raise_error(self,*unused):
        p,=self.arguments(1);name=self.error_strings[p];codes={b'GNFileArchiveFormatNotSupportedException':1,b'GNFileArchiveIsCorruptedException':2,b'GNFileArchiveCannotReadArchiveException':3,b'GNAssertionException':4}
        if name not in codes:raise ValueError('Unknown exception '+repr(name))
        self.error=codes[name];self.uc.emu_stop()
    def allocate_data(self,*unused):
        n,=self.arguments(1);n=signed(n);assert 0<=n<=1048576;index=len(self.data);p=DATAOBJS+index*0x100;at=self.heap;self.heap+=n+16;self.uc.mem_write(at,b'\xa5'*n);self.data.append(dict(p=p,at=at,size=n,locked=False));self.event(11,n,index+1);self.finish(p)
    def d(self,p):return self.data[(p-DATAOBJS)//0x100]
    def data_lock(self,*unused):p,=self.arguments(1);self.d(p)['locked']=True;self.event(12,(p-DATAOBJS)//0x100+1);self.finish()
    def data_bytes(self,*unused):p,=self.arguments(1);self.finish(self.d(p)['at'])
    def data_unlock(self,*unused):p,=self.arguments(1);self.d(p)['locked']=False;self.event(13,(p-DATAOBJS)//0x100+1);self.finish()
    def decode(self,*unused):self_,d,name,f7,f6=self.arguments(5);assert self_==DELEGATE;self.event(17,(d-DATAOBJS)//0x100+1,(name-NAMES)//0x100 if name else 0,f7,f6,self.h[13]);self.finish(0 if self.h[13]==2 else d)
    def base_read(self,*unused):p,out,count=self.arguments(3);assert p==MEMBER;self.positions[2]=self.word(MEMBER+0x1c);ok=self.read_raw(2,out,count);self.put(MEMBER+0x1c,self.positions[2]);self.finish(ok)
    def call_reg(self,addr,args=(),eax=0,edx=0):
        self.error=0;self.uc.mem_write(STACK,struct.pack('<I',RETURN)+pack(args));self.uc.reg_write(UC_X86_REG_ESP,STACK);self.uc.reg_write(UC_X86_REG_EAX,eax);self.uc.reg_write(UC_X86_REG_EDX,edx);self.uc.reg_write(UC_X86_REG_EFLAGS,2);self.uc.reg_write(UC_X86_REG_MXCSR,0x1f80);self.uc.emu_start(addr,RETURN,count=3000000)
        if not self.error and self.uc.reg_read(UC_X86_REG_EIP)!=RETURN:raise ValueError(f'Original {addr:x} did not finish')
        return self.uc.reg_read(UC_X86_REG_EAX)
    def execute(self,c):
        self.h=h=c['h'];self.raw=c['raw'];self.trace=[];self.capacity=self.names=self.reads=0;self.maximum=h[5];self.fail=h[6];self.read_ok=h[7];self.positions=[h[8],h[9],h[8]];self.error_strings={};self.data=[];self.heap=0x1000000
        for at,size in [(CORE,0x80),(PATH,0x80),(MEMBER,0x80),(OWNER,0x80)]:self.uc.mem_write(at,bytes(size))
        self.put(CORE+4,h[14],h[15],h[16]);self.put(CORE+0x18,h[2],h[3],MUTEX,IOS,OWNER);self.uc.mem_write(CORE+0x2c,bytes([h[4]]));self.put(OWNER+0x10,DELEGATE if h[13] else 0);self.uc.mem_write(OWNER+0x18,bytes([h[12]]))
        self.put(PATH+0x10,CORE,1,0);self.put(MEMBER+0x28,PATH,0,h[19],h[20]);self.uc.mem_write(MEMBER+0x38,bytes([h[21]]));self.put(MEMBER+0xc,0x571000);self.put(MEMBER+0x1c,h[8],len(self.raw))
        for i in range(2):self.put(IOS+i*0x100,IOVT)
        self.call_reg(0xe0a4c,eax=CORE);parsed=self.error
        answer=pack([parsed,*[self.word(CORE+off) for off in [4,8,12,16]],int(bool(self.word(CORE+20))),self.uc.mem_read(CORE+0x2c,1)[0],self.capacity])+bytes(self.uc.mem_read(CORE+0x18,8))
        for i in range(self.capacity):
            e=bytearray(self.uc.mem_read(DESC+i*576,576));name=struct.unpack_from('<I',e,572)[0];struct.pack_into('<I',e,572,(name-NAMES)//0x100 if name else 0);answer+=e
        answer+=pack([0 if parsed else len(c['ops'])])
        for kind,a,b,d in c['ops']:
            if parsed:continue
            self.error=0;value=count=0;payload=b''
            if kind==1:self.call_reg(0xe3e38,(MEMBER,IOS))
            elif kind==2:
                count=a;capacity=max(a,len(self.raw))+32;self.uc.mem_write(OUT,b'\xa5'*capacity);self.put(OUT+0x110000,count);value=self.call_reg(0xe4172,(MEMBER,OUT+16,OUT+0x110000));value=(value&255) if not self.error else 0;count=self.word(OUT+0x110000);payload=bytes(self.uc.mem_read(OUT,capacity))
            elif kind==3:self.call_reg(0xe440a,(MEMBER,a))
            elif kind==4:value=self.call_reg(0xe455a,(MEMBER,));value=value if not self.error else 0
            elif kind in [5,6]:self.put(PATH+0x14,a);value=self.call_reg(0xe05a2 if kind==5 else 0xe09c0,(PATH,));value=value&255 if kind==5 else value
            elif kind==7:
                result=self.call_reg(0xe063c,eax=CORE,edx=a)
                if not self.error and result:value=1;obj=self.d(result);payload=bytes(self.uc.mem_read(obj['at'],obj['size']))
            elif kind==8:self.maximum=a;self.read_ok=b;self.fail=-1 if d<0 else self.reads+d
            elif kind==9:self.put(PATH+0x14,a,1 if b else 0)
            elif kind==10:self.put(MEMBER+0x2c,IOS+(a-1)*0x100 if a else 0);self.uc.mem_write(MEMBER+0x38,bytes([bool(b)]))
            elif kind==11:self.put(MEMBER+0x30,a,b)
            elif kind==12:self.put(CORE+0x24,IOS if a else 0)
            else:raise ValueError('Unknown op')
            self.positions[2]=self.word(MEMBER+0x1c);backing=self.word(MEMBER+0x2c);backing=(backing-IOS)//0x100+1 if backing else 0
            answer+=pack([self.error,value,count,self.word(PATH+0x14),int(bool(self.word(PATH+0x18))),backing,self.uc.mem_read(MEMBER+0x38,1)[0],self.word(MEMBER+0x30),self.word(MEMBER+0x34),*self.positions,len(payload)])+payload
        answer+=pack([len(self.data)])
        for obj in self.data:answer+=pack([obj['size'],int(obj['locked'])])+bytes(self.uc.mem_read(obj['at'],obj['size']))
        return answer+pack([len(self.trace)])+b''.join(pack(row) for row in self.trace)

def compare(binary,runner,prefix,platform,builtin):
    oracle=ArchiveOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=0
    for c in fixtures(builtin):
        try:expected=oracle.execute(c)
        except Exception as e:raise RuntimeError(f'Original archive failed at {c["name"]}: {e}') from e
        data=pack(c['h'])+c['raw']+b''.join(pack(op) for op in c['ops']);actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA011-native');folder.mkdir(exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]:(folder/f'failing-archive-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)))
            raise ValueError(f'Archive mismatch {c["name"]} exit={actual.returncode} byte={at} expected={expected[at:at+24].hex()} native={actual.stdout[at:at+24].hex()}')
        total+=len(expected);cases.append(dict(name=c['name'],status=struct.unpack_from('<i',expected)[0],trace_events=len(oracle.trace),sha256=hashlib.sha256(expected).hexdigest(),all_bytes_match=True))
    probe.close();return dict(checkpoint='ELA011',original_i386_sha256=SHA,compiled_platform=platform,scope='Original GNFA directory parser, file predicates, stream binding/range reads/seeks/end and materialized data',fixture_count=len(cases),compared_bytes=total,all_cases_match_bit_for_bit=True,automatic_fixture_retries=0,archive_metadata_substituted=False,member_file_bytes_substituted=False,builtin_archive_sha256=ARCHIVE_SHA,boundaries_adapted=['GN allocation and UTF16 object construction','raw byte stream read/seek/position/clone/open/retain','GN exception to status','mutex primitives','path resolution callback','GN data allocation/lock/bytes/unlock','optional synthetic pass-through/null delegate; real bank delegate not ported','GNFile memory base fallback read'],user_bank_compatibility_verified=False,bank_authorization_modified=False,real_bank_delegate_ported=False,actual_macos_execution=False,thread_concurrency_validated=False,full_engine_built=False,audio_unit_validated=False,cases=cases)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--builtin',type=Path,default=BUILTIN);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform,a.builtin);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k] for k in ['fixture_count','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']},indent=2))
