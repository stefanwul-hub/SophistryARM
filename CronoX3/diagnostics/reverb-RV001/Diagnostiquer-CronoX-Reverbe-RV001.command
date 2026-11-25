#!/bin/bash
# Standalone measurement only. Neither component nor the installed sources are replaced.
set -uo pipefail
ROOT="$(cd "$(dirname "$0")" && pwd)"
[[ "$(uname -s)" == Darwin && "$(uname -m)" == arm64 ]] || { echo 'Lancez ce diagnostic depuis un Terminal natif Apple Silicon.' >&2;exit 2; }
if /usr/bin/pgrep -x Live >/dev/null || /usr/bin/pgrep -x 'Logic Pro' >/dev/null || /usr/bin/pgrep -x LogicPro >/dev/null; then
  echo 'Fermez Live et Logic pour que la comparaison CPU ne soit pas faussée, puis relancez ce fichier.' >&2
  exit 2
fi
STAMP="$(/bin/date -u +%Y%m%dT%H%M%SZ)"
BASE="$HOME/CronoX3-ARM64/diagnostics/RV001"
REPORT="$HOME/Desktop/CronoX3-reverbe-RV001-$STAMP"
mkdir -p "$BASE" "$REPORT" || exit 1
PRIVATE="$(/usr/bin/mktemp -d "$BASE/prive.XXXXXX")" || exit 1
cleanup(){ /bin/rm -rf "$PRIVATE"; }
trap cleanup EXIT
finish(){
  /usr/bin/python3 "$ROOT/summarize.py" "$REPORT" > "$REPORT/resume.log" 2>&1 || true
  /usr/bin/ditto -c -k --sequesterRsrc --keepParent "$REPORT" "$REPORT.zip" || return 1
  echo "Rapport à transmettre : $REPORT.zip"
}
run(){
  /usr/bin/sw_vers > "$REPORT/macos.txt"
  /usr/sbin/sysctl -n machdep.cpu.brand_string > "$REPORT/processeur.txt" 2>&1 || true
  /usr/bin/shasum -a 256 "$ROOT/CronoXReverbProbe.mm" "$ROOT/summarize.py" > "$REPORT/outil.sha256"
  /usr/bin/xcrun --find clang++ > "$REPORT/xcode.txt" 2>&1 || return 1
  echo 'Choisissez Breath and Butter.FXP (Pads / Airy pads), ou un .aupreset CronoX correspondant.'
  PRESET="$(/usr/bin/osascript -e 'POSIX path of (choose file with prompt "Choisissez Breath and Butter (FXP), ou son état AU" of type {"fxp", "aupreset"})')" || return 1
  echo 'Compilation du petit hôte de mesure pour ARM64 et Intel. Le plugin ne sera pas recompilé.'
  for architecture in arm64 x86_64; do
    /usr/bin/xcrun clang++ -std=c++17 -arch "$architecture" -mmacosx-version-min=11.0 -O2 -g0 \
      -fobjc-arc -fblocks -fno-fast-math -ffp-contract=off -Wno-deprecated-declarations \
      "$ROOT/CronoXReverbProbe.mm" -framework Foundation -framework AudioToolbox -framework CoreFoundation \
      -o "$PRIVATE/sonde-$architecture" > "$REPORT/compilation-$architecture.log" 2>&1 || return 1
    /usr/bin/lipo "$PRIVATE/sonde-$architecture" -verify_arch "$architecture" || return 1
  done
  /usr/bin/arch -arm64 "$PRIVATE/sonde-arm64" --prepare "$PRESET" "$PRIVATE/commun.aupreset" "$REPORT/preparation.json" > "$REPORT/preparation.log" 2>&1 || return 1
  echo 'Quatre mesures du même accord, environ 32 secondes chacune. Aucun son ne sera envoyé aux haut-parleurs.'
  local failures=0
  echo '1/4 — Original Intel, réverbération active'
  /usr/bin/arch -x86_64 "$PRIVATE/sonde-x86_64" --measure original "$PRIVATE/commun.aupreset" "$REPORT/original-reverb.json" --paced > "$REPORT/original-reverb.log" 2>&1 || failures=$((failures+1))
  echo '2/4 — ARM64, réverbération active'
  /usr/bin/arch -arm64 "$PRIVATE/sonde-arm64" --measure arm "$PRIVATE/commun.aupreset" "$REPORT/arm-reverb.json" --paced > "$REPORT/arm-reverb.log" 2>&1 || failures=$((failures+1))
  echo '3/4 — ARM64, réverbération coupée'
  /usr/bin/arch -arm64 "$PRIVATE/sonde-arm64" --measure arm "$PRIVATE/commun.aupreset" "$REPORT/arm-bypass.json" --paced --bypass > "$REPORT/arm-bypass.log" 2>&1 || failures=$((failures+1))
  echo '4/4 — Original Intel, réverbération coupée'
  /usr/bin/arch -x86_64 "$PRIVATE/sonde-x86_64" --measure original "$PRIVATE/commun.aupreset" "$REPORT/original-bypass.json" --paced --bypass > "$REPORT/original-bypass.log" 2>&1 || failures=$((failures+1))
  echo 'Profil des routines ARM64 : une dernière séquence séparée des mesures CPU.'
  /usr/bin/arch -arm64 "$PRIVATE/sonde-arm64" --measure arm "$PRIVATE/commun.aupreset" "$REPORT/arm-profilage.json" --paced --ready "$PRIVATE/profil-pret" > "$REPORT/arm-profilage.log" 2>&1 &
  local probe_pid=$!
  local attempt
  for ((attempt=0;attempt<120;attempt++)); do
    [[ -f "$PRIVATE/profil-pret" ]] && break
    kill -0 "$probe_pid" 2>/dev/null || break
    /bin/sleep 0.25
  done
  if [[ -f "$PRIVATE/profil-pret" ]] && kill -0 "$probe_pid" 2>/dev/null; then
    /usr/bin/sample "$probe_pid" 20 1 -file "$REPORT/arm-piles-de-calcul.txt" > "$REPORT/profilage.log" 2>&1 || true
  fi
  wait "$probe_pid" || failures=$((failures+1))
  [[ "$failures" -eq 0 ]]
}
result=0
run || result=$?
printf 'Code de fin des mesures : %s\n' "$result" > "$REPORT/resultat.txt"
finish || exit 1
[[ "$result" -eq 0 ]] || echo 'Au moins une mesure a échoué ; le rapport contient ses journaux.'
exit "$result"
