#!/bin/bash
# Download a verified, immutable checkpoint and run its native Mac tests.
set +x
set -euo pipefail
if [[ "$(uname -s)" != Darwin ]]; then
  echo 'Ce lanceur est destiné à macOS sur Apple Silicon.' >&2
  exit 2
fi
if [[ "$(uname -m)" != arm64 ]]; then
  if [[ "$(/usr/sbin/sysctl -in hw.optional.arm64 2>/dev/null || true)" == 1 ]]; then
    exec /usr/bin/arch -arm64 /bin/bash "$0" "$@"
  fi
  echo 'Un Mac Apple Silicon est nécessaire.' >&2
  exit 2
fi
COMMIT='63fdae177535c81efb1cabd4413b9661e138798a'
SHA256='ab4e491f9bcff35324aa696eb225d4f1c92300f73a42dd9f36aa2328dce3fc52'
BASE="${SOPHISTRY_WORKSPACE:-$HOME/Documents/SophistryARM-CP033}"
mkdir -p "$BASE"
ARCHIVE="$BASE/Sophistry-CP033-sources.zip"
SOURCE="$BASE/SophistryARM-$COMMIT"
valid_archive(){
  [[ -f "$1" ]] && [[ "$(/usr/bin/shasum -a 256 "$1" | /usr/bin/awk '{print $1}')" == "$SHA256" ]]
}
if ! valid_archive "$ARCHIVE"; then
  printf '%s\n' 'Téléchargement du checkpoint CP-033 (~44 Mo)…'
  /usr/bin/curl --fail --location --retry 2 --connect-timeout 20 \
    "https://codeload.github.com/stefanwul-hub/SophistryARM/zip/$COMMIT" \
    --output "$ARCHIVE.part"
  if ! valid_archive "$ARCHIVE.part"; then
    echo 'L’empreinte de l’archive ne correspond pas au checkpoint vérifié.' >&2
    exit 1
  fi
  mv "$ARCHIVE.part" "$ARCHIVE"
fi
if [[ ! -f "$SOURCE/.sophistry-cp033-source" ]] || [[ "$(cat "$SOURCE/.sophistry-cp033-source")" != "$SHA256" ]]; then
  if [[ -e "$SOURCE" ]]; then
    SOURCE="$SOURCE-$(date -u +%Y%m%dT%H%M%SZ)"
  fi
  STAGING="$(mktemp -d "$BASE/extraction.XXXXXX")"
  /usr/bin/ditto -x -k "$ARCHIVE" "$STAGING"
  [[ -f "$STAGING/SophistryARM-$COMMIT/Installer-ARM64.command" ]]
  mv "$STAGING/SophistryARM-$COMMIT" "$SOURCE"
  rmdir "$STAGING"
  printf '%s\n' "$SHA256" > "$SOURCE/.sophistry-cp033-source"
fi
printf '%s\n' "Sources et checkpoints conservés dans : $SOURCE"
if [[ "${1:-}" == --diagnose-only ]]; then
  printf '%s\n' 'Inspection indépendante sans installation ; Logic et Live peuvent rester ouverts.'
elif [[ "${1:-}" == --recenter-windows ]]; then
  printf '%s\n' 'Laissez la fenêtre Sophistry ouverte dans Logic ou Live pour le recentrage.'
else
  printf '%s\n' 'La compilation ARM64 peut prendre plusieurs minutes au premier lancement.'
  printf '%s\n' 'La configuration de la licence reste locale. Fermez Logic et Live avant l’installation de test.'
fi
exec /bin/bash "$SOURCE/Installer-ARM64.command" "$@"
