#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
: "${GHIDRA_HOME:?Set GHIDRA_HOME to Ghidra 11.3.2 installation}"
: "${JAVA_HOME:?Set JAVA_HOME to a full JDK 21, not just a JRE}"
mkdir -p "$ROOT/work/ghidra-project" "$ROOT/work/ghidra-home"
export JAVA_TOOL_OPTIONS="${JAVA_TOOL_OPTIONS:-} -Duser.home=$ROOT/work/ghidra-home"
# Audit/extract first. Outputs are isolated beneath work/.
python3 "$ROOT/scripts/analyze_binary.py" "$ROOT/reference/Sophistry.component.zip" --output "$ROOT/work/audit"
"$GHIDRA_HOME/support/analyzeHeadless" "$ROOT/work/ghidra-project" Sophistry \
 -import "$ROOT/work/audit/original/Sophistry.i386" \
 -scriptPath "$ROOT/scripts/ghidra" \
 -preScript ApplyHints.java "$ROOT/work/audit/analysis/function-hints.tsv" \
 -postScript ExportSophistry.java "$ROOT/work/ghidra-export" \
 -analysisTimeoutPerFile 600 -max-cpu 4
