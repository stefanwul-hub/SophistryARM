#!/usr/bin/env python3
"""Original GNFA member byte stream connected to original/native WAVE decode.

The native test is one C++ executable. The reference has two pinned i386 VMs:
WAVE raw I/O calls the unchanged archive-member code in its own VM. No WAV
extraction, header fixtures or decoded audio stubs bridge that boundary.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from compare_original_file_archive import ArchiveOracle,fixture,archive,op,pack,CORE,PATH,MEMBER,OUT,ARCHIVE_SHA,BUILTIN
from compare_original_wave import WaveOracle
from native_probe import NativeProbe
from legacy_image import SHA
from wave_fixtures import fixtures as wave_fixtures

def fixtures(builtin,wave):
    raw=builtin.read_bytes();assert hashlib.sha256(raw).hexdigest()==ARCHIVE_SHA
    for clone in [0,1]:
        for first,count in [(0,17),(77123,17),(176382,17),(0,176399)]:
            yield dict(name=f'builtin-wave-clone{clone}-first{first}-count{count}',raw=raw,h=[len(raw),2,clone,first,count,257,0,0])
        yield dict(name=f'builtin-plist-rejected-as-wave-clone{clone}',raw=raw,h=[len(raw),3,clone,0,17,257,0,0])
    for c in wave_fixtures(wave):
        name=c['name']
        if (name.startswith('pcm-') and '-frames257-extra0' in name
            or name.startswith('compressed-wave-tag') and name.endswith('-first1-count1')):
            for layout,clone in [(0,0),(1,1)]:
                raw=archive([('loops',b'',dict(length=0x8000000000000001)),('source.wav',c['raw'],dict(parent=1))],layout=layout)
                yield dict(name=f'archive-layout{layout}-clone{clone}-{name}',raw=raw,h=[len(raw),2,clone,c['h'][12],c['h'][13],c['h'][14],0,0])

class ArchiveWaveOracle(WaveOracle):
    def __init__(self,binary):super().__init__(binary);self.archive=ArchiveOracle(binary)
    def read_raw(self,wanted):
        a=self.archive;at=a.word(MEMBER+0x30);a.uc.mem_write(OUT,b'\xa5'*(wanted+32));a.put(OUT+0x110000,wanted);ok=a.call_reg(0xe4172,(MEMBER,OUT+16,OUT+0x110000));assert not a.error
        actual=a.word(OUT+0x110000);assert 0<=actual<=wanted;data=bytes(a.uc.mem_read(OUT+16,actual));self.record(2,at,wanted,actual,int(bool(ok)));self.reads+=1;return bool(ok),data
    def seek(self,*unused):
        obj,at=self.arguments(2);self.record(1,at);a=self.archive;a.call_reg(0xe440a,(MEMBER,at));assert not a.error;self.finish()
    def position(self,*unused):at=self.archive.word(MEMBER+0x30);self.record(3,at);self.finish(at)
    def length(self,*unused):a=self.archive;result=a.call_reg(0xe09c0,(PATH,));assert not a.error;self.record(4,result);self.finish(result)
    def execute_archive(self,c):
        h=c['h'];a=self.archive;a.execute(fixture('archive-wave-bridge',c['raw'],[op(9,h[1]),op(1)],clone=h[2]));assert not a.error
        # Raw bytes live only in the archive VM's source. This WAVE fixture
        # supplies no container bytes and no sample-derived metadata.
        wave_case=dict(raw=b'',h=[3,0,0,1,-1,-1,0,0,0,0,0,0,h[3],h[4],h[5],0])
        result=super().execute(wave_case)
        state=[a.word(CORE+0x10),a.word(MEMBER+0x30),a.word(MEMBER+0x34),a.positions[0],a.positions[1]]
        return result+pack(state)+pack([len(a.trace)])+b''.join(pack(row) for row in a.trace)

def compare(binary,runner,prefix,platform,builtin,wave):
    oracle=ArchiveWaveOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=0
    for c in fixtures(builtin,wave):
        try:expected=oracle.execute_archive(c)
        except Exception as e:raise RuntimeError(f'Original GNFA/WAVE failed at {c["name"]}: {e}') from e
        data=pack(c['h'])+c['raw'];actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA011-native');folder.mkdir(exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]:(folder/f'failing-archive-wave-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)))
            raise ValueError(f'Archive/WAVE mismatch {c["name"]} exit={actual.returncode} byte={at} expected={expected[at:at+24].hex()} native={actual.stdout[at:at+24].hex()}')
        total+=len(expected);cases.append(dict(name=c['name'],wave_status=struct.unpack_from('<i',expected)[0],archive_trace_events=len(oracle.archive.trace),wave_trace_events=len(oracle.trace),sha256=hashlib.sha256(expected).hexdigest(),all_bytes_match=True))
    probe.close();return dict(checkpoint='ELA011',original_i386_sha256=SHA,compiled_platform=platform,scope='GNFA member byte I/O feeding WAVE parser and PCM/MS/DVI decoders',fixture_count=len(cases),compared_bytes=total,all_cases_match_bit_for_bit=True,automatic_fixture_retries=0,reference_pinned_i386_vms=2,native_test_single_cpp_executable=True,wave_bytes_extracted_before_read=False,header_metadata_substituted=False,decoded_samples_substituted=False,builtin_original_archive_sha256=ARCHIVE_SHA,complete_builtin_wave_frames_compared=176399,actual_macos_execution=False,protected_user_bank_compatibility_verified=False,full_instrument_engine_built=False,audio_unit_validated=False,cases=cases)

if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--builtin',type=Path,default=BUILTIN);p.add_argument('--wave',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform,a.builtin,a.wave);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k] for k in ['fixture_count','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']},indent=2))
