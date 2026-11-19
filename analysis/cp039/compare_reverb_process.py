#!/usr/bin/env python3
"""Compare the original Reverb2 processing body with its unchanged static lift.

Synthetic stereo ports are explicit virtual callbacks. This tests the original
comb/allpass arithmetic, ring buffers and modulation state, not AU routing,
private presets, registration, whole-synth audio or CPU performance.
"""
import argparse
import ctypes
import hashlib
import json
import math
import random
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT / "tests"), str(ROOT / "scripts")]
from compare_lifted_dsp import Native, Original, SHA
from legacy_image import LegacyImage

OBJ, VT, INPUT_PORT, OUTPUT_PORT = 0x200000, 0x210000, 0x211000, 0x212000
INPUT_VT, OUTPUT_VT = 0x213000, 0x214000
LEFT, RIGHT, PREDELAY = 0x220000, 0x230000, 0x260000
CALLS = [0x500010, 0x500020, 0x500030, 0x500040]


class Ports:
    def __init__(self, backend):
        self.b = backend
        for address in CALLS:
            backend.hook(address, self.callback)

    def word(self, address):
        return struct.unpack("<I", self.b.read(address, 4))[0]

    def put(self, address, value):
        self.b.write(address, struct.pack("<I", value & 0xffffffff))

    def floating(self, address, value):
        self.b.write(address, struct.pack("<f", value))

    def callback(self, address):
        sp = self.b.esp()
        arg = lambda i: self.word(sp + 4 + 4 * i)
        if address == CALLS[0]:
            assert arg(0) == OUTPUT_PORT
            self.put(arg(1), 1)
            self.put(arg(2), 2)
            self.events.append("output_ports")
        elif address == CALLS[1]:
            assert arg(0) == INPUT_PORT
            self.put(arg(1), LEFT + self.input_offset * 4)
            self.put(arg(2), RIGHT + self.input_offset * 4)
            self.events.append("input_ports")
        elif address == CALLS[2]:
            assert arg(0) == OBJ
            channel = self.word(arg(1)) - 1
            assert channel in [0, 1]
            value = arg(2)
            assert math.isfinite(struct.unpack("<f", struct.pack("<I", value))[0])
            self.audio[channel].append(value)
        elif address == CALLS[3]:
            assert arg(0) == OUTPUT_PORT
            self.events.append("finish")
        self.b.ret()

    def setup(self, case):
        self.events, self.audio, self.input_offset = [], [[], []], 0
        self.regions = [(OBJ, 0x1000)]
        for address in [OBJ, VT, INPUT_PORT, OUTPUT_PORT, INPUT_VT, OUTPUT_VT]:
            self.b.write(address, bytes(0x1000))
        self.put(OBJ, VT)
        self.put(OBJ + 4 * 4, INPUT_PORT)
        self.put(OBJ + 0x46 * 4, OUTPUT_PORT)
        self.put(INPUT_PORT, INPUT_VT)
        self.put(OUTPUT_PORT, OUTPUT_VT)
        self.put(OUTPUT_VT + 0x2c, CALLS[0])
        self.put(INPUT_VT + 0x38, CALLS[1])
        self.put(VT + 0xcc, CALLS[2])
        self.put(OUTPUT_VT + 0x44, CALLS[3])
        rng = random.Random(case["seed"])
        count = max(case["frames"], 1)
        for channel, address in enumerate([LEFT, RIGHT]):
            values = [rng.uniform(-.4, .4) if case["signal"] == "noise"
                      else (.5 if i == channel else 0.0) for i in range(count)]
            self.b.write(address, struct.pack("<" + "f" * count, *values))
        def buffer(address, length):
            values = [rng.uniform(-.08, .08) for _ in range(length)]
            self.b.write(address, struct.pack("<" + "f" * length, *values))
            self.regions.append((address, length * 4))
        self.put(OBJ + 0x748, PREDELAY)
        self.put(OBJ + 0x754, 16)
        self.put(OBJ + 0x75c, 17)
        buffer(PREDELAY, 17)
        self.floating(OBJ + 0x868, .73)
        self.put(OBJ + 0x860, case["modulated"])
        self.put(OBJ + 0x864, case["allpass"])
        self.floating(OBJ + 0x1e0, .4)
        lengths = [5, 7, 11, 13, 17, 19, 23, 29]
        for channel in range(2):
            for i in range(8):
                base = OBJ + 0x1e4 + channel * 0x220 + i * 0x44
                pointer = 0x270000 + (channel * 8 + i) * 0x1000
                length = lengths[i]
                self.floating(base, .25 + .08 * i)
                self.put(base + 4, pointer)
                self.put(base + 8, length)
                self.put(base + 16, length - 1)
                self.floating(base + 24, -.02 + .005 * i)
                self.floating(base + 28, [0, .35, .95][i % 3])
                self.put(base + 48, i % 3)
                self.floating(base + 52, .98 if i % 2 else .02)
                self.floating(base + 60, -.17 if i % 2 else .13)
                self.put(base + 64, 3)
                buffer(pointer, length)
        for channel in range(2):
            for i in range(4):
                base = OBJ + 0x624 + channel * 0x90 + i * 24
                pointer = 0x290000 + (channel * 4 + i) * 0x1000
                length = lengths[i]
                self.floating(base, .3 + .1 * i)
                self.put(base + 4, pointer)
                self.put(base + 8, length)
                self.put(base + 16, length - 1)
                buffer(pointer, length)


