#!/usr/bin/env python3
"""Compare the four i386 direct-voice filter modes and their live control changes."""

import argparse
import hashlib
import itertools
import json
import struct
from pathlib import Path

from compare_original_program_voice import ASSET, FILE, RIGHT_ASSET, VOICE, float_bits
from compare_original_program_voice_lifecycle import INSTRUMENT, LifecycleOracle, program_fixture
from compare_original_program_voice_render import DATA, OUTPUTS, STRIDE
from compare_original_state_archive import number
from inspect_state_archive import inspect_header
from legacy_image import SHA
from native_probe import NativeProbe
from original_keyed_state_oracle import KeyedStateOracle
from unicorn import UC_HOOK_CODE

FILTER_FIELDS = {
    'filterQ': (0x40, 'i'), 'filterType': (0x44, 'i'), 'filterCutOff': (0x3c, 'f'),
    'filterResonance': (0x38, 'f'), 'dirt': (0xc, 'f'), 'resonanceDirt': (0x10, 'f'),
    'limiterKnee': (0x14, 'f'), 'filterOn': (0x48, 'b'),
}
NOISE = 0x36704c
FILTER_SLOTS = (0xbc, 0xb8, 0xc0, 0xc4)
FILTER_RESPONSES = (1, 0, 2, 3)
CONTROL_FIELDS = tuple(FILTER_FIELDS.items())[:-1]


class FilterOracle(LifecycleOracle):
    def __init__(self, binary):
        super().__init__(binary)
        self.uc.hook_add(UC_HOOK_CODE, self.identity, begin=0x14f500, end=0x14f500)

    def instantiate(self, *unused):
        before = len(self.model_objects)
        super().instantiate()
        if len(self.model_objects) != before and self.object_types[self.model_objects[-1]] == 'ETKeyMapping':
            self.memory_floats(self.model_objects[-1] + 0xc, 0.05, 0.1, 0.5)

    def property_set(self, *unused):
        obj, value, key, _ = self.arguments(4)
        name = self.text(key).decode('ascii')
        if name not in FILTER_FIELDS:
            return super().property_set()
        offset, kind = FILTER_FIELDS[name]
        assert bytes(self.uc.mem_read(value + 0x10, 1)) == kind.encode('ascii')
        word = self.word(value + 0xc)
        if kind == 'b':
            self.uc.mem_write(obj + offset, bytes([word]))
        else:
            self.put(obj + offset, self.word(word) if kind == 'f' else word)
        KeyedStateOracle.property_set(self)

    def initialize_filters(self, rate):
        for offset, response in zip(FILTER_SLOTS, FILTER_RESPONSES):
            obj = self.reserve(0xe8)
            self.call(0x1f351c, obj)
            self.call(0x1f2cae, obj, response)
            self.call(0x1cd38, obj, 2)
            self.call(0x1ce42, obj, 2)
            self.uc.mem_write(obj + 0x4c, struct.pack('<d', rate))
            self.call(0x1f35c4, obj)
            self.put(VOICE + offset, obj)

    def render_filter(self, raw, file_frames, rate, events):
        self.frames = file_frames
        self.cache, self.reader_calls = [], 0
        order, _ = self.load_keyed(raw, inspect_header(raw), 3)
        mapping = self.call(0x15f296, order[0], 36)
        assert mapping and self.object_types[mapping] == 'ETKeyMapping'
        self.uc.mem_write(VOICE, bytes(0x130))
        self.uc.mem_write(FILE, bytes(0x60))
        self.put(INSTRUMENT, 0x36d648)
        self.put(INSTRUMENT + 0xbc, order[0])
        self.put(VOICE, 0x38b288)
        self.put(VOICE + 0x80, INSTRUMENT)
        self.put(VOICE + 0x58, 2)
        self.put(VOICE + 0xac, -1)
        self.put(NOISE, struct.unpack_from('<I', self.image.initial, NOISE)[0])
        self.put(FILE + 0x24, self.frames)
        self.uc.mem_write(FILE + 0x18, struct.pack('<d', 44100))
        self.put(ASSET + 0xc, FILE)
        self.put(RIGHT_ASSET + 0xc, FILE)
        self.put(mapping + 0x8c, ASSET, RIGHT_ASSET, -1, -1)
        self.call(0x14af3e, mapping)
        self.initialize_filters(rate)
        self.call(0x152e74, VOICE, 36, 95, 7)
        self.put(OUTPUTS, DATA + 16, DATA + STRIDE + 16)

        out = bytearray()
        for frames, event, *controls in events:
            if event == 1:
                self.uc.mem_write(mapping + 0x48, b'\0')
            elif event == 2:
                self.uc.mem_write(mapping + 0x48, b'\1')
                for (_, (offset, kind)), control in zip(CONTROL_FIELDS, controls):
                    self.put(mapping + offset, float_bits(control) if kind == 'f' else control)
            elif event == 3:
                self.call(0x152e74, VOICE, 36, 95, 7)
            elif event == 4:
                self.call(0x1521a0, VOICE, 39, 0)
            self.reads = []
            for channel in range(2):
                self.memory_floats(DATA + channel * STRIDE, *([0.125] * (frames + 8)))
            active_before = self.uc.mem_read(VOICE + 0x92, 1)[0]
            self.call(0x1532f8, VOICE, 0, OUTPUTS, frames)
            active = self.uc.mem_read(VOICE + 0x92, 1)[0]
            status = 2 if not active_before else (0 if active else 1)
            out.extend(struct.pack('<Bii', status, self.word(NOISE), self.word(VOICE + 0xac)))
            for channel in range(2):
                out.extend(self.uc.mem_read(DATA + channel * STRIDE, (frames + 8) * 4))
        return bytes(out)


