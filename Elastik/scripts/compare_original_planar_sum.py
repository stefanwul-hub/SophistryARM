#!/usr/bin/env python3
"""Differential test: original complete i386 summing routine vs compiled C++.

Runs only the original 117-byte helper in Unicorn, without engine startup,
host API replacements, authorization changes or original-code patches.
The native program uses tests/PlanarSumProbe.cpp's binary fixture protocol.
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
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_MXCSR, UC_X86_REG_EFLAGS

ENTRY, END = 0x161700, 0x161775
STORAGE, DESTINATIONS, SOURCES, RETURN, STACK = 0x600000, 0x500000, 0x500100, 0x500400, 0x70f000


def fixtures(demo):
    rng = random.Random(0xE1A002)
    edges = [0, 0x80000000, 1, 0x80000001, 0x007fffff, 0x807fffff,
             0x00800000, 0x80800000, 0x3f800000, 0xbf800000, 0x33800000, 0xb3800000]
    for channels in [0, 1, 2, 4, 16]:
        for frames in [0, 1, 7, 32, 257, 1024]:
            for flagged in [False, True]:
                stride = frames + 8
                words = max(16, 2 * max(channels, 1) * stride)
                values = [edges[i % len(edges)] if i % 3 == 0 else
                          struct.unpack('<I', struct.pack('<f', rng.uniform(-4, 4)))[0]
                          for i in range(words)]
                dst = [c * stride for c in range(channels)]
                src = [(channels + c) * stride for c in range(channels)]
                fmt = channels | (0x100 if flagged else 0)
                yield f'channels-{channels}-frames-{frames}-flag-{int(flagged)}', frames, 0x44, fmt, dst, src, struct.pack('<' + 'I' * words, *values)
    for alias in ['self', 'forward-overlap', 'backward-overlap', 'cross-channel']:
        for frames in [1, 31, 256]:
            stride = frames + 8
            values = [rng.uniform(-0.1, 0.1) for _ in range(stride * 4)]
            dst, src = [1, stride + 1], [stride * 2 + 1, stride * 3 + 1]
            if alias == 'self': src = dst[:]
            elif alias == 'forward-overlap': src = [0, stride]
            elif alias == 'backward-overlap': src = [2, stride + 2]
            else: src = [stride + 1, 1]
            yield alias + '-' + str(frames), frames, 0x44, 0x102, dst, src, struct.pack('<' + 'f' * len(values), *values)
    if demo:
        with wave.open(str(demo), 'rb') as w:
            if (w.getnchannels(), w.getsampwidth(), w.getframerate()) != (2, 2, 44100):
                raise ValueError('Expected original stereo PCM16 fixture')
            raw = w.readframes(1024)
        samples = struct.unpack('<' + 'h' * (len(raw) // 2), raw)
        frames = len(samples) // 2
        left = [x / 32768 for x in samples[0::2]]
        right = [x / 32768 for x in samples[1::2]]
        values = left + right + left + right
        yield 'original-builtin-wave-sum-only', frames, 0x44, 2, [0, frames], [2 * frames, 3 * frames], struct.pack('<' + 'f' * len(values), *values)


def compare(binary, runner, prefix, demo, platform):
    image = LegacyImage(binary.read_bytes())
    u = Uc(UC_ARCH_X86, UC_MODE_32)
    u.mem_map(0, 0x800000)
    u.mem_write(0, bytes(image.mapped()))
    cases, compared_words = [], 0
    for name, frames, sample_format, channel_format, destination, source, storage in fixtures(demo):
        channel_count = len(destination)
        u.mem_write(STORAGE, storage)
        u.mem_write(DESTINATIONS, struct.pack('<' + 'I' * channel_count, *(STORAGE + 4 * n for n in destination)))
        u.mem_write(SOURCES, struct.pack('<' + 'I' * channel_count, *(STORAGE + 4 * n for n in source)))
        u.mem_write(STACK, struct.pack('<6I', RETURN, DESTINATIONS, SOURCES, sample_format, frames, channel_format))
        u.reg_write(UC_X86_REG_ESP, STACK)
        u.reg_write(UC_X86_REG_EFLAGS, 2)
        u.reg_write(UC_X86_REG_MXCSR, 0x1f80)
        u.emu_start(ENTRY, RETURN, count=max(1000, frames * channel_count * 15 + 2000))
        if u.reg_read(UC_X86_REG_EIP) != RETURN:
            raise ValueError('Original helper did not return: ' + name)
        original = bytes(u.mem_read(STORAGE, len(storage)))
        fixture = struct.pack('<4I', len(storage) // 4, frames, sample_format, channel_format)
        fixture += struct.pack('<' + 'I' * channel_count, *destination)
        fixture += struct.pack('<' + 'I' * channel_count, *source) + storage
        compiled = subprocess.run(prefix + [str(runner.resolve())], input=fixture,
                                  stdout=subprocess.PIPE, stderr=subprocess.PIPE, check=True).stdout
        if compiled != original:
            first = next((i for i, (a, b) in enumerate(zip(compiled, original)) if a != b), min(len(compiled), len(original)))
            raise ValueError(f'Original/C++ mismatch: {name}, byte {first}')
        compared_words += len(storage) // 4
        cases.append({'name': name, 'frames': frames, 'channels': channel_count,
                      'storage_bytes': len(storage), 'all_storage_bytes_match': True,
                      'sha256': hashlib.sha256(original).hexdigest()})
    return {'checkpoint': 'ELA002', 'scope': 'Complete original planar float32 summing helper only',
            'original_i386_sha256': SHA, 'original_function': hex(ENTRY),
            'original_function_bytes': END - ENTRY,
            'original_function_sha256': hashlib.sha256(image.initial[ENTRY:END]).hexdigest(),
            'translated_source': 'src/OriginalPlanarSum.cpp',
            'compiled_runner_platform': platform,
            'reference_execution': 'Original i386 bytes under Unicorn, MXCSR=0x1f80',
            'fixture_count': len(cases), 'compared_float32_storage_words': compared_words,
            'all_cases_match_bit_for_bit': True,
            'coverage': ['zero-length and channel counts', '1/2/4/16 channels',
                         'channel-format low-byte flag', 'finite audio values',
                         'signed zeros and subnormal operands', 'self and overlapping buffers',
                         'all buffer bytes including guard regions'],
            'nan_infinity_inputs_and_alternate_fp_modes_verified': False,
            'original_engine_initialized': False, 'full_engine_audio_fidelity_verified': False,
            'macos_audio_unit_validated': False, 'cases': cases}


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary', type=Path)
    p.add_argument('runner', type=Path)
    p.add_argument('--runner-prefix', action='append', default=[])
    p.add_argument('--platform', required=True)
    p.add_argument('--demo', type=Path)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    result = compare(a.binary, a.runner, a.runner_prefix, a.demo, a.platform)
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k: result[k] for k in ['fixture_count', 'compared_float32_storage_words', 'all_cases_match_bit_for_bit', 'compiled_runner_platform']}, indent=2))
