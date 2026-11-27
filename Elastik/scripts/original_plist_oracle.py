"""Run the i386 plist dispatcher, OpenStep grammar, and numeric scanners."""

import math
import struct

from original_cache_oracle import OriginalCacheOracle
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_EIP, UC_X86_REG_ESI

PATH, READER, VT, RUNES = 0x520000, 0x521000, 0x522000, 0x524000
HEAP, LIMIT = 0x540000, 0x6c0000
POW_RESULT, POW_RETURN = 0x530000, 0x530020


class InvalidOriginal(Exception):
    """A parser operation triggered an original GN exception."""


class PropertyListOracle(OriginalCacheOracle):
    def __init__(self, binary):
        super().__init__(binary)
        hooks = {
            0x0aecc: self.allocate,
            0x0a930: self.identity,
            0x0bfd6: self.raise_gn,
            0x2dc66: self.identity,
            0x2dfa6: self.identity,
            0x2dfe2: self.identity,
            0x2dffc: self.identity,
            0x2e0bc: self.identity,
            0x2926c: self.read_data,
            0x2765e: self.data_init,
            0x278d6: self.data_length,
            0x27abc: self.data_bytes,
            0x27b4e: self.identity,
            0x27bec: self.identity,
            0x332e2: self.string_init,
            0x33b90: self.literal,
            0x3788a: self.string_append,
            0x384d4: self.string_set_bytes,
            0x34b8e: self.identity,
            0x35d80: self.character_bounds,
            0x630b6: self.dict_init,
            0x66284: self.dict_set,
            0x29d44: self.list_init,
            0x2bb40: self.list_push,
            0x18bc7c: self.scanner_init,
            0x18ab46: self.identity,  # No skippable characters in numeric tokens.
            0x67103: self.xml,
            0x1a5eb8: lambda *args: setattr(self, 'format', 1),
            0x1a5f6c: lambda *args: setattr(self, 'format', 2),
            0x500610: self.reader,
            0x500620: self.read,
            0x500630: self.rewind,
            0x500640: self.resize_data,
        }
        for address, fn in hooks.items():
            self.uc.hook_add(UC_HOOK_CODE, fn, begin=address, end=address)
        self.import_handlers.update(
            __Znwm=self.allocate, ___tolower=self.lowercase, _pow=self.power, _strchr=self.strchr,
        )

        self.put(PATH, VT)
        self.put(VT + 0x248, 0x500610)
        self.put(READER, VT + 0x400)
        self.put(VT + 0x400 + 0x1a4, 0x500630)
        self.put(VT + 0x400 + 0x1ac, 0x500620)
        self.put(VT + 0x800 + 0x1a4, 0x500640)
        for base in (VT, VT + 0x800):
            for offset, target in [(0x40, 0x2dfe2), (0x44, 0x2dffc), (0x48, 0x2e0bc)]:
                self.put(base + offset, target)

        # The parser inlines Darwin's default C locale digit and xdigit bits.
        for ch in b'0123456789':
            self.uc.mem_write(RUNES + ch * 4 + 0x35, b'\x04')
        for ch in b'0123456789ABCDEFabcdef':
            self.uc.mem_write(RUNES + ch * 4 + 0x36, b'\x01')
        for ptr in self.image.pointers:
            if ptr['name'] == '__DefaultRuneLocale':
                self.put(ptr['address'], RUNES)
        self.uc.mem_write(POW_RETURN, b'\xdd\x05' + struct.pack('<I', POW_RESULT) + b'\xc3')

    def reserve(self, size):
        p = self.heap
        self.heap += (max(size, 1) + 15) & ~15
        if self.heap > LIMIT:
            raise ValueError('Original property-list fixture exceeded guest allocation arena')
        self.uc.mem_write(p, bytes(self.heap - p))
        return p

    def allocate(self, *unused):
        size, = self.arguments(1)
        self.finish(self.reserve(size))

    def identity(self, *unused):
        obj, = self.arguments(1)
        self.finish(obj)

    def raise_gn(self, *unused):
        exc, = self.arguments(1)
        name = self.strings.get(exc)
        if name not in ('GNAssertionException', 'GNNotImplementedException'):
            raise ValueError(f'Unexpected original GN exception {name!r}')
        raise InvalidOriginal(name)

    def lowercase(self):
        ch, = self.arguments(1)
        self.finish(ch + 32 if 65 <= ch <= 90 else ch)

    def strchr(self):
        address, ch = self.arguments(2)
        for i in range(8192):
            value = self.uc.mem_read(address + i, 1)[0]
            if value == (ch & 255):
                self.finish(address + i)
                return
            if not value:
                self.finish()
                return
        raise ValueError('Unterminated original C string')

    def power(self):
        base_low, base_high, exp_low, exp_high = self.arguments(4)
        base, exp = struct.unpack('<dd', struct.pack('<4I', base_low, base_high, exp_low, exp_high))
        try:
            result = math.pow(base, exp)
        except OverflowError:
            result = math.inf
        self.uc.mem_write(POW_RESULT, struct.pack('<d', result))
        self.uc.reg_write(UC_X86_REG_EIP, POW_RETURN)

    def reader(self, *unused):
        self.finish(READER if self.has_reader else 0)

    def read(self, *unused):
        obj, target, count = self.arguments(3)
        assert obj == READER and self.word(count) == 1
        if self.position == len(self.raw):
            self.put(count, 0)
            self.finish()
            return
        self.uc.mem_write(target, self.raw[self.position:self.position + 1])
        self.position += 1
        self.finish(1)

    def rewind(self, *unused):
        assert self.arguments(1) == (READER,)
        self.rewinds += 1
        self.position = 0
        self.finish()

    def read_data(self, *unused):
        assert self.arguments(1) == (PATH,)
        obj = self.reserve(32)
        self.init_data(obj, self.raw)
        self.finish(obj)

    def init_data(self, obj, content):
        addr = self.reserve(len(content))
        if content:
            self.uc.mem_write(addr, content)
        self.data[obj] = (addr, len(content))
        self.put(obj, VT + 0x800)

    def data_init(self, *unused):
        obj, = self.arguments(1)
        self.init_data(obj, b'')
        self.finish(obj)

    def data_length(self, *unused):
        obj, = self.arguments(1)
        self.finish(self.data[obj][1])

    def data_bytes(self, *unused):
        obj, = self.arguments(1)
        self.finish(self.data[obj][0])

    def resize_data(self, *unused):
        obj, size = self.arguments(2)
        old_addr, old_size = self.data[obj]
        contents = bytes(self.uc.mem_read(old_addr, min(old_size, size))).ljust(size, b'\0')
        self.init_data(obj, contents)
        self.finish()

    def set_string(self, obj, string):
        units = string.encode('utf-16-le', 'surrogatepass')
        raw = string.encode('ascii', errors='replace')
        chars = self.reserve(len(units) + 2)
        cstr = self.reserve(len(raw) + 1)
        if units:
            self.uc.mem_write(chars, units)
            self.uc.mem_write(cstr, raw)
        self.strings[obj] = string
        self.put(obj, VT)
        self.put(obj + 0xc, cstr, chars, len(units) // 2)

    def string_init(self, *unused):
        obj, = self.arguments(1)
        self.set_string(obj, '')
        self.finish(obj)

    def literal(self, *unused):
        addr, = self.arguments(1)
        obj = self.reserve(32)
        text = bytes(self.uc.mem_read(addr, 128)).split(b'\0', 1)[0]
        self.set_string(obj, text.decode('ascii'))
        self.finish(obj)

    def string_append(self, *unused):
        obj, addr, count = self.arguments(3)
        raw = bytes(self.uc.mem_read(addr, count * 2))
        text = self.strings.get(obj, '').encode('utf-16-le', 'surrogatepass') + raw
        self.set_string(obj, text.decode('utf-16-le', 'surrogatepass'))
        self.finish(obj)

    def string_set_bytes(self, *unused):
        obj, addr, count, encoding = self.arguments(4)
        assert encoding in (0, 9999)
        raw = bytes(self.uc.mem_read(addr, count))
        assert raw == self.raw
        self.set_string(obj, self.decoded[encoding])
        self.finish(obj)

    def decode_bytes(self, raw, mode):
        source = self.reserve(len(raw))
        target = self.reserve(len(raw) * 2 + 2)
        if raw:
            self.uc.mem_write(source, raw)
        units = self.call(0x189376, source, target, mode, len(raw))
        return bytes(self.uc.mem_read(target, units * 2)).decode('utf-16-le', 'surrogatepass')

    def character_bounds(self, *unused):
        obj, idx = self.arguments(2)
        if idx >= self.word(obj + 0x14):
            raise InvalidOriginal('GNString character position')

    def dict_init(self, *unused):
        obj, = self.arguments(1)
        self.put(obj, VT)
        self.dicts[obj] = {}
        self.finish(obj)

    def dict_set(self, *unused):
        obj, value, key = self.arguments(3)
        self.dicts[obj][self.strings[key]] = value
        self.finish()

    def list_init(self, *unused):
        obj, = self.arguments(1)
        self.put(obj, VT)
        self.arrays[obj] = []
        self.finish(obj)

    def list_push(self, *unused):
        obj, value = self.arguments(2)
        self.arrays[obj].append(value)
        self.finish()

    def scanner_init(self, *unused):
        obj, = self.arguments(1)
        scanner = self.reserve(24)
        self.put(scanner, 0x390d88, 0, 0, obj, 0, 0)
        self.finish(scanner)

    def xml(self, *unused):
        self.format = 0
        self.uc.reg_write(UC_X86_REG_ESI, 0)
        self.uc.reg_write(UC_X86_REG_EIP, 0x670f6)

    def setup(self, raw, has_reader):
        self.heap = HEAP
        self.raw = raw
        self.has_reader = has_reader
        self.position = self.rewinds = 0
        self.format = None
        self.strings, self.dicts, self.arrays, self.data = {}, {}, {}, {}

    def output(self, ptr):
        if ptr in self.strings:
            return b's' + encode_string(self.strings[ptr])
        if ptr in self.data:
            addr, size = self.data[ptr]
            return b'd' + word(size) + bytes(self.uc.mem_read(addr, size))
        if ptr in self.dicts:
            items = self.dicts[ptr]
            return b'm' + word(len(items)) + b''.join(encode_string(k) + self.output(v) for k, v in items.items())
        if ptr in self.arrays:
            items = self.arrays[ptr]
            return b'a' + word(len(items)) + b''.join(self.output(v) for v in items)
        marker = bytes(self.uc.mem_read(ptr + 0x10, 1))
        if marker == b'i':
            return marker + bytes(self.uc.mem_read(ptr + 0xc, 4))
        if marker == b'f':
            return marker + bytes(self.uc.mem_read(self.word(ptr + 0xc), 4))
        raise ValueError(f'Unrecognized original property value @{ptr:#x}')

    def run(self, raw, has_reader, parse=True):
        self.setup(raw, has_reader)
        if not parse:
            is_path = self.call(0x1a4cb0, PATH)
            if is_path:
                return b'\x01'
            data = self.reserve(32)
            self.init_data(data, raw)
            return bytes([2 if self.call(0x1a4e18, data) else 0])
        self.decoded = {
            0: self.decode_bytes(raw.split(b'\0', 1)[0], 0),
            9999: self.decode_bytes(raw, 1000),
        }
        try:
            result = self.call(0x6739a, PATH)
        except InvalidOriginal:
            result = 0
        if self.position or self.rewinds != int(has_reader):
            raise ValueError('Original path format probe did not rewind the reader')
        if self.format is None:
            raise ValueError('Original property-list dispatch did not select a branch')
        return bytes([self.format, 2 if result else 1 if self.format else 0]) + (self.output(result) if result else b'')


def word(n):
    return struct.pack('<I', n)


def encode_string(s):
    raw = s.encode('utf-16-le', 'surrogatepass')
    return word(len(raw) // 2) + raw
