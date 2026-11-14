#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
SOURCE="${1:-$ROOT/src/lifter/whole}"
DEST="${2:-$ROOT/work/lifter-whole}"
JOBS="${SOPHISTRY_BUILD_JOBS:-2}"
case "$JOBS" in ''|*[!0-9]*) echo 'SOPHISTRY_BUILD_JOBS doit être un entier entre 1 et 16.' >&2; exit 2;; esac
if [[ "$JOBS" -lt 1 || "$JOBS" -gt 16 ]]; then exit 2; fi
if [[ ! -f "$SOURCE/manifest.json" || ! -f "$SOURCE/Dispatch.cpp" ]]; then
  echo 'Le dossier source doit contenir la génération découpée et son manifest.json.' >&2
  exit 2
fi
mkdir -p "$DEST"
flags=(-std=c++17 -O2 -g0 -ffp-contract=off -fno-fast-math -fno-exceptions -fno-rtti -fPIC -I"$ROOT/src/lifter")
if [[ "$(uname -s)" == Darwin ]]; then
  compiler=(/usr/bin/xcrun clang++)
  flags+=(-arch arm64 -mmacosx-version-min=11.0)
  shared=(-dynamiclib)
  library="$DEST/liblift-whole.dylib"
else
  compiler=("${CXX:-c++}")
  shared=(-shared)
  library="$DEST/liblift-whole.so"
fi
sources=("$ROOT/src/lifter/LifterRuntime.cpp" "$SOURCE/Dispatch.cpp" "$SOURCE"/Unit*.cpp)
compiler_version="$("${compiler[@]}" --version)"
objects=()
pids=()
completed=0
wait_batch(){
  local result=0 pid
  for pid in "${pids[@]}"; do wait "$pid" || result=1; done
  pids=()
  if [[ "$result" -ne 0 ]]; then echo "Compilation interrompue. Détails : $DEST/*.compile.log" >&2; exit 1; fi
}
for source in "${sources[@]}"; do
  name="$(basename "$source" .cpp)"
  object="$DEST/$name.o";objects+=("$object")
  key="$( { printf '%s\n' "${compiler[*]}" "${flags[*]}" "$compiler_version"; cat "$ROOT/src/lifter/LifterRuntime.h" "$source"; } | shasum -a 256 | awk '{print $1}')"
  if [[ -f "$object" && -f "$object.compile.sha256" && "$(cat "$object.compile.sha256")" == "$key" ]]; then
    completed=$((completed+1))
    continue
  fi
  (
    "${compiler[@]}" "${flags[@]}" -c "$source" -o "$object.pending"
    mv "$object.pending" "$object"
    printf '%s\n' "$key" > "$object.compile.sha256"
  ) > "$DEST/$name.compile.log" 2>&1 &
  pids+=("$!")
  completed=$((completed+1))
  if [[ "${#pids[@]}" -ge "$JOBS" ]]; then
    wait_batch
    if [[ $((completed%16)) -lt "$JOBS" ]]; then printf '%s\n' "Unités compilées : $completed/${#sources[@]}"; fi
  fi
done
if [[ "${#pids[@]}" -gt 0 ]]; then wait_batch; fi
"${compiler[@]}" "${flags[@]}" "${shared[@]}" "${objects[@]}" -o "$library"
"${compiler[@]}" "${flags[@]}" "${objects[@]}" "$ROOT/tests/LiftedProbeMain.cpp" -o "$DEST/LiftedProbe"
"${compiler[@]}" "${flags[@]}" "${objects[@]}" "$ROOT/tests/InstructionProbeMain.cpp" -o "$DEST/InstructionProbe"
printf '%s\n' "$library" "$DEST/LiftedProbe" "$DEST/InstructionProbe"
