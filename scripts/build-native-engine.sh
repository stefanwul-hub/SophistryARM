#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DEST="${1:-$ROOT/work/native-engine}"
CORE="${2:-$ROOT/work/lifter-whole}"
bash "$ROOT/scripts/build-lifter-chunks.sh" "$ROOT/src/lifter/whole" "$CORE"
mkdir -p "$DEST"
flags=(-std=c++17 -O2 -g0 -ffp-contract=off -fno-fast-math)
frameworks=()
if [[ "$(uname -s)" == Darwin ]]; then
  compiler=(/usr/bin/xcrun clang++)
  flags+=(-arch arm64 -mmacosx-version-min=11.0)
  frameworks=(-framework CoreFoundation)
else
  compiler=("${CXX:-c++}")
fi
compiler_version="$("${compiler[@]}" --version)"
sources=("$ROOT/src/engine/LegacyEngine.cpp" "$ROOT/src/engine/LegacyImageData.cpp" "$ROOT/tests/NativeEngineProbeMain.cpp")
objects=()
for source in "${sources[@]}"; do
  object="$DEST/$(basename "$source" .cpp).o";objects+=("$object")
  key="$( { printf '%s\n' "${compiler[*]}" "${flags[*]}" "$compiler_version"; cat "$ROOT/src/engine/GeneratorControls.h" "$ROOT/src/engine/GuestAllocator.h" "$ROOT/src/engine/PcmConversion.h" "$ROOT/src/engine/LegacyEngine.h" "$ROOT/src/engine/LegacyImageData.h" "$ROOT/src/lifter/LifterRuntime.h" "$source"; } | shasum -a 256 | awk '{print $1}')"
  if [[ ! -f "$object" || ! -f "$object.compile.sha256" || "$(cat "$object.compile.sha256")" != "$key" ]]; then
    "${compiler[@]}" "${flags[@]}" -c "$source" -o "$object.pending" > "$object.compile.log" 2>&1
    mv "$object.pending" "$object"
    printf '%s\n' "$key" > "$object.compile.sha256"
  fi
done
core_objects=("$CORE/LifterRuntime.o" "$CORE/Dispatch.o" "$CORE"/Unit*.o)
"${compiler[@]}" "${flags[@]}" "${objects[@]}" "${core_objects[@]}" "${frameworks[@]}" -o "$DEST/NativeEngineProbe"
if [[ "$(uname -s)" == Darwin ]]; then /usr/bin/lipo "$DEST/NativeEngineProbe" -verify_arch arm64; fi
printf '%s\n' "$DEST/NativeEngineProbe"
