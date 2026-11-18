#!/usr/bin/env python3
"""Audit original executable coverage; static evidence is not exhaustive behavior proof."""
from pathlib import Path
import argparse,os
ROOT=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();output=args.output.resolve();output.parent.mkdir(parents=True,exist_ok=True);os.chdir(ROOT)
import json,struct,sys,gzip,re
from legacy_image import LegacyImage
p=output.parent;image=LegacyImage(Path('reference/Sophistry.i386').read_bytes());raw=bytes(image.mapped());sec=next(s for s in image.sections if s['name']=='__eh_frame');start=sec['address'];end=start+sec['size'];cies={};fdes=[];at=start

def leb(pos,signed=False):
 value=0;shift=0
 while True:
  b=raw[pos];pos+=1;value|=(b&127)<<shift;shift+=7
  if not b&128:break
 if signed and b&64:value-=1<<shift
 return value,pos

def pointer(pos,encoding,relative=True):
 fmt=encoding&15;base=pos
 if encoding==255:return None,pos
 if encoding&0x70==0x50:pos=(pos+3)&~3;base=pos
 if fmt==0:value=struct.unpack_from('<I',raw,pos)[0];pos+=4
 elif fmt==1:value,pos=leb(pos)
 elif fmt==9:value,pos=leb(pos,True)
 elif fmt in [2,3,4,10,11,12]:
  n={2:2,3:4,4:8,10:2,11:4,12:8}[fmt];value=int.from_bytes(raw[pos:pos+n],'little',signed=fmt>=10);pos+=n
 else:raise ValueError('Pointer format '+hex(encoding))
 if relative:
  app=encoding&0x70
  if app==0x10:value=(value+base)&0xffffffff
  elif app not in [0,0x50]:raise ValueError('Pointer application '+hex(encoding))
 return value,pos

while at+4<=end:
 length=struct.unpack_from('<I',raw,at)[0]
 if not length:at+=4;continue
 if length==0xffffffff:raise ValueError('64-bit record not expected')
 stop=at+4+length;assert stop<=end,(hex(at),length)
 ident=struct.unpack_from('<I',raw,at+4)[0];pos=at+8
 if not ident:
  version=raw[pos];pos+=1;null=raw.index(0,pos);augmentation=raw[pos:null].decode();pos=null+1
  if augmentation=='eh':pos+=4
  _,pos=leb(pos);_,pos=leb(pos,True)
  if version==1:pos+=1
  else:_,pos=leb(pos)
  encoding=0
  if augmentation.startswith('z'):
   n,pos=leb(pos);augend=pos+n
   for c in augmentation[1:]:
    if c=='R':encoding=raw[pos];pos+=1
    elif c=='L':pos+=1
    elif c=='P':typ=raw[pos];pos+=1;_,pos=pointer(pos,typ)
    elif c=='S':pass
    else:raise ValueError('Unknown CIE augmentation '+augmentation)
   assert pos<=augend;pos=augend
  cies[at]={'encoding':encoding,'augmentation':augmentation}
 else:
  cie=at+4-ident;spec=cies[cie];pc,pos=pointer(pos,spec['encoding']);size,pos=pointer(pos,spec['encoding']&15,False);fdes.append({'entry':hex(pc),'size':size,'record':hex(at)})
 at=stop
known=set()
for f in Path('src/lifter/whole').glob('Unit*.cpp'):known.update(int(x,16) for x in re.findall(r'^L_([0-9a-f]+):',f.read_text(),re.M))
missing=[r for r in fdes if int(r['entry'],16) not in known]
execsects=[s for s in image.sections if s['flags']&0x80000400]
symbols=[s for s in image.symbols if s['address'] and any(t['address']<=s['address']<t['address']+t['size'] for t in execsects)]
missing_symbols=[s for s in symbols if s['address'] not in known]
r={'cie_records':len(cies),'fde_records':len(fdes),'missing_fde_entries':missing,'executable_sections':[{k:s[k] for k in ['name','address','size','flags']} for s in execsects],'symbols_in_executable_sections':len(symbols),'missing_executable_symbols':missing_symbols,'frames':fdes}
r['passed']=not missing and not missing_symbols
output.write_text(json.dumps(r,indent=2)+'\n');print({k:len(v) if isinstance(v,list) else v for k,v in r.items()});print('missing unwind',missing[:12]);print('missing symbols',missing_symbols[:6])

if not r['passed']:raise SystemExit(1)
