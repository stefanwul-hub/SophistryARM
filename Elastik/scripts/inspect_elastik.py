#!/usr/bin/env python3
"""Read a legacy Elastik installer without running its installer or plugin.

The package's Archive.pax.gz is an old ASCII CPIO archive, not a tar file.
Original files are extracted only with --extract; links are never followed.
"""
import argparse
import gzip
import hashlib
import json
from pathlib import Path, PurePosixPath
import plistlib
import struct
import zipfile
import zlib

EXPECTED='e72aa430ddb833de7e50d4157962caf45d8f75da105d68969cfad5a0b56c6939'


def cpio_files(data):
    at=0
    while at+76<=len(data):
        h=data[at:at+76]
        if h[:6]!=b'070707':raise ValueError('Expected old ASCII CPIO header')
        mode=int(h[18:24],8);namesize=int(h[59:65],8);size=int(h[65:76],8);at+=76
        if not 1<=namesize<=4096 or size>64*1024*1024:raise ValueError('Invalid member size')
        raw=data[at:at+namesize];at+=namesize
        if len(raw)!=namesize or raw[-1:]!=b'\0':raise ValueError('Invalid CPIO path')
        name=raw[:-1].decode('utf-8');blob=data[at:at+size];at+=size
        if len(blob)!=size:raise ValueError('Truncated CPIO data')
        if name=='TRAILER!!!':return
        path=PurePosixPath(name)
        if path.is_absolute() or '..' in path.parts:raise ValueError('Unsafe CPIO path')
        yield path,mode,blob
    raise ValueError('Missing CPIO trailer')


def resource_fork(data):
    start,map_start,_,_=struct.unpack_from('>4I',data)
    type_offset=struct.unpack_from('>H',data,map_start+24)[0];types=map_start+type_offset
    count=struct.unpack_from('>H',data,types)[0]+1;result=[]
    for i in range(count):
        kind,last,offset=struct.unpack_from('>4sHH',data,types+2+i*8)
        for j in range(last+1):
            ref=types+offset+j*12;rid,_,packed=struct.unpack_from('>hHI',data,ref)
            at=start+(packed&0xffffff);size=struct.unpack_from('>I',data,at)[0];blob=data[at+4:at+4+size]
            row={'resource_type':kind.decode('ascii'),'id':rid,'bytes':size}
            if kind==b'thng':
                row.update(type=blob[:4].decode(),subtype=blob[4:8].decode(),manufacturer=blob[8:12].decode(),version=struct.unpack_from('>I',blob,44)[0])
            if kind==b'STR ':row['text']=blob[1:1+blob[0]].decode('utf-8')
            if kind==b'dlle':row['entry']=blob.rstrip(b'\0').decode('ascii')
            result.append(row)
    return result


def macho(data):
    if data[:4]!=b'\xca\xfe\xba\xbe':raise ValueError('Expected a FAT Mach-O')
    count=struct.unpack_from('>I',data,4)[0];result=[];slices={}
    for i in range(count):
        cpu,sub,offset,size,_=struct.unpack_from('>5I',data,8+i*20)
        arch={7:'i386',18:'ppc',0x1000007:'x86_64',0x100000c:'arm64'}.get(cpu,hex(cpu))
        b=data[offset:offset+size];slices[arch]=b
        order='<' if b[:4]==b'\xce\xfa\xed\xfe' else '>'
        header=struct.unpack_from(order+'7I',b);at=28;libs=[];sections=[];table=None
        for _ in range(header[4]):
            cmd,n=struct.unpack_from(order+'II',b,at)
            if cmd in (0xc,0x80000018,0x8000001f):
                p=struct.unpack_from(order+'I',b,at+8)[0];libs.append(b[at+p:at+n].split(b'\0')[0].decode())
            if cmd==2:table=struct.unpack_from(order+'4I',b,at+8)
            if cmd==1:
                segment=struct.unpack_from(order+'16s8I',b,at+8)
                for j in range(segment[7]):
                    s=struct.unpack_from(order+'16s16s9I',b,at+56+j*68)
                    sections.append({'name':s[0].split(b'\0')[0].decode(),'segment':s[1].split(b'\0')[0].decode(),'address':s[2],'bytes':s[3],'offset':s[4],'flags':s[8]})
            at+=n
        symbols=[]
        if table:
            symoff,total,stroff,strsize=table;strings=b[stroff:stroff+strsize]
            for j in range(total):
                p,kind,sect,_,address=struct.unpack_from(order+'IBBHI',b,symoff+j*12)
                name=strings[p:].split(b'\0')[0].decode('utf-8',errors='replace')
                symbols.append({'name':name,'type':kind,'section':sect,'address':address})
        exports=[s for s in symbols if s['section'] and sections[s['section']-1]['name']=='__text']
        result.append({'architecture':arch,'bytes':size,'sha256':hashlib.sha256(b).hexdigest(),'dynamic_libraries':libs,'sections':sections,'defined_text_exports':exports,'undefined_import_count':sum((s['type']&14)==0 for s in symbols),'imports':[s['name'] for s in symbols if (s['type']&14)==0]})
    return result,slices


