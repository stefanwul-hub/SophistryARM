#!/bin/bash
# Native comparison installation. The CrX3 original and Sophistry are preserved.
set +x
set -euo pipefail
umask 077
ROOT="$(cd "$(dirname "$0")" && pwd)"
[[ "$(uname -s)" == Darwin && "$(uname -m)" == arm64 ]] || { echo 'Utilisez un Terminal natif Apple Silicon avec Xcode.' >&2;exit 2; }
STAMP="$(date -u +%Y%m%dT%H%M%SZ)"
REPORT="$HOME/Desktop/CronoX3-rapports-CRX013-$STAMP"
BUILD="$ROOT/work/cronox-audio-unit"
CORE="$ROOT/work/cronox-core"
TARGET="/Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component"
ORIGINAL="/Library/Audio/Plug-Ins/Components/CronoX 3.component"
TRANSACTION_TOOL="$ROOT/scripts/cronox_component_transaction.py"
TRANSACTION=''
installed=0
rollback=0
auval_passed=0
factory_passed=0
stage='préparation'
mkdir -p "$REPORT"
finish(){
 result=$?;trap - EXIT
 if [[ -n "$TRANSACTION" && "$installed" -ne 1 ]]; then
  echo 'Validation échouée : récupération de la version ARM Test précédente…'
  if sudo /usr/bin/python3 "$TRANSACTION_TOOL" rollback --transaction "$TRANSACTION" > "$REPORT/rollback.json" 2>&1; then
   rollback=1
  else
   echo 'La récupération automatique demande une vérification ; toutes les copies sont conservées.' >&2
  fi
  /usr/bin/killall -u "$(id -u)" AudioComponentRegistrar 2>/dev/null || true
 fi
 export CRX_REPORT="$REPORT" CRX_RESULT="$result" CRX_INSTALLED="$installed" CRX_ROLLBACK="$rollback" CRX_AUVAL="$auval_passed" CRX_FACTORY="$factory_passed" CRX_STAGE="$stage"
 /usr/bin/python3 - <<'PY'
import json,os
from pathlib import Path
p=Path(os.environ['CRX_REPORT'])/'installation.json'
p.write_text(json.dumps({'checkpoint':'CRX013','identity':'aumu/CrT3/LinP','exit_code':int(os.environ['CRX_RESULT']),'system_installation_committed':os.environ['CRX_INSTALLED']=='1','rollback_performed':os.environ['CRX_ROLLBACK']=='1','auval_passed':os.environ['CRX_AUVAL']=='1','candidate_factory_passed':os.environ['CRX_FACTORY']=='1','stage':os.environ['CRX_STAGE'],'original_component_targeted':False,'original_panels_complete':False,'recovered_original_panels_available':True,'sound_fidelity_verified':False,'private_preferences_in_report':False},indent=2)+'\n')
PY
 for directory in "$CORE" "$ROOT/work/cronox-engine" "$BUILD" "$BUILD/sdk"; do
  if [[ -d "$directory" ]]; then
   name="$(basename "$directory")";mkdir -p "$REPORT/compilation-$name"
   for log in "$directory"/*.compile.log; do if [[ -f "$log" ]]; then /bin/cp "$log" "$REPORT/compilation-$name/" || true;fi;done
  fi
 done
 /usr/bin/ditto -c -k --sequesterRsrc --keepParent "$REPORT" "$REPORT.zip" || true
 /usr/bin/open -R "$REPORT.zip" || true
 if [[ "$installed" -eq 1 ]]; then
  echo 'CronoX 3 ARM Test (CRX013) installé et validé. Rouvrez Logic ou Live pour le trouver.'
  echo 'L’original CrX3 et Sophistry CP038 ont été conservés.'
 else
  echo 'Installation CRX013 non confirmée. Le rapport contient le détail de l’échec.' >&2
 fi
 echo "Rapport : $REPORT.zip"
 exit "$result"
}
trap finish EXIT
trap 'exit 130' INT
trap 'exit 143' TERM
exec > >(/usr/bin/tee "$REPORT/diagnostic.log") 2>&1
{
 /usr/bin/sw_vers
 /usr/bin/uname -m
 /usr/bin/xcrun clang++ --version
} > "$REPORT/configuration.txt" 2>&1
echo 'CronoX 3 ARM Test — CRX013 : compilation, rendu, interface et validation Audio Unit.'
echo 'Seul CronoX 3 ARM Test.component sera installé. L’original CrX3 reste en place.'
/usr/bin/python3 "$ROOT/scripts/prepare-cronox-source.py"
/usr/bin/python3 "$ROOT/scripts/generate-cronox-au-identity.py"
ACTIVE_TRANSACTION='/Library/Audio/Plug-Ins/CronoX3ARMTest-Rollback/active.json'
if [[ -f "$ACTIVE_TRANSACTION" ]]; then
 stage='récupération de la tentative précédente'
 previous="$(/usr/bin/python3 -c 'import json,sys;print(json.load(open(sys.argv[1]))["id"])' "$ACTIVE_TRANSACTION")"
 sudo /usr/bin/python3 "$TRANSACTION_TOOL" rollback --transaction "$previous" > "$REPORT/interrupted-recovery.json"
 /usr/bin/killall -u "$(id -u)" AudioComponentRegistrar 2>/dev/null || true
fi
stage='compilation'
bash "$ROOT/scripts/build-cronox-audio-unit.sh" "$BUILD" "$CORE"
CANDIDATE="$BUILD/CronoX 3 ARM Test.component"
/usr/bin/python3 "$ROOT/scripts/verify-cronox-bundle.py" "$CANDIDATE" --exports "$BUILD/exports.txt" > "$REPORT/bundle-identity.json"
/usr/bin/file "$CANDIDATE/Contents/MacOS/CronoX3ARMTest" > "$REPORT/architectures.txt"
/bin/cp "$BUILD/exports.txt" "$REPORT/exports.txt"
stage='temporisateurs et destruction d’origine'
"$BUILD/CronoXRunLoopProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" > "$REPORT/run-loop.json" 2> "$REPORT/run-loop.log"
"$BUILD/CronoXControlThreadProbe" > "$REPORT/control-thread.json" 2> "$REPORT/control-thread.log"
stage='commandes de l’interface originale'
"$BUILD/CronoXEditorProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" > "$REPORT/editor-bindings.json" 2> "$REPORT/editor-bindings.log"
stage='vérification du gain avant Master et des champs du sampler'
"$BUILD/CronoXCorrectionsProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" > "$REPORT/crx013-corrections.json" 2> "$REPORT/crx013-corrections.log"
stage='vérification des boucles et du cache de forme d’onde'
"$BUILD/CronoXLoopSamplerProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" > "$REPORT/loop-sampler.json" 2> "$REPORT/loop-sampler.log"
stage='vérification des banques et du clavier polyphonique'
/usr/bin/python3 "$ROOT/scripts/create-cronox-browser-fixture.py" "$REPORT/browser-fixture"
"$BUILD/CronoXBrowserKeyboardProbe" "$REPORT/browser-fixture" > "$REPORT/browser-keyboard.json" 2> "$REPORT/browser-keyboard.log"
stage='catégories Matrix et arpégiateur originaux'
"$BUILD/CronoXModulationProbe" > "$REPORT/modulation.json" 2> "$REPORT/modulation.log"
stage='concordance bit à bit de la réverbération originale'
"$BUILD/CronoXNativeReverbProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" > "$REPORT/native-reverb.json" 2> "$REPORT/native-reverb.log"
stage='prévalidation du candidat'
"$BUILD/CronoXComparisonProbe" --bundle "$CANDIDATE" --preset "$ROOT/reference/Presets/lightgarden 02 BT.FXP" --output "$REPORT/candidate-stereo" --channels 2 > "$REPORT/candidate-stereo.log" 2>&1
factory_passed=1
# Verify the exact native comparison path and identifiers before any mutation.
[[ "$TARGET" != "$ORIGINAL" && "$TARGET" == '/Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component' ]] || exit 2
stage='copie du composant de comparaison'
TRANSACTION="$(/usr/bin/python3 -c 'import uuid;print(uuid.uuid4().hex)')"
BINARY_SHA256="$(/usr/bin/shasum -a 256 "$CANDIDATE/Contents/MacOS/CronoX3ARMTest" | /usr/bin/awk '{print $1}')"
sudo /usr/bin/python3 "$TRANSACTION_TOOL" install --transaction "$TRANSACTION" --source "$CANDIDATE" --expected-sha256 "$BINARY_SHA256" > "$REPORT/component-transaction.json"
# Notify discovery only after the atomically installed candidate is visible.
sudo /usr/bin/touch "$TARGET" "$(dirname "$TARGET")"
/usr/bin/killall -u "$(id -u)" AudioComponentRegistrar 2>/dev/null || true
stage='détection du composant installé'
if ! /usr/bin/python3 "$ROOT/scripts/diagnose-cronox-registration.py" > "$REPORT/registration-initial.json" 2> "$REPORT/registration-initial.log"; then
 echo 'Diagnostic facultatif incomplet ; poursuite de la détection et de la validation Audio Unit.' >&2
fi
if ! /usr/bin/python3 "$ROOT/scripts/wait-cronox-registration.py" --probe "$BUILD/CronoXRegistrationProbe" --report "$REPORT" --timeout 30 > "$REPORT/registration-result.json"; then
 /usr/bin/python3 "$ROOT/scripts/diagnose-cronox-registration.py" --logs > "$REPORT/registration-failure.json" || true
 echo 'Le registre Audio Unit ne charge pas le composant CrT3 attendu ; récupération de ARM Test.' >&2
 exit 1
fi
stage='validation auval CrT3'
if ! /usr/bin/python3 "$ROOT/scripts/run-cronox-auval.py" --log "$REPORT/auval.log" --timeout 180 > "$REPORT/auval-result.json"; then
 /usr/bin/python3 "$ROOT/scripts/diagnose-cronox-registration.py" --logs > "$REPORT/auval-environment.json" || true
 exit 1
fi
auval_passed=1
stage='rendu du composant enregistré'
"$BUILD/CronoXComparisonProbe" --registered --preset "$ROOT/reference/Presets/lightgarden 02 BT.FXP" --output "$REPORT/registered-stereo" --channels 2 > "$REPORT/registered-stereo.log" 2>&1
"$BUILD/CronoXComparisonProbe" --registered --preset "$ROOT/reference/Presets/lightgarden 02 BT.FXP" --output "$REPORT/registered-six-channel" --channels 6 > "$REPORT/registered-six-channel.log" 2>&1
stage='confirmation de la transaction'
sudo /usr/bin/python3 "$TRANSACTION_TOOL" commit --transaction "$TRANSACTION" > "$REPORT/component-committed.json"
stage='installation confirmée'
installed=1
