#!/usr/bin/env python3
"""Verify every embedded WAV frame against original i386 and PCM16 arithmetic."""
import argparse
import hashlib
import io
import json
import math
from pathlib import Path
import struct
import wave
from compare_original_wave import WaveOracle, pack
from wave_fixtures import fixtures, WAVE_SHA
from native_probe import NativeProbe


def verify(binary, wave_path, candidates, audio_output=None):
    raw=wave_path.read_bytes()
    if hashlib.sha256(raw).hexdigest()!=WAVE_SHA:raise ValueError('Wrong embedded original WAV')
    case=next(c for c in fixtures(wave_path) if c['name']=='embedded-original-wave-complete')
    oracle=WaveOracle(binary);expected=oracle.execute(case)
    with wave.open(io.BytesIO(raw),'rb') as f:
        channels,frames,rate=f.getnchannels(),f.getnframes(),f.getframerate()
        if f.getsampwidth()!=2:raise ValueError('Expected original PCM16 input')
        pcm=f.readframes(frames)
    storage_bytes=channels*(frames+16)*4;buffer_bytes=case['h'][14]
    storage=expected[-storage_bytes-buffer_bytes:-buffer_bytes]
    planar=[storage[c*(frames+16)*4:c*(frames+16)*4+frames*4] for c in range(channels)]
    source=struct.unpack('<'+'h'*(frames*channels),pcm)
    analytic=[b''.join(struct.pack('<f',source[i*channels+c]/32768.0) for i in range(frames)) for c in range(channels)]
    if planar!=analytic:raise ValueError('Original conversion differs from independent PCM16 arithmetic')
    measurements=[]
    for c,b in enumerate(planar):
        values=struct.unpack('<'+'f'*frames,b)
        measurements.append(dict(channel=c,frames=frames,peak=max(map(abs,values)),rms=math.sqrt(math.fsum(x*x for x in values)/frames),float32_sha256=hashlib.sha256(b).hexdigest()))
    runs=[]
    for platform,runner,prefix in candidates:
        probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True)
        result=probe.run(pack(case['h'])+raw,len(expected));probe.close()
        if result.returncode or result.stdout!=expected:raise ValueError(f'Original/native PCM mismatch on {platform}')
        if result.stdout[-storage_bytes-buffer_bytes:-buffer_bytes]!=storage:raise ValueError('Audio storage mismatch')
        runs.append(dict(platform=platform,all_output_bytes_match_original_i386=True,all_audio_samples_match_source_pcm16_normalization=True))
    interleaved=b''.join(planar[c][i*4:i*4+4] for i in range(frames) for c in range(channels))
    if audio_output:
        header=b'RIFF'+struct.pack('<I',36+len(interleaved))+b'WAVEfmt '+struct.pack('<IHHIIHH',16,3,channels,rate,rate*channels*4,channels*4,32)+b'data'+struct.pack('<I',len(interleaved))
        audio_output.parent.mkdir(parents=True,exist_ok=True);audio_output.write_bytes(header+interleaved)
    return dict(checkpoint='ELA008',scope='Complete embedded WAVE container to planar float32 PCM, no synth voice/pitch processing',original_wave_sha256=WAVE_SHA,frames=frames,channels=channels,sample_rate=rate,duration_seconds=frames/rate,all_frames_match_original_i386=True,all_samples_match_independent_pcm16_divide_by_32768=True,channel_measurements=measurements,execution=runs,interleaved_float32_sha256=hashlib.sha256(interleaved).hexdigest(),audio_artifact_private=True,original_wave_or_rendered_audio_published=False,complete_instrument_engine_tested=False,macos_audio_unit_tested=False)


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary',type=Path);p.add_argument('wave',type=Path);p.add_argument('runner',type=Path)
    p.add_argument('--platform',required=True);p.add_argument('--runner-prefix',action='append',default=[])
    p.add_argument('--arm64-runner',type=Path);p.add_argument('--qemu',type=Path)
    p.add_argument('--audio-output',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    candidates=[(a.platform,a.runner,a.runner_prefix)]
    if a.arm64_runner:
        if not a.qemu:p.error('--arm64-runner requires --qemu')
        candidates.append(('aarch64',a.arm64_runner,[str(a.qemu)]))
    r=verify(a.binary,a.wave,candidates,a.audio_output);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
