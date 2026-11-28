"""Execute pinned i386 GNKeyValue restore with bounded GN runtime bindings."""

import struct

from original_state_archive_oracle import DESCRIPTOR_BY_OBJECT, OBJECTS, StateArchiveReaderOracle
from unicorn import UC_HOOK_CODE

KEYED = 0x524000
DISPATCH = 0x524100
AUTORELEASE_VTABLE = 0x524400
MODEL_TABLES = 0x525000
PROPERTY_SET, MODEL_CTOR, NO_ACTION = 0x500850, 0x500860, 0x500870
MODEL_CLASSES = {
    'ETProgram': (0x15ecac, 0x3d47d4, 0x38c588),
    'ETKeyMapping': (0x1489c0, 0x3d479c, 0x38a768),
    'ETInstrument': (None, None, 0x36d648),
    'GNList': (None, None, 0x36e8e8),
}


class KeyedStateOracle(StateArchiveReaderOracle):
    def __init__(self, binary):
        super().__init__(binary)
        self.import_handlers.update({'_setjmp': self.ignore, '_strcmp': self.strcmp})
        hooks = {
            0x0bea2: self.ignore, 0x0bec0: self.ignore, 0x1ea42: self.ignore,
            0x1e688: self.autorelease_pool, 0x2dfa6: self.identity,
            0x29d44: self.new_list, 0x2d13c: self.append_list,
            0x2e288: self.class_test, 0x630b6: self.new_dictionary, 0x64626: self.get_key, 0x66284: self.set_key,
            0x1fcfc: self.class_lookup, 0x1fe74: self.register_class,
            0x20c18: self.register_member, 0x2035a: self.register_value,
            0x204a2: self.register_relationship, 0x3a042: self.substring, 0x3dd2a: self.format_number,
            0x1000ae: self.identity, 0x100532: self.identity, 0xaa362: self.property_descriptor,
            0xfe4d8: self.property_descriptor, 0xfe3a4: self.property_descriptor, 0x41be2: self.member_count,
            PROPERTY_SET: self.property_set, MODEL_CTOR: self.model_ctor, NO_ACTION: self.identity,
        }
        for address, fn in hooks.items():
            self.uc.hook_add(UC_HOOK_CODE, fn, begin=address, end=address)

        self.uc.mem_write(DISPATCH, bytes(self.uc.mem_read(0x3860e8, 0x2c0)))
        self.put(AUTORELEASE_VTABLE + 0x44, NO_ACTION)
        self.put(self.vtables['GNList'] + 0x48, NO_ACTION)
        self.model_tables = {}
        for i, (name, (registration, _, original_table)) in enumerate(MODEL_CLASSES.items()):
            table = MODEL_TABLES + i * 0x200
            self.uc.mem_write(table, bytes(self.uc.mem_read(original_table, 0x198)))
            self.put(table + 8, DESCRIPTOR_BY_OBJECT)
            for slot in (0x40, 0x44, 0x48, 0x54, 0x7c):
                self.put(table + slot, MODEL_CTOR if slot == 0x54 else NO_ACTION)
            if registration:
                self.put(table + 0x168, PROPERTY_SET)
            if name == 'ETInstrument':
                self.put(table + 0x6c, NO_ACTION)
            self.model_tables[name] = table

    def bytes_at(self, addr):
        return bytes(self.uc.mem_read(addr, 256)).split(b'\0', 1)[0]

    def strcmp(self):
        left, right = self.arguments(2)
        a, b = self.bytes_at(left), self.bytes_at(right)
        self.finish((a > b) - (a < b))

    def format_number(self, *unused):
        fmt, value = self.arguments(2)
        assert self.bytes_at(fmt) == b'%i'
        self.finish(self.string(str(value).encode('ascii')))

    def autorelease_pool(self, *unused):
        obj, = self.arguments(1)
        self.put(obj, AUTORELEASE_VTABLE)
        self.finish(obj)

    def new_list(self, *unused):
        obj, = self.arguments(1)
        self.registries[obj] = []
        self.put(obj, self.vtables['GNList'])
        self.finish(obj)

    def append_list(self, *unused):
        dst, src = self.arguments(2)
        self.registries[dst].extend(self.registries[src])
        self.finish()

    def new_dictionary(self, *unused):
        obj, = self.arguments(1)
        self.id_map = obj
        self.model_ids = {}
        self.finish(obj)

    def dictionary_key(self, obj):
        if not obj:
            return None
        is_number = self.object_types.get(obj) == 'GNNumber'
        if is_number:
            assert self.uc.mem_read(obj + 0x10, 1) == b'i'
            return self.word(obj + 0xc)
        return self.text(obj)

    def get_key(self, *unused):
        obj, key = self.arguments(2)
        if obj == self.id_map:
            result = self.model_ids.get(self.dictionary_key(key), 0)
        else:
            keys = self.registries[self.word(obj + 0xc)]
            values = self.registries[self.word(obj + 0x10)]
            match = self.dictionary_key(key)
            result = next((value for name, value in zip(keys, values) if self.dictionary_key(name) == match), 0)
        self.finish(result)

    def set_key(self, *unused):
        obj, value, key = self.arguments(3)
        assert obj == self.id_map
        self.model_ids[self.dictionary_key(key)] = value
        self.finish()

    def lookup_or_register(self, name):
        if name not in self.model_descriptors:
            descriptor = self.reserve(0x80)
            self.model_descriptors[name] = descriptor
            self.classes[descriptor] = (name, 0, self.string(name.encode('ascii')))
        return self.model_descriptors[name]

    def class_test(self, *unused):
        obj, key = self.arguments(2)
        self.finish(int(self.object_types.get(obj) == self.text(key).decode("ascii")))

    def class_lookup(self, *unused):
        key, = self.arguments(1)
        self.finish(self.model_descriptors.get(self.text(key).decode('ascii'), 0))

    def register_class(self, *unused):
        key, _, parent = self.arguments(3)
        name = self.text(key).decode('ascii')
        descriptor = self.lookup_or_register(name)
        self.put(descriptor + 0x40, self.model_descriptors[self.text(parent).decode('ascii')])
        self.finish(descriptor)

    def register_member(self, *unused):
        descriptor, member = self.arguments(2)
        name = self.classes[descriptor][0]
        self.member_names[name].append(self.text(self.word(member + 8)).decode('ascii'))
        self.finish()

    def substring(self, *unused):
        obj, first, count = self.arguments(3)
        body = self.text(obj)
        assert first + count <= len(body)
        self.finish(self.string(body[first:first + count]))

    def property_descriptor(self, *unused):
        key, _ = self.arguments(2)
        descriptor = self.reserve(0x18)
        self.put(descriptor + 0xc, key)
        self.finish(descriptor)

    def add_property(self, offset):
        descriptor, prop = self.arguments(2)
        target = self.word(descriptor + offset)
        if not target:
            target = self.reserve(0x20)
            self.registries[target] = []
            self.put(descriptor + offset, target)
        self.registries[target].append(prop)
        self.put(descriptor + 0x2c, 1)
        self.finish()

    def register_value(self, *unused):
        self.add_property(0x20)

    def register_relationship(self, *unused):
        self.add_property(0x24)

    def member_count(self, *unused):
        marker, = self.arguments(1)
        assert marker == 1
        self.finish(marker)

    def instantiate(self, *unused):
        descriptor, = self.arguments(1)
        if descriptor not in self.model_descriptors.values():
            return super().instantiate()
        name = self.classes[descriptor][0]
        obj = self.reserve(0x100)
        self.put(obj, self.model_tables[name])
        self.object_types[obj] = name
        self.registries[obj] = []
        self.model_objects.append(obj)
        self.finish(obj)

    def object_descriptor(self, *unused):
        obj, = self.arguments(1)
        if obj in self.model_objects:
            self.finish(self.model_descriptors[self.object_types[obj]])
        else:
            super().object_descriptor()

    def model_ctor(self, *unused):
        obj, keyed = self.arguments(2)
        assert keyed == KEYED and obj in self.model_objects
        self.finish(obj)

    def property_set(self, *unused):
        obj, value, name, flags = self.arguments(4)
        assert flags == 0 and len(self.model_ids) == self.expected_records
        self.property_trace.append((obj, self.text(name).decode('ascii'), value))
        self.finish()

    def write_archive(self, objects, class_order=None):
        self.model_objects = []
        return super().write_archive(objects, class_order)

    def load_keyed(self, raw, header, expected_records):
        self.model_descriptors = {}
        self.model_objects = []
        self.id_map = 0
        self.read_archive(raw, header)
        self.binary_refs = {ptr: ref for ref, ptr in enumerate([0] + self.registries[OBJECTS])}
        self.member_names = {name: [] for name in MODEL_CLASSES}
        self.property_trace = []
        self.expected_records = expected_records

        self.lookup_or_register('GNObject')
        for name, (entry, cache, _) in MODEL_CLASSES.items():
            if cache:
                self.put(cache, 0)
                assert self.call(entry) == self.model_descriptors[name]
            else:
                self.lookup_or_register(name)

        # GNList's original short numeric-key cache is a GNList itself.
        short_keys = self.reserve(0x20)
        self.registries[short_keys] = [self.string(str(i).encode('ascii')) for i in range(13)]
        self.put(0x3d400c, short_keys)
        self.uc.mem_write(KEYED, bytes(0x40))
        self.put(KEYED, DISPATCH)
        root = self.call(0x1211b0, KEYED, self.registries[OBJECTS][0])
        order = self.registries[self.word(KEYED + 0x1c)]
        self.record_ptrs = self.registries[self.word(KEYED + 0x18)]
        self.model_refs = {obj: self.binary_refs[record] for obj, record in zip(order, self.record_ptrs)}
        assert len(order) == len(self.model_ids) == expected_records and root == order[0]

        # Decode records and reflection results from the i386 return values.
        props = {}
        for name, descriptor in self.model_descriptors.items():
            ptr = self.call(0x21866, descriptor)
            props[name] = [self.text(key).decode('ascii') for key in self.registries[ptr]]
        return order, props

    def lookup(self, record, name):
        self.put(KEYED + 0x28, self.record_ptrs[record])
        key = self.string(name.encode('ascii'))
        present = self.call(0x1219d4, KEYED, key)
        ptr = self.call(0x1218f2, KEYED, key)
        return struct.pack('<B', present) + self.pack_value(ptr)

    def pack_value(self, ptr):
        if ptr in self.model_refs:
            return struct.pack('<BI', 1, self.model_refs[ptr])
        return struct.pack('<BI', 0, self.binary_refs[ptr])
