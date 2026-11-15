#!/bin/bash
# Copied beside the private backup and independent of the source checkout.
set +x
set -euo pipefail
restore_settings=0
if [[ "${1:-}" == --restore-settings && "$#" -eq 1 ]]; then
  restore_settings=1
elif [[ "$#" -ne 0 ]]; then
  echo 'Usage : Restaurer-Sophistry.command [--restore-settings]' >&2
  exit 2
fi
if [[ "$(uname -s)" != Darwin || "$EUID" -eq 0 ]]; then
  echo 'Lancez ce fichier sur votre Mac, sans sudo ; les droits administrateur seront demandés pour le composant.' >&2
  exit 2
fi
SELF="$(cd "$(dirname "$0")" && pwd)"
TRANSACTION="$(basename "$SELF")"
for app in 'Logic Pro' 'Logic' 'Live' 'Ableton Live'; do
  if /usr/bin/pgrep -u "$(id -u)" -x "$app" >/dev/null 2>&1; then
    echo 'Fermez Logic et Live avant de restaurer le composant.' >&2
    exit 2
  fi
done
PYTHON="$(/usr/bin/xcrun --find python3)"
printf '%s\n' 'Restauration de la version précédente de Sophistry…'
/usr/bin/sudo -- "$PYTHON" "$SELF/ComponentTransaction.py" rollback --transaction "$TRANSACTION"
if [[ ( "$restore_settings" -eq 1 || ! -f "$SELF/Settings-validated.txt" ) && -f "$SELF/Preferences-privees-avant-installation.plist" ]]; then
  "$SELF/bin/ConfigureSophistry" --restore-backup "$SELF/Preferences-privees-avant-installation.plist"
fi
/usr/bin/killall -u "$(id -u)" AudioComponentRegistrar >/dev/null 2>&1 || true
echo 'Restauration terminée. Les sauvegardes et le candidat écarté sont conservés.'
