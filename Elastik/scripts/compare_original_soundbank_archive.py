#!/usr/bin/env python3
"""Exercise the original ETSoundbank control flow with GNFA and plist results from i386."""

import argparse
import hashlib
import itertools
import json
import struct
from pathlib import Path

from compare_original_archive_open import ArchiveOpenOracle, GNA, ROOT, SOURCE, fixture as archive_fixture
from compare_original_file_archive import ARCHIVE_SHA, BUILTIN, OUT, archive
from compare_original_soundbank import BANK, CSTR, VT, SoundbankOracle, SETTERS
from legacy_image import SHA
from native_probe import NativeProbe
from original_plist_oracle import encode_string
from original_xml_plist_oracle import XmlPropertyListOracle

KEYS = ('identifier', 'title', 'serial', 'color', 'gracePeriode')
GRACE_GUEST = 0x500700
GRACE_RESULT = 0x500730


def snapshot_string(text):
    return b's' + encode_string(text)


def take_text(raw, offset):
    count, = struct.unpack_from('<I', raw, offset)
    end = offset + 4 + count * 2
    return raw[offset + 4:end].decode('utf-16-le', 'surrogatepass'), end


def take_value(raw, offset):
    """Return the end offset and any direct dictionary entries of a plist value."""
    tag = raw[offset:offset + 1]
    offset += 1
    fixed = {b'i': 4, b'q': 8, b'f': 4, b'b': 1, b't': 25}
    if tag in fixed:
        return offset + fixed[tag], None
    count, = struct.unpack_from('<I', raw, offset)
    if tag in (b's', b'd'):
        return offset + 4 + count * (2 if tag == b's' else 1), None
    if tag not in (b'm', b'a'):
        raise ValueError(f'Unknown encoded value {tag!r}')
    entries = {}
    offset += 4
    for _ in range(count):
        if tag == b'm':
            key, offset = take_text(raw, offset)
        end, _ = take_value(raw, offset)
        if tag == b'm':
            entries[key] = raw[offset:end]
        offset = end
    return offset, entries if tag == b'm' else None


class BankPlistOracle(XmlPropertyListOracle):
    def __init__(self, binary):
        super().__init__(binary)
        # Call the real GNString float getter and project its x87 return bits.
        call = b'\xe8' + struct.pack('<i', 0x34496 - (GRACE_GUEST + 9))
        fstp = b'\xd9\x1d' + struct.pack('<I', GRACE_RESULT)
        self.uc.mem_write(GRACE_GUEST, b'\xff\x74\x24\x04' + call + b'\x83\xc4\x04' + fstp + b'\xc3')

    def scanner_init(self, *unused):
        obj, = self.arguments(1)
        scanner = self.reserve(24)
        skip = self.reserve(32)
        self.set_string(skip, self.cstr(0x34026 + 0x292f12).decode('ascii'))
        self.put(scanner, 0x390d88, 0, 0, obj, skip, 0)
        self.finish(scanner)

    def number_float(self, string):
        self.setup(b'', False)
        obj = self.reserve(32)
        self.set_string(obj, string)
        self.call(GRACE_GUEST, obj)
        return bytes(self.uc.mem_read(GRACE_RESULT, 4))


