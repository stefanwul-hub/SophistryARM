#!/bin/bash
# Inspect the installed AU without replacing it or opening its editor.
set +x
set -euo pipefail
umask 077
if [[ "$(uname -s)" != Darwin || "$(uname -m)" != arm64 || "$EUID" -eq 0 ]]; then
  echo 'Lancez ce diagnostic sur votre Mac Apple Silicon, sans sudo.' >&2
  exit 2
fi
ROOT="$(cd "$(dirname "$0")" && pwd)"
STAMP="$(date -u +%Y%m%dT%H%M%SZ)"
REPORT="$ROOT/work/inspection-$STAMP"
BUILD="$ROOT/work/inspection-tool"
mkdir -p "$REPORT" "$BUILD"
collect(){
  result=$?
  trap - EXIT
  printf '%s\n' "$result" > "$REPORT/script-exitcode.txt"
  archive="$ROOT/Sophistry-inspection-CP022-$STAMP.zip"
  (cd "$REPORT"; /usr/bin/zip -q "$archive" ./*.json ./*.log ./*.txt 2>/dev/null || true)
  printf '\n%s\n' "Rapport : $archive"
  /usr/bin/open -R "$archive" >/dev/null 2>&1 || true
  exit "$result"
}
trap collect EXIT
echo 'Inspection du composant installé, sans ouvrir son interface ni modifier vos projets.'
echo 'Cette instance de contrôle ne lit pas l’état de la piste déjà ouverte dans Logic ou Live.'
key="$( { /usr/bin/xcrun clang++ --version; cat "$ROOT/tests/InstalledAUInspector.mm" "$ROOT/src/au/SophistryProperties.h"; } | /usr/bin/shasum -a 256 | /usr/bin/awk '{print $1}')"
if [[ ! -x "$BUILD/InstalledAUInspector" || ! -f "$BUILD/compile.sha256" || "$(cat "$BUILD/compile.sha256")" != "$key" ]]; then
  /usr/bin/xcrun clang++ -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -fobjc-arc \
    "$ROOT/tests/InstalledAUInspector.mm" -framework Foundation -framework AudioToolbox \
    -o "$BUILD/InstalledAUInspector.pending" > "$REPORT/compile.log" 2>&1
  /usr/bin/lipo "$BUILD/InstalledAUInspector.pending" -verify_arch arm64
  mv "$BUILD/InstalledAUInspector.pending" "$BUILD/InstalledAUInspector"
  printf '%s\n' "$key" > "$BUILD/compile.sha256"
fi
SYSTEM_PYTHON="$(/usr/bin/xcrun --find python3)"
"$SYSTEM_PYTHON" - "$BUILD/InstalledAUInspector" "$REPORT/installed-component.json" > "$REPORT/inspection.log" 2>&1 <<'PY'
import subprocess,sys
try:
    result=subprocess.run(sys.argv[1:],timeout=60)
except subprocess.TimeoutExpired:
    raise SystemExit('Le contrôle du composant a dépassé une minute.')
raise SystemExit(result.returncode)
PY
"$SYSTEM_PYTHON" - "$REPORT/installed-component.json" <<'PY'
import json,sys
r=json.load(open(sys.argv[1]))
print('Version réellement chargée :',r['loaded_wrapper_version'] or 'non identifiée')
print('Propriété de vue Cocoa disponible :', 'oui' if r['cocoa_property_available'] else 'non')
if not r['current_checkpoint_loaded']:
    print('Le registre charge une autre version que CP022 ; consulter le rapport avant de relancer une installation.')
PY
