#!/usr/bin/env python3
"""Verify state primitives by executing original i386 typed-stream routines.

Provides initialized in-memory GNData/GNString/GNTypedStream record layouts.
Only libc memcpy is bound; no engine, license or activation path is called.
The generated directory is explicitly a synthetic header, not a real preset.
"""
import argparse
import hashlib
import json
from pathlib import Path
import random
import struct
from legacy_image import LegacyImage, SHA
from inspect_state_archive import inspect_header
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX


def probe(binary, output):
    image = LegacyImage(binary.read_bytes())
    u = Uc(UC_ARCH_X86, UC_MODE_32)
    u.mem_map(0, 0x800000)
    u.mem_write(0, bytes(image.mapped()))
    stream, data, string, result = 0x510000, 0x510100, 0x510200, 0x510300
    buffer, text_buffer, stack, sentinel = 0x600000, 0x650000, 0x70f000, 0x500400
    put = lambda at, value: u.mem_write(at, struct.pack('<I', value & 0xffffffff))
    get = lambda at: struct.unpack('<I', u.mem_read(at, 4))[0]
    put(stream + 0x14, data)
    put(data + 0x18, buffer)
    put(data + 0x1c, 0x10000)
    imports = {item['address']: item['name'] for item in image.stubs}
    memcpy_calls = []

    def bind_libc(uc, address, size, user):
        name = imports.get(address)
        if name != '_memcpy':
            raise ValueError('Unexpected host call in primitive probe: ' + str(name))
        sp = uc.reg_read(UC_X86_REG_ESP)
        ret, dst, src, count = struct.unpack('<4I', uc.mem_read(sp, 16))
        uc.mem_write(dst, bytes(uc.mem_read(src, count)))
        uc.reg_write(UC_X86_REG_EAX, dst)
        uc.reg_write(UC_X86_REG_ESP, sp + 4)
        uc.reg_write(UC_X86_REG_EIP, ret)
        memcpy_calls.append(count)

    u.hook_add(UC_HOOK_CODE, bind_libc, begin=min(imports), end=max(imports) + 4)

    def call(address, *args):
        u.mem_write(stack, struct.pack('<' + 'I' * (len(args) + 1), sentinel, *(v & 0xffffffff for v in args)))
        u.reg_write(UC_X86_REG_ESP, stack)
        u.emu_start(address, sentinel, count=100000)
        if u.reg_read(UC_X86_REG_EIP) != sentinel:
            raise ValueError('Original primitive did not return')
        return u.reg_read(UC_X86_REG_EAX)

    rng = random.Random(0xE1A002)
    integers = [-2147483648, -1, 0, 1, 2, 127, 255, 256, 2147483647]
    integers += [rng.randint(-2147483648, 2147483647) for _ in range(256)]
    for value in integers:
        put(stream + 0x10, 3)
        if call(0x1640f2, stream, value) != 1:
            raise ValueError('Original integer write failed')
        actual = bytes(u.mem_read(buffer + 3, 5))
        if actual != b'i' + struct.pack('>i', value) or get(stream + 0x10) != 8:
            raise ValueError('Original integer encoding differs')
        put(stream + 0x10, 3)
        if call(0x163006, stream, result) != 1 or get(result) != value & 0xffffffff or get(stream + 0x10) != 8:
            raise ValueError('Original integer roundtrip differs')
    strings = ['', 'GNDictionary', 'GNList', 'ETProgram', 'ETKeyMapping']
    for value in strings:
        encoded = value.encode('ascii')
        u.mem_write(text_buffer, encoded + b'\0')
        put(string + 0xc, text_buffer)
        put(string + 0x14, len(encoded))
        put(stream + 0x10, 0)
        if call(0x164748, stream, string) != 1:
            raise ValueError('Original string write failed')
        actual = bytes(u.mem_read(buffer, get(stream + 0x10)))
        if actual != b'*i' + struct.pack('>i', len(encoded)) + encoded:
            raise ValueError('Original string encoding differs')
    put(stream + 0x10, 0)
    for item in [1, 2, 1, 0, 'GNDictionary', 2, 0, 'GNList', 1, 1]:
        if isinstance(item, int):
            assert call(0x1640f2, stream, item) == 1
        else:
            encoded = item.encode('ascii')
            u.mem_write(text_buffer, encoded + b'\0')
            put(string + 0xc, text_buffer)
            put(string + 0x14, len(encoded))
            assert call(0x164748, stream, string) == 1
    header = bytes(u.mem_read(buffer, get(stream + 0x10)))
    decoded = inspect_header(header)
    assert [x['name'] for x in decoded['classes']] == ['GNDictionary', 'GNList']
    assert decoded['object_count'] == 1 and decoded['body_bytes'] == 0
    for malformed in [b'', header[:4], header[:-1], b'x' + header[1:]]:
        try:
            inspect_header(malformed)
        except ValueError:
            pass
        else:
            raise ValueError('Inspector accepted an incomplete directory')
    output.mkdir(parents=True, exist_ok=True)
    (output / 'synthetic-header-only.bin').write_bytes(header)
    report = {'checkpoint': 'ELA002', 'original_i386_sha256': SHA,
        'scope': 'Original typed integer/string state primitives only',
        'integer_roundtrips_against_original': len(integers),
        'string_encodings_against_original': len(strings),
        'integer_wire_format': "ASCII i followed by big-endian signed int32",
        'string_wire_format': "ASCII * followed by typed byte length and cached string bytes",
        'original_functions': ['0x1640f2', '0x163006', '0x164748'],
        'host_binding': 'libc memcpy only', 'memcpy_calls': len(memcpy_calls),
        'constructed_memory_records': ['GNTypedStream', 'GNData', 'GNString'],
        'synthetic_header_sha256': hashlib.sha256(header).hexdigest(),
        'synthetic_header_decoded': decoded,
        'synthetic_header_is_complete_preset': False,
        'actual_user_state_tested': False, 'engine_initialized': False,
        'license_or_activation_path_executed': False, 'old_project_restored': False}
    (output / 'typed-stream-original-comparison.json').write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({k: report[k] for k in ['integer_roundtrips_against_original', 'string_encodings_against_original', 'actual_user_state_tested', 'old_project_restored']}, indent=2))


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary', type=Path)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    probe(a.binary, a.output)
