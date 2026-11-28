#!/usr/bin/env python3
"""Differential GNArchiver state bodies: genuine i386 writer and reader vs native."""

import argparse
import hashlib
import itertools
import json
import random
import struct
from pathlib import Path

from inspect_state_archive import inspect_header
from legacy_image import SHA
from native_probe import NativeProbe
from original_state_archive_oracle import StateArchiveReaderOracle, CLASS_LAYOUTS


def string(text, unicode=False, mutable=False):
    raw = text.encode('utf-16-le', 'surrogatepass') if unicode else text.encode('ascii')
    return 'GNString', (5 if unicode else 0, raw, mutable)


def number(kind, bits):
    size = {'i': 4, 'b': 1, 'f': 4, 'd': 8, 'l': 8}[kind]
    return 'GNNumber', (kind, bits.to_bytes(size, 'little'))


def list_of(refs, weak=False, nullable=False):
    return 'GNList', (weak, nullable, refs)


def fixtures():
    # GNKeyValueArchiver envelope shape seen at 0x155546 and 0x155396.
    # Test fields/values are synthetic and never taken from a preset.
    key_value = [
        ('GNDictionary', (2, 3)), list_of([4]), list_of([5]), string('objects'),
        list_of([6, 7]), ('GNDictionary', (8, 9)), ('GNDictionary', (10, 11)),
        list_of([12, 13, 14]), list_of([15, 16, 7]),
        list_of([12, 13, 17]), list_of([18, 19, 20]),
        string('@id'), string('@isa'), string('_mapping'), number('i', 0),
        string('ETProgram'), string('name'), number('i', 1),
        string('ETKeyMapping'), string('Échantillon 🎵', unicode=True),
    ]
    yield 'key-value-envelope', key_value, None, [(1, 'objects'), (6, '@id'), (6, '@isa'), (6, '_mapping'),
                                                  (7, 'name'), (7, 'missing'), (0, '@id')]
    aliases = [
        ('GNDictionary', (2, 3)), list_of([4, 5, 4]), list_of([1, 0, 6], nullable=True),
        string('self'), string('東京', unicode=True), list_of([1, 6, 0], weak=True, nullable=True),
    ]
    yield 'aliases-nulls-cycles', aliases, ['GNString', 'GNList', 'GNDictionary'], [
        (1, 'self'), (1, '東京'), (1, 'missing'), (3, 'self'), (999, 'self')]
    for weak, nullable in itertools.product((False, True), repeat=2):
        yield f'empty-list-{weak}-{nullable}', [list_of([], weak, nullable)], None, []
    yield 'empty-dictionary', [('GNDictionary', (2, 3)), list_of([]), list_of([])], None, [(1, 'missing')]
    yield 'empty-data', [('GNData', b'')], None, []

    for n in range(1, 256):
        yield f'legacy-byte-{n}', [('GNString', (0, bytes([n]), bool(n & 1)))], None, []
    for text, mutable in itertools.product(('', 'Café', '東京', 'A\0B', '🎹', '\ud800X', '\udc00'), (False, True)):
        yield f'utf16-{text.encode("unicode_escape").hex()}-{mutable}', [string(text, True, mutable)], None, []

    edge_bits = {
        'i': [0, 1, 0x7fffffff, 0x80000000, 0xffffffff],
        'b': [0, 1],
        'f': [0, 0x80000000, 1, 0x3f000000, 0x7f800000, 0xff800000, 0x7fc12345],
        'd': [0, 0x8000000000000000, 1, 0x3fe0000000000000, 0x7ff0000000000000, 0x7ff8000000012345],
        'l': [0, 0x123456789abcdef0, 0x8000000000000000, 0xffffffffffffffff],
    }
    for kind, values in edge_bits.items():
        for bits in values:
            yield f'number-{kind}-{bits:x}', [number(kind, bits), string('next')], None, []

    for version in range(3):
        yield f'older-list-{version}', [list_of([1], True, True)], None, []
        yield f'older-string-{version}', [string('legacy', mutable=True)], None, []
    for version, kind in itertools.product((0, 1), ('i', 'b')):
        yield f'older-number-{version}-{kind}', [number(kind, 1)], None, []
    yield 'utf16-big-endian', [string('日本🎹', unicode=True)], None, []

    rng = random.Random(0xe1a017)
    for i in range(80):
        count = rng.randrange(1, 28)
        items = [list_of([rng.randint(0, count) for _ in range(count)], weak=bool(i & 1), nullable=True)]
        for _ in range(count - 1):
            kind = rng.choice(('text', 'bytes', 'i', 'f', 'd', 'l', 'b'))
            if kind == 'text':
                item = string(rng.choice(('synthetic', '日本', 'École')), True)
            elif kind == 'bytes':
                item = ('GNData', rng.randbytes(rng.randrange(192)))
            else:
                width = {'i': 32, 'f': 32, 'd': 64, 'l': 64, 'b': 1}[kind]
                bits = rng.getrandbits(width)
                # Quiet any random NaN before the x87 reference loads the value.
                if kind == 'f' and bits & 0x7fffffff > 0x7f800000:
                    bits |= 1 << 22
                if kind == 'd' and bits & 0x7fffffffffffffff > 0x7ff0000000000000:
                    bits |= 1 << 51
                item = number(kind, bits)
            items.append(item)
        order = list(dict.fromkeys(name for name, _ in items))
        rng.shuffle(order)
        yield f'mixed-graph-{i}', items, order, []


