#!/bin/bash
# This checkpoint is deliberately not installable. Do not replace a working AU
# with a stub carrying the same AudioComponent identity: it could damage recall.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")" && pwd)"
echo 'CP-013 construit un premier candidat Sophistry.component ARM64, encore sans validation AU sur Mac.' >&2
echo 'Le rappel Logic/Live et l’interface Sophistry ne sont pas validés ; le remplacement système reste bloqué.' >&2
echo "Utilisez : bash \"$ROOT/Verifier-AU-Mac.command\" pour compiler et tester le candidat sans installation." >&2
exit 78
