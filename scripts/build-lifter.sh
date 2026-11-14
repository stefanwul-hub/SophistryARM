#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DEST="${1:-$ROOT/work/lifter}"
mkdir -p "$DEST"
flags=(-std=c++17 -O2 -ffp-contract=off -fno-fast-math -fno-exceptions -fno-rtti)
if [[ "$(uname -s)" == Darwin ]]; then
  compiler=(/usr/bin/xcrun clang++)
  flags+=(-arch arm64 -mmacosx-version-min=11.0)
  shared=(-dynamiclib)
  library="$DEST/liblift.dylib"
else
  compiler=("${CXX:-c++}")
  shared=(-fPIC -shared)
  library="$DEST/liblift.so"
fi
sources=("$ROOT/src/lifter/LifterRuntime.cpp" "$ROOT/src/lifter/GeneratedDsp.cpp")
"${compiler[@]}" "${flags[@]}" "${shared[@]}" "${sources[@]}" -o "$library"
"${compiler[@]}" "${flags[@]}" -I"$ROOT/src/lifter" "${sources[@]}" "$ROOT/tests/LiftedProbeMain.cpp" -o "$DEST/LiftedProbe"
printf '%s\n' "$library" "$DEST/LiftedProbe"
