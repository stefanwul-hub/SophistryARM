#!/usr/bin/env python3
"""Compare saved mapping -> original path dispatch -> real GNFA member reads."""

import argparse
import hashlib
import io
import json
import struct
import wave
from pathlib import Path

from compare_original_archive_open import GNA, SOURCE, ArchiveOpenOracle, fixture as open_fixture
from compare_original_file_archive import ARCHIVE_SHA, OUT, PATH, archive
from compare_original_keyed_state import Fixture
from compare_original_program_state import keyed_list
from inspect_state_archive import inspect_header
from legacy_image import SHA
from native_probe import NativeProbe
from original_cache_oracle import OriginalCacheOracle
from original_program_state_oracle import ProgramStateOracle
from original_archive_name_oracle import ROOT
from unicorn import UC_HOOK_CODE

DISK, DISK_TABLE, BANK, CATALOG, CACHE, MEMBER = range(0x520000, 0x520600, 0x100)
DISK_IS_FILE = 0x500b00
BUILTIN_WAVE = '/elastik/01drm120elastik_2.WAV'


class ProgramBeforeCatalogue(ProgramStateOracle):
    finalize_models = False

    def mappings(self, raw, count):
        order, _ = self.load_keyed(raw, inspect_header(raw), count)
        assert self.object_types[order[0]] == 'ETProgram'
        for entry in self.registries[self.word(order[0] + 0x1c)]:
            path, identifier = [self.word(entry + n) for n in (0x24, 0x28)]
            yield (self.string_units(path) if path else None,
                   self.string_units(identifier) if identifier else None, bool(self.word(entry + 0x78)))


class MemberOracle(ArchiveOpenOracle):
    def member_path(self, image, path, clone):
        setup = open_fixture('program-member', image, path)
        setup['h'][10] = clone
        self.setup_open(setup)
        self.phase = 'parse'
        self.call_reg(0xe13de, (GNA, SOURCE))
        assert not self.error
        self.phase = 'lookup'
        result = self.call_reg(0xe1a68, (GNA, ROOT))
        if self.error:
            assert self.error == 4
            return False
        assert result == PATH
        return True

    def read_member(self):
        file = self.call_reg(0xe3ff4, (PATH,))
        assert not self.error
        if not file:
            return None
        assert file in self.files
        length = self.call_reg(0xe09c0, (PATH,))
        assert not self.error
        if not length:
            return None
        self.put(OUT + 0x110000, length)
        read = self.call_reg(0xe4172, (file, OUT, OUT + 0x110000))
        assert read and not self.error and self.word(OUT + 0x110000) == length
        return bytes(self.uc.mem_read(OUT, length))


