#!/usr/bin/env python3
"""Original ETSoundbank metadata/cache/ownership control versus native C++.

GN primitives, property-list parsing, archive opening and OS path services are
explicit bindings here. Real authorization and protected-data code is not
substituted or exercised by these metadata tests.
"""
import argparse,hashlib,itertools,json,struct,math
from pathlib import Path
from original_cache_oracle import OriginalCacheOracle,STACK,RETURN
from legacy_image import SHA
from native_probe import NativeProbe
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_EBP,UC_X86_REG_EBX,UC_X86_REG_ESI,UC_X86_REG_EDI
BANK,NODES,VT,KEYS,CSTR,APP,RES=0x540000,0x550000,0x560000,0x570000,0x580000,0x590000,0x590100
KEY_NAMES=[b'/Info.plist',b'identifier',b'title',b'serial',b'color',b'gracePeriode']
SETTERS={0:0x1a9cf8,1:0x1a9b78,2:0x1a9d80,3:0x1a9dc4,4:0x1a9bda,5:0x1a9cb4,7:0x1a9d3c}
def pack(v):return struct.pack('<'+'I'*len(v),*(x&0xffffffff for x in v))
def op(k,a=0,b=0):return [k,a,b]
def fixture(name,ops):
    h=[0]*32;h[:8]=[4,2,5,6,2,7,0,8];h[8:26]=[12,41,1,42,1,2,4,43,1,44,1,4,5,8,31,9,0,2]
    h[28]=len(ops);return dict(name=name,h=h,numbers=[123.5,987.25,123.456789],ops=ops)
def fixtures():
    for field,(old,new),mutable,cached in itertools.product(SETTERS,itertools.product(range(4),repeat=2),[0,0xfffffffe],[0,101]):
        c=fixture(f'set-field{field}-old{old}-new{new}-mutable{mutable:x}-archive{cached}',[op(1,field,new),op(1,field,new)]);c['h'][field]=old;c['h'][25]=mutable;c['h'][6]=cached;yield c
    for old,newpath,result,cached in itertools.product(range(4),[0,41,42],[0,1,2],[0,101]):
        c=fixture(f'set-file-old{old}-path{newpath}-result{result}-archive{cached}',[op(2,newpath),op(2,newpath)]);c['h'][4]=old;c['h'][13]=result;c['h'][6]=cached;yield c
    for source,length,system,yes,resource,resource_yes in itertools.product([0,2],[-1,0,1,12],[0,41],[0,1],[0,42],[0,1]):
        c=fixture(f'source-{source}-len{length}-system{system}-{yes}-resource{resource}-{resource_yes}',[op(3)]);c['h'][4]=source;c['h'][8:13]=[length,system,yes,resource,resource_yes];yield c
    sources=[('no-source',0,12,41,1,42,1),('empty',2,0,41,1,42,1),('null-system',2,12,0,1,42,1),('system',2,12,41,1,42,1),('resource',2,12,41,0,42,1),('null-resource',2,12,41,0,0,1),('missing-resource',2,12,41,0,42,0)]
    metadata=[('null-member',0,1,44,31,9),('missing-member',43,0,44,31,9),('invalid-plist',43,1,0,31,9),('empty-dict',43,1,44,0,9),('all',43,1,44,31,9),('identifier',43,1,44,1,9),('title',43,1,44,2,9),('grace',43,1,44,16,9),('null-description',43,1,44,31,0)]
    for source,(meta,member,exists,parsed,mask,desc),status,cached in itertools.product(sources,metadata,[0,1,2,3,4,5],[0,101]):
        label,src,n,sy,syes,re,ryes=source;c=fixture(f'archive-{label}-{meta}-error{status}-cached{cached}',[op(4),op(4)]);h=c['h'];h[4]=src;h[6]=cached;h[8:13]=[n,sy,syes,re,ryes];h[15:18]=[member,exists,parsed];h[18:23]=[v if mask&(1<<i) else 0 for i,v in enumerate([1,4,5,8,31])];h[23:25]=[desc,status];yield c
    for mask,old_title,mutable in itertools.product(range(32),[0,4],[0,2]):
        c=fixture(f'metadata-mask{mask}-oldtitle{old_title}-mutable{mutable}',[op(4)]);c['h'][0]=old_title;c['h'][18:23]=[v if mask&(1<<i) else 0 for i,v in enumerate([1,4,5,8,31])];c['h'][25]=mutable;yield c
    for mask,alias in itertools.product(range(256),[0,1]):
        c=fixture(f'clear-mask{mask}-alias{alias}',[op(5),op(5)]);c['h'][:8]=[(1 if alias else i+1) if mask&(1<<i) else 0 for i in range(8)];yield c
    for value in [0.0,-0.0,0.1,-0.1,1e-30,1e30,16777217.,math.pi,math.inf,-math.inf]:
        c=fixture(f'grace-float-{value}',[op(4),op(1,4,2),op(6,22,0),op(4)]);c['numbers'][2]=value;yield c
    sequences=[('replace-and-reload',[op(4),op(1,4,3),op(4),op(4)]),('file-change',[op(4),op(2,41),op(4)]),('open-retry',[op(6,24,2),op(4),op(6,24,0),op(4)]),('title-fallback',[op(6,19,0),op(6,14,0),op(4)]),('identifier-fallback',[op(6,18,0),op(6,13,0),op(4)]),('clear-after-load',[op(4),op(5),op(4)]),('cached-source-missing',[op(4),op(6,9,0),op(4)]),('cached-source-empty',[op(4),op(6,8,0),op(4)])]
    for name,ops in sequences:yield fixture('sequence-'+name,ops)

