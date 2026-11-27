#!/usr/bin/env python3
"""Bitwise comparison of original MS/DVI ADPCM and full WAVE read dispatch."""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
from original_cache_oracle import OriginalCacheOracle
from original_wave_chunks_oracle import pack
from native_probe import NativeProbe
from legacy_image import SHA
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP

WAVE,IO,IOVT,OUTPUTS,STORAGE,RAW,SCRATCH,BUFFER,ALLOC=0x580000,0x581000,0x582000,0x590000,0x600000,0x640000,0x670000,0x680000,0x690000
MS_COEFFICIENTS=[(256,0),(512,-256),(0,0),(192,64),(240,0),(460,-208),(392,-232)]

def ms_block(rng,channels,frames,*,predictors=None,deltas=None,seeds=None,nibble=None):
    predictors=predictors or [rng.randrange(7) for _ in range(channels)];deltas=deltas or [rng.randrange(1,65536) for _ in range(channels)];seeds=seeds or [(rng.randrange(-32768,32768),rng.randrange(-32768,32768)) for _ in range(channels)]
    n=(max(0,frames-2)*channels+1)//2
    body=rng.randbytes(n) if nibble is None else bytes([nibble*17])*n
    return bytes(predictors)+struct.pack('<'+'H'*channels,*deltas)+struct.pack('<'+'h'*channels,*(s[0] for s in seeds))+struct.pack('<'+'h'*channels,*(s[1] for s in seeds))+body

def dvi_block(rng,channels,groups,*,indices=None,reserved=0,nibble=None,seeds=None):
    indices=indices or [rng.randrange(256) for _ in range(channels)];seeds=seeds or [rng.randrange(-32768,32768) for _ in range(channels)]
    headers=b''.join(struct.pack('<hBB',seeds[c],indices[c],reserved) for c in range(channels))
    body=rng.randbytes(channels*groups*4) if nibble is None else bytes([nibble*17])*(channels*groups*4)
    return headers+body

def case(rng,name,mode,fmt,channels,frames,block,*,first=0,end=None,mask=0,delta=0,blocks=None,read_count=None,maximum=-1,fail=-1,read_ok=1,coefficients=None):
    block_bytes=len(block);data_offset=11 if mode==2 else 0;raw=(b'p'*data_offset+b''.join(blocks or [block])) if mode==2 else block
    if end is None:end=frames
    if mode==2:end=frames if read_count is None else read_count
    storage_frames=256
    storage=struct.pack('<'+'f'*(channels*storage_frames),*(rng.uniform(-0.002,0.002) for _ in range(channels*storage_frames)))
    coefficients=coefficients or MS_COEFFICIENTS+[(0,0)]*(256-len(MS_COEFFICIENTS))
    return dict(name=name,h=[mode,len(raw),fmt,channels,frames,block_bytes,first,end,8,storage_frames,mask,maximum,fail,read_ok,data_offset,257],coefficients=[v for pair in coefficients for v in pair],storage=storage,raw=raw)

