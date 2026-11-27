"""Execute original WAVE inst/ACID byte-span readers and instrument writer."""
from pathlib import Path
import struct
from original_cache_oracle import OriginalCacheOracle, STACK, RETURN
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_EFLAGS,UC_X86_REG_MXCSR

STATE,DATA,READER,VTABLE,RAW,WRITER,WRITTEN=0x570000,0x571000,0x572000,0x573000,0x580000,0x574000,0x590000
def pack(values):return struct.pack('<'+'i'*len(values),*((v+(1<<31))%(1<<32)-(1<<31) for v in values))

class ChunkOracle(OriginalCacheOracle):
    def __init__(self,binary):
        super().__init__(binary)
        hooks={0x278d6:self.count,0x17e50c:self.construct,0x2dfa6:self.identity,0x17f8a0:self.bind_data,
               0x500f00:self.identity,0x500f10:self.read,0x33b90:self.string,0xbf34:self.raise_error,
               0x28308:self.create_data,0x27abc:lambda *x:self.finish(WRITTEN)}
        for at,fn in hooks.items():self.uc.hook_add(UC_HOOK_CODE,fn,begin=at,end=at)
        self.import_handlers['__Znwm']=lambda:self.finish(READER)
        self.put(VTABLE+0x40,0x500f00,0x500f00,0x500f00);self.put(VTABLE+0x1ac,0x500f10)
    def identity(self,*unused):p,=self.arguments(1);self.finish(p)
    def count(self,*unused):p,=self.arguments(1);self.finish(self.writer_size if p==WRITER else len(self.raw))
    def construct(self,*unused):
        p,=self.arguments(1);assert p==READER;self.uc.mem_write(READER,bytes(64));self.put(READER,VTABLE);self.finish()
    def bind_data(self,*unused):p,data=self.arguments(2);assert(p,data)==(READER,DATA);self.position=0;self.finish()
    def read(self,*unused):
        obj,dest,size=self.arguments(3);assert obj==READER;n=self.word(size);data=self.raw[self.position:self.position+n];assert len(data)==n
        self.uc.mem_write(dest,data);self.put(size,n);self.position+=n;self.finish(1)
    def string(self,*unused):
        p,=self.arguments(1);name=bytes(self.uc.mem_read(p,256)).split(b'\0')[0]
        if name==b'GNSoundFileCannotReadFileException':self.finish(1)
        elif name==b'GNSoundFileFormatNotSupportedException':self.finish(2)
        else:raise ValueError('Unexpected original chunk exception '+repr(name))
    def raise_error(self,*unused):self.error,=self.arguments(1);self.uc.emu_stop()
    def create_data(self,*unused):self.writer_size,=self.arguments(1);self.finish(WRITER)
    def call_packed(self,address,packed):
        self.error=0;self.uc.mem_write(STACK,struct.pack('<I',RETURN)+packed);self.uc.reg_write(UC_X86_REG_ESP,STACK);self.uc.reg_write(UC_X86_REG_EFLAGS,2);self.uc.reg_write(UC_X86_REG_MXCSR,0x1f80)
        self.uc.emu_start(address,RETURN,count=100000)
        if not self.error and self.uc.reg_read(UC_X86_REG_EIP)!=RETURN:raise ValueError('Original chunk did not return')
        return self.uc.reg_read(UC_X86_REG_EAX)
    def execute(self,mode,raw,initial,is_null=False,flags=0):
        self.raw=raw;self.position=0;self.writer_size=0
        self.uc.mem_write(STATE,b'\xa5'*64);self.uc.mem_write(WRITTEN,b'\xa5'*8)
        self.uc.mem_write(RAW,raw or b'\0')
        if mode==1:
            self.uc.mem_write(STATE+0xc,bytes([initial[0]&255]));self.put(STATE+0x10,*initial[1:6]);self.put(STATE+0x24,initial[6])
            self.call(0x288744,STATE,0 if is_null else DATA);status=self.error
            state=[self.uc.mem_read(STATE+0xc,1)[0],*[self.word(STATE+x) for x in [0x10,0x14,0x18,0x1c,0x20,0x24]]];padding=bytes(self.uc.mem_read(STATE+0xd,3))
        else:
            self.put(STATE+0xc,*initial)
            if mode==0:self.call(0x28900e,STATE,0 if is_null else DATA);status=self.error
            else:self.call(0x28916a,STATE,flags);status=self.writer_size
            state=[self.word(STATE+x) for x in [0xc,0x10,0x14,0x18,0x1c,0x20,0x24]];padding=bytes(3)
        assert bytes(self.uc.mem_read(RAW,len(raw)))==raw
        return pack([status])+pack(state)+padding+bytes(self.uc.mem_read(WRITTEN,8))+raw
    def decoded_state(self,acid,raw):
        result=self.execute(1 if acid else 0,raw,[0]*7)
        status=struct.unpack_from('<i',result)[0]
        return status,result[4:28 if acid else 32]
