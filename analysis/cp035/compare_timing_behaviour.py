#!/usr/bin/env python3
"""Compare original i386 timing-dependent decisions with the unchanged CP032 lift.

These are isolated, public synthetic fixtures, without registration or presets.
OS imports and virtual notification consumers are controlled explicitly. They
test the original decisions, not the complete synth, its CPU cost or AU hosting.
"""

import argparse
import ctypes
import hashlib
import json
import random
import struct
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT / "tests"), str(ROOT / "scripts")]
from compare_lifted_dsp import Native, Original, SHA
from legacy_image import LegacyImage
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EDX

OBJ, TABLE, PARAM = 0x200000, 0x220000, 0x230000
INST_A, INST_B, VTABLE = 0x240000, 0x241000, 0x250000
TIMER, QUEUE = 0x260000, 0x270000


class Harness:
    def __init__(self, backend, image):
        self.b = backend
        self.callbacks = []
        self.clock_queries = 0
        self.synthetic_ticks = 0
        self.now_ticks = 0
        self.synthetic = False
        wanted = {
            "_mach_timebase_info", "_mach_absolute_time",
            "_OSAtomicAdd32Barrier", "_pthread_mutex_lock",
            "_pthread_mutex_unlock", "_strcmp", "_SetEventLoopTimerNextFireTime",
        }
        self.names = {x["address"]: x["name"] for x in image.stubs
                      if x["name"] in wanted}
        assert set(self.names.values()) == wanted
        self.notices = {0x500040: ("slot_0x29c", 1),
                        0x500050: ("slot_0x2a4", 3),
                        0x500060: ("slot_0x2a0", 3),
                        0x500070: ("slot_0x364", 4),
                        0x500080: ("slot_0x2a8", 1),
                        0x500090: ("slot_0x2ac", 1),
                        0x5000a0: ("slot_0x318", 1),
                        0x5000b0: ("slot_0x32c", 5)}
        for pc in [*self.names, 0x500010, 0x500020, 0x500030, *self.notices]:
            self.b.hook(pc, self.service)

    def word(self, pc):
        return struct.unpack("<I", self.b.read(pc, 4))[0]

    def put(self, pc, value):
        self.b.write(pc, struct.pack("<I", value & 0xffffffff))

    def string(self, pc):
        text = bytearray()
        for i in range(512):
            value = self.b.read(pc + i, 1)[0]
            if value == 0:
                return bytes(text)
            text.append(value)
        raise AssertionError("Fixture string exceeds its bound")

    def register(self, offset, value):
        if isinstance(self.b, Original):
            self.b.uc.reg_write(UC_X86_REG_EAX if offset == 0 else
                               UC_X86_REG_EDX, value & 0xffffffff)
        else:
            self.b.regwrite(offset, struct.pack("<I", value & 0xffffffff))

    def eax(self):
        if isinstance(self.b, Original):
            return self.b.uc.reg_read(UC_X86_REG_EAX)
        out = ctypes.create_string_buffer(4)
        assert not self.b.l.sl_reg_read(self.b.c, 0, out, 4)
        return struct.unpack("<I", out.raw)[0]

    def reset(self, synthetic=False):
        for address, length in [(OBJ, 0xe000), (TABLE, 0x1000),
                                (PARAM, 0x100), (INST_A, 0x200),
                                (INST_B, 0x200), (VTABLE, 0x1000),
                                (TIMER, 0x100), (QUEUE, 0x1000)]:
            self.b.write(address, bytes(length))
        self.b.write(0xfc210, bytes(8))
        self.b.write(OBJ - 0xec + 0x32b418, b"\0")
        self.synthetic = synthetic
        self.synthetic_ticks = self.now_ticks = self.clock_queries = 0
        self.callbacks = []

    def at_ms(self, milliseconds):
        self.now_ticks = milliseconds * 1000000

    def service(self, pc):
        sp = self.b.esp()
        arg = lambda i: self.word(sp + 4 + i * 4)
        result = 0
        name = self.names.get(pc)
        if name == "_mach_timebase_info":
            self.put(arg(0), 1)
            self.put(arg(0) + 4, 1)
        elif name == "_mach_absolute_time":
            self.clock_queries += 1
            if self.synthetic:
                self.synthetic_ticks += 1000
            ticks = self.synthetic_ticks if self.synthetic else self.now_ticks
            result = ticks & 0xffffffff
            self.register(8, ticks >> 32)
        elif name == "_OSAtomicAdd32Barrier":
            result = (self.word(arg(1)) + arg(0)) & 0xffffffff
            self.put(arg(1), result)
        elif name in ["_pthread_mutex_lock", "_pthread_mutex_unlock"]:
            # A valid uncontended mutex in this isolated fixture.
            pass
        elif name == "_strcmp":
            a, b = self.string(arg(0)), self.string(arg(1))
            result = (a > b) - (a < b)
        elif name == "_SetEventLoopTimerNextFireTime":
            delay = struct.unpack("<d", self.b.read(sp + 8, 8))[0]
            self.callbacks.append(["reschedule", arg(0), delay])
        elif pc == 0x500010:
            self.callbacks.append(["voice_notice", arg(0), arg(1), arg(2)])
        elif pc == 0x500020:
            self.callbacks.append(["queued_notice", self.b.read(arg(1), 24).hex()])
        elif pc == 0x500030:
            self.callbacks.append(["tooltip_notice", arg(1)])
        elif pc in self.notices:
            label, count = self.notices[pc]
            self.callbacks.append([label, *[arg(i) for i in range(count)]])
        else:
            raise AssertionError((pc, name))
        self.register(0, result)
        self.b.ret()

    def call(self, pc, *args):
        self.b.run(pc, list(args))
        return self.eax()


