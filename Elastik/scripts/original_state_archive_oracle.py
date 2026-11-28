"""Generate state fixtures with the original i386 archive and object writers."""

import struct

from original_cache_oracle import OriginalCacheOracle
from unicorn import UC_HOOK_CODE

ARCHIVER, STREAM, DATA = 0x520000, 0x520100, 0x520200
CLASSES, OBJECTS, ARCHIVER_VTABLE = 0x520300, 0x520400, 0x521000
VTABLES, HEAP, BUFFER = 0x522000, 0x540000, 0x610000
CAPACITY = 0x60000
DESCRIPTOR_BY_OBJECT, CLASS_NUMBER, OBJECT_NUMBER = 0x500800, 0x500810, 0x500820

# Primary vtables recovered from the pinned image's GNU C++ RTTI.
CLASS_LAYOUTS = {
    'GNDictionary': (0x371a88, 0),
    'GNList': (0x36e8e8, 3),
    'GNString': (0x36ec68, 3),
    'GNNumber': (0x374468, 2),
    'GNData': (0x36e728, 0),
}


class StateArchiveOracle(OriginalCacheOracle):
    def __init__(self, binary):
        super().__init__(binary)
        hooks = {
            0x2ba66: self.ignore,
            0x29ddc: self.list_count,
            0x2a364: self.list_at,
            0x1fa72: self.class_version,
            0x1f4dc: self.class_name,
            0x33b90: self.string_literal,
            0x1b6980: self.check_registration,
            DESCRIPTOR_BY_OBJECT: self.object_descriptor,
            CLASS_NUMBER: self.class_number,
            OBJECT_NUMBER: self.object_number,
        }
        for address, fn in hooks.items():
            self.uc.hook_add(UC_HOOK_CODE, fn, begin=address, end=address)

        self.uc.mem_write(ARCHIVER_VTABLE, bytes(self.uc.mem_read(0x3937c8, 0x2cc)))
        self.put(ARCHIVER_VTABLE + 8, DESCRIPTOR_BY_OBJECT)
        self.put(ARCHIVER_VTABLE + 0x2c4, CLASS_NUMBER, OBJECT_NUMBER)
        self.vtables = {}
        for i, (name, (addr, _)) in enumerate(CLASS_LAYOUTS.items()):
            table = VTABLES + i * 0x200
            self.uc.mem_write(table, bytes(self.uc.mem_read(addr, 0x1a8)))
            self.put(table + 0x74, DESCRIPTOR_BY_OBJECT)
            self.put(table + 8, DESCRIPTOR_BY_OBJECT)
            self.vtables[name] = table

    def ignore(self, *unused):
        self.finish()

    def diagnostic(self, *unused):
        addr, = self.arguments(1)
        text = bytes(self.uc.mem_read(addr, 128)).split(b'\0', 1)[0]
        if text not in (b'encodeInt64() not implemented by %s', b'decodeInt64() not implemented by %s'):
            raise ValueError(f'Unexpected i386 state diagnostic {text!r}')
        self.int64_diagnostics += 1
        self.finish()


    def reserve(self, size):
        at = self.heap
        self.heap += (max(1, size) + 15) & ~15
        if self.heap >= BUFFER:
            raise ValueError('Synthetic GN objects exceeded their guest region')
        self.uc.mem_write(at, bytes(self.heap - at))
        return at

    def memory(self, raw):
        addr = self.reserve(len(raw))
        if raw:
            self.uc.mem_write(addr, raw)
        return addr

    def string(self, text):
        ptr = self.reserve(32)
        self.put(ptr, self.vtables['GNString'])
        self.put(ptr + 0xc, self.memory(text + b'\0'), 0, -1)
        return ptr

    def text(self, ptr):
        return bytes(self.uc.mem_read(self.word(ptr + 0xc), 128)).split(b'\0', 1)[0]

    def string_literal(self, *unused):
        addr, = self.arguments(1)
        self.finish(self.string(bytes(self.uc.mem_read(addr, 128)).split(b'\0', 1)[0]))

    def list_count(self, *unused):
        ptr, = self.arguments(1)
        self.finish(len(self.registries[ptr]))

    def list_at(self, *unused):
        ptr, index = self.arguments(2)
        self.finish(self.registries[ptr][index])

    def class_version(self, *unused):
        ptr, = self.arguments(1)
        self.finish(self.classes[ptr][1])

    def class_name(self, *unused):
        ptr, = self.arguments(1)
        self.finish(self.classes[ptr][2])

    def check_registration(self, *unused):
        archiver, name_ptr, version = self.arguments(3)
        name = self.text(name_ptr).decode('ascii')
        assert archiver == ARCHIVER and CLASS_LAYOUTS[name][1] == version and name in self.descriptors
        self.finish()

    def object_descriptor(self, *unused):
        obj, = self.arguments(1)
        self.finish(self.descriptors[self.object_types[obj]])

    def class_number(self, *unused):
        archiver, descriptor = self.arguments(2)
        assert archiver == ARCHIVER
        self.finish(self.registries[CLASSES].index(descriptor) + 1)

    def object_number(self, *unused):
        archiver, obj = self.arguments(2)
        assert archiver == ARCHIVER
        self.finish(self.registries[OBJECTS].index(obj) + 1)

    def populate(self, obj, name, value):
        if name == 'GNDictionary':
            self.put(obj + 0xc, *(self.pointers[ref] for ref in value))
        elif name == 'GNList':
            weak, allows_null, refs = value
            children = struct.pack('<' + 'I' * len(refs), *(self.pointers[ref] for ref in refs))
            self.put(obj + 0xc, self.memory(children), len(refs))
            self.uc.mem_write(obj + 0x18, bytes([weak, allows_null]))
        elif name == 'GNString':
            encoding, raw, mutable = value
            if encoding == 0:
                self.put(obj + 0xc, self.memory(raw + b'\0'), 0, -1)
            else:
                assert encoding == 5 and len(raw) % 2 == 0
                self.put(obj + 0xc, 0, self.memory(raw + b'\0\0'), len(raw) // 2)
            self.uc.mem_write(obj + 0x18, bytes([mutable]))
        elif name == 'GNNumber':
            kind, bits = value
            stored = self.memory(bits) if kind in 'fdl' else int.from_bytes(bits, 'little')
            self.put(obj + 0xc, stored)
            self.uc.mem_write(obj + 0x10, kind.encode('ascii'))
        elif name == 'GNData':
            self.put(obj + 0x18, self.memory(value), len(value))
        else:
            raise ValueError(f'Unknown synthetic class {name}')

    def write_archive(self, objects, class_order=None):
        self.heap = HEAP
        self.int64_diagnostics = 0
        class_order = list(dict.fromkeys(name for name, _ in objects)) if class_order is None else class_order
        self.descriptors = {name: self.reserve(0x80) for name in (*class_order, 'GNArchiver')}
        self.classes = {
            self.descriptors[name]: (name, CLASS_LAYOUTS.get(name, (0, 0))[1], self.string(name.encode('ascii')))
            for name in self.descriptors
        }
        self.pointers = [0] + [self.reserve(0x40) for _ in objects]
        self.object_types = {ARCHIVER: 'GNArchiver'}
        self.registries = {CLASSES: [self.descriptors[name] for name in class_order], OBJECTS: self.pointers[1:]}
        self.put(ARCHIVER, ARCHIVER_VTABLE)
        self.put(ARCHIVER + 0x18, OBJECTS, CLASSES, 0, 0, STREAM)
        self.put(STREAM + 0x10, 0, DATA, 0)
        self.put(DATA + 0x18, BUFFER, CAPACITY)
        for ptr, (name, value) in zip(self.pointers[1:], objects):
            self.object_types[ptr] = name
            self.put(ptr, self.vtables[name])
            self.populate(ptr, name, value)

        self.call(0x1b71e2, ARCHIVER)
        self.call(0x1b73d8, ARCHIVER)
        return bytes(self.uc.mem_read(BUFFER, self.word(STREAM + 0x10)))


UNARCHIVER, UNARCHIVER_VTABLE = 0x520500, 0x523000
READ_CLASS_VERSION, RESIZE_DATA = 0x500830, 0x500840


class StateArchiveReaderOracle(StateArchiveOracle):
    """Execute the original two-pass object loader with class/runtime bindings."""

    def __init__(self, binary):
        super().__init__(binary)
        self.import_handlers["__Znwm"] = self.allocate
        hooks = {
            0xaecc: self.allocate,
            0xb122: self.ignore,
            0x2a14a: self.ignore,
            0x2bb40: self.list_append,
            0x2dfe2: self.identity,
            0x2dffc: self.identity,
            0x1fdb0: self.instantiate,
            READ_CLASS_VERSION: self.read_class_version_slot,
            RESIZE_DATA: self.resize_data,
        }
        for address, fn in hooks.items():
            self.uc.hook_add(UC_HOOK_CODE, fn, begin=address, end=address)
        self.uc.mem_write(UNARCHIVER_VTABLE, bytes(self.uc.mem_read(0x393aa8, 0x2d4)))
        self.put(UNARCHIVER_VTABLE + 8, DESCRIPTOR_BY_OBJECT)
        self.put(UNARCHIVER_VTABLE + 0x270, READ_CLASS_VERSION)
        self.put(self.vtables['GNData'] + 0x1a4, RESIZE_DATA)

    def allocate(self, *unused):
        size, = self.arguments(1)
        self.finish(self.reserve(size))

    def identity(self, *unused):
        obj, = self.arguments(1)
        self.finish(obj)

    def instantiate(self, *unused):
        descriptor, = self.arguments(1)
        name = self.classes[descriptor][0]
        ptr = self.reserve(0x40)
        self.put(ptr, self.vtables[name])
        self.object_types[ptr] = name
        if name == 'GNList':
            self.registries[ptr] = []
        if name == 'GNString':
            self.put(ptr + 0x14, -1)
        self.finish(ptr)

    def list_append(self, *unused):
        ptr, item = self.arguments(2)
        self.registries[ptr].append(item)
        self.finish()

    def read_class_version_slot(self, *unused):
        receiver, ptr = self.arguments(2)
        assert receiver == UNARCHIVER
        name = self.text(ptr).decode('ascii')
        self.finish(self.classes[self.descriptors[name]][1])

    def resize_data(self, *unused):
        ptr, length = self.arguments(2)
        self.put(ptr + 0x18, self.reserve(length), length)
        self.finish()

    def read_archive(self, raw, header):
        """Use the synthetic class factory and real i386 body pass 0x1b92b4."""
        self.heap = HEAP
        self.int64_diagnostics = 0
        self.descriptors = {row['name']: self.reserve(0x80) for row in header['classes']}
        self.descriptors['GNUnarchiver'] = self.reserve(0x80)
        self.classes = {
            self.descriptors[row['name']]: (row['name'], row['version'], self.string(row['name'].encode()))
            for row in header['classes']
        }
        self.classes[self.descriptors['GNUnarchiver']] = ('GNUnarchiver', 0, self.string(b'GNUnarchiver'))
        self.object_types = {UNARCHIVER: 'GNUnarchiver'}
        names = [row['name'] for row in header['classes']]
        class_ptrs = [self.descriptors[name] for name in names]
        class_array = self.memory(struct.pack('<' + 'I' * len(class_ptrs), *class_ptrs))
        self.put(CLASSES + 0xc, class_array, len(class_ptrs))
        self.registries = {CLASSES: class_ptrs, OBJECTS: []}

        self.put(UNARCHIVER, UNARCHIVER_VTABLE)
        self.put(UNARCHIVER + 0x18, OBJECTS, CLASSES, 0, STREAM, 1, 0, 0)
        self.put(STREAM + 0x10, header['body_offset'] - 5 * (header['object_count'] + 1), DATA, 0)
        self.put(DATA + 0x18, BUFFER, len(raw))
        self.uc.mem_write(BUFFER, raw)
        self.put(0x3d400c, 1)  # Unused keyed number-string cache in the binary list path.
        if self.call(0x1b92b4, UNARCHIVER) != 1 or self.word(STREAM + 0x10) != len(raw):
            raise ValueError('Original body loader did not finish the archive')
        pointers = self.registries[OBJECTS]
        index_by_pointer = {ptr: i for i, ptr in enumerate([0] + pointers)}
        result = []
        for ptr in pointers:
            name = self.object_types[ptr]
            if name == 'GNDictionary':
                fields = tuple(index_by_pointer[self.word(ptr + off)] for off in (0xc, 0x10))
            elif name == 'GNList':
                weak, nullable = self.uc.mem_read(ptr + 0x18, 2)
                fields = (bool(weak), bool(nullable), [index_by_pointer[x] for x in self.registries[ptr]])
            elif name == 'GNString':
                encoding = 0 if self.word(ptr + 0x14) == -1 else 5
                if encoding == 0:
                    self.call(0x358be, ptr)
                length = self.word(ptr + 0x14)
                at = self.word(ptr + 0x10)
                body = bytes(self.uc.mem_read(at, length * 2)) if length else b''
                fields = (encoding, bool(self.uc.mem_read(ptr + 0x18, 1)[0]), body)
            elif name == 'GNNumber':
                kind = chr(self.uc.mem_read(ptr + 0x10, 1)[0])
                cell = self.word(ptr + 0xc) & 0xffffffff
                length = {'f': 4, 'd': 8, 'l': 8}.get(kind, 0)
                bits = int.from_bytes(self.uc.mem_read(cell, length), 'little') if length else cell
                fields = (kind, bits, kind != 'l')
            else:
                at, size = self.word(ptr + 0x18), self.word(ptr + 0x1c)
                fields = bytes(self.uc.mem_read(at, size)) if size else b''
            result.append((name, fields))
        return result
