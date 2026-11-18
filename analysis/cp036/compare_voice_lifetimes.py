#!/usr/bin/env python3
"""Follow complete original voice-table lifetimes under two clock contracts.

The original i386 allocator, note-off, state, iterator and completion routines
are executed against the unchanged CP032 C++ translation. Instrument notices
and voice DSP callbacks are controlled; completion events are explicit fixtures,
not DSP envelopes. The original polyphonic instrument render loop is executed.
No licence checks, presets, audio rendering or DAW CPU benchmark are involved.
"""

import argparse
import ctypes
import gzip
import hashlib
import json
import random
import re
import struct
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path[:0] = [str(ROOT / "analysis/cp035"), str(ROOT / "tests"),
                str(ROOT / "scripts")]
from compare_timing_behaviour import Harness, Native, Original, SHA
from compare_timing_behaviour import OBJ, TABLE, PARAM, INST_A, INST_B, VTABLE
from legacy_image import LegacyImage

INSTRUMENTS = [INST_A, INST_B]
SYNTH = OBJ - 0x38cc
VOICE_POINTERS, VOICE_OBJECTS, VOICE_VTABLE = 0x280000, 0x290000, 0x2a0000


def signed(value):
    return value if value < 0x80000000 else value - 0x100000000


class VoiceHost(Harness):
    def __init__(self, backend, image):
        self.sprintf_pc = next(x["address"] for x in image.stubs
                               if x["name"] == "_sprintf")
        super().__init__(backend, image)
        self.b.hook(self.sprintf_pc, self.service)
        self.b.hook(0x5000c0, self.service)
        self.b.hook(0x5000d0, self.service)
        self.debug_messages = 0
        self.render_slots = []

    def service(self, pc):
        if pc in [0x5000c0, 0x5000d0]:
            if pc == 0x5000d0:
                pointer = self.word(self.b.esp() + 4)
                slot = (pointer - VOICE_OBJECTS) // 0x100
                assert pointer == VOICE_OBJECTS + slot * 0x100
                assert 0 <= slot < self.pool_size
                self.render_slots.append(slot)
                self.callbacks.append(["voice_dsp", slot])
            # The fixture DSP remains active; natural completion is not modeled.
            self.register(0, 0)
            self.b.ret()
            return
        if pc != self.sprintf_pc:
            return super().service(pc)
        sp = self.b.esp()
        arg = lambda i: self.word(sp + 4 + i * 4)
        fmt = self.string(arg(1)).decode("ascii")
        assert fmt.startswith("Idx=%d Ins=%d (InsIdxIn=%d) State %d")
        formats = re.findall(r"%l?[du]", fmt)
        values = [(arg(i + 2) if spec.endswith("u") else signed(arg(i + 2)))
                  for i, spec in enumerate(formats)]
        text = re.sub(r"%l([du])", r"%\1", fmt) % tuple(values)
        data = text.encode("ascii")
        self.b.write(arg(0), data + b"\0")
        self.debug_messages += 1
        self.register(0, len(data))
        self.b.ret()

    def initialize_pool(self, size, synthetic):
        self.reset(synthetic)
        self.pool_size = size
        self.debug_messages = 0
        self.put(OBJ + 12, size)
        self.put(OBJ + 16, TABLE)
        self.put(OBJ + 28, 1)
        self.put(VTABLE + 0x8c, 0x500010)
        for index, pointer in enumerate(INSTRUMENTS):
            self.b.write(pointer, bytes(0x1000))
            self.put(pointer, VTABLE)
            self.put(pointer + 4, SYNTH)
            self.put(pointer + 0x150, 1)  # Polyphonic rendering path.
            self.put(pointer + 0x1a4, index)
        for slot in [0x68, 0x6c, 0x3c, 0x2c, 0x74]:
            self.put(VTABLE + slot, 0x5000c0)
        self.put(SYNTH + 0x3b0c, VOICE_POINTERS)
        self.put(VOICE_VTABLE + 0x30, 0x5000d0)
        for index in range(size):
            pointer = VOICE_OBJECTS + index * 0x100
            self.put(VOICE_POINTERS + index * 4, pointer)
            self.put(pointer, VOICE_VTABLE)
        self.call(0x2eb20, OBJ)

    def rows(self):
        data = self.b.read(TABLE, self.pool_size * 36)
        return list(struct.iter_unpack("<9I", data))

    def dispatch(self, event, limit, reuse):
        self.callbacks = []
        self.at_ms(event["ms"])
        action = event["action"]
        instrument, note, channel = (event.get("instrument", 0),
                                      event.get("note", 60), event.get("channel", 0))
        if action in ["on", "off"]:
            self.b.write(PARAM, struct.pack("<5I", 0, 1, note,
                                           100 if action == "on" else 64, channel))
        if action == "on":
            self.b.write(PARAM + 24, b"\xff")
            result = signed(self.call(0x2fb5c, OBJ, instrument,
                                      INSTRUMENTS[instrument], event.get("limit", limit),
                                      PARAM, PARAM + 24, int(reuse)))
            return {"slot": result, "reuse_or_steal": bool(self.b.read(PARAM + 24, 1)[0])}
        if action == "off":
            return {"slot": signed(self.call(0x2fdc4, OBJ, instrument, PARAM))}
        if action in ["complete_released", "complete_all", "choke_all"]:
            slots = [i for i, row in enumerate(self.rows()) if row[0] and
                     (action != "complete_released" or row[0] in [2, 3])]
            for slot in slots:
                self.call(0x2f80e if action == "choke_all" else 0x2f86e, OBJ, slot)
            return {"slots": slots}
        if action == "complete_note":
            slots = [i for i, row in enumerate(self.rows())
                     if row[0] in [2, 3] and row[1] == instrument and
                     row[3] == note and row[5] == channel]
            for slot in slots:
                self.call(0x2f86e, OBJ, slot)
            return {"slots": slots}
        if action == "reset":
            self.call(0x2eb20, OBJ)
            return {}
        raise AssertionError(action)

    def activity(self):
        rows = self.rows()
        by_state = Counter(row[0] for row in rows)
        occupied = self.word(OBJ + 20)
        held = self.word(OBJ + 24)
        assert occupied == sum(row[0] != 0 for row in rows)
        assert held == by_state[1]
        assert 0 <= held <= occupied <= self.pool_size
        instruments = []
        for index, pointer in enumerate(INSTRUMENTS):
            actual_occupied = sum(r[0] != 0 and r[2] == pointer for r in rows)
            actual_held = sum(r[0] == 1 and r[2] == pointer for r in rows)
            assert self.word(pointer + 0x14c) == actual_occupied
            assert self.word(pointer + 0x154) == actual_held
            visited = []
            slot = signed(self.call(0x2f3da, OBJ, index, PARAM + 64))
            while slot >= 0:
                assert slot < self.pool_size and slot not in visited
                visited.append(slot)
                slot = signed(self.call(0x2ecd6, OBJ, index, PARAM + 64))
            expected = [i for i, r in enumerate(rows) if r[0] and r[1] == index]
            assert visited == expected
            self.render_slots = []
            self.call(0xd1a6, pointer, PARAM + 80, 256)
            assert self.render_slots == expected
            instruments.append({"occupied": actual_occupied, "held": actual_held,
                                "render_iteration_slots": visited,
                                "original_render_dsp_calls": len(self.render_slots)})
        assert sum(len(i["render_iteration_slots"]) for i in instruments) == occupied
        return {"occupied": occupied, "held": held, "released": by_state[2],
                "forced_release": by_state[3], "per_instrument": instruments,
                "original_render_dsp_calls": sum(i["original_render_dsp_calls"] for i in instruments),
                "notes": [{"slot": i, "state": r[0], "instrument": r[1],
                           "note": r[3], "channel": r[5], "on_ms": signed(r[7]),
                           "off_ms": signed(r[8]), "age_gap_over_30ms_flag": bool(r[6] & 255)}
                          for i, r in enumerate(rows) if r[0]]}


