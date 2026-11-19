#!/bin/bash
# CP038: profile the installed CP037 or CP038; no DSP build or installation.
set +x
set -euo pipefail
umask 077
ROOT="$(cd "$(dirname "$0")" && pwd)"
if [[ "$(uname -s)" != Darwin || "$(uname -m)" != arm64 || "$EUID" -eq 0 ]]; then
  echo 'Lancez ce script dans un Terminal natif Apple Silicon, sans sudo.' >&2
  exit 2
fi
for app in 'Logic Pro' 'Logic' 'Live' 'Ableton Live'; do
  if /usr/bin/pgrep -u "$(id -u)" -x "$app" >/dev/null 2>&1; then
    echo 'Fermez Logic et Live pendant la mesure CPU, puis relancez ce script.' >&2
    exit 1
  fi
done
PYTHON="$(/usr/bin/xcrun --find python3)"
REPORT="$ROOT/work/cpu-profile-$(date -u +%Y%m%dT%H%M%SZ)-$$"
COMPONENT='/Library/Audio/Plug-Ins/Components/Sophistry.component'
mkdir -p "$REPORT"
exec > >(/usr/bin/tee "$REPORT/diagnostic.log") 2>&1
collect(){
  result=$?
  trap - EXIT INT TERM
  printf '%s\n' "$result" > "$REPORT/script-exitcode.txt"
  archive="$ROOT/Sophistry-rapports-CP038-$(basename "$REPORT").zip"
  (cd "$REPORT"; /usr/bin/zip -q "$archive" ./*.json ./*.txt ./*.log 2>/dev/null || true)
  printf '\n%s\n' "Rapport : $archive"
  echo 'Le composant et les préférences Sophistry n’ont pas été remplacés par ce script.'
  /usr/bin/open -R "$archive" >/dev/null 2>&1 || true
  exit "$result"
}
trap collect EXIT
trap 'exit 130' INT
trap 'exit 143' TERM
echo 'Sophistry CP038 — profilage CPU du composant installé'
"$PYTHON" - "$COMPONENT" "$REPORT" <<'PY'
import hashlib,json,plistlib,sys
from pathlib import Path
bundle,report=map(Path,sys.argv[1:])
info=plistlib.loads((bundle/'Contents/Info.plist').read_bytes())
build=str(info.get('CFBundleVersion'))
if info.get('CFBundleIdentifier')!='com.linplug.au.Sophistry' or build not in ['37001','38001']:
    raise SystemExit('Ce diagnostic attend le composant CP037 ou CP038 installé.')
binary=bundle/'Contents/MacOS/Sophistry'
(report/'component.json').write_text(json.dumps({'checkpoint':'CP-037' if build=='37001' else 'CP-038','build':build,'binary_sha256':hashlib.sha256(binary.read_bytes()).hexdigest(),'replacement_requested':False},indent=2)+'\n')
PY
VERSION="$("$PYTHON" -c 'import json,sys;print("SophistryARM "+json.load(open(sys.argv[1]))["checkpoint"])' "$REPORT/component.json")"
/usr/bin/lipo "$COMPONENT/Contents/MacOS/Sophistry" -verify_arch arm64
/usr/bin/sw_vers > "$REPORT/macos.txt"
/usr/bin/xcrun clang++ --version > "$REPORT/compiler.txt"
echo 'Compilation du petit hôte de mesure ARM64 ; le noyau DSP déjà installé est utilisé.'
/usr/bin/xcrun clang++ -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 \
  "$ROOT/tests/AudioUnitFactoryProbe.cpp" -framework AudioToolbox -framework CoreFoundation \
  -o "$REPORT/AudioUnitProfileProbe" > "$REPORT/profile-probe.compile.log" 2>&1
/usr/bin/lipo "$REPORT/AudioUnitProfileProbe" -verify_arch arm64
/usr/bin/nm -nm "$COMPONENT/Contents/MacOS/Sophistry" > "$REPORT/symbols.txt" 2> "$REPORT/symbols.log" || true
"$PYTHON" "$ROOT/scripts/profile_au_cpu.py" --probe "$REPORT/AudioUnitProfileProbe" \
  --bundle "$COMPONENT" --state "$COMPONENT/Contents/Resources/Presets/Lightgarden 02 BT.aupreset" \
  --contract "$ROOT/tests/fixtures/original-au-parameters.plist" --output "$REPORT" --expected-version "$VERSION"
echo 'Captures terminées : une note, puis un accord de quatre notes, sans éditeur graphique.'
echo 'Les piles complètes restent dans ce rapport local ; aucune publication automatique.'
