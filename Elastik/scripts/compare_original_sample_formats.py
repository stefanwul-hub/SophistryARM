#!/usr/bin/env python3
"""Compare original 2922-byte format converter and byte-width routine to C++.

Reference execution uses the pinned original i386 machine bytes. Only the
diagnostic-print boundary is adapted. Compare the entire shared byte store,
including input byte swaps, aliases, strides and untouched guard regions.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
import subprocess
from native_probe import NativeProbe
from legacy_image import LegacyImage, SHA
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX, UC_X86_REG_EFLAGS, UC_X86_REG_MXCSR

FORMATS = [0, 1, 2, 3, 4, 0x10, 0x11, 0x12, 0x13, 0x14, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45]
WIDTHS = dict(zip(FORMATS, [2, 3, 4, 4, 8, 2, 3, 4, 4, 8, 2, 3, 4, 1, 4, 1]))
BASE, STACK, RETURN = 0x600000, 0x70f000, 0x500400


def source_values(fmt, words):
    width = WIDTHS[fmt]
    order = 'big' if fmt < 0x10 else 'little'
    patterns = {
        1: [0, 1, 127, 128, 254, 255],
        2: [0, 1, 0x7fff, 0x8000, 0xffff, 0x4000, 0xc000],
        3: [0, 1, 0x7fffff, 0x800000, 0xffffff, 0x400000, 0xc00000],
        4: [0, 1, 0x7fffffff, 0x80000000, 0xffffffff, 0x40000000, 0xc0000000],
        8: [0, 1, 0x3ff0000000000000, 0xbff0000000000000],
    }[width]
    if fmt in [3, 0x13, 0x44]:
        patterns = [0, 0x80000000, 0x3f800000, 0xbf800000, 0x3f000000, 0xbf000000,
                    0x40000000, 0xc0000000, 1, 0x80000001, 0x7fffff, 0x7f800000,
                    0xff800000, 0x7fc12345, 0xffc23456, 0x7f812345, 0x4f000000]
    return b''.join(patterns[i % len(patterns)].to_bytes(width, order) for i in range(words))


def fixtures():
    rng = random.Random(0xE1A004)
    serial = 0
    for source in FORMATS:
        for target in FORMATS:
            for count in [0, 1, 2, 17, 65]:
                serial += 1
                a, b, c, d = [(1, 0, 1, 0), (2, 1, 3, 2), (4, 3, 2, 1), (1, 0, 0, 0)][serial % 4]
                input_words = b + max(1, count) * max(a, 1) + 8
                output_words = d + max(1, count) * max(c, 1) + 8
                payload = source_values(source, input_words)
                src = 16; dst = src + len(payload) + 32
                storage = bytearray(rng.getrandbits(8) for _ in range(dst + output_words * WIDTHS[target] + 16))
                storage[src:src + len(payload)] = payload
                h = [len(storage), src, dst, source, a, b, target, c, d, 0, count]
                yield f'matrix-{source:02x}-{target:02x}-n-{count}-stride-{a}-{c}', h, bytes(storage)
    for source, target in [(x, x) for x in FORMATS] + [(0x10, 0x44), (0x44, 0x10), (0, 0x44), (3, 0x44), (0x11, 0x44), (0x44, 1)]:
        for delta in [0, 1, -1]:
            count = 17; src = 32; dst = src + delta
            size = max(WIDTHS[source], WIDTHS[target]) * (count + 8) + 80
            storage = bytearray(rng.getrandbits(8) for _ in range(size))
            data = source_values(source, count + 4); storage[src:src + len(data)] = data
            yield f'alias-{source:02x}-{target:02x}-delta-{delta}', [size, src, dst, source, 1, 0, target, 1, 0, 1, count], bytes(storage)
    for source, target in [(0x10, 0x44), (0x44, 0x10), (0x45, 0x44), (0x44, 0x43)]:
        count = 17; src = 32; dst = 256
        storage = bytearray(rng.getrandbits(8) for _ in range(512))
        data = source_values(source, count); storage[src:src + len(data)] = data
        yield f'negative-stride-{source:02x}-{target:02x}', [512, src, dst, source, -1, count - 1, target, -1, count - 1, 2, count], bytes(storage)


def compare(binary, runner, prefix, platform, persistent=False):
    image = LegacyImage(binary.read_bytes())
    u = Uc(UC_ARCH_X86, UC_MODE_32); u.mem_map(0, 0x800000); u.mem_write(0, bytes(image.mapped()))
    current = {}

    def unexpected(uc, address, size, user):
        raise ValueError('Unexpected host call at ' + hex(address))

    imports = [item['address'] for item in image.stubs]
    u.hook_add(UC_HOOK_CODE, unexpected, begin=min(imports), end=max(imports) + 4)

    def diagnostic(uc, address, size, user):
        sp = uc.reg_read(UC_X86_REG_ESP); ret, text_at = struct.unpack('<2I', uc.mem_read(sp, 8))
        text = bytes(uc.mem_read(text_at, 128)).split(b'\0', 1)[0]
        if text == b'GNAudioConvertSampleFormat(): Unsupported input format.': current['errors'] |= 2
        elif text == b'GNAudioConvertSampleFormat(): Unsupported output format.': current['errors'] |= 4
        else: raise ValueError('Unexpected original diagnostic')
        uc.reg_write(UC_X86_REG_EAX, 0); uc.reg_write(UC_X86_REG_ESP, sp + 4); uc.reg_write(UC_X86_REG_EIP, ret)

    u.hook_add(UC_HOOK_CODE, diagnostic, begin=0xab14, end=0xab14)

    def call(address, *args):
        u.mem_write(STACK, struct.pack('<' + 'I' * (len(args) + 1), RETURN, *(v & 0xffffffff for v in args)))
        u.reg_write(UC_X86_REG_ESP, STACK); u.reg_write(UC_X86_REG_EFLAGS, 2); u.reg_write(UC_X86_REG_MXCSR, 0x1f80)
        u.emu_start(address, RETURN, count=50000)
        if u.reg_read(UC_X86_REG_EIP) != RETURN: raise ValueError('Original converter did not return')
        return u.reg_read(UC_X86_REG_EAX)

    probe = NativeProbe(prefix + [str(runner.resolve())], persistent)
    cases = []; total_bytes = 0
    for name, h, data in fixtures():
        current.update(name=name, errors=0)
        u.mem_write(BASE, data)
        input_width = call(0x161584, h[3]); output_width = call(0x161584, h[6])
        call(0x1619b0, BASE + h[1], h[3], h[4], h[5], BASE + h[2], h[6], h[7], h[8], h[10])
        original = struct.pack('<3I', input_width, output_width, current['errors']) + bytes(u.mem_read(BASE, len(data)))
        fixture = struct.pack('<11i', *h) + data
        process = probe.run(fixture, len(original))
        actual = process.stdout
        if process.returncode or actual != original:
            folder = Path('work/ELA004-native'); folder.mkdir(parents=True, exist_ok=True)
            (folder / 'failing-format-fixture.bin').write_bytes(fixture)
            (folder / 'failing-format-original.bin').write_bytes(original)
            (folder / 'failing-format-native.bin').write_bytes(actual)
            at = next((i for i, (a, b) in enumerate(zip(actual, original)) if a != b), min(len(actual), len(original)))
            raise ValueError(f'Format mismatch {name}; process={process.returncode}, byte={at}, original={original[at:at+4].hex()}, native={actual[at:at+4].hex()}')
        total_bytes += len(data)
        cases.append({'name': name, 'input_format': h[3], 'output_format': h[6], 'samples': h[10],
                      'diagnostics': current['errors'], 'all_storage_bytes_match': True, 'sha256': hashlib.sha256(original).hexdigest()})
    probe.close()
    return {'checkpoint': 'ELA004', 'scope': 'Original generic sample converter, widths, byte swaps and integer conversion data effects',
            'original_i386_sha256': SHA, 'original_function': '0x1619b0', 'original_function_bytes': 2922,
            'original_byte_width_function': '0x161584', 'original_byte_width_bytes': 128,
            'reference_execution': 'Original i386 in Unicorn, MXCSR=0x1f80; only diagnostic print adapted',
            'compiled_platform': platform, 'persistent_probe_process': persistent, 'automatic_fixture_retries': 0, 'format_codes_tested': FORMATS,
            'float64_unsupported_like_original': True, 'fixture_count': len(cases), 'compared_storage_bytes': total_bytes,
            'all_cases_match_bit_for_bit': True,
            'coverage': ['format matrix', 'signed/unsigned integer limits', 'float32 NaN/Inf/subnormals/signed zero', 'source input mutations', 'strides and channel offsets', 'aliases and overlaps', 'untouched guards', 'unsupported float64 diagnostics'],
            'fp_exception_status_registers_compared': False, 'complete_engine_built': False, 'macos_audio_unit_validated': False, 'cases': cases}


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary', type=Path); p.add_argument('runner', type=Path)
    p.add_argument('--runner-prefix', action='append', default=[]); p.add_argument('--platform', required=True)
    p.add_argument('--persistent-runner', action='store_true', help='All fixtures in one probe process, with fresh buffers for each')
    p.add_argument('--output', type=Path, required=True); a = p.parse_args()
    r = compare(a.binary, a.runner, a.runner_prefix, a.platform, a.persistent_runner)
    a.output.parent.mkdir(parents=True, exist_ok=True); a.output.write_text(json.dumps(r, indent=2) + '\n')
    print(json.dumps({k:r[k] for k in ['fixture_count','compared_storage_bytes','all_cases_match_bit_for_bit','compiled_platform']}, indent=2))