class SamplePathOracle(OriginalCacheOracle):
    def __init__(self, binary):
        super().__init__(binary)
        self.archive = MemberOracle(binary)
        self.put(DISK, DISK_TABLE)
        self.put(DISK_TABLE + 0x1d0, DISK_IS_FILE)
        self.import_handlers['__Znwm'] = self.allocate
        for addr, handler in {
            0x630b6: self.identity, 0x2dfa6: self.identity, 0x64626: self.get_cached,
            0x66284: self.set_cached, 0x9af5e: self.system_path, DISK_IS_FILE: self.is_file,
            0xcfca: self.catalogue, 0x68b5e: self.find_bank, 0x1aa9c6: self.bank_archive,
            0xe1a68: self.member, 0x1adefe: self.open_sample,
        }.items():
            self.uc.hook_add(UC_HOOK_CODE, handler, begin=addr, end=addr)

    def allocate(self):
        size, = self.arguments(1)
        assert size == 0x18
        self.finish(CACHE)

    def identity(self, *unused):
        obj, = self.arguments(1)
        self.finish(obj)

    def get_cached(self, *unused):
        cache, key = self.arguments(2)
        assert cache == CACHE
        sample = self.cache.get(self.strings[key], 0)
        if sample:
            self.status = 1
        self.finish(sample)

    def set_cached(self, *unused):
        cache, sample, key = self.arguments(3)
        assert cache == CACHE and sample in self.outputs
        self.cache_writes += 1
        self.cache[self.strings[key]] = sample
        self.finish()

    def system_path(self, *unused):
        key, = self.arguments(1)
        self.events.append(1)
        self.name = self.strings[key]
        self.status = 4
        self.finish(DISK if self.name in ('/disk/ok.wav', '/disk/broken.wav', '/disk/absent.wav') else 0)

    def is_file(self, *unused):
        path, = self.arguments(1)
        assert path == DISK
        self.events.append(2)
        self.finish(int(self.name != '/disk/absent.wav'))

    def catalogue(self, *unused):
        self.finish(CATALOG)

    def find_bank(self, *unused):
        catalogue, id_ = self.arguments(2)
        assert catalogue == CATALOG
        self.events.append(3)
        self.status = 5
        self.finish(BANK if self.strings[id_] in ('bank-A', 'bank-B') else 0)

    def bank_archive(self, *unused):
        bank, = self.arguments(1)
        assert bank == BANK
        self.events.append(4)
        self.finish(GNA)

    def member(self, *unused):
        bank, key = self.arguments(2)
        assert bank == GNA
        self.events.append(5)
        self.status = 7
        name = self.strings[key]
        self.finish(MEMBER if self.archive.member_path(self.image_bytes, name, self.clone) else 0)

    def open_sample(self, *unused):
        path, = self.arguments(1)
        assert path in (DISK, MEMBER)
        self.events.append(6)
        result = (None if self.name == '/disk/broken.wav' else b'disk') if path == DISK else self.archive.read_member()
        if result is None:
            self.status = 8
            self.finish()
            return
        self.status = 0
        sample = len(self.outputs) + 1
        self.outputs[sample] = result
        self.finish(sample)

    def run(self, image, descriptors, clone):
        self.cache, self.strings, self.outputs, self.events = {}, {}, {}, []
        self.image_bytes, self.clone, self.cache_writes = image, clone, 0
        self.put(0x3d47d8, 0)
        result = bytearray(struct.pack('<I', len(descriptors)))
        for i, (path, bank, owner) in enumerate(descriptors):
            sample = 0
            if path is None:
                self.status = 2
            elif not owner:
                self.status = 3
            elif bank is None:
                self.status = 4
            else:
                key = 0x540000 + i * 16
                self.strings[key] = path
                self.strings[key + 4] = bank
                sample = self.call(0x15f48c, 0, key + 4, key)
            status = self.status
            result.extend(struct.pack('<3BI', status, 4 if status == 7 else 0, 1 if status == 8 else 0, sample))
            if status == 0:
                chunk = self.outputs[sample]
                result.extend(struct.pack('<I', len(chunk)))
                result.extend(chunk)
                pcm, _ = pcm_reference(chunk) if chunk != b'disk' else (struct.pack('<I', 0), 0)
                result.extend(pcm)
        result.extend(struct.pack('<I', len(self.events)))
        result.extend(struct.pack('<' + 'I' * len(self.events), *self.events))
        return bytes(result)


def pcm_reference(chunk):
    with wave.open(io.BytesIO(chunk), 'rb') as source:
        frames = source.getnframes()
        assert source.getnchannels() == 2 and source.getsampwidth() == 2 and source.getframerate() == 44100
        samples = struct.unpack('<' + 'h' * (frames * 2), source.readframes(frames))
    left = struct.pack('<' + 'f' * frames, *(x / 32768.0 for x in samples[::2]))
    right = struct.pack('<' + 'f' * frames, *(x / 32768.0 for x in samples[1::2]))
    return struct.pack('<I', frames) + left + right, frames


def serialized_fixture(rows):
    f = Fixture()
    mappings = []
    for i, (path, bank, owner) in enumerate(rows, 3):
        props = [('midiNote', f.integer(36 + i))]
        if path is not None:
            props.append(('soundFilePath', f.text(path)))
        if bank is not None:
            props.append(('soundBankIdentifier', f.text(bank)))
        if owner:
            props.append(('@program', f.integer(1)))
        mappings.append(f.record(i, 'ETKeyMapping', props))
    keys = keyed_list(f, 2, list(range(3, len(mappings) + 3)))
    program = f.record(1, 'ETProgram', [('@keyMappings', f.integer(2))])
    f.envelope([program, keys, *mappings])
    return f, 2 + len(mappings)


def small_wave():
    output = io.BytesIO()
    with wave.open(output, 'wb') as writer:
        writer.setparams((2, 2, 44100, 0, 'NONE', 'not compressed'))
        writer.writeframes(struct.pack('<64h', *(i * 941 - 30000 for i in range(64))))
    return output.getvalue()


