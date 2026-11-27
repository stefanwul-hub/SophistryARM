#!/usr/bin/env python3
"""Compare original inst/ACID readers and instrument serializer on native targets."""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
from original_wave_chunks_oracle import ChunkOracle,pack
from native_probe import NativeProbe
from legacy_image import SHA

def fixtures():
    rng=random.Random(0xe1a0091);initial=[-12345,91,-77,63,17,88,-12]
    for n in range(35):
        for null in [0,1]:yield dict(name=f'instrument-length{n}-null{null}',mode=0,raw=rng.randbytes(n),initial=initial,null=null,flags=0)
    for byte in range(256):
        for column in range(7):
            raw=bytearray([60,0,0,0,127,1,127]);raw[column]=byte
            yield dict(name=f'instrument-column{column}-byte{byte}',mode=0,raw=bytes(raw),initial=initial,null=0,flags=0)
    for n in range(35):
        for null in [0,1]:yield dict(name=f'acid-length{n}-null{null}',mode=1,raw=rng.randbytes(n),initial=[255,3,8,77,-3,9,319],null=null,flags=0)
    for flags in [0,1,2,3,4,5,0x80000000,0xffffffff]:
        for root in [0,1,48,60,127,128,32767,-32768,-1]:
            for looping in [0,1,2,255]:
                raw=struct.pack('<IhHIIhhI',flags,root,0x8000,0x7f800001,0x80000001,-7,5,0x7fc01234)
                yield dict(name=f'acid-flags{flags:x}-root{root}-priorloop{looping}',mode=1,raw=raw,initial=[looping,91,63,17,88,-12,319],null=0,flags=0)
    for i in range(80):
        raw=rng.randbytes(24);yield dict(name=f'acid-random{i}',mode=1,raw=raw,initial=[rng.randrange(256),*[rng.randrange(-2**31,2**31) for _ in range(6)]],null=0,flags=0)
    for flags in [0,1,2,3,0x80,0xff,0x100,0xffffffff]:
        for seed in range(32):
            state=[rng.randrange(-2**31,2**31) for _ in range(7)]
            yield dict(name=f'instrument-write-flags{flags:x}-state{seed}',mode=2,raw=b'',initial=state,null=0,flags=flags)

def compare(binary,runner,prefix,platform):
    oracle=ChunkOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=0
    for c in fixtures():
        expected=oracle.execute(c['mode'],c['raw'],c['initial'],c['null'],c['flags']);data=pack([c['mode'],len(c['raw']),c['null'],c['flags']])+pack(c['initial'])+c['raw'];actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA009-native');folder.mkdir(parents=True,exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]: (folder/f'failing-chunks-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)))
            raise ValueError(f'Chunk mismatch {c["name"]}: exit={actual.returncode} byte={at} original={expected[at:at+16].hex()} native={actual.stdout[at:at+16].hex()}')
        cases.append(dict(name=c['name'],mode=c['mode'],all_bytes_match=True,sha256=hashlib.sha256(expected).hexdigest()));total+=len(expected)
    probe.close()
    return dict(checkpoint='ELA009',scope='Original WAVE inst and ACID payload readers plus instrument byte serializer',original_i386_sha256=SHA,compiled_platform=platform,fixture_count=len(cases),compared_bytes=total,all_cases_match_bit_for_bit=True,acid_ignored_float_bits_preserved_as_ignored=True,signed_instrument_char_values_compared=True,acid_looping_state_and_padding_compared=True,GN_data_and_memory_stream_bindings_adapted=True,actual_GN_reference_counting_validated=False,complete_engine_built=False,macos_audio_unit_validated=False,automatic_fixture_retries=0,cases=cases)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:v for k,v in r.items() if k!='cases'},indent=2))
