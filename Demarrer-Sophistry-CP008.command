#!/bin/bash
set -euo pipefail
if [[ "$(uname -s)" != Darwin ]]; then
  echo 'Ce lanceur exige macOS et les outils Xcode.' >&2
  exit 2
fi
SOPHISTRY_BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
if [[ -f "$SOPHISTRY_BASE_DIR/Verifier-Mac.command" && -f "$SOPHISTRY_BASE_DIR/port-status.json" ]] && /usr/bin/grep -Fq '"checkpoint": "CP-008"' "$SOPHISTRY_BASE_DIR/port-status.json" && /usr/bin/grep -Eq '"mac_verifier_revision"[[:space:]]*:[[:space:]]*1[[:space:]]*[,}]' "$SOPHISTRY_BASE_DIR/port-status.json"; then
  exec /bin/bash "$SOPHISTRY_BASE_DIR/Verifier-Mac.command" "$@"
fi
SOPHISTRY_WORK_DIR="$(mktemp -d "$SOPHISTRY_BASE_DIR/Sophistry-CP008-correctif1.XXXXXX")"
trap 'printf "%s\n" "Fichiers et rapports conservés dans : $SOPHISTRY_WORK_DIR"' EXIT
SOPHISTRY_ARCHIVE="$SOPHISTRY_WORK_DIR/Sophistry-CP008-sources.zip"
printf '%s\n' 'Téléchargement du checkpoint CP-008, correctif Mac 1. Le plugin Audio Unit complet reste à développer.'
/usr/bin/curl --fail --location --retry 2 --connect-timeout 15 --max-time 600 \
  'https://codeload.github.com/stefanwul-hub/SophistryARM/zip/1f85c63cff513d0ccf9e93d12711eed910fbc056' -o "$SOPHISTRY_ARCHIVE"
SOPHISTRY_DOWNLOADED_SHA=$(/usr/bin/shasum -a 256 "$SOPHISTRY_ARCHIVE" | /usr/bin/awk '{print $1}')
if [[ "$SOPHISTRY_DOWNLOADED_SHA" != '1ec9e3a784d30506367c92f9a01d0255db7a59f6eed5d7988cd905c00033ae6c' ]]; then
  echo 'L’empreinte de l’archive diffère de celle vérifiée. Arrêt.' >&2
  exit 1
fi
/usr/bin/ditto -x -k "$SOPHISTRY_ARCHIVE" "$SOPHISTRY_WORK_DIR"
SOPHISTRY_SOURCE_DIR="$SOPHISTRY_WORK_DIR/SophistryARM-1f85c63cff513d0ccf9e93d12711eed910fbc056"
/bin/bash "$SOPHISTRY_SOURCE_DIR/Verifier-Mac.command" "$@"
