#!/usr/bin/env python3
"""Read-only preset audit. Never modify project or preset source files.
Extracts the documented outer AU plist / FXP container, NOT the opaque DSP state.
"""
import argparse, hashlib, json, plistlib, struct
from pathlib import Path

def fourcc(n): return (int(n)&0xffffffff).to_bytes(4,'big').decode('mac_roman')
def digest(data):return hashlib.sha256(data).hexdigest()

def inspect(p, out):
    data=p.read_bytes();r={'path':str(p),'size':len(data),'sha256':digest(data)};chunks={}
    if p.suffix.lower()=='.aupreset':
        pl=plistlib.loads(data)
        if not isinstance(pl,dict):raise ValueError('Expected AU dictionary')
        r['keys']=sorted(pl)
        r['identity']={k:fourcc(pl[k]) for k in ['type','subtype','manufacturer'] if isinstance(pl.get(k),int)}
        r['name']=pl.get('name');r['version']=pl.get('version')
        r['sophistry_identity_matches']=(r['identity']=={'type':'aumu','subtype':'Sop3','manufacturer':'LinP'})
        for k in ['vstdata','data']:
            if isinstance(pl.get(k),bytes):chunks[k]=pl[k]
        r['has_original_vstdata']=bool(chunks.get('vstdata'))
        r['state_decoder_implemented']=False
    elif data[:4]==b'CcnK':
        if len(data)<28:raise ValueError('Truncated FXP/FXB header')
        size,magic,version,uid,pversion,count=struct.unpack_from('>I4sI4sII',data,4)
        r.update(container=magic.decode('ascii','replace'),declared_size=size,format_version=version,plugin_id=uid.decode('mac_roman'),plugin_version=pversion,count=count)
        r['declared_size_matches']=(size+8==len(data))
        chunkoffset=60 if magic==b'FPCh' else 156 if magic==b'FBCh' else None
        if chunkoffset is not None:
            if len(data)<chunkoffset:raise ValueError('Truncated chunk container')
            length=struct.unpack_from('>I',data,chunkoffset-4)[0]
            if length>len(data)-chunkoffset:raise ValueError('Truncated FXP/FXB chunk')
            chunks['chunk']=data[chunkoffset:chunkoffset+length]
        r['state_decoder_implemented']=False
    else:raise ValueError('Supported input: .aupreset or CcnK FXP/FXB')
    r['chunks']={k:{'size':len(v),'sha256':digest(v),'first_32_bytes_hex':v[:32].hex()} for k,v in chunks.items()}
    if out:
        out.mkdir(parents=True,exist_ok=True)
        stem=p.stem+'-'+digest(data)[:12]
        for k,v in chunks.items():(out/(stem+'-'+k+'.bin')).write_bytes(v)
        (out/(stem+'.json')).write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n')
    return r

if __name__=='__main__':
    a=argparse.ArgumentParser();a.add_argument('presets',nargs='+',type=Path);a.add_argument('--output',type=Path);n=a.parse_args()
    print(json.dumps([inspect(p,n.output) for p in n.presets],ensure_ascii=False,indent=2))
