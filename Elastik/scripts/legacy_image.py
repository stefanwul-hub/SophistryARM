#!/usr/bin/env python3
"""Map the pinned 32-bit Mach-O as guest data; never execute its machine bytes."""
import argparse,hashlib,json,struct
from pathlib import Path
SHA='5b313e738d92c438253927e8d57969ddfd99302b1d978372ac9e045490698920'
class LegacyImage:
 def __init__(self,data):
  if hashlib.sha256(data).hexdigest()!=SHA:raise ValueError('Expected the pinned Elastik 1.5.2.3 i386 image')
  self.file=data;self.segments=[];self.sections=[];self.symbols=[];self.stubs=[];self.pointers=[];self.relocations=[]
  if struct.unpack_from('<II',data)!=(0xfeedface,7):raise ValueError('Expected little-endian i386 Mach-O')
  at=28;symtab=None;dysymtab=None
  for _ in range(struct.unpack_from('<I',data,16)[0]):
   cmd,size=struct.unpack_from('<II',data,at)
   if size<8 or at+size>len(data):raise ValueError('Invalid load command')
   if cmd==1:
    name,vm,vmsize,fileoff,filesize,maxprot,initprot,nsections,flags=struct.unpack_from('<16s8I',data,at+8)
    if filesize>vmsize or fileoff+filesize>len(data):raise ValueError('Invalid segment')
    self.segments.append({'name':name.rstrip(b'\0').decode(),'address':vm,'size':vmsize,'fileoff':fileoff,'filesize':filesize})
    for i in range(nsections):
     s=struct.unpack_from('<16s16s9I',data,at+56+68*i)
     self.sections.append({'name':s[0].rstrip(b'\0').decode(),'segment':s[1].rstrip(b'\0').decode(),'address':s[2],'size':s[3],'offset':s[4],'flags':s[8],'reserved1':s[9],'reserved2':s[10]})
   elif cmd==2:symtab=struct.unpack_from('<4I',data,at+8)
   elif cmd==0xb:dysymtab=struct.unpack_from('<18I',data,at+8)
   at+=size
  if not symtab or not dysymtab:raise ValueError('Missing symbol tables')
  size=max(s['address']+s['size'] for s in self.segments)
  mapped=bytearray(size)
  for s in self.segments:mapped[s['address']:s['address']+s['filesize']]=data[s['fileoff']:s['fileoff']+s['filesize']]
  self.initial=bytes(mapped)
  so,count,strings,strings_size=symtab
  for i in range(count):
   index,kind,section,description,value=struct.unpack_from('<IBBhI',data,so+12*i)
   name=data[strings+index:strings+strings_size].split(b'\0',1)[0].decode('utf8')
   self.symbols.append({'name':name,'address':value,'kind':kind,'section':section})
  indirect=struct.unpack_from('<'+'I'*dysymtab[13],data,dysymtab[12])
  for section in self.sections:
   kind=section['flags']&0xff
   if kind not in [6,7,8]:continue
   stride=section['reserved2'] if kind==8 else 4
   for i in range(section['size']//stride):
    index=indirect[section['reserved1']+i]
    if index&0xc0000000:continue
    item={'address':section['address']+i*stride,'name':self.symbols[index]['name']}
    (self.stubs if kind==8 else self.pointers).append(item)
  for i in range(dysymtab[15]):
   address,info=struct.unpack_from('<II',data,dysymtab[14]+i*8)
   if info>>28 or (info>>25)&3!=2 or (info>>24)&1 or not (info>>27)&1:raise ValueError('Unsupported external relocation')
   self.relocations.append({'address':address,'name':self.symbols[info&0xffffff]['name'],'addend':struct.unpack_from('<I',self.initial,address)[0]})
  self.initializers=[]
  for section in self.sections:
   if section['name']=='__mod_init_func':
    self.initializers.extend(struct.unpack_from('<'+'I'*(section['size']//4),self.initial,section['address']))
 def mapped(self):
  """Return correctly located segments and zero-filled bss/common data."""
  return bytearray(self.initial)
 def bind(self,memory,name,guest_address):
  """Bind a known import to a 32-bit guest token; no native pointer truncation."""
  if not 0<=guest_address<=0xffffffff:raise ValueError('Import binding exceeds a guest pointer')
  count=0
  for pointer in self.pointers:
   if pointer['name']==name:struct.pack_into('<I',memory,pointer['address'],guest_address);count+=1
  for relocation in self.relocations:
   if relocation['name']==name:struct.pack_into('<I',memory,relocation['address'],(guest_address+relocation['addend'])&0xffffffff);count+=1
  return count
 def report(self):
  zero_sections=[s for s in self.sections if s['flags']&0xff==1]
  return {'scope':'Guest data loader metadata only; no engine initialization or machine-code execution',
   'original_sha256':SHA,'mapped_bytes':len(self.initial),'mapped_sha256':hashlib.sha256(self.initial).hexdigest(),
   'segments':self.segments,'zero_filled_sections':[{'name':s['name'],'address':hex(s['address']),'bytes':s['size'],'all_zero':not any(self.initial[s['address']:s['address']+s['size']])} for s in zero_sections],
   'function_imports':self.stubs,'pointer_imports':self.pointers,'external_relocations':len(self.relocations),
   'external_data_symbols':sorted({r['name'] for r in self.relocations}),'global_initializers':[hex(i) for i in self.initializers],
   'whole_engine_initialized':False}
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('image',type=Path);p.add_argument('--output',type=Path,required=True);n=p.parse_args()
 r=LegacyImage(n.image.read_bytes()).report();n.output.write_text(json.dumps(r,indent=2)+'\n')
 print(json.dumps({'mapped_bytes':r['mapped_bytes'],'function_imports':len(r['function_imports']),'pointer_imports':len(r['pointer_imports']),'global_initializers':len(r['global_initializers']),'external_relocations':r['external_relocations'],'zero_filled_sections':r['zero_filled_sections']},indent=2))
