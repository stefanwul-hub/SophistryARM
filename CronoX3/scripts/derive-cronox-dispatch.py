#!/usr/bin/env python3
"""Add two opt-in entry hooks without editing the pinned generated sources."""
from pathlib import Path
import sys


def derive(source, destination):
    text = source.read_text()
    anchor = ' unsigned unit=c.pc<sizeof(sl_pc_units)/sizeof(sl_pc_units[0])?sl_pc_units[c.pc]:0;'
    if text.count(anchor) != 1 or 'sl_cronox_preferred_hook' in text:
        raise ValueError('Unexpected original CronoX dispatcher; refusing transformation')
    result = '#include "CronoXHookPriority.h"\n' + text.replace(
        anchor, ' if(sl_cronox_preferred_hook(c))continue;\n' + anchor)
    destination.parent.mkdir(parents=True, exist_ok=True)
    if not destination.exists() or destination.read_text() != result:
        destination.write_text(result)


if __name__ == '__main__':
    derive(Path(sys.argv[1]), Path(sys.argv[2]))
