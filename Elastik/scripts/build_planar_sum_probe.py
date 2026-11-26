#!/usr/bin/env python3
"""Build the isolated translated summing helper with local Xcode/GCC tools."""
import argparse
import json
from pathlib import Path
import shutil
import subprocess
import sys


def build(output, compiler=None):
    root = Path(__file__).resolve().parents[1]
    if compiler is None:
        if sys.platform == 'darwin':
            compiler = subprocess.check_output(['xcrun', '--find', 'clang++'], text=True).strip()
        else:
            compiler = shutil.which('c++')
    if not compiler:
        raise RuntimeError('A local C++ compiler is required')
    version = subprocess.check_output([compiler, '--version'], text=True)
    flags = ['-std=c++17', '-O2', '-fno-fast-math', '-ffp-contract=off']
    flags += ['-fno-vectorize', '-fno-slp-vectorize'] if 'clang' in version.lower() else ['-fno-tree-vectorize']
    output = output.resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    command = [compiler] + flags + [str(root / 'src/OriginalPlanarSum.cpp'),
                                   str(root / 'tests/PlanarSumProbe.cpp'), '-o', str(output)]
    subprocess.run(command, check=True)
    print(json.dumps({'output': str(output), 'compiler': version.splitlines()[0],
                      'flags': flags, 'audio_unit_built': False}, indent=2))


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--output', type=Path, required=True)
    p.add_argument('--compiler')
    a = p.parse_args()
    build(a.output, a.compiler)