def event(ms, action, note=60, instrument=0, channel=0, **extras):
    return {"ms": ms, "action": action, "note": note,
            "instrument": instrument, "channel": channel, **extras}


def scenarios():
    out = []
    def add(name, pool, limit, events, reuse=False):
        out.append({"name": name, "pool": pool, "limit": limit,
                    "reuse": reuse, "events": events})
    add("melody_below_limit", 8, 8,
        [e for k, note in enumerate([60, 62, 64, 65, 67, 64, 62, 60]) for e in
         [event(k * 500, "on", note), event(k * 500 + 200, "off", note),
          event(k * 500 + 400, "complete_released")]])
    add("chord_below_limit", 8, 8,
        [event(0, "on", n) for n in [60, 64, 67, 72]] +
        [event(700, "off", n) for n in [60, 64, 67, 72]] +
        [event(1000, "complete_released")])
    for reuse in [False, True]:
        add("repeated_note_reuse_" + str(int(reuse)), 8, 8,
            [e for k in range(6) for e in
             [event(k * 250, "on"), event(k * 250 + 120, "off")]] +
            [event(2000, "complete_released")], reuse)
    add("held_notes_at_capacity", 4, 4,
        [event(k * 100, "on", n) for k, n in enumerate([60, 62, 64, 65, 67, 69])] +
        [event(700 + k * 10, "off", n) for k, n in enumerate([60, 62, 64, 65, 67, 69])] +
        [event(1000, "complete_released")])
    add("released_voice_priority", 4, 4,
        [event(k * 100, "on", n) for k, n in enumerate([60, 62, 64, 65])] +
        [event(450 + k * 50, "off", n) for k, n in enumerate([64, 60, 65, 62])] +
        [event(650, "on", 70), event(750, "on", 72), event(850, "off", 70),
         event(950, "off", 72), event(1200, "complete_released")])
    add("slot_reuse_then_steal", 3, 3,
        [event(0, "on", 60), event(100, "on", 62), event(200, "on", 64),
         event(250, "off", 60), event(275, "complete_note", 60),
         event(300, "on", 65), event(400, "on", 67),
         *[event(600, "off", n) for n in [60, 62, 64, 65, 67]],
         event(900, "complete_released")])
    add("same_note_different_channels", 8, 8,
        [event(0, "on", channel=0), event(100, "on", channel=1),
         event(200, "off", channel=0), event(300, "off", channel=1),
         event(600, "complete_released")])
    add("two_instruments_shared_pool", 8, 4,
        [event(k * 100, "on", 60 + k, instrument=k % 2) for k in range(12)] +
        [event(1400 + k * 20, "off", 60 + k, instrument=k % 2) for k in range(12)] +
        [event(2000, "complete_released")])
    add("forced_release_and_completion", 4, 4,
        [event(k * 100, "on", 60 + k) for k in range(4)] +
        [event(500, "choke_all"), event(510, "on", 72),
         event(600, "complete_all"), event(700, "on", 72),
         event(800, "off", 72), event(1000, "complete_released")])
    add("polyphony_limit_reduced_while_held", 16, 8,
        [event(k * 100, "on", 60 + k) for k in range(8)] +
        [event(1000, "on", 72, limit=2), event(1100, "complete_all")])
    add("single_note", 8, 8, [event(0, "on"), event(500, "off"),
                              event(1000, "complete_released")])
    # Reduced from the deterministic matrix by native-only discovery, then
    # verified here against the original i386 too. No completion or note-off
    # precedes the count difference; the final completion is only cleanup.
    minimal = [event(0, "on", 61, 0, 1), event(100, "on", 64, 1, 1),
               event(200, "on", 64, 1, 1), event(300, "on", 65, 0, 1),
               event(400, "on", 63, 0, 1), event(500, "on", 60, 1, 0),
               event(600, "on", 64, 0, 0), event(1000, "complete_all")]
    add("seven_note_counterexample", 8, 2, minimal)
    add("seven_note_single_channel_control", 8, 2,
        [{**e, "channel": 0} for e in minimal])
    add("single_channel_note_off_after_wrong_steal", 3, 3,
        [event(0, "on", 60), event(100, "on", 62), event(200, "on", 64),
         event(300, "on", 65), event(400, "on", 67), event(450, "off", 65),
         # Explicit 250ms release completion, not an executed DSP envelope.
         event(700, "complete_note", 65), event(750, "off", 60),
         event(800, "off", 62), event(850, "off", 64), event(900, "off", 67),
         event(1200, "complete_released")])
    rng = random.Random(36032)
    for pool in [4, 8, 16]:
        for limit in [2, pool]:
            for reuse in [False, True]:
                for parts in [1, 2]:
                    stream = []
                    for i in range(64):
                        action = rng.choice(["on", "on", "off", "off"])
                        if i % 13 == 12:
                            action = "complete_released"
                        stream.append(event(i * 87, action, rng.randrange(60, 68),
                                            rng.randrange(parts), rng.randrange(2)))
                    stream.append(event(6000, "complete_all"))
                    add(f"matrix_{pool}_{limit}_{int(reuse)}_{parts}", pool, limit,
                        stream, reuse)
    for case in list(out):
        if case["name"].startswith("matrix_"):
            add(case["name"] + "_single_channel", case["pool"], case["limit"],
                [{**e, "channel": 0} for e in case["events"]], case["reuse"])
    return out