def compare(args):
    original = (ROOT / "reference/Sophistry.i386").read_bytes()
    assert hashlib.sha256(original).hexdigest() == SHA
    mapped = bytes(LegacyImage(original).mapped())
    library = ctypes.CDLL(str(args.library.resolve()))
    hosts = [Ports(Original(mapped)), Ports(Native(library, mapped))]
    cases, compared_bytes, calls, output_samples = [], 0, 0, 0
    for frames in [0, 1, 7, 64, 256]:
        for modulated in [0, 1]:
            for allpass in [0, 1, 4]:
                for signal in ["impulse", "noise"]:
                    case = {"frames": frames, "modulated": modulated, "allpass": allpass,
                            "signal": signal, "seed": 39000 + len(cases)}
                    for host in hosts:
                        host.setup(case)
                    blocks = [frames] if frames != 256 else [1, 7, 64, 184]
                    for block in blocks:
                        for host in hosts:
                            host.b.run(0xb73a6, [OBJ, block])
                            host.input_offset += block
                        assert hosts[0].audio == hosts[1].audio, case
                        assert hosts[0].events == hosts[1].events, case
                        for address, length in hosts[0].regions:
                            a, b = hosts[0].b.read(address, length), hosts[1].b.read(address, length)
                            if a != b:
                                first = next(i for i, values in enumerate(zip(a, b)) if values[0] != values[1])
                                raise AssertionError((case, hex(address + first), a[first], b[first]))
                            compared_bytes += length
                        calls += 1
                    assert [len(x) for x in hosts[0].audio] == [frames, frames]
                    assert hosts[0].events == ["output_ports", "input_ports", "finish"] * len(blocks)
                    output_samples += 2 * frames
                    cases.append({**case, "blocks": blocks, "passed": True})
    for host in hosts:
        host.b.close()
    return {"checkpoint": "CP-039", "scope": __doc__.strip(), "original_sha256": SHA,
            "original_process_entry": "0xb73a6", "cases": cases,
            "case_count": len(cases), "differential_process_calls": calls,
            "output_float32_samples_compared": output_samples,
            "object_and_delay_buffer_state_bytes_compared": compared_bytes,
            "production_code_modified": False, "whole_synth_or_cpu_performance_tested": False,
            "mismatches": [], "passed": True}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--library", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    result = compare(args)
    args.output.write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps({k: v for k, v in result.items() if k not in ["cases", "scope"]}, indent=2))
