#!/bin/bash
set -euo pipefail
ROOT="$(cd "$(dirname "$0")" && pwd)"
/usr/bin/open "$ROOT/docs/Interface.html"