def fixtures():
    rng=random.Random(0xe1a0092)
    for channels in [1,2]:
        for frames in [0,1,2,3,4,9,32]:
            for nibble in range(16):
                for delta in [1,16,32768,65535]:
                    block=ms_block(rng,channels,frames,deltas=[delta]*channels,nibble=nibble)
                    yield case(rng,f'ms-ch{channels}-frames{frames}-nibble{nibble}-delta{delta}',0,2,channels,frames,block,first=0,end=frames+1)
    for channels in [1,2]:
        for predictor in range(7):
            block=ms_block(rng,channels,33,predictors=[predictor]*channels)
            for first,end in [(-2,0),(-2,5),(0,0),(0,1),(1,2),(2,8),(17,33),(32,36),(36,40)]:
                for mask in [0,(1<<channels)-1,1]:yield case(rng,f'ms-crop-ch{channels}-pred{predictor}-range{first}-{end}-mask{mask}',0,2,channels,33,block,first=first,end=end,mask=mask)
    # Wrapped signed prediction products and both clamp extremes.
    for coefficients in [[(-32768,-32768)]*256,[(32767,32767)]*256]:
        for seed in [-32768,32767]:
            block=ms_block(rng,2,17,seeds=[(seed,seed)]*2,nibble=8)
            yield case(rng,f'ms-prediction-wrap-coef{coefficients[0][0]}-seed{seed}',0,2,2,17,block,coefficients=coefficients)
    for channels in [1,2,4]:
        for groups in [0,1,3]:
            frames=1+groups*8
            for index in [0,1,44,87,88,89,255]:
                for nibble in range(16):
                    block=dvi_block(rng,channels,groups,indices=[index]*channels,nibble=nibble,reserved=1 if index==255 else 0)
                    yield case(rng,f'dvi-ch{channels}-groups{groups}-index{index}-nibble{nibble}',1,17,channels,frames,block)
    for channels in [1,2,4,8]:
        block=dvi_block(rng,channels,2,reserved=255)
        for extra in [0,1,7]:
            for first,end in [(-2,0),(-2,7),(0,0),(0,1),(1,8),(8,17),(16,24),(24,28)]:
                for mask in [0,1,(1<<channels)-1]:yield case(rng,f'dvi-crop-ch{channels}-zero-tail{extra}-range{first}-{end}-mask{mask}',1,17,channels,17+extra,block,first=first,end=end,mask=mask)
    for fmt in [2,17]:
        for channels in [1,2]:
            values=17;factory=lambda:ms_block(rng,channels,values) if fmt==2 else dvi_block(rng,channels,2)
            blocks=[factory() for _ in range(8)];block_frames=values if fmt==2 else values//channels
            for first in [0,1,block_frames-1,block_frames,block_frames+3]:
                for count in [0,1,3,block_frames,block_frames*2+1]:
                    for mask in [0,1,(1<<channels)-1]:
                        yield case(rng,f'dispatch-fmt{fmt}-ch{channels}-first{first}-count{count}-mask{mask}',2,fmt,channels,values,blocks[0],blocks=blocks,first=first,read_count=count,mask=mask)
            for maximum in [-1,0,1,len(blocks[0])-1]:
                for fail in [-1,0,1,2]:
                    for ok in [0,1]:yield case(rng,f'dispatch-read-fmt{fmt}-ch{channels}-maximum{maximum}-fail{fail}-ok{ok}',2,fmt,channels,values,blocks[0],blocks=blocks,first=1,read_count=block_frames*2,maximum=maximum,fail=fail,read_ok=ok)
    for fmt in [1,3,7]:
        for channels in [1,2,4]:
            block=rng.randbytes(128*channels*(4 if fmt==3 else 2))
            for ok in [0,1]:yield case(rng,f'dispatch-pcm-unknown-fmt{fmt}-ch{channels}-ok{ok}',2,fmt,channels,17,block,first=3,read_count=31,read_ok=ok)

