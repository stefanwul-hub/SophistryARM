import contextlib
import importlib.util
import io
import json
import os
import sys
import tempfile
import types
import unittest
from pathlib import Path
from unittest.mock import patch

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location("profiler", ROOT / "scripts/profile_au_cpu.py")
profiler = importlib.util.module_from_spec(spec)
spec.loader.exec_module(profiler)

PROBE = r'''
import json,os,sys,time
from pathlib import Path
def value(name):return sys.argv[sys.argv.index(name)+1]
mode=os.environ.get('PROFILE_TEST_MODE','success')
if mode=='early_exit':sys.exit(2)
if mode=='no_ready':time.sleep(30);sys.exit(3)
ready=Path(value('--profile-ready-file'));go=Path(value('--profile-go-file'))
ready.write_text('warm')
while not go.exists():time.sleep(.005)
if mode=='sampler_failure':time.sleep(30)
notes=int(value('--profile-notes'))
activity={'available':True,'counters_consistent':mode!='bad_voices','capacity':32,'occupied':notes,'held':notes,'released':0,'forced_release':0,'by_part':[]}
diag=json.dumps({'voice_activity':activity,'asset_roots':['/Users/private/do-not-publish'],'host_import_calls':{'fixture_only':999}})
r={'error':None,'engine_error':'','expected_checkpoint':value('--expected-version'),'profile_note_count':notes,'render_frames':882000,'signal_above_minus_100_dbfs':True,'profile_warm_engine_diagnostics_json':diag,'engine_diagnostics_json':diag,'render_calls':3446,'render_thread_cpu_seconds':.2,'render_call_wall_seconds':.21,'maximum_render_call_seconds':.001}
if mode=='bad_timing':r['render_thread_cpu_seconds']=float('nan')
if mode=='bad_json':del r['profile_warm_engine_diagnostics_json']
time.sleep(.12)
Path(value('--output-prefix')+'.json').write_text(json.dumps(r))
'''
SAMPLER = r'''
import os,sys,time
from pathlib import Path
if os.environ.get('PROFILE_TEST_MODE')=='sampler_failure':sys.exit(7)
time.sleep(.03)
Path(sys.argv[sys.argv.index('-file')+1]).write_text('Call graph:\n  test render stack\n')
'''


class ProfileLifecycleTests(unittest.TestCase):
    def setUp(self):
        temp = tempfile.TemporaryDirectory()
        self.addCleanup(temp.cleanup)
        root = Path(temp.name)
        self.args = types.SimpleNamespace(probe=root / "probe", sampler=root / "sample",
                                          bundle=root / "bundle", state=root / "state", contract=root / "contract",
                                          output=root / "reports", ready_timeout=.4, render_timeout=2,
                                          expected_version="SophistryARM CP-037")
        for path, source in [(self.args.probe, PROBE), (self.args.sampler, SAMPLER)]:
            path.write_text("#!" + sys.executable + "\n" + source)
            path.chmod(0o700)

    def run_profile(self, mode="success"):
        with patch.dict(os.environ, {"PROFILE_TEST_MODE": mode}), contextlib.redirect_stdout(io.StringIO()):
            result = profiler.profile(self.args)
        self.assertEqual(result, json.loads((self.args.output / "profile-summary.json").read_text()))
        return result

    def test_success_and_summary_excludes_private_diagnostics(self):
        result = self.run_profile()
        self.assertTrue(result["passed"])
        self.assertEqual([r["midi_notes_held"] for r in result["runs"]], [1, 4])
        self.assertNotIn("/Users/private", json.dumps(result))
        self.assertNotIn("host_import_calls", json.dumps(result))
        self.assertFalse(result["component_replaced"])

    def test_cp038_supported(self):
        self.args.expected_version = "SophistryARM CP-038"
        self.assertTrue(self.run_profile()["passed"])

    def test_probe_failure_before_audio_is_reported(self):
        self.assertFalse(self.run_profile("early_exit")["passed"])

    def test_readiness_timeout_does_not_hang(self):
        self.assertFalse(self.run_profile("no_ready")["passed"])

    def test_sampler_failure_terminates_render(self):
        self.assertFalse(self.run_profile("sampler_failure")["passed"])

    def test_invalid_voice_counters_rejected(self):
        self.assertFalse(self.run_profile("bad_voices")["passed"])

    def test_missing_diagnostic_is_reported(self):
        self.assertFalse(self.run_profile("bad_json")["passed"])

    def test_invalid_cpu_timing_rejected(self):
        self.assertFalse(self.run_profile("bad_timing")["passed"])


if __name__ == "__main__":
    unittest.main()