def run(library, traces_file):
    raw = (ROOT / "reference/Sophistry.i386").read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA
    image = LegacyImage(raw)
    mapped = bytes(image.mapped())
    lib = ctypes.CDLL(str(library.resolve()))
    traces, steps, compared_bytes = {}, 0, 0
    all_scenarios = scenarios()
    for mode in ["elapsed", "cp032_synthetic"]:
        hosts = [VoiceHost(Original(mapped), image), VoiceHost(Native(lib, mapped), image)]
        for case in all_scenarios:
            for h in hosts:
                h.initialize_pool(case["pool"], mode == "cp032_synthetic")
            trace = []
            for e in case["events"]:
                results, activities = [], []
                for h in hosts:
                    results.append(h.dispatch(e, case["limit"], case["reuse"]))
                    activities.append(h.activity())
                assert results[0] == results[1], (case["name"], e, "return")
                assert activities[0] == activities[1], (case["name"], e, "activity")
                assert hosts[0].callbacks == hosts[1].callbacks
                assert hosts[0].clock_queries == hosts[1].clock_queries
                for address, size in [(OBJ, 32), (TABLE, case["pool"] * 36),
                                      (INST_A, 0x1000), (INST_B, 0x1000), (PARAM, 96)]:
                    assert hosts[0].b.read(address, size) == hosts[1].b.read(address, size)
                    compared_bytes += size
                trace.append({"event": e, "decision": results[0], **activities[0]})
                steps += 1
            assert trace[-1]["occupied"] == 0, (case["name"], mode, "cleanup")
            traces.setdefault(case["name"], {})[mode] = trace
        for h in hosts:
            h.b.close()
    differences = []
    for case in all_scenarios:
        name = case["name"]
        a, b = traces[name]["elapsed"], traces[name]["cp032_synthetic"]
        choice_differences = sum(x["decision"] != y["decision"] for x, y in zip(a, b))
        extra = max(y["occupied"] - x["occupied"] for x, y in zip(a, b))
        held_extra = max(y["held"] - x["held"] for x, y in zip(a, b))
        differences.append({"scenario": name, "pool": case["pool"], "limit": case["limit"],
                            "reuse_matching_released_note": case["reuse"],
                            "decision_differences": choice_differences,
                            "maximum_extra_synthetic_occupied": extra,
                            "maximum_extra_synthetic_held": held_extra,
                            "peak_occupied_elapsed": max(x["occupied"] for x in a),
                            "peak_occupied_synthetic": max(x["occupied"] for x in b),
                            "both_final_occupied_zero": a[-1]["occupied"] == b[-1]["occupied"] == 0})
    traces_file.parent.mkdir(parents=True, exist_ok=True)
    with gzip.open(traces_file, "wt") as out:
        json.dump(traces, out, separators=(",", ":"))
    example_names = ["melody_below_limit", "repeated_note_reuse_0", "repeated_note_reuse_1",
                     "slot_reuse_then_steal", "polyphony_limit_reduced_while_held",
                     "seven_note_counterexample", "seven_note_single_channel_control",
                     "single_channel_note_off_after_wrong_steal"]
    minimal = traces["seven_note_counterexample"]
    assert minimal["elapsed"][-2]["occupied"] == 4
    assert minimal["cp032_synthetic"][-2]["occupied"] == 5
    control = traces["seven_note_single_channel_control"]
    assert control["elapsed"][-2]["occupied"] == control["cp032_synthetic"][-2]["occupied"] == 4
    mono = traces["single_channel_note_off_after_wrong_steal"]
    assert mono["elapsed"][5]["held"] == 2 and mono["cp032_synthetic"][5]["held"] == 3
    assert mono["elapsed"][6]["occupied"] == 2 and mono["cp032_synthetic"][6]["occupied"] == 3
    single_channel = [x for x in differences if x["scenario"].endswith("_single_channel")]
    return {
        "checkpoint": "CP-036", "functional_baseline": "CP-032",
        "scope": __doc__.strip(), "original_sha256": SHA,
        "architecture_executed": "Linux x86_64 C++ and original i386/Unicorn",
        "scenarios": len(all_scenarios), "clock_contracts": 2,
        "differential_event_steps": steps, "compared_state_bytes": compared_bytes,
        "state_and_counter_invariants_passed": True,
        "original_render_iteration_matches_occupied_slots": True,
        "original_instrument_render_loop_executed": "0xd1a6",
        "original_render_dsp_calls_match_occupied_slots": True,
        "pool_capacity_exceeded": False, "unbounded_voice_leak_demonstrated": False,
        "seven_note_counterexample_before_any_note_off_or_completion": True,
        "single_channel_noteoff_case_extra_held_before_completion": 1,
        "single_channel_completion_case_extra_occupied": 1,
        "single_channel_completion_is_explicit_fixture_not_audio_envelope": True,
        "single_channel_matrix_scenarios": len(single_channel),
        "single_channel_matrix_maximum_extra_synthetic_occupied": max(
            x["maximum_extra_synthetic_occupied"] for x in single_channel),
        "actual_envelope_completion_tested": False,
        "original_native_routine_mismatches": [], "clock_comparisons": differences,
        "selected_traces": {name: traces[name] for name in example_names},
        "full_engine_audio_or_cpu_causality_proven": False,
        "private_registration_or_preferences_used": False,
        "production_code_changed": False, "passed": True,
    }


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("library", type=Path)
    parser.add_argument("--output", type=Path, required=True)
    parser.add_argument("--traces", type=Path, required=True)
    args = parser.parse_args()
    result = run(args.library, args.traces)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n")
    print(json.dumps({k: v for k, v in result.items() if k != "selected_traces"}, indent=2))
