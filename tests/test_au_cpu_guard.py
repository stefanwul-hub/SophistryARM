import contextlib
import importlib.util
import io
import json
import math
import plistlib
import struct
import sys
import tempfile
import types
import unittest
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "scripts"))
spec = importlib.util.spec_from_file_location("cpu_guard", ROOT / "scripts/compare_au_cpu_guard.py")
guard = importlib.util.module_from_spec(spec)
spec.loader.exec_module(guard)


class CpuGuardTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        root = Path(self.temp.name)
        self.args = types.SimpleNamespace(probe=root / "probe", baseline=root / "baseline",
                                         candidate=root / "candidate", state=root / "state",
                                         contract=root / "contract", output=root / "reports")
        info = self.args.baseline / "Contents/Info.plist"
        info.parent.mkdir(parents=True)
        info.write_bytes(plistlib.dumps({"CFBundleIdentifier": "com.linplug.au.Sophistry",
                                        "CFBundleVersion": "32001"}))
        self.candidate_cpu = 0.63
        self.different_audio = False
        self.calls = []

    def probe(self, command, **kwargs):
        def value(option):
            return command[command.index(option) + 1]
        version = value("--expected-version")
        candidate = version.endswith("038")
        prefix = Path(value("--output-prefix"))
        self.calls.append(version)
        result = {"error": "", "engine_error": "", "expected_checkpoint": version,
                  "render_thread_cpu_seconds": self.candidate_cpu if candidate else 0.6,
                  "render_call_wall_seconds": 0.7, "render_frames": 132300,
                  "render_block_size": 256, "maximum_render_call_seconds": 0.002,
                  "render_calls": 517}
        prefix.with_suffix(".json").write_text(json.dumps(result))
        values = [.25, -.25, .5, -.5]
        if candidate:
            gain = struct.unpack('<f', struct.pack('<f', math.pow(10, 6/20)))[0]
            values = [v * gain for v in values]
            if self.different_audio:
                values[-1] += .001
        data = struct.pack('<4f', *values)
        header = b'RIFF' + struct.pack('<I',36+len(data)) + b'WAVEfmt ' + struct.pack('<IHHIIHH',16,3,2,44100,352800,8,32) + b'data' + struct.pack('<I',len(data))
        prefix.with_suffix(".wav").write_bytes(header + data)

    def run_comparison(self):
        with patch.object(guard.subprocess, "run", side_effect=self.probe), contextlib.redirect_stdout(io.StringIO()):
            return guard.compare(self.args)

    def test_equal_audio_and_small_timing_variation_pass(self):
        result = self.run_comparison()
        self.assertTrue(result["passed"])
        self.assertTrue(result["performance_is_installation_gate"])
        self.assertAlmostEqual(result["candidate_to_cp032_cpu_ratio"], 1.05)
        self.assertEqual(len(self.calls), 10)
        self.assertEqual(self.calls[:4], ["SophistryARM CP-032", "SophistryARM CP-038",
                                          "SophistryARM CP-038", "SophistryARM CP-032"])

    def test_major_cpu_regression_fails_even_with_identical_audio(self):
        self.candidate_cpu = 1.98
        result = self.run_comparison()
        self.assertFalse(result["passed"])
        self.assertTrue(result["all_audio_exact_after_requested_gain"])
        self.assertAlmostEqual(result["candidate_to_cp032_cpu_ratio"], 3.3)

    def test_audio_difference_fails(self):
        self.different_audio = True
        with self.assertRaisesRegex(ValueError, "audio differs"):
            self.run_comparison()

    def test_missing_baseline_does_not_silently_pass(self):
        (self.args.baseline / "Contents/Info.plist").unlink()
        self.assertFalse(self.run_comparison()["passed"])
        self.assertEqual(self.calls, [])

    def test_wrong_checkpoint_does_not_silently_pass(self):
        (self.args.baseline / "Contents/Info.plist").write_bytes(plistlib.dumps({
            "CFBundleIdentifier": "com.linplug.au.Sophistry", "CFBundleVersion": "33001"}))
        self.assertFalse(self.run_comparison()["passed"])
        self.assertEqual(self.calls, [])


if __name__ == "__main__":
    unittest.main()
