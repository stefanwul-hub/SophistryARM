"""Pinned original i386 execution for the sample cache and file test adapters."""
import struct
from legacy_image import LegacyImage
from unicorn import Uc, UC_ARCH_X86, UC_MODE_32, UC_HOOK_CODE
from unicorn.x86_const import (UC_X86_REG_ESP, UC_X86_REG_EIP, UC_X86_REG_EAX,
                               UC_X86_REG_EFLAGS, UC_X86_REG_MXCSR)

CACHE, BLOCKS, MAP, CLIENTS, POOL = 0x520000, 0x521000, 0x522000, 0x523000, 0x580000
STORAGE, STACK, RETURN = 0x600000, 0x70f000, 0x500400


class OriginalCacheOracle:
    def __init__(self, binary):
        self.image = LegacyImage(binary.read_bytes())
        self.uc = Uc(UC_ARCH_X86, UC_MODE_32)
        self.uc.mem_map(0, 0x800000)
        self.uc.mem_write(0, bytes(self.image.mapped()))
        self.diagnostics = []
        self.import_handlers = {}
        self.imports = {i['address']: i['name'] for i in self.image.stubs}
        self.uc.hook_add(UC_HOOK_CODE, self.import_call, begin=min(self.imports), end=max(self.imports) + 4)
        self.uc.hook_add(UC_HOOK_CODE, self.diagnostic, begin=0xab14, end=0xab14)

    def put(self, at, *values):
        self.uc.mem_write(at, struct.pack('<' + 'I' * len(values), *(v & 0xffffffff for v in values)))

    def word(self, at):
        return struct.unpack('<i', self.uc.mem_read(at, 4))[0]

    def finish(self, result=0):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        ret = self.word(sp) & 0xffffffff
        self.uc.reg_write(UC_X86_REG_EAX, result & 0xffffffff)
        self.uc.reg_write(UC_X86_REG_ESP, sp + 4)
        self.uc.reg_write(UC_X86_REG_EIP, ret)

    def arguments(self, count):
        sp = self.uc.reg_read(UC_X86_REG_ESP)
        return struct.unpack('<' + 'I' * count, self.uc.mem_read(sp + 4, count * 4))

    def import_call(self, uc, address, size, user):
        name = self.imports.get(address)
        if name == '_memcpy':
            destination, source, count = self.arguments(3)
            if count: uc.mem_write(destination, bytes(uc.mem_read(source, count)))
            self.finish(destination)
        elif name == '_memset':
            destination, value, count = self.arguments(3)
            if count: uc.mem_write(destination, bytes([value & 255]) * count)
            self.finish(destination)
        elif name in self.import_handlers:
            self.import_handlers[name]()
        else:
            raise ValueError(f'Unexpected original import {name} at {address:#x}')

    def diagnostic(self, uc, address, size, user):
        text_at, = self.arguments(1)
        text = bytes(uc.mem_read(text_at, 256)).split(b'\0', 1)[0]
        if text == b'_cache[%i].block = %i | _blocks[%i] = %i':
            values = [1] + [self.word(uc.reg_read(UC_X86_REG_ESP) + 8 + i * 4) for i in range(4)]
        elif text.startswith(b'GNSoundFileCache: buffer unnderrun at sample index '):
            values = [2] + [self.word(uc.reg_read(UC_X86_REG_ESP) + 8 + i * 4) for i in range(4)]
        elif text == b'GNSoundFile::getSamplesOfChannelForRange(): File already closed.':
            values = [3, 0, 0, 0, 0]
        elif text.startswith(b'Reading sound failed: We wanted to read '):
            values = [4] + [self.word(uc.reg_read(UC_X86_REG_ESP) + 8 + i * 4) for i in range(3)] + [0]
        elif text == b'GNAudioConvertSampleFormat(): Unsupported input format.':
            values = [5, 0, 0, 0, 0]
        elif text == b'GNAudioConvertSampleFormat(): Unsupported output format.':
            values = [6, 0, 0, 0, 0]
        elif text == b'getSamplesOfChannelForRange failed':
            values = [7, 0, 0, 0, 0]
        else:
            raise ValueError('Unexpected original diagnostic ' + repr(text))
        self.diagnostics.append(values)
        self.finish()

    def call_packed(self, address, packed):
        self.uc.mem_write(STACK, struct.pack('<I', RETURN) + packed)
        self.uc.reg_write(UC_X86_REG_ESP, STACK)
        self.uc.reg_write(UC_X86_REG_EFLAGS, 2)
        self.uc.reg_write(UC_X86_REG_MXCSR, 0x1f80)
        self.uc.emu_start(address, RETURN, count=2000000)
        if self.uc.reg_read(UC_X86_REG_EIP) != RETURN:
            raise ValueError(f'Original function {address:#x} did not return')
        result = self.uc.reg_read(UC_X86_REG_EAX)
        return result - (1 << 32) if result & 0x80000000 else result

    def call(self, address, *args):
        return self.call_packed(address, struct.pack('<' + 'I' * len(args), *(v & 0xffffffff for v in args)))

    def set_cache(self, h, ids, mapping, clients, pool):
        # Header: frames/chunk/channels/slot count/map count/client count/...
        allocated = max(1, h[3])
        self.uc.mem_write(CACHE, bytes(0x60))
        self.put(CACHE + 0x10, BLOCKS, MAP)
        self.put(CACHE + 0x1c, h[3])
        self.uc.mem_write(CACHE + 0x30, bytes([h[8] & 255]))
        self.put(CACHE + 0x40, CLIENTS, h[5])
        self.put(CACHE + 0x4c, h[0], h[1])
        for i in range(allocated): self.put(BLOCKS + i * 8, ids[i], POOL + i * h[1] * h[2] * 4)
        self.put(MAP, *mapping)
        for i, client in enumerate(clients): self.put(CLIENTS + i * 12, client[0] & 255, client[1], client[2])
        self.uc.mem_write(POOL, pool)
        self.diagnostics = []

    def cache_snapshot(self, h):
        clients = []
        for i in range(h[5]):
            clients += [self.uc.mem_read(CLIENTS + i * 12, 1)[0], self.word(CLIENTS + i * 12 + 4), self.word(CLIENTS + i * 12 + 8)]
        return (self.uc.mem_read(CACHE + 0x30, 1)[0], struct.pack('<' + 'i' * len(clients), *clients),
                bytes(self.uc.mem_read(MAP, h[4] * 4)),
                b''.join(struct.pack('<i', self.word(BLOCKS + i * 8)) for i in range(max(1, h[3]))),
                bytes(self.uc.mem_read(POOL, max(1, h[3]) * h[1] * h[2] * 4)))
