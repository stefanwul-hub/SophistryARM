#!/bin/bash
# Development engine probe only; no installation, AU registration or preferences.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DEST="${1:-$ROOT/work/cronox-engine}"
CORE="${2:-$ROOT/work/cronox-core}"
bash "$ROOT/scripts/build-lifter-chunks.sh" "$ROOT/src/lifter/cronox" "$CORE"
mkdir -p "$DEST"
flags=(-std=c++17 -O2 -g0 -ffp-contract=off -fno-fast-math)
frameworks=()
if [[ "$(uname -s)" == Darwin ]]; then
  [[ "$(uname -m)" == arm64 ]] || { echo 'Utilisez un Terminal natif Apple Silicon.' >&2;exit 2; }
  compiler=(/usr/bin/xcrun clang++)
  flags+=(-arch arm64 -mmacosx-version-min=11.0)
  frameworks=(-framework CoreFoundation)
else
  compiler=("${CXX:-c++}")
fi
version="$("${compiler[@]}" --version)"
headers="$(find "$ROOT/src/engine" -maxdepth 1 -name '*.h' -type f -exec shasum -a 256 {} + | LC_ALL=C sort | shasum -a 256)"
objects=()
for source in "$ROOT/src/engine/LegacyEngine.cpp" "$ROOT/src/engine/LegacyImageData.cpp" ; do
  object="$DEST/$(basename "$source" .cpp).o";objects+=("$object")
  key="$( { printf '%s\n' "${compiler[*]}" "${flags[*]}" "$version" "$headers";cat "$ROOT/src/lifter/LifterRuntime.h" "$source"; } | shasum -a 256 | awk '{print $1}')"
  if [[ ! -f "$object" || ! -f "$object.compile.sha256" || "$(cat "$object.compile.sha256")" != "$key" ]]; then
    "${compiler[@]}" "${flags[@]}" -c "$source" -o "$object.pending" > "$object.compile.log" 2>&1
    mv "$object.pending" "$object"
    printf '%s\n' "$key" > "$object.compile.sha256"
  fi
done
for probe in CronoXBootProbe CronoXAUBridgeProbe; do
  "${compiler[@]}" "${flags[@]}" "$ROOT/tests/$probe.cpp" "${objects[@]}" "$CORE/LifterRuntime.o" "$CORE/Dispatch.o" "$CORE"/Unit*.o \
    "${frameworks[@]}" -o "$DEST/$probe"
  if [[ "$(uname -s)" == Darwin ]]; then /usr/bin/lipo "$DEST/$probe" -verify_arch arm64;fi
  printf '%s\n' "$DEST/$probe"
done
"${compiler[@]}" "${flags[@]}" "$ROOT/tests/GuestStdStringProbe.cpp" -o "$DEST/GuestStdStringProbe"
if [[ "$(uname -s)" == Darwin ]]; then /usr/bin/lipo "$DEST/GuestStdStringProbe" -verify_arch arm64;fi
