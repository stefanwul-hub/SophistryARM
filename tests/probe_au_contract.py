#!/usr/bin/env python3
"""Execute original AU parameter methods in a narrowly defined outer-object fixture.

The synth is initialized normally. Only the outer AU vtable and already-open flag
are provided, since parameter methods do not require AudioComponent registration.
This does not construct the original AUBase or establish its audio bus layout.
"""
import argparse,ctypes,hashlib,json,math,struct,sys
from pathlib import Path
from probe_engine_initialization import Host,HostedNative,Original,ROOT,LegacyImage

def run(library,output):
 image=LegacyImage((ROOT/'reference/Sophistry.i386').read_bytes())
 b=HostedNative(ctypes.CDLL(str(library.resolve())),bytes(image.mapped()),0x4000000) if library else Original(bytes(image.mapped()),0x4000000)
 h=Host(b,image);error=None;stage='initialization';parameters=[];ids=[];aliases=[];validation=[]
 outer=0x200000-0xec
 def call(pc,args):
  b.run(pc,args);return h.eax()
 try:
  for pc in image.initializers:call(pc,[])
  call(0x4e876,[0x200000,0x273c]);call(h.word(0x200024),[0x200020,0,0,0,0,0])
  # Original AUCronoX vtable: the address after its two Itanium ABI headers.
  if struct.unpack('<I',b.read(0xf2048,4))[0]!=0x8285c:raise ValueError('Unexpected AU vtable')
  h.put(outer,0xf2048);b.write(outer+0x32b430,b'\x01')
  stage='AU parameter list size';h.put(0x5d0000,0)
  status=call(0x82cbe,[outer,0,0,0x5d0000]);count=h.word(0x5d0000)
  if status or count>2048:raise ValueError('Invalid parameter list size')
  stage='AU parameter list';b.write(0x5d0100,b'\xff'*(4*count))
  status=call(0x82cbe,[outer,0,0x5d0100,0x5d0000])
  if status:raise ValueError('Parameter list returned '+hex(status))
  ids=list(struct.unpack('<'+'I'*count,b.read(0x5d0100,4*count)))
  if len(set(ids))!=len(ids):raise ValueError('Duplicate AU parameter IDs')
  stage='AU parameter validation and legacy aliases'
  for pid in range(603):
   h.put(0x5d3000,pid);valid=call(0x835d6,[outer,0x5d3000]);alias=h.word(0x5d3000)
   validation.append({'id':pid,'accepted':bool(valid),'validation_alias':alias if valid else None,'listed':pid in ids})
   if valid and alias!=pid:aliases.append({'au_parameter_id':pid,'validation_alias':alias,'listed':pid in ids})
  for pid in ids:
   stage='AU parameter info '+str(pid);h.put(0x5d3000,pid)
   valid=call(0x835d6,[outer,0x5d3000]);alias=h.word(0x5d3000)
   if not valid:raise ValueError('Listed parameter rejected by original validation')
   b.write(0x5d2000,b'\0'*84)
   status=call(0x82d68,[outer,0,pid,0x5d2000])
   if status:raise ValueError('AU info error '+hex(status))
   raw=b.read(0x5d2000,84)
   name=raw[:52].split(b'\0',1)[0].decode('utf8','replace')
   unit_name,clump,cf_name,unit=struct.unpack_from('<4I',raw,52)
   minimum,maximum,default=struct.unpack_from('<3f',raw,68);flags=struct.unpack_from('<I',raw,80)[0]
   if not all(math.isfinite(v) for v in [minimum,maximum,default]):raise ValueError('Non-finite parameter range')
   h.put(0x5d2100,0);status=call(0x3bfe,[outer,pid,0,0,0x5d2100])
   if status:raise ValueError('AU getParameter error '+hex(status))
   value=struct.unpack('<f',b.read(0x5d2100,4))[0]
   call(0x1ce0e,[0x200000,pid,0x5d2200]);kind,lo,hi,initial,labels,width,curve_bits=struct.unpack('<7I',b.read(0x5d2200,28))
   labels_text=None
   if kind==2 and labels and width and hi>=lo and (hi-lo+1)*width<65536:
    labels_text=[b.read(labels+i*width,width).decode('utf8','replace') for i in range(hi-lo+1)]
   parameters.append({'id':pid,'validation_alias':alias,'name':name,'cf_name':h.cf_string(cf_name) if cf_name else None,'unit':unit,'unit_name':h.cf_string(unit_name) if unit_name else None,'clump_id':clump,'minimum':minimum,'maximum':maximum,'default':default,'value_after_effOpen':value,'flags':hex(flags),'descriptor_kind':kind,'indexed_value_labels':labels_text})
  stage='completed'
 except Exception as e:error=str(e)
 pc=b.l.sl_get_pc(b.c) if library else b.uc.reg_read(__import__('unicorn.x86_const',fromlist=['UC_X86_REG_EIP']).UC_X86_REG_EIP)
 result={'scope':'Original AU parameter methods executed with an explicitly synthetic outer object; not AU registration, host integration or bus validation','backend':'statically translated C++' if library else 'original i386 / Unicorn','original_sha256':image.report()['original_sha256'],'stage':stage,'error':error,'stopped_pc':hex(pc),'last_import':h.last_import,'parameter_ids':ids,'parameter_count':len(ids),'metadata_records_completed':len(parameters),'aliases':aliases,'validation_for_indices_0_to_602':validation,'parameters':parameters,'host_import_calls':dict(h.calls),'object_memory_sha256':hashlib.sha256(b.read(0x200000,0x340000)).hexdigest(),'heap_memory_sha256':hashlib.sha256(b.read(0x800000,h.heap-0x800000)).hexdigest(),'global_memory_sha256':hashlib.sha256(b.read(0xe2000,0x104000-0xe2000)).hexdigest(),'native_au_available':False,'project_recall_verified':False,'bus_layout_verified':False}
 output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(result,indent=2,ensure_ascii=False)+'\n');b.close();return result
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--library',type=Path);p.add_argument('--output',type=Path,required=True);n=p.parse_args();r=run(n.library,n.output)
 print(json.dumps({k:v for k,v in r.items() if k not in ['parameters','host_import_calls','parameter_ids','validation_for_indices_0_to_602']},indent=2));sys.exit(1 if r['error'] else 0)
