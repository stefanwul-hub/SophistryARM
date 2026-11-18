#!/usr/bin/env python3
"""Reuse qualified CP032 ARM64 core objects when their build inputs match.

The absolute include-directory flag changes between extracted checkpoints.
Verify the old build key, identical source/header bytes, compiler version and
ARM64 object header before recording the equivalent key for the new path.
No source, compiler options or DSP operation is transformed.
"""
import argparse
import hashlib
import json
import os
import shutil
import struct
import subprocess
import sys
from collections import Counter
from pathlib import Path

CP032_ARCHIVE_SHA256 = "0fa3d52b58c753ba5b2cee5dbc6cd13d5099191f78b18812e2274ceff0661d0a"


def flags(root):
    return ["-std=c++17", "-O2", "-g0", "-ffp-contract=off", "-fno-fast-math",
            "-fno-exceptions", "-fno-rtti", "-fPIC", "-I" + str(root / "src/lifter"),
            "-arch", "arm64", "-mmacosx-version-min=11.0"]


def build_key(root, relative_source, compiler_version):
    prefix = "/usr/bin/xcrun clang++\n" + " ".join(flags(root)) + "\n" + compiler_version.rstrip("\n") + "\n"
    return hashlib.sha256(prefix.encode() + (root / "src/lifter/LifterRuntime.h").read_bytes()
                          + (root / relative_source).read_bytes()).hexdigest()


def arm64_object(path):
    try:
        with path.open("rb") as f:
            return struct.unpack("<II", f.read(8)) == (0xfeedfacf, 0x0100000c)
    except (OSError, struct.error):
        return False


def reuse(previous, current, compiler_version):
    # Preserve the logical path used by the shell build keys (Documents may
    # be a symlink). Resolving it would unnecessarily invalidate every object.
    previous, current = Path(os.path.abspath(previous)), Path(os.path.abspath(current))
    result = {"scope": "Qualified CP032 core build-cache reuse; no DSP optimization",
              "executed": False, "reused_objects": 0, "reused_bytes": 0,
              "skipped": {}, "runtime_source_transformed": False}
    marker = previous / ".sophistry-cp032-source"
    if not marker.is_file() or marker.read_text().strip() != CP032_ARCHIVE_SHA256:
        return {**result, "reason": "No verified CP032 source workspace found"}
    header = Path("src/lifter/LifterRuntime.h")
    if not (previous / header).is_file() or (previous / header).read_bytes() != (current / header).read_bytes():
        return {**result, "reason": "Core runtime header differs; normal compilation required"}
    sources = [Path("src/lifter/LifterRuntime.cpp"), Path("src/lifter/whole/Dispatch.cpp")]
    sources += [p.relative_to(current) for p in sorted((current / "src/lifter/whole").glob("Unit*.cpp"))]
    destination = current / "work/lifter-whole"
    destination.mkdir(parents=True, exist_ok=True)
    skipped = Counter()
    result["executed"] = True
    for source in sources:
        old_source, new_source = previous / source, current / source
        if not old_source.is_file() or old_source.read_bytes() != new_source.read_bytes():
            skipped["source_changed"] += 1
            continue
        old_object = previous / "work/lifter-whole" / (source.stem + ".o")
        old_key = Path(str(old_object) + ".compile.sha256")
        if not old_key.is_file() or old_key.read_text().strip() != build_key(previous, source, compiler_version):
            skipped["compiler_or_build_inputs_changed"] += 1
            continue
        if not arm64_object(old_object):
            skipped["arm64_object_missing_or_invalid"] += 1
            continue
        target = destination / old_object.name
        target_key = Path(str(target) + ".compile.sha256")
        key = build_key(current, source, compiler_version)
        if target_key.is_file() and target_key.read_text().strip() == key and arm64_object(target):
            skipped["already_valid"] += 1
            continue
        pending = Path(str(target) + ".cp032.pending")
        shutil.copyfile(old_object, pending)
        os.replace(pending, target)
        pending_key = Path(str(target_key) + ".pending")
        pending_key.write_text(key + "\n")
        os.replace(pending_key, target_key)
        result["reused_objects"] += 1
        result["reused_bytes"] += target.stat().st_size
    result["skipped"] = dict(skipped)
    return result


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--previous-root", type=Path, required=True)
    parser.add_argument("--current-root", type=Path, required=True)
    parser.add_argument("--report", type=Path, required=True)
    args = parser.parse_args()
    if sys.platform != "darwin":
        parser.error("CP032 build-cache reuse targets native Mac ARM64 objects")
    version = subprocess.check_output(["/usr/bin/xcrun", "clang++", "--version"], text=True)
    result = reuse(args.previous_root, args.current_root, version)
    args.report.parent.mkdir(parents=True, exist_ok=True)
    args.report.write_text(json.dumps(result, indent=2) + "\n")
    print("Objets ARM64 CP032 réutilisés après vérification : " + str(result["reused_objects"]))
    if not result["executed"]:
        print(result["reason"])
