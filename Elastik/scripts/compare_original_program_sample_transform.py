#!/usr/bin/env python3
"""Compare the original file-tempo scanner and numeric pitch-preparation job."""

import argparse
import hashlib
import io
import itertools
import json
import struct
import wave
from pathlib import Path

from compare_original_file_archive import ARCHIVE_SHA, archive
from compare_original_keyed_state import Fixture
from compare_original_program_samples import BUILTIN_WAVE, ProgramBeforeCatalogue
from compare_original_program_state import keyed_list
from compare_original_program_voice import float_bits
from compare_original_state_archive import number
from inspect_state_archive import inspect_header
from legacy_image import SHA
from native_probe import NativeProbe
from original_cache_oracle import STACK
from original_keyed_state_oracle import KeyedStateOracle, NO_ACTION
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EBP, UC_X86_REG_ECX, UC_X86_REG_EIP, UC_X86_REG_MXCSR

MAPPING_PITCH = {'pitchShiftSemitones': (0x50, 'i'), 'pitchShiftCent': (0x54, 'i'),
                 'pitchShifterMode': (0x84, 'i'), 'userTempoFactor': (0x88, 'f')}
JOB_VTABLE = 0x394ee8
SOURCE_VTABLE = 0x538000
FILE, ASSET = 0x538800, 0x538900
PROCESSOR, LOCK, LOCK_VTABLE = 0x539000, 0x539100, 0x539200
CAPTURE_F64, RESULT = 0x503260, 0x503400


