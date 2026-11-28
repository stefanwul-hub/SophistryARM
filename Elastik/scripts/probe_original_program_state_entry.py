#!/usr/bin/env python3
"""Verify the original ETInstrument save/restore boundary with guest objects."""

import argparse
import json
import struct
from pathlib import Path

from legacy_image import SHA
from original_cache_oracle import OriginalCacheOracle
from unicorn import UC_HOOK_CODE

INSTRUMENT, OLD_PROGRAM, PROGRAM = 0x520000, 0x521000, 0x522000
MAPPINGS, MAPPING_A, MAPPING_B, DATA = 0x523000, 0x523100, 0x523200, 0x524000
ARCHIVER, UNARCHIVER = 0x525000, 0x525100
ARCHIVER_TABLE, UNARCHIVER_TABLE, PROGRAM_TABLE = 0x526000, 0x526400, 0x526800
SAVE_DATA, READ_DATA, IDENTITY, RETAIN, RELEASE = range(0x500900, 0x500950, 0x10)


class ProgramStateEntryOracle(OriginalCacheOracle):
    def __init__(self, binary):
        super().__init__(binary)
        self.trace = []
        self.allocations = iter((ARCHIVER, UNARCHIVER, UNARCHIVER))
        self.import_handlers['__Znwm'] = self.allocate
        hooks = {
            0x153fb6: self.construct_archiver, 0x120f0e: self.construct_unarchiver,
            0x2dfa6: self.identity, IDENTITY: self.identity, SAVE_DATA: self.save_data,
            READ_DATA: self.read_data, RETAIN: self.retain, RELEASE: self.release,
            0x29ddc: self.count, 0x2a364: self.get_mapping,
            0x14a6c0: self.has_sample, 0x14bcd4: self.resolve_sample,
        }
        for address, binding in hooks.items():
            self.uc.hook_add(UC_HOOK_CODE, binding, begin=address, end=address)

        # Keep the genuine ETInstrument vtable, including its program getter/setter.
        self.put(INSTRUMENT, 0x36d648)
        self.put(ARCHIVER_TABLE + 0x48, IDENTITY)
        self.put(ARCHIVER_TABLE + 0x298, SAVE_DATA)
        self.put(UNARCHIVER_TABLE + 0x48, IDENTITY)
        self.put(UNARCHIVER_TABLE + 0x29c, READ_DATA)
        self.put(PROGRAM_TABLE + 0x40, RETAIN, RELEASE)
        self.put(PROGRAM, PROGRAM_TABLE)
        self.put(OLD_PROGRAM, PROGRAM_TABLE)
        self.put(OLD_PROGRAM + 0x28, INSTRUMENT)
        self.put(PROGRAM + 0x1c, MAPPINGS)
        self.uc.mem_write(PROGRAM + 0x10, struct.pack('<d', 123.75))

    def allocate(self):
        obj = next(self.allocations)
        size, = self.arguments(1)
        assert size == (0x38 if obj == ARCHIVER else 0x34)
        self.finish(obj)

    def construct_archiver(self, *unused):
        obj, = self.arguments(1)
        assert obj == ARCHIVER
        self.put(obj, ARCHIVER_TABLE)
        self.finish(obj)

    def construct_unarchiver(self, *unused):
        obj, = self.arguments(1)
        assert obj == UNARCHIVER
        self.put(obj, UNARCHIVER_TABLE)
        self.finish(obj)

    def identity(self, *unused):
        obj, = self.arguments(1)
        self.finish(obj)

    def save_data(self, *unused):
        archiver, root = self.arguments(2)
        assert archiver == ARCHIVER and root == PROGRAM
        fmt = self.word(archiver + 0x30)
        assert fmt == 2
        self.trace.append({'operation': 'save-root', 'root': 'ETProgram', 'archive_format': fmt})
        self.finish(DATA)

    def read_data(self, *unused):
        unarchiver, data = self.arguments(2)
        assert unarchiver == UNARCHIVER and data == DATA
        self.trace.append({'operation': 'load-root', 'root': 'ETProgram'})
        self.finish(PROGRAM)

    def retain(self, *unused):
        obj, = self.arguments(1)
        assert obj == PROGRAM and self.word(INSTRUMENT + 0xbc) == PROGRAM
        self.trace.append({'operation': 'retain-new-program'})
        self.finish(obj)

    def release(self, *unused):
        obj, = self.arguments(1)
        assert obj == OLD_PROGRAM and self.word(obj + 0x28) == 0
        self.trace.append({'operation': 'detach-and-release-old-program'})
        self.finish()

    def count(self, *unused):
        mappings, = self.arguments(1)
        assert mappings == MAPPINGS
        self.finish(2)

    def get_mapping(self, *unused):
        mappings, index = self.arguments(2)
        assert mappings == MAPPINGS
        self.finish((MAPPING_A, MAPPING_B)[index])

    def has_sample(self, *unused):
        mapping, = self.arguments(1)
        assert mapping in (MAPPING_A, MAPPING_B)
        self.trace.append({'operation': 'check-key-mapping', 'index': int(mapping == MAPPING_B)})
        self.finish(int(mapping == MAPPING_B))

    def resolve_sample(self, *unused):
        mapping, = self.arguments(1)
        assert mapping == MAPPING_A
        self.trace.append({'operation': 'request-sample-load', 'index': 0})
        self.finish()

    def verify(self):
        self.put(INSTRUMENT + 0xbc, PROGRAM)
        assert self.call(0x1b416, INSTRUMENT) == DATA
        self.put(INSTRUMENT + 0xbc, OLD_PROGRAM)
        self.call(0x1b4aa, INSTRUMENT, 0)
        assert len(self.trace) == 1 and self.word(INSTRUMENT + 0xbc) == OLD_PROGRAM
        self.call(0x1b4aa, INSTRUMENT, DATA)
        assert self.word(INSTRUMENT + 0xbc) == PROGRAM
        assert self.word(PROGRAM + 0x28) == INSTRUMENT and self.word(OLD_PROGRAM + 0x28) == 0
        tempo = struct.unpack('<d', self.uc.mem_read(INSTRUMENT + 0x144, 8))[0]
        assert tempo == 123.75
        assert [r['operation'] for r in self.trace] == [
            'save-root', 'load-root', 'detach-and-release-old-program', 'retain-new-program',
            'check-key-mapping', 'request-sample-load', 'check-key-mapping']
        return {'original_i386_sha256': SHA,
                'routines_executed': ['0x1b416', '0x1551ce', '0x1b34c', '0x1b4aa',
                                      '0x1b2bc', '0x15f258', '0x15f752'],
                'null_input_keeps_program': True, 'resulting_tempo': tempo, 'trace': self.trace,
                'payload_serialization_and_decode_are_bindings': True,
                'mapping_sample_reads_are_bindings': True, 'actual_user_state_tested': False}


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('original', type=Path)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    result = ProgramStateEntryOracle(a.original).verify()
    a.output.parent.mkdir(parents=True, exist_ok=True)
    a.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result))
