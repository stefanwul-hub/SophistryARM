#!/bin/bash
# CP-032: test installation with original registration, verified backup and rollback.
set +x
set -euo pipefail
umask 077
ROOT="$(cd "$(dirname "$0")" && pwd)"
cd "$ROOT"
choose_bank=0
diagnose_only=0
recenter_windows=0
for argument in "$@"; do
  if [[ "$argument" == --choose-bank ]]; then choose_bank=1;
  elif [[ "$argument" == --diagnose-only ]]; then diagnose_only=1;
  elif [[ "$argument" == --recenter-windows ]]; then recenter_windows=1;
  else echo 'Usage : Installer-ARM64.command [--choose-bank | --diagnose-only | --recenter-windows]' >&2;exit 2;fi
done
if [[ "$(uname -s)" != Darwin || "$(uname -m)" != arm64 || "$EUID" -eq 0 ]]; then
  echo 'Lancez ce script dans un Terminal natif Apple Silicon, sans sudo.' >&2
  exit 2
fi
if [[ "$((choose_bank + diagnose_only + recenter_windows))" -gt 1 ]]; then
  echo 'Utilisez une seule option à la fois.' >&2
  exit 2
fi
if [[ "$recenter_windows" -eq 1 ]]; then
  exec /bin/bash "$ROOT/Recentrer-Fenetre-Sophistry.command"
fi
if [[ "$diagnose_only" -eq 1 ]]; then
  exec /bin/bash "$ROOT/Diagnostiquer-Sophistry.command"
fi
closed_daws(){
  for app in 'Logic Pro' 'Logic' 'Live' 'Ableton Live'; do
    if /usr/bin/pgrep -u "$(id -u)" -x "$app" >/dev/null 2>&1; then
      echo 'Fermez Logic et Live avant de remplacer le composant ; aucun projet ne sera fermé automatiquement.' >&2
      return 1
    fi
  done
}
closed_daws
SYSTEM_PYTHON="$(/usr/bin/xcrun --find python3)"
PRIVATE_BASE="$HOME/Library/Application Support/SophistryARM/Backups"
ACTIVE='/Library/Audio/Plug-Ins/SophistryARM-Rollback/active.json'
if [[ -r "$ACTIVE" ]]; then
  pending="$("$SYSTEM_PYTHON" - "$ACTIVE" <<'PY'
import json,re,sys
value=json.load(open(sys.argv[1])).get('id','')
if not re.fullmatch('[0-9a-f]{32}',value):raise SystemExit('Journal de récupération invalide')
print(value)
PY
)"
  prior="$PRIVATE_BASE/$pending"
  if [[ ! -f "$prior/Restaurer-Sophistry.command" ]]; then
    echo 'Une transaction système est encore en attente ; son dossier de restauration appartient à une autre session ou à un autre utilisateur.' >&2
    exit 1
  fi
  prior_pid="$(cat "$prior/controller.pid" 2>/dev/null || true)"
  case "$prior_pid" in ''|*[!0-9]*) prior_pid=0;; esac
  if [[ "$prior_pid" -gt 0 ]] && /bin/ps -p "$prior_pid" -o command= 2>/dev/null | /usr/bin/grep -q 'Installer-ARM64.command'; then
    echo 'Une installation Sophistry est déjà en cours.' >&2
    exit 1
  fi
  echo 'Une tentative interrompue a été trouvée ; restauration de son état précédent avant reprise.'
  /bin/bash "$prior/Restaurer-Sophistry.command"
