#!/usr/bin/env python3
"""Compare keyed Elastik model graph and reflective field dispatch to original i386."""

import argparse
import hashlib
import json
import random
import struct
from pathlib import Path

from compare_original_state_archive import input_bytes, list_of, number, string
from inspect_state_archive import inspect_header
from legacy_image import SHA
from native_probe import NativeProbe
from original_keyed_state_oracle import KeyedStateOracle

ROOT = Path(__file__).resolve().parents[1]


class Fixture:
    def __init__(self):
        self.objects = [None]
        self.strings = {}

    def add(self, value):
        self.objects.append(value)
        return len(self.objects)

    def text(self, value):
        if value not in self.strings:
            self.strings[value] = self.add(string(value, unicode=not value.isascii()))
        return self.strings[value]

    def integer(self, value):
        return self.add(number('i', value & 0xffffffff))

    def dictionary(self, fields, ref=None):
        keys = self.add(list_of([self.text(key) for key, _ in fields]))
        vals = self.add(list_of([value for _, value in fields], nullable=True))
        entry = ('GNDictionary', (keys, vals))
        if ref is None:
            return self.add(entry)
        self.objects[ref - 1] = entry
        return ref

    def record(self, id_, class_, fields):
        return self.dictionary([('@id', self.integer(id_)), ('@isa', self.text(class_)), *fields])

    def envelope(self, refs):
        self.dictionary([('objects', self.add(list_of(refs, nullable=True)))], ref=1)


def layout():
    data = json.loads((ROOT / 'evidence/ELA003/state-model-fields.json').read_text())
    return {c['class']: c['fields'] for c in data['classes']}


def generated_cases(classes):
    rng = random.Random(0xe1a018)
    for case, mappings in enumerate([0, 1, 2, 12, 13, 14, 28] + [rng.randrange(1, 13) for _ in range(33)]):
        f = Fixture()
        n_records = mappings + 3
        ids = list(range(n_records)) if case % 3 == 0 else rng.sample(range(2**31), n_records)
        if case in (1, 4):
            ids[-1] = 0
        instrument, program, keylist, *keymaps = ids
        class_names = ['ETInstrument', 'ETProgram', 'GNList'] + ['ETKeyMapping'] * mappings

        def model_fields(class_name, slot):
            fields = []
            for entry in classes[class_name]:
                name = entry['name'][1:]
                if case and (slot + case) % 7 == 0 and rng.randrange(3) == 0:
                    continue
                kind = entry.get('registration_type_tag')
                ref = None
                if name == 'program':
                    ref = f.integer(program)
                elif name == 'keyMappings':
                    ref = f.integer(keylist)
                elif entry['type'] == 'relationship':
                    ref = f.integer(next(i for i in range(n_records + 1) if i not in ids))
                if ref is not None:
                    fields.append(('@' + name, ref))
                elif kind:
                    bits = {'b': slot % 2, 'i': (0xfffffffc + slot) & 0xffffffff, 'f': 0x3e800000 + slot}
                    fields.append((name, f.add(number(kind, bits[kind]))))
                elif entry['declared_class'] == 'GNString':
                    fields.append((name, f.text(f'Boucles/Échantillon {slot} 🎵')))
                else:
                    raise ValueError(f'Unmodeled declaration: {entry}')
            return fields

        # The same numeric literal appears as both a value and a model ID.
        ordered = [
            f.record(instrument, 'ETInstrument', [
                ('@program', f.integer(program)), ('number', f.integer(program)), ('nil', 0),
                ('@collision', f.integer(keylist)), ('collision', f.integer(15)),
                ('otherCollision', f.text('inline')), ('@otherCollision', f.integer(program)),
                ('@@twice', f.integer(instrument)), ('@outside', f.integer(0x7fffffff)),
            ]),
            f.record(program, 'ETProgram', model_fields('ETProgram', 1)),
        ]
        items = [('@' + str(i), f.integer(id_)) for i, id_ in enumerate(keymaps)]
        if mappings:
            items.extend([(str(mappings), f.text('Inline')), ('@' + str(mappings + 1), f.integer(keymaps[0]))])
        rng.shuffle(items)
        ordered.append(f.record(keylist, 'GNList', [('count', f.integer(len(items))), *items]))
        for slot, id_ in enumerate(keymaps, 3):
            ordered.append(f.record(id_, 'ETKeyMapping', model_fields('ETKeyMapping', slot)))
        if case % 2:
            indices = list(range(1, n_records))
            rng.shuffle(indices)
            order = [0] + indices
        else:
            order = list(range(n_records))
        f.envelope([ordered[i] for i in order])
        yield f'keyed-graph-{case:02}', f, [class_names[i] for i in order]


