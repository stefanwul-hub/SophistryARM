#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")" && pwd)"
if [[ "$(uname -s)" != Darwin ]]; then
  echo 'Ce script exige macOS et les outils Xcode.' >&2
  exit 2
fi
RUN_ID="$(date -u +%Y%m%dT%H%M%SZ)"
RUN="$ROOT/work/mac-$RUN_ID"
mkdir -p "$RUN"
exec > >(tee "$RUN/diagnostic.log") 2>&1
trap 'code=$?; echo "Code de sortie : $code. Rapports : $RUN"' EXIT
printf '%s\n' 'Checkpoint incomplet : ce script compile des outils de test, pas le synthétiseur complet.'
/usr/bin/sw_vers
/usr/bin/uname -m
/usr/bin/xcrun --find clang++
/usr/bin/xcrun --show-sdk-version
/usr/bin/xcrun clang++ --version
SOPHISTRY_SLICE_HASH=$(/usr/bin/shasum -a 256 "$ROOT/reference/Sophistry.i386" | /usr/bin/awk '{print $1}')
if [[ "$SOPHISTRY_SLICE_HASH" != '17239b5c4055557877635cabd0a37668016ca2a61f90c1773de7c0c2e10b6b12' ]]; then
  echo 'La tranche de référence diffère du binaire audité.' >&2
  exit 1
fi
/usr/bin/xcrun clang++ -arch arm64 -mmacosx-version-min=11.0 -std=c++17 -O2 \
  -ffp-contract=off -fno-fast-math -I"$ROOT/src" \
  "$ROOT/src/SaturKernel.cpp" "$ROOT/tests/SaturProbeMain.cpp" -o "$RUN/SaturProbe"
/usr/bin/lipo -verify_arch arm64 "$RUN/SaturProbe"
/usr/bin/file "$RUN/SaturProbe"
/usr/bin/arch -arm64 "$RUN/SaturProbe" "$ROOT/evidence/satur-fixtures.bin" | tee "$RUN/kernel-test.json"
/usr/bin/xcrun clang++ -arch arm64 -mmacosx-version-min=11.0 -std=c++17 -O2 \
  -I"$ROOT/src" "$ROOT/src/LegacyStateReader.cpp" "$ROOT/tests/LegacyStateProbeMain.cpp" -o "$RUN/LegacyStateProbe"
/usr/bin/lipo -verify_arch arm64 "$RUN/LegacyStateProbe"
/usr/bin/arch -arm64 "$RUN/LegacyStateProbe" "$ROOT/tests/fixtures/legacy-au-vstdata.bin" "$ROOT/tests/fixtures/legacy-fxp-chunk.bin" | tee "$RUN/legacy-state-test.jsonl"
bash "$ROOT/scripts/build-lifter.sh" "$RUN/lifter"
/usr/bin/lipo -verify_arch arm64 "$RUN/lifter/LiftedProbe"
/usr/bin/arch -arm64 "$RUN/lifter/LiftedProbe" "$ROOT/reference/Sophistry.i386" "$ROOT/evidence/static-lift-comparison.fixtures" | tee "$RUN/static-lift-replay.json"
# Compare the platform libm separately; a mismatch is recorded for investigation.
set +e
/usr/bin/arch -arm64 "$RUN/lifter/LiftedProbe" "$ROOT/reference/Sophistry.i386" "$ROOT/evidence/static-lift-comparison.fixtures" --native-math > "$RUN/static-lift-native-libm.json" 2> "$RUN/static-lift-native-libm-errors.log"
MATH_STATUS=$?
set -e
printf '%s\n' "$MATH_STATUS" > "$RUN/static-lift-native-libm.exitcode"
if [[ "$MATH_STATUS" -ne 0 ]]; then
  echo "La comparaison avec les maths natives diffère : consultez $RUN/static-lift-native-libm-errors.log"
fi
/usr/bin/xcrun clang++ -arch arm64 -mmacosx-version-min=11.0 -std=c++17 -O2 \
  "$ROOT/src/AUStateProbe.cpp" -framework AudioToolbox -framework AudioUnit \
  -framework CoreFoundation -o "$RUN/AUStateProbe"
/usr/bin/lipo -verify_arch arm64 "$RUN/AUStateProbe"
/usr/bin/file "$RUN/AUStateProbe"
COMPONENT='/Library/Audio/Plug-Ins/Components/Sophistry.component'
USER_COMPONENT="$HOME/Library/Audio/Plug-Ins/Components/Sophistry.component"
printf '%s\n' 'Inventaire des composants existants :'
for candidate in "$COMPONENT" "$USER_COMPONENT"; do
  if [[ -d "$candidate" ]]; then
    executable=$(/usr/libexec/PlistBuddy -c 'Print CFBundleExecutable' "$candidate/Contents/Info.plist")
    /usr/bin/file "$candidate/Contents/MacOS/$executable"
  fi
done
# Detection/validation only; no component, cache or project is changed.
set +e
/usr/bin/arch -arm64 /usr/bin/auval -v aumu Sop3 LinP > "$RUN/auval-existing.log" 2>&1
AUVAL_STATUS=$?
set -e
printf '%s\n' "$AUVAL_STATUS" > "$RUN/auval-existing.exitcode"
if [[ "$AUVAL_STATUS" -ne 0 ]]; then
  echo "auval n'a pas validé l'AU enregistré (code $AUVAL_STATUS). C'est attendu pour l'original i386/PPC sur macOS 15."
fi
if [[ "${1:-}" == '--render' ]]; then
  PRESET="${2:--}"
  for rate in 44100 48000 96000; do
    for block in 64 512; do
      /usr/bin/arch -arm64 "$RUN/AUStateProbe" "$RUN/render-$rate-$block" "$PRESET" "$rate" "$block"
    done
  done
fi
printf '%s\n' 'Tests du noyau isolé terminés. Aucun .component ARM64 complet n’est fourni ou installé.'
printf '%s\n' "Rapports : $RUN"
