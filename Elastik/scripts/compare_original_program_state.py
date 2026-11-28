#!/usr/bin/env python3
"""Compare native AU program decoding with synthetic states on the original i386."""

import argparse
import hashlib
import json
import random
import struct
from pathlib import Path

from compare_original_keyed_state import Fixture
from compare_original_state_archive import number, string
from inspect_state_archive import inspect_header
from legacy_image import SHA
from native_probe import NativeProbe
from original_au_class_info_oracle import IDENTITY, ClassInfoOracle
from original_program_state_oracle import ProgramStateOracle


def keyed_list(fixture, id_, member_ids):
    return fixture.record(id_, 'GNList', [
        ('count', fixture.integer(len(member_ids))),
        *(('@' + str(i), fixture.integer(member_id)) for i, member_id in enumerate(member_ids)),
    ])


def generated():
    rng = random.Random(0xe1a019)
    tempos = [
        None, '120.00', '123.75', '145.1266789', '132,50', '   +87.5 bpm', '.125e+3',
        '366E-1', '0', '-0', 'invalid', '70e', '1e39', '2e-100', '77.02999', '  -1.5E+1',
    ] + [f'{rng.randrange(20, 400)}.{rng.randrange(10000):04}' for _ in range(24)]
    for i, tempo in enumerate(tempos):
        f = Fixture()
        base = i * 100
        root_id = base + 90
        mappings_id, parameters_id = base + 1, base + 2
        root_fields = []
        if tempo is not None:
            root_fields.append(('formattedTempo', f.add(string(tempo, unicode=i % 2 == 1))))
        if i > 0:
            root_fields.extend([
                ('autoselect', f.add(number('b', i % 2))),
                ('automapMode', f.integer(i % 3)),
                ('algorithm', f.integer(-i)),
                ('syncUserTempoToFileTempo', f.integer([0, 1, 256, -1][i % 4])),
            ])
        records = []
        if i % 8 != 0:
            keys = []
            for n in range([0, 1, 2, 14][i % 4]):
                key_id = base + 10 + n
                keys.append(key_id)
                fields = []
                if n % 4 != 0:
                    fields.extend([
                        ('midiNote', f.integer([36, 103, 0, -1][n % 4])),
                        ('isUserKey', f.add(number('b', n % 2))),
                        ('@program', f.integer(root_id)),
                        ('soundBankIdentifier', f.text(f'Banque de test {n % 2}')),
                    ])
                    if n % 3 != 0:
                        fields.append(('soundFilePath', f.text(f'boucles/Échantillon {n}.wav')))
                records.append(f.record(key_id, 'ETKeyMapping', fields))
            if keys and i % 5 == 0:
                keys.extend([keys[0], keys[-1]])
            records.append(keyed_list(f, mappings_id, keys))
            root_fields.append(('@keyMappings', f.integer(mappings_id)))
        if i % 6 != 0:
            params = list(range(base + 40, base + 40 + [0, 1, 7, 8, 10][i % 5]))
            records.extend(f.record(pid, 'ETAutomationParameter', []) for pid in params)
            records.append(keyed_list(f, parameters_id, params))
            root_fields.append(('@automationParameters', f.integer(parameters_id)))
        root = f.record(root_id, 'ETProgram', root_fields)
        rng.shuffle(records)
        f.envelope([root, *records])
        yield f'program-{i:02}', f, len(records) + 1


def invalid_cases():
    f = Fixture()
    root = f.record(1, 'ETInstrument', [])
    f.envelope([root])
    yield 'invalid-root-class', f, 5, root

    for key, value in [('formattedTempo', number('i', 123)),
                       ('autoselect', number('i', 1)), ('algorithm', string('2'))]:
        f = Fixture()
        root = f.record(1, 'ETProgram', [(key, f.add(value))])
        f.envelope([root])
        yield 'invalid-' + key, f, 6, root

    for key, code in [('keyMappings', 7), ('automationParameters', 10)]:
        f = Fixture()
        root = f.record(1, 'ETProgram', [('@' + key, f.integer(2))])
        f.envelope([root])
        yield 'dangling-' + key, f, code, root

        f = Fixture()
        member = f.record(2, 'GNList', [('count', f.integer(1))])
        root = f.record(1, 'ETProgram', [('@' + key, f.integer(2))])
        f.envelope([root, member])
        yield 'incomplete-' + key, f, code, member

    for key, cls, code in [('keyMappings', 'ETAutomationParameter', 8),
                           ('automationParameters', 'ETKeyMapping', 11)]:
        f = Fixture()
        member = f.record(3, cls, [])
        entries = keyed_list(f, 2, [3])
        root = f.record(1, 'ETProgram', [('@' + key, f.integer(2))])
        f.envelope([root, entries, member])
        yield 'wrong-member-class-' + key, f, code, member

    f = Fixture()
    member = f.record(3, 'ETKeyMapping', [('soundFilePath', f.integer(2))])
    entries = keyed_list(f, 2, [3])
    root = f.record(1, 'ETProgram', [('@keyMappings', f.integer(2))])
    f.envelope([root, entries, member])
    yield 'nonstring-sample-path', f, 9, member


