#!/usr/bin/env python3
"""Execute the original AU property 33, including its CF collection cache.

Compare with --library for the statically translated instructions. The optional
plist is a public test vector for the native Apple AU property, not a preset.
"""
import argparse
import ctypes
import json
import plistlib
import struct
from pathlib import Path
from probe_au_render import RenderHost, HostedNative, Original, ROOT, LegacyImage


class TextHost(RenderHost):
    SERVICES = {
        '_CFNumberCreate', '_CFDictionaryCreateMutable',
        '_CFDictionaryContainsKey', '_CFDictionaryGetValue',
        '_CFDictionaryAddValue', '_CFStringCreateWithSubstring',
        '_CFArrayCreate', '_CFRelease',
    }

    def retain(self, token):
        if token in self.opaque_handles:
            self.opaque_handles[token]['refs'] += 1

    def release(self, token):
        obj = self.opaque_handles.get(token)
        if obj is None:
            self.cf_string(token)
            return
        obj['refs'] -= 1
        if obj['refs']:
            return
        del self.opaque_handles[token]
        if obj['type'] == 'CFArray':
            for child in obj['value']:
                self.release(child)
        elif obj['type'] == 'CFDictionary':
            for key, value in obj['value']:
                self.release(key)
                self.release(value)

    def create(self, kind, value):
        token = self.alloc(16)
        self.opaque_handles[token] = {'type': kind, 'value': value, 'refs': 1}
        return token

    def callback(self, pc):
        name = self.names.get(pc)
        if name not in self.SERVICES:
            return super().callback(pc)
        self.last_import = {'address': hex(pc), 'name': name}
        self.calls[name] += 1
        sp = self.b.esp()
        arg = lambda n: self.word(sp + 4 + 4*n)
        result = 0
        if name == '_CFNumberCreate':
            if arg(1) != 10:
                raise ValueError('Expected guest kCFNumberLongType')
            result = self.create('CFNumber', struct.unpack('<i', self.b.read(arg(2), 4))[0])
        elif name == '_CFDictionaryCreateMutable':
            result = self.create('CFDictionary', [])
        elif name.startswith('_CFDictionary'):
            entries = self.opaque_handles[arg(0)]['value']
            number = self.opaque_handles[arg(1)]['value']
            found = next((v for k, v in entries
                          if self.opaque_handles[k]['value'] == number), 0)
            if name == '_CFDictionaryContainsKey':
                result = int(bool(found))
            elif name == '_CFDictionaryGetValue':
                result = found
            elif name == '_CFDictionaryAddValue' and not found:
                entries.append((arg(1), arg(2)))
                self.retain(arg(1))
                self.retain(arg(2))
        elif name == '_CFStringCreateWithSubstring':
            raw = self.cf_string(arg(1)).encode('utf-16-le')
            start, size = arg(2)*2, arg(3)*2
            if start + size > len(raw):
                raise ValueError('CF substring out of bounds')
            result = self.new_cf_string(raw[start:start+size].decode('utf-16-le'))
        elif name == '_CFArrayCreate':
            children = [self.word(arg(1)+4*i) for i in range(arg(2))]
            result = self.create('CFArray', children)
            for child in children:
                self.retain(child)
        elif name == '_CFRelease':
            self.release(arg(0))
        if isinstance(self.b, Original):
            from unicorn.x86_const import UC_X86_REG_EAX
            self.b.uc.reg_write(UC_X86_REG_EAX, result & 0xffffffff)
        else:
            self.b.regwrite(0, struct.pack('<I', result & 0xffffffff))
        self.b.ret()


def run(library, output, fixture=None):
    image = LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes())
    b = (HostedNative(ctypes.CDLL(str(library.resolve())), bytes(image.mapped()), 0x4000000)
         if library else Original(bytes(image.mapped()), 0x4000000))
    h = TextHost(b, image)
    outer = 0x200000 - 0xec
    records = []
    error = None
    stage = 'construct original AU'

    def call(pc, *args):
        b.run(pc, list(args))
        return h.eax()

    try:
        for pc in image.initializers:
            call(pc)
        call(0x48b0, outer, 0x70001000)
        for offset, value in [(0, 0xf2048), (8, 0xf21a8), (0xe4, 0xf21b4), (0xec, 0xf2208)]:
            h.put(outer+offset, value)
        call(0xa6a2a, outer)
        call(0x2918, outer)
        # Cache created by the original derived entry's constructor tail.
        h.put(outer+0x32b464, h.create('CFDictionary', []))
        h.put(0x5d0000, 0)
        if call(0x82cbe, outer, 0, 0x5d0100, 0x5d0000):
            raise ValueError('Parameter list')
        ids = struct.unpack('<'+'I'*h.word(0x5d0000), b.read(0x5d0100, h.word(0x5d0000)*4))
        tests = []
        for pid in ids:
            b.write(0x5d2000, bytes(84))
            if call(0x82d68, outer, 0, pid, 0x5d2000):
                raise ValueError('Parameter info')
            raw = b.read(0x5d2000, 84)
            minimum, maximum, default = struct.unpack_from('<3f', raw, 68)
            flags = struct.unpack_from('<I', raw, 80)[0]
            if flags & (1 << 21):
                tests.extend((pid, mode, value) for mode, value in [
                    ('minimum', minimum), ('default', default), ('maximum', maximum),
                    ('below', minimum-1), ('above', maximum+1), ('current', None)])
        tests.extend([(0, 'ordinary', 0.0), (603, 'invalid', None)])
        for pid, mode, value in tests:
            stage = f'property 33 id={pid} case={mode}'
            b.write(0x5d2500, struct.pack('<3I', pid, 0x5d2520 if value is not None else 0, 0))
            if value is not None:
                b.write(0x5d2520, struct.pack('<f', value))
            status = call(0x829fc, outer, 33, 0, 0, 0x5d2500)
            ptr = h.word(0x5d2508)
            record = {'id': pid, 'case': mode, 'current': value is None,
                      'value': float(value or 0),
                      'status': ctypes.c_int32(status).value,
                      'has_text': bool(ptr), 'text': h.cf_string(ptr) if ptr else ''}
            records.append(record)
            if ptr:
                h.release(ptr)
        stage = 'completed'
    except Exception as exc:
        error = str(exc)
    result = {'backend': 'translated C++' if library else 'original i386 / Unicorn',
              'scope': 'original AU property 33 with explicit CoreFoundation adapters',
              'stage': stage, 'error': error, 'cases': records,
              'host_import_calls': dict(h.calls)}
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(result, indent=2, ensure_ascii=False)+'\n')
    if fixture and not error:
        fixture.write_bytes(plistlib.dumps(records, sort_keys=False))
    b.close()
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--library', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--write-fixture', type=Path)
    args = parser.parse_args()
    result = run(args.library, args.output, args.write_fixture)
    print(json.dumps({k: v for k, v in result.items() if k != 'cases'}, indent=2))
    raise SystemExit(1 if result['error'] else 0)
