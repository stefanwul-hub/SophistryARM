#!/bin/bash
# Reposition only windows whose title contains Sophistry; no project edits.
set -euo pipefail
if [[ "$(uname -s)" != Darwin || "$EUID" -eq 0 ]]; then
  echo 'Lancez ce fichier sur votre Mac, sans sudo.' >&2
  exit 2
fi
echo 'Recentrage des fenêtres Sophistry de Logic ou Live. Aucun projet ne sera modifié.'
if ! /usr/bin/osascript -l JavaScript <<'JXA'
ObjC.import('AppKit');
const screen = $.NSScreen.screens.objectAtIndex(0);
const visible = screen.visibleFrame;
const width = Math.min(1180, visible.size.width - 40);
const height = Math.min(700, visible.size.height - 40);
const x = visible.origin.x + 20;
const y = screen.frame.size.height - visible.origin.y - visible.size.height + 20;
const events = Application('System Events');
let moved = 0;
for (const name of ['Logic Pro', 'Logic', 'Live', 'Ableton Live']) {
  const process = events.applicationProcesses.byName(name);
  if (!process.exists()) continue;
  for (const window of process.windows()) {
    if (!String(window.name()).toLowerCase().includes('sophistry')) continue;
    // Moving the top into view is sufficient even if the host refuses a
    // smaller size for its long generic parameter list.
    window.position = [x, y];
    try { window.size = [width, height]; } catch (ignored) {}
    process.frontmost = true;
    ++moved;
  }
}
if (!moved) throw new Error('Ouvrez d’abord la fenêtre Sophistry dans Logic ou Live.');
'Fenêtres Sophistry recentrées : ' + moved;
JXA
then
  echo 'Si macOS refuse l’accès : Réglages Système > Confidentialité et sécurité > Accessibilité, autorisez Terminal, puis relancez ce fichier.' >&2
  exit 1
fi
