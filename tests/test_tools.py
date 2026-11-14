import hashlib,json,plistlib,struct,sys,tempfile,unittest
from pathlib import Path
ROOT=Path(__file__).resolve().parents[1]
sys.path.insert(0,str(ROOT/'scripts'))
from analyze_binary import ARCHIVE_SHA256,macho,resources
from inspect_presets import inspect
from compare_audio import compare

class Tools(unittest.TestCase):
    def test_original_architecture_and_au_resource(self):
        archive=ROOT/'reference/Sophistry.component.zip'
        self.assertEqual(hashlib.sha256(archive.read_bytes()).hexdigest(),ARCHIVE_SHA256)
        meta=macho((ROOT/'reference/Sophistry.i386').read_bytes())
        self.assertEqual(len(meta['symbols']),425)
        self.assertIn('/System/Library/Frameworks/Carbon.framework/Versions/A/Carbon',meta['dylibs'])
        rr=resources((ROOT/'reference/Resources/Sophistry.rsrc').read_bytes())
        inst=next(r for r in rr if r['type']=='thng' and r['id']==1000)
        self.assertEqual(inst['component'],{'type':'aumu','subtype':'Sop3','manufacturer':'LinP'})
        self.assertEqual(inst['version'],'0x30008')
    def test_arm64_evidence_is_an_object_not_a_bundle(self):
        d=(ROOT/'evidence/SaturKernel.arm64.o').read_bytes()
        magic,cpu,sub,filetype=struct.unpack_from('<4I',d)
        self.assertEqual((magic,cpu,filetype),(0xfeedfacf,0x100000c,1))
    def test_au_outer_state_extraction_and_identity(self):
        # Synthetic wrapper tests ONLY the plist extractor, not a real DSP state.
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'synthetic.aupreset'
            pl={k:int.from_bytes(v.encode(),'big') for k,v in [('type','aumu'),('subtype','Sop3'),('manufacturer','LinP')]}
            pl.update(name='synthetic-test-only',vstdata=b'\0\1FAKE-STATE')
            p.write_bytes(plistlib.dumps(pl,fmt=plistlib.FMT_BINARY));out=Path(td)/'out'
            r=inspect(p,out)
            self.assertTrue(r['sophistry_identity_matches']);self.assertFalse(r['state_decoder_implemented'])
            self.assertEqual(next(out.glob('*-vstdata.bin')).read_bytes(),pl['vstdata'])
            pl['subtype']=int.from_bytes(b'xxxx','big');p.write_bytes(plistlib.dumps(pl))
            self.assertFalse(inspect(p,None)['sophistry_identity_matches'])
    def test_fxp_outer_chunk_and_truncation(self):
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'synthetic.fxp';chunk=b'\1\2TEST'
            body=b'FPCh'+struct.pack('>I4sII',1,b'Sop3',0x30008,1)+b'test\0'.ljust(28,b'\0')+struct.pack('>I',len(chunk))+chunk
            p.write_bytes(b'CcnK'+struct.pack('>I',len(body))+body)
            r=inspect(p,Path(td)/'out');self.assertEqual(r['chunks']['chunk']['size'],len(chunk));self.assertTrue(r['declared_size_matches'])
            p.write_bytes(p.read_bytes()[:-1])
            with self.assertRaises(ValueError):inspect(p,None)
    def test_audio_reference_is_non_silent_and_exact(self):
        r=compare(ROOT/'evidence/audio/satur-original-instructions.wav',ROOT/'evidence/audio/satur-cpp.wav',0.)
        self.assertTrue(r['passed']);self.assertEqual(r['max_abs_error'],0.)
    def test_silent_or_changed_audio_does_not_pass(self):
        raw=(ROOT/'evidence/audio/satur-original-instructions.wav').read_bytes();start=raw.index(b'data')+8
        with tempfile.TemporaryDirectory() as td:
            p=Path(td)/'silence.wav';p.write_bytes(raw[:start]+b'\0'*(len(raw)-start))
            self.assertFalse(compare(p,p,0.)['passed'])
            self.assertFalse(compare(ROOT/'evidence/audio/satur-original-instructions.wav',p,0.)['passed'])

if __name__=='__main__':unittest.main()
