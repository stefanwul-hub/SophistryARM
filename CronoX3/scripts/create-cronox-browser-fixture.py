#!/usr/bin/env python3
"""Create disposable catalog entries for a display test, never playable sounds."""
from pathlib import Path
import sys
root=Path(sys.argv[1]);root.mkdir(parents=True,exist_ok=True)
for name in ['Bank A','Bank B','Empty','.hidden','z patterns arp']:
    (root/name).mkdir(exist_ok=True)
for name in ['01 first.FXP','10 tenth.fxp','2 second.aupreset','ignore.wav']:
    (root/'Bank A'/name).write_bytes(b'Catalog fixture only; not an audio preset.\n')
(root/'Bank B'/'Other.FXP').write_bytes(b'Catalog fixture only.\n')
link=root/'Bank Link'
if not link.exists():link.symlink_to('Bank A',target_is_directory=True)
