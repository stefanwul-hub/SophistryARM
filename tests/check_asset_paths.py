#!/usr/bin/env python3
"""Exercise nested banks, legacy path suffixes, root precedence and ambiguity."""
import argparse
import json
from pathlib import Path
import shutil
import subprocess
import tempfile

ROOT=Path(__file__).resolve().parents[1]

def run(probe,output):
    sample=ROOT/'reference/Samples/BT_cronox18.wav'
    state=ROOT/'reference/Presets/Lightgarden 02 BT.aupreset'
    cases=[]
    with tempfile.TemporaryDirectory(prefix='asset-paths-',dir=ROOT/'work') as temporary:
        root=Path(temporary)
        def check(name,directories,expected_error=None):
            prefix=root/name
            command=[str(probe.resolve()),'--state',str(state),'--recursive-assets','--output-prefix',str(prefix),'--snapshots']
            for directory in directories:command.extend(['--asset-directory',str(directory)])
            process=subprocess.run(command,stdout=subprocess.PIPE,stderr=subprocess.PIPE,text=True)
            report=json.loads(prefix.with_suffix('.json').read_text())
            if expected_error:
                assert process.returncode!=0 and expected_error in report['error'],(name,report)
                cases.append({'case':name,'ambiguous_sample_refused':True})
                return None
            assert process.returncode==0 and report['error'] is None,(name,report)
            result={ext:prefix.with_suffix('.'+ext).read_bytes() for ext in ['object','heap','globals','chunk']}
            cases.append({'case':name,'state_restored':True})
            return result
        baseline=check('baseline',[sample.parent])
        nested=root/'nested/A/B';nested.mkdir(parents=True);shutil.copy2(sample,nested/sample.name)
        assert check('nested-bank',[root/'nested'])==baseline
        ambiguous=root/'ambiguous'
        for child in ['A','B']:
            folder=ambiguous/child;folder.mkdir(parents=True);shutil.copy2(sample,folder/sample.name)
        check('duplicate-basename',[ambiguous],expected_error='Several samples share this name')
        matching=root/'matching'
        for child in ['Samples','Other']:(matching/child).mkdir(parents=True)
        shutil.copy2(sample,matching/'Samples'/sample.name)
        (matching/'Other'/sample.name).write_bytes(b'Deliberately invalid audio: this candidate must not be selected')
        assert check('legacy-Samples-suffix',[matching])==baseline
        fallback=root/'fallback';fallback.mkdir();(fallback/sample.name).write_bytes(b'Invalid fallback: selected bank takes precedence')
        assert check('explicit-bank-before-fallback',[root/'nested',fallback])==baseline
    result={'scope':'Public fixture only, native host without licence/preferences; decoded guest object/heap/globals/program compared strictly','passed':True,'cases':cases,'private_inputs_used':False}
    output.parent.mkdir(parents=True,exist_ok=True);output.write_text(json.dumps(result,indent=2)+'\n');return result

if __name__=='__main__':
    parser=argparse.ArgumentParser();parser.add_argument('--probe',type=Path,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();print(json.dumps(run(args.probe,args.output),indent=2))
