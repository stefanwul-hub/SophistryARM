#!/bin/bash
# CP-013: build and test an uninstalled ARM64 Audio Unit candidate.
set +x
set -euo pipefail
ROOT="$(cd "$(dirname "$0")" && pwd)"
cd "$ROOT"
if [[ "$(uname -s)" != Darwin || "$(uname -m)" != arm64 ]]; then
  echo 'Ce test nécessite un Terminal natif Apple Silicon et Xcode.' >&2
  exit 2
fi
STAMP="$(date -u +%Y%m%dT%H%M%SZ)"
REPORT="$ROOT/work/mac-au-reports-$STAMP"
BUILD="$ROOT/work/audio-unit"
CORE="$ROOT/work/lifter-whole"
mkdir -p "$REPORT"
exec > >(/usr/bin/tee "$REPORT/diagnostic.log") 2>&1
stage='début'
collect(){
  result=$?
  trap - EXIT
  unset serial_input
  for log in "$CORE"/*.compile.log "$BUILD/sdk"/*.compile.log "$BUILD/host"/*.compile.log "$BUILD"/*.compile.log; do
    if [[ -s "$log" ]]; then cp "$log" "$REPORT/compile-$(basename "$(dirname "$log")")-$(basename "$log")"; fi
  done
  printf '%s\n' "$result" > "$REPORT/script-exitcode.txt"
  printf '%s\n' "$stage" > "$REPORT/last-stage.txt"
  archive="$ROOT/Sophistry-rapports-CP013-$STAMP.zip"
  (cd "$REPORT"; /usr/bin/zip -q "$archive" ./*.json ./*.txt ./*.log ./*.wav 2>/dev/null || true)
  printf '\n%s\n' "Rapports : $archive"
  printf '%s\n' 'Le candidat reste dans work/audio-unit/Sophistry.component. Aucun remplacement dans /Library.'
  /usr/bin/open -R "$archive" >/dev/null 2>&1 || true
  exit "$result"
}
trap collect EXIT
printf '%s\n' 'Sophistry CP-013 — premier candidat Audio Unit ARM64, testé sans installation'
/usr/bin/sw_vers
/usr/bin/uname -m
/usr/bin/xcrun clang++ --version
stage='compilation du candidat AU et des sondes'
bash "$ROOT/scripts/build-audio-unit.sh" "$BUILD" "$CORE" > "$REPORT/build.log" 2>&1 || {
  tail -60 "$REPORT/build.log"
  echo 'Échec de compilation ; les détails sont inclus dans le rapport.' >&2
  exit 1
}
stage='vérification ARM64 et signature locale'
for binary in "$BUILD/Sophistry.component/Contents/MacOS/Sophistry" "$BUILD/AudioUnitFactoryProbe" "$BUILD/NativeAUBridgeProbe" "$BUILD/host/NativeEngineProbe"; do
  /usr/bin/file "$binary"
  /usr/bin/lipo "$binary" -verify_arch arm64
done
/usr/bin/codesign --verify --strict "$BUILD/Sophistry.component"
stage='replays DSP et régression du pont AU'
"$CORE/LiftedProbe" "$ROOT/reference/Sophistry.i386" "$ROOT/evidence/static-lift-comparison.fixtures" > "$REPORT/dsp-replay.json"
"$CORE/InstructionProbe" "$ROOT/reference/Sophistry.i386" "$ROOT/evidence/primitive-instructions.fixtures" > "$REPORT/instruction-replay.json"
"$BUILD/NativeAUBridgeProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" > "$REPORT/bridge-regression.json" 2> "$REPORT/bridge-regression-errors.log"
printf '\n%s\n' 'Les tests suivants chargent la factory du candidat dans leur propre processus.'
printf '%s\n' 'La clé reste en mémoire locale, sans fichier de clé, sans capture mémoire ni publication.'
printf '%s\n' 'Entrée seule : utiliser les préférences LinPlug existantes sur ce Mac.'
printf '%s' 'Numéro de série Sophistry (saisie masquée) : '
stage='saisie privée locale'
serial_input=''
IFS= read -r -s serial_input < /dev/tty
printf '\n'
stage='préparation de la référence i386 locale'
PYTHON="$ROOT/work/reference-python/bin/python3"
if [[ ! -x "$PYTHON" ]]; then
  /usr/bin/xcrun python3 -m venv "$ROOT/work/reference-python" > "$REPORT/reference-setup.log" 2>&1
fi
"$PYTHON" -m pip --disable-pip-version-check install --cache-dir "$ROOT/work/pip-cache" --only-binary=:all: -r "$ROOT/requirements-analysis.txt" >> "$REPORT/reference-setup.log" 2>&1
run_private(){
  local preference_mode="$1"
  shift
  if [[ -n "$serial_input" ]]; then
    printf '%s\n' "$serial_input" | "$@" --registration-from-stdin
  elif [[ "$preference_mode" == preferences ]]; then
    "$@" --local-mac-preferences
  else
    "$@"
  fi
}
result=0
for channels in 2 6; do
  printf '%s\n' "Test Audio Unit : $channels canaux, 44,1 kHz, trois secondes…"
  stage="factory AU $channels canaux"
  run_private factory "$BUILD/AudioUnitFactoryProbe" --bundle "$BUILD/Sophistry.component" \
    --state "$ROOT/reference/Presets/Lightgarden 02 BT.aupreset" \
    --contract "$ROOT/tests/fixtures/original-au-parameters.plist" --channels "$channels" \
    --output-prefix "$REPORT/factory-$channels" > "$REPORT/factory-$channels.log" 2>&1 || result=1
  stage="moteur AU direct $channels canaux"
  run_private preferences "$BUILD/host/NativeEngineProbe" --state "$ROOT/reference/Presets/Lightgarden 02 BT.aupreset" \
    --asset-directory "$ROOT/reference/Samples" --asset-directory "$ROOT/reference/Presets" \
    --au-channels "$channels" --render 3 --output-prefix "$REPORT/direct-$channels" > "$REPORT/direct-$channels.log" 2>&1 || result=1
  stage="instructions AU originales $channels canaux"
  run_private preferences "$PYTHON" "$ROOT/tests/probe_au_render.py" --state "$ROOT/reference/Presets/Lightgarden 02 BT.aupreset" \
    --channels "$channels" --seconds 3 --output "$REPORT/original-$channels.json" > "$REPORT/original-$channels.log" 2>&1 || result=1
  factory_equal=false;original_equal=false
  if [[ -f "$REPORT/factory-$channels.wav" && -f "$REPORT/direct-$channels.wav" ]] && \
    /usr/bin/cmp "$REPORT/factory-$channels.wav" "$REPORT/direct-$channels.wav" > "$REPORT/factory-direct-$channels.txt" 2>&1; then factory_equal=true;else result=1;fi
  if [[ -f "$REPORT/factory-$channels.wav" && -f "$REPORT/original-$channels.wav" ]] && \
    /usr/bin/cmp "$REPORT/factory-$channels.wav" "$REPORT/original-$channels.wav" > "$REPORT/factory-original-$channels.txt" 2>&1; then original_equal=true;else result=1;fi
  printf '{"channels":%s,"factory_vs_direct_byte_exact":%s,"factory_vs_original_byte_exact":%s}\n' \
    "$channels" "$factory_equal" "$original_equal" > "$REPORT/audio-comparison-$channels.json"
  /usr/bin/shasum -a 256 "$REPORT"/*-"$channels".wav > "$REPORT/audio-sha256-$channels.txt" 2>/dev/null || true
done
unset serial_input
printf '{"checkpoint":"CP-013","candidate_factory_tests_passed":%s,"system_installed":false,"auval_executed":false,"logic_recall_verified":false,"live_recall_verified":false}\n' \
  "$(if [[ "$result" -eq 0 ]]; then echo true;else echo false;fi)" > "$REPORT/result.json"
stage='tests terminés'
if [[ "$result" -eq 0 ]]; then
  echo 'Tests du candidat réussis. L’interface Sophistry, auval et le rappel des projets restent à valider.'
else
  echo 'Au moins un test du candidat échoue. Le ZIP conserve les erreurs et les comparaisons strictes.'
fi
exit "$result"