class TransformOracle(ProgramBeforeCatalogue):
    def __init__(self, binary):
        super().__init__(binary)
        for addr, handler in {
            0x34a88: self.character, 0x332e2: self.init_string, 0x376dc: self.in_characters,
            0x3788a: self.append_characters, 0x3b118: self.assign_string,
            0x15f48c: self.source_lookup, 0x14b707: self.observe_render_branch,
            0x14a5fd: self.initialize_tempo_local, 0x22f910: self.observe_processor,
        }.items():
            self.uc.hook_add(UC_HOOK_CODE, handler, begin=addr, end=addr)
        for slot in (0x48, 0x1cc, 0x1dc, 0x1ec):
            self.put(JOB_VTABLE + slot, NO_ACTION)
        self.put(SOURCE_VTABLE + 0x40, NO_ACTION)
        self.put(FILE, SOURCE_VTABLE)
        self.put(0x3d8b44, LOCK)
        self.put(LOCK, LOCK_VTABLE)
        self.put(LOCK_VTABLE + 0x1a4, NO_ACTION, 0, NO_ACTION)
        self.put(ASSET + 0xc, FILE)
        # Call the i386 x87-returning routine, then store its result as a double.
        self.uc.mem_write(CAPTURE_F64, b'\xff\x74\x24\x08\xff\x54\x24\x08\x83\xc4\x04\xdd\x1d' +
                          struct.pack('<I', RESULT) + b'\xc3')

    def f64(self, routine, obj):
        self.call(CAPTURE_F64, routine, obj)
        return bytes(self.uc.mem_read(RESULT, 8))

    def instantiate(self, *unused):
        count = len(self.model_objects)
        super().instantiate()
        if len(self.model_objects) > count:
            mapping = self.model_objects[-1]
            if self.object_types[mapping] == 'ETKeyMapping':
                self.put(mapping + 0x84, 4, float_bits(1.0))

    def property_set(self, *unused):
        obj, value, key, _ = self.arguments(4)
        name = self.text(key).decode('ascii')
        if name not in MAPPING_PITCH:
            return super().property_set()
        offset, tag = MAPPING_PITCH[name]
        assert bytes(self.uc.mem_read(value + 0x10, 1)) == tag.encode('ascii')
        bits = self.word(value + 0xc)
        self.put(obj + offset, self.word(bits) if tag == 'f' else bits)
        KeyedStateOracle.property_set(self)

    def set_string(self, obj, units):
        raw = units.encode('utf-16-le', 'surrogatepass')
        self.put(obj + 0xc, 0, self.memory(raw + b'\0\0'), len(raw) // 2)

    def utf16(self, obj):
        raw = self.string_units(obj).encode('utf-16-le', 'surrogatepass')
        return [x[0] for x in struct.iter_unpack('<H', raw)]

    def character(self, *unused):
        obj, index = self.arguments(2)
        self.finish(self.utf16(obj)[index])

    def string_length(self, *unused):
        obj, = self.arguments(1)
        self.finish(len(self.utf16(obj)))

    def substring(self, *unused):
        obj, first, count = self.arguments(3)
        body = self.string_units(obj).encode('utf-16-le', 'surrogatepass')
        assert (first + count) * 2 <= len(body)
        units = body[first * 2:(first + count) * 2].decode('utf-16-le', 'surrogatepass')
        if units.isascii():
            self.finish(self.string(units.encode('ascii')))
        else:
            out = self.reserve(0x20)
            self.put(out, self.vtables['GNString'])
            self.set_string(out, units)
            self.finish(out)

    def init_string(self, *unused):
        obj, = self.arguments(1)
        self.put(obj, self.vtables['GNString'])
        self.set_string(obj, '')
        self.finish(obj)

    def in_characters(self, *unused):
        obj, unit = self.arguments(2)
        self.finish(int(unit in self.utf16(obj)))

    def append_characters(self, *unused):
        obj, ptr, count = self.arguments(3)
        added = bytes(self.uc.mem_read(ptr, count * 2)).decode('utf-16-le', 'surrogatepass')
        self.set_string(obj, self.string_units(obj) + added)
        self.finish(obj)

    def assign_string(self, *unused):
        obj, source = self.arguments(2)
        self.set_string(obj, self.string_units(source))
        self.finish(obj)

    def observe_render_branch(self, *unused):
        self.render_requested = True
        # Stop at the real epilogue before entering the address formatter.
        self.uc.reg_write(UC_X86_REG_EIP, 0x14b92c)

    def initialize_tempo_local(self, *unused):
        # When no number is found the i386 code reads this unwritten local.
        # Seed it with zero to make the intended program-tempo fallback repeatable.
        self.put(self.uc.reg_read(UC_X86_REG_EBP) - 0x28, 0, 0)

    def source_lookup(self, *unused):
        program, bank, path = self.arguments(3)
        assert (program, bank, path) == self.source_args
        self.finish(FILE)

    def observe_processor(self, *unused):
        handle, frames, channels, rate, mode = self.arguments(5)
        assert handle == PROCESSOR + 0x80 and frames == 512 and channels == 2
        self.processor_arguments = (rate, mode)
        self.finish()

    def diagnostic(self, *unused):
        text, = self.arguments(1)
        if self.bytes_at(text) == b'no _elastiqueHandle':
            self.finish()
        else:
            super().diagnostic()

    def frame_length(self, frames, stretch):
        # Run the three instructions of the original worker's length calculation.
        self.put(STACK - 0x3c, frames)
        self.put(STACK - 0x4c, stretch)
        self.uc.reg_write(UC_X86_REG_EBP, STACK)
        self.uc.reg_write(UC_X86_REG_MXCSR, 0x1f80)
        self.uc.emu_start(0x1c4a55, 0x1c4a63, count=3)
        return self.uc.reg_read(UC_X86_REG_ECX)

    def run(self, raw, rate, frames):
        order, _ = self.load_keyed(raw, inspect_header(raw), 3)
        program = order[0]
        self.requests = []
        self.call(0x160ba8, program)
        mapping = self.registries[self.word(program + 0x1c)][0]
        self.source_args = (program, self.word(mapping + 0x28), self.word(mapping + 0x24))
        self.put(mapping + 0x8c, ASSET)
        self.uc.mem_write(FILE + 0x18, struct.pack('<d', rate))
        file_tempo = self.f64(0x14a5d8, mapping)
        ratio = struct.unpack('<d', self.f64(0x14ab7e, mapping))[0]
        self.render_requested = False
        assert self.call(0x14b680, mapping) == 0
        job = self.call(0x1c5456, mapping, 0, 0)
        assert self.word(job + 0x28) == FILE
        self.put(PROCESSOR + 0x80, 0)
        self.put(PROCESSOR + 0x98, job)
        self.processor_arguments = None
        self.call(0x1c4930, PROCESSOR)
        assert self.processor_arguments is not None
        processor_rate, mode = self.processor_arguments
        assert processor_rate == float_bits(rate)
        owner_tempo = struct.unpack('<d', self.uc.mem_read(program + 0x10, 8))[0]
        factor = struct.unpack('<f', self.uc.mem_read(mapping + 0x88, 4))[0]
        count = self.frame_length(frames, self.word(job + 0x14))
        return (struct.pack('<BB', 0, self.render_requested) + file_tempo + bytes(self.uc.mem_read(job + 0xc, 8)) +
                struct.pack('<ff', owner_tempo * factor, ratio) + bytes(self.uc.mem_read(job + 0x14, 16)) +
                struct.pack('<iI', mode, count))


def fixture(path, program_tempo, algorithm, semitones, cents, mode, factor):
    f = Fixture()
    attrs = [('midiNote', f.integer(36)), ('soundFilePath', f.text(path)), ('soundBankIdentifier', f.text('bank-A')),
             ('@program', f.integer(1))]
    fields = {'pitchShiftSemitones': semitones, 'pitchShiftCent': cents, 'pitchShifterMode': mode}
    attrs += [(key, f.add(number('i', value & 0xffffffff))) for key, value in fields.items() if value is not None]
    if factor is not None:
        attrs.append(('userTempoFactor', f.add(number('f', float_bits(factor)))))
    mapping = f.record(3, 'ETKeyMapping', attrs)
    listing = keyed_list(f, 2, [3])
    program = f.record(1, 'ETProgram', [('@keyMappings', f.integer(2)), ('formattedTempo', f.text(program_tempo)),
                                        ('algorithm', f.integer(algorithm))])
    f.envelope([program, listing, mapping])
    return f


def make_wave(rate, frames):
    output = io.BytesIO()
    with wave.open(output, 'wb') as writer:
        writer.setparams((2, 2, rate, 0, 'NONE', 'not compressed'))
        writer.writeframes(bytes(frames * 4))
    return output.getvalue()


def compare(binary, probe, prefix, platform, builtin):
    original = TransformOracle(binary)
    native = NativeProbe(prefix + [str(probe.resolve())], persistent=True)
    cases = []
    try:
        controls = [(None, None, None, None), (0, 0, 0, 1.0), (12, 0, 1, 1.0), (-7, 7, 2, 1.25),
                    (0, -17, 3, 0.75), (5, 16, 4, 1.0000001192092896), (12, -100, 4, 1.0)]
        filenames = ['01drm120elastik_2.WAV', '23-cab97.125take.WAV', 'abc124.010073345.aif.WAV',
                     'no-tempo.wav', 'abc-take0.00flat.WAV', 'abc99.1.2.WAV', '007café.5ghost.WAV',
                     '音源cTempo138.7.WAV', 'ABC.WAV']
        rows = list(itertools.product(filenames, controls))
        rows.append((BUILTIN_WAVE.removeprefix('/elastik/'), (0, 0, None, None)))
        rows.append((BUILTIN_WAVE.removeprefix('/elastik/'), (-5, 9, 4, 1.1)))
        builtin_data = builtin.read_bytes()
        assert hashlib.sha256(builtin_data).hexdigest() == ARCHIVE_SHA
        for index, (name, (semitones, cents, mode, factor)) in enumerate(rows):
            real_loop = index >= len(rows) - 2
            rate = 44100 if real_loop else (44100, 48000, 96000)[index % 3]
            frames = 176399 if real_loop else (1023, 512, 31, 1535)[index % 4]
            tempo = ('120', '120.000001', '95.175827', '141.6')[index % 4]
            if real_loop:
                path, raw_bank = BUILTIN_WAVE, builtin_data
            else:
                path = '/Kit/' + name
                raw_bank = archive([('Kit', b'', {'length': 0x8000000000000001}),
                                    (name, make_wave(rate, frames), {'parent': 1})], layout=index % 2)
            model = fixture(path, tempo, index % 3, semitones, cents, mode, factor)
            raw = original.write_archive(model.objects)
            want = original.run(raw, rate, frames)
            actual = native.run(struct.pack('<3I', len(raw), len(raw_bank), 2 | (index % 2)) + raw + raw_bank, len(want))
            if actual.returncode or actual.stdout != want:
                raise ValueError(f'case {index} ({name}, {tempo}, {factor}): {want.hex()} vs {actual.stdout.hex()} '
                                 f'{actual.stderr!r}')
            values = struct.unpack('<BBddffffiiii', want)
            cases.append({'case': index, 'source_name': name, 'bundled_loop': real_loop, 'source_frames': frames,
                          'source_rate': rate, 'file_tempo': values[2], 'target_tempo': values[4],
                          'tempo_ratio': values[5], 'stretch_ratio': values[6], 'pitch_ratio': values[7],
                          'shifter_mode': values[8], 'program_algorithm': values[9], 'processor_mode': values[10],
                          'output_frames': values[11],
                          'render_requested': bool(values[1]), 'result_sha256': hashlib.sha256(want).hexdigest()})
    finally:
        native.close()
    processor_modes = sorted({case['processor_mode'] for case in cases})
    assert processor_modes == list(range(6))
    return {'checkpoint': 'ELA025', 'platform': platform, 'original_i386_sha256': SHA,
            'fixture_count': len(cases), 'render_requests': sum(case['render_requested'] for case in cases),
            'direct_requests': sum(not case['render_requested'] for case in cases),
            'processor_modes': processor_modes,
            'bundled_loop_cases': sum(case['bundled_loop'] for case in cases),
            'original_functions': ['0x14a5d8', '0x14ab7e', '0x14b680', '0x1c5456', '0x1c4930'],
            'host_bindings': ['GN objects and properties', 'source file locator and source rate', 'pow',
                              'capture offline factory arguments',
                              'zero seed for the unwritten original tempo fallback local'],
            'original_cache_key_formatted': False, 'pitch_dsp_executed': False, 'native_audio_unit_built': False,
            'cases': cases}


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('original', type=Path)
    p.add_argument('probe', type=Path)
    p.add_argument('--runner-prefix', action='append', default=[])
    p.add_argument('--builtin', type=Path, required=True)
    p.add_argument('--platform', required=True)
    p.add_argument('--output', type=Path, required=True)
    args = p.parse_args()
    result = compare(args.original, args.probe, args.runner_prefix, args.platform, args.builtin)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k: result[k] for k in ('fixture_count', 'render_requests', 'direct_requests', 'platform')}))
