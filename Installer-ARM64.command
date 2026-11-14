#!/bin/bash
# This checkpoint is deliberately not installable. Do not replace a working AU
# with a stub carrying the same AudioComponent identity: it could damage recall.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")" && pwd)"
echo 'Checkpoint CP-004 : portage complet du moteur DSP et du lecteur vstdata absent.' >&2
echo 'Aucun Sophistry.component ARM64 installable ne peut être construit depuis ce checkpoint.' >&2
echo 'L’installation et le remplacement du composant existant sont donc désactivés.' >&2
echo "Utilisez : $ROOT/Verifier-Mac.command pour compiler les tests et collecter les diagnostics." >&2
exit 78
