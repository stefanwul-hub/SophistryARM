import importlib.util
import json
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location("summary", ROOT / "analysis/cp039/profile_summary.py")
summary = importlib.util.module_from_spec(spec)
spec.loader.exec_module(summary)

SAMPLE = """Process: private ignored metadata
Call graph:
    10 Thread_123 DispatchQueue: com.apple.main-thread
    + 10 main  (in probe) + 12 [0x12345]
    +   8 sophistry::LegacyEngine::process(float*)  (in Sophistry) + 16 [0x23456]
    +   ! 6 sl_execute(SlCpu&)  (in Sophistry) + 32 [0x34567]
    +   ! + 5 sl_unit_0001(SlCpu&)  (in Sophistry) + 48 [0x45678]
    +   ! +   1 sl_tick(SlCpu&)  (in Sophistry) + 8 [0x56789]
    +   ! 2 sophistry::LegacyEngine::Impl::service(unsigned int)  (in Sophistry)
    +   !   2 sophistry::LegacyEngine::Impl::editorPlatformService(str)  (in Sophistry)
    +   !     1 _platform_strlen  (in library)
    10000 Thread_456
    + 10000 __workq_kernreturn  (in library)
Total number in stack:
    ignored aggregate
Binary Images:
    /Users/private/not-public
"""


class SummaryTests(unittest.TestCase):
    def test_only_main_thread_and_conserved_exclusive_counts(self):
        r = summary.summarize(SAMPLE)
        self.assertEqual(r["main_thread_samples"], 10)
        self.assertTrue(r["exclusive_samples_conserved"])
        self.assertEqual(r["compiled_units"][0]["exclusive_samples"], 4)
        self.assertEqual(r["instruction_bookkeeping"]["exclusive_samples"], 1)
        self.assertEqual(r["host_import_binding"]["all"]["exclusive_samples"], 2)
        self.assertEqual(r["host_import_binding"]["editor_router"]["exclusive_samples"], 2)

    def test_private_metadata_addresses_and_thread_ids_absent(self):
        result = json.dumps(summary.summarize(SAMPLE))
        for value in ["/Users/", "0x12345", "Thread_123", "Thread_456", "private ignored metadata"]:
            self.assertNotIn(value, result)

    def test_inconsistent_counts_rejected(self):
        with self.assertRaises(ValueError):
            summary.summarize(SAMPLE.replace("+   ! +   1 sl_tick", "+   ! +   7 sl_tick"))


if __name__ == "__main__":
    unittest.main()
