#!/usr/bin/env python3
"""Compare unmodified original WAVE parsing, scanner/getters and PCM rendering.

GN object primitives, byte I/O, GN exceptions and inst/acid subdecoders are
explicit boundaries. Container parsing and numeric reads execute original code.
The inst/acid bindings return opaque test objects; they do not decode music data.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from original_cache_oracle import OriginalCacheOracle, STACK, RETURN
from native_probe import NativeProbe
from legacy_image import SHA
from wave_fixtures import fixtures,WAVE_SHA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP,UC_X86_REG_EAX,UC_X86_REG_EDX,UC_X86_REG_EFLAGS,UC_X86_REG_MXCSR

WAVE,IO,PATH,FILE=0x560000,0x562000,0x562100,0x562200
IOVT,PATHVT,FILEVT,OBJVT=0x563000,0x563400,0x563800,0x564000
CHUNK,CHUNK_SIZE,DATA_STRING,CHANNELS,BUFFER=0x565000,0x565100,0x565200,0x566000,0x600000
def pack(v):return struct.pack('<'+'i'*len(v),*((x+(1<<31))%(1<<32)-(1<<31) for x in v))
def serialize(n):
    if n is None:return pack([0])
    kind,value=n['kind'],n['value']
    if kind==1:
        entries=sorted(value.items());return pack([1,len(entries)])+b''.join(pack([len(k.encode('latin1'))])+k.encode('latin1')+serialize(v) for k,v in entries)
    if kind==2:return pack([2,len(value)])+b''.join(serialize(v) for v in value)
    return pack([kind,len(value)])+value


class WaveOracle(OriginalCacheOracle):
    def __init__(self,binary):
        super().__init__(binary);self.uc.mem_map(0x800000,0x3000000)
        callbacks={0x500d00:self.read,0x500d10:self.position,0x500d20:self.seek,0x500d30:lambda *x:self.finish(FILE),0x500d40:self.length,
                   0x500d50:self.open,0x500d60:self.retain_io,0x500d70:lambda *x:self.finish(0),0x500e00:self.object_noop,
                   0x500e10:self.resize_or_name,0x630b6:lambda *x:self.construct(1),0x29d44:lambda *x:self.construct(2),
                   0x2dfa6:self.initialize,0x33b90:self.string,0x858da:self.integer,0x859a8:self.long_integer,0x66284:self.set,
                   0x64626:self.get,0x2bb40:self.append,0x63426:self.identity,0x29ddc:self.count,0x278d6:self.count,
                   0x180166:self.read_data,0x3887c:self.create_string,0x38d00:self.data_string,0x39d7a:self.create_string_default,
                   0x27b4e:self.data_lock,0x27abc:self.data_bytes,0x27bec:self.identity,0xbf34:self.raise_error,0xbfd6:self.raise_error,
                   0x289de8:lambda *x:self.decode(False),0x28a322:lambda *x:self.decode(True),0xaecc:self.allocate_dvi}
        for at,callback in callbacks.items():self.uc.hook_add(UC_HOOK_CODE,callback,begin=at,end=at)
        self.import_handlers.update(__Znwm=self.new,__Znam=self.new,__ZdlPv=self.delete,_strncmp=self.strncmp,_strcmp=self.strcmp,___udivdi3=self.divide_u64)
        self.put(IOVT+0x40,0x500d60);self.put(IOVT+0x1a8,0x500d30,0x500d00);self.put(IOVT+0x1b8,0x500d10,0,0x500d20)
        self.put(PATHVT+0x248,0x500d50);self.put(PATHVT+0x1bc,0x500d70);self.put(FILEVT+0x1d8,0x500d40)
        self.put(OBJVT+0x40,0x500e00,0x500e00,0x500e00);self.put(OBJVT+0x1a4,0x500e10)
        self.uc.mem_write(DATA_STRING,b'data\0')
    def record(self,*v):self.trace.append(list(v)+[0]*(5-len(v)))
    def cstring(self,p):
        data=bytes(self.uc.mem_read(p,4096));return data.split(b'\0',1)[0]
    def alloc(self,n):
        p=self.heap;self.heap+=(n+15)//16*16+16
        if self.heap>=0x1f00000:raise ValueError('Fixture object heap bound')
        self.uc.mem_write(p,bytes(n));return p
    def node(self,kind,value):
        p=self.alloc(64);self.put(p,OBJVT);self.nodes[p]=dict(kind=kind,value=value);return p
    def n(self,p):return self.nodes[p] if p else None
    def new(self):size,=self.arguments(1);self.finish(self.alloc(size))
    def delete(self):self.finish()
    def construct(self,kind):
        p,=self.arguments(1);self.put(p,OBJVT);self.nodes[p]=dict(kind=kind,value={} if kind==1 else []);self.finish()
    def identity(self,*unused):p,=self.arguments(1);self.finish(p)
    def initialize(self,*unused):self.identity()
    def object_noop(self,*unused):self.identity()
    def integer(self,*unused):v,=self.arguments(1);self.finish(self.node(3,struct.pack('<I',v)))
    def long_integer(self,*unused):a,b=self.arguments(2);self.finish(self.node(4,struct.pack('<II',a,b)))
    def string(self,*unused):p,=self.arguments(1);self.finish(self.node(5,self.cstring(p)))
    def create_string(self,*unused):p,n,encoding=self.arguments(3);assert encoding==4;self.finish(self.node(5,bytes(self.uc.mem_read(p,n))))
    def create_string_default(self,*unused):p,n=self.arguments(2);self.finish(self.node(5,bytes(self.uc.mem_read(p,n))))
    def data_string(self,*unused):p,encoding=self.arguments(2);assert encoding==4;self.finish(self.node(5,self.n(p)['value']) if p else 0)
    def set(self,*unused):
        d,value,key=self.arguments(3);k=self.n(key)['value'].decode('latin1');target=self.n(d)['value']
        if value:target[k]=self.n(value)
        else:target.pop(k,None)
        self.finish()
    def get(self,*unused):
        d,key=self.arguments(2);value=self.n(d)['value'].get(self.n(key)['value'].decode('latin1'))
        self.finish(next((p for p,n in self.nodes.items() if n is value),0))
    def append(self,*unused):a,v=self.arguments(2);self.n(a)['value'].append(self.n(v));self.finish()
    def count(self,*unused):p,=self.arguments(1);self.finish(len(self.n(p)['value']))
    def resize_or_name(self,*unused):
        p,=self.arguments(1);node=self.n(p)
        if node['kind']==7:
            name=b'GNSoundFileTimeAndScaleChunk' if node['value'][:4]==b'acid' else b'GNSoundFileInstrumentChunk';self.finish(self.node(5,name))
        else:
            p,length=self.arguments(2);assert 0<=length<=len(node['value']);node['value']=node['value'][:length];self.finish()
    def data_lock(self,*unused):
        p,=self.arguments(1)
        if not p:self.error=3;self.uc.emu_stop()
        else:self.finish()
    def data_bytes(self,*unused):
        p,=self.arguments(1);value=self.n(p)['value'];at=self.data_heap;self.data_heap+=(len(value)+15)//16*16+16;self.uc.mem_write(at,value);self.finish(at)
    def read_raw(self,wanted):
        actual=max(0,min(wanted,len(self.case['raw'])-self.at)) if self.at>=0 else 0
        if self.case['h'][5]>=0:actual=min(actual,self.case['h'][5])
        ok=bool((self.case['h'][15]&2) or actual==wanted) and self.reads!=self.case['h'][4]
        data=self.case['raw'][self.at:self.at+actual] if actual else b'';self.record(2,self.at,wanted,actual,int(ok));self.at+=actual;self.reads+=1
        return ok,data
    def read(self,*unused):
        obj,dest,size=self.arguments(3);assert obj==IO;ok,data=self.read_raw(self.word(size))
        if data:self.uc.mem_write(dest,data)
        self.put(size,len(data));self.finish(int(ok))
    def read_data(self,*unused):
        obj,size=self.arguments(2);assert obj==IO and size<0x1000000
        if not size:self.finish(self.node(6,b''));return
        ok,data=self.read_raw(size);self.finish(self.node(6,data) if ok else 0)
    def decode(self,acid):
        kind,data=self.arguments(2);assert kind==2
        if not data or self.case['h'][15]&4:self.finish(0)
        else:self.finish(self.node(7,(b'acid' if acid else b'inst')+self.n(data)['value']))
    def allocate_dvi(self,*unused):
        size,=self.arguments(1);self.record(8,size);self.finish(0 if self.case['h'][15]&8 else self.alloc(size))
    def open(self,*unused):self.record(5,self.case['h'][3]);self.finish(IO if self.case['h'][3] else 0)
    def retain_io(self,*unused):self.record(6);self.finish(IO)
    def seek(self,*unused):obj,at=self.arguments(2);assert obj==IO;self.at=at if at<0x80000000 else at-0x100000000;self.record(1,self.at);self.finish()
    def position(self,*unused):self.record(3,self.at);self.finish(self.at)
    def length(self,*unused):self.record(4,len(self.case['raw']));self.finish(len(self.case['raw']))
    def strncmp(self):
        a,b,n=self.arguments(3);left=bytes(self.uc.mem_read(a,n)).split(b'\0',1)[0];right=bytes(self.uc.mem_read(b,n)).split(b'\0',1)[0];self.finish((left>right)-(left<right))
    def strcmp(self):a,b=self.arguments(2);left,right=self.cstring(a),self.cstring(b);self.finish((left>right)-(left<right))
    def divide_u64(self):
        a,b,c,d=self.arguments(4);dividend=a+(b<<32);divisor=c+(d<<32);assert divisor
        quotient=dividend//divisor;self.uc.reg_write(UC_X86_REG_EDX,quotient>>32);self.finish(quotient)
    def raise_error(self,*unused):
        kind,=self.arguments(1);name=self.n(kind)['value'];codes={b'GNSoundFileCannotReadFileException':1,b'GNSoundFileFormatNotSupportedException':2,b'GNAssertionException':3}
        if name not in codes:raise ValueError('Unexpected GN exception '+repr(name))
        self.error=codes[name];self.uc.emu_stop()
    def diagnostic(self,*unused):
        args=self.arguments(5);text=self.cstring(args[0])
        if text==b'Wave format %i not supported':self.record(7,1,self.word(self.uc.reg_read(UC_X86_REG_ESP)+8),0)
        elif text.startswith(b'Wave: File '):self.record(7,2,args[2],args[3])
        elif text==b'Wave playlists not supported':self.record(7,3)
        elif text==b'Wave wavelists not supported':self.record(7,4)
        elif text.startswith(b'Reading sound failed:'):self.record(9,*args[1:4])
        elif text==b'GNAudioConvertSampleFormat(): Unsupported input format.':self.record(10,1)
        elif text==b'GNAudioConvertSampleFormat(): Unsupported output format.':self.record(10,2)
        else:raise ValueError('Unexpected diagnostic '+repr(text))
        self.finish()
    def call_packed(self,address,packed):
        self.error=0;self.uc.mem_write(STACK,struct.pack('<I',RETURN)+packed);self.uc.reg_write(UC_X86_REG_ESP,STACK);self.uc.reg_write(UC_X86_REG_EFLAGS,2);self.uc.reg_write(UC_X86_REG_MXCSR,0x1f80)
        self.uc.emu_start(address,RETURN,count=50000000 if address==0x24cc60 else 3000000)
        if not self.error and self.uc.reg_read(UC_X86_REG_EIP)!=RETURN:raise ValueError(f'Original {address:#x} did not return')
        return self.uc.reg_read(UC_X86_REG_EAX)
    def execute(self,case):
        self.case=case;h=case['h'];self.at=self.reads=0;self.trace=[];self.nodes={};self.heap=0x1000000;self.data_heap=0x2000000
        self.uc.mem_write(0x700000,bytes(0x10000));self.uc.mem_write(WAVE,bytes(0x1000));self.put(WAVE,0x3a9908)
        for off,value in [(0x1e,h[6]),(0x1a,h[7]),(0x1c,h[8])]:self.uc.mem_write(WAVE+off,struct.pack('<H',value&65535))
        self.put(WAVE+0x20,h[9]);self.put(WAVE+0x28,h[10]);self.uc.mem_write(WAVE+0x48,b'\xa5'*2048)
        root=self.node(1,{});self.put(WAVE+0x34,root)
        if h[15]&1:self.n(root)['value']['preexisting']=dict(kind=3,value=pack([319]))
        self.put(IO,IOVT);self.put(IO+0x14,h[2]);self.put(PATH,PATHVT);self.put(FILE,FILEVT)
        self.uc.mem_write(CHUNK,bytes(5));self.put(CHUNK_SIZE,0)
        status=0
        if h[0]==1:status=self.call(0x24bfce,IO,h[11],CHUNK,CHUNK_SIZE,0x3673a0,21,DATA_STRING)
        elif h[0]!=2:self.call(0x24ce76,WAVE,PATH);status=self.error
        channels=frames=0;audio=[];buffer=b''
        if h[0]==3 and status==0:
            channels=struct.unpack('<h',self.uc.mem_read(WAVE+0x1a,2))[0];frames=h[13];self.put(WAVE+0xc,h[14],BUFFER);self.uc.mem_write(BUFFER,b'\xa5'*h[14])
            for channel in range(channels):
                at=0x2800000+channel*0x200000;self.put(CHANNELS+channel*4,at);self.uc.mem_write(at,struct.pack('<f',0.03125)*(frames+16))
            self.call(0x24cc60,WAVE,CHANNELS,h[12],frames)
            assert not self.error
            audio=[bytes(self.uc.mem_read(0x2800000+channel*0x200000,(frames+16)*4)) for channel in range(channels)];buffer=bytes(self.uc.mem_read(BUFFER,h[14]))
        s=lambda off:struct.unpack('<h',self.uc.mem_read(WAVE+off,2))[0]
        header=[status,int(self.word(WAVE+0x14)!=0),s(0x18),s(0x1a),s(0x1c),s(0x1e),self.word(WAVE+0x20),self.word(WAVE+0x24),self.word(WAVE+0x28),self.word(WAVE+0x2c),self.word(WAVE+0x30),s(0x38),s(0x3a),s(0x3c),s(0x3e),s(0x40),int(self.word(WAVE+0x44)!=0),self.call(0x249976,WAVE),self.call(0x2499f8,WAVE),self.call(0x249a3c,WAVE)]
        answer=pack(header)+bytes(self.uc.mem_read(WAVE+0x48,2048))+bytes(self.uc.mem_read(CHUNK,5))+bytes(self.uc.mem_read(CHUNK_SIZE,4))+serialize(self.n(root))+pack([len(self.trace)])+b''.join(pack(row) for row in self.trace)
        return answer+pack([channels,frames,len(buffer)])+b''.join(audio)+buffer


def compare(binary,runner,prefix,platform,wave):
    oracle=WaveOracle(binary)
    probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=events=audio_cases=0
    for case in fixtures(wave):
        try:expected=oracle.execute(case)
        except Exception as e:raise RuntimeError(f'Original failed at {case["name"]}: {e}') from e
        data=pack(case['h'])+case['raw'];actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA008-native');folder.mkdir(parents=True,exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]: (folder/f'failing-wave-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)))
            raise ValueError(f'WAVE mismatch {case["name"]}: exit={actual.returncode} byte={at} expected={expected[at:at+24].hex()} native={actual.stdout[at:at+24].hex()}')
        total+=len(expected);events+=len(oracle.trace);audio_cases+=case['h'][0]==3
        cases.append(dict(name=case['name'],mode=case['h'][0],status=struct.unpack_from('<i',expected)[0],trace_events=len(oracle.trace),all_bytes_match=True,sha256=hashlib.sha256(expected).hexdigest()))
    probe.close()
    return dict(checkpoint='ELA008',scope='Original WAVE container parsing, scalar metadata, musical chunk graph and PCM rendering',original_i386_sha256=SHA,compiled_platform=platform,fixture_count=len(cases),compared_bytes=total,platform_trace_events=events,pcm_render_cases=audio_cases,all_cases_match_bit_for_bit=True,original_header_parser_executed=True,header_derived_metadata_substituted=False,original_numeric_file_reads_executed=True,embedded_wave_cases=4,embedded_wave_sha256=WAVE_SHA,complete_embedded_wave_frames=176399,boundaries_adapted=['byte file open/retain/position/length/read/seek','GN metadata primitives and raw-data reads','GN exceptions represented by status','inst/acid subdecoders return opaque fixture objects','DVI scratch allocator','unsigned 64-bit compiler runtime division'],inst_acid_payloads_decoded=False,compressed_audio_decoded=False,actual_GN_objects_and_reference_counting_validated=False,actual_macos_file_io_validated=False,complete_engine_built=False,macos_audio_unit_validated=False,automatic_fixture_retries=0,cases=cases)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--wave',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    r=compare(a.binary,a.runner,a.runner_prefix,a.platform,a.wave);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:v for k,v in r.items() if k not in ['cases','boundaries_adapted']},indent=2))
