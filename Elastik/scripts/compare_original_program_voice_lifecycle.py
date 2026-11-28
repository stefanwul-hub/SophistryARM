#!/usr/bin/env python3
"""Compare MIDI note selection and a complete direct-voice note lifecycle."""

import argparse
import hashlib
import itertools
import json
import struct
from pathlib import Path

from compare_original_keyed_state import Fixture
from compare_original_program_state import keyed_list
from compare_original_program_voice import ASSET, FILE, RIGHT_ASSET, VOICE, float_bits
from compare_original_program_voice_render import DATA, OUTPUTS, STRIDE, RenderOracle
from compare_original_state_archive import number
from inspect_state_archive import inspect_header
from legacy_image import SHA
from native_probe import NativeProbe
from original_keyed_state_oracle import KeyedStateOracle

INSTRUMENT = 0x534000
ENVELOPES = {'envelopeAttack': 0x34, 'envelopeRelease': 0x30}


class LifecycleOracle(RenderOracle):
    def property_set(self, *unused):
        obj, value, key, _ = self.arguments(4)
        name = self.text(key).decode('ascii')
        if name not in ENVELOPES:
            return super().property_set()
        assert bytes(self.uc.mem_read(value + 0x10, 1)) == b'f'
        self.put(obj + ENVELOPES[name], self.word(self.word(value + 0xc)))
        KeyedStateOracle.property_set(self)

    def lookup(self, raw, mappings):
        order, _ = self.load_keyed(raw, inspect_header(raw), mappings + 2)
        refs = [self.model_refs.get(self.call(0x15f296, order[0], note), 0) for note in range(128)]
        return struct.pack('<128I', *refs)

    def snapshot(self):
        released, active = self.uc.mem_read(VOICE + 0x91, 2)
        note, velocity = self.uc.mem_read(VOICE + 0x84, 2)
        release_velocity = self.uc.mem_read(VOICE + 0x90, 1)[0]
        values = [self.word(VOICE + n) for n in (0xb4, 0x88, 0x8c, 0x9c, 0xa0, 0xa4)]
        return (struct.pack('<5B6i', active, released, note, velocity, release_velocity, *values) +
                bytes(self.uc.mem_read(VOICE + 0xc8, 24)) + self.ramp_bytes() +
                bytes(self.uc.mem_read(VOICE + 0xe0, 24)))

    def lifecycle(self, raw, input_, blocks):
        self.frames, channels, delay, velocity, release_velocity, release_offset = input_
        self.cache, self.reader_calls = [], 0
        order, _ = self.load_keyed(raw, inspect_header(raw), 3)
        program = order[0]
        mapping = self.call(0x15f296, program, 36)
        assert mapping and self.object_types[mapping] == 'ETKeyMapping'
        self.uc.mem_write(VOICE, bytes(0x130))
        self.uc.mem_write(FILE, bytes(0x60))
        self.put(INSTRUMENT, 0x36d648)
        self.put(INSTRUMENT + 0xbc, program)
        self.put(VOICE, 0x38b288)
        self.put(VOICE + 0x80, INSTRUMENT)
        self.put(VOICE + 0x58, channels)
        self.put(FILE + 0x24, self.frames)
        self.uc.mem_write(FILE + 0x18, struct.pack('<d', 44100))
        self.put(ASSET + 0xc, FILE)
        self.put(RIGHT_ASSET + 0xc, FILE)
        self.put(mapping + 0x8c, ASSET, RIGHT_ASSET, -1, -1)
        self.call(0x14af3e, mapping)
        self.call(0x152e74, VOICE, 36, velocity, delay)
        assert self.word(VOICE + 0x98) == mapping
        out = bytearray(self.snapshot())
        self.put(OUTPUTS, *(DATA + channel * STRIDE + 16 for channel in range(channels)))

        finished = 0
        for block, frames in enumerate(blocks):
            if block == 1:
                self.call(0x1521a0, VOICE, release_velocity, release_offset)
                out.extend(self.snapshot())
            self.reads = []
            for channel in range(channels):
                self.memory_floats(DATA + channel * STRIDE, *([0.125] * (frames + 8)))
            active_before = self.uc.mem_read(VOICE + 0x92, 1)[0]
            self.call(0x1532f8, VOICE, 0, OUTPUTS, frames)
            active = self.uc.mem_read(VOICE + 0x92, 1)[0]
            status = 2 if not active_before else (0 if active else 1)
            finished += status == 1
            out.append(status)
            out.extend(self.snapshot())
            for channel in range(channels):
                out.extend(self.uc.mem_read(DATA + channel * STRIDE, (frames + 8) * 4))
        return bytes(out), finished