def fixture(q, kind, direction, wrapped, cutoff, resonance, defaults=False):
    props = [('filterOn', number('b', 1)), ('direction', number('i', direction))]
    settings = (q, kind, cutoff, resonance, 0.14, 0.22, 0.7)
    if not defaults:
        props.extend((name, number(field_type, float_bits(value) if field_type == 'f' else value))
                     for (name, (_, field_type)), value in zip(CONTROL_FIELDS, settings))
    start, stop = (315, 70) if wrapped else (0, 360)
    props.extend((name, number('f', float_bits(value))) for name, value in
                 [('startDegree', start), ('stopDegree', stop), ('volume', 0.83), ('panorama', 0.68),
                  ('envelopeAttack', 0.07), ('envelopeRelease', 0.42)])
    return program_fixture([36], props)


def compare(binary, runner, prefix, platform):
    original = FilterOracle(binary)
    native = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    cases = []
    try:
        configs = [(*entry, False) for entry in itertools.product((44100, 48000, 96000), range(4), range(6))]
        configs.append((44100, 0, 0, True))
        configs.extend((48000, mode, 3, False) for mode in range(4))
        for index, (rate, kind, q, defaults) in enumerate(configs):
            cutoff, resonance = (0.34, 0.91) if index % 2 else (0.59, 0.57)
            data = fixture(q, kind, index % 2, index % 3 == 0, cutoff, resonance, defaults)
            raw = original.write_archive(data.objects)
            events = [
                (47, 0),
                (17, 2, q, kind, 0.72, 0.82, 0.21, 0.41, 0.63),
                (61, 2, (q + 1) % 6, kind, 0.85, 0.98, 0.17, 0.31, 0.53),
                (43, 2, q, (kind + 1) % 4, 0.63, 0.71, 0.09, 0.21, 0.61),
                (31, 1),
                (23, 2, q, kind, 0.85, 0.88, 0.35, 0.51, 0.47),
                (53, 3),
                (29, 4),
                (187, 0),
                (37, 0),
            ]
            long_sweep = index >= len(configs) - 4
            if long_sweep:
                events = [(47, 0), (41, 2, q, kind, 0.89, 0.82, 0.51, 0.39, 0.28)]
                events += [(513, 0)] * 9
                events += [(17, 2, q, kind, 0.89, 0.82, 0.33, 0.49, 0.38), (67, 0), (29, 4), (187, 0)]
            expected = original.render_filter(raw, 629 + index % 3, rate, events)
            wire = struct.pack('<4i', len(raw), original.frames, len(events), rate) + raw
            wire += b''.join(struct.pack('<2i', *event[:2]) +
                             (struct.pack('<2i5f', *event[2:]) if event[1] == 2 else b'') for event in events)
            actual = native.run(wire, len(expected))
            if actual.returncode or actual.stdout != expected:
                changed = next((i for i, (a, b) in enumerate(zip(expected, actual.stdout)) if a != b), None)
                for block, event in enumerate(events):
                    size = 9 + (event[0] + 8) * 8
                    if changed is None or changed < size:
                        break
                    changed -= size
                at = sum(9 + (event[0] + 8) * 8 for event in events[:block])
                raise ValueError(f'case {index} type {kind} q {q} block {block} byte {changed}, '
                                 f'{expected[at:at+63].hex()} vs {actual.stdout[at:at+63].hex()} {actual.stderr!r}')
            cases.append({'case': index, 'rate': rate, 'type': kind, 'q': q, 'default_settings': defaults,
                          'long_sweep': long_sweep, 'blocks': len(events), 'frames': sum(event[0] for event in events),
                          'sha256': hashlib.sha256(expected).hexdigest()})
    finally:
        native.close()
    return {'checkpoint': 'ELA024', 'platform': platform, 'original_i386_sha256': SHA,
            'sequences': len(cases), 'blocks': sum(x['blocks'] for x in cases), 'frames': sum(x['frames'] for x in cases),
            'filter_modes': 4, 'orders': 6, 'processor_rates': [44100, 48000, 96000],
            'original_functions': ['0x1f351c', '0x1f35c4', '0x152e74', '0x1521a0', '0x1532f8', '0x1f379e',
                                   '0x1f318a', '0x227dae'],
            'host_bindings': ['GN object and property storage', 'audio processor base initialization', 'pow',
                              'synthetic PCM', 'clock and note-end notification'],
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
    print(json.dumps({k: report[k] for k in ('sequences', 'blocks', 'frames', 'platform')}))
