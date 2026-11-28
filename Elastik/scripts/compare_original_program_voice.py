#!/usr/bin/env python3
"""Compare saved ETKeyMapping playback bounds, voice setup and audio blocks."""

import argparse
import hashlib
import itertools
import json
import random
import struct
import wave
from pathlib import Path

from compare_original_keyed_state import Fixture
from compare_original_program_state import keyed_list
from compare_original_sample_file import WAVE_SHA
from compare_original_state_archive import number
from inspect_state_archive import inspect_header
from legacy_image import SHA
from native_probe import NativeProbe
from original_keyed_state_oracle import KeyedStateOracle
from original_program_state_oracle import ProgramStateOracle
from unicorn import UC_HOOK_CODE

VOICE, ASSET, FILE, READER, READER_TABLE, RIGHT_ASSET, RANGE, NEXT = range(0x531000, 0x533000, 0x400)
FRAME_COUNT, PCM = 0x500a00, 0x610000
LOOP_FIELDS = {'startDegree': (0x6c, b'f'), 'stopDegree': (0x70, b'f'),
               'direction': (0x5c, b'i'), 'loopMode': (0x58, b'i')}
SEED_RAMPS = struct.pack('<12f', 0.25, 0.5, -0.125, 0.75, 0.125, 0.0625, 0, 0.25, -0.125, 1, 0.25, 0.125)


class VoiceOracle(ProgramStateOracle):
    finalize_models = False

    def __init__(self, binary):
        super().__init__(binary)
        self.frames = 0
        self.put(READER, READER_TABLE)
        self.put(READER_TABLE + 0x1bc, FRAME_COUNT)
        hooks = {
            FRAME_COUNT: self.frame_count, 0x1f0c06: self.observe_cache,
            0x1f0b98: self.observe_cache, 0x1f0c92: self.read_samples,
        }
        for addr, handler in hooks.items():
            self.uc.hook_add(UC_HOOK_CODE, handler, begin=addr, end=addr)

    def instantiate(self, *unused):
        count = len(self.model_objects)
        super().instantiate()
        if len(self.model_objects) != count:
            obj = self.model_objects[-1]
            if self.object_types[obj] == 'ETKeyMapping':
                # The real factory at 0x14b522 sets this before decode.
                self.put(obj + 0x58, 1)

    def property_set(self, *unused):
        obj, value, key, _ = self.arguments(4)
        name = self.text(key).decode('ascii')
        if name not in LOOP_FIELDS:
            return super().property_set()
        offset, kind = LOOP_FIELDS[name]
        assert self.object_types[obj] == 'ETKeyMapping'
        assert bytes(self.uc.mem_read(value + 0x10, 1)) == kind
        word = self.word(value + 0xc)
        self.put(obj + offset, self.word(word) if kind == b'f' else word)
        KeyedStateOracle.property_set(self)

    def diagnostic(self, *unused):
        text, = self.arguments(1)
        if self.frames == 1 and bytes(self.uc.mem_read(text, 40)).startswith(b'ETKeyMapping::adjustSoundFileClients'):
            self.finish()
            return
        super().diagnostic(*unused)

    def frame_count(self, *unused):
        reader, = self.arguments(1)
        assert reader == READER
        self.reader_calls += 1
        self.finish(self.frames)

    def observe_cache(self, uc, addr, size, user):
        asset, start, count = self.arguments(3)
        assert asset in (ASSET, RIGHT_ASSET)
        self.cache.append((hex(addr), int(asset == RIGHT_ASSET), start, count))
        self.finish()

    def read_samples(self, *unused):
        asset, dest, channel, first, count, *windows = self.arguments(9)
        assert asset == ASSET and dest == PCM + 32 and channel in (0, 1)
        assert windows == [0, 0x40590000, 0, 0x40590000]
        assert 0 <= first <= self.frames and 0 <= count <= self.frames - first, (first, count, self.frames)
        self.reads.append((channel, first, count))
        if count:
            if self.pcm:
                values = struct.unpack_from('<' + 'h' * (count * 2), self.pcm, first * 4)
                pcm = [value / 32768 for value in values[channel::2]]
            else:
                pcm = [((i * 73 + channel * 1009) % 32768 - 16384) / 32768 for i in range(first, first + count)]
            self.uc.mem_write(dest, struct.pack('<' + 'f' * count, *pcm))
        self.finish(1)

    def ramp_bytes(self):
        return bytes(self.uc.mem_read(VOICE + 0x110, 24) + self.uc.mem_read(VOICE + 0xf8, 24))

    def execute_voice(self, raw, header, pcm):
        self.pcm = pcm
        self.frames, fallback, channels, released, channel, count = header
        self.reader_calls, self.cache, self.reads = 0, [], []
        order, _ = self.load_keyed(raw, inspect_header(raw), 3)
        mappings = self.registries[self.word(order[0] + 0x1c)]
        mapping, = mappings
        assert self.object_types[mapping] == 'ETKeyMapping'
        self.uc.mem_write(VOICE, bytes(0x130))
        self.uc.mem_write(FILE, bytes(0x60))
        self.put(ASSET + 0xc, FILE)
        self.put(RIGHT_ASSET + 0xc, FILE)
        self.put(FILE + 0x24, 0 if fallback else self.frames)
        self.put(FILE + 0x54, READER if fallback else 0)
        self.uc.mem_write(FILE + 0x18, struct.pack('<d', 44100))
        self.put(mapping + 0x8c, ASSET, RIGHT_ASSET, -1, -1)
        self.put(VOICE + 0x58, channels)
        self.uc.mem_write(VOICE + 0x91, bytes([released]))
        self.put(VOICE + 0x98, mapping)
        self.uc.mem_write(VOICE + 0x110, SEED_RAMPS[:24])
        self.uc.mem_write(VOICE + 0xf8, SEED_RAMPS[24:])
        self.call(0x14af3e, mapping)
        self.call(0x152472, VOICE)
        start, stop, length, mode = (self.word(VOICE + i) for i in (0x9c, 0xa0, 0xa4, 0xa8))
        direction = self.word(mapping + 0x5c)
        last_direction = self.word(VOICE + 0xb0)
        cursor = self.word(VOICE + 0xb4)
        if fallback:
            assert self.reader_calls > 0
        else:
            assert self.reader_calls == 0
        wanted = struct.pack('<2B9i', 0, 0, self.frames, start, stop, direction, mode,
                             released, last_direction, cursor, length) + self.ramp_bytes()
        if count < 0:
            return wanted, start, stop, 0

        self.put(RANGE, -1, -1)
        self.put(NEXT, -1)
        self.uc.mem_write(PCM, struct.pack('<f', 0.03125) * (count + 16))
        read = self.call(0x152664, VOICE, PCM + 32, channel, cursor, count, NEXT, RANGE)
        channel, first, count_read = self.reads[0]
        wanted += struct.pack('<5i', read, self.word(NEXT), self.word(RANGE), self.word(RANGE + 4),
                              self.word(VOICE + 0xb0)) + self.ramp_bytes()
        wanted += struct.pack('<4i', len(self.reads), channel, first, count_read)
        wanted += bytes(self.uc.mem_read(PCM, (count + 16) * 4))
        return wanted, start, stop, read