def program_fixture(notes, attributes=()):
    f = Fixture()
    records = [f.record(i + 3, 'ETKeyMapping', [('midiNote', f.integer(note))] +
                        [(name, f.add(value)) for name, value in attributes])
               for i, note in enumerate(notes)]
    indices = keyed_list(f, 2, list(range(3, len(notes) + 3)))
    program = f.record(1, 'ETProgram', [('@keyMappings', f.integer(2))])
    f.envelope([program, indices, *records])
    return f


def compare(binary, runner, prefix, platform):
    oracle = LifecycleOracle(binary)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    lookup_cases, cases = [], []
    try:
        for name, notes in [('normal', list(range(36, 104))),
                            ('alternate', list(range(72, 104)) + [0] * 4 + list(range(36, 72)))]:
            raw = oracle.write_archive(program_fixture(notes).objects)
            expected = oracle.lookup(raw, len(notes))
            actual = probe.run(struct.pack('<8i', len(raw), 0, 0, 0, 0, 0, 0, 0) + raw, len(expected))
            assert actual.returncode == 0 and actual.stdout == expected, (name, actual.stderr)
            lookup_cases.append({'case': name, 'notes': 128, 'sha256': hashlib.sha256(expected).hexdigest()})
        for index, (direction, attack, release, bounds) in enumerate(itertools.product(
                (0, 1), (0.0, 1.0e-5, 0.0001, 0.35), (0.0, 0.0001, 0.5), ((0, 360), (315, 30)))):
            start, stop = bounds
            attrs = [(name, number('f', float_bits(value))) for name, value in
                     [('startDegree', start), ('stopDegree', stop), ('volume', 0.65), ('panorama', 0.2 if index & 1 else 0.75),
                      ('envelopeAttack', attack), ('envelopeRelease', release)]]
            attrs.append(('direction', number('i', direction)))
            raw = oracle.write_archive(program_fixture([36], attrs).objects)
            parameters = (384 + index % 3, 2, 5 + index % 7, 45 + index, 23 + index, index % 32)
            blocks = [47, 53, 69, 185, 113]
            expected, finished = oracle.lifecycle(raw, parameters, blocks)
            wire = struct.pack('<8i', len(raw), *parameters, len(blocks)) + raw + struct.pack('<5i', *blocks)
            actual = probe.run(wire, len(expected))
            if actual.returncode or actual.stdout != expected:
                at = next((i for i, (a, b) in enumerate(zip(expected, actual.stdout)) if a != b), None)
                if at is not None:
                    at = (at, expected[max(0, at - 4):at + 10].hex(), actual.stdout[max(0, at - 4):at + 10].hex())
                raise ValueError(f'Lifecycle {index} mismatch at {at}, {actual.stderr!r}')
            cases.append({'case': index, 'sha256': hashlib.sha256(expected).hexdigest(),
                          'render_blocks': len(blocks), 'compared_bytes': len(expected), 'finished': int(finished)})
    finally:
        probe.close()
    return {'checkpoint': 'ELA023', 'platform': platform, 'original_i386_sha256': SHA,
            'lookup_cases': lookup_cases, 'voice_sequences': len(cases), 'render_blocks': sum(x['render_blocks'] for x in cases),
            'finished_voices': sum(x['finished'] for x in cases), 'compared_bytes': sum(x['compared_bytes'] for x in cases),
            'original_functions': ['0x15f296', '0x14af3e', '0x152e74', '0x1521a0', '0x1532f8',
                                   '0x1566f8', '0x156734', '0x156756'],
            'host_bindings': ['GN object and property storage', 'synthetic PCM', 'clock and note-end notification'],
            'native_audio_unit_built': False, 'cases': cases}


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
    print(json.dumps({k: report[k] for k in ('voice_sequences', 'render_blocks', 'finished_voices',
                                             'compared_bytes', 'platform')}))
