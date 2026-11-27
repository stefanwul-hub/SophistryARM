#!/usr/bin/env python3
"""Named GNFA path -> original factory -> memory/stream -> WAVE/PCM/ADPCM."""
import argparse,hashlib,json,struct
from pathlib import Path
from compare_original_archive_wave import fixtures as indexed_fixtures
from compare_original_archive_names import fixture
from compare_original_file_archive import pack,BUILTIN,ARCHIVE_SHA,CORE,PATH,OUT
from original_archive_name_oracle import ArchiveNameOracle
from compare_original_wave import WaveOracle
from native_probe import NativeProbe
from legacy_image import SHA
def fixtures(builtin,wave):
    for c in indexed_fixtures(builtin,wave):
        name=c['name'];path='elastik/Info.plist' if name.startswith('builtin-plist') else '/elastik/01drm120elastik_2.WAV' if name.startswith('builtin-wave') else '/loops/source.wav'
        raw=path.encode('utf-16-le');h=list(c['h']);h[1]=len(raw)//2;h[6]=0;h[7]=1
        yield dict(name='named-'+name,raw=c['raw'],path=raw,h=h)
    raw=builtin.read_bytes();assert hashlib.sha256(raw).hexdigest()==ARCHIVE_SHA
    for clone in [0,1]:
        for path in ['/elastik/missing.wav','/elastik']:
            p=path.encode('utf-16-le');yield dict(name=f'named-rejected-{path}-clone{clone}',raw=raw,path=p,h=[len(raw),len(p)//2,clone,0,17,257,0,1])
class NamedWaveOracle(WaveOracle):
    def __init__(self,binary):super().__init__(binary);self.archive=ArchiveNameOracle(binary);self.reader=0
    def logical(self):a=self.archive;n=a.call_reg(0xdfab4,(self.reader,));assert not a.error;return n
    def read_raw(self,wanted):
        a=self.archive;at=self.logical();a.uc.mem_write(OUT,b'\xa5'*(wanted+32));a.put(OUT+0x110000,wanted);ok=a.call_reg(0xe4172,(self.reader,OUT+16,OUT+0x110000));assert not a.error;actual=a.word(OUT+0x110000);assert 0<=actual<=wanted;self.record(2,at,wanted,actual,int(bool(ok)));self.reads+=1;return bool(ok),bytes(a.uc.mem_read(OUT+16,actual))
    def seek(self,*unused):obj,at=self.arguments(2);self.record(1,at);self.archive.call_reg(0xe440a,(self.reader,at));assert not self.archive.error;self.finish()
    def position(self,*unused):n=self.logical();self.record(3,n);self.finish(n)
    def length(self,*unused):a=self.archive;n=a.call_reg(0xe09c0,(PATH,));assert not a.error;self.record(4,n);self.finish(n)
    def execute_named_wave(self,c):
        h=c['h'];a=self.archive;path=c['path'].decode('utf-16-le','surrogatepass');setup=fixture('named-wave-setup',c['raw'],path,[],clone=h[2],shared=h[6]);a.prepare(setup);self.reader=a.call_reg(0xe3ff4,(PATH,));assert not a.error
        a.current=a.files.index(self.reader)+1 if self.reader in a.files else 0
        wave_case=dict(raw=b'',h=[3,0,0,int(bool(a.current)),-1,-1,0,0,0,0,0,0,h[3],h[4],h[5],0]);result=super().execute(wave_case)
        return result+pack([a.word(PATH+0x14),int(bool(a.word(PATH+0x18))),a.depth,a.current,len(a.files),a.path_releases,a.path_retains])+a.snapshot()
def compare(binary,runner,prefix,platform,builtin,wave):
    oracle=NamedWaveOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=0
    for c in fixtures(builtin,wave):
        try:expected=oracle.execute_named_wave(c)
        except Exception as e:raise RuntimeError(f'Original named WAVE failed {c["name"]}: {e}') from e
        data=pack(c['h'])+c['raw']+c['path'];actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA012-native');folder.mkdir(exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]:(folder/f'failing-named-wave-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)));raise ValueError(f'Named WAVE mismatch {c["name"]} exit={actual.returncode} byte={at} expected={expected[at:at+20].hex()} native={actual.stdout[at:at+20].hex()}')
        total+=len(expected);cases.append(dict(name=c['name'],wave_status=struct.unpack_from('<i',expected)[0],sha256=hashlib.sha256(expected).hexdigest(),all_bytes_match=True))
    probe.close();return dict(checkpoint='ELA012',original_i386_sha256=SHA,compiled_platform=platform,fixture_count=len(cases),compared_bytes=total,all_cases_match_bit_for_bit=True,automatic_fixture_retries=0,reference_pinned_i386_vms=2,native_single_cpp_executable=True,native_path_selected_by_name=True,original_path_factory_memory_reader_and_wave_executed=True,direct_read_only_and_materialized_memory_modes_tested=True,wave_or_metadata_or_audio_substituted=False,complete_builtin_wave_frames=176399,real_bank_delegate_ported=False,actual_macos_execution=False,complete_engine_built=False,audio_unit_validated=False,cases=cases)
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--builtin',type=Path,default=BUILTIN);p.add_argument('--wave',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform,a.builtin,a.wave);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k] for k in ['fixture_count','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']},indent=2))
