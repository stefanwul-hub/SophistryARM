#!/usr/bin/env python3
"""Compare a missing-sample notification and a retry against original i386.

Only known one-button load-error alerts are acknowledged. No confirmations or
licence decisions are handled by these diagnostic adapters.
"""
import argparse
import ctypes
import hashlib
import json
import struct
from pathlib import Path
from probe_au_render import RenderHost, HostedNative, Original, ROOT, LegacyImage


class MissingSampleHost(RenderHost):
    def __init__(self, backend, image):
        super().__init__(backend, image)
        self.missing = True
        self.alerts = set()
        self.titles = []

    def callback(self, pc):
        name = self.names.get(pc)
        if name not in ['_fprintf', '_CreateStandardAlert', '_RunStandardAlert'] and not (name == '_fopen' and self.missing):
            return super().callback(pc)
        self.last_import = {'address': hex(pc), 'name': name}
        self.calls[name] += 1
        sp = self.b.esp()
        arg = lambda n: self.word(sp+4+4*n)
        result = 0
        if name == '_fopen':
            if not self.errno_pointer:
                self.errno_pointer = self.alloc(4)
            self.put(self.errno_pointer, 2)
        elif name == '_fprintf':
            if arg(0) != self.word(0x1037f8)+0xb0:
                raise ValueError('Unknown guest fprintf stream')
            result = len(self.formatted(self.string(arg(1)).decode('latin1'), sp+12))
        elif name == '_CreateStandardAlert':
            title = self.cf_string(arg(1))
            if arg(0) != 1 or title not in ['File Error - Load failed', 'Load Error', 'Instrument Load Error', 'Bank Load Error']:
                raise ValueError('Unhandled original dialog')
            token = self.alloc(16)
            self.alerts.add(token)
            self.titles.append(title)
            self.put(arg(4), token)
        elif name == '_RunStandardAlert':
            if arg(1) or arg(0) not in self.alerts:
                raise ValueError('Unknown original alert token')
            self.alerts.remove(arg(0))
            self.b.write(arg(2), struct.pack('<H', 1))
            self.frees.add(arg(0))
        if isinstance(self.b, Original):
            from unicorn.x86_const import UC_X86_REG_EAX
            self.b.uc.reg_write(UC_X86_REG_EAX, result & 0xffffffff)
        else:
            self.b.regwrite(0, struct.pack('<I', result & 0xffffffff))
        self.b.ret()


def run(library, output):
    image = LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes())
    backend = (HostedNative(ctypes.CDLL(str(library.resolve())), bytes(image.mapped()), 0x4000000)
               if library else Original(bytes(image.mapped()), 0x4000000))
    h = MissingSampleHost(backend, image)
    outer = 0x200000-0xec
    obj = 0x200000
    chunk = (ROOT/'reference/Presets/lightgarden 02 BT.FXP').read_bytes()[60:]
    error = None
    programs = {}

    def call(pc, *args):
        backend.run(pc, list(args))
        return h.eax()

    try:
        for pc in image.initializers:
            call(pc)
        call(0x48b0, outer, 0x70001000)
        for offset, value in [(0, 0xf2048), (8, 0xf21a8), (0xe4, 0xf21b4), (0xec, 0xf2208)]:
            h.put(outer+offset, value)
        call(0xa6a2a, outer)
        call(0x2918, outer)
        for name, missing in [('missing', True), ('reloaded', False)]:
            h.missing = missing
            backend.write(0x600000, chunk)
            if call(h.word(obj+0x24), obj+0x20, 24, 1, len(chunk), 0x600000, 0) != len(chunk):
                raise ValueError('Incomplete program restoration')
            # Match LegacyEngine::saveProgram's original program-name query.
            backend.write(0x5f0100, bytes(256))
            call(h.word(obj+0x24), obj+0x20, 5, 0, 0, 0x5f0100, 0)
            h.put(0x5f0000, 0)
            n = call(h.word(obj+0x24), obj+0x20, 23, 1, 0, 0x5f0000, 0)
            program = backend.read(h.word(0x5f0000), n)
            output.with_suffix('.'+name).write_bytes(program)
            programs[name] = {'bytes': n, 'sha256': hashlib.sha256(program).hexdigest(),
                              'sample_reference_retained': b'BT_cronox18.wav' in program}
    except Exception as exc:
        error = str(exc)
    result = {'backend': 'translated instructions' if library else 'original i386',
              'error': error, 'one_button_load_notifications': h.titles,
              'programs': programs, 'private_licence_or_preferences_used': False}
    output.write_text(json.dumps(result, indent=2)+'\n')
    backend.close()
    return result


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--library', type=Path)
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    result = run(args.library, args.output)
    print(json.dumps(result, indent=2))
    raise SystemExit(1 if result['error'] else 0)