class SoundbankOracle(OriginalCacheOracle):
    def __init__(self,binary):
        super().__init__(binary)
        hooks={0x500f00:lambda *x:self.reference(1),0x500f10:lambda *x:self.reference(2),0x500f20:self.mutable,0x3b448:self.copy,0x349f4:self.length,0x9af5e:self.system_path,0x500f30:self.exists,0x3a99a:self.component,0xcfca:lambda *x:self.finish(APP),0x500f40:lambda *x:self.finish(RES),0x500f50:self.resource,0x500f60:self.posix,0x500f70:self.name,0xdf2aa:self.construct,0x2dfa6:self.initialize,0x500f80:self.autorelease,0xe13de:self.open_archive,0xe1a68:self.member,0x6739a:self.parse,0x500f90:self.description,0x64626:self.get,0x34496:self.number,0x33b90:self.string,0x34962:self.string_bytes,0xbea2:self.push,0xbec0:self.pop}
        for at,fn in hooks.items():self.uc.hook_add(UC_HOOK_CODE,fn,begin=at,end=at)
        self.import_handlers.update(__Znwm=self.new,_setjmp=self.setjmp)
        for off,addr in [(0x40,0x500f00),(0x44,0x500f10),(0x48,0x500f80),(0x80,0x500f20),(0x1d0,0x500f30),(0x1bc,0x500f60),(0x1c8,0x500f70),(0xc,0x500f90)]:self.put(VT+off,addr)
        self.put(APP,VT+0x1000);self.put(VT+0x1000+0x2c8,0x500f40);self.put(RES,VT+0x2000);self.put(VT+0x2000+0x210,0x500f50)
        # Return the numeric primitive in the original x87 float ABI. The hook
        # observes but does not replace this FLD/RET machine code.
        self.uc.mem_write(0x34496,bytes.fromhex('8b442404d94020c3'))
    def event(self,*v):self.trace.append(list(v)+[0]*(6-len(v)))
    def ptr(self,n):return NODES+n*0x100 if n else 0
    def token(self,p):
        if not p:return 0
        assert NODES<=p<NODES+0x8000 and (p-NODES)%0x100==0,f'Unknown object {p:x}'
        return (p-NODES)//0x100
    def cstring(self,p):return bytes(self.uc.mem_read(p,256)).split(b'\0',1)[0]
    def reference(self,op):p,=self.arguments(1);n=self.token(p);self.event(1,op,n);self.refs[n]+=1 if op==1 else -1;self.finish(p)
    def mutable(self,*unused):p,=self.arguments(1);n=self.token(p);yes=n<32 and bool(self.h[25]&(1<<n));self.event(2,n,int(yes));self.finish(int(yes))
    def copy(self,*unused):p,=self.arguments(1);n=self.token(p);self.event(3,n,n+64);self.finish(self.ptr(n+64))
    def length(self,*unused):p,=self.arguments(1);self.event(4,self.token(p),self.h[8]);self.finish(self.h[8])
    def system_path(self,*unused):p,=self.arguments(1);self.event(5,self.token(p),self.h[9]);self.finish(self.ptr(self.h[9]))
    def exists(self,*unused):p,=self.arguments(1);n=self.token(p);yes=int(bool(self.h[10 if n==41 else 12 if n==42 else 16]));self.event(6,n,yes);self.finish(yes)
    def component(self,*unused):p,=self.arguments(1);self.event(7,self.token(p),50);self.finish(self.ptr(50))
    def resource(self,*unused):p,part=self.arguments(2);assert p==RES;self.event(8,self.token(part),self.h[11]);self.finish(self.ptr(self.h[11]))
    def posix(self,*unused):p,=self.arguments(1);self.event(9,self.token(p),self.h[13]);self.finish(self.ptr(self.h[13]))
    def name(self,*unused):p,=self.arguments(1);self.event(10,self.token(p),self.h[14]);self.finish(self.ptr(self.h[14]))
    def new(self):size,=self.arguments(1);assert size==28;self.constructs+=1;n=100+self.constructs;self.event(11,n);self.finish(self.ptr(n))
    def construct(self,*unused):p,=self.arguments(1);self.event(12,self.token(p));self.finish(p)
    def initialize(self,*unused):p,=self.arguments(1);self.event(13,self.token(p));self.finish(p)
    def autorelease(self,*unused):p,=self.arguments(1);self.event(14,self.token(p));self.finish(p)
    def open_archive(self,*unused):
        a,p=self.arguments(2);self.event(15,self.token(a),self.token(p),self.h[24])
        if not self.h[24]:self.finish();return
        frame=self.frames.pop();sp,ret,registers=self.jumps[frame]
        for r,v in registers.items():self.uc.reg_write(r,v)
        self.uc.reg_write(UC_X86_REG_ESP,sp+4);self.uc.reg_write(UC_X86_REG_EIP,ret);self.uc.reg_write(UC_X86_REG_EAX,1)
    def push(self,*unused):p,=self.arguments(1);self.frames.append(p);self.finish()
    def pop(self,*unused):p,=self.arguments(1);assert self.frames.pop()==p;self.finish()
    def setjmp(self):
        p,=self.arguments(1);sp=self.uc.reg_read(UC_X86_REG_ESP);registers=[UC_X86_REG_EBP,UC_X86_REG_EBX,UC_X86_REG_ESI,UC_X86_REG_EDI];self.jumps[p]=(sp,self.word(sp)&0xffffffff,{r:self.uc.reg_read(r) for r in registers});self.finish()
    def member(self,*unused):a,p=self.arguments(2);assert self.keys[p]==b'/Info.plist';self.event(16,self.token(a),self.h[15]);self.finish(self.ptr(self.h[15]))
    def parse(self,*unused):p,=self.arguments(1);self.event(17,self.token(p),self.h[17]);self.finish(self.ptr(self.h[17]))
    def description(self,*unused):p,=self.arguments(1);self.event(18,self.token(p),self.h[23]);self.finish(self.ptr(self.h[23]))
    def get(self,*unused):p,key=self.arguments(2);i=KEY_NAMES.index(self.keys[key]);assert i>0;value=self.h[17+i];self.event(19,self.token(p),i,value);self.finish(self.ptr(value))
    def number(self,*unused):p,=self.arguments(1);self.event(20,self.token(p),struct.unpack('<I',self.float_bytes)[0]);self.uc.mem_write(p+0x20,self.float_bytes)
    def string(self,*unused):p,=self.arguments(1);s=self.cstring(p);i=KEY_NAMES.index(s);p=KEYS+i*0x100;self.keys[p]=s;self.finish(p)
    def string_bytes(self,*unused):p,=self.arguments(1);self.finish(CSTR+self.token(p)*0x100)
    def diagnostic(self,*unused):
        text_at,value=self.arguments(2);text=self.cstring(text_at);code={b'Info.plist not found in %s':1,b'Info.plist cannot be parsed from %s':2,b'Loaded archive %s':3}[text];n=(value-CSTR)//0x100 if CSTR<=value<CSTR+0x8000 else 0;self.event(21,code,n);self.finish()
    def execute(self,c):
        self.h=h=list(c['h']);self.float_bytes=struct.pack('<f',c['numbers'][2]);self.trace=[];self.refs=[0]*128;self.constructs=0;self.frames=[];self.jumps={};self.keys={};self.uc.mem_write(BANK,bytes(0x100));self.put(BANK+0xc,*(self.ptr(n) for n in h[:8]));self.uc.mem_write(BANK+0x2c,struct.pack('<2d',*c['numbers'][:2]));self.error=0
        for n in range(1,128):self.put(self.ptr(n),VT);self.uc.mem_write(CSTR+n*0x100,b'node\0')
        answer=b''
        for k,a,b in c['ops']:
            result=0
            if k==1:self.call(SETTERS[a],BANK,self.ptr(b))
            elif k==2:self.call(0x1aa964,BANK,self.ptr(a))
            elif k==3:result=self.call(0x1a9c28,BANK)
            elif k==4:result=self.call(0x1aa9c6,BANK)
            elif k==5:self.call(0x1a99d2,BANK)
            elif k==6:self.h[a]=b
            elif k==7:self.float_bytes=pack([a])
            else:raise ValueError('Unknown operation')
            assert not self.frames
            answer+=pack([self.token(result) if k in [3,4] else 0,*[self.token(self.word(BANK+0xc+i*4)) for i in range(8)],self.constructs])+bytes(self.uc.mem_read(BANK+0x2c,16))
        return answer+pack(self.refs)+pack([len(self.trace)])+b''.join(pack(row) for row in self.trace)

