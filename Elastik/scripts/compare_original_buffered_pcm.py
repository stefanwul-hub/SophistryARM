#!/usr/bin/env python3
"""Compare original encoded PCM byte reads and conversion with native C++.

The byte-stream seek/read and diagnostic printing are the only adapted calls.
Original 0x219820, 0x161584 and 0x1619b0 execute as pinned i386 instructions.
Metadata is supplied by the fixture, not an implementation of the WAVE parser.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
from native_probe import NativeProbe

from compare_original_sample_formats import FORMATS, WIDTHS, source_values
from legacy_image import LegacyImage, SHA
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import (UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX,
                               UC_X86_REG_EFLAGS, UC_X86_REG_MXCSR)

READER, IO, VTABLE, OUTPUTS = 0x520000, 0x521000, 0x522000, 0x523000
STORAGE, BUFFER, STACK, RETURN, SEEK, READ = 0x600000, 0x620000, 0x70f000, 0x500400, 0x500700, 0x500710
WAVE_SHA = '3a34c829da83d0b79773927fd2d026479a8038f4f7666c29a745aff2968b342f'


def make_fixture(rng, name, fmt, channel_format, first, frames, capacity,
                 mask=None, max_read=-1, read_ok=1, raw=None, data_offset=13):
    channels = channel_format & 0xff if channel_format & 0x100 else channel_format
    frame_bytes = channels * WIDTHS[fmt]
    if raw is None:
        raw = bytes(rng.getrandbits(8) for _ in range(data_offset))
        raw += source_values(fmt, (first + max(frames, 1) + 8) * channels)
    initial = bytes(rng.getrandbits(8) for _ in range(capacity))
    words = frames + 16
    storage = bytes(rng.getrandbits(8) for _ in range(max(1, channels) * words * 4))
    if mask is None:
        mask = (1 << channels) - 1
    h = [len(raw), fmt, channel_format, first, frames, data_offset, capacity, mask, words, max_read, read_ok]
    assert not frames or capacity >= frame_bytes
    return name, h, raw, initial, storage


def fixtures(wave_path):
    rng = random.Random(0xE1A004B)
    for fmt in FORMATS:
        for channel_format in [1, 2, 0x104]:
            channels = channel_format & 0xff if channel_format & 0x100 else channel_format
            for frames in [0, 1, 17, 65]:
                for buffer_frames in [1, 7, 70]:
                    capacity = buffer_frames * channels * WIDTHS[fmt] + (1 if buffer_frames == 7 else 0)
                    name = f'format-{fmt:02x}-channels-{channel_format:x}-n-{frames}-buffer-{capacity}'
                    yield make_fixture(rng, name, fmt, channel_format, 3, frames, capacity)
    for fmt in [0, 1, 3, 0x10, 0x11, 0x13, 0x43, 0x45]:
        for mask in [0, 1, 2, 5]:
            yield make_fixture(rng, f'null-outputs-{fmt:02x}-{mask}', fmt, 0x104, 1, 65,
                               WIDTHS[fmt] * 4 * 9, mask=mask)
        for ok in [0, 1]:
            for short in [0, 1, WIDTHS[fmt] * 2 - 1]:
                yield make_fixture(rng, f'short-read-{fmt:02x}-{ok}-{short}', fmt, 2, 2, 17,
                                   WIDTHS[fmt] * 2 * 5 + 1, max_read=short, read_ok=ok)
        raw = b'X' * 13 + source_values(fmt, 2 * 19 - 1)
        yield make_fixture(rng, f'partial-eof-{fmt:02x}', fmt, 2, 2, 17,
                           WIDTHS[fmt] * 2 * 23, raw=raw, read_ok=0)
    raw = wave_path.read_bytes()
    if hashlib.sha256(raw).hexdigest() != WAVE_SHA:
        raise ValueError('Unexpected embedded original WAVE fixture')
    if raw[:4] != b'RIFF' or raw[8:12] != b'WAVE':
        raise ValueError('Fixture is not RIFF/WAVE')
    at = 12
    while at + 8 <= len(raw):
        chunk, size = raw[at:at + 4], struct.unpack_from('<I', raw, at + 4)[0]
        if chunk == b'data':
            data_offset, data_size = at + 8, size
            break
        at += 8 + size + (size & 1)
    else:
        raise ValueError('No data chunk in original fixture')
    assert data_size == 176399 * 4
    for first in [0, 57001, 176399 - 257]:
        for frames in [1, 65, 257]:
            yield make_fixture(rng, f'embedded-wave-first-{first}-n-{frames}', 0x10, 2,
                               first, frames, 4 * 13 + 1, raw=raw, data_offset=data_offset)


def compare(binary, runner, prefix, platform, wave_path, persistent=False):
    image = LegacyImage(binary.read_bytes())
    u = Uc(UC_ARCH_X86, UC_MODE_32)
    u.mem_map(0, 0x800000)
    u.mem_write(0, bytes(image.mapped()))
    current = {}

    def unexpected(uc, address, size, user):
        raise ValueError('Unexpected host call at ' + hex(address))

    imports = [item['address'] for item in image.stubs]
    u.hook_add(UC_HOOK_CODE, unexpected, begin=min(imports), end=max(imports) + 4)

    def finish(uc, sp, ret, result=0):
        uc.reg_write(UC_X86_REG_EAX, result)
        uc.reg_write(UC_X86_REG_ESP, sp + 4)
        uc.reg_write(UC_X86_REG_EIP, ret)

    def seek(uc, address, size, user):
        sp = uc.reg_read(UC_X86_REG_ESP)
        ret, obj, position = struct.unpack('<3I', uc.mem_read(sp, 12))
        assert obj == IO and position <= len(current['raw'])
        current['position'] = position
        current['events'].append([1, position, 0, 0])
        finish(uc, sp, ret)

    def read(uc, address, size, user):
        sp = uc.reg_read(UC_X86_REG_ESP)
        ret, obj, destination, count_at = struct.unpack('<4I', uc.mem_read(sp, 16))
        wanted = struct.unpack('<i', uc.mem_read(count_at, 4))[0]
        assert obj == IO and destination == BUFFER and wanted <= current['capacity']
        position = current['position']
        actual = min(wanted, len(current['raw']) - position)
        if current['max_read'] >= 0:
            actual = min(actual, current['max_read'])
        if actual:
            uc.mem_write(destination, current['raw'][position:position + actual])
        current['position'] += actual
        uc.mem_write(count_at, struct.pack('<i', actual))
        current['events'].append([2, wanted, actual, current['ok']])
        finish(uc, sp, ret, current['ok'])

    def diagnostic(uc, address, size, user):
        sp = uc.reg_read(UC_X86_REG_ESP)
        ret, text_at = struct.unpack('<2I', uc.mem_read(sp, 8))
        text = bytes(uc.mem_read(text_at, 160)).split(b'\0', 1)[0]
        if text.startswith(b'Reading sound failed: We wanted to read '):
            wanted, position, actual = struct.unpack('<3i', uc.mem_read(sp + 8, 12))
            current['read_diagnostics'] += 1
            current['events'].append([3, wanted, position, actual])
        else:
            if text == b'GNAudioConvertSampleFormat(): Unsupported input format.': code = 1
            elif text == b'GNAudioConvertSampleFormat(): Unsupported output format.': code = 2
            else: raise ValueError('Unexpected diagnostic: ' + repr(text))
            current['format_diagnostics'] += 1
            current['format_flags'] |= 1 << code
            current['events'].append([4, code, 0, 0])
        finish(uc, sp, ret)

    u.hook_add(UC_HOOK_CODE, seek, begin=SEEK, end=SEEK)
    u.hook_add(UC_HOOK_CODE, read, begin=READ, end=READ)
    u.hook_add(UC_HOOK_CODE, diagnostic, begin=0xab14, end=0xab14)
    u.mem_write(IO, struct.pack('<I', VTABLE))
    u.mem_write(VTABLE + 0x1c0, struct.pack('<I', SEEK))
    u.mem_write(VTABLE + 0x1ac, struct.pack('<I', READ))
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent)
    cases = []
    compared_bytes = frames = read_calls = 0
    for name, h, raw, initial, storage in fixtures(wave_path):
        current.update(raw=raw, capacity=h[6], max_read=h[9], ok=h[10], position=0,
                       events=[], read_diagnostics=0, format_diagnostics=0, format_flags=0)
        channels = h[2] & 0xff if h[2] & 0x100 else h[2]
        u.mem_write(READER, bytes(32))
        u.mem_write(READER + 0xc, struct.pack('<2I', h[6], BUFFER))
        u.mem_write(BUFFER, initial)
        u.mem_write(STORAGE, storage)
        pointers = [STORAGE + i * h[8] * 4 + 32 if h[7] & (1 << i) else 0 for i in range(channels)]
        u.mem_write(OUTPUTS, struct.pack('<' + 'I' * len(pointers), *pointers))
        u.mem_write(STACK, struct.pack('<9I', RETURN, READER, OUTPUTS, h[3], h[4], h[1], h[2], h[5], IO))
        u.reg_write(UC_X86_REG_ESP, STACK)
        u.reg_write(UC_X86_REG_EFLAGS, 2)
        u.reg_write(UC_X86_REG_MXCSR, 0x1f80)
        u.emu_start(0x219820, RETURN, count=1000000)
        if u.reg_read(UC_X86_REG_EIP) != RETURN:
            raise ValueError('Original buffered reader did not return: ' + name)
        header = [current[k] for k in ['read_diagnostics', 'format_diagnostics', 'format_flags']]
        header += [len(current['events']), 0]
        original = struct.pack('<5i', *header)
        original += b''.join(struct.pack('<4i', *event) for event in current['events'])
        original += bytes(u.mem_read(BUFFER, h[6])) + bytes(u.mem_read(STORAGE, len(storage)))
        fixture = struct.pack('<11i', *h) + raw + initial + storage
        process = probe.run(fixture, len(original))
        actual = process.stdout
        if process.returncode or actual != original:
            folder = Path('work/ELA004-native')
            folder.mkdir(parents=True, exist_ok=True)
            for label, data in [('fixture', fixture), ('original', original), ('native', actual), ('stderr', process.stderr)]:
                (folder / ('failing-buffered-' + label + '.bin')).write_bytes(data)
            at = next((i for i, (a, b) in enumerate(zip(actual, original)) if a != b), min(len(actual), len(original)))
            raise ValueError(f'Buffered mismatch {name}; process={process.returncode}, byte={at}, original={original[at:at+4].hex()}, native={actual[at:at+4].hex()}')
        compared_bytes += len(original)
        frames += h[4]
        read_calls += sum(event[0] == 2 for event in current['events'])
        cases.append({'name': name, 'format': h[1], 'channel_format': h[2], 'frames': h[4],
                      'read_diagnostics': current['read_diagnostics'], 'format_diagnostics': current['format_diagnostics'],
                      'byte_io_events': len(current['events']), 'all_bytes_match': True,
                      'sha256': hashlib.sha256(original).hexdigest()})
    probe.close()
    return {'checkpoint': 'ELA004', 'scope': 'Buffered raw sample bytes to planar float32 using original converter',
            'original_i386_sha256': SHA, 'original_function': '0x219820', 'original_function_bytes': 556,
            'reference_execution': 'Original i386 instructions in Unicorn; byte seek/read and diagnostic boundary adapted',
            'compiled_platform': platform, 'persistent_probe_process': persistent, 'automatic_fixture_retries': 0,
            'fixture_count': len(cases), 'requested_frames': frames,
            'byte_read_calls': read_calls, 'compared_bytes': compared_bytes, 'all_cases_match_bit_for_bit': True,
            'embedded_original_wave_sha256': WAVE_SHA, 'embedded_original_wave_cases': 9,
            'wave_container_metadata_supplied_by_fixture': True, 'original_wave_header_parser_executed': False,
            'coverage': ['interleaved channels 1/2/4', 'bounded and non-frame-aligned buffers', 'null output channels',
                         'seek offsets', 'read and format diagnostic traces', 'short/failed reads and reused buffer contents',
                         'original embedded PCM16 WAVE bytes at beginning/middle/end', 'output guards and read buffer mutations'],
            'compressed_sample_codecs_executed': False, 'complete_engine_built': False,
            'macos_audio_unit_validated': False, 'cases': cases}


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary', type=Path)
    p.add_argument('runner', type=Path)
    p.add_argument('--wave', type=Path, required=True)
    p.add_argument('--runner-prefix', action='append', default=[])
    p.add_argument('--persistent-runner', action='store_true', help='All fixtures in one probe process, with fresh buffers for each')
    p.add_argument('--platform', required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    result = compare(a.binary, a.runner, a.runner_prefix, a.platform, a.wave, a.persistent_runner)
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k: result[k] for k in ['fixture_count', 'byte_read_calls', 'compared_bytes', 'all_cases_match_bit_for_bit', 'compiled_platform']}, indent=2))
