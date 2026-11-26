#!/usr/bin/env python3
"""Inventory original ETProgram/ETKeyMapping member registrations from Ghidra.

This reads the pinned analysis outputs, not user presets or live memory.
Offsets describe the original i386 objects, not native ARM64 object layouts.
It is a schema inventory, not an archive decoder or a restored sound state.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
from legacy_image import SHA


def recover(directory):
    classes = []
    for name, address in [('ETProgram', '0015ecac'), ('ETKeyMapping', '001489c0')]:
        source = (directory / (address + '.c')).read_text()
        pattern = re.compile(r'uStack_28 = (0x[0-9a-f]+|[0-9]+);\s+uStack_24 = (0x[0-9a-f]+|[0-9]+);\s+(?:iRam[0-9a-f]+ = [^;]+;\s+)?uStack_20 = FUN_00033b90\("([^"\n]+)"\);')
        matches = list(pattern.finditer(source))
        if not matches:
            raise ValueError('Original registration pattern not found: ' + name)
        fields = []
        for i, match in enumerate(matches):
            block = source[match.end():matches[i + 1].start() if i + 1 < len(matches) else len(source)]
            scalar = re.search(r'FUN_001000ae\((0x[0-9a-f]+|[0-9]+)\)', block)
            declared = re.findall(r'FUN_00033b90\("([^"\n]+)"\)', block)
            row = {'name': match[3], 'original_i386_offset': hex(int(match[1], 0)), 'original_member_bytes': int(match[2], 0)}
            if scalar:
                tag = chr(int(scalar[1], 0))
                row.update({'registration_type_tag': tag, 'type': {'f': 'float32', 'd': 'float64', 'i': 'int32', 'l': 'int64', 'b': 'boolean'}[tag]})
            else:
                row['type'] = 'relationship' if 'FUN_000204a2(' in block else 'object property'
                row['declared_class'] = next((value for value in declared if value != row['name']), None)
            fields.append(row)
        if len({f['name'] for f in fields}) != len(fields):
            raise ValueError('Duplicate original property name')
        classes.append({'class': name, 'class_registration_function': '0x' + address,
                        'decompiled_input_sha256': hashlib.sha256(source.encode()).hexdigest(), 'fields': fields})
    return {'checkpoint': 'ELA003', 'original_i386_sha256': SHA,
            'basis': 'Original class registration decompilation; not a saved user state',
            'classes': classes, 'total_registered_fields': sum(len(c['fields']) for c in classes),
            'actual_user_state_received': False, 'object_bodies_decoded': False,
            'old_project_restored': False}


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('decompiled_directory', type=Path); p.add_argument('--output', type=Path, required=True)
    a = p.parse_args(); result = recover(a.decompiled_directory)
    a.output.parent.mkdir(parents=True, exist_ok=True); a.output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({'total_fields': result['total_registered_fields'], 'classes': [{'class': c['class'], 'fields': len(c['fields'])} for c in result['classes']]}, indent=2))
