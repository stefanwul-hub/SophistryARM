#!/usr/bin/env python3
"""Exercise the actual AU build script's shell/argv/cache logic with fake Apple tools.

This is a build orchestration regression, never a macOS, DSP, signing or AU test.
Use --bash with a Bash 3.2 binary to cover the shell shipped with macOS.
"""
from pathlib import Path
import argparse
import json
import os
import shlex
import shutil
import subprocess
import tempfile


DRIVER = r'''#!/usr/bin/env python3
from pathlib import Path
import json,os,plistlib,shutil,sys
name=Path(sys.argv[0]).name;args=sys.argv[1:]
with open(os.environ['CRX_FIXTURE_LOG'],'a') as f:
 f.write(json.dumps({'tool':name,'args':args})+'\n')
root=Path(os.environ['CRX_FIXTURE_ROOT'])
if name=='uname':
 print({'-s':'Darwin','-m':'arm64'}[args[0]])
elif name=='xcrun':
 assert args.pop(0)=='clang++'
 assert all(args),'Empty compiler argument'
 if '--version' in args:print('Apple compiler fixture, not a native compiler')
 else:
  assert '-arch' in args and args[args.index('-arch')+1]=='arm64'
  assert '-mmacosx-version-min=11.0' in args
  if '-c' in args:
   source=Path(args[args.index('-c')+1]);assert source.is_file()
   assert ('-fobjc-arc' in args)==(source.suffix=='.mm'),'Incorrect ARC flags'
   assert '-fno-fast-math' in args and '-ffp-contract=off' in args
  output=Path(args[args.index('-o')+1]);output.parent.mkdir(parents=True,exist_ok=True)
  output.write_bytes(b'Build fixture only: this is NOT an Audio Unit.\n')
elif name=='ditto':shutil.copytree(args[0],args[1],dirs_exist_ok=True)
elif name=='plutil':
 with open(args[-1],'rb') as f:assert plistlib.load(f)['CFBundleIdentifier']=='com.linplug.au.CronoX3.ARMTest'
elif name=='lipo':
 assert Path(args[0]).is_file() and args[-1]=='arm64'
elif name=='nm':
 for symbol in (root/'src/au/CronoX3ARMTest.exports').read_text().splitlines():
  print('00000000 T '+symbol)
elif name=='codesign':
 assert Path(args[-1],'Contents/MacOS/CronoX3ARMTest').is_file()
else:raise RuntimeError('Unexpected fixture tool: '+name)
'''


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--bash', type=Path, default=Path('/bin/bash'))
    parser.add_argument('--baseline', type=Path,
                        help='Optional CRX002 build script; must reproduce the empty-array failure')
    options = parser.parse_args()
    shell = options.bash.resolve()
    root = Path(__file__).resolve().parents[1]
    version = subprocess.check_output([str(shell), '--version'], text=True).splitlines()[0]
    with tempfile.TemporaryDirectory(prefix='CronoX shell fixture ') as temporary:
        project = Path(temporary) / 'source with spaces'
        tools = project / 'tools'
        tools.mkdir(parents=True)
        for directory in ['scripts', 'src/au', 'src/engine', 'config',
                          'third_party/AudioUnitSDK/include',
                          'third_party/AudioUnitSDK/src/AudioUnitSDK',
                          'reference/Presets', 'reference/Samples']:
            (project / directory).mkdir(parents=True, exist_ok=True)
        for name in ['scripts/generate-cronox-au-identity.py',
                     'scripts/verify-cronox-bundle.py', 'config/au-identity-test.json',
                     'src/au/CronoX3ARMTestAU.cpp', 'src/au/CronoX3ARMTestEditor.mm',
                     'src/au/CronoX3ARMTest.exports', 'third_party/AudioUnitSDK/LICENSE.txt']:
            shutil.copyfile(root / name, project / name)
        for path in (root / 'third_party/AudioUnitSDK/src/AudioUnitSDK').glob('*.cpp'):
            shutil.copyfile(path, project / 'third_party/AudioUnitSDK/src/AudioUnitSDK' / path.name)
        for directory in ['src/au', 'src/engine', 'third_party/AudioUnitSDK/include']:
            (project / directory / 'fixture.h').write_text('// Header dependency fixture\n')
        for directory in ['reference/Presets', 'reference/Samples']:
            (project / directory / 'fixture.txt').write_text('Resource copy fixture\n')
        (project / 'scripts/build-cronox-engine.sh').write_text('''#!/bin/bash
set -eu
mkdir -p "$1" "$2"
for name in LegacyEngine LegacyImageData; do printf 'host fixture' > "$1/$name.o"; done
for name in LifterRuntime Dispatch Unit0000; do printf 'core fixture' > "$2/$name.o"; done
''')
        driver = tools / 'driver.py'
        driver.write_text(DRIVER)
        driver.chmod(0o755)
        for name in ['uname', 'xcrun', 'ditto', 'plutil', 'lipo', 'nm', 'codesign']:
            (tools / name).symlink_to(driver)
        (tools / 'bash').symlink_to(shell)
        log = project / 'commands.jsonl'
        env = dict(os.environ, PATH=str(tools) + os.pathsep + os.environ.get('PATH', ''),
                   CRX_FIXTURE_ROOT=str(project), CRX_FIXTURE_LOG=str(log))
        script = project / 'scripts/build-cronox-audio-unit.sh'

        def install_script(content):
            # Only redirect absolute Apple tool locations into the fixture.
            # All array handling, flags, hashing, loops and cache logic stay intact.
            for name in ['xcrun', 'ditto', 'plutil', 'lipo', 'nm', 'codesign']:
                content = content.replace('/usr/bin/' + name, shlex.quote(str(tools / name)))
            script.write_text(content)

        def run():
            return subprocess.run([str(shell), str(script)], env=env,
                                  text=True, stdout=subprocess.PIPE,
                                  stderr=subprocess.STDOUT, timeout=90)

        reproduced = False
        if options.baseline:
            install_script(options.baseline.read_text())
            result = run()
            assert result.returncode != 0 and 'extra[*]: unbound variable' in result.stdout, result.stdout
            reproduced = True
        install_script((root / 'scripts/build-cronox-audio-unit.sh').read_text())
        log.write_text('')
        cold = run()
        assert cold.returncode == 0, cold.stdout

        def compilations():
            return [x for x in map(json.loads, log.read_text().splitlines())
                    if x['tool'] == 'xcrun' and '-c' in x['args']]

        calls = compilations()
        expected = len(list((project / 'third_party/AudioUnitSDK/src/AudioUnitSDK').glob('*.cpp'))) + 2
        assert len(calls) == expected, calls
        assert sum('-fobjc-arc' in x['args'] for x in calls) == 1
        assert all(all(x['args']) for x in calls)
        log.write_text('')
        warm = run()
        assert warm.returncode == 0 and not compilations(), warm.stdout
        changed = project / 'src/au/CronoX3ARMTestAU.cpp'
        changed.write_text(changed.read_text() + '\n// Source cache invalidation fixture\n')
        log.write_text('')
        rebuild = run()
        assert rebuild.returncode == 0, rebuild.stdout
        rebuilt = compilations()
        assert len(rebuilt) == 1 and str(changed) in rebuilt[0]['args'], rebuilt
    print(json.dumps({'scope': 'Build shell orchestration with mocked Apple tools only',
                      'bash': version, 'baseline_failure_reproduced': reproduced,
                      'cold_compilation_units': expected, 'cpp_and_objcpp_flags_preserved': True,
                      'empty_compiler_arguments': 0, 'paths_with_spaces_passed': True,
                      'warm_object_cache_reused': True, 'single_source_invalidation_passed': True,
                      'macos_execution': False, 'auval_executed': False, 'passed': True}))


if __name__ == '__main__':
    main()
