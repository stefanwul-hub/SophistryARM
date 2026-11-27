#!/usr/bin/env python3
"""Independent PCM16 reference for the complete file-derived cache audio."""
import argparse
import hashlib
import json
import math
from pathlib import Path
import struct
from compare_original_file_pipeline import fixtures
from native_probe import NativeProbe
from wave_fixtures import WAVE_SHA

def skip_node(data,at):
    kind,=struct.unpack_from('<i',data,at);at+=4
    if not kind:return at
    n,=struct.unpack_from('<i',data,at);at+=4
    if kind>=3:return at+n
    for _ in range(n):
        if kind==1:
            size,=struct.unpack_from('<i',data,at);at+=4+size
        at=skip_node(data,at)
    return at

def verify(wave,runner,prefix):
    raw=wave.read_bytes();assert hashlib.sha256(raw).hexdigest()==WAVE_SHA
    case=next(c for c in fixtures(wave) if c['name']=='embedded-original-wave-first0-direction0')
    h=case['h'];command=prefix+[str(runner.resolve())]
    import subprocess
    result=subprocess.run(command,input=struct.pack('<12i',*h)+raw,stdout=subprocess.PIPE,stderr=subprocess.PIPE,check=True,timeout=30)
    data=result.stdout;header=struct.unpack_from('<14i',data);assert header[0]==0 and header[1:5]==(0x10,2,2,176399)
    at=skip_node(data,64);audio=[]
    for i in range(3):
        record=struct.unpack_from('<8i',data,at);assert record[0]==17
        at+=32+48;audio.append(data[at:at+17*4]);at+=(h[1]+16)*4
    assert audio[0]==bytes(17*4) and audio[1]==audio[2]
    capacity=header[6];slots=header[9];ids=struct.unpack_from('<'+'i'*capacity,data,at);at+=capacity*4
    mapping=struct.unpack_from('<'+'i'*capacity,data,at);at+=capacity*4
    cache_at=at;frames=176399;chunk=16384;channels=[[],[]];interleaved=bytearray()
    for frame in range(frames):
        block,within=divmod(frame,chunk);slot=mapping[block];assert slot>=0 and ids[slot]==block
        words=[data[cache_at+(slot*chunk*2+c*chunk+within)*4:cache_at+(slot*chunk*2+c*chunk+within+1)*4] for c in range(2)]
        for c,word in enumerate(words):channels[c].append(struct.unpack('<f',word)[0])
        interleaved.extend(b''.join(words))
    assert slots==11
    for slot in range(slots):
        valid=min(chunk,max(0,frames-ids[slot]*chunk))
        for c in range(2):
            start=cache_at+(slot*chunk*2+c*chunk+valid)*4;end=cache_at+(slot*chunk*2+(c+1)*chunk)*4
            assert data[start:end]==bytes((chunk-valid)*4)
    at=12
    while raw[at:at+4]!=b'data':size,=struct.unpack_from('<I',raw,at+4);at+=8+size+(size&1)
    size,=struct.unpack_from('<I',raw,at+4);samples=struct.unpack('<'+'h'*(size//2),raw[at+8:at+8+size])
    independent=struct.pack('<'+'f'*len(samples),*(x/32768.0 for x in samples));assert bytes(interleaved)==independent
    return dict(frames=frames,channels=2,sample_rate=44100,original_wave_sha256=WAVE_SHA,
        cache_slots_derived_and_filled=slots,all_cached_samples_match_independent_pcm16_reference=True,
        final_cache_block_tail_zeroed=True,cold_voice_read_zero=True,cached_and_direct_voice_audio_identical=True,
        interleaved_float32_sha256=hashlib.sha256(interleaved).hexdigest(),
        measurements=[dict(channel=c,peak=max(map(abs,x)),rms=math.sqrt(sum(v*v for v in x)/len(x))) for c,x in enumerate(channels)],
        actual_macos_execution=False,full_instrument_render=False)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--wave',type=Path,required=True);p.add_argument('--platform',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=verify(a.wave,a.runner,a.runner_prefix);r.update(checkpoint='ELA010',platform=a.platform);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
