#!/usr/bin/env python3
"""Run CP036 original/translated voice trajectories through the CP037 C++ clock.

The clock policy is the production template with a controlled source. Its
system-specific source is tested separately. Original instrument rendering is
executed with controlled final DSP callbacks, not a complete audio engine.
"""
import argparse
import ctypes
import gzip
import hashlib
import json
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT / "analysis/cp036"), str(ROOT / "tests"), str(ROOT / "scripts")]
from compare_voice_lifetimes import VoiceHost, Native, Original, SHA, scenarios
from compare_voice_lifetimes import OBJ, TABLE, PARAM, INST_A, INST_B
from legacy_image import LegacyImage


class ClockHost(VoiceHost):
    def __init__(self, backend, image, clock_lib, native, numerator, denominator):
        self.clock_lib = clock_lib
        self.clock_handle = None
        self.clock_native = native
        self.source_numerator = numerator
        self.source_denominator = denominator
        super().__init__(backend, image)

    def reset(self, synthetic=False):
        if self.clock_handle:
            self.clock_lib.cp037_clock_destroy(self.clock_handle)
        super().reset(synthetic)
        self.clock_handle = self.clock_lib.cp037_clock_create(
            int(self.clock_native), self.source_numerator, self.source_denominator)
        assert self.clock_handle

    def service(self, pc):
        name = self.names.get(pc)
        if name not in ["_mach_timebase_info", "_mach_absolute_time"]:
            return super().service(pc)
        if name == "_mach_timebase_info":
            pointer = self.word(self.b.esp() + 4)
            self.put(pointer, self.clock_lib.cp037_clock_numerator(self.clock_handle))
            self.put(pointer + 4, self.clock_lib.cp037_clock_denominator(self.clock_handle))
            result = 0
        else:
            self.clock_queries += 1
            ticks = self.now_ticks * self.source_denominator // self.source_numerator
            self.clock_lib.cp037_clock_input(ticks)
            result = self.clock_lib.cp037_clock_ticks(self.clock_handle)
            self.register(8, result >> 32)
        self.register(0, result)
        self.b.ret()

    def close(self):
        if self.clock_handle:
            self.clock_lib.cp037_clock_destroy(self.clock_handle)
            self.clock_handle = None
        self.b.close()


def compare(args):
    raw = (ROOT / "reference/Sophistry.i386").read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA
    image = LegacyImage(raw)
    mapped = bytes(image.mapped())
    kernel = ctypes.CDLL(str(args.library.resolve()))
    clocks = ctypes.CDLL(str(args.clock_library.resolve()))
    clocks.cp037_clock_create.argtypes = [ctypes.c_int, ctypes.c_uint32, ctypes.c_uint32]
    clocks.cp037_clock_create.restype = ctypes.c_void_p
    clocks.cp037_clock_destroy.argtypes = [ctypes.c_void_p]
    clocks.cp037_clock_input.argtypes = [ctypes.c_uint64]
    for name in ["ticks", "numerator", "denominator"]:
        fn = getattr(clocks, "cp037_clock_" + name)
        fn.argtypes = [ctypes.c_void_p]
        fn.restype = ctypes.c_uint64 if name == "ticks" else ctypes.c_uint32
    with gzip.open(ROOT / "evidence/cp036-voice-lifetime-traces.json.gz", "rt") as f:
        baseline = json.load(f)
    profiles = []
    total, state_bytes = 0, 0
    selected = {}
    for profile, native, numerator, denominator in [
        ("deterministic_reference", False, 1, 1),
        ("native_nanosecond_units", True, 1, 1),
        ("native_mach_125_over_3_units", True, 125, 3),
    ]:
        hosts = [ClockHost(Original(mapped), image, clocks, native, numerator, denominator),
                 ClockHost(Native(kernel, mapped), image, clocks, native, numerator, denominator)]
        count = 0
        for case in scenarios():
            for h in hosts:
                h.initialize_pool(case["pool"], not native)
            trace = []
            reference = baseline[case["name"]]["elapsed" if native else "cp032_synthetic"]
            for index, event in enumerate(case["events"]):
                decisions, activities = [], []
                for h in hosts:
                    decisions.append(h.dispatch(event, case["limit"], case["reuse"]))
                    activities.append(h.activity())
                assert decisions[0] == decisions[1]
                assert activities[0] == activities[1]
                assert hosts[0].callbacks == hosts[1].callbacks
                assert hosts[0].clock_queries == hosts[1].clock_queries
                for address, size in [(OBJ, 32), (TABLE, case["pool"] * 36),
                                      (INST_A, 0x1000), (INST_B, 0x1000), (PARAM, 96)]:
                    assert hosts[0].b.read(address, size) == hosts[1].b.read(address, size)
                    state_bytes += size
                # A Mach timebase can truncate a converted date by one ms.
                # Compare the actual original/translated bytes above, then
                # require the expected allocation/count behavior independently.
                expected = reference[index]
                assert decisions[0] == expected["decision"], (profile, case["name"], event)
                for key in ["occupied", "held", "released", "forced_release",
                            "per_instrument", "original_render_dsp_calls"]:
                    assert activities[0][key] == expected[key], (profile, case["name"], key)
                trace.append({"event": event, "decision": decisions[0], **activities[0]})
                count += 1
            assert trace[-1]["occupied"] == 0
            if case["name"] in ["seven_note_counterexample",
                                  "single_channel_note_off_after_wrong_steal"]:
                selected.setdefault(case["name"], {})[profile] = trace
        profiles.append({"profile": profile, "native_policy": native,
                         "timebase_numerator": numerator, "timebase_denominator": denominator,
                         "differential_event_steps": count, "passed": True})
        total += count
        for h in hosts:
            h.close()
    for case, modes in selected.items():
        index = -2 if case == "seven_note_counterexample" else 6
        assert modes["deterministic_reference"][index]["occupied"] == (5 if index == -2 else 3)
        for name in ["native_nanosecond_units", "native_mach_125_over_3_units"]:
            assert modes[name][index]["occupied"] == (4 if index == -2 else 2)
    return {"checkpoint": "CP-037", "scope": __doc__.strip(),
            "original_sha256": SHA, "profiles": profiles,
            "differential_event_steps": total, "compared_state_bytes": state_bytes,
            "original_voice_selection_code_changed": False,
            "deterministic_reference_preserved": True,
            "native_policy_recovers_elapsed_clock_voice_counts": True,
            "full_audio_envelopes_or_live_cpu_tested": False,
            "mismatches": [], "passed": True}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--library", type=Path, required=True)
    parser.add_argument("--clock-library", type=Path, required=True)
    parser.add_argument("--output", type=Path, required=True)
    args = parser.parse_args()
    result = compare(args)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps(result, indent=2))
