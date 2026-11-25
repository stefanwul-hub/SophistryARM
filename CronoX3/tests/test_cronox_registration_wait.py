import importlib.util
import json
from pathlib import Path
import subprocess
import tempfile
import unittest

MODULE=Path(__file__).resolve().parents[1]/'scripts/wait-cronox-registration.py'
spec=importlib.util.spec_from_file_location('cronox_registration_wait',MODULE)
module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)

class RegistrationWaitTests(unittest.TestCase):
    def run_wait(self,codes,timeout=6,payload=None):
        elapsed=[0.0];calls=[]
        def runner(command,**kwargs):
            calls.append(command)
            code=codes[min(len(calls)-1,len(codes)-1)]
            if code==124:raise subprocess.TimeoutExpired(command,kwargs['timeout'])
            data=payload if payload is not None else {'passed':code==0,'subtype':'CrT3','registered_matches':1 if code==0 else 0}
            return subprocess.CompletedProcess(command,code,json.dumps(data).encode(),b'')
        with tempfile.TemporaryDirectory() as d:
            result=module.wait_for_registration(Path('/test/probe'),Path(d),timeout,runner,
                lambda:elapsed[0],lambda seconds:elapsed.__setitem__(0,elapsed[0]+seconds))
            files=sorted(p.name for p in Path(d).iterdir())
        return result,calls,elapsed[0],files

    def test_delayed_registration_and_stale_build_are_retried_in_fresh_processes(self):
        result,calls,elapsed,files=self.run_wait([3,5,0])
        self.assertTrue(result['passed']);self.assertEqual(len(calls),3)
        self.assertEqual(elapsed,4);self.assertEqual(len(files),6)

    def test_missing_component_reaches_bounded_deadline(self):
        result,calls,elapsed,_=self.run_wait([3])
        self.assertFalse(result['passed']);self.assertEqual(elapsed,6);self.assertEqual(len(calls),3)

    def test_duplicate_and_factory_errors_are_not_retried(self):
        for code in (4,6):
            with self.subTest(code=code):
                result,calls,_,_=self.run_wait([code,0]);self.assertFalse(result['passed']);self.assertEqual(len(calls),1)

    def test_fake_success_without_positive_expected_identity_is_rejected(self):
        for payload in ([],{'passed':True,'subtype':'CrX3','registered_matches':1},{'passed':True,'subtype':'CrT3','registered_matches':2}):
            with self.subTest(payload=payload):
                result,calls,_,_=self.run_wait([0],payload=payload);self.assertFalse(result['passed']);self.assertEqual(len(calls),1)

    def test_probe_timeout_is_reported_without_retrying(self):
        result,calls,_,_=self.run_wait([124,0]);self.assertFalse(result['passed']);self.assertEqual(len(calls),1)
        self.assertEqual(result['attempts'][0]['exit_code'],124)

if __name__=='__main__':unittest.main()