class AdpcmOracle(OriginalCacheOracle):
    def __init__(self,binary):
        super().__init__(binary)
        for at,fn in [(0x500f30,self.read),(0x500f40,self.seek),(0xaecc,self.allocate),(0xb122,self.release),(0x33b90,lambda *x:self.finish(1)),(0xbf34,self.raise_read)]:self.uc.hook_add(UC_HOOK_CODE,fn,begin=at,end=at)
        self.put(IOVT+0x1ac,0x500f30);self.put(IOVT+0x1c0,0x500f40);self.put(IO,IOVT)
    def record(self,*v):self.trace.append(list(v)+[0]*(5-len(v)))
    def read(self,*unused):
        obj,dest,count=self.arguments(3);assert obj==IO;wanted=self.word(count);h=self.case['h']
        actual=max(0,min(wanted,len(self.case['raw'])-self.position)) if self.position>=0 else 0
        if h[11]>=0:actual=min(actual,h[11])
        ok=bool(h[13] and self.reads!=h[12]);data=self.case['raw'][self.position:self.position+actual] if actual else b''
        if data:self.uc.mem_write(dest,data)
        self.record(2,self.position,wanted,actual,int(ok));self.position+=actual;self.reads+=1;self.put(count,actual);self.finish(int(ok))
    def seek(self,*unused):obj,at=self.arguments(2);assert obj==IO;self.position=at if at<0x80000000 else at-0x100000000;self.record(1,self.position);self.finish()
    def allocate(self,*unused):n,=self.arguments(1);p=ALLOC+len(self.allocations)*0x10000;self.uc.mem_write(p,b'\xa5'*n);self.allocations.append(p);self.record(3,n,len(self.allocations));self.finish(p)
    def release(self,*unused):p,=self.arguments(1);self.released+=1;self.record(4,self.allocations.index(p)+1);self.finish()
    def raise_read(self,*unused):self.error=1;self.uc.emu_stop()
    def diagnostic(self,*unused):
        text_at,*v=self.arguments(4);text=bytes(self.uc.mem_read(text_at,256)).split(b'\0')[0]
        if text==b'IMA ADPCM synchronisation error.':self.record(5,5)
        elif text.startswith(b'Reading sound failed:'):self.record(6,*v)
        elif text==b'GNAudioConvertSampleFormat(): Unsupported input format.':self.record(7,1)
        elif text==b'GNAudioConvertSampleFormat(): Unsupported output format.':self.record(7,2)
        else:raise ValueError('Unexpected codec diagnostic '+repr(text))
        self.finish()
    def execute(self,c):
        self.case=c;h=c['h'];self.position=self.reads=self.released=self.error=0;self.trace=[];self.allocations=[]
        self.uc.mem_write(WAVE,bytes(0x900));self.put(WAVE,0x3a9908);self.put(WAVE+0xc,h[15],BUFFER,IO)
        for off,value in [(0x1a,h[3]),(0x1c,32 if h[2]==3 else 16),(0x1e,h[2]),(0x38,h[4]),(0x3a,h[5]),(0x3e,h[4]),(0x40,h[5])]:self.uc.mem_write(WAVE+off,struct.pack('<H',value&65535))
        self.put(WAVE+0x20,4 if h[2]==3 else 2);self.put(WAVE+0x30,h[14]);self.put(WAVE+0x48,*c['coefficients'])
        values=h[3]*h[4] if h[0]==1 or h[2]==17 else 0;self.uc.mem_write(SCRATCH,b'\xa5'*((values+16)*2));self.put(WAVE+0x44,SCRATCH+16 if values else 0)
        self.uc.mem_write(BUFFER,b'\xa5'*h[15]);self.uc.mem_write(RAW,c['raw'] or b'\0');self.uc.mem_write(STORAGE,c['storage'])
        for channel in range(h[3]):self.put(OUTPUTS+channel*4,0 if h[10]&(1<<channel) else STORAGE+channel*h[9]*4+(h[8]*4 if h[0]==2 else 0))
        before=bytes(self.uc.mem_read(WAVE,0x900));status=0
        if h[0]==0:self.call(0x24c638,WAVE,RAW,h[6],h[7],OUTPUTS,h[8])
        elif h[0]==1:self.call(0x249b18,WAVE,RAW,h[6],h[7],OUTPUTS,h[8])
        else:
            try:self.call(0x24cc60,WAVE,OUTPUTS,h[6],h[7])
            except ValueError:
                if not self.error:raise
            status=self.error
        assert bytes(self.uc.mem_read(WAVE,0x900))==before
        assert bytes(self.uc.mem_read(RAW,len(c['raw'])))==c['raw']
        return pack([status,len(self.allocations),self.released,self.position,values])+bytes(self.uc.mem_read(STORAGE,len(c['storage'])))+bytes(self.uc.mem_read(SCRATCH,(values+16)*2))+bytes(self.uc.mem_read(BUFFER,h[15]))+c['raw']+pack([len(self.trace)])+b''.join(pack(row) for row in self.trace)

def compare(binary,runner,prefix,platform):
    oracle=AdpcmOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=0
    for c in fixtures():
        try:expected=oracle.execute(c)
        except Exception as e:raise RuntimeError(f'Original ADPCM case {c["name"]}: {e}') from e
        data=pack(c['h'])+pack(c['coefficients'])+c['storage']+c['raw'];actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA009-native');folder.mkdir(parents=True,exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]: (folder/f'failing-adpcm-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)))
            raise ValueError(f'ADPCM mismatch {c["name"]}: exit={actual.returncode} byte={at} original={expected[at:at+16].hex()} native={actual.stdout[at:at+16].hex()}')
        cases.append(dict(name=c['name'],mode=c['h'][0],status=struct.unpack_from('<i',expected)[0],all_bytes_match=True,sha256=hashlib.sha256(expected).hexdigest()));total+=len(expected)
    probe.close();return dict(checkpoint='ELA009',scope='Original MS/DVI ADPCM block decoders and complete WAVE frame dispatch',original_i386_sha256=SHA,compiled_platform=platform,fixture_count=len(cases),compared_bytes=total,all_cases_match_bit_for_bit=True,input_and_reader_metadata_unchanged=True,dvi_integer_scratch_and_guards_compared=True,asymmetric_float_normalization_compared=True,allocator_and_byte_io_are_bindings=True,compressed_read_exception_mapped_to_status=True,complete_engine_built=False,macos_audio_unit_validated=False,automatic_fixture_retries=0,cases=cases)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:v for k,v in r.items() if k!='cases'},indent=2))