def scenarios(builtin):
    wav = small_wave()
    for layout in (0, 1):
        raw = archive([('Kit', b'', {'length': 0x8000000000000001}), ('Café.wav', wav, {'parent': 1}),
                       ('disk', b'', {'length': 0x8000000000000001}), ('absent.wav', wav, {'parent': 3})],
                      layout=layout)
        for clone in (0, 1):
            batch = [
                ('archive-cache', [('/Kit/Café.wav', 'bank-A', True), ('/Kit/Café.wav', 'bank-B', True),
                                   ('/Kit/Café.wav', 'missing', True)]),
                ('disk-priority', [('/disk/ok.wav', 'missing', True), ('/disk/ok.wav', 'bank-A', True),
                                   ('/disk/broken.wav', 'bank-A', True), ('/disk/broken.wav', 'bank-A', True),
                                   ('/disk/absent.wav', 'bank-A', True)]),
                ('retry-after-missing-bank', [('/Kit/Café.wav', 'missing', True),
                                              ('/Kit/Café.wav', 'bank-A', True)]),
                ('missing-member', [('/Kit/absent.wav', 'bank-A', True), ('/Kit', 'bank-B', True),
                                    ('/Kit/absent.wav', 'bank-A', True)]),
                ('unresolved-locators', [(None, 'bank-A', True), ('/Kit/Café.wav', 'bank-A', False),
                                         ('/Kit/Café.wav', None, True), ('/Kit/Café.wav', 'bank-A', True)]),
                ('invalid-member-path', [('Kit/Café.wav', 'bank-A', True), ('', 'bank-A', True)]),
            ]
            for label, rows in batch:
                yield f'{label}-layout-{layout}-clone-{clone}', raw, rows, clone
    raw = builtin.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == ARCHIVE_SHA
    for clone in (0, 1):
        rows = [(BUILTIN_WAVE, 'bank-A', True), (BUILTIN_WAVE, 'bank-A', True)]
        yield f'builtin-wave-clone-{clone}', raw, rows, clone


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def compare(binary, runner, prefix, platform, builtin):
    model = ProgramBeforeCatalogue(binary)
    lookup = SamplePathOracle(binary)
    probe = NativeProbe(prefix + [str(runner.resolve())], persistent=True)
    cases = []
    try:
        for name, bank, rows, clone in scenarios(builtin):
            fixture, count = serialized_fixture(rows)
            try:
                state = model.write_archive(fixture.objects)
                decoded = list(model.mappings(state, count))
                assert decoded == rows
                want = lookup.run(bank, decoded, clone)
            except Exception as error:
                raise RuntimeError(f'Original program sample fixture failed: {name}') from error
            actual = probe.run(struct.pack('<3I', len(state), len(bank), clone) + state + bank, len(want))
            if actual.returncode or actual.stdout != want:
                offset = next((i for i, (a, b) in enumerate(zip(want, actual.stdout)) if a != b), None)
                raise ValueError(f'{name}: mismatch at {offset}; expected {len(want)} bytes, '
                                 f'got {len(actual.stdout)} ({actual.stderr!r})')
            if name.startswith('builtin-wave'):
                chunk, = lookup.outputs.values()
                assert len(chunk) == 707036
                with wave.open(io.BytesIO(chunk), 'rb') as sample:
                    assert (sample.getnframes(), sample.getnchannels(), sample.getframerate()) == (176399, 2, 44100)
            outputs = [data for data in lookup.outputs.values() if data != b'disk']
            pcm = [pcm_reference(data) for data in outputs]
            cases.append({'case': name, 'state_sha256': sha(state), 'bank_sha256': sha(bank),
                          'result_sha256': sha(want), 'bytes': len(want), 'mappings': len(rows),
                          'loaded_member_bytes': sum(map(len, outputs)), 'member_sha256': [sha(x) for x in outputs],
                          'decoded_pcm_frames': sum(frames for _, frames in pcm),
                          'pcm_sha256': [sha(data[4:]) for data, _ in pcm],
                          'original_cache_writes': lookup.cache_writes})
    finally:
        probe.close()
    return {'checkpoint': 'ELA020', 'platform': platform, 'original_i386_sha256': SHA,
            'original_program_path_dispatch': '0x15f48c', 'original_archive_path_factory': '0xe1a68',
            'original_bank_members_read_in_separate_vm': True, 'native_program_state_and_gnfa_in_one_process': True,
            'host_bindings': ['programme property writes', 'system path and physical file tests',
                              'eligible mounted bank lookup', 'GN allocation, streams and objects'],
            'sample_file_open_boundary': 'Original path-dispatch caller bound to real GNFA reads; native uses translated sample-file factory',
            'actual_user_preset_used': False, 'protected_bank_used': False, 'audio_unit_built': False,
            'fixture_count': len(cases), 'mappings': sum(c['mappings'] for c in cases),
            'compared_bytes': sum(c['bytes'] for c in cases),
            'independent_pcm_reference': 'interleaved signed PCM16 divided by 32768 and compared on both float channels',
            'decoded_pcm_frames': sum(c['decoded_pcm_frames'] for c in cases), 'cases': cases}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original', type=Path)
    parser.add_argument('probe', type=Path)
    parser.add_argument('--runner-prefix', action='append', default=[])
    parser.add_argument('--builtin', type=Path, required=True)
    parser.add_argument('--platform', required=True)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    report = compare(args.original, args.probe, args.runner_prefix, args.platform, args.builtin)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(report, indent=2) + '\n')
    print(json.dumps({k: report[k] for k in ('fixture_count', 'mappings', 'compared_bytes', 'platform')}))
