#!/bin/bash
# CP-018: test installation with original registration, verified backup and rollback.
set +x
set -euo pipefail
umask 077
ROOT="$(cd "$(dirname "$0")" && pwd)"
cd "$ROOT"
choose_bank=0
for argument in "$@"; do
  if [[ "$argument" == --choose-bank ]]; then choose_bank=1;
  else echo 'Usage : Installer-ARM64.command [--choose-bank]' >&2;exit 2;fi
done
if [[ "$(uname -s)" != Darwin || "$(uname -m)" != arm64 || "$EUID" -eq 0 ]]; then
  echo 'Lancez ce script dans un Terminal natif Apple Silicon, sans sudo.' >&2
  exit 2
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
  printf '{"checkpoint":"CP-018","system_installation_committed":%s,"rollback_completed_if_needed":%s,"validated_settings_retained":%s,"auval_and_registered_audio_passed":%s,"original_ui_complete":false,"project_recall_verified":false,"private_preferences_in_report":false}\n' \
    "$(if [[ "$committed" -eq 1 ]]; then echo true;else echo false;fi)" "$rollback_ok" \
    "$(if [[ "$settings_confirmed" -eq 1 ]]; then echo true;else echo false;fi)" \
    "$(if [[ "$committed" -eq 1 ]]; then echo true;else echo false;fi)" > "$REPORT/result.json"
  archive="$ROOT/Sophistry-rapports-CP018-$STAMP.zip"
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
echo 'Sophistry CP-018 — installation de test ARM64 avec sauvegarde et validation AU'
echo 'Cette version ajoute une première vue Cocoa avec état du son et choix de banque. Testez des copies de vos projets.'
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
"$BUILD/NativeAUBridgeProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" > "$REPORT/bridge-regression.json" 2> "$REPORT/bridge-errors.log"
"$BUILD/NativeBankDiagnosticsProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" "$ROOT/work/unavailable-bank-fixture" > "$REPORT/bank-diagnostics.json" 2> "$REPORT/bank-diagnostics.log"
stage='configuration locale de la banque et de la licence'
bank_options=()
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
    printf '%s\n' "$serial_input" | "$BUILD/ConfigureSophistry" --registration-from-stdin "${bank_options[@]}" --backup-directory "$PRIVATE" --asset-directory "$ROOT/reference/Samples" > "$REPORT/settings-configured.json" 2>&1
  else
    "$BUILD/ConfigureSophistry" "${bank_options[@]}" --backup-directory "$PRIVATE" --asset-directory "$ROOT/reference/Samples" > "$REPORT/settings-configured.json" 2>&1
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
stage='prévalidation de la vue Cocoa et des commandes de presets'
"$SYSTEM_PYTHON" - "$BUILD/AudioUnitEditorProbe" "$BUILD/Sophistry.component" "$state" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$REPORT/editor" > "$REPORT/editor.log" 2>&1 <<'PY'
import subprocess,sys
try:
    result=subprocess.run(sys.argv[1:],timeout=60)
except subprocess.TimeoutExpired:
    raise SystemExit('Le test de la vue Cocoa a dépassé une minute ; le composant installé reste conservé.')
raise SystemExit(result.returncode)
PY
/usr/bin/cmp "$REPORT/editor.wav" "$REPORT/original-2.wav" > "$REPORT/editor-audio-comparison.txt" 2>&1
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
for channels in 2 6; do
  stage="rendu du composant installé $channels canaux"
  "$BUILD/AudioUnitFactoryProbe" --registered --state "$state" --contract "$contract" --channels "$channels" --output-prefix "$REPORT/registered-$channels" > "$REPORT/registered-$channels.log" 2>&1
  /usr/bin/cmp "$REPORT/registered-$channels.wav" "$REPORT/original-$channels.wav" > "$REPORT/registered-comparison-$channels.txt" 2>&1
  printf '{"channels":%s,"preflight_vs_original_byte_exact":true,"registered_vs_original_byte_exact":true}\n' "$channels" > "$REPORT/audio-comparison-$channels.json"
done
stage='vue Cocoa et diagnostic dans un hôte AU séparé'
"$SYSTEM_PYTHON" - "$BUILD/AudioUnitEditorProbe" '/Library/Audio/Plug-Ins/Components/Sophistry.component' "$state" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$REPORT/editor-remote" --remote > "$REPORT/editor-remote.log" 2>&1 <<'PY'
import subprocess,sys
try:
    result=subprocess.run(sys.argv[1:],timeout=60)
except subprocess.TimeoutExpired:
    raise SystemExit('Le test de l’hôte AU séparé a dépassé une minute.')
raise SystemExit(result.returncode)
PY
/usr/bin/cmp "$REPORT/editor-remote.wav" "$REPORT/original-2.wav" > "$REPORT/editor-remote-audio-comparison.txt" 2>&1
stage='confirmation de l’installation vérifiée'
/usr/bin/sudo -- "$SYSTEM_PYTHON" "$PRIVATE/ComponentTransaction.py" commit --transaction "$TRANSACTION" > "$REPORT/component-commit.json" 2>&1
committed=1
stage='installation de test terminée'
echo 'Le candidat ARM64 est installé dans /Library/Audio/Plug-Ins/Components/Sophistry.component.'
echo 'auval et les comparaisons audio passent. La réouverture des projets Logic/Live et l’interface d’origine restent à valider.'
exit 0
