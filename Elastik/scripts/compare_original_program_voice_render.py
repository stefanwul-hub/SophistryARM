#!/usr/bin/env python3
"""Compare consecutive direct-sample voice render calls to Elastik i386."""

import argparse
import hashlib
import itertools
import json
import struct
from pathlib import Path

from compare_original_keyed_state import Fixture
from compare_original_program_state import keyed_list
from compare_original_program_voice import ASSET, VOICE, VoiceOracle, float_bits
from compare_original_state_archive import number
from legacy_image import SHA
from native_probe import NativeProbe
from original_keyed_state_oracle import KeyedStateOracle
from unicorn import UC_HOOK_CODE

OUTPUTS, DATA, STRIDE = 0x609000, 0x620000, 0x2000
MIX_FIELDS = {'volume': 0x2c, 'panorama': 0x64}


class RenderOracle(VoiceOracle):
    def __init__(self, binary):
        super().__init__(binary)
        # Fixed x87 timestamp. The original writes it to the key's display state.
        self.uc.mem_write(0xa8fe, b'\xd9\xee\xc3')
        for address, hook in {0x15f8e4: self.identity_zero, 0x1b35a: self.identity_zero,
                              0x1b3bc: self.instrument_still_running}.items():
            self.uc.hook_add(UC_HOOK_CODE, hook, begin=address, end=address)

    def identity_zero(self, *unused):
        self.finish()

    def instrument_still_running(self, *unused):
        self.finish(1)

    def property_set(self, *unused):
        obj, value, key, _ = self.arguments(4)
        name = self.text(key).decode('ascii')
        if name in MIX_FIELDS:
            assert bytes(self.uc.mem_read(value + 0x10, 1)) == b'f'
            self.put(obj + MIX_FIELDS[name], self.word(self.word(value + 0xc)))
        elif name == 'firstOutputChannelIndex':
            assert bytes(self.uc.mem_read(value + 0x10, 1)) == b'i'
            self.put(obj + 0x4c, self.word(value + 0xc))
        else:
            return super().property_set()
        KeyedStateOracle.property_set(self)

    def read_samples(self, *unused):
        asset, dest, channel, first, count, *windows = self.arguments(9)
        assert asset == ASSET and DATA <= dest < DATA + 8 * STRIDE and channel in (0, 1)
        assert windows == [0, 0x40590000, 0, 0x40590000]
        assert 0 <= first <= self.frames and 0 <= count <= self.frames - first
        self.reads.append((channel, first, count))
        if count:
            pcm = [((i * 73 + channel * 1009) % 32768 - 16384) / 32768 for i in range(first, first + count)]
            self.uc.mem_write(dest, struct.pack('<' + 'f' * count, *pcm))
        self.finish(1)

    def memory_floats(self, at, *values):
        self.uc.mem_write(at, struct.pack('<' + 'f' * len(values), *values))

    def render_sequence(self, state, input_, blocks):
        sample_frames, channels, delay, attack, release, released, edit = input_
        self.execute_voice(state, (sample_frames, 0, channels, released, 0, -1), b'')
        self.put(VOICE, 0x38b288)
        self.put(VOICE + 0x88, delay)
        self.uc.mem_write(VOICE + 0x92, b'\1')
        self.memory_floats(VOICE + 0xc8, 0.0, 0.25, 0.0, 0.0, 0.75, 0.0)
        self.memory_floats(VOICE + 0xe0, *( (1.0, 0.0, 0.125) if attack else (0, 0, 0) ))
        self.memory_floats(VOICE + 0xec, *( (0.0, 1.0, -0.00390625) if release else (0, 0, 0) ))
        self.put(OUTPUTS, *(DATA + channel * STRIDE + 16 for channel in range(channels)))
        out = bytearray()
        bytes_compared = 0
        self.read_calls = self.finishes = 0
        for block, frames in enumerate(blocks):
            if edit and block == 1:
                mapping = self.word(VOICE + 0x98)
                self.memory_floats(mapping + 0x6c, 75.0, 280.0)
                self.call(0x14af3e, mapping)
            self.reads = []
            for ch in range(channels):
                self.memory_floats(DATA + ch * STRIDE, *([0.125] * (frames + 8)))
            active_before = self.uc.mem_read(VOICE + 0x92, 1)[0]
            delay_before = self.word(VOICE + 0x88)
            self.call(0x1532f8, VOICE, 0, OUTPUTS, frames)
            is_released, active = self.uc.mem_read(VOICE + 0x91, 2)
            status = 2 if not active_before else (0 if active else 1)
            self.finishes += status == 1
            self.read_calls += len(self.reads)
            written = max(delay_before, 0) + sum(count for ch, _, count in self.reads if ch == 0) if active_before else 0
            out.extend(struct.pack('<BiBB5i', status, written, active, is_released, self.word(VOICE + 0xb4),
                                   self.word(VOICE + 0x88), self.word(VOICE + 0x9c),
                                   self.word(VOICE + 0xa0), self.word(VOICE + 0xa4)))
            out.extend(self.uc.mem_read(VOICE + 0xc8, 24))
            out.extend(self.ramp_bytes())
            out.extend(self.uc.mem_read(VOICE + 0xe0, 24))
            for ch in range(channels):
                data = self.uc.mem_read(DATA + ch * STRIDE, (frames + 8) * 4)
                out.extend(data)
                bytes_compared += len(data)
        return bytes(out), bytes_compared