def compatible_wire(name, raw):
    """Construct supported historical variants from current writer output."""
    if name.startswith(('older-list-', 'older-string-', 'older-number-')):
        version = int(name.split('-')[2])
        end = inspect_header(raw)['body_offset']
        body = raw[end:]
        if name.startswith('older-list'):
            body = body[4 if version < 2 else 2:]
        elif name.startswith('older-string') and version < 2:
            body = body[5:]
        assert raw[15:16] == b'i'
        return raw[:16] + struct.pack('>i', version) + raw[20:end] + body
    if name == 'utf16-big-endian':
        end = inspect_header(raw)['body_offset']
        body = raw[end:]
        assert body[11:13] == b'\xff\xfe'
        chars = body[19:-2]
        swapped = b''.join(chars[i:i + 2][::-1] for i in range(0, len(chars), 2))
        return raw[:end] + body[:11] + b'\xfe\xff' + body[13:19] + swapped + body[-2:]
    return raw

def input_bytes(raw, queries=()):
    result = struct.pack('<2I', len(raw), len(queries)) + raw
    for ref, key in queries:
        units = key.encode('utf-16-le', 'surrogatepass')
        result += struct.pack('<2I', ref, len(units) // 2) + units
    return result


def present(value):
    return b'\0' if value is None else b'\1' + struct.pack('<I', value)


def find_key(objects, ref, key):
    if not 1 <= ref <= len(objects) or objects[ref - 1][0] != 'GNDictionary':
        return None
    keys, values = objects[ref - 1][1]
    if not keys or not values:
        return None
    key_list, value_list = objects[keys - 1], objects[values - 1]
    if key_list[0] != 'GNList' or value_list[0] != 'GNList':
        return None
    keys, values = key_list[1][2], value_list[1][2]
    if len(keys) != len(values):
        return None
    wire_key = key.encode('utf-16-le', 'surrogatepass')
    for index, key_ref in enumerate(keys):
        if key_ref and objects[key_ref - 1][0] == 'GNString' and objects[key_ref - 1][1][2] == wire_key:
            return values[index]
    return None


def expected(raw, head, objects, queries):
    result = struct.pack('<BIII', 0, 0, len(raw), len(head['classes']))
    for cls in head['classes']:
        name = cls['name'].encode('ascii')
        result += struct.pack('<iI', cls['version'], len(name)) + name
    result += struct.pack('<I', len(objects))
    ids = {cls['name']: cls['number'] for cls in head['classes']}
    for name, value in objects:
        result += struct.pack('<I', ids[name])
        if name == 'GNDictionary':
            result += b'm' + struct.pack('<2I', *value)
        elif name == 'GNList':
            weak, nullable, items = value
            result += b'a' + struct.pack('<BBI', weak, nullable, len(items)) + struct.pack('<' + 'I' * len(items), *items)
        elif name == 'GNString':
            encoding, mutable, text = value
            result += b's' + struct.pack('<iBI', encoding, mutable, len(text) // 2) + text
        elif name == 'GNNumber':
            kind, bits, payload = value
            result += b'n' + kind.encode('ascii') + struct.pack('<BQ', payload, bits)
        else:
            result += b'd' + struct.pack('<I', len(value)) + value
    return result + b''.join(present(find_key(objects, ref, key)) for ref, key in queries)


def reject(probe, raw, allowed, label):
    actual = probe.run(input_bytes(raw), 9)
    if actual.returncode or len(actual.stdout) != 9 or actual.stdout[0] not in allowed:
        raise ValueError(f'{label}: native decoder did not reject as expected ({actual.stdout.hex()})')
    return hashlib.sha256(actual.stdout).hexdigest()


def compare(binary, runner, prefix, platform):
    oracle = StateArchiveReaderOracle(binary)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    cases, invalid, tagged, diagnostic_counts = [], [], {}, [0, 0]
    for name, objects, class_order, queries in fixtures():
        try:
            raw = oracle.write_archive(objects, class_order)
            diagnostic_counts[0] += oracle.int64_diagnostics
            raw = compatible_wire(name, raw)
            header = inspect_header(raw)
            i386 = oracle.read_archive(raw, header)
            diagnostic_counts[1] += oracle.int64_diagnostics
            want = expected(raw, header, i386, queries)
        except Exception as error:
            raise RuntimeError(f'Original GNArchive fixture failed: {name}') from error
        actual = probe.run(input_bytes(raw, queries), len(want))
        if actual.returncode or actual.stdout != want:
            at = next((i for i, (x, y) in enumerate(zip(want, actual.stdout)) if x != y),
                      min(len(want), len(actual.stdout)))
            raise ValueError(f'{name}: mismatch at byte {at}: expected {want[at:at+24].hex()} '
                             f'found {actual.stdout[at:at+24].hex()} ({actual.stderr!r})')
        if name in ('key-value-envelope', 'empty-data', 'aliases-nulls-cycles'):
            tagged[name] = raw
        cases.append({'name': name, 'objects': len(i386), 'archive_bytes': len(raw),
                      'archive_sha256': hashlib.sha256(raw).hexdigest(),
                      'compared_bytes': len(want), 'result_sha256': hashlib.sha256(want).hexdigest()})

    sample = tagged['key-value-envelope']
    for i in range(len(sample)):
        name = f'truncation-{i}'
        invalid.append({'name': name, 'result_sha256': reject(probe, sample[:i], (1,), name)})
    head = inspect_header(sample)
    mutations = [
        ('archive-version', sample[:1] + struct.pack('>i', 2) + sample[5:], 3),
        ('class-number', sample[:11] + struct.pack('>i', 99) + sample[15:], 4),
        ('invalid-reference', sample[:head['body_offset'] + 1] + struct.pack('>i', 0x7fffffff)
         + sample[head['body_offset'] + 5:], 8),
        ('wrong-tag', sample[:head['body_offset']] + b'b' + sample[head['body_offset'] + 1:], 2),
        ('unknown-class', sample.replace(b'GNDictionary', b'XXDictionary', 1), 6),
        ('trailing-byte', sample + b'x', 12),
    ]
    data = tagged['empty-data']
    offset = inspect_header(data)['body_offset']
    mutations.append(('compressed-data', data[:offset + 1] + struct.pack('>i', 10) + data[offset + 5:], 11))
    for name, raw, error in mutations:
        invalid.append({'name': name, 'result_sha256': reject(probe, raw, (error,), name)})
    probe.close()
    assert diagnostic_counts[0] == diagnostic_counts[1] and diagnostic_counts[0] > 0
    report = {
        'checkpoint': 'ELA017', 'platform': platform, 'original_i386_sha256': SHA,
        'fixture_count': len(cases), 'object_count': sum(r['objects'] for r in cases),
        'compared_bytes': sum(r['compared_bytes'] for r in cases),
        'native_rejection_cases': len(invalid),
        'original_int64_writer_and_reader_diagnostics': diagnostic_counts,
        'original_archive_header_writer_executed': True, 'original_two_pass_body_reader_executed': True,
        'original_object_body_writer_and_reader_classes': sorted(CLASS_LAYOUTS),
        'class_registry_lifecycle_and_allocator_are_bindings': True, 'actual_user_projects_tested': False,
        'cases': cases, 'malformed': invalid,
    }
    return report, tagged['key-value-envelope']


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary', type=Path)
    p.add_argument('runner', type=Path)
    p.add_argument('--runner-prefix', action='append', default=[])
    p.add_argument('--platform', required=True)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--synthetic', type=Path)
    args = p.parse_args()
    report, fixture = compare(args.binary, args.runner, args.runner_prefix, args.platform)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    if args.synthetic:
        args.synthetic.write_bytes(fixture)
    print(json.dumps({key: report[key] for key in ('fixture_count', 'object_count', 'compared_bytes',
                                                  'native_rejection_cases', 'platform')}))
