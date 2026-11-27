#!/usr/bin/env python3
"""Compare original path-based GNFA opening and memory/direct readers."""
import argparse,hashlib,itertools,json,struct
from pathlib import Path
from compare_original_file_archive import archive,op,pack,BUILTIN,ARCHIVE_SHA
from original_archive_name_oracle import ArchiveNameOracle
from native_probe import NativeProbe
from legacy_image import SHA

def fixture(name,raw,path,ops,*,index=0,clone=0,clone_ok=1,shared=0,opened=1,delegate=0):
    encoded=(path or '').encode('utf-16-le','surrogatepass');h=[len(raw),len(encoded)//2,int(path is not None),index,clone,clone_ok,shared,opened,delegate,len(ops),0,0,0,0,0,0]
    return dict(name=name,raw=raw,path=encoded,h=h,ops=ops)
def graph(layout):
    return archive([('root',b'',dict(length=0x8000000000000001)),('Pads',b'',dict(length=0x8000000000000001,parent=1)),('Tone.wav',bytes(range(64)),dict(parent=2,field6=0x11223344,field7=0xaabbccdd)),('empty',b'',dict(parent=1)),('.',b'period',dict(parent=1)),('..',b'double',dict(parent=5)),('éclair',b'accent',dict(parent=1)),('東京',b'japan',dict(parent=1)),('\U0001f3b9',b'piano',dict(parent=1)),('x',b'one',dict(parent=1)),('a/b',b'slash',dict(parent=1)),('same',b'first',dict(parent=1)),('same',b'second',dict(parent=1))],layout=layout)
def fixtures(builtin):
    paths=[None,'','/','//','////','r','root','/root/','root/Pads/Tone.wav','/root//Pads///Tone.wav/','root/pads/Tone.wav','ROOT/Pads/Tone.wav','root/Pads/missing.wav','missing/root','root/empty','root/./..','root/../Tone.wav','root/éclair','root/東京','root/\U0001f3b9','root/x','root/a/b','root/same','root/\ud800\udfff','root/\0\0']
    sequence=[op(1),op(8),op(9),op(2),op(4,17),op(7),op(5,1),op(4,7),op(6),op(7),op(4,1),op(2),op(7)]
    for layout in [0,1]:
        raw=graph(layout)
        for path,oldindex,(clone,shared) in itertools.product(paths,[0,3],[(0,0),(1,0),(1,1)]):
            label='none' if path is None else path.encode('unicode_escape').decode()
            yield fixture(f'lookup-layout{layout}-path{label}-index{oldindex}-clone{clone}-shared{shared}',raw,path,sequence,index=oldindex,clone=clone,shared=shared)
    for layout in [0,1]:
        raw=graph(layout)
        for clone,clone_ok,opened,delegate in itertools.product([0,1],[0,1],[0,1],[0,1,2]):
            yield fixture(f'factory-layout{layout}-clone{clone}-ok{clone_ok}-open{opened}-delegate{delegate}',raw,'root/Pads/Tone.wav',[op(2),op(8),op(9)],clone=clone,clone_ok=clone_ok,opened=opened,delegate=delegate)
        for maximum,ok in itertools.product([-4,-1,0,1,17],[0,1]):
            yield fixture(f'factory-read-result-layout{layout}-max{maximum}-ok{ok}',raw,'root/Pads/Tone.wav',[op(12,maximum,ok),op(2),op(3,1),op(7),op(4,17)],delegate=1)
        for initial in [0,3]:
            yield fixture(f'resolve-failure-retry-layout{layout}-index{initial}',raw,'root/Pads/missing.wav',[op(1),op(1),op(10,initial,1),op(1),op(2)],index=initial)
            yield fixture(f'closed-then-open-layout{layout}-index{initial}',raw,'root/Pads/Tone.wav',[op(2),op(11,1),op(2),op(4,17),op(10,0,1),op(1),op(2)],index=initial,opened=0)
    raw=builtin.read_bytes();assert hashlib.sha256(raw).hexdigest()==ARCHIVE_SHA
    for path in ['elastik/01drm120elastik_2.WAV','/elastik//01drm120elastik_2.WAV/','elastik/Info.plist','elastik/missing.wav']:
        for clone in [0,1]:yield fixture(f'builtin-named-{path}-clone{clone}',raw,path,[op(8),op(2),op(4,17),op(7),op(6),op(4,1)],clone=clone)

def serialized(c):return pack(c['h'])+c['raw']+c['path']+b''.join(pack(o) for o in c['ops'])
def compare(binary,runner,prefix,platform,builtin):
    oracle=ArchiveNameOracle(binary);probe=NativeProbe(prefix+[str(runner.resolve())],persistent=True);cases=[];total=0
    for c in fixtures(builtin):
        try:expected=oracle.execute_named(c)
        except Exception as e:raise RuntimeError(f'Original named archive failed {c["name"]}: {e}') from e
        data=serialized(c);actual=probe.run(data,len(expected))
        if actual.returncode or actual.stdout!=expected:
            folder=Path('work/ELA012-native');folder.mkdir(exist_ok=True)
            for label,b in [('fixture',data),('original',expected),('native',actual.stdout),('stderr',actual.stderr)]:(folder/f'failing-archive-name-{label}.bin').write_bytes(b)
            at=next((i for i,(a,b) in enumerate(zip(expected,actual.stdout)) if a!=b),min(len(expected),len(actual.stdout)));raise ValueError(f'Named archive mismatch {c["name"]}: exit={actual.returncode} byte={at} expected={expected[at:at+20].hex()} native={actual.stdout[at:at+20].hex()}')
        total+=len(expected);cases.append(dict(name=c['name'],trace_events=len(oracle.trace),sha256=hashlib.sha256(expected).hexdigest(),all_bytes_match=True))
    probe.close();return dict(checkpoint='ELA012',original_i386_sha256=SHA,compiled_platform=platform,fixture_count=len(cases),compared_bytes=total,all_cases_match_bit_for_bit=True,automatic_fixture_retries=0,original_path_lookup_executed=True,original_GNString_split_hash_compare_executed=True,original_GNString_encoding0_conversion_executed=True,original_read_file_factory_executed=True,original_memory_file_reader_executed=True,boundaries_adapted=['GN object/string storage constructors and array primitives','raw allocation','GN references/data primitives','underlying byte I/O and clone','GN exception to status'],native_GNString_primitives_still_runtime_bindings=True,real_bank_delegate_ported=False,actual_macos_execution=False,complete_engine_built=False,audio_unit_validated=False,cases=cases)
if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('binary',type=Path);p.add_argument('runner',type=Path);p.add_argument('--runner-prefix',action='append',default=[]);p.add_argument('--platform',required=True);p.add_argument('--builtin',type=Path,default=BUILTIN);p.add_argument('--output',type=Path,required=True);a=p.parse_args();r=compare(a.binary,a.runner,a.runner_prefix,a.platform,a.builtin);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(r,indent=2)+'\n');print(json.dumps({k:r[k] for k in ['fixture_count','compared_bytes','all_cases_match_bit_for_bit','compiled_platform']},indent=2))
