#!/bin/bash
# Collect existing Sophistry test reports. No download, compilation or installation.
set -euo pipefail
if [[ "$#" -gt 2 ]]; then
  printf '%s\n' 'Usage : bash Recuperer-Rapports-Mac.command [dossier_de_rapports|diagnostic.log] [archive.zip]' >&2
  exit 2
fi
SOPHISTRY_BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
SOPHISTRY_REPORT_DIR="${1:-}"
if [[ -z "$SOPHISTRY_REPORT_DIR" ]]; then
  SOPHISTRY_LATEST_LOG=''
  for SOPHISTRY_SEARCH_DIR in "$SOPHISTRY_BASE_DIR" "$HOME/Downloads"; do
    [[ -d "$SOPHISTRY_SEARCH_DIR" ]] || continue
    while IFS= read -r -d '' SOPHISTRY_CANDIDATE; do
      /usr/bin/grep -Fq 'Checkpoint incomplet : ce script compile des outils de test, pas le synthétiseur complet.' "$SOPHISTRY_CANDIDATE" || continue
      if [[ -z "$SOPHISTRY_LATEST_LOG" || "$SOPHISTRY_CANDIDATE" -nt "$SOPHISTRY_LATEST_LOG" ]]; then
        SOPHISTRY_LATEST_LOG="$SOPHISTRY_CANDIDATE"
      fi
    done < <(/usr/bin/find "$SOPHISTRY_SEARCH_DIR" -type f -path '*/work/mac-*/diagnostic.log' -print0 2>/dev/null)
    [[ "$SOPHISTRY_BASE_DIR" == "$HOME/Downloads" ]] && break
  done
  if [[ -z "$SOPHISTRY_LATEST_LOG" ]]; then
    printf '%s\n' 'Aucun rapport trouvé. Relancez ce script avec le chemin du diagnostic.log déjà obtenu en premier argument.' >&2
    exit 1
  fi
  SOPHISTRY_REPORT_DIR="$(dirname "$SOPHISTRY_LATEST_LOG")"
elif [[ -f "$SOPHISTRY_REPORT_DIR" ]]; then
  SOPHISTRY_REPORT_DIR="$(dirname "$SOPHISTRY_REPORT_DIR")"
fi
if [[ ! -f "$SOPHISTRY_REPORT_DIR/diagnostic.log" ]]; then
  printf '%s\n' "diagnostic.log absent du dossier : $SOPHISTRY_REPORT_DIR" >&2
  exit 1
fi
SOPHISTRY_REPORT_DIR="$(cd "$SOPHISTRY_REPORT_DIR" && pwd)"
SOPHISTRY_FILES=()
for SOPHISTRY_NAME in diagnostic.log kernel-test.json legacy-state-test.jsonl \
  static-lift-replay.json static-lift-native-libm.json \
  static-lift-native-libm-errors.log static-lift-native-libm.exitcode \
  auval-existing.log auval-existing.exitcode; do
  if [[ -f "$SOPHISTRY_REPORT_DIR/$SOPHISTRY_NAME" ]]; then
    SOPHISTRY_FILES+=("$SOPHISTRY_REPORT_DIR/$SOPHISTRY_NAME")
  fi
done
SOPHISTRY_ARCHIVE="${2:-$SOPHISTRY_BASE_DIR/Sophistry-rapports-$(date -u +%Y%m%dT%H%M%SZ).zip}"
SOPHISTRY_ARCHIVE="$(cd "$(dirname "$SOPHISTRY_ARCHIVE")" && pwd)/$(basename "$SOPHISTRY_ARCHIVE")"
if [[ -e "$SOPHISTRY_ARCHIVE" || -L "$SOPHISTRY_ARCHIVE" ]]; then
  printf '%s\n' "Cette archive existe déjà : $SOPHISTRY_ARCHIVE" >&2
  exit 1
fi
/usr/bin/zip -q -j "$SOPHISTRY_ARCHIVE" "${SOPHISTRY_FILES[@]}"
printf '%s\n' "Rapports collectés : $SOPHISTRY_REPORT_DIR" \
  "Archive à transmettre : $SOPHISTRY_ARCHIVE" \
  'Aucune compilation ni installation effectuée.'
if [[ "$(uname -s)" == Darwin ]]; then
  /usr/bin/open -R "$SOPHISTRY_ARCHIVE" || true
fi