def compare(binary,runner,prefix,platform):
    oracle=SoundbankOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=0
    for c in fixtures():
        try:expected=oracle.execute(c)
        except Exception as e:raise RuntimeError(f'Original soundbank failed {c["name"]}: {e}') from e
        data=pack(c['h'])+struct.pack('<2df',*c['numbers'])+b''.join(pack(o) for o in c['ops']);actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA013-native');folder.mkdir(exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]:(folder/f'failing-bank-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)));raise ValueError(f'Soundbank mismatch {c["name"]}: exit={actual.returncode} byte={at} expected={expected[at:at+24].hex()} native={actual.stdout[at:at+24].hex()}')
        total+=len(expected);cases.append(dict(name=c['name'],trace_events=len(oracle.trace),sha256=hashlib.sha256(expected).hexdigest(),all_bytes_match=True))
    probe.close();return dict(checkpoint='ELA013',scope='ETSoundbank source resolution, lazy metadata/archive state and ownership',original_i386_sha256=SHA,compiled_platform=platform,fixture_count=len(cases),compared_bytes=total,all_cases_match_bit_for_bit=True,automatic_fixture_retries=0,original_bank_routine_bodies_executed=True,actual_property_list_parser_executed=False,actual_archive_open_executed_in_this_corpus=False,boundaries_adapted=['GN object reference/mutability/copy/string primitives','GN property-list/dictionary primitives','GN archive construction/open and metadata path','OS system/resource paths','GN exception frames/setjmp'],actual_GN_ownership_exception_runtime_validated=False,actual_macos_execution=False,real_bank_authorization_modified=False,real_bank_authorization_validated=False,protected_bank_decoder_ported=False,complete_engine_built=False,audio_unit_validated=False,cases=cases)
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k] for k in ['fixture_count','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']},indent=2))
