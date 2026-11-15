#!/usr/bin/env python3
"""Document the original bank loader's SynthEdited reset, using public fixtures only."""
import argparse, hashlib, json, struct
from pathlib import Path
from probe_au_render import RenderHost, Original, ROOT, LegacyImage
import sys
sys.path.insert(0, str(ROOT / 'scripts'))
from decode_legacy_state import summarize, compare

def run(output):
 image = LegacyImage((ROOT / 'reference/Sophistry.i386').read_bytes())
 backend = Original(bytes(image.mapped()), 0x4000000)
 host = RenderHost(backend, image)
 outer = 0x200000 - 0xec
 def call(pc, *args):
  backend.run(pc, list(args))
  return host.eax()
 try:
  for pc in image.initializers: call(pc)
  call(0x48b0, outer, 0x70001000)
  for offset, value in [(0,0xf2048),(8,0xf21a8),(0xe4,0xf21b4),(0xec,0xf2208)]: host.put(outer+offset,value)
  call(0xa6a2a,outer);call(0x2918,outer)
  dispatcher=host.word(0x200024)
  def restore(chunk,program):
   backend.write(0x600000,chunk)
   if not program:backend.write(outer+0x32b434,b'\x01')
   try:
    if call(dispatcher,0x200020,24,program,len(chunk),0x600000,0)!=len(chunk):raise RuntimeError('Incomplete bank restore')
   finally:
    if not program:backend.write(outer+0x32b434,b'\0')
  def save():
   host.put(0x5f0000,0);size=call(dispatcher,0x200020,23,0,0,0x5f0000,0)
   return backend.read(host.word(0x5f0000),size)
  restore((ROOT/'reference/Presets/lightgarden 02 BT.FXP').read_bytes()[60:],1)
  first=save();restore(first,0);second=save();restore(second,0);third=save()
  output.parent.mkdir(parents=True,exist_ok=True)
  first_path=output.with_suffix('.first.bin');second_path=output.with_suffix('.second.bin')
  first_path.write_bytes(first);second_path.write_bytes(second)
  schemas=json.loads((ROOT/'analysis/parameter-schemas.json').read_text())['modules']
  _,a=summarize(first_path,schemas);_,b=summarize(second_path,schemas);comparison=compare(a,b)
  result={'scope':'Original i386 AU-variant bank save/restore in explicit platform fixture, unregistered public FXP only','first_restore_changes':comparison['differences'],'first_restore_different_bytes':sum(a!=b for a,b in zip(first,second)),'subsequent_roundtrip_byte_exact':second==third,'first_bank_bytes':len(first),'first_bank_sha256':hashlib.sha256(first).hexdigest(),'restored_bank_sha256':hashlib.sha256(second).hexdigest(),'original_sha256':image.report()['original_sha256']}
  output.write_text(json.dumps(result,indent=2)+'\n')
  assert comparison['different_decoded_fields']==1 and comparison['differences'][0]['name']=='SynthEdited'
  assert comparison['differences'][0]['first']==1 and comparison['differences'][0]['second']==0 and second==third
  return result
 finally:backend.close()

if __name__=='__main__':
 parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();print(json.dumps(run(args.output),indent=2))