class LinkedSoundbankOracle(SoundbankOracle):
    def __init__(self, binary):
        super().__init__(binary)
        self.archive = ArchiveOpenOracle(binary)
        self.plist = BankPlistOracle(binary)

    def system_path(self, *unused):
        self.source_lookups += 1
        super().system_path()

    def length(self, *unused):
        p, = self.arguments(1)
        self.h[8] = len(take_text(self.objects[self.token(p)], 1)[0])
        super().length()

    def open_archive(self, *unused):
        case = archive_fixture('linked', self.images[self.active], '/Info.plist')
        case['h'][10:12] = [self.flags & 1, (self.flags >> 1) & 1]
        case['h'][4] = int(not self.flags & 4)
        self.archive.setup_open(case)
        self.archive.phase = 'parse'
        self.archive.call_reg(0xe13de, (GNA, SOURCE))
        self.h[24] = self.archive.error
        super().open_archive()

    def member(self, *unused):
        self.paths += 1
        self.archive.phase = 'lookup'
        pointer = self.archive.call_reg(0xe1a68, (GNA, ROOT))
        self.member_path = pointer if self.archive.error == 0 else 0
        self.h[15] = 43 if self.member_path else 0
        self.h[16] = int(bool(self.member_path and self.archive.call_reg(0xe05a2, (self.member_path,))))
        super().member()

    def parse(self, *unused):
        self.h[17:23] = [0] * 6
        guest = self.archive
        path = self.member_path
        length = guest.call_reg(0xe09c0, (path,))
        reader = guest.call_reg(0xe3ff4, (path,))
        if reader and not guest.error:
            count = OUT + 1024 * 1024
            guest.put(count, length)
            ok = guest.call_reg(0xe4172, (reader, OUT, count))
            if ok and not guest.error and guest.word(count) == length:
                data = bytes(guest.uc.mem_read(OUT, length))
                decoded = self.plist.run(data, True)
                if decoded[1] == 2:
                    self.documents += 1
                    end, values = take_value(decoded, 2)
                    assert end == len(decoded) and values is not None
                    self.h[17] = 44
                    for index, key in enumerate(KEYS):
                        if key not in values:
                            continue
                        token = 20 + index + 5 * (self.documents - 1)
                        self.objects[token] = values[key]
                        self.h[18 + index] = token
                    if 'gracePeriode' in values:
                        text, end = take_text(values['gracePeriode'], 1)
                        assert values['gracePeriode'].startswith(b's') and end == len(values['gracePeriode'])
                        self.float_bytes = self.plist.number_float(text)
        super().parse()

    def event(self, *row):
        if row[0] == 21:
            self.diagnostics.append(row[1])

    def execute_linked(self, case):
        _, self.images, self.flags, mode, old_title, operations = case
        self.active = self.paths = self.documents = self.source_lookups = self.constructs = 0
        self.diagnostics, self.frames, self.jumps, self.keys = [], [], {}, {}
        self.refs = [0] * 128
        self.error = 0
        self.objects = {
            i: snapshot_string(text) for i, text in enumerate((
                '/fixture/Source.elastik' if mode != 4 else '', 'old identifier',
                'old serial', 'old title', 'old response', '/old/root', 'old color',
                '/fixture/Fallback.elastik', 'Fallback.elastik',
            ), start=1)
        }
        self.h = [0] * 32
        self.h[9] = 0 if mode == 2 else 41
        self.h[10] = int(mode not in (1, 3))
        self.h[11] = 42 if mode == 1 else 0
        self.h[12] = int(mode == 1)
        self.h[13:15] = [8, 9]
        self.h[23] = 9
        self.uc.mem_write(BANK, bytes(0x100))
        fields = [4 if old_title else 0, 2, 3, 5, 1, 6, 0, 7]
        self.put(BANK + 0xc, *(self.ptr(n) for n in fields))
        self.uc.mem_write(BANK + 0x2c, struct.pack('<2d', 123.5, 987.25))
        for n in range(1, 128):
            self.put(self.ptr(n), VT)
            self.uc.mem_write(CSTR + n * 0x100, b'node\0')
        answer = b''
        for op in operations:
            returned = 0
            if op == 1:
                returned = self.call(0x1aa9c6, BANK)
            elif op == 2:
                self.call(SETTERS[4], BANK, self.word(BANK + 0x1c))
            elif op == 3:
                self.call(0x1a99d2, BANK)
            elif op == 4:
                self.active = 1
            elif op == 5:
                self.call(0x1aa964, BANK, self.ptr(41))
            else:
                raise ValueError(f'Unknown operation {op}')
            assert not self.frames
            cached = self.word(BANK + 0x24)
            counts = [self.token(returned) - 100 if returned else 0, self.token(cached) - 100 if cached else 0,
                      self.constructs, self.paths, self.documents, self.source_lookups]
            answer += struct.pack('<6I', *counts) + bytes(self.uc.mem_read(BANK + 0x2c, 16))
            for field in (0, 1, 2, 3, 4, 5, 7):
                token = self.token(self.word(BANK + 0xc + field * 4))
                answer += b'\1' + self.objects[token] if token else b'\0'
        return answer + struct.pack('<I', len(self.diagnostics)) + bytes(self.diagnostics)