def float_bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def state_fixture(start, stop, direction, mode, invalid_type=False):
    f = Fixture()
    fields = []
    for name, value in [('startDegree', start), ('stopDegree', stop)]:
        if value is not None:
            data = number('i', 1) if invalid_type else number('f', float_bits(value))
            fields.append((name, f.add(data)))
    if direction is not None:
        fields.append(('direction', f.integer(direction)))
    if mode is not None:
        fields.append(('loopMode', f.integer(mode)))
    mapping = f.record(3, 'ETKeyMapping', fields)
    indices = keyed_list(f, 2, [3])
    program = f.record(1, 'ETProgram', [('@keyMappings', f.integer(2))])
    f.envelope([program, indices, mapping])
    return f


def scenarios(builtin):
    cases = [(None, None), (0.0, 360.0), (360.0, -0.0), (30.0, 180.0), (300.0, 60.0),
             (90.0, 90.0), (0.001, 0.002), (359.9, 359.8)]
    for n, (degrees, frames, direction) in enumerate(itertools.product(cases, (1, 97, 1024, 176399), (0, 1))):
        start, stop = degrees
        mode = (None, 0, 1, 7)[n % 4]
        channels = (0, 1, 2, 3, 0x101, 0x102)[n % 6]
        leaves_single = frames == 1
        count = -1 if leaves_single else (1, 31, 100, 257)[n % 4]
        channel = int((channels & 0xff) >= 2 and n % 3 == 0)
        yield f'boundary-{n:03}', (start, stop, direction, mode), (frames, n % 2, channels, n % 2, channel, count), b''

    rng = random.Random(0xe1a021)
    for n in range(64):
        start, stop = (rng.uniform(0.0, 360.0) for _ in range(2))
        channels = 1 + n % 2
        yield (f'interior-{n:03}', (start, stop, n % 2, n % 5),
               (rng.randrange(128, 200000), n % 2, channels, n % 2, channels - 1, 137), b'')

    if sha(builtin.read_bytes()) != WAVE_SHA:
        raise ValueError('Expected the original WAVE from the bundled Elastik bank')
    with wave.open(str(builtin), 'rb') as source:
        assert source.getnchannels() == 2 and source.getsampwidth() == 2
        frames = source.getnframes()
        pcm = source.readframes(frames)
    for n, settings in enumerate([(0, 0, 0, 0), (90, 270, 1, 1), (359.8, 12, 0, 1), (300, 0.15, 1, 1)]):
        yield f'builtin-{n}', settings, (frames, n % 2, 2, 0, n % 2, 257), pcm


