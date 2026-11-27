#!/usr/bin/env python3
"""Compare original 0x1afed2 multichannel read, clipping and lock/error path."""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct

from compare_original_sample_file import fixture, serialized, OriginalFileOracle, WIDTHS, WAVE_SHA
from legacy_image import SHA
from native_probe import NativeProbe


def multi_fixture(rng, name, *, mask=None, **options):
    case = fixture(rng, name, entry=5, **options)
    channels = case['f'][1] & 255 if case['f'][1] & 0x100 else case['f'][1]
    case['f'][13] = (1 << channels) - 1 if mask is None else mask
    case['h'][6] = max(1, channels)
    case['storage'] = rng.randbytes(max(1, channels) * case['h'][7] * 4)
    return case


def fixtures(wave):
    rng = random.Random(0xE1A0061)
    for channels in [0, 1, 2, 0x104]:
        for known in [False, True]:
            for first in [-20, -1, 0, 16, 258, 259, 260]:
                for count in [0, 1, 17, 65]:
                    yield multi_fixture(rng, f'clip-ch{channels:x}-known{known}-first{first}-n{count}',
                                        channels=channels, known=known, first=first, count=count)
    for fmt in WIDTHS:
        for mask in [0, 1, 2, 3]:
            for separate in [0, 1]:
                yield multi_fixture(rng, f'format-{fmt:x}-mask{mask}-separate{separate}', fmt=fmt,
                                    mask=mask, separate=separate, first=19, count=65)
    for fail in [1, 2, 3, 4]:
        for mask in [0, 1, 2, 3]:
            yield multi_fixture(rng, f'exception-target{fail}-mask{mask}', separate=1,
                                fail=fail, mask=mask, first=17, count=65)
    for ok in [0, 1]:
        for short in [0, 1, 3]:
            yield multi_fixture(rng, f'raw-short-ok{ok}-bytes{short}', max_read=short, read_ok=ok)
    for first in [-30, 259, 260]:
        yield multi_fixture(rng, f'closed-outside-first{first}', first=first, count=17, closed=1)
    raw = wave.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == WAVE_SHA
    at = 12
    while at + 8 <= len(raw):
        size = struct.unpack_from('<I', raw, at + 4)[0]
        if raw[at:at + 4] == b'data': data_offset = at + 8; break
        at += 8 + size + (size & 1)
    else: raise ValueError('No data chunk')
    for first in [0, 57001, 176399 - 17]:
        for mask in [0, 1, 2, 3]:
            yield multi_fixture(rng, f'embedded-wave-first{first}-mask{mask}', first=first, count=65,
                                mask=mask, frames=176399, raw=raw, data_offset=data_offset, cache=False)


def compare(binary, runner, prefix, platform, wave):
    oracle = OriginalFileOracle(binary)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    cases = []; total = reads = 0
    for case in fixtures(wave):
        expected = oracle.execute(case); data = serialized(case)
        actual = probe.run(data, len(expected))
        if actual.returncode or actual.stdout != expected:
            folder = Path('work/ELA006-native'); folder.mkdir(parents=True, exist_ok=True)
            for label, b in [('fixture', data), ('original', expected), ('native', actual.stdout), ('stderr', actual.stderr)]:
                (folder / f'failing-multichannel-{label}.bin').write_bytes(b)
            at = next((i for i, (a, b) in enumerate(zip(expected, actual.stdout)) if a != b), min(len(expected), len(actual.stdout)))
            raise ValueError(f'Multichannel mismatch {case["name"]}: exit={actual.returncode}, byte={at}, original={expected[at:at+4].hex()}, native={actual.stdout[at:at+4].hex()}')
        total += len(expected); reads += sum(t[0] == 6 for t in oracle.trace)
        cases.append({'name':case['name'], 'diagnostics':len(oracle.diagnostics), 'trace_events':len(oracle.trace),
                      'all_bytes_match':True, 'sha256':hashlib.sha256(expected).hexdigest()})
    probe.close()
    return {'checkpoint':'ELA006','scope':'Original multichannel file reader with platform boundaries adapted',
            'original_function':'0x1afed2','original_function_bytes':695,'original_i386_sha256':SHA,
            'compiled_platform':platform,'fixture_count':len(cases),'byte_read_calls':reads,'compared_bytes':total,
            'all_cases_match_bit_for_bit':True,'embedded_original_wave_cases':12,'embedded_original_wave_sha256':WAVE_SHA,
            'automatic_fixture_retries':0,'container_metadata_supplied_by_fixture':True,
            'real_GN_exception_runtime_validated':False,'complete_engine_built':False,'macos_audio_unit_validated':False,'cases':cases}


if __name__ == '__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path)
    p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True)
    p.add_argument('--wave',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    r=compare(a.binary,a.runner,a.runner_prefix,a.platform,a.wave)
    a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n')
    print(json.dumps({k:r[k] for k in ['fixture_count','byte_read_calls','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']},indent=2))