def structural_cases():
    f = Fixture()
    f.objects[0] = string('unkeyed')
    yield 'not-dictionary', f, 1, 1

    f = Fixture()
    f.dictionary([('elsewhere', f.add(list_of([])))], ref=1)
    yield 'missing-objects', f, 1, 1

    f = Fixture()
    f.dictionary([('objects', f.text('not a list'))], ref=1)
    yield 'nonlist-objects', f, 1, 1

    f = Fixture()
    f.envelope([])
    yield 'empty-objects', f, 2, 2

    f = Fixture()
    f.envelope([0])
    yield 'null-record', f, 3, 0

    f = Fixture()
    record = f.text('not a record')
    f.envelope([record])
    yield 'wrong-record-type', f, 3, record

    for bad_id in ('missing', 'negative', 'text', 'float', 'unsupported-long'):
        f = Fixture()
        alternatives = {
            'negative': ('@id', f.integer(-1)),
            'text': ('@id', f.text('0')),
            'float': ('@id', f.add(number('f', 0))),
            'unsupported-long': ('@id', f.add(number('l', 0))),
        }
        record = f.dictionary([('@isa', f.text('ETProgram'))] +
                              ([alternatives[bad_id]] if bad_id in alternatives else []))
        f.envelope([record])
        yield 'id-' + bad_id, f, 4, record

    for bad_class in ('missing', 'empty', 'number', 'embedded-nul'):
        f = Fixture()
        fields = [('@id', f.integer(0))]
        if bad_class != 'missing':
            value = f.integer(1) if bad_class == 'number' else f.add(string(
                '' if bad_class == 'empty' else 'ET\0Program', unicode=True))
            fields.append(('@isa', value))
        record = f.dictionary(fields)
        f.envelope([record])
        yield 'class-' + bad_class, f, 5, record

    f = Fixture()
    first = f.record(0, 'ETProgram', [])
    second = f.record(0, 'ETKeyMapping', [])
    f.envelope([first, second])
    yield 'duplicate-model-id', f, 6, second


def noncanonical_list_cases():
    for bad_count, fields in [
            (None, []), (-1, []), (0x7fffffff, []), (2, [('1', 'gap')]),
            (1, [('00', 'not canonical')]), (1, [('4294967296', 'overflow')]),
            (1, [('18446744073709551616', 'overflow')])]:
        f = Fixture()
        props = [(key, f.text(text)) for key, text in fields]
        if bad_count is not None:
            props.insert(0, ('count', f.integer(bad_count)))
        record = f.record(0, 'GNList', props)
        cls = f.strings['GNList']
        f.envelope([record])
        yield f'list-{bad_count}-{len(props)}-{fields}', f, struct.pack('<B5I', 0, 0, 1, 0, record, cls) + b'\xff' * 4


def expectation(oracle, order, props, class_names):
    result = bytearray(struct.pack('<BII', 0, 0, len(order)))
    queries = []
    reflection = []
    answers = []
    list_members = 0
    by_obj_id = {obj: id_ for id_, obj in oracle.model_ids.items()}
    for i, (model, name, record) in enumerate(zip(order, class_names, oracle.record_ptrs)):
        assert name == oracle.object_types[model]
        class_key = oracle.string(b'@isa')
        class_ref = oracle.binary_refs[oracle.call(0x64626, record, class_key)]
        result += struct.pack('<3I', by_obj_id[model], oracle.binary_refs[record], class_ref)
        if name == 'GNList':
            items = oracle.registries[model]
            result += struct.pack('<I', len(items))
            result += b''.join(oracle.pack_value(ptr) for ptr in items)
            list_members += len(items)
        else:
            result += struct.pack('<I', 0xffffffff)
        for key in props[name]:
            queries.append((i, key))
            expected = oracle.lookup(i, key)
            answers.append(expected)
            if expected[0]:
                reflection.append((model, key, expected[1:]))
        extra = {
            'ETInstrument': ('program', 'number', 'missing', 'outside', 'nil', 'collision',
                             'otherCollision', '@twice', '@@twice', 'id', '@id', 'isa', '@isa'),
            'ETKeyMapping': ('_soundFilePath',),
        }
        for key in extra.get(name, ()):
            queries.append((i, key))
            answers.append(oracle.lookup(i, key))
    assert reflection == [(obj, name, oracle.pack_value(value)) for obj, name, value in oracle.property_trace]
    return bytes(result) + b''.join(answers), queries, len(reflection), list_members


