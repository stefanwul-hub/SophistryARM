import importlib.util
import struct
import subprocess
import hashlib
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location("core_reuse", ROOT / "scripts/reuse_cp032_core.py")
cache = importlib.util.module_from_spec(spec)
spec.loader.exec_module(cache)


class CacheReuseTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.old, self.new = [Path(self.temp.name) / name for name in ["old", "new"]]
        self.version = "Apple clang version fixture\nTarget: arm64-apple-darwin\n"
        self.sources = [Path("src/lifter/LifterRuntime.cpp"),
                        Path("src/lifter/whole/Dispatch.cpp"),
                        Path("src/lifter/whole/Unit0001.cpp")]
        for root in [self.old, self.new]:
            (root / "src/lifter/whole").mkdir(parents=True)
            (root / "src/lifter/LifterRuntime.h").write_text("// verified identical header\n")
            (root / "work/lifter-whole").mkdir(parents=True)
            for source in self.sources:
                (root / source).write_text("// " + source.name + "\n")
        (self.old / ".sophistry-cp032-source").write_text(cache.CP032_ARCHIVE_SHA256 + "\n")
        for source in self.sources:
            obj = self.old / "work/lifter-whole" / (source.stem + ".o")
            obj.write_bytes(struct.pack("<II", 0xfeedfacf, 0x0100000c) + b"fixture")
            Path(str(obj) + ".compile.sha256").write_text(cache.build_key(self.old, source, self.version) + "\n")

    def test_unchanged_inputs_reused_with_new_path_key(self):
        result = cache.reuse(self.old, self.new, self.version)
        self.assertEqual(result["reused_objects"], 3)
        for source in self.sources:
            target = self.new / "work/lifter-whole" / (source.stem + ".o")
            self.assertEqual(target.read_bytes(), (self.old / "work/lifter-whole" / target.name).read_bytes())
            self.assertEqual(Path(str(target) + ".compile.sha256").read_text().strip(),
                             cache.build_key(self.new, source, self.version))

    def test_key_matches_the_existing_shell_build_recipe(self):
        script = '''
test_root="$1"
test_source="$2"
test_version="$3"
test_flags=(-std=c++17 -O2 -g0 -ffp-contract=off -fno-fast-math -fno-exceptions -fno-rtti -fPIC -I"$test_root/src/lifter" -arch arm64 -mmacosx-version-min=11.0)
printf '%s\\n' '/usr/bin/xcrun clang++' "${test_flags[*]}" "$test_version"
cat "$test_root/src/lifter/LifterRuntime.h" "$test_root/$test_source"
'''
        raw = subprocess.check_output(["bash", "-c", script, "bash", str(self.old),
                                       str(self.sources[-1]), self.version.rstrip("\n")])
        self.assertEqual(hashlib.sha256(raw).hexdigest(),
                         cache.build_key(self.old, self.sources[-1], self.version))

    def test_changed_header_rejects_all(self):
        (self.new / "src/lifter/LifterRuntime.h").write_text("changed ABI\n")
        self.assertEqual(cache.reuse(self.old, self.new, self.version)["reused_objects"], 0)

    def test_changed_unit_is_not_reused(self):
        (self.new / self.sources[-1]).write_text("changed instructions\n")
        result = cache.reuse(self.old, self.new, self.version)
        self.assertEqual(result["reused_objects"], 2)
        self.assertEqual(result["skipped"]["source_changed"], 1)

    def test_changed_compiler_is_not_reused(self):
        self.assertEqual(cache.reuse(self.old, self.new, "Other compiler")["reused_objects"], 0)

    def test_x86_object_is_not_reused(self):
        obj = self.old / "work/lifter-whole/Unit0001.o"
        obj.write_bytes(struct.pack("<II", 0xfeedfacf, 0x01000007))
        result = cache.reuse(self.old, self.new, self.version)
        self.assertEqual(result["reused_objects"], 2)
        self.assertEqual(result["skipped"]["arm64_object_missing_or_invalid"], 1)

    def test_unverified_source_not_reused(self):
        (self.old / ".sophistry-cp032-source").unlink()
        self.assertFalse(cache.reuse(self.old, self.new, self.version)["executed"])


if __name__ == "__main__":
    unittest.main()
