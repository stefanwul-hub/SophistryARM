import json,struct,sys,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1];sys.path.insert(0,str(ROOT/'scripts'))
from decode_legacy_state import records,read_input,summarize,leaves
class RealStates(unittest.TestCase):
 @classmethod
 def setUpClass(cls):cls.schemas=json.loads((ROOT/'analysis/parameter-schemas.json').read_text())['modules']
 def test_recovered_descriptors_and_real_au(self):
  self.assertEqual(len(self.schemas),51);self.assertTrue(all(s['extraction_ok'] for s in self.schemas))
  p=ROOT/'reference/Presets/Lightgarden 02 BT.aupreset';r,rr=summarize(p,self.schemas)
  self.assertEqual(r['metadata']['identity']['subtype'],'CrX3');self.assertEqual(r['chunk_size'],22192)
  self.assertEqual([x['tag'] for x in rr],['SYG0','SYG1','TUN0','PROG']);self.assertEqual(r['leaf_blocks'],121)
  self.assertEqual(r['fully_consumed_by_schema'],117);self.assertTrue(r['round_trip_byte_exact'])
 def test_real_fxp_and_sample_reference(self):
  p=ROOT/'reference/Presets/lightgarden 02 BT.FXP';r,rr=summarize(p,self.schemas)
  self.assertEqual(r['chunk_size'],20640);self.assertEqual(r['leaf_blocks'],118);self.assertEqual(r['fully_consumed_by_schema'],116)
  files=[f['value'] for x in leaves(rr) for f in x.get('decoded',{}).get('fields',[]) if f['name']=='Filename' and f['value']]
  self.assertTrue(any('BT_cronox18.wav' in x for x in files))
 def test_bad_record_size_and_truncated_nested_program(self):
  raw=(ROOT/'tests/fixtures/legacy-au-vstdata.bin').read_bytes()
  with self.assertRaises(ValueError):records(raw[:-1])
  bad=bytearray(raw);bad[4:8]=struct.pack('<I',4)
  with self.assertRaises(ValueError):records(bad)
 def test_unknown_payload_remains_opaque(self):
  raw=struct.pack('<III',0x554e4b30,16,7)+b'\xcd\0\xff\0';rr=records(raw)
  self.assertEqual(rr[0]['tag'],'UNK0');self.assertEqual(rr[0]['raw'],raw)
if __name__=='__main__':unittest.main()