def compare(binary, runner, prefix, platform):
    classes = layout()
    oracle = KeyedStateOracle(binary)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    results = []
    field_names = {}
    try:
        for name, fixture, class_names in generated_cases(classes):
            try:
                raw = oracle.write_archive(fixture.objects)
                order, props = oracle.load_keyed(raw, inspect_header(raw), len(class_names))
                for cls in classes:
                    assert {entry['name'] for entry in classes[cls]} == set(oracle.member_names[cls])
                    assert set(props[cls]) == {name[1:] for name in oracle.member_names[cls]}
                    assert cls not in field_names or field_names[cls] == props[cls]
                    field_names[cls] = props[cls]
                expected, queries, dispatched, members = expectation(oracle, order, props, class_names)
            except Exception as error:
                raise RuntimeError(f'Original keyed fixture failed: {name}') from error
            actual = probe.run(input_bytes(raw, queries), len(expected))
            if actual.returncode or actual.stdout != expected:
                raise ValueError(f'{name}: native/original mismatch: {actual.stderr!r}')
            results.append({'label': name, 'input_sha256': hashlib.sha256(raw).hexdigest(),
                            'result_sha256': hashlib.sha256(expected).hexdigest(), 'compared_bytes': len(expected),
                            'records': len(order), 'queries': len(queries),
                            'reflected_setter_calls': dispatched, 'list_members': members})
        rejected = []
        negatives = [(name, f, struct.pack('<BI', code, obj)) for name, f, code, obj in structural_cases()]
        negatives.extend(noncanonical_list_cases())
        for name, fixture, expected in negatives:
            raw = oracle.write_archive(fixture.objects)
            actual = probe.run(input_bytes(raw), len(expected))
            if actual.returncode or actual.stdout != expected:
                raise ValueError(f'{name}: portable keyed validation failed ({actual.stdout.hex()})')
            rejected.append({'label': name, 'input_sha256': hashlib.sha256(raw).hexdigest(),
                             'result_sha256': hashlib.sha256(expected).hexdigest()})
    finally:
        probe.close()
    totals = {key: sum(row[key] for row in results) for key in (
        'compared_bytes', 'records', 'queries', 'reflected_setter_calls', 'list_members')}
    return {'checkpoint': 'ELA018', 'original_i386_sha256': SHA, 'platform': platform,
            'original_routines_executed': ['0x1b71e2', '0x1b73d8', '0x1b92b4', '0x1489c0', '0x15ecac',
                                           '0x3b05e', '0x21866', '0x315e4', '0x1211b0', '0x1218f2', '0x1219d4', '0x2c7ec'],
            'fixtures': 'synthetic model records encoded with the original foundation archive writer',
            'runtime_bindings': ['allocation and ownership', 'class registry and model construction',
                                 'GN containers and descriptor storage', 'string substring and C library',
                                 'capture reflective setter arguments'],
            'registered_wire_keys_in_reflection_order': field_names, 'totals': totals,
            'differential_cases': results, 'native_validation_cases': rejected,
            'user_state_tested': False, 'model_setters_executed': False, 'audio_unit_built': False}


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('original', type=Path)
    p.add_argument('probe', type=Path)
    p.add_argument('--runner-prefix', action='append', default=[])
    p.add_argument('--platform', required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    report = compare(a.original, a.probe, a.runner_prefix, a.platform)
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_text(json.dumps(report, indent=2, ensure_ascii=False) + '\n')
    print(json.dumps({'compared_cases': len(report['differential_cases']),
                      'native_validation_cases': len(report['native_validation_cases']), **report['totals']}))
