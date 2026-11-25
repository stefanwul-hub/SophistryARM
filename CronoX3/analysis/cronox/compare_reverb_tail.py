#!/usr/bin/env python3
"""Compare the two original Intel schedulers with the static i386->C++ port.

The DSP callback is deliberately replaced by a counter producing exact zeros.
This tests the scheduling contract, not a preset's audio or its CPU load on Mac.
No synth instance, licence state, private preferences or registration are used.
"""
import argparse
import ctypes
import hashlib
import json
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tests'))
from compare_lifted_dsp import Original, Native
from legacy_image import LegacyImage
from unicorn import Uc, UC_ARCH_X86, UC_MODE_64, UC_HOOK_CODE
from unicorn.x86_const import (UC_X86_REG_RSP, UC_X86_REG_RAX, UC_X86_REG_RDI,
                              UC_X86_REG_RSI, UC_X86_REG_RDX, UC_X86_REG_EAX,
                              UC_X86_REG_RIP, UC_X86_REG_MXCSR)


class Original64:
    def __init__(self, data):
        assert struct.unpack_from('<II', data) == (0xfeedfacf, 0x1000007)
        self.uc = Uc(UC_ARCH_X86, UC_MODE_64)
        self.uc.mem_map(0, 0x4000000)
        at = 32
        for _ in range(struct.unpack_from('<I', data, 16)[0]):
            cmd, size = struct.unpack_from('<II', data, at)
            if cmd == 0x19:
                _, vm, _, off, count, *_ = struct.unpack_from('<16s4Q4I', data, at + 8)
                self.uc.mem_write(vm, data[off:off + count])
            at += size
        self.uc.reg_write(UC_X86_REG_MXCSR, 0x1f80)
        self.callbacks = {}
        self.uc.hook_add(UC_HOOK_CODE, self._instruction)

    def _instruction(self, uc, pc, size, user):
        if pc in self.callbacks:
            self.callbacks[pc](pc)

    def hook(self, pc, callback):
        self.callbacks[pc] = callback

    def write(self, p, data):
        self.uc.mem_write(p, data)

    def read(self, p, size):
        return bytes(self.uc.mem_read(p, size))

    def ret(self):
        sp = self.uc.reg_read(UC_X86_REG_RSP)
        pc = struct.unpack('<Q', self.read(sp, 8))[0]
        self.uc.reg_write(UC_X86_REG_RSP, sp + 8)
        self.uc.reg_write(UC_X86_REG_RIP, pc)

    def run(self, pc, args):
        for reg, value in zip((UC_X86_REG_RDI, UC_X86_REG_RSI, UC_X86_REG_RDX), args):
            self.uc.reg_write(reg, value)
        self.uc.reg_write(UC_X86_REG_RSP, 0x70eff8)
        self.write(0x70eff8, struct.pack('<Q', 0x500100))
        self.uc.emu_start(pc, 0x500100, count=10000)
        assert self.uc.reg_read(UC_X86_REG_RIP) == 0x500100

    def close(self):
        pass


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--library', type=Path, default=ROOT / 'work/cronox-core/liblift-whole.so')
    parser.add_argument('--output', type=Path, default=ROOT / 'work/reverb-tail-audit')
    opts = parser.parse_args()
    opts.output.mkdir(parents=True, exist_ok=True)
    i386 = (ROOT / 'reference/CronoX3.i386').read_bytes()
    x64 = (ROOT / 'reference/CronoX3.x86_64').read_bytes()
    mapped = bytes(LegacyImage(i386).mapped())
    lib = ctypes.CDLL(str(opts.library))
    backends = [Original(mapped, 0x4000000), Native(lib, mapped, 0x4000000), Original64(x64)]
    obj, vt, para, definition, buffer = 0x300000, 0x302000, 0x310000, 0x312000, 0x320000
    counts = [{} for _ in backends]

    def put(b, p, n, width=4):
        b.write(p, int(n).to_bytes(width, 'little', signed=False))

    for ix, b in enumerate(backends):
        def callback(pc, ix=ix, b=b):
            counts[ix]['render' if pc == 0x6f1000 else 'resume'] += 1
            if ix == 1:
                b.regwrite(0, bytes(4))
            else:
                b.uc.reg_write(UC_X86_REG_RAX if ix == 2 else UC_X86_REG_EAX, 0)
            b.ret()
        b.hook(0x6f1000, callback)
        b.hook(0x6f1010, callback)

    cases = []
    for rate in (44100, 48000, 96000):
        for frames in (64, 256, 1024):
            for decay in (.1, 2., 5.):
                for predelay in (0., 25., 125.):
                    for ix, b in enumerate(backends):
                        b.write(obj, bytes(0x900))
                        b.write(vt, bytes(0x400))
                        b.write(para, bytes(0x300))
                        b.write(definition, bytes(0x40))
                        b.write(buffer, bytes(0x100))
                        if ix < 2:
                            put(b, obj, vt)
                            for off, pc in ((0x140, 0x35a18), (0x134, 0x6f1000),
                                            (0x148, 0xd4d6e), (0x14c, 0x6f1010)):
                                put(b, vt + off, pc)
                            b.write(obj + 0xc, struct.pack('<f', rate))
                            put(b, obj + 0x120, buffer)
                            put(b, obj + 0x134, para)
                            b.write(para + 0x58, struct.pack('<f', decay))
                            b.write(para + 0x90, struct.pack('<f', predelay))
                            put(b, para + 0xd4, definition)
                            put(b, definition + 12, 9)
                            put(b, para + 0xd8, 9)
                        else:
                            put(b, obj, vt, 8)
                            for off, pc in ((0x280, 0x332f4), (0x268, 0x6f1000),
                                            (0x290, 0xc8a02), (0x298, 0x6f1010)):
                                put(b, vt + off, pc, 8)
                            b.write(obj + 0x14, struct.pack('<f', rate))
                            put(b, obj + 0x238, buffer, 8)
                            put(b, obj + 0x260, para, 8)
                            b.write(para + 0x98, struct.pack('<f', decay))
                            b.write(para + 0xf8, struct.pack('<f', predelay))
                            put(b, para + 0x168, definition, 8)
                            put(b, definition + 0x18, 9)
                            put(b, para + 0x170, 9)
                        counts[ix] = dict(render=0, resume=0)
                        put(b, buffer + (0x2c if ix == 2 else 0x1c), 1)
                        b.run(0x3328e if ix == 2 else 0x35990, [obj, frames])
                        put(b, buffer + (0x2c if ix == 2 else 0x1c), 0)
                    for k in range(25000):
                        before = counts[0]['render']
                        states = []
                        for ix, b in enumerate(backends):
                            b.run(0x3328e if ix == 2 else 0x35990, [obj, frames])
                            had_input = b.read(obj + (0x30a if ix == 2 else 0x1c2), 1)
                            remaining = struct.unpack('<i', b.read(obj + (0x30c if ix == 2 else 0x1c4), 4))[0]
                            states.append((had_input, remaining))
                        assert states[0] == states[1] == states[2], (rate, frames, decay, predelay, k, states)
                        assert counts[0] == counts[1] == counts[2], (k, counts)
                        if k == 0:
                            initial = states[0][1] + frames
                        if counts[0]['render'] == before:
                            break
                    else:
                        raise RuntimeError('Tail did not stop')
                    assert k == (initial + frames - 1) // frames
                    assert counts[0]['resume'] == 1
                    cases.append(dict(rate=rate, frames=frames, decay=decay, predelay_ms=predelay,
                                      initial_countdown=initial, rendered_tail_blocks=k, seconds=k * frames / rate))
                    if len(cases) % 9 == 0:
                        print('Intel i386 / Intel x86_64 / static C++ tail cases:', len(cases), flush=True)
    result = dict(scope='Isolated original scheduling, exact-zero DSP callback; not a full preset audio/CPU test',
                  original_i386_sha256=hashlib.sha256(i386).hexdigest(),
                  original_x86_64_sha256=hashlib.sha256(x64).hexdigest(),
                  cases=len(cases), all_counters_and_virtual_render_calls_bit_equal=True,
                  original_countdown_formula='1.4*(RevTime + predelay_seconds), folded predelay <=0.125s',
                  full_plugin_preset_reproduced=False, macos_cpu_measured=False,
                  discrepancy_with_user_observation_explained=False, passed=True,
                  examples=[c for c in cases if c['rate'] == 44100 and c['frames'] == 256 and c['predelay_ms'] == 25])
    (opts.output / 'cases-three-backends.json').write_text(json.dumps(cases, indent=2) + '\n')
    (opts.output / 'result-three-backends.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(result))
    for b in backends:
        b.close()


if __name__ == '__main__':
    main()
