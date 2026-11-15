#!/usr/bin/env python3
"""Generate public test assets from the supplied PCM16 fixture, not a user bank.

The D4U/D4T header follows the original reader at 0xb2a2a: decimal byte
count, channel count, decimal rate and planar little-endian float32 data.
"""
import argparse
import array
import json
import plistlib
import struct
import sys
import wave
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def decimal(value, length):
    data = bytearray(length)
    for n in reversed(range(length)):
        data[n] = value % 100
        value //= 100
    if value:
        raise ValueError('Test asset exceeds the original decimal header')
    return data


def generate(output):
    output.mkdir(parents=True, exist_ok=True)
    with wave.open(str(ROOT/'reference/Samples/BT_cronox18.wav'), 'rb') as f:
        assert (f.getnchannels(), f.getsampwidth(), f.getframerate()) == (2, 2, 44100)
        frames = f.getnframes()
        pcm = array.array('h', f.readframes(frames))
        if sys.byteorder != 'little':
            pcm.byteswap()
    samples = [pcm[0::2], pcm[1::2]]
    fxp = (ROOT/'reference/Presets/lightgarden 02 BT.FXP').read_bytes()
    au = plistlib.loads((ROOT/'reference/Presets/Lightgarden 02 BT.aupreset').read_bytes())
    cases = []
    specifications = [('wav',16,1), ('wav',24,1), ('wav',24,2), ('wav',32,2),
                      ('wav-float',32,1), ('wav-float',32,2),
                      ('aiff',16,1), ('aiff',24,2),
                      ('d4u',32,1), ('d4u',32,2), ('d4t',32,1), ('d4t',32,2)]
    for kind,bits,channels in specifications:
        name = f'{kind}-{bits}-{channels}'
        folder = output/name
        folder.mkdir(exist_ok=True)
        extension = {'wav':'wav','wav-float':'wav','aiff':'AIF','d4u':'D4U','d4t':'D4T'}[kind]
        basename = 'BT_cronox18.'+extension
        target = folder/basename
        floating = kind in ['wav-float','d4u','d4t']
        planar = kind in ['d4u','d4t']
        order = 'big' if kind == 'aiff' else 'little'
        if planar:
            data = b''.join(struct.pack('<f', n/32768.0)
                            for c in range(channels) for n in samples[c])
        elif floating:
            data = b''.join(struct.pack('<f', samples[c][i]/32768.0)
                            for i in range(frames) for c in range(channels))
        else:
            data = b''.join((int(samples[c][i]) * (1 << (bits-16))).to_bytes(bits//8,order,signed=True)
                            for i in range(frames) for c in range(channels))
        if planar:
            header = bytearray(40)
            header[:8] = b'D4U 0001' if kind == 'd4u' else b'D4T 0001'
            header[8:12] = decimal(len(data),4)
            header[12] = channels
            header[13:16] = decimal(44100,3)
            target.write_bytes(header+data)
        elif kind == 'aiff':
            comm = struct.pack('>HIH',channels,frames,bits)+bytes.fromhex('400eac44000000000000')
            chunks = b'COMM'+struct.pack('>I',len(comm))+comm
            chunks += b'SSND'+struct.pack('>I',len(data)+8)+bytes(8)+data
            target.write_bytes(b'FORM'+struct.pack('>I',len(chunks)+4)+b'AIFF'+chunks)
        else:
            stride = channels*(bits//8)
            fmt = struct.pack('<HHIIHH',3 if floating else 1,channels,44100,44100*stride,stride,bits)
            target.write_bytes(b'RIFF'+struct.pack('<I',36+len(data))+b'WAVEfmt '+struct.pack('<I',16)+fmt+b'data'+struct.pack('<I',len(data))+data)
        replacement = basename.encode('ascii')
        assert len(replacement) == len(b'BT_cronox18.wav')
        assert fxp.count(b'BT_cronox18.wav') > 0
        (folder/'program.FXP').write_bytes(fxp.replace(b'BT_cronox18.wav',replacement))
        state = dict(au)
        assert au['vstdata'].count(b'BT_cronox18.wav') > 0
        state['vstdata'] = au['vstdata'].replace(b'BT_cronox18.wav',replacement)
        state['name'] = 'CP021 public fixture '+name
        (folder/'program.aupreset').write_bytes(plistlib.dumps(state))
        cases.append({'case':name,'kind':kind,'bits':bits,'channels':channels,
                      'frames':frames,'sample_rate':44100,'filename':basename})
    (output/'manifest.json').write_text(json.dumps({'scope':'generated from supplied public fixture only','cases':cases},indent=2)+'\n')
    return cases


if __name__ == '__main__':
    p = argparse.ArgumentParser()
    p.add_argument('output',type=Path)
    a = p.parse_args()
    print(json.dumps({'cases_generated':len(generate(a.output))}))