def fixtures(builtin):
    raw = builtin.read_bytes()
    if hashlib.sha256(raw).hexdigest() != ARCHIVE_SHA:
        raise ValueError('Expected the original built-in soundbank')
    xml = b'''<?xml version="1.0"?>
    <plist><dict><key>identifier</key><string>test.xml.bank</string>
    <key>title</key><string>Bank &#xE9;</string><key>color</key><string>blue</string>
    <key>gracePeriode</key><string> -9.25e-2</string><key>ignore</key><array><true/></array>
    </dict></plist>'''
    openstep = b'''{identifier="test.openstep.bank"; title="Example"; serial="demo";
    color=green; gracePeriode="16777217";}'''
    docs = {
        'xml': xml, 'openstep': openstep, 'empty-dict': b'{}',
        'partial': b'{ title = Partial; gracePeriode = "not-a-number"; }',
        'typed-fields': b'{ identifier = (Name,42); title = 7; color = <aabb>; }',
        'bad-xml': b'<plist><dict></plist>', 'bad-openstep': b'{ title = ',
    }
    for (label, text), layout, flags, title in itertools.product(docs.items(), (0, 1), range(4), (0, 1)):
        image = archive([('Info.plist', text, {})], layout=layout)
        yield (f'{label}-layout{layout}-stream{flags}-title{title}', (image, image), flags, 0, title, (1, 1, 2, 1, 3))
    for flags, mode, title in itertools.product(range(4), range(5), (0, 1)):
        yield (f'builtin-stream{flags}-source{mode}-title{title}', (raw, raw), flags, mode, title, (1, 1, 3, 1))
    no_root = archive([
        ('other', b'', {'length': 0x8000000000000001}),
        ('Info.plist', xml, {'parent': 1}),
    ])
    short = archive([('Info.plist', b'{}', {'length': 12})])
    for label, image in [('nested-only', no_root), ('missing', archive([])),
                         ('directory', archive([('Info.plist', b'', {'length': 0x8000000000000001})])),
                         ('short-read', short), ('bad-header', b'not an archive')]:
        for flags, old in itertools.product(range(4), (0, 1)):
            yield (f'{label}-stream{flags}-title{old}', (image, raw), flags, 0, old, (1, 1, 4, 1, 2, 1, 3))
    for flags in range(4, 8):
        yield (f'no-reader-{flags}', (raw, raw), flags, 0, 1, (1, 1, 2, 1, 3))
    for flags in range(4):
        second = archive([('Info.plist', xml, {})])
        yield (f'changed-source-{flags}', (raw, second), flags, 0, 0, (1, 4, 1, 5, 1, 1, 3))


def compare(binary, runner, prefix, platform, builtin):
    oracle = LinkedSoundbankOracle(binary)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    cases = []
    for case in fixtures(builtin):
        name, images, flags, mode, title, ops = case
        try:
            expected = oracle.execute_linked(case)
        except Exception as error:
            raise RuntimeError(f'Original bank failed {name}') from error
        payload = struct.pack('<6I', *(len(img) for img in images), flags, mode, title, len(ops))
        actual = probe.run(payload + b''.join(images) + bytes(ops), len(expected))
        if actual.returncode or actual.stdout != expected:
            difference = next((i for i, (a, b) in enumerate(zip(expected, actual.stdout)) if a != b),
                              min(len(expected), len(actual.stdout)))
            raise ValueError(f'{name}: mismatch at {difference}, {expected[difference:difference+32].hex()} '
                             f'vs {actual.stdout[difference:difference+32].hex()}, {actual.stderr!r}')
        cases.append({'name': name, 'bytes': len(expected), 'sha256': hashlib.sha256(expected).hexdigest()})
    probe.close()
    return {
        'checkpoint': 'ELA016', 'platform': platform, 'original_i386_sha256': SHA,
        'fixture_count': len(cases), 'result_bytes': sum(row['bytes'] for row in cases),
        'original_bank_archive_open_lookup_and_parser_bodies_executed': True,
        'original_pipeline_uses_three_vms': True, 'synthetic_raw_io_and_host_object_runtime': True,
        'grace_actual_i386_string_to_float_and_float_to_double': True,
        'all_output_bytes_match': True, 'automatic_case_retries': 0,
        'protected_banks_tested': False, 'audio_unit_built': False, 'cases': cases,
    }


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary', type=Path)
    p.add_argument('runner', type=Path)
    p.add_argument('--runner-prefix', action='append', default=[])
    p.add_argument('--platform', required=True)
    p.add_argument('--builtin', type=Path, default=BUILTIN)
    p.add_argument('--output', type=Path, required=True)
    args = p.parse_args()
    result = compare(args.binary, args.runner, args.runner_prefix, args.platform, args.builtin)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({key: result[key] for key in ('fixture_count', 'result_bytes', 'platform')}))