def run(library):
    raw = (ROOT / "reference/Sophistry.i386").read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA
    image = LegacyImage(raw)
    mapped = bytes(image.mapped())
    lib = ctypes.CDLL(str(library.resolve()))
    hosts = [Harness(Original(mapped), image), Harness(Native(lib, mapped), image)]
    cases = Counter()
    compared_bytes = 0

    def compare(kind, regions, scalar=False):
        nonlocal compared_bytes
        if scalar:
            assert hosts[0].eax() == hosts[1].eax(), (kind, "return")
        assert hosts[0].callbacks == hosts[1].callbacks, (kind, "callbacks")
        assert hosts[0].clock_queries == hosts[1].clock_queries
        for address, size in regions:
            expected = hosts[0].b.read(address, size)
            actual = hosts[1].b.read(address, size)
            assert expected == actual, (kind, hex(address))
            compared_bytes += size
        cases[kind] += 1

    rng = random.Random(35032)
    capabilities = {}
    for query in ["supplyIdle", "receiveVstEvents", "receiveVstMidiEvent",
                  "sendVstEvents", "sendVstMidiEvent", "receiveVstTimeInfo",
                  "offline", "x-unsupported"]:
        for h in hosts:
            h.reset()
            h.b.write(PARAM, query.encode() + b"\0")
            h.call(0x3286, OBJ - 0xec, PARAM)
        compare("original_au_capabilities", [(PARAM, len(query) + 1)], True)
        capabilities[query] = hosts[0].eax()
    assert capabilities["supplyIdle"] == 1
    assert capabilities["x-unsupported"] == 0
    for trial in range(512):
        count = rng.choice([1, 2, 4, 8, 16])
        rows = []
        for index in range(count):
            rows.append([rng.choice([1, 2]), rng.randrange(4), INST_A,
                         rng.randrange(36, 97), 100, rng.randrange(16),
                         0, rng.randrange(1, 1000), rng.randrange(1000, 2000)])
        request = [rng.randrange(5), rng.randrange(36, 97),
                   rng.choice([0, 1, 5, 15, 16])]
        for h in hosts:
            h.reset()
            h.put(OBJ + 12, count)
            h.put(OBJ + 16, TABLE)
            h.b.write(TABLE, b"".join(struct.pack("<9I", *r) for r in rows))
            h.at_ms(5000 + trial)
            h.call(0x2eede, OBJ, *request)
        compare("voice_selection", [(OBJ, 32), (TABLE, 36 * count)], True)

    for initial in range(4):
        for target in range(4):
            for replacement in [0, INST_A, INST_B]:
                for h in hosts:
                    h.reset()
                    h.put(OBJ + 12, 4)
                    h.put(OBJ + 16, TABLE)
                    h.put(OBJ + 20, int(initial != 0))
                    h.put(OBJ + 24, int(initial == 1))
                    for p in [INST_A, INST_B]:
                        h.put(p, VTABLE)
                    h.put(VTABLE + 0x8c, 0x500010)
                    h.put(INST_A + 0x14c, int(initial != 0))
                    h.put(INST_A + 0x154, int(initial == 1))
                    h.b.write(TABLE, struct.pack("<9I", initial, 0, INST_A,
                                                60, 100, 0, 0, 1, 2))
                    h.call(0x2f468, OBJ, 0, target, replacement)
                compare("voice_state_transition", [(OBJ, 32), (TABLE, 144),
                                                     (INST_A, 0x158),
                                                     (INST_B, 0x158)])

    def nrpn(h, channel, delay, data_cc, synthetic=False):
        h.reset(synthetic)
        h.b.write(OBJ + 4, b"\xff" * 256)
        for cc, value, ms in [(99, 2, 1000), (98, 3, 1000),
                              (data_cc, 17, 1000 + delay)]:
            h.put(PARAM, cc)
            h.put(PARAM + 4, value)
            h.at_ms(ms)
            h.call(0x89edc, OBJ, channel & 0xffffffff, PARAM, PARAM + 4)
        return {"accepted": bool(h.eax()), "parameter": h.word(PARAM),
                "value": h.word(PARAM + 4)}

    for channel in [-1, *range(16), 16]:
        for delay in [0, 1, 999, 1000, 1001, 5000]:
            for cc in [6, 38]:
                for h in hosts:
                    nrpn(h, channel, delay, cc)
                compare("nrpn_timeout", [(OBJ, 0x108), (PARAM, 8)], True)

    for delay in [0, 1, 5, 10, 25, 100, 499, 500, 1000]:
        for repeated in [False, True]:
            for button in [0, 2, 3, 4]:
                for h in hosts:
                    h.reset()
                    h.put(OBJ + 0x324, 12)
                    h.put(OBJ + 0x328, 34 if repeated else 35)
                    h.put(OBJ + 0x32c, 1000)
                    for offset, value in [(0, 34), (4, 12), (8, button)]:
                        h.put(PARAM + offset, value)
                    h.at_ms(1000 + delay)
                    h.call(0x8beea, OBJ, PARAM, PARAM + 4, PARAM + 8, PARAM + 12)
                compare("pointer_acceleration", [(OBJ, 0x330), (PARAM, 16)])

    for queued in [0, 1, 2, 3]:
        for milliseconds in [0, 25, 1000, 5000]:
            for h in hosts:
                h.reset()
                h.put(OBJ, VTABLE)
                h.put(VTABLE + 0x27c, 0x1a54a)
                h.put(VTABLE + 0x308, 0x500030)
                h.put(VTABLE + 0x3d0, 0x500020)
                h.put(OBJ + 0x3b78, -1)
                h.put(OBJ + 0x3b80, -1)
                for offset, value in [(4, 8), (8, QUEUE), (12, queued), (16, 0)]:
                    h.put(OBJ + 0x38b8 + offset, value)
                for i in range(queued):
                    h.b.write(QUEUE + i * 24,
                              struct.pack("<6I", 0, 0, 0, i + 1, 127 - i, 0))
                h.put(TIMER + 12, OBJ)
                h.put(TIMER + 16, 0x1af32)
                h.at_ms(milliseconds)
                h.call(0xae9ec, 0x70004000, TIMER)
                assert h.word(OBJ + 0x38c8) == queued
                assert h.word(OBJ + 0xd270) == milliseconds
                assert len(h.callbacks) == queued
                assert h.word(OBJ + 0x3b30) == 0
            compare("idle_timer_dispatch", [(OBJ, 0xd280), (QUEUE, 192)])

    # The actual AU timer registered by LPAUSynth uses this separate entry.
    for idle_requested in [False, True]:
        for timer_token in [0, 0x70004000]:
            for queued in [0, 1, 2, 3]:
                for milliseconds in [0, 25, 1000, 5000]:
                    for h in hosts:
                        h.reset()
                        h.put(OBJ, VTABLE)
                        h.put(VTABLE + 0x258, 0x1a004)
                        h.put(VTABLE + 0x27c, 0x1a54a)
                        h.put(VTABLE + 0x3d0, 0x500020)
                        h.put(OBJ + 0x3b78, -1)
                        h.put(OBJ + 0x3b80, -1)
                        for offset, value in [(4, 8), (8, QUEUE), (12, queued),
                                              (16, 0)]:
                            h.put(OBJ + 0x38b8 + offset, value)
                        for i in range(queued):
                            h.b.write(QUEUE + i * 24, struct.pack(
                                "<6I", 0, 0, 0, i + 1, 127 - i, 0))
                        h.b.write(OBJ - 0xec + 0x32b418, bytes([int(idle_requested)]))
                        h.at_ms(milliseconds)
                        h.call(0x3aba, timer_token, OBJ - 0xec)
                        assert h.word(OBJ + 0x38c8) == (queued if idle_requested else 0)
                        assert h.word(OBJ + 0xd270) == (milliseconds if idle_requested else 0)
                        assert len(h.callbacks) == (queued if idle_requested else 0) + bool(timer_token)
                        if timer_token:
                            assert h.callbacks[-1] == ["reschedule", timer_token, 0.25]
                        assert h.word(OBJ + 0x3b30) == 0
                    compare("original_au_idle_timer",
                            [(OBJ, 0xd280), (QUEUE, 192)])

    # Execute the original queue consumer itself, including its switch and
    # indirect tail calls. Only final presentation callbacks are controlled.
    notification_slots = {0x29c: 0x500040, 0x2a4: 0x500050,
                          0x2a0: 0x500060, 0x364: 0x500070,
                          0x2a8: 0x500080, 0x2ac: 0x500090,
                          0x318: 0x5000a0, 0x32c: 0x5000b0}
    for message in [0, 0x45, 0x46, 0x49, 0x4a, 0x4b, 0x4c,
                    0x4d, 0x4e, 0x4f, 1, 0x7f]:
        for edit_mode in [0, 1]:
            for edit_aux in [0, 1]:
                for h in hosts:
                    h.reset()
                    h.put(OBJ, VTABLE)
                    h.put(VTABLE + 0x27c, 0x1a54a)
                    h.put(VTABLE + 0x3d0, 0x18360)
                    for slot, callback in notification_slots.items():
                        h.put(VTABLE + slot, callback)
                    h.put(OBJ + 0x3b78, -1)
                    h.put(OBJ + 0x3b80, -1)
                    h.put(OBJ + 0x38f0, edit_mode)
                    h.put(OBJ + 0x38ec, edit_aux)
                    for offset, value in [(4, 8), (8, QUEUE), (12, 1), (16, 0)]:
                        h.put(OBJ + 0x38b8 + offset, value)
                    h.b.write(QUEUE, struct.pack("<IBBhHHIII", 0, message,
                                                2, -3, 0, 0, 17, 0, 0))
                    h.put(TIMER + 12, OBJ)
                    h.put(TIMER + 16, 0x1af32)
                    h.at_ms(5000)
                    h.call(0xae9ec, 0x70004000, TIMER)
                    assert h.word(OBJ + 0x38c8) == 1
                compare("original_notification_dispatch",
                        [(OBJ, 0xd280), (QUEUE, 192)])

    # Same original decision code, two different host-clock contracts.
    # This demonstrates behavior sensitivity; it does not reproduce a DAW load.
    sensitivity = {}
    nrpn_results = {}
    for synthetic in [False, True]:
        values = [nrpn(h, 0, 5000, 6, synthetic) for h in hosts]
        assert values[0] == values[1]
        nrpn_results["cp032_synthetic" if synthetic else "elapsed"] = values[0]
    assert not nrpn_results["elapsed"]["accepted"]
    assert nrpn_results["cp032_synthetic"]["accepted"]
    sensitivity["nrpn_data_five_seconds_after_selection"] = nrpn_results

    selected = {}
    for synthetic in [False, True]:
        indices = []
        for h in hosts:
            h.reset(synthetic)
            h.put(OBJ + 12, 3)
            h.put(OBJ + 16, TABLE)
            # Slot zero was reused most recently. Compressed timestamps tie.
            for i, ms in [(1, 100), (2, 200), (0, 300)]:
                h.at_ms(ms)
                timestamp = h.call(0x2e1c0, OBJ + 4)
                h.b.write(TABLE + i * 36, struct.pack(
                    "<9I", 1, 0, INST_A, 60, 100, 0, 0, timestamp, 0))
            h.at_ms(400)
            indices.append(h.call(0x2eede, OBJ, 0, 60, 0))
        assert indices[0] == indices[1]
        selected["cp032_synthetic" if synthetic else "elapsed"] = indices[0]
    assert selected == {"elapsed": 1, "cp032_synthetic": 0}
    sensitivity["oldest_voice_after_slot_reuse"] = selected

    for h in hosts:
        h.b.close()
    return {
        "checkpoint": "CP-035", "functional_baseline": "CP-032",
        "scope": __doc__.strip(), "original_sha256": SHA,
        "architecture_executed": "Linux x86_64 C++ and original i386/Unicorn",
        "cases_by_kind": dict(cases), "differential_cases": sum(cases.values()),
        "compared_state_bytes": compared_bytes, "mismatches": [],
        "clock_contract_sensitivity": sensitivity,
        "original_au_capabilities": capabilities,
        "timer_callback": "0xae9ec -> 0x1af32 -> 0x1a54a",
        "actual_au_timer_callback": "0x3aba -> 0x1a004 -> 0x1a54a; rearm 250ms",
        "notification_consumer": "Original 0x18360 also executed in 48 cases",
        "callback_consumers": "Controlled final presentation callbacks; not the real editor",
        "cpu_causality_demonstrated": False, "full_engine_audio_tested": False,
        "private_registration_or_preferences_used": False,
        "production_code_changed": False, "passed": True,
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("library", type=Path)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    result = run(args.library)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))
