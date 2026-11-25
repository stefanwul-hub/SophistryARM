#!/bin/bash
# CronoX3 CRX006. Source épinglée et contrôlée ; seul CronoX 3 ARM Test peut être remplacé.
set -euo pipefail
if [[ "$(uname -s)" != Darwin || "$(uname -m)" != arm64 ]]; then
  echo 'Lancez ce fichier depuis un Terminal natif Apple Silicon.' >&2
  exit 2
fi
CRONOX_BASE_DIR="$HOME/CronoX3-ARM64"
CRONOX_SOURCE_COMMIT="2af4f3a456eb21a5ea7073464385c6a0e356699d"
CRONOX_ARCHIVE_SHA256="d6b7da9efa7ff01c4458ccff07c7d47b6e5e6aff5bb740759a345f8427e0d1c8"
mkdir -p "$CRONOX_BASE_DIR/cache"
CRONOX_ARCHIVE="$CRONOX_BASE_DIR/cache/CRX006-source.zip"
valid_archive(){
  [[ -f "$CRONOX_ARCHIVE" && "$(/usr/bin/shasum -a 256 "$CRONOX_ARCHIVE" | /usr/bin/awk '{print $1}')" == "$CRONOX_ARCHIVE_SHA256" ]]
}
if ! valid_archive; then
  echo 'Téléchargement du checkpoint CronoX CRX006…'
  /usr/bin/curl --fail --location --retry 2 --proto '=https' --tlsv1.2 \
    "https://codeload.github.com/stefanwul-hub/SophistryARM/zip/$CRONOX_SOURCE_COMMIT" \
    --output "$CRONOX_ARCHIVE.pending"
  actual="$(/usr/bin/shasum -a 256 "$CRONOX_ARCHIVE.pending" | /usr/bin/awk '{print $1}')"
  [[ "$actual" == "$CRONOX_ARCHIVE_SHA256" ]] || { echo 'Empreinte de l’archive incorrecte.' >&2;exit 1; }
  /bin/mv "$CRONOX_ARCHIVE.pending" "$CRONOX_ARCHIVE"
fi
CRONOX_STAGE="$(/usr/bin/mktemp -d "$CRONOX_BASE_DIR/preparation.XXXXXX")"
cleanup(){ /bin/rm -rf "$CRONOX_STAGE"; }
trap cleanup EXIT
/usr/bin/unzip -q "$CRONOX_ARCHIVE" "SophistryARM-$CRONOX_SOURCE_COMMIT/CronoX3/*" -d "$CRONOX_STAGE"
CRONOX_SOURCE="$CRONOX_STAGE/SophistryARM-$CRONOX_SOURCE_COMMIT/CronoX3"
[[ -f "$CRONOX_SOURCE/Installer-CronoX-CRX006.command" ]] || { echo 'Dossier CronoX3 absent de l’archive.' >&2;exit 1; }
mkdir -p "$CRONOX_BASE_DIR/projet"
/usr/bin/ditto "$CRONOX_SOURCE" "$CRONOX_BASE_DIR/projet"
echo 'Profil de comparaison réservé : CronoX 3 ARM Test, identifiant aumu/CrT3/LinP.'
echo 'Compilation et installation du composant ARM Test. CronoX original et Sophistry restent en place.'
/bin/bash "$CRONOX_BASE_DIR/projet/Installer-CronoX-CRX006.command"