def fixture(loop, mix):
    f = Fixture()
    start, stop, direction, mode = loop
    volume, pan, channel = mix
    fields = [(key, f.add(number('f', float_bits(value)))) for key, value in
              (('startDegree', start), ('stopDegree', stop), ('volume', volume), ('panorama', pan))]
    fields += [(key, f.integer(value)) for key, value in
               (('direction', direction), ('loopMode', mode), ('firstOutputChannelIndex', channel))]
    mapping = f.record(3, 'ETKeyMapping', fields)
    keys = keyed_list(f, 2, [3])
    program = f.record(1, 'ETProgram', [('@keyMappings', f.integer(2))])
    f.envelope([program, keys, mapping])
    return f


def cases():
    bounds = [(0, 360), (120, 240), (315, 30), (180, 180)]
    for n, ((start, stop), direction, mode, pan) in enumerate(itertools.product(bounds, (0, 1), (0, 1), (0, 0.5, 0.8))):
        channels = 1 if n % 7 == 0 else 4 if n % 3 == 0 else 2
        output = 2 if channels == 4 else 0
        mix = (0.875 if n % 2 else 0.25, pan, output)
        attack = channels != 1 and n % 3 == 0
        yield f'render-{n:02}', (start, stop, direction, mode), mix, (384, channels, 11, attack, False, False, False), [53, 137, 317, 17, 384]
    for direction in (0, 1):
        yield f'release-{direction}', (90, 270, direction, 1), (0.7, 0.5, 0), (512, 2, -1, True, True, True, False), [64] * 5
        yield f'edit-loop-{direction}', (10, 140, direction, 1), (0.7, 0.65, 0), (384, 2, 0, False, False, False, True), [64, 64, 200, 127, 521]


def compare(original, runner, prefix, platform):
    oracle = RenderOracle(original)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    results = []
    try:
        for name, loop, mix, input_, blocks in cases():
            raw = oracle.write_archive(fixture(loop, mix).objects)
            expected, audio_bytes = oracle.render_sequence(raw, input_, blocks)
            feed = struct.pack('<9i', len(raw), *input_, len(blocks)) + raw + struct.pack('<5i', *blocks)
            actual = probe.run(feed, len(expected))
            if actual.returncode or actual.stdout != expected:
                at = next((i for i, (a, b) in enumerate(zip(expected, actual.stdout)) if a != b), None)
                if at is not None:
                    at = (at, expected[max(0, at - 8):at + 16].hex(), actual.stdout[max(0, at - 8):at + 16].hex())
                raise ValueError(f'{name}: first differing bytes {at}, {actual.stderr!r}')
            results.append({'case': name, 'sha256': hashlib.sha256(expected).hexdigest(),
                            'blocks': len(blocks), 'audio_bytes': audio_bytes,
                            'read_calls': oracle.read_calls, 'finished_voices': oracle.finishes})
    finally:
        probe.close()
    return {'checkpoint': 'ELA022', 'platform': platform, 'original_i386_sha256': SHA,
            'cases': len(results), 'blocks': sum(r['blocks'] for r in results),
            'audio_bytes': sum(r['audio_bytes'] for r in results),
            'original_read_calls': sum(r['read_calls'] for r in results),
            'finished_voices': sum(r['finished_voices'] for r in results),
            'original_0x1532f8_executed': True, 'original_filter_disabled': True,
            'original_host_bindings': ['synthetic PCM provider', 'fixed timestamp', 'unsynchronized start',
                                      'instrument note end notification', 'GN state and object runtime'],
            'audio_unit_built': False, 'results': results}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original', type=Path)
    parser.add_argument('probe', type=Path)
    parser.add_argument('--runner-prefix', action='append', default=[])
    parser.add_argument('--platform', required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    report = compare(args.original, args.probe, args.runner_prefix, args.platform)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({key: report[key] for key in ('cases', 'blocks', 'audio_bytes', 'finished_voices', 'platform')}))
