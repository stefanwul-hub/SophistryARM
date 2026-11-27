#!/usr/bin/env python3
"""Inventory ETSoundbank's original field registrations, without user data."""
import argparse,hashlib,json,re
from pathlib import Path
from legacy_image import SHA

def recover(directory):
    source=(directory/'001a9596.c').read_text()
    pattern=re.compile(r'uStack_28 = (0x[0-9a-f]+|[0-9]+);\s+uStack_24 = (0x[0-9a-f]+|[0-9]+);\s+(?:iRam[0-9a-f]+ = [^;]+;\s+)?uStack_20 = FUN_00033b90\("([^"\n]+)"\);')
    matches=list(pattern.finditer(source));rows=[]
    for i,m in enumerate(matches):
        block=source[m.end():matches[i+1].start() if i+1<len(matches) else len(source)]
        names=re.findall(r'FUN_00033b90\("([^"\n]+)"\)',block)
        row={'name':m[3],'original_i386_offset':hex(int(m[1],0)),'original_member_bytes':int(m[2],0)}
        if 'FUN_001000ae(0x40)' in block:row.update(type='object value',registration_type_tag='@')
        else:row.update(type='relationship' if 'FUN_000204a2(' in block else 'object property',declared_class=next((n for n in names if n!=m[3]),None))
        rows.append(row)
    assert [r['name'] for r in rows]==['_identifier','_sourceFilePosixPath','_rootFilePath','_serialNumber','_responseCode']
    assert [int(r['original_i386_offset'],16) for r in rows]==[0x10,0x1c,0x20,0x14,0x18]
    return dict(checkpoint='ELA013',original_i386_sha256=SHA,class_name='ETSoundbank',class_registration_function='0x1a9596',decompiled_input_sha256=hashlib.sha256(source.encode()).hexdigest(),fields=rows,total_registered_fields=len(rows),actual_user_state_received=False,object_bodies_decoded=False,private_serial_or_response_data_received=False,old_project_restored=False)
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('decompiled_directory',type=Path);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=recover(a.decompiled_directory);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({'class':r['class_name'],'registered_fields':r['total_registered_fields']}))
