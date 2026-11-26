#!/usr/bin/env python3
"""Compare complete original voice-chunk DSP and cursor with native C++.

The decoded sample-file provider (original API 0x1f0c92) supplies fixture PCM.
All chunk DSP, loop decisions, fades, cursor and original field getters run
as original i386 bytes. File codecs, banks, pitch/cache and full AU are outside
this comparison. No activation or license path is run.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
import wave
from legacy_image import LegacyImage, SHA
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX, UC_X86_REG_EFLAGS, UC_X86_REG_MXCSR

VOICE, KEY, ASSET, MODEL = 0x520000, 0x521000, 0x522000, 0x523000
RANGE, NEXT, BUFFER, STACK, RETURN = 0x524000, 0x524100, 0x600000, 0x70f000, 0x500400


def sources(demo):
    rng = random.Random(0xE1A003)
    frames = 1024
    values = [rng.uniform(-0.8, 0.8) for _ in range(frames * 2)]
    yield 'generated-planar-pcm', frames, struct.pack('<' + 'f' * len(values), *values)
    if demo:
        with wave.open(str(demo), 'rb') as w:
            if (w.getnchannels(), w.getsampwidth(), w.getframerate()) != (2, 2, 44100):
                raise ValueError('Expected original built-in stereo PCM16 WAV')
            raw = w.readframes(4096)
        pcm = struct.unpack('<' + 'h' * (len(raw) // 2), raw)
        frames = len(pcm) // 2
        values = [v / 32768 for v in pcm[::2]] + [v / 32768 for v in pcm[1::2]]
        yield 'builtin-wave-first-4096-frames', frames, struct.pack('<' + 'f' * len(values), *values)


def fixtures(demo):
    rng = random.Random(0xE1A003)
    default_in, default_out = [1.0, 1.0, 0.0] * 2, [0.0, 1.0, 0.0] * 2
    serial = 0
    for source_name, frames, source in sources(demo):
        for first, last in [(0, frames - 1), (120, frames - 160), (frames - 160, 120)]:
            for looping in [0, 1]:
                for direction in [0, 1]:
                    positions = ([first, max(first, last - 110), last] if first < last else [first, frames - 1, 0, last]) if direction == 0 else ([last, min(last, first + 80), first] if first < last else [last, 0, frames - 1, first])
                    for position in sorted(set(positions)):
                        for requested in [0, 1, 2, 3, 31, 100, 128, 257]:
                            for channel in [0, 1]:
                                serial += 1
                                storage = [rng.uniform(-0.01, 0.01) for _ in range(requested + 16)]
                                h = [frames, 2, len(storage), position, requested, channel, int(serial % 3 != 0), first, last, -7, direction, looping, serial & 1]
                                yield f'{source_name}-loop-{first}-{last}-mode-{looping}-dir-{direction}-pos-{position}-n-{requested}-ch-{channel}', h, default_in + default_out, source, struct.pack('<' + 'f' * len(storage), *storage)
        ramp_sets = [
            ([1.0, 0.0, 0.01], [0.0, 1.0, 0.0]),
            ([1.0, 1.0, 0.0], [0.0, 1.0, -0.01]),
            ([1.0, 0.0, 0.01], [0.0, 1.0, -0.01]),
            ([0.25, 0.1, 0.03], [0.0, 1.0, 0.0]),
            ([0.5, 0.7, -0.03125], [0.0, 1.0, -0.03125]),
            ([1.0, 1.0, 0.0], [0.5, 0.1, 0.2]),
        ]
        for index, (fade_in, fade_out) in enumerate(ramp_sets):
            for direction in [0, 1]:
                for channel in [0, 1]:
                    for released in [0, 1]:
                        for requested in [1, 2, 31, 101, 256]:
                            position = 300 if direction == 0 else 700
                            h = [frames, 2, requested + 16, position, requested, channel, 1, 120, frames - 160, -7, direction, 1, released]
                            ramps = fade_in * 2 + fade_out * 2
                            storage = struct.pack('<' + 'f' * (requested + 16), *([0.012345] * (requested + 16)))
                            yield f'{source_name}-ramp-{index}-dir-{direction}-ch-{channel}-released-{released}-n-{requested}', h, ramps, source, storage


def compare(binary, runner, prefix, demo, platform):
    image = LegacyImage(binary.read_bytes())
    u = Uc(UC_ARCH_X86, UC_MODE_32)
    u.mem_map(0, 0x800000)
    u.mem_write(0, bytes(image.mapped()))
    current = {}
    put = lambda at, value: u.mem_write(at, struct.pack('<I', value & 0xffffffff))
    get = lambda at: struct.unpack('<I', u.mem_read(at, 4))[0]

    def unexpected(uc, address, size, user):
        raise ValueError('Unexpected host or diagnostic call ' + hex(address) + ': ' + current['name'])

    imports = [item['address'] for item in image.stubs]
    u.hook_add(UC_HOOK_CODE, unexpected, begin=min(imports), end=max(imports) + 4)
    u.hook_add(UC_HOOK_CODE, unexpected, begin=0xab14, end=0xab14)

    def provider(uc, address, size, user):
        sp = uc.reg_read(UC_X86_REG_ESP)
        ret, asset, destination, channel, start, count, a, b = struct.unpack('<6I2d', uc.mem_read(sp, 40))
        h = current['h']; frames = h[0]
        if asset != ASSET or channel >= 2 or start > frames or count > frames - start or a != 100.0 or b != 100.0:
            raise ValueError(f'Invalid fixture provider request {channel,start,count,a,b}: ' + current['name'])
        begin = (channel * frames + start) * 4
        uc.mem_write(destination, current['source'][begin:begin + count * 4])
        current['reads'].append([channel, start, count])
        uc.reg_write(UC_X86_REG_EAX, 1)
        uc.reg_write(UC_X86_REG_ESP, sp + 4)
        uc.reg_write(UC_X86_REG_EIP, ret)

    u.hook_add(UC_HOOK_CODE, provider, begin=0x1f0c92, end=0x1f0c92)
    cases = []
    total_samples = 0
    for name, h, ramps, source, storage in fixtures(demo):
        current.update(name=name, h=h, source=source, reads=[])
        for at, size in [(VOICE, 0x140), (KEY, 0x120), (ASSET, 0x40), (MODEL, 0x80)]:
            u.mem_write(at, bytes(size))
        put(VOICE + 0x98, KEY); put(KEY + 0x8c, ASSET); put(ASSET + 0xc, MODEL); put(MODEL + 0x24, h[0])
        put(VOICE + 0x9c, h[7]); put(VOICE + 0xa0, h[8]); put(VOICE + 0xb0, h[9]); put(KEY + 0x5c, h[10]); put(KEY + 0x58, h[11]); u.mem_write(VOICE + 0x91, bytes([h[12]]))
        u.mem_write(VOICE + 0x110, struct.pack('<6f', *ramps[:6])); u.mem_write(VOICE + 0xf8, struct.pack('<6f', *ramps[6:]))
        put(RANGE, 0xffffffff); put(RANGE + 4, 0xffffffff); put(NEXT, 0x12345678)
        u.mem_write(BUFFER, storage)
        u.mem_write(STACK, struct.pack('<8I', RETURN, VOICE, BUFFER + 32, h[5], h[3], h[4], NEXT if h[6] else 0, RANGE))
        u.reg_write(UC_X86_REG_ESP, STACK); u.reg_write(UC_X86_REG_EFLAGS, 2); u.reg_write(UC_X86_REG_MXCSR, 0x1f80)
        u.emu_start(0x152664, RETURN, count=max(20000, h[4] * 100 + 10000))
        if u.reg_read(UC_X86_REG_EIP) != RETURN:
            raise ValueError('Original reader did not return: ' + name)
        original = struct.pack('<5I', u.reg_read(UC_X86_REG_EAX), get(NEXT), get(RANGE), get(RANGE + 4), get(VOICE + 0xb0))
        original += bytes(u.mem_read(VOICE + 0x110, 24)) + bytes(u.mem_read(VOICE + 0xf8, 24)) + bytes(u.mem_read(BUFFER, len(storage)))
        fixture = struct.pack('<13i12f', *h, *ramps) + source + storage
        process = subprocess.run(prefix + [str(runner.resolve())], input=fixture, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        if process.returncode != 0:
            Path('work/ELA003-native/failing-process-fixture.bin').write_bytes(fixture)
            Path('work/ELA003-native/failing-process-stderr.txt').write_bytes(process.stderr)
            raise ValueError(f'Native runner returned {process.returncode}: {name}')
        actual = process.stdout
        if actual != original:
            first = next((i for i, (a, b) in enumerate(zip(actual, original)) if a != b), min(len(actual), len(original)))
            Path('work/ELA003-native/failing-fixture.bin').write_bytes(fixture)
            Path('work/ELA003-native/failing-original.bin').write_bytes(original)
            Path('work/ELA003-native/failing-native.bin').write_bytes(actual)
            raise ValueError(f'Original/native mismatch {name}, byte {first}, original={original[first:first+4].hex()}, native={actual[first:first+4].hex()}')
        total_samples += get(RANGE + 4)
        cases.append({'name': name, 'read_range': [get(RANGE), get(RANGE + 4)], 'sample_reads': current['reads'], 'all_buffer_and_state_bytes_match': True, 'sha256': hashlib.sha256(original).hexdigest()})
    return {'checkpoint': 'ELA003', 'scope': 'Complete original voice chunk DSP and cursor, decoded fixture sample provider',
            'original_i386_sha256': SHA, 'original_chunk_function': '0x152664', 'original_chunk_function_bytes': 2064,
            'original_cursor_function': '0x15197c', 'original_cursor_function_bytes': 262,
            'original_chunk_sha256': hashlib.sha256(image.initial[0x152664:0x152e74]).hexdigest(),
            'compiled_platform': platform, 'reference_execution': 'Original i386 bytes in Unicorn, MXCSR=0x1f80',
            'original_sample_provider_api_adapted': '0x1f0c92: decoded fixture samples, percentages 100/100',
            'original_file_decoder_or_pitch_cache_executed': False, 'original_engine_initialized': False,
            'fixture_count': len(cases), 'processed_channel_samples': total_samples,
            'all_cases_match_bit_for_bit': True, 'compared': ['all output and guard bytes', 'both channel fade states', 'loop read range', 'optional next cursor', 'cached direction'],
            'full_engine_fidelity_verified': False, 'macos_audio_unit_validated': False, 'cases': cases}


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary', type=Path); p.add_argument('runner', type=Path)
    p.add_argument('--runner-prefix', action='append', default=[]); p.add_argument('--platform', required=True)
    p.add_argument('--demo', type=Path); p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    r = compare(a.binary, a.runner, a.runner_prefix, a.demo, a.platform)
    a.output.parent.mkdir(parents=True, exist_ok=True); a.output.write_text(json.dumps(r, indent=2) + '\n')
    print(json.dumps({k: r[k] for k in ['fixture_count', 'processed_channel_samples', 'all_cases_match_bit_for_bit', 'compiled_platform']}, indent=2))
