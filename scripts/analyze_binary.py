#!/usr/bin/env python3
"""Reproduce the static audit using Python's standard library; never execute the plugin."""
import argparse, hashlib, json, plistlib, re, struct, zipfile
from pathlib import Path, PurePosixPath

ARCHIVE_SHA256 = 'c6fdd914f7388210a552706c3f0d2a845134fca13aa39fe85e31c415cc5ad5f1'
COMMIT = 'd0b62115360f1f3b993ae2c7c404c2ba74bdb2ab'

def sha(data): return hashlib.sha256(data).hexdigest()
def save(p, data):
    p.parent.mkdir(parents=True, exist_ok=True)
    p.write_text(json.dumps(data, indent=2, ensure_ascii=False)+'\n')

def resources(data):
    do, mo, dl, ml = struct.unpack_from('>4I', data)
    to, no = struct.unpack_from('>HH', data, mo+24)
    base = mo+to
    count = struct.unpack_from('>H', data, base)[0]+1
    result=[]
    for k in range(count):
        typ, n, ro=struct.unpack_from('>4sHH',data,base+2+8*k)
        typ=typ.decode('mac_roman')
        for j in range(n+1):
            at=base+ro+12*j
            rid, name_off=struct.unpack_from('>hh',data,at)
            offset=int.from_bytes(data[at+5:at+8],'big')
            nbytes=struct.unpack_from('>I',data,do+offset)[0]
            payload=data[do+offset+4:do+offset+4+nbytes]
            entry={'type':typ,'id':rid,'size':nbytes,'hex':payload.hex()}
            if name_off>=0:
                ni=mo+no+name_off
                entry['name']=data[ni+1:ni+1+data[ni]].decode('mac_roman')
            if typ=='STR ' and payload:
                entry['text']=payload[1:1+payload[0]].decode('mac_roman')
            if typ=='thng':
                entry['component']={k:payload[i:i+4].decode('mac_roman') for k,i in [('type',0),('subtype',4),('manufacturer',8)]}
                entry['flags'],entry['flags_mask']=struct.unpack_from('>II',payload,12)
                entry['version']=hex(struct.unpack_from('>I',payload,44)[0])
            result.append(entry)
    return result

def macho(data):
    magic,cpu,sub,ft,n,sz,flags=struct.unpack_from('<7I',data)
    assert magic==0xfeedface and cpu==7, 'Expected i386 Mach-O'
    pos=28; sections=[]; segments=[]; dylibs=[]; symtab=None
    for _ in range(n):
        cmd,cs=struct.unpack_from('<II',data,pos)
        if cmd==1:
            sn,vm,vs,fo,fs,ma,init,ns,fl=struct.unpack_from('<16s8I',data,pos+8)
            segments.append({'name':sn.rstrip(b'\0').decode(),'vmaddr':vm,'vmsize':vs,'fileoff':fo,'filesize':fs})
            for j in range(ns):
                st=struct.unpack_from('<16s16s9I',data,pos+56+68*j)
                sections.append({'name':st[0].rstrip(b'\0').decode(),'segment':st[1].rstrip(b'\0').decode(),'address':st[2],'size':st[3],'offset':st[4]})
        elif cmd==2: symtab=struct.unpack_from('<4I',data,pos+8)
        elif cmd in (12,24,0x80000018):
            no=struct.unpack_from('<I',data,pos+8)[0]
            dylibs.append(data[pos+no:pos+cs].split(b'\0')[0].decode())
        assert cs>=8 and pos+cs<=len(data)
        pos+=cs
    syms=[]
    if symtab:
        so,nn,sto,sts=symtab
        for j in range(nn):
            ix,typ,sec,desc,val=struct.unpack_from('<IBBhI',data,so+12*j)
            name=data[sto+ix:sto+sts].split(b'\0')[0].decode('utf8','replace')
            syms.append({'address':val,'type':typ,'section':sec,'name':name})
    return {'segments':segments,'sections':sections,'dylibs':dylibs,'symbols':syms}