def cbf_png(data,path):
    version,channels,width,height=struct.unpack_from('>4H',data)
    if version!=1 or channels!=4 or len(data)!=8+width*height*4:raise ValueError('Unsupported CBF bitmap')
    def chunk(kind,b):return struct.pack('>I',len(b))+kind+b+struct.pack('>I',zlib.crc32(kind+b)&0xffffffff)
    scan=b''.join(b'\0'+data[8+y*width*4:8+(y+1)*width*4] for y in range(height))
    png=b'\x89PNG\r\n\x1a\n'+chunk(b'IHDR',struct.pack('>2I5B',width,height,8,6,0,0,0))+chunk(b'IDAT',zlib.compress(scan,9))+chunk(b'IEND',b'')
    path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(png)
    return {'width':width,'height':height,'channels':channels,'copied_rgba_pixels_unchanged':True}


def inspect(source,output,extract=None):
    raw=source.read_bytes();digest=hashlib.sha256(raw).hexdigest()
    if digest!=EXPECTED:raise ValueError('Installer differs from the supplied 1.5.2.3 reference')
    with zipfile.ZipFile(source) as z:
        pkg=plistlib.loads(z.read('ElastikAU.pkg/Contents/Info.plist'))
        with gzip.GzipFile(fileobj=__import__('io').BytesIO(z.read('ElastikAU.pkg/Contents/Archive.pax.gz'))) as f:
            payload=f.read(64*1024*1024+1)
        if len(payload)>64*1024*1024:raise ValueError('Payload size limit exceeded')
    members={};inventory=[]
    for path,mode,blob in cpio_files(payload):
        regular=(mode&0o170000)==0o100000
        inventory.append({'path':str(path),'bytes':len(blob),'regular':regular,'sha256':hashlib.sha256(blob).hexdigest() if regular else None})
        if not regular:continue
        members[str(path)]=blob
        if extract:
            target=extract/Path(*path.parts);target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(blob)
    prefix='Library/Audio/Plug-Ins/Components/Elastik.component/Contents/'
    info=plistlib.loads(members[prefix+'Info.plist'].lstrip());arches,slices=macho(members[prefix+'MacOS/Elastik'])
    rsrc=resource_fork(members[prefix+'Resources/Elastik.rsrc'])
    output.mkdir(parents=True,exist_ok=True)
    graphic=cbf_png(members[prefix+'Resources/bg.cbf'],output/'original-background.png')
    themes=[]
    for name,b in members.items():
        if name.endswith('.appearance/Info.plist'):
            p=plistlib.loads(b);themes.append({'resource':name.split('/Resources/',1)[-1],'identifier':p.get('identifier'),'title':p.get('title'),'fonts':p.get('fonts')})
    report={'checkpoint':'ELA001','package_sha256':digest,'package_version':pkg['CFBundleShortVersionString'],'bundle':info,'architectures':arches,'audio_unit_resources':rsrc,'resource_file_count':sum('/Resources/' in n for n in members),'bitmap_background':graphic,'themes':themes,'builtin_archive':{'resource':'Elastik.elastik','bytes':len(members[prefix+'Resources/Elastik.elastik']),'magic':members[prefix+'Resources/Elastik.elastik'][:4].decode('ascii'),'soundbank_compatibility_not_yet_proven':True},'installer_executed':False,'original_plugin_executed':False,'native_arm64_plugin_built':False,'original_files_modified':False}
    (output/'original-inventory.json').write_text(json.dumps(report,indent=2)+'\n')
    (output/'payload-files.json').write_text(json.dumps(inventory,indent=2)+'\n')
    if extract:
        for name,b in slices.items():(extract.parent/('Elastik.'+name)).write_bytes(b)
    return report


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('installer',type=Path);p.add_argument('--output',type=Path,required=True);p.add_argument('--extract',type=Path)
    a=p.parse_args();r=inspect(a.installer,a.output,a.extract)
    print(json.dumps({'package_version':r['package_version'],'architectures':[x['architecture']for x in r['architectures']],'audio_unit':[x for x in r['audio_unit_resources']if x.get('type')=='aumu'],'resource_files':r['resource_file_count'],'installer_executed':False,'native_plugin_built':False},indent=2))
