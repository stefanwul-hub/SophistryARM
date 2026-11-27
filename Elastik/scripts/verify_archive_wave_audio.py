#!/usr/bin/env python3
"""Independent PCM16 audio check while native WAVE reads inside original GNFA."""
import argparse
import hashlib
import io
import json
import math
from pathlib import Path
import struct
import subprocess
import wave
from compare_original_file_archive import ARCHIVE_SHA,BUILTIN
from wave_fixtures import WAVE_SHA
from verify_file_pipeline_audio import skip_node

def verify(runner,prefix,builtin,wave_path):
    bank=builtin.read_bytes();raw=wave_path.read_bytes();assert hashlib.sha256(bank).hexdigest()==ARCHIVE_SHA;assert hashlib.sha256(raw).hexdigest()==WAVE_SHA
    with wave.open(io.BytesIO(raw),'rb') as f:
        frames=f.getnframes();channels=f.getnchannels();rate=f.getframerate();assert f.getsampwidth()==2
        integers=struct.unpack('<'+'h'*(frames*channels),f.readframes(frames))
    independent=struct.pack('<'+'f'*len(integers),*(x/32768.0 for x in integers));runs=[]
    for clone in [0,1]:
        h=[len(bank),2,clone,0,frames,257,0,0]
        r=subprocess.run(prefix+[str(runner.resolve())],input=struct.pack('<8i',*h)+bank,stdout=subprocess.PIPE,stderr=subprocess.PIPE,check=True,timeout=30);b=r.stdout
        header=struct.unpack_from('<20i',b);assert header[0]==0 and header[3]==channels and header[7]==rate and header[8]==frames
        at=skip_node(b,80+2048+9);trace_count,=struct.unpack_from('<i',b,at);at+=4+trace_count*20
        ch,n,capacity=struct.unpack_from('<3i',b,at);at+=12;assert (ch,n,capacity)==(channels,frames,257)
        planar=[]
        for c in range(channels):planar.append(b[at:at+frames*4]);at+=(frames+16)*4
        at+=capacity;entry_count,logical_low,logical_high,source_position,clone_position=struct.unpack_from('<5I',b,at)
        interleaved=b''.join(planar[c][i*4:i*4+4] for i in range(frames) for c in range(channels));assert interleaved==independent
        assert entry_count==3 and logical_high==0 and source_position==1688
        if clone:assert clone_position==1688+logical_low
        runs.append(dict(stream_mode='dedicated clone' if clone else 'shared save/restore',all_samples_match_independent_pcm16_reference=True,container_source_position_preserved=True,interleaved_float32_sha256=hashlib.sha256(interleaved).hexdigest()))
    assert runs[0]['interleaved_float32_sha256']==runs[1]['interleaved_float32_sha256']=='555760159fb2f5e4331d3df06df12c1e659b27585601687f8ab364cd3e3d4ef3'
    measured=[]
    for c in range(channels):
        values=[integers[i*channels+c]/32768.0 for i in range(frames)];measured.append(dict(channel=c,peak=max(map(abs,values)),rms=math.sqrt(math.fsum(v*v for v in values)/frames)))
    return dict(checkpoint='ELA011',scope='Complete PCM WAVE read directly from the original GNFA bank through native archive member I/O',original_archive_sha256=ARCHIVE_SHA,reference_wave_sha256=WAVE_SHA,reference_wave_supplied_to_native_executable=False,frames=frames,channels=channels,sample_rate=rate,runs=runs,measurements=measured,original_archive_or_audio_published=False,protected_user_bank_compatibility_verified=False,complete_engine_rendered=False,macos_audio_unit_validated=False)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--builtin',type=Path,default=BUILTIN);p.add_argument('--wave',type=Path,required=True);p.add_argument('--platform',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=verify(a.runner,a.runner_prefix,a.builtin,a.wave);r['platform']=a.platform;a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