def saved_locator_without_bank(fixture, with_bank):
    path = fixture.text('loops/Échantillon.wav')
    bank = fixture.text('Banque absente') if with_bank else 0
    props = [('soundFilePath', path), ('midiNote', fixture.integer(72))]
    if bank:
        props.append(('soundBankIdentifier', bank))
    mapping = fixture.record(3, 'ETKeyMapping', props)
    entries = keyed_list(fixture, 2, [3])
    root = fixture.record(1, 'ETProgram', [('@keyMappings', fixture.integer(2))])
    fixture.envelope([root, entries, mapping])
    return (struct.pack('<BIBBI2IdIiiII', 0, 0, 0, 0, 0, 1, root, 120.0, 1, 0, 0, 1, 1) +
            struct.pack('<Ii4I', mapping, 72, 0, path, bank, 0) + struct.pack('<I8I', 8, *([0] * 8)))


def input_bytes(raw, with_class_info=True, version=0, identity=IDENTITY):
    return struct.pack('<6I', len(raw), with_class_info, version, *identity) + raw


def check(probe, fixture, want, label):
    actual = probe.run(fixture, len(want))
    if actual.returncode or actual.stdout != want:
        first = next((i for i, (a, b) in enumerate(zip(want, actual.stdout)) if a != b), None)
        raise ValueError(f'{label}: native mismatch at {first}; expected {len(want)} bytes, '
                         f'got {len(actual.stdout)} ({actual.stderr!r})')


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def compare(original, executable, prefix, platform):
    oracle = ProgramStateOracle(original)
    class_info = ClassInfoOracle(original)
    probe = NativeProbe(prefix + [str(executable.resolve())], persistent=True)
    cases, invalid, pending = [], [], []
    try:
        for name, fixture, records in generated():
            try:
                raw = oracle.write_archive(fixture.objects)
                status, payload = class_info.run(raw)
                assert status == 0 and payload == raw
                want, mappings, automation, requests = oracle.output(payload, inspect_header(payload), records)
            except Exception as error:
                raise RuntimeError(f'Original program case failed: {name}') from error
            for wrapped in (False, True):
                check(probe, input_bytes(raw, wrapped), want, name)
            cases.append({'case': name, 'input_sha256': sha(raw), 'result_sha256': sha(want),
                          'records': records, 'key_mappings': mappings, 'automation_slots': automation,
                          'original_sample_load_requests': requests, 'compared_bytes_per_entry': len(want)})
        for name, fixture, error, ref in invalid_cases():
            raw = oracle.write_archive(fixture.objects)
            want = struct.pack('<BIBBI', error, ref, 0, 0, 0)
            check(probe, input_bytes(raw), want, name)
            invalid.append({'case': name, 'result_sha256': sha(want)})
        header_cases = [
            ('version-mismatch', 1, IDENTITY, 1),
            ('type-mismatch', 0, (0, *IDENTITY[1:]), 2),
            ('subtype-mismatch', 0, (IDENTITY[0], 0, IDENTITY[2]), 2),
            ('manufacturer-mismatch', 0, (*IDENTITY[:2], 0), 2),
        ]
        for name, version, identity, error in header_cases:
            assert class_info.run(b'test', version, identity) == (-10851, None)
            want = struct.pack('<BIBBI', error, 0, 0, 0, 0)
            check(probe, input_bytes(b'test', version=version, identity=identity), want, name)
            invalid.append({'case': name, 'original_rejected_before_engine': True, 'result_sha256': sha(want)})
        want = struct.pack('<BIBBI', 3, 0, 1, 0, 0)
        check(probe, input_bytes(b''), want, 'empty-data')
        invalid.append({'case': 'empty-data', 'result_sha256': sha(want)})
        for with_bank in (False, True):
            fixture = Fixture()
            want = saved_locator_without_bank(fixture, with_bank)
            label = 'retain-unresolved-bank' if with_bank else 'retain-path-without-bank-id'
            raw = oracle.write_archive(fixture.objects)
            check(probe, input_bytes(raw), want, label)
            pending.append({'case': label, 'input_sha256': sha(raw), 'result_sha256': sha(want)})
    finally:
        probe.close()
    totals = {key: sum(row[key] for row in cases) for key in (
        'records', 'key_mappings', 'automation_slots', 'original_sample_load_requests',
        'compared_bytes_per_entry')}
    return {'checkpoint': 'ELA019', 'original_i386_sha256': SHA, 'platform': platform,
            'original_routines_executed': ['0x5b64', '0x1b71e2', '0x1b73d8', '0x1b92b4', '0x1211b0',
                                           '0x160584', '0x315e4', '0x160ba8', '0x34496', '0x18b560',
                                           '0x14b946', '0x1b2bc', '0x14a6c0'],
            'verified_entry_points': ['GNArchiver payload', 'numeric AU ClassInfo and payload'],
            'runtime_bindings': ['CoreFoundation and component lookup', 'allocation, ownership and GN collection storage', 'class registry and factories',
                                 'write decoded properties into original member storage',
                                 'GNScanner strings and C pow', 'synthetic bank catalogue and sample load capture'],
            'differential_cases': cases, 'native_validation_cases': invalid,
            'native_pending_locator_cases': pending, 'totals': totals,
            'real_banks_used': False, 'user_state_tested': False, 'audio_unit_built': False}


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
    a.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({'compared_cases': len(report['differential_cases']),
                      'native_validation_cases': len(report['native_validation_cases']), **report['totals']}))
