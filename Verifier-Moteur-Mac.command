#!/bin/bash
# CP-011: compile and exercise the C++ engine host. No component is installed.
set +x
set -euo pipefail
ROOT="$(cd "$(dirname "$0")" && pwd)"
cd "$ROOT"
if [[ "$(uname -s)" != Darwin || "$(uname -m)" != arm64 ]]; then
  echo 'Ce test doit être lancé dans un Terminal natif sur un Mac Apple Silicon.' >&2
  exit 2
fi
STAMP="$(date -u +%Y%m%dT%H%M%SZ)"
REPORT="$ROOT/work/mac-native-reports-$STAMP"
mkdir -p "$REPORT"
exec > >(/usr/bin/tee "$REPORT/diagnostic.log") 2>&1
stage='début'
collect(){
  result=$?
  trap - EXIT
  unset serial_input
  for log in "$ROOT/work/lifter-whole"/*.compile.log "$ROOT/work/native-engine"/*.compile.log; do
    if [[ -s "$log" ]]; then cp "$log" "$REPORT/compile-$(basename "$(dirname "$log")")-$(basename "$log")"; fi
  done
  printf '%s\n' "$result" > "$REPORT/script-exitcode.txt"
  printf '%s\n' "$stage" > "$REPORT/last-stage.txt"
  archive="$ROOT/Sophistry-rapports-CP011-$STAMP.zip"
  (
    cd "$REPORT"
    /usr/bin/zip -q "$archive" ./*.json ./*.txt ./*.log ./*.wav 2>/dev/null || true
  )
  printf '\n%s\n' "Rapports : $archive"
  printf '%s\n' 'Ce checkpoint ne construit pas encore de composant Audio Unit installable.'
  exit "$result"
}
trap collect EXIT
printf '%s\n' 'Sophistry CP-011 — hôte C++ natif, compilation ARM64 et tests'
/usr/bin/sw_vers
/usr/bin/uname -m
/usr/bin/xcrun clang++ --version
stage='compilation du moteur et des probes'
bash "$ROOT/scripts/build-native-engine.sh" "$ROOT/work/native-engine" "$ROOT/work/lifter-whole" > "$REPORT/build.log" 2>&1 || {
  tail -50 "$REPORT/build.log"
  echo "Le build a échoué. Les journaux de compilation sont dans $ROOT/work/." >&2
  exit 1
}
CORE="$ROOT/work/lifter-whole"
PROBE="$ROOT/work/native-engine/NativeEngineProbe"
stage='vérification des exécutables ARM64'
for binary in "$PROBE" "$CORE/LiftedProbe" "$CORE/InstructionProbe"; do
  /usr/bin/file "$binary"
  /usr/bin/lipo "$binary" -verify_arch arm64
done
stage='replay DSP et instructions'
"$CORE/LiftedProbe" "$ROOT/reference/Sophistry.i386" "$ROOT/evidence/static-lift-comparison.fixtures" > "$REPORT/dsp-replay.json"
"$CORE/InstructionProbe" "$ROOT/reference/Sophistry.i386" "$ROOT/evidence/primitive-instructions.fixtures" > "$REPORT/instruction-replay.json"
assets=(--asset-directory "$ROOT/reference/Samples" --asset-directory "$ROOT/reference/Presets")
stage='restauration FXP et AU, sans préférences privées'
"$PROBE" --state "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "${assets[@]}" --output-prefix "$REPORT/fxp" > "$REPORT/fxp.log" 2>&1
"$PROBE" --state "$ROOT/reference/Presets/Lightgarden 02 BT.aupreset" "${assets[@]}" --output-prefix "$REPORT/aupreset" > "$REPORT/aupreset.log" 2>&1
state_result=0
/usr/bin/cmp "$REPORT/fxp.chunk" "$ROOT/evidence/fxp-original-cp010.chunk" > "$REPORT/fxp-serialization.txt" 2>&1 || state_result=1
/usr/bin/cmp "$REPORT/aupreset.chunk" "$ROOT/evidence/aupreset-original-cp010.chunk" > "$REPORT/aupreset-serialization.txt" 2>&1 || state_result=1
printf '{"byte_exact_program_serialization":%s}\n' "$(if [[ "$state_result" -eq 0 ]]; then echo true; else echo false; fi)" > "$REPORT/state-comparison.json"
if [[ "$state_result" -ne 0 ]]; then
  echo 'Une sérialisation diffère de la référence : voir les rapports.'
  exit 1
fi
printf '\n%s\n' 'Les tests de base passent. Le test suivant active le rendu audio.'
printf '%s\n' 'Votre clé sera saisie sans être affichée, sans fichier de clé et sans capture mémoire.'
printf '%s\n' 'Entrée seule : essayer les préférences LinPlug déjà présentes sur ce Mac.'
printf '%s' 'Numéro de série Sophistry (saisie masquée) : '
stage='saisie privée locale'
serial_input=''
IFS= read -r -s serial_input < /dev/tty
printf '\n'
stage='rendu avec enregistrement local'
audio_result=0
if [[ -n "$serial_input" ]]; then
  printf '%s\n' "$serial_input" | "$PROBE" --state "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "${assets[@]}" --output-prefix "$REPORT/licensed-render" --registration-from-stdin --render 3 > "$REPORT/licensed-render.log" 2>&1 || audio_result=$?
else
  "$PROBE" --state "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "${assets[@]}" --output-prefix "$REPORT/licensed-render" --local-mac-preferences --render 3 > "$REPORT/licensed-render.log" 2>&1 || audio_result=$?
fi
printf '%s\n' "$audio_result" > "$REPORT/licensed-render-exitcode.txt"
if [[ "$audio_result" -ne 0 ]]; then
  echo 'Le rendu complet reste en échec. Le rapport indique le contrôle ou la fonction qui bloque.'
  cat "$REPORT/licensed-render.json" 2>/dev/null || true
  exit 1
fi
printf '%s\n' 'Le rendu C++ aboutit. Préparation de la référence i386 locale.'
stage='préparation de la référence locale'
PYTHON="$ROOT/work/reference-python/bin/python3"
if [[ ! -x "$PYTHON" ]]; then
  /usr/bin/xcrun python3 -m venv "$ROOT/work/reference-python" > "$REPORT/reference-setup.log" 2>&1
fi
"$PYTHON" -m pip --disable-pip-version-check install --cache-dir "$ROOT/work/pip-cache" --only-binary=:all: -r "$ROOT/requirements-analysis.txt" >> "$REPORT/reference-setup.log" 2>&1
stage='rendu des instructions i386 originales, localement'
reference_result=0
if [[ -n "$serial_input" ]]; then
  printf '%s\n' "$serial_input" | "$PYTHON" "$ROOT/tests/probe_engine_initialization.py" --construct --open --preset "$ROOT/reference/Presets/lightgarden 02 BT.FXP" --au-callback --registration-from-stdin --render 3 --output "$REPORT/original-render.json" > "$REPORT/original-render.log" 2>&1 || reference_result=$?
else
  "$PYTHON" "$ROOT/tests/probe_engine_initialization.py" --construct --open --preset "$ROOT/reference/Presets/lightgarden 02 BT.FXP" --au-callback --local-mac-preferences --render 3 --output "$REPORT/original-render.json" > "$REPORT/original-render.log" 2>&1 || reference_result=$?
fi
unset serial_input
printf '%s\n' "$reference_result" > "$REPORT/original-render-exitcode.txt"
if [[ "$reference_result" -ne 0 ]]; then
  echo 'La référence originale reste en échec : voir original-render.json et original-render.log.'
  exit 1
fi
stage='comparaison audio stricte'
if /usr/bin/cmp "$REPORT/licensed-render.wav" "$REPORT/original-render.wav" > "$REPORT/audio-comparison.txt" 2>&1; then
  printf '{"wav_byte_exact":true,"original_apple_i386_libm_executed":false}\n' > "$REPORT/audio-comparison.json"
else
  printf '{"wav_byte_exact":false,"original_apple_i386_libm_executed":false}\n' > "$REPORT/audio-comparison.json"
  echo 'Les deux rendus diffèrent ; le contrôle strict reste en échec.'
  exit 1
fi
stage='comparaison audio terminée, intégration AU restante'
printf '%s\n' 'Les deux rendus locaux sont identiques. Le wrapper AU reste à terminer.'
