#!/bin/bash
# CRX001: validation du moteur traduit; le composant installé est conservé.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")" && pwd)"
if [[ "$(uname -s)" != Darwin || "$(uname -m)" != arm64 ]]; then
  echo 'Ce test demande un Terminal natif Apple Silicon avec Xcode.' >&2
  exit 2
fi
/usr/bin/xcrun --find clang++ >/dev/null
STAMP="$(date -u +%Y%m%dT%H%M%SZ)"
REPORT="$HOME/Desktop/CronoX3-rapports-CRX001-$STAMP"
mkdir -p "$REPORT"
finish(){
  result=$?
  trap - EXIT
  printf '%s\n' "$result" > "$REPORT/exit-code.txt"
  if [[ "$result" -eq 0 ]]; then
    echo 'Tests du moteur terminés. Le plugin AU et son interface restent à finaliser.'
  else
    echo 'Un test a échoué. Le rapport contient les détails et les journaux de compilation.' >&2
  fi
  for directory in "$ROOT/work/cronox-core" "$ROOT/work/cronox-engine"; do
    if [[ -d "$directory" ]]; then
      target="$REPORT/$(basename "$directory")-compilation"
      mkdir -p "$target"
      for compilelog in "$directory"/*.compile.log; do
        if [[ -f "$compilelog" ]]; then /bin/cp "$compilelog" "$target/" || true;fi
      done
    fi
  done
  /usr/bin/ditto -c -k --sequesterRsrc --keepParent "$REPORT" "$REPORT.zip" || true
  /usr/bin/open -R "$REPORT.zip" || true
  echo "Rapport : $REPORT.zip"
  exit "$result"
}
trap finish EXIT
{
  /usr/bin/sw_vers
  /usr/bin/uname -m
  /usr/bin/xcrun clang++ --version
} > "$REPORT/configuration.txt" 2>&1
exec > >(/usr/bin/tee "$REPORT/diagnostic.log") 2>&1
echo 'CronoX 3 ARM64 — CRX001 : compilation et tests du moteur original traduit.'
echo 'Première compilation : 415 fichiers C++ ; le cache work est conservé pour les reprises.'
echo 'Aucun composant Audio Unit ni préférence de licence ne sera remplacé par ce test.'
if [[ ! -x /usr/bin/python3 ]]; then echo 'Python 3 de Xcode est requis.' >&2;exit 2;fi
/usr/bin/python3 "$ROOT/scripts/prepare-cronox-source.py"
bash "$ROOT/scripts/build-cronox-engine.sh" "$ROOT/work/cronox-engine" "$ROOT/work/cronox-core"
for executable in "$ROOT/work/cronox-core/InstructionProbe" "$ROOT/work/cronox-engine/CronoXBootProbe" "$ROOT/work/cronox-engine/CronoXAUBridgeProbe" "$ROOT/work/cronox-engine/GuestStdStringProbe"; do
  /usr/bin/lipo "$executable" -verify_arch arm64
  /usr/bin/file "$executable" >> "$REPORT/architectures.txt"
done
"$ROOT/work/cronox-core/InstructionProbe" "$ROOT/reference/CronoX3.i386" "$ROOT/evidence/cronox-sqrt-instructions.fixtures" | /usr/bin/tee "$REPORT/instruction-replay.json"
"$ROOT/work/cronox-engine/GuestStdStringProbe" | /usr/bin/tee "$REPORT/string-abi.json"
"$ROOT/work/cronox-engine/CronoXBootProbe" | /usr/bin/tee "$REPORT/engine-boot.json"
"$ROOT/work/cronox-engine/CronoXAUBridgeProbe" | /usr/bin/tee "$REPORT/original-au-bridge.json"
"$ROOT/work/cronox-engine/CronoXAUBridgeProbe" "$ROOT/reference/Presets/lightgarden 02 BT.FXP" "$ROOT/reference/Samples" | /usr/bin/tee "$REPORT/public-preset.json"
echo 'L’architecture ARM64, les paramètres et la restauration ont été testés dans le banc C++.'
echo 'La validation auval sera exécutée lorsque le composant AU CronoX sera disponible.'
