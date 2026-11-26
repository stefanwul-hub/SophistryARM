#!/usr/bin/env python3
"""Actual Bash 3.2 core build orchestration: preserve original unit caches."""
from pathlib import Path
import argparse
import hashlib
import json
import os
import shutil
import subprocess
import tempfile

ROOT=Path(__file__).resolve().parents[1]


def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--bash',type=Path,default=Path('/bin/bash'))
    a=p.parse_args()
    baseline=(ROOT/'tests/fixtures/cronox-build-lifter-crx011.sh').read_text()
    with tempfile.TemporaryDirectory(prefix='CronoX original unit cache ') as temp:
        root=Path(temp)/'project with spaces'
        for d in ['scripts','src/lifter/cronox','tests']:(root/d).mkdir(parents=True)
        for s in ['scripts/derive-cronox-dispatch.py','src/lifter/CronoXHookPriority.h']:
            shutil.copyfile(ROOT/s,root/s)
        (root/'src/lifter/LifterRuntime.h').write_text('// runtime ABI fixture, unchanged\n')
        (root/'src/lifter/LifterRuntime.cpp').write_text('// runtime fixture\n')
        source=root/'src/lifter/cronox'
        (source/'manifest.json').write_text('{}\n')
        original=(ROOT/'src/lifter/cronox/Dispatch.cpp').read_text()
        (source/'Dispatch.cpp').write_text(original)
        for name in ['Unit0000.cpp','Unit0001.cpp']:(source/name).write_text('// original unit fixture\n')
        script=root/'scripts/build-lifter-chunks.sh';script.write_text(baseline)
        log=root/'commands.jsonl';compiler=root/'fake-compiler'
        compiler.write_text('''#!/usr/bin/env python3
import json,os,sys
from pathlib import Path
if '--version' in sys.argv:print('fixed compiler identity')
else:
 with open(os.environ['CRX_COMPILER_LOG'],'a') as f:f.write(json.dumps(sys.argv[1:])+'\\n')
 Path(sys.argv[sys.argv.index('-o')+1]).write_bytes(b'Object/link fixture only\\n')
''');compiler.chmod(0o755)
        env=dict(os.environ,CXX=str(compiler),CRX_COMPILER_LOG=str(log),CRONOX_BUILD_JOBS='2')
        def run():
            log.write_text('');subprocess.run([str(a.bash),str(script)],env=env,check=True,stdout=subprocess.DEVNULL)
            rows=[json.loads(line) for line in log.read_text().splitlines()]
            return sorted(Path(row[row.index('-c')+1]).name for row in rows if '-c' in row)
        assert run()==['Dispatch.cpp','LifterRuntime.cpp','Unit0000.cpp','Unit0001.cpp']
        old_keys={p.name:p.read_bytes() for p in (root/'work/cronox-core').glob('*.compile.sha256')}
        script.write_text((ROOT/'scripts/build-lifter-chunks.sh').read_text())
        assert run()==['Dispatch.cpp'],'Runtime/units rebuilt when only entry selection changed'
        for p in (root/'work/cronox-core').glob('*.compile.sha256'):
            if p.name!='Dispatch.o.compile.sha256':assert p.read_bytes()==old_keys[p.name]
        assert run()==[],'Repeat build lost its cache'
        helper=root/'src/lifter/CronoXHookPriority.h';helper.write_text(helper.read_text()+'\n// dependency change\n')
        assert run()==['Dispatch.cpp'],'Helper dependency did not isolate dispatcher'
        unit=source/'Unit0001.cpp';unit.write_text(unit.read_text()+'// source change\n')
        assert run()==['Unit0001.cpp']
        assert (source/'Dispatch.cpp').read_text()==original,'Pinned source edited'
        assert hashlib.sha256((source/'Dispatch.cpp').read_bytes()).digest()==hashlib.sha256((ROOT/'src/lifter/cronox/Dispatch.cpp').read_bytes()).digest()
    print(json.dumps({'passed':True,'shell':subprocess.check_output([str(a.bash),'--version'],text=True).splitlines()[0],
                      'old_unit_and_runtime_keys_preserved':True,'only_dispatcher_recompiled':True,
                      'repeat_build_recompiles_zero_objects':True,'helper_invalidates_only_dispatcher':True,
                      'generated_original_sources_unchanged':True,'compiler_is_fixture_not_macos_validation':True}))


if __name__=='__main__':main()
