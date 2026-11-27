"""Run the original i386 XML reader and GN property-list projection in Unicorn."""

import re
import struct

from original_plist_oracle import PropertyListOracle, RUNES
from unicorn import UC_HOOK_CODE


class XmlPropertyListOracle(PropertyListOracle):
    def __init__(self, binary, base64_padding=0):
        super().__init__(binary)
        self.base64_padding = base64_padding
        hooks = {
            0xb122: self.noop,
            0x3887c: self.xml_string,
            0x3dd2a: self.xml_empty_string,
            0x39d7a: self.xml_scan_string,
            0x2803a: self.data_from_bytes,
            0x3e8aa: self.remove_characters,
            0x17d6b8: self.data_padding,
            0x1a7df0: self.date,
            0x1a7cfa: self.default_date,
        }
        for address, fn in hooks.items():
            self.uc.hook_add(UC_HOOK_CODE, fn, begin=address, end=address)
        self.import_handlers.update({
            '__Znam': self.allocate,
            '__ZdlPv': self.noop,
            '__ZdaPv': self.noop,
            '_malloc': self.allocate,
            '_free': self.noop,
            '_strlen': self.strlen,
            '_strcmp': self.strcmp,
            '_strncmp': self.strncmp,
            '_strcpy': self.strcpy,
            '_strncpy': self.strncpy,
            '_memmove': self.memmove,
            '_memcmp': self.memcmp,
            '_sscanf': self.sscanf,
            '___toupper': self.uppercase,
            '___maskrune': self.maskrune,
        })
        for b in b'0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz':
            self.uc.mem_write(RUNES + b * 4 + 0x35, bytes([0x05 if 48 <= b <= 57 else 0x01]))
        for b in b' \t\r\n\f\v':
            self.uc.mem_write(RUNES + b * 4 + 0x35, b'\x40')

    def skip_scanner_space(self, *unused):
        pass  # Execute the original 0x18ab46 scanner method.

    def xml(self, *unused):
        self.format = 0

    def setup(self, raw, has_reader):
        super().setup(raw, has_reader)
        self.dates = {}
        self.put(0x3d42c8, 0)
        self.put(0x3d4060, 0)

    def diagnostic(self, *unused):
        self.finish()

    def noop(self, *unused):
        self.finish()

    def cstr(self, ptr):
        data = bytearray()
        while len(data) < 8192:
            at = ptr + len(data)
            read = min(8192 - len(data), (at | 0xfff) + 1 - at)
            part = bytes(self.uc.mem_read(at, read))
            data.extend(part.split(b'\0', 1)[0])
            if 0 in part:
                return bytes(data)
        raise ValueError('Unterminated guest C string')

    def strlen(self):
        self.finish(len(self.cstr(self.arguments(1)[0])))

    def strcmp(self):
        a, b = map(self.cstr, self.arguments(2))
        self.finish((a > b) - (a < b))

    def strncmp(self):
        a, b, n = self.arguments(3)
        if not n:
            self.finish()
            return
        first = bytes(self.uc.mem_read(a, n)).split(b'\0', 1)[0]
        second = bytes(self.uc.mem_read(b, n)).split(b'\0', 1)[0]
        self.finish((first > second) - (first < second))

    def strcpy(self):
        dest, src = self.arguments(2)
        self.uc.mem_write(dest, self.cstr(src) + b'\0')
        self.finish(dest)

    def strncpy(self):
        dest, src, n = self.arguments(3)
        if n:
            data = bytes(self.uc.mem_read(src, n)).split(b'\0', 1)[0].ljust(n, b'\0')
            self.uc.mem_write(dest, data)
        self.finish(dest)

    def memmove(self):
        dest, src, n = self.arguments(3)
        if n:
            self.uc.mem_write(dest, bytes(self.uc.mem_read(src, n)))
        self.finish(dest)

    def memcmp(self):
        a, b, n = self.arguments(3)
        first, second = bytes(self.uc.mem_read(a, n)), bytes(self.uc.mem_read(b, n))
        self.finish((first > second) - (first < second))

    def sscanf(self):
        data, fmt = self.arguments(2)
        text = self.cstr(data)
        pattern = self.cstr(fmt)
        if pattern == b'%lld':
            match = re.match(rb'\s*([+-]?[0-9]+)', text)
            if match:
                result, = self.arguments(3)[2:]
                parsed = min(2**63 - 1, max(-2**63, int(match[1])))
                self.uc.mem_write(result, struct.pack('<q', parsed))
            self.finish(int(bool(match)))
            return
        if pattern == b'%d.%d.%d %d:%d:%d':
            fields = self.arguments(8)[2:]
            count = 0
            for index, dest in enumerate(fields):
                delimiter = (b'', b'.', b'.', b'', b':', b':')[index]
                if not text.startswith(delimiter):
                    break
                match = re.match(rb'\s*([+-]?[0-9]+)', text[len(delimiter):])
                if not match:
                    break
                self.put(dest, int(match[1]))
                text = text[len(delimiter) + match.end():]
                count += 1
            self.finish(count)
            return
        raise ValueError(f'Unexpected original sscanf format {pattern!r}')

    def uppercase(self):
        ch, = self.arguments(1)
        self.finish(ch - 32 if 97 <= ch <= 122 else ch)

    def maskrune(self):
        ch, mask = self.arguments(2)
        bits = 0
        if 48 <= ch <= 57:
            bits |= 0x400
        if 65 <= ch <= 90:
            bits |= 0x8100
        if 97 <= ch <= 122:
            bits |= 0x1100
        if ch < 128 and ch in b'0123456789ABCDEFabcdef':
            bits |= 0x10000
        if ch < 128 and ch in b' \t\r\n\f\v':
            bits |= 0x4000
        self.finish(bits & mask)

    def new_string(self, text):
        obj = self.reserve(32)
        self.set_string(obj, text)
        self.finish(obj)

    def xml_string(self, *unused):
        ptr, count, encoding = self.arguments(3)
        assert encoding == 1000
        raw = bytes(self.uc.mem_read(ptr, count))
        try:
            text = raw.decode('utf-8', 'surrogatepass')
        except UnicodeDecodeError:
            text = ''
        self.new_string(text)

    def xml_empty_string(self, *unused):
        ptr, = self.arguments(1)
        assert self.cstr(ptr) == b''
        self.new_string('')

    def xml_scan_string(self, *unused):
        ptr, count = self.arguments(2)
        self.new_string(bytes(self.uc.mem_read(ptr, count)).decode('latin-1'))

    def data_from_bytes(self, *unused):
        ptr, size = self.arguments(2)
        obj = self.reserve(32)
        self.init_data(obj, bytes(self.uc.mem_read(ptr, size)))
        self.finish(obj)

    def string_set_bytes(self, *unused):
        obj, addr, count, encoding = self.arguments(4)
        if encoding != 1000:
            super().string_set_bytes()
            return
        raw = bytes(self.uc.mem_read(addr, count))
        self.set_string(obj, raw.decode('utf-8', 'surrogatepass'))
        self.finish(obj)

    def remove_characters(self, *unused):
        obj, chars = self.arguments(2)
        self.new_string(self.strings[obj].translate({ord(ch): None for ch in self.strings[chars]}))

    def data_padding(self, *unused):
        if not self.base64_padding:
            return
        dest, encoded = self.arguments(2)
        token = re.match(rb'[A-Za-z0-9+/]*', self.cstr(encoded))
        count = ((len(token[0]) + 3) // 4) * 3 + 1
        self.uc.mem_write(dest, bytes([self.base64_padding]) * count)

    def dict_set(self, *unused):
        obj, value, key = self.arguments(3)
        self.dicts.setdefault(obj, {})[self.strings[key]] = value
        self.finish()

    def date(self, *unused):
        fields = self.arguments(6)
        obj = self.reserve(32)
        self.dates[obj] = b't\x00' + struct.pack('<6I', *fields)
        self.finish(obj)

    def default_date(self, *unused):
        obj, = self.arguments(1)
        self.put(obj, 0x522000)
        self.dates[obj] = b't\x01' + bytes(24)
        self.finish(obj)

    def output(self, ptr):
        if ptr in self.dates:
            return self.dates[ptr]
        if self.word(ptr) == 0x371a88:
            self.dicts.setdefault(ptr, {})
        marker = bytes(self.uc.mem_read(ptr + 0x10, 1))
        if marker == b'l':
            return b'q' + bytes(self.uc.mem_read(self.word(ptr + 0xc), 8))
        if marker == b'b':
            return marker + bytes([bool(self.word(ptr + 0xc))])
        return super().output(ptr)

    def run(self, raw, has_reader, parse=True):
        result = super().run(raw, has_reader, parse)
        return b'\x00\x01' if parse and result == b'\x00\x00' else result