def vtables(data, meta):
    def off(address):
        for s in meta['segments']:
            if s['vmaddr']<=address<s['vmaddr']+s['filesize']:
                return s['fileoff']+address-s['vmaddr']
        raise ValueError(hex(address))
    strs={}
    for sec in meta['sections']:
        if sec['offset']==0: continue
        for m in re.finditer(rb'[0-9]{1,3}[A-Za-z_][A-Za-z0-9_]{2,90}\x00',data[sec['offset']:sec['offset']+sec['size']]):
            strs[sec['address']+m.start()]=m.group()[:-1].decode('ascii')
    const=[s for s in meta['sections'] if s['segment']=='__DATA' and s['name'] in ('__const','__const_coal')]
    code=[s for s in meta['sections'] if s['name'] in ('__text','__textcoal_nt','__jump_table')]
    valid=lambda a:any(s['address']<=a<s['address']+s['size'] for s in code)
    result=[]
    for sec in const:
        for at in range(sec['address'], sec['address']+sec['size']-8, 4):
            ptr=struct.unpack_from('<I',data,off(at)+4)[0]
            if ptr not in strs: continue
            name=re.sub(r'^\d+','',strs[ptr]); tables=[]
            needle=struct.pack('<II',0,at)
            for vs in const:
                start=vs['offset'];end=start+vs['size']
                while True:
                    hit=data.find(needle,start,end)
                    if hit<0:break
                    start=hit+1
                    if (hit-vs['offset'])%4: continue
                    values=[];k=hit+8
                    while k+4<=end:
                        adr=struct.unpack_from('<I',data,k)[0]
                        if not valid(adr):break
                        values.append(hex(adr));k+=4
                    if values:tables.append({'address':hex(vs['address']+hit-vs['offset']),'functions':values})
            if tables:result.append({'name':name,'rtti':hex(at),'tables':tables})
    return result

def audit(archive, output):
    packed=archive.read_bytes()
    if sha(packed)!=ARCHIVE_SHA256:raise ValueError('Archive differs from pinned original; stop and inspect it')
    with zipfile.ZipFile(archive) as z:
        for info in z.infolist():
            pp=PurePosixPath(info.filename)
            if pp.is_absolute() or '..' in pp.parts or (info.external_attr>>16)&0o170000==0o120000:
                raise ValueError('Unsafe ZIP entry: '+info.filename)
        z.extractall(output/'original')
    root=output/'original/Sophistry.component/Contents'
    universal=(root/'MacOS/Sophistry').read_bytes()
    assert struct.unpack_from('>I',universal)[0]==0xcafebabe
    arches=[];thin=None
    for i in range(struct.unpack_from('>I',universal,4)[0]):
        cpu,sub,offset,size,align=struct.unpack_from('>IIIII',universal,8+20*i)
        arches.append({'cpu_type':cpu,'subtype':sub,'architecture':{7:'i386',18:'ppc',0x1000007:'x86_64',0x100000c:'arm64'}.get(cpu,'unknown'),'offset':offset,'size':size})
        if cpu==7:thin=universal[offset:offset+size]
    if thin is None:raise ValueError('No i386 slice')
    (output/'original/Sophistry.i386').write_bytes(thin)
    meta=macho(thin); tables=vtables(thin,meta)
    rr=resources((root/'Resources/Sophistry.rsrc').read_bytes())
    report={'source_url':'https://github.com/stefanwul-hub/SophistryARM','source_commit':COMMIT,'archive_sha256':sha(packed),'universal_sha256':sha(universal),'i386_sha256':sha(thin),'architectures':arches,'info':plistlib.loads((root/'Info.plist').read_bytes()),'resources':rr,'image_count':len(list((root/'Resources').glob('*.png'))),'symbol_count':len(meta['symbols']),'defined_symbol_count':sum(s['section']>0 for s in meta['symbols']),'rtti_vtable_classes':len(tables)}
    save(output/'analysis/binary-report.json',report);save(output/'analysis/macho.json',meta);save(output/'analysis/vtables.json',tables)
    hints={}
    for c in tables:
        for t in c['tables']:
            for i,a in enumerate(t['functions']):hints.setdefault(a,re.sub('[^A-Za-z0-9_]','_',c['name'])+'_vslot_'+str(i))
    (output/'analysis/function-hints.tsv').write_text(''.join(a+'\t'+n+'\n' for a,n in hints.items()))
    cs=next(s for s in meta['sections'] if s['name']=='__cstring')
    entries=[{'address':hex(cs['address']+m.start()),'text':m.group()[:-1].decode('utf8','replace')} for m in re.finditer(rb'[^\x00]+\x00',thin[cs['offset']:cs['offset']+cs['size']])]
    save(output/'analysis/cstrings.json',entries)
    print(json.dumps({k:report[k] for k in ['architectures','image_count','rtti_vtable_classes','defined_symbol_count']},indent=2))

if __name__=='__main__':
    a=argparse.ArgumentParser();a.add_argument('archive',type=Path);a.add_argument('--output',type=Path,default=Path('work/audit'));n=a.parse_args();audit(n.archive,n.output)
