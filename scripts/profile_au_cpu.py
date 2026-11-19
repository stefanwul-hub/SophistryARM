#!/usr/bin/env python3
"""Sample the installed CP037 render path without changing its DSP or settings."""
import argparse
import json
import math
import subprocess
import time
from pathlib import Path


def stop(process):
    if process is None:
        return
    if process.poll() is None:
        process.terminate()
        try:
            process.wait(timeout=3)
        except subprocess.TimeoutExpired:
            process.kill()
            process.wait(timeout=3)
    else:
        process.wait()


def profile(args):
    args.output.mkdir(parents=True, exist_ok=True)
    runs = []
    result = {
        "checkpoint": "CP-038 CPU profiling",
        "component_version": args.expected_version,
        "scope": "Offline native AU CPU sampling; held note and four-note chord, Lightgarden, 44100 Hz/256. Not a Live or CronoX benchmark.",
        "component_replaced": False,
        "preferences_modified_by_controller": False,
        "raw_stacks_local_only": True,
        "runs": runs,
        "passed": False,
    }
    try:
        for notes in [1, 4]:
            prefix = args.output / ("notes-" + str(notes))
            ready = prefix.with_suffix(".ready")
            go = prefix.with_suffix(".go")
            stack = prefix.with_suffix(".sample.txt")
            if any(p.exists() for p in [ready, go, stack, prefix.with_suffix(".json")]):
                raise ValueError("Use a fresh profiling report directory")
            process = sampler = None
            print("Capture CPU : " + str(notes) + " note(s), rendu ARM64 hors ligne…", flush=True)
            try:
                with prefix.with_suffix(".log").open("w") as log, prefix.with_suffix(".sampler.log").open("w") as sample_log:
                    command = [str(args.probe), "--bundle", str(args.bundle),
                               "--state", str(args.state), "--contract", str(args.contract),
                               "--output-prefix", str(prefix), "--channels", "2",
                               "--render-block-size", "256", "--expected-version", args.expected_version,
                               "--profile-notes", str(notes), "--profile-ready-file", str(ready),
                               "--profile-go-file", str(go)]
                    process = subprocess.Popen(command, stdout=log, stderr=subprocess.STDOUT)
                    deadline = time.monotonic() + args.ready_timeout
                    while not ready.is_file():
                        if process.poll() is not None:
                            raise RuntimeError("AU probe exited before first-buffer readiness; inspect notes-" + str(notes) + ".log")
                        if time.monotonic() >= deadline:
                            raise TimeoutError("AU probe did not reach its first audio buffer")
                        time.sleep(0.05)
                    sampler = subprocess.Popen([str(args.sampler), str(process.pid), "3", "1", "-file", str(stack)],
                                               stdout=sample_log, stderr=subprocess.STDOUT)
                    go.write_text("Start held-note render\n")
                    sampler.wait(timeout=15)
                    if (sampler.returncode or not stack.is_file() or
                            "Call graph:" not in stack.read_text(errors="replace")):
                        raise RuntimeError("macOS sample did not capture stacks; inspect notes-" + str(notes) + ".sampler.log")
                    process.wait(timeout=args.render_timeout)
                    if process.returncode:
                        raise RuntimeError("AU profile render failed; inspect notes-" + str(notes) + ".log")
                observation = json.loads(prefix.with_suffix(".json").read_text())
                if (observation.get("error") or observation.get("engine_error") or
                        observation.get("expected_checkpoint") != args.expected_version or
                        observation.get("profile_note_count") != notes or
                        observation.get("render_frames") != 882000 or
                        not observation.get("signal_above_minus_100_dbfs")):
                    raise ValueError("Incomplete or silent AU profile render")
                for field in ["render_thread_cpu_seconds", "render_call_wall_seconds", "maximum_render_call_seconds"]:
                    if not math.isfinite(observation[field]) or observation[field] <= 0:
                        raise ValueError("Invalid render timing")
                warm = json.loads(observation["profile_warm_engine_diagnostics_json"])
                final = json.loads(observation["engine_diagnostics_json"])
                for diagnostics in [warm, final]:
                    activity = diagnostics.get("voice_activity", {})
                    if not activity.get("available") or not activity.get("counters_consistent"):
                        raise ValueError("Voice counters unavailable or inconsistent")
                # Keep only explicit outcome fields in the summary. Full AU
                # diagnostics, sample paths and stack addresses stay local.
                runs.append({"midi_notes_held": notes, "sample_rate": 44100, "render_block_size": 256,
                             "audio_seconds": 20, "render_calls": observation["render_calls"],
                             "render_thread_cpu_seconds": observation["render_thread_cpu_seconds"],
                             "render_call_wall_seconds": observation["render_call_wall_seconds"],
                             "maximum_render_call_seconds": observation["maximum_render_call_seconds"],
                             "voice_activity_after_first_buffer": warm["voice_activity"],
                             "voice_activity_at_render_end": final["voice_activity"],
                             "stack_sample_captured": True})
            finally:
                stop(sampler)
                stop(process)
        result["passed"] = True
    except (OSError, ValueError, KeyError, TypeError, RuntimeError, TimeoutError, subprocess.SubprocessError) as error:
        result["error"] = str(error)
    (args.output / "profile-summary.json").write_text(json.dumps(result, indent=2) + "\n")
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ["probe", "bundle", "state", "contract", "output"]:
        parser.add_argument("--" + name, type=Path, required=True)
    parser.add_argument("--sampler", type=Path, default=Path("/usr/bin/sample"))
    parser.add_argument("--expected-version", choices=["SophistryARM CP-037", "SophistryARM CP-038"], required=True)
    parser.add_argument("--ready-timeout", type=float, default=60)
    parser.add_argument("--render-timeout", type=float, default=120)
    args = parser.parse_args()
    if args.ready_timeout <= 0 or args.render_timeout <= 0:
        parser.error("Positive timeouts required")
    result = profile(args)
    if not result["passed"]:
        raise SystemExit(result.get("error", "Profiling failed"))
    print("Les deux captures CPU sont enregistrées ; le composant installé est conservé.", flush=True)


if __name__ == "__main__":
    main()
