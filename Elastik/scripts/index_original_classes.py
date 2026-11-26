#!/usr/bin/env python3
"""Recover selected original GNU C++ RTTI/vtables as data, without running code."""
import argparse
import json
import re
import struct
from pathlib import Path
from legacy_image import LegacyImage, SHA

CLASSES = {
    'ETInstrument', 'ETProgram', 'ETInstrumentVoice', 'ETKeyMapping',
    'ETSoundbank', 'ETPitchShifter', 'ETPitchShifterJob',
    'ETRenderCacheCtrl', 'ETRenderCacheItem', 'GNAudioResampler',
    'GNKeyValueArchiver', 'GNKeyValueUnarchiver',
}


def inspect(binary, ranges):
    image = LegacyImage(binary.read_bytes())
    data = image.mapped()
    word = lambda at: struct.unpack_from('<I', data, at)[0]
    code = [(s['address'], s['address'] + s['size']) for s in image.sections
            if s['flags'] & 0x80000400]
    executable = lambda address: any(a <= address < b for a, b in code)
    external = {r['address']: r['name'] for r in image.relocations}
    fde = {int(row.split(',')[0], 16) for row in ranges.read_text().splitlines()[1:]}
    rtti = {}
    for r in image.relocations:
        if 'class_type_info' not in r['name']:
            continue
        at = r['address']
        name_at = word(at + 4)
        if not 0 <= name_at < len(data):
            raise ValueError('RTTI name outside pinned image')
        raw = bytes(data[name_at:name_at + 256]).split(b'\0', 1)[0].decode('ascii')
        match = re.fullmatch(r'(\d+)([A-Za-z_][A-Za-z_0-9]*)', raw)
        name = match[2] if match and int(match[1]) == len(match[2]) else raw
        rtti[at] = {'name': name, 'abi_name': raw, 'typeinfo_address': hex(at),
                    'vtables': []}
    selected = {at: row for at, row in rtti.items() if row['name'] in CLASSES}
    for section in image.sections:
        if section['segment'] != '__DATA':
            continue
        for at in range(section['address'], section['address'] + section['size'] - 4, 4):
            pointer = word(at)
            if pointer not in selected or at < 4 or not executable(word(at + 4)):
                continue
            displacement = struct.unpack_from('<i', data, at - 4)[0]
            if displacement > 0 or displacement < -65536:
                continue
            entries = []
            for offset in range(0, 2048, 4):
                slot = at + 4 + offset
                value = word(slot)
                if slot in external:
                    entries.append({'offset': hex(offset), 'import': external[slot]})
                elif executable(value):
                    entries.append({'offset': hex(offset), 'address': hex(value),
                                    'has_unwind_boundary': value in fde})
                else:
                    break
            selected[pointer]['vtables'].append({'address': hex(at + 4),
                'offset_to_top': displacement, 'entries': entries})
    return {'checkpoint': 'ELA002', 'original_i386_sha256': SHA,
            'method': 'Original GNU C++ RTTI relocations and executable vtable entries',
            'all_rtti_records': len(rtti), 'classes': sorted(selected.values(), key=lambda x: x['name']),
            'machine_code_executed': False, 'all_dsp_functions_identified': False}


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('binary', type=Path)
    p.add_argument('ranges', type=Path)
    p.add_argument('--output', required=True, type=Path)
    a = p.parse_args()
    a.output.parent.mkdir(parents=True, exist_ok=True)
    result = inspect(a.binary, a.ranges)
    a.output.write_text(json.dumps(result, separators=(',', ':')) + '\n')
    print(json.dumps({'rtti_records': result['all_rtti_records'],
                      'selected_classes': [{k: c[k] for k in ['name', 'typeinfo_address']} |
                                           {'vtables': [v['address'] for v in c['vtables']]}
                                           for c in result['classes']]}, indent=2))
