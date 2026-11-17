#!/usr/bin/env python3
"""Reproduce the UI tables by executing the public original i386 image.

No serial, local preferences or private presets are read. The normal Mac
installer uses the checked-in tables and does not need this recovery step.
"""
import argparse
import hashlib
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, default=ROOT/'work/editor-recovery')
    parser.add_argument('--check', action='store_true')
    options = parser.parse_args()
    dest = options.output.resolve()
    dest.mkdir(parents=True, exist_ok=True)
    scripts = ROOT/'scripts/editor_recovery'
    for script, args in [
        ('constructor_trace.py', [dest/'original-layout.json']),
        ('metadata_trace.py', [dest/'all-controls.json']),
        ('normalize_layout.py', [dest]),
        ('keyboard_trace.py', [dest]),
    ]:
        subprocess.run([sys.executable, str(scripts/script), *map(str,args)],
                       cwd=ROOT, check=True)
    for name, target in [
        ('recovered-editor-layout.json', ROOT/'analysis/recovered-editor-layout.json'),
        ('RecoveredEditorLayout.h', ROOT/'src/engine/RecoveredEditorLayout.h'),
        ('RecoveredKeyboard.h', ROOT/'src/engine/RecoveredKeyboard.h'),
    ]:
        generated = (dest/name).read_bytes()
        if options.check and generated != target.read_bytes():
            raise SystemExit(f'Recovery differs: {target.relative_to(ROOT)}')
        print(name, hashlib.sha256(generated).hexdigest())

if __name__ == '__main__':
    main()
