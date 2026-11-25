import contextlib
import importlib.util
import io
import json
import os
from pathlib import Path
import plistlib
import shlex
import subprocess
import tempfile
import types
import unittest
from unittest.mock import patch

ROOT=Path(__file__).resolve().parents[1]
spec=importlib.util.spec_from_file_location('cronox_diagnostics',ROOT/'scripts/diagnose-cronox-registration.py')
module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)


class DiagnosticPortabilityTests(unittest.TestCase):
    def test_missing_python_xattr_api_uses_native_names_only(self):
        with patch.object(module,'os',types.SimpleNamespace()), patch.object(module,'command',return_value={'exit_code':0,'stdout':'com.apple.quarantine\ncom.apple.provenance\n'}) as command:
            self.assertTrue(module.quarantine_present(Path('/fixture.component')))
            command.assert_called_once_with(['/usr/bin/xattr','/fixture.component'],limit=5)

    def test_absent_quarantine_and_failed_native_query_are_distinct(self):
        for response,expected in [({'exit_code':0,'stdout':'com.apple.provenance\n'},False),({'exit_code':1},None),({'error':'TimeoutExpired'},None)]:
            with self.subTest(response=response),patch.object(module,'os',types.SimpleNamespace()),patch.object(module,'command',return_value=response):
                self.assertIs(module.quarantine_present(Path('/fixture.component')),expected)

    def test_present_python_api_does_not_need_external_tool(self):
        with patch.object(module,'os',types.SimpleNamespace(listxattr=lambda path:['com.apple.quarantine'])),patch.object(module,'command') as command:
            self.assertTrue(module.quarantine_present(Path('/fixture.component')));command.assert_not_called()

    def test_full_collector_runs_without_os_listxattr(self):
        with tempfile.TemporaryDirectory() as temporary:
            bundle=Path(temporary)/'CronoX 3 ARM Test.component';(bundle/'Contents/MacOS').mkdir(parents=True)
            (bundle/'Contents/MacOS/CronoX3ARMTest').write_bytes(b'fixture')
            (bundle/'Contents/Info.plist').write_bytes(plistlib.dumps({'CFBundleIdentifier':'com.linplug.au.CronoX3.ARMTest','CFBundleExecutable':'CronoX3ARMTest','CFBundleVersion':'5001','AudioComponents':[]}))
            output=io.StringIO()
            def command(args,limit=15):
                text='com.apple.provenance\n' if args[0].endswith('/xattr') else 'aumu CrT3 LinP CronoX 3 ARM Test\naumu Other Other Plugin\n'
                return {'exit_code':0,'stdout':text,'stderr':''}
            with patch.object(module,'os',types.SimpleNamespace()),patch.object(module,'TARGET',bundle),patch.object(module,'command',side_effect=command),patch.object(module.sys,'platform','darwin'),patch.object(module.sys,'argv',['diagnose']),contextlib.redirect_stdout(output):
                self.assertEqual(module.main(),0)
            report=json.loads(output.getvalue());self.assertTrue(report['read_only'])
            self.assertNotIn('Other Plugin',report['cronox_catalogue']['stdout'])
            target=next(p for p in report['paths'] if p['path']==str(bundle))
            self.assertIs(target['quarantine_present'],False)


class InstallerValidationFlowTests(unittest.TestCase):
    def flow(self,installer,diagnostic=1,discovery=0,auval=0):
        # Exercise the actual installer block; only the Python executable is
        # redirected to inject process outcomes. No system folders are touched.
        source=(ROOT/installer).read_text()
        first=source.index("stage='détection du composant installé'")
        last=source.index('auval_passed=1',first)+len('auval_passed=1')
        block=source[first:last]
        with tempfile.TemporaryDirectory(prefix='CronoX validation flow ') as temporary:
            base=Path(temporary);report=base/'report';report.mkdir();calls=base/'calls.jsonl'
            fake=base/'python fixture';fake.write_text('''#!/usr/bin/env python3
import json,os,sys
from pathlib import Path
name=Path(sys.argv[1]).name
with open(os.environ['FLOW_CALLS'],'a') as f:f.write(json.dumps(name)+'\\n')
key='FLOW_DIAGNOSTIC' if name.startswith('diagnose-') else 'FLOW_DISCOVERY' if name.startswith('wait-') else 'FLOW_AUVAL'
code=int(os.environ[key])
print(json.dumps({'fixture':name,'exit_code':code}))
if code:print('injected process failure',file=sys.stderr)
sys.exit(code)
''');fake.chmod(0o755)
            block=block.replace('/usr/bin/python3',shlex.quote(str(fake)))
            script=base/'flow.command';script.write_text('set -euo pipefail\nROOT='+shlex.quote(str(base))+'\nREPORT='+shlex.quote(str(report))+'\nBUILD='+shlex.quote(str(base))+'\n'+block+'\nprintf completed > "$REPORT/completed"\n')
            env=dict(os.environ,FLOW_CALLS=str(calls),FLOW_DIAGNOSTIC=str(diagnostic),FLOW_DISCOVERY=str(discovery),FLOW_AUVAL=str(auval))
            result=subprocess.run([os.environ.get('CRONOX_TEST_BASH','/bin/bash'),str(script)],env=env,stdout=subprocess.PIPE,stderr=subprocess.PIPE,timeout=15)
            names=[json.loads(line) for line in calls.read_text().splitlines()]
            return result.returncode,(report/'completed').exists(),names

    def test_crx004_collector_failure_reproduces_premature_abort(self):
        code,completed,names=self.flow('Installer-CronoX-CRX004.command')
        self.assertNotEqual(code,0);self.assertFalse(completed)
        self.assertEqual(names,['diagnose-cronox-registration.py'])

    def test_crx005_diagnostic_failure_does_not_skip_discovery_or_auval(self):
        code,completed,names=self.flow('Installer-CronoX-CRX005.command')
        self.assertEqual(code,0);self.assertTrue(completed)
        self.assertIn('wait-cronox-registration.py',names);self.assertIn('run-cronox-auval.py',names)

    def test_crx006_keeps_mandatory_registration_and_validation_checks(self):
        for discovery,auval,success in [(0,0,True),(3,0,False),(0,2,False)]:
            with self.subTest(discovery=discovery,auval=auval):
                code,completed,names=self.flow('Installer-CronoX-CRX006.command',discovery=discovery,auval=auval)
                self.assertEqual(code==0,success)
                self.assertIn('wait-cronox-registration.py',names)
                if discovery==0:self.assertIn('run-cronox-auval.py',names)

    def test_required_discovery_failure_still_aborts(self):
        code,completed,names=self.flow('Installer-CronoX-CRX005.command',discovery=3)
        self.assertNotEqual(code,0);self.assertFalse(completed)
        self.assertNotIn('run-cronox-auval.py',names)

    def test_required_auval_failure_still_aborts(self):
        code,completed,names=self.flow('Installer-CronoX-CRX005.command',auval=2)
        self.assertNotEqual(code,0);self.assertFalse(completed)
        self.assertIn('run-cronox-auval.py',names)


if __name__=='__main__':unittest.main()
