"""Original archive lookup/factory with real GNString split/hash/comparison.

Only object construction/storage, array primitives, allocation, references and
byte I/O are bindings. Original path matching and string algorithms execute.
"""
import struct
from compare_original_file_archive import (ArchiveOracle,fixture,pack,signed,CORE,PATH,MEMBER,OWNER,IOS,IOVT,NAMES,DATAOBJS,DESC,OUT)
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EAX

ROOT,SLASH,ARRAYVT,DATAVT,FILES=0xd00000,0xd00100,0xd10000,0xd50000,0xb00000
class ArchiveNameOracle(ArchiveOracle):
    def __init__(self,binary):
        super().__init__(binary)
        hooks={0x2dc66:lambda *x:self.finish(),0x29d44:self.array_construct,0x2bb40:self.array_append,
            0x29ddc:self.array_count,0x2a364:self.array_at,0x390f6:self.assign_string,0x3948e:self.assign_range,
            0xb122:lambda *x:self.finish(),0x2e0bc:self.autorelease,0x2dfe2:self.retain_object,0x2dffc:self.release_object,
            0x349f4:self.observe_length,0x39a08:self.observe_split,0x34e24:self.observe_equal,0x17e5fa:self.construct_file,
            0x278d6:self.data_length,0x500c00:lambda *x:self.data_object(1),0x500c10:lambda *x:self.data_object(2)}
        for at,fn in hooks.items():self.uc.hook_add(UC_HOOK_CODE,fn,begin=at,end=at)
        # Replace the old GNFile fallback binding with its actual instructions.
        # The existing hook calls this override, which deliberately does not
        # finish the call, letting 0x17f918 execute normally.
        self.put(ARRAYVT+0x48,0x2e0bc);self.put(DATAVT+0x40,0x500c00,0x500c10);self.put(PATH,0x37b668)
        self.put(0x3d4048,0xd80000);self.uc.mem_write(0x3d404c,b'\0')
        self.import_handlers['_strstr']=self.strstr
    def allocate_bytes(self,b):
        p=self.string_heap;self.string_heap+=(len(b)+15)//16*16+16;assert self.string_heap<0x2600000
        self.uc.mem_write(p,b);return p
    def string_node(self,p,raw=None,units=None):
        self.uc.mem_write(p,bytes(32));self.put(p,0x36ec68);self.uc.mem_write(p+0x18,b'\1');self.put(p+0x1c,-1)
        if units is not None:self.put(p+0x10,self.allocate_bytes(units+b'\0\0'),len(units)//2)
        else:self.put(p+0xc,self.allocate_bytes((raw or b'')+b'\0'));self.put(p+0x14,-1)
    def new(self):
        size,=self.arguments(1)
        if size==60:
            p=FILES+len(self.files)*0x100;self.files.append(p);self.event(17,len(self.files));self.finish(p)
        else:
            assert size==32;self.names+=1;p=NAMES+self.names*0x100;self.string_node(p,raw=b'');self.finish(p)
    def initialize_file(self,p):self.uc.mem_write(p,bytes(60));self.put(p,0x38fca8)
    def construct_file(self,*unused):p,=self.arguments(1);self.initialize_file(p);self.finish()
    def identity(self,*unused):
        p,=self.arguments(1)
        if p in self.files:self.event(18,self.files.index(p)+1)
        self.finish(p)
    def autorelease(self,*unused):
        p,=self.arguments(1)
        if p in self.files:self.event(19,self.files.index(p)+1)
        self.finish(p)
    def retain_object(self,*unused):
        p,=self.arguments(1)
        if p==PATH:self.path_retains+=1;self.event(20)
        self.finish(p)
    def release_object(self,*unused):
        p,=self.arguments(1)
        if p==ROOT:self.path_releases+=1;self.event(27)
        self.finish()
    def create_name(self,*unused):
        p,units,n=self.arguments(3);self.event(6,n);self.string_node(p,units=bytes(self.uc.mem_read(units,n*2)));self.finish()
    def allocate_entries(self,*unused):
        if self.phase=='parse':super().allocate_entries()
        else:n,=self.arguments(1);self.finish(self.allocate_bytes(bytes(n)))
    def string(self,*unused):
        p,=self.arguments(1);text=bytes(self.uc.mem_read(p,256)).split(b'\0')[0]
        if text==b'/':self.finish(SLASH)
        else:super().string()
    def array_construct(self,*unused):p,=self.arguments(1);self.put(p,ARRAYVT);self.arrays[p]=[];self.active_array=p;self.finish()
    def array_append(self,*unused):p,value=self.arguments(2);self.parts[value]=len(self.arrays[p]);self.arrays[p].append(value);self.finish()
    def array_count(self,*unused):p,=self.arguments(1);n=len(self.arrays[p]);self.event(24,n);self.finish(n)
    def array_at(self,*unused):p,index=self.arguments(2);self.event(25,index);self.finish(self.arrays[p][index])
    def cstring(self,p):
        result=bytearray()
        while True:
            b=bytes(self.uc.mem_read(p,1))[0]
            if not b:return bytes(result)
            result.append(b);p+=1
    def assign_string(self,*unused):p,source=self.arguments(2);self.put(p+0xc,self.allocate_bytes(self.cstring(source)+b'\0'));self.put(p+0x10,0,-1);self.finish()
    def assign_range(self,*unused):p,source,n=self.arguments(3);self.put(p+0xc,self.allocate_bytes(bytes(self.uc.mem_read(source,n))+b'\0'));self.put(p+0x10,0,-1);self.finish()
    def strstr(self):a,b=self.arguments(2);n=self.cstring(a).find(self.cstring(b));self.finish(0 if n<0 else a+n)
    def observe_length(self,*unused):
        p,=self.arguments(1)
        if p==ROOT:self.event(22,self.root_length)
    def observe_split(self,*unused):self.event(23)
    def observe_equal(self,*unused):name,component=self.arguments(2);self.event(26,(name-NAMES)//0x100,self.parts[component])
    def resolve(self,*unused):self.event(10,self.word(PATH+0x14),int(bool(self.word(PATH+0x18))))
    def mutex(self,event):self.depth+=1 if event==7 else -1;self.event(event);self.finish()
    def allocate_data(self,*unused):
        super().allocate_data();p=self.uc.reg_read(UC_X86_REG_EAX);self.put(p,DATAVT);self.refs[p]=1
    def data_lock(self,*unused):
        p,=self.arguments(1)
        if not p:self.event(12,0);self.error=4;self.uc.emu_stop()
        else:super().data_lock()
    def data_object(self,op):p,=self.arguments(1);self.event(21,op,(p-DATAOBJS)//0x100+1);self.refs[p]+=1 if op==1 else -1;self.finish(p)
    def data_length(self,*unused):p,=self.arguments(1);obj=self.d(p);self.event(28,(p-DATAOBJS)//0x100+1,obj['size']);self.finish(obj['size'])
    def data_bytes(self,*unused):p,=self.arguments(1);self.event(29,(p-DATAOBJS)//0x100+1);super().data_bytes()
    def base_read(self,*unused):pass
    def prepare(self,c):
        h=c['h'];self.string_heap=0x2000000;self.phase='parse';self.files=[];self.refs={};self.arrays={};self.parts={};self.depth=self.path_releases=self.path_retains=self.current=0
        super().execute(fixture('named-archive-setup',c['raw'],clone=h[4],clone_ok=h[5],force_shared=h[6],delegate=h[8]));self.phase='lookup';self.root_length=h[1];self.root_units=c['path'];self.string_node(ROOT,units=c['path']);self.string_node(SLASH,raw=b'/');self.uc.mem_write(SLASH+0x18,b'\0');self.put(PATH,0x37b668);self.put(PATH+0x14,h[3],ROOT if h[2] else 0);self.put(CORE+0x24,IOS if h[7] else 0)
        return self.error
    def execute_named(self,c):
        parsed=self.prepare(c);answer=pack([parsed,self.word(CORE+0x10),self.uc.mem_read(CORE+0x2c,1)[0]])
        for k,a,b,d in c['ops']:
            self.error=0;value=count=0;payload=b'';file=self.files[self.current-1] if self.current else 0
            if k==1:self.call_reg(0xdf8d2,(PATH,))
            elif k==2:
                result=self.call_reg(0xe3ff4,(PATH,));self.current=value=self.files.index(result)+1 if result in self.files and not self.error else 0
            elif k==3:self.current=a
            elif k==4:
                count=a;n=max(a,len(c['raw']))+32;self.uc.mem_write(OUT,b'\xa5'*n);self.put(OUT+0x110000,a)
                if file:value=self.call_reg(0xe4172,(file,OUT+16,OUT+0x110000));value=value&255 if not self.error else 0;count=self.word(OUT+0x110000)
                else:self.error=-1
                payload=bytes(self.uc.mem_read(OUT,n))
            elif k in [5,6,7]:
                if file:
                    result=self.call_reg({5:0xe440a,6:0xe455a,7:0xdfab4}[k],(file,a) if k==5 else (file,));value=result if k!=5 and not self.error else 0
                else:self.error=-1
            elif k in [8,9]:value=self.call_reg(0xe05a2 if k==8 else 0xe09c0,(PATH,));value=value&255 if k==8 else value
            elif k==10:self.string_node(ROOT,units=c['path']);self.put(PATH+0x14,a,ROOT if b else 0)
            elif k==11:self.put(CORE+0x24,IOS if a else 0)
            elif k==12:self.maximum=a;self.read_ok=b;self.fail=-1 if d<0 else self.reads+d
            elif k==13:self.uc.mem_write(CORE+0x2c,bytes([bool(a)]))
            else:raise ValueError('Unknown named operation')
            answer+=pack([self.error,value,count,self.word(PATH+0x14),int(bool(self.word(PATH+0x18))),self.depth,self.current,len(self.files),self.path_releases,self.path_retains,len(payload)])+payload
        return answer+self.snapshot()
    def snapshot(self):
        answer=pack(self.positions[:2])+pack([len(self.files)])
        for f in self.files:
            data=self.word(f+0xc);backing=self.word(f+0x2c);answer+=pack([(data-DATAOBJS)//0x100+1 if data else 0,struct.unpack('<h',self.uc.mem_read(f+0x10,2))[0],self.word(f+0x1c),self.word(f+0x20),int(bool(self.word(f+0x28))),(backing-IOS)//0x100+1 if backing else 0,self.uc.mem_read(f+0x38,1)[0],self.word(f+0x30),self.word(f+0x34),self.uc.mem_read(f+0x24,1)[0]])
        answer+=pack([len(self.data)])
        for obj in self.data:answer+=pack([obj['size'],int(obj['locked']),self.refs[obj['p']]])+bytes(self.uc.mem_read(obj['at'],obj['size']))
        return answer+pack([len(self.trace)])+b''.join(pack(row) for row in self.trace)
