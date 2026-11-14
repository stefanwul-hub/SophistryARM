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
flags+=(-fPIC)
"${compiler[@]}" "${flags[@]}" -c "$ROOT/src/lifter/LifterRuntime.cpp" -o "$DEST/LifterRuntime.o"
"${compiler[@]}" "${flags[@]}" -c "$ROOT/src/lifter/GeneratedDsp.cpp" -o "$DEST/GeneratedDsp.o"
objects=("$DEST/LifterRuntime.o" "$DEST/GeneratedDsp.o")
"${compiler[@]}" "${flags[@]}" "${shared[@]}" "${objects[@]}" -o "$library"
"${compiler[@]}" "${flags[@]}" -I"$ROOT/src/lifter" "${objects[@]}" "$ROOT/tests/LiftedProbeMain.cpp" -o "$DEST/LiftedProbe"
printf '%s\n' "$library" "$DEST/LiftedProbe"
