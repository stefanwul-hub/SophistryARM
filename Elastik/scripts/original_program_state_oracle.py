"""Run original program initialization and finalization over a GN archive."""

import struct

from original_keyed_state_oracle import KEYED, MODEL_CLASSES, NO_ACTION, KeyedStateOracle
from original_plist_oracle import POW_RESULT, POW_RETURN, PropertyListOracle
from unicorn import UC_HOOK_CODE

PROGRAM_VALUES = {
    'autoselect': (0xc, 'b'), 'automapMode': (0x18, 'i'), 'algorithm': (0x30, 'i'),
    'syncUserTempoToFileTempo': (0x38, 'i'), 'formattedTempo': (0x34, 'p'),
    'keyMappings': (0x1c, 'p'), 'automationParameters': (0x20, 'p'),
}
KEY_VALUES = {
    'midiNote': (0x7c, 'i'), 'isUserKey': (0x68, 'b'),
    'soundFilePath': (0x24, 'p'), 'soundBankIdentifier': (0x28, 'p'), 'program': (0x78, 'p'),
}


class ProgramStateOracle(KeyedStateOracle):
    model_classes = MODEL_CLASSES | {'ETAutomationParameter': (None, None, 0x38c028)}
    finalize_models = True

    def __init__(self, binary):
        super().__init__(binary)
        self.put(self.model_tables['ETProgram'] + 0x54, 0x2df8a)
        self.put(self.model_tables['ETProgram'] + 0x7c, 0x160ba8)
        self.import_handlers['_pow'] = self.power
        self.uc.mem_write(POW_RETURN, b'\xdd\x05' + struct.pack('<I', POW_RESULT) + b'\xc3')
        bindings = {
            0x2dc66: self.identity, 0x2e0bc: self.identity,
            0x18bc7c: PropertyListOracle.scanner_init.__get__(self), 0x18ab46: self.skip_space,
            0x35d80: self.character, 0x349f4: self.string_length, 0x340ba: self.c_string,
            0x14a83e: self.bind_catalog, 0x14b252: self.ignore, 0x14bcd4: self.request_sample,
        }
        for address, binding in bindings.items():
            self.uc.hook_add(UC_HOOK_CODE, binding, begin=address, end=address)
        self.put(self.model_tables['ETAutomationParameter'] + 0x6c, NO_ACTION)

    power = PropertyListOracle.power

    def instantiate(self, *unused):
        before = len(self.model_objects)
        super().instantiate()
        if len(self.model_objects) != before:
            obj = self.model_objects[-1]
            if self.object_types[obj] == 'ETProgram':
                # ETProgram factory at 0x1601f0 sets this before virtual init.
                self.uc.mem_write(obj + 0x38, b'\1')

    def string_units(self, string):
        length = self.word(string + 0x14)
        if length != -1:
            return bytes(self.uc.mem_read(self.word(string + 0x10), length * 2)).decode(
                'utf-16-le', 'surrogatepass')
        return self.bytes_at(self.word(string + 0xc)).decode('ascii')

    def c_string(self, *unused):
        obj, = self.arguments(1)
        # Tempo fixtures use ASCII digits and punctuation in both encodings.
        self.put(obj + 0xc, self.memory(self.string_units(obj).encode('ascii') + b'\0'))
        self.finish()

    def string_length(self, *unused):
        obj, = self.arguments(1)
        self.finish(len(self.string_units(obj)))

    def character(self, *unused):
        obj, index = self.arguments(2)
        self.finish(ord(self.string_units(obj)[index]))

    def skip_space(self, *unused):
        scanner, = self.arguments(1)
        text = self.string_units(self.word(scanner + 0xc))
        pos = self.word(scanner + 0x14)
        while pos < len(text) and text[pos] in ' \t\r\n\v\f':
            pos += 1
        self.put(scanner + 0x14, pos)
        self.finish()

    def property_set(self, *unused):
        obj, value, key, _ = self.arguments(4)
        fields = PROGRAM_VALUES if self.object_types[obj] == 'ETProgram' else KEY_VALUES
        offset, kind = fields[self.text(key).decode('ascii')]
        if kind == 'p':
            self.put(obj + offset, value)
        else:
            assert self.uc.mem_read(value + 0x10, 1) == kind.encode('ascii')
            bits = self.word(value + 0xc)
            if kind == 'b':
                self.uc.mem_write(obj + offset, bytes([bits & 255]))
            else:
                self.put(obj + offset, bits)
        super().property_set()

    def bind_catalog(self, *unused):
        # Named synthetic banks are available if the mapping references its
        # program. The real post-decode reset runs for unmatched/default keys.
        obj, = self.arguments(1)
        self.finish(int(bool(self.word(obj + 0x78) and self.word(obj + 0x28))))

    def request_sample(self, *unused):
        obj, = self.arguments(1)
        self.requests.append(obj)
        self.finish()

    def output(self, raw, header, records):
        order, _ = self.load_keyed(raw, header, records)
        program = order[0]
        assert self.object_types[program] == 'ETProgram'
        self.requests = []
        instrument = self.reserve(0x150)
        self.call(0x1b2bc, instrument, program)
        assert self.word(instrument + 0xbc) == program and self.word(program + 0x28) == instrument
        tempo, = struct.unpack('<d', self.uc.mem_read(instrument + 0x144, 8))
        byte_at = lambda offset: self.uc.mem_read(program + offset, 1)[0]
        id_ = next(i for i, obj in self.model_ids.items() if obj == program)
        mappings = self.registries[self.word(program + 0x1c)]
        result = bytearray(struct.pack('<BIBBI2IdIiiII', 0, 0, 0, 0, 0, id_, self.model_refs[program], tempo,
                                       byte_at(0xc), self.word(program + 0x18), self.word(program + 0x30),
                                       bool(byte_at(0x38)), len(mappings)))
        requests = []
        for item in mappings:
            sample = self.word(item + 0x24)
            if sample:
                requests.append(item)
            user_key = self.uc.mem_read(item + 0x68, 1)[0]
            result.extend(struct.pack('<Ii4I', self.model_refs.get(item, 0), self.word(item + 0x7c),
                                      user_key, self.binary_refs[sample], self.binary_refs[self.word(item + 0x28)],
                                      self.model_refs.get(self.word(item + 0x78), 0)))
        assert requests == self.requests

        parameters = self.registries[self.word(program + 0x20)]
        result.extend(struct.pack('<I', len(parameters)))
        for i, item in enumerate(parameters, 1):
            ref = self.model_refs.get(item, 0)
            if not ref:
                assert self.word(item + 0x14) == i
            result.extend(struct.pack('<I', ref))
        return bytes(result), len(mappings), len(parameters), len(requests)
