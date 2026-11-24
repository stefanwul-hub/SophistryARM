#!/bin/bash
# CronoX3 CRX001. Source épinglée et contrôlée ; aucun plugin installé n’est remplacé.
set -euo pipefail
if [[ "$(uname -s)" != Darwin || "$(uname -m)" != arm64 ]]; then
  echo 'Lancez ce fichier depuis un Terminal natif Apple Silicon.' >&2
  exit 2
fi
CRONOX_BASE_DIR="$HOME/CronoX3-ARM64"
CRONOX_SOURCE_COMMIT="e8eca92d1b51bc4e5d754d2880880bd8593cbf9d"
CRONOX_ARCHIVE_SHA256="23606fa8ab160e0ad48046e13700a1b04fca445af0096a9e0d2a160a7b9f9630"
mkdir -p "$CRONOX_BASE_DIR/cache"
CRONOX_ARCHIVE="$CRONOX_BASE_DIR/cache/CRX001-source.zip"
valid_archive(){
  [[ -f "$CRONOX_ARCHIVE" && "$(/usr/bin/shasum -a 256 "$CRONOX_ARCHIVE" | /usr/bin/awk '{print $1}')" == "$CRONOX_ARCHIVE_SHA256" ]]
}
if ! valid_archive; then
  echo 'Téléchargement du checkpoint CronoX CRX001…'
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
[[ -f "$CRONOX_SOURCE/Compiler-et-tester-CronoX.command" ]] || { echo 'Dossier CronoX3 absent de l’archive.' >&2;exit 1; }
mkdir -p "$CRONOX_BASE_DIR/projet"
/usr/bin/ditto "$CRONOX_SOURCE" "$CRONOX_BASE_DIR/projet"
echo 'Profil de comparaison réservé : CronoX 3 ARM Test, identifiant aumu/CrT3/LinP.'
echo 'CRX001 teste le moteur C++ et ne contient pas encore d’AU installable.'
/bin/bash "$CRONOX_BASE_DIR/projet/Compiler-et-tester-CronoX.command"