fi
STAMP="$(date -u +%Y%m%dT%H%M%SZ)"
TRANSACTION="$("$SYSTEM_PYTHON" -c 'import uuid;print(uuid.uuid4().hex)')"
PRIVATE="$PRIVATE_BASE/$TRANSACTION"
REPORT="$ROOT/work/mac-install-reports-$STAMP"
BUILD="$ROOT/work/audio-unit"
CORE="$ROOT/work/lifter-whole"
mkdir -p "$PRIVATE/bin" "$REPORT"
printf '%s\n' "$$" > "$PRIVATE/controller.pid"
exec > >(/usr/bin/tee "$REPORT/diagnostic.log") 2>&1
stage='début'
installation_started=0
committed=0
settings_confirmed=0
auval_passed=0
registered_audio_passed=0
editor_local_passed=0
remote_host_passed=0
collect(){
  result=$?
  trap - EXIT INT TERM
  unset serial_input
  rollback_ok=true
  if [[ "$result" -ne 0 && "$committed" -eq 0 ]]; then
    if [[ "$installation_started" -eq 1 ]]; then
      echo 'Échec de validation : restauration du composant précédent…'
      /usr/bin/sudo -- "$SYSTEM_PYTHON" "$PRIVATE/ComponentTransaction.py" rollback --transaction "$TRANSACTION" > "$REPORT/component-rollback.json" 2>&1 || rollback_ok=false
    fi
    if [[ "$rollback_ok" == true && "$settings_confirmed" -eq 0 && -f "$PRIVATE/Preferences-privees-avant-installation.plist" ]]; then
      "$PRIVATE/bin/ConfigureSophistry" --restore-backup "$PRIVATE/Preferences-privees-avant-installation.plist" > "$REPORT/preferences-rollback.json" 2>&1 || rollback_ok=false
    fi
    if [[ "$settings_confirmed" -eq 1 ]]; then
      echo 'La licence et le dossier de sons ont été vérifiés dans un nouveau processus et restent enregistrés pour la prochaine tentative.'
    fi
    if [[ "$installation_started" -eq 1 ]]; then /usr/bin/killall -u "$(id -u)" AudioComponentRegistrar >/dev/null 2>&1 || true;fi
  fi
  for log in "$CORE"/*.compile.log "$BUILD/sdk"/*.compile.log "$BUILD/host"/*.compile.log "$BUILD"/*.compile.log; do
    if [[ -s "$log" ]]; then cp "$log" "$REPORT/compile-$(basename "$(dirname "$log")")-$(basename "$log")"; fi
  done
  printf '%s\n' "$result" > "$REPORT/script-exitcode.txt"
  printf '%s\n' "$stage" > "$REPORT/last-stage.txt"
  printf '{"checkpoint":"CP-032","system_installation_committed":%s,"rollback_completed_if_needed":%s,"validated_settings_retained":%s,"auval_and_registered_audio_passed":%s,"local_editor_and_audio_passed":%s,"remote_host_view_and_audio_passed":%s,"script_exitcode":%s,"recovered_constructor_controls":1067,"mac_gui_review_complete":false,"project_recall_verified":false,"private_preferences_in_report":false}\n' \
    "$(if [[ "$committed" -eq 1 ]]; then echo true;else echo false;fi)" "$rollback_ok" \
    "$(if [[ "$settings_confirmed" -eq 1 ]]; then echo true;else echo false;fi)" \
    "$(if [[ "${auval_passed:-0}" -eq 1 && "${registered_audio_passed:-0}" -eq 1 ]]; then echo true;else echo false;fi)" \
    "$(if [[ "${editor_local_passed:-0}" -eq 1 ]]; then echo true;else echo false;fi)" \
    "$(if [[ "${remote_host_passed:-0}" -eq 1 ]]; then echo true;else echo false;fi)" \
    "$result" > "$REPORT/result.json"
  if [[ "$result" -ne 0 ]]; then
    printf '%s\n' "Installation CP032 non confirmée : $stage (code $result)."
    if [[ "$installation_started" -eq 1 && "$committed" -eq 0 && "$rollback_ok" == true ]]; then
      echo 'Le composant précédent a été restauré : la nouvelle interface CP032 n’est donc pas installée.'
    elif [[ "$installation_started" -eq 0 ]]; then
      echo 'Le composant installé auparavant a été conservé.'
      echo 'Les corrections de cette tentative ne sont pas installées ; Logic et Live affichent encore la version précédente.'
    fi
  fi
  archive="$ROOT/Sophistry-rapports-CP032-$STAMP.zip"
  (cd "$REPORT"; /usr/bin/zip -q "$archive" ./*.json ./*.txt ./*.log ./*.wav ./*.png 2>/dev/null || true)
  printf '\n%s\n' "Rapports : $archive"
  printf '%s\n' "Restauration autonome : $PRIVATE/Restaurer-Sophistry.command"
  if [[ "$rollback_ok" != true ]]; then
    echo 'La restauration automatique n’est pas complète. Les anciennes copies sont conservées ; consultez les rapports de restauration.' >&2
  fi
  /usr/bin/open -R "$archive" >/dev/null 2>&1 || true
  exit "$result"
}
trap collect EXIT
trap 'exit 130' INT
trap 'exit 143' TERM
echo 'Sophistry CP-032 — installation de test ARM64 avec sauvegarde et validation AU'
echo 'Cette version affiche le nom des samples sans les anciens chemins Windows. Testez des copies de vos projets.'
/usr/bin/sw_vers
/usr/bin/uname -m
/usr/bin/xcrun clang++ --version
stage='compilation ARM64'
bash "$ROOT/scripts/build-audio-unit.sh" "$BUILD" "$CORE" 2>&1 | /usr/bin/tee "$REPORT/build.log"
cp "$ROOT/scripts/component_transaction.py" "$PRIVATE/ComponentTransaction.py"
cp "$ROOT/scripts/Restaurer-Sophistry.command" "$PRIVATE/Restaurer-Sophistry.command"
cp -p "$BUILD/ConfigureSophistry" "$PRIVATE/bin/ConfigureSophistry"
chmod 700 "$PRIVATE/Restaurer-Sophistry.command"
stage='replays et régression du moteur AU'
"$CORE/LiftedProbe" "$ROOT/reference/Sophistry.i386" "$ROOT/evidence/static-lift-comparison.fixtures" > "$REPORT/dsp-replay.json"
"$CORE/InstructionProbe" "$ROOT/reference/Sophistry.i386" "$ROOT/evidence/primitive-instructions.fixtures" > "$REPORT/instruction-replay.json"
stage='régression des blocs et tables de saut récupérés'
/usr/bin/gzip -dc "$ROOT/evidence/recovered-code-cp032.fixtures.gz" > "$ROOT/work/recovered-code-cp032.fixtures"
"$CORE/InstructionProbe" "$ROOT/reference/Sophistry.i386" "$ROOT/work/recovered-code-cp032.fixtures" > "$REPORT/recovered-code.json"
"$BUILD/NativeAUBridgeProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" > "$REPORT/bridge-regression.json" 2> "$REPORT/bridge-errors.log"
"$BUILD/NativeBankDiagnosticsProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" "$ROOT/work/unavailable-bank-fixture" > "$REPORT/bank-diagnostics.json" 2> "$REPORT/bank-diagnostics.log"
stage='équivalence numérique des conversions flottantes'
"$BUILD/FloatConversionProbe" > "$REPORT/float-conversions.json" 2> "$REPORT/float-conversions.log"
stage='fidélité du mode flottant du rendu original'
"$BUILD/AudioFloatModeProbe" > "$REPORT/audio-float-mode.json" 2> "$REPORT/audio-float-mode.log"
stage='restauration du volume Master original'
"$BUILD/MasterVolumeProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" > "$REPORT/master-volume.json" 2> "$REPORT/master-volume.log"
stage='validation PCM avec la référence Core Audio native'
"$BUILD/PcmConversionProbe" > "$REPORT/pcm-conversion.json" 2> "$REPORT/pcm-conversion.log"
stage='vérification des images des générateurs'
"$BUILD/GeneratorLayoutProbe" "$BUILD/Sophistry.component/Contents/Resources/OriginalImages" > "$REPORT/generator-layout.json" 2> "$REPORT/generator-layout.log"
stage='vérification de la réutilisation de mémoire invitée'
"$BUILD/GuestAllocatorProbe" > "$REPORT/guest-allocator.json" 2> "$REPORT/guest-allocator.log"
stage='configuration locale de la banque et de la licence'
bank_options=(--backup-directory "$PRIVATE" --asset-directory "$ROOT/reference/Samples")
if [[ "$choose_bank" -eq 1 ]]; then bank_options+=(--choose-bank);fi
if "$BUILD/ConfigureSophistry" --check --no-folder-panel --asset-directory "$ROOT/reference/Samples" > "$REPORT/settings-existing.json" 2>&1; then
  if [[ "$choose_bank" -eq 1 ]]; then
    "$BUILD/ConfigureSophistry" --choose-bank --backup-directory "$PRIVATE" --asset-directory "$ROOT/reference/Samples" > "$REPORT/settings-configured.json" 2>&1
  else echo 'La banque et l’enregistrement local sont réutilisés.';fi
else
  echo 'Choisissez ensuite votre dossier de sons dans la fenêtre qui va s’ouvrir.'
  echo 'La clé sera enregistrée localement au format LinPlug d’origine après son contrôle original.'
  echo 'Entrée seule : essayer les anciennes préférences LinPlug de ce Mac.'
  printf '%s' 'Numéro de série Sophistry (saisie masquée) : '
  serial_input=''
  IFS= read -r -s serial_input < /dev/tty
  printf '\n'
  if [[ -n "$serial_input" ]]; then
    printf '%s\n' "$serial_input" | "$BUILD/ConfigureSophistry" --registration-from-stdin "${bank_options[@]}" > "$REPORT/settings-configured.json" 2>&1
  else
    "$BUILD/ConfigureSophistry" "${bank_options[@]}" > "$REPORT/settings-configured.json" 2>&1
  fi
  unset serial_input
fi
stage='vérification de l’enregistrement dans un nouveau processus'
"$BUILD/ConfigureSophistry" --check --no-folder-panel --asset-directory "$ROOT/reference/Samples" > "$REPORT/settings-fresh-process.json" 2>&1
settings_confirmed=1
printf 'validated in a fresh process\n' > "$PRIVATE/Settings-validated.txt"
stage='préparation de la référence originale locale'
REFERENCE_PYTHON="$ROOT/work/reference-python/bin/python3"
if [[ ! -x "$REFERENCE_PYTHON" ]]; then "$SYSTEM_PYTHON" -m venv "$ROOT/work/reference-python" > "$REPORT/reference-setup.log" 2>&1;fi
"$REFERENCE_PYTHON" -m pip --disable-pip-version-check install --cache-dir "$ROOT/work/pip-cache" --only-binary=:all: -r "$ROOT/requirements-analysis.txt" >> "$REPORT/reference-setup.log" 2>&1
state="$ROOT/reference/Presets/Lightgarden 02 BT.aupreset"
contract="$ROOT/tests/fixtures/original-au-parameters.plist"
for channels in 2 6; do
  stage="prévalidation du candidat $channels canaux"
  "$BUILD/AudioUnitFactoryProbe" --bundle "$BUILD/Sophistry.component" --state "$state" --contract "$contract" --channels "$channels" --output-prefix "$REPORT/preflight-$channels" > "$REPORT/preflight-$channels.log" 2>&1
  "$REFERENCE_PYTHON" "$ROOT/tests/probe_au_render.py" --state "$state" --channels "$channels" --seconds 3 --local-mac-preferences --output "$REPORT/original-$channels.json" > "$REPORT/original-$channels.log" 2>&1
  /usr/bin/cmp "$REPORT/preflight-$channels.wav" "$REPORT/original-$channels.wav" > "$REPORT/preflight-comparison-$channels.txt" 2>&1
done
stage='génération des fixtures publiques de formats de samples'
FORMATS="$ROOT/work/sample-formats"
"$SYSTEM_PYTHON" "$ROOT/tests/generate_sample_formats.py" "$FORMATS" > "$REPORT/sample-formats-generation.json" 2>&1
stage='chargements répétés de douze formats et stabilité mémoire'
"$BUILD/NativePresetCycleProbe" "$FORMATS" > "$REPORT/preset-cycles.json" 2> "$REPORT/preset-cycles.log"
for format in d4u-32-1 d4u-32-2; do
  stage="rendu D4U par moteur AU et référence originale : $format"
  "$BUILD/host/NativeEngineProbe" --state "$FORMATS/$format/program.aupreset" --asset-directory "$FORMATS/$format" --au-channels 2 --render 3 --local-mac-preferences --output-prefix "$REPORT/format-$format-native" > "$REPORT/format-$format-native.log" 2>&1
  "$REFERENCE_PYTHON" "$ROOT/tests/probe_au_render.py" --state "$FORMATS/$format/program.aupreset" --asset-directory "$FORMATS/$format" --channels 2 --seconds 3 --local-mac-preferences --output "$REPORT/format-$format-original.json" > "$REPORT/format-$format-original.log" 2>&1
  /usr/bin/cmp "$REPORT/format-$format-native.wav" "$REPORT/format-$format-original.wav" > "$REPORT/format-$format-comparison.txt" 2>&1
done
stage='commandes des générateurs contre les instructions originales'
"$REFERENCE_PYTHON" "$ROOT/tests/compare_generator_controls.py" --engine "$BUILD/NativeGeneratorProbe" --output "$ROOT/work/generator-comparison" > "$REPORT/generator-comparison.log" 2>&1
cp "$ROOT/work/generator-comparison/comparison.json" "$REPORT/generator-comparison.json"
stage='tracés et commandes Main/Filter contre les instructions originales'
"$REFERENCE_PYTHON" "$ROOT/tests/compare_editor_controls.py" --engine "$BUILD/NativeEditorProbe" --output "$ROOT/work/editor-comparison" > "$REPORT/original-editor-comparison.log" 2>&1
cp "$ROOT/work/editor-comparison/comparison.json" "$REPORT/original-editor-comparison.json"
stage='interface complète et modules contre les instructions originales'
"$REFERENCE_PYTHON" "$ROOT/tests/compare_complete_editor.py" --engine "$BUILD/NativeCompleteEditorProbe" --output "$ROOT/work/complete-editor-comparison" > "$REPORT/complete-editor-comparison.log" 2>&1
cp "$ROOT/work/complete-editor-comparison/comparison.json" "$REPORT/complete-editor-comparison.json"
stage='prévalidation de la vue Cocoa et des commandes de presets'
"$SYSTEM_PYTHON" - "$BUILD/AudioUnitEditorProbe" "$BUILD/Sophistry.component" "$state" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$REPORT/editor" "$ROOT/tests/fixtures/loop-preview.fxp" > "$REPORT/editor.log" 2>&1 <<'PY'
import subprocess,sys
try:
    result=subprocess.run(sys.argv[1:],timeout=180)
except subprocess.TimeoutExpired:
    raise SystemExit('Le test de la vue Cocoa a dépassé trois minutes ; le composant installé reste conservé.')
raise SystemExit(result.returncode)
PY
/usr/bin/cmp "$REPORT/editor.wav" "$REPORT/original-2.wav" > "$REPORT/editor-audio-comparison.txt" 2>&1
editor_local_passed=1
stage='sauvegarde et remplacement du composant système'
closed_daws
echo 'Les prévalidations passent. macOS demande maintenant les droits pour sauvegarder et remplacer Sophistry.component.'
/usr/bin/sudo -v
binary_sha="$(/usr/bin/shasum -a 256 "$BUILD/Sophistry.component/Contents/MacOS/Sophistry" | /usr/bin/awk '{print $1}')"
installation_started=1
/usr/bin/sudo -- "$SYSTEM_PYTHON" "$PRIVATE/ComponentTransaction.py" install --source "$BUILD/Sophistry.component" --expected-sha256 "$binary_sha" --transaction "$TRANSACTION" > "$REPORT/component-installation.json" 2>&1
/usr/bin/killall -u "$(id -u)" AudioComponentRegistrar >/dev/null 2>&1 || true
stage='détection du candidat par le registre Audio Unit'
registered=false
for attempt in 1 2 3 4 5 6 7 8 9 10; do
  if "$BUILD/AudioUnitFactoryProbe" --registered --discover-only --state "$state" --contract "$contract" --output-prefix "$REPORT/discovery-$attempt" > "$REPORT/discovery-$attempt.log" 2>&1; then registered=true;break;fi
  /bin/sleep 2
done
if [[ "$registered" != true ]]; then echo 'Le registre AU ne charge pas le candidat attendu.' >&2;exit 1;fi
stage='validation auval'
echo 'Validation auval en cours (limite de trois minutes)…'
"$SYSTEM_PYTHON" "$ROOT/scripts/run_auval.py" --log "$REPORT/auval.log" --timeout 180 > "$REPORT/auval-result.json"
auval_passed=1
for channels in 2 6; do
  stage="rendu du composant installé $channels canaux"
  "$BUILD/AudioUnitFactoryProbe" --registered --state "$state" --contract "$contract" --channels "$channels" --output-prefix "$REPORT/registered-$channels" > "$REPORT/registered-$channels.log" 2>&1
  /usr/bin/cmp "$REPORT/registered-$channels.wav" "$REPORT/original-$channels.wav" > "$REPORT/registered-comparison-$channels.txt" 2>&1
  printf '{"channels":%s,"preflight_vs_original_byte_exact":true,"registered_vs_original_byte_exact":true}\n' "$channels" > "$REPORT/audio-comparison-$channels.json"
done
registered_audio_passed=1
stage='hôte AU séparé : propriétés publiques, vue système et rendu audio'
"$SYSTEM_PYTHON" - "$BUILD/AudioUnitRemoteHostProbe" "$state" "$contract" "$REPORT/remote-host" > "$REPORT/remote-host.log" 2>&1 <<'PY'
import subprocess,sys
try:
    result=subprocess.run(sys.argv[1:],timeout=180)
except subprocess.TimeoutExpired:
    raise SystemExit('Le test de l’hôte AU séparé a dépassé trois minutes.')
raise SystemExit(result.returncode)
PY
/usr/bin/cmp "$REPORT/remote-host.wav" "$REPORT/original-2.wav" > "$REPORT/remote-host-audio-comparison.txt" 2>&1
remote_host_passed=1
stage='inspection finale du composant enregistré'
"$SYSTEM_PYTHON" - "$BUILD/InstalledAUInspector" "$REPORT/installed-inspection.json" > "$REPORT/installed-inspection.log" 2>&1 <<'PY'
import json,subprocess,sys
try:
    result=subprocess.run(sys.argv[1:],timeout=180)
except subprocess.TimeoutExpired:
    raise SystemExit('L’inspection finale a dépassé trois minutes.')
if result.returncode: raise SystemExit(result.returncode)
r=json.load(open(sys.argv[2]))
if not (r['current_checkpoint_loaded'] and r['cocoa_property_available'] and r['registered_matches']==1):
    raise SystemExit('L’inspection finale ne confirme pas la version CP032 et sa propriété Cocoa.')
PY
stage='confirmation de l’installation vérifiée'
/usr/bin/sudo -- "$SYSTEM_PYTHON" "$PRIVATE/ComponentTransaction.py" commit --transaction "$TRANSACTION" > "$REPORT/component-commit.json" 2>&1
committed=1
stage='installation de test terminée'
echo 'Le candidat ARM64 est installé dans /Library/Audio/Plug-Ins/Components/Sophistry.component.'
echo 'Installation CP032 confirmée : auval, éditeur local, hôte séparé avec vue système et comparaisons audio passent.'
echo 'Après réouverture de Logic/Live, vérifiez la mention SophistryARM CP-032 en bas de l’éditeur.'
echo 'Le rappel sonore des projets et la fenêtre relayée par Logic/Live restent à vérifier sur des copies.'
exit 0
