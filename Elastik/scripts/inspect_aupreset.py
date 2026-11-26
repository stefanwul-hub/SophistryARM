#!/usr/bin/env python3
"""Read legacy AU preset identity and data sizes without exporting state/keys."""
import argparse
import hashlib
import json
from pathlib import Path
import plistlib

EXPECTED={'type':'aumu','subtype':'ELSK','manufacturer':'UBER'}


def fourcc(value):
    if isinstance(value,int) and not isinstance(value,bool):
        try:return (value&0xffffffff).to_bytes(4,'big').decode('ascii')
        except UnicodeDecodeError:return None
    return value if isinstance(value,str) and len(value)==4 else None


def inspect(path):
    raw=path.read_bytes()
    if len(raw)>32*1024*1024:raise ValueError('Preset exceeds analysis limit')
    obj=plistlib.loads(raw.lstrip())
    if not isinstance(obj,dict):raise ValueError('Expected an AU ClassInfo dictionary')
    identity={k:fourcc(obj.get(k))for k in EXPECTED};blobs=[]
    def walk(value,location):
        if isinstance(value,bytes):
            signature='GNFA'if value.startswith(b'GNFA')else 'binary plist'if value.startswith(b'bplist00')else 'XML'if value.lstrip().startswith(b'<?xml')else 'unidentified'
            blobs.append({'location':location,'bytes':len(value),'sha256':hashlib.sha256(value).hexdigest(),'recognized_container':signature})
        elif isinstance(value,dict):
            for key,item in value.items():walk(item,location+'/'+str(key))
        elif isinstance(value,list):
            for i,item in enumerate(value):walk(item,location+'/'+str(i))
    walk(obj,'ClassInfo')
    return {'file_sha256':hashlib.sha256(raw).hexdigest(),'identity':identity,'identity_matches_elastik_1':identity==EXPECTED,'version':obj.get('version')if isinstance(obj.get('version'),int)else None,'state_version_accepted_by_original_header':obj.get('version')==0,'has_state_data_value':isinstance(obj.get('data'),bytes),'state_blobs':blobs,'raw_state_exported':False,'preset_modified':False,'successful_project_restoration_proven':False}


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('aupreset',type=Path);p.add_argument('--output',type=Path);a=p.parse_args();text=json.dumps(inspect(a.aupreset),indent=2)+'\n'
    if a.output:a.output.write_text(text)
    else:print(text,end='')
