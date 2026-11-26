#!/usr/bin/env python3
"""Inspect the original bundled GNFA example and copy its existing WAV bytes.

This is a file-container audit, not playback, time stretching, or activation.
Only the exact built-in example shipped in the provided installer is accepted.
"""
import argparse
import hashlib
import io
import json
from pathlib import Path
import struct
import wave

EXPECTED='9b4aca313f9ba24da8c4c2b2473f4023ca9a3efcd009d117644c3a46e2be0f84'


def extract(source,output,report):
    b=source.read_bytes()
    if hashlib.sha256(b).hexdigest()!=EXPECTED or b[:4]!=b'GNFA':raise ValueError('Expected the original bundled example archive')
    header_bytes=struct.unpack_from('>I',b,4)[0];count=struct.unpack_from('>I',b,16)[0];at=header_bytes;entries=[]
    for _ in range(count):
        fields=struct.unpack_from('>9I',b,at);size=fields[0]
        if size!=556:raise ValueError('Unexpected reference directory record')
        name=b[at+36:at+548].decode('utf-16-be').split('\0',1)[0]
        directory=bool(fields[2]&0x80000000);length=fields[3]|(fields[4]<<32);offset=fields[5]|(fields[6]<<32)
        entries.append({'name':name,'directory':directory,'bytes':None if directory else length,'offset':None if directory else offset})
        if not directory and (offset>len(b) or length>len(b)-offset):raise ValueError('Archive member exceeds file')
        at+=size
    entry=next(x for x in entries if x['name']=='01drm120elastik_2.WAV' and not x['directory'])
    raw=b[entry['offset']:entry['offset']+entry['bytes']]
    if raw[:4]!=b'RIFF' or struct.unpack_from('<I',raw,4)[0]+8!=len(raw):raise ValueError('Unexpected WAV framing')
    with wave.open(io.BytesIO(raw),'rb') as w:
        details={'channels':w.getnchannels(),'sample_rate':w.getframerate(),'bits':w.getsampwidth()*8,'frames':w.getnframes(),'seconds':w.getnframes()/w.getframerate()}
    output.mkdir(parents=True,exist_ok=True);(output/entry['name']).write_bytes(raw)
    result={'checkpoint':'ELA001','source_archive_sha256':EXPECTED,'directory_records':entries,'wave':{**details,'bytes':len(raw),'sha256':hashlib.sha256(raw).hexdigest()},'audio_bytes_unchanged':True,'original_engine_rendered':False,'native_arm64_plugin_built':False,'bank_authorization_modified':False}
    report.parent.mkdir(parents=True,exist_ok=True);report.write_text(json.dumps(result,indent=2)+'\n');return result


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('archive',type=Path);p.add_argument('--output',type=Path,required=True);p.add_argument('--report',type=Path,required=True);a=p.parse_args();print(json.dumps(extract(a.archive,a.output,a.report),indent=2))