def sha(data):
    return hashlib.sha256(data).hexdigest()


def compare(binary, runner, prefix, platform, builtin):
    oracle = VoiceOracle(binary)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    cases, rejected = [], []
    try:
        for name, fields, params, pcm in scenarios(builtin):
            state = oracle.write_archive(state_fixture(*fields).objects)
            try:
                expected, first, last, frames = oracle.execute_voice(state, params, pcm)
            except Exception as error:
                raise RuntimeError(f'Original voice fixture failed: {name}') from error
            raw = struct.pack('<8i', len(state), *params, len(pcm) // 2) + state + pcm
            actual = probe.run(raw, len(expected))
            if actual.returncode or actual.stdout != expected:
                byte = next((i for i, (a, b) in enumerate(zip(expected, actual.stdout)) if a != b), None)
                raise ValueError(f'{name}: mismatch at {byte} (start={first}, stop={last}, result={actual.stderr!r})')
            cases.append({'case': name, 'archive_sha256': sha(state), 'result_sha256': sha(expected),
                          'bounds': [first, last], 'frames_compared': frames, 'bytes': len(expected),
                          'i386_range_prepare_calls': oracle.cache})
        for name, start, stop, frames, invalid_type, code in (
            ('negative-start', -1.0, 42.0, 97, False, 2), ('stop-above-turn', 0.0, 361.0, 97, False, 2),
            ('nan-start', float('nan'), 0.0, 97, False, 2), ('infinite-stop', 0.0, float('inf'), 97, False, 2),
            ('empty-file', 0.0, 0.0, 0, False, 1), ('wrong-wire-type', 0.0, 0.0, 97, True, 9),
        ):
            state = oracle.write_archive(state_fixture(start, stop, 0, 1, invalid_type).objects)
            expected = bytes([code]) if invalid_type else (
                struct.pack('<2B9i', 0, code, 19, 2, 13, 7, 5, 0, 9, 17, 18) + SEED_RAMPS)
            actual = probe.run(struct.pack('<8i', len(state), frames, 0, 2, 0, 1, -1, 0) + state, len(expected))
            if actual.returncode or actual.stdout != expected:
                raise ValueError(f'{name}: validation mismatch')
            rejected.append({'case': name, 'archive_sha256': sha(state), 'result_sha256': sha(expected)})
    finally:
        probe.close()
    return {'checkpoint': 'ELA021', 'platform': platform, 'original_i386_sha256': SHA,
            'source_from_synthetic_gnkeyvalue_archive': True,
            'builtin_audio_fixtures': 4, 'builtin_wave_sha256': WAVE_SHA,
            'original_routines_executed': ['0x1b92b4', '0x1211b0', '0x315e4', '0x14af3e', '0x14ad4e',
                                           '0x14d374', '0x1ab7c0', '0x152472', '0x152664', '0x15197c'],
            'host_bindings': ['GN runtime, model storage and ownership', 'sample frame metadata and fixture PCM',
                              'observe advance cache requests without a live cache'],
            'differential_cases': len(cases), 'native_validation_cases': len(rejected),
            'frames_compared': sum(c['frames_compared'] for c in cases),
            'compared_bytes': sum(c['bytes'] for c in cases),
            'user_state_used': False, 'full_voice_rendered': False, 'audio_unit_built': False,
            'cases': cases, 'rejected': rejected}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original', type=Path)
    parser.add_argument('probe', type=Path)
    parser.add_argument('--runner-prefix', action='append', default=[])
    parser.add_argument('--wave', type=Path, required=True)
    parser.add_argument('--platform', required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    report = compare(args.original, args.probe, args.runner_prefix, args.platform, args.wave)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({k: report[k] for k in ('differential_cases', 'native_validation_cases',
                                             'frames_compared', 'compared_bytes', 'platform')}))
