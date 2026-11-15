import contextlib
import importlib.util
import io
import json
from pathlib import Path
import subprocess
import tempfile
import unittest
from unittest.mock import patch

path=Path(__file__).resolve().parents[1]/'scripts/run_auval.py'
spec=importlib.util.spec_from_file_location('run_auval',path)
runner=importlib.util.module_from_spec(spec);spec.loader.exec_module(runner)

class AuvalRunnerTests(unittest.TestCase):
    def invoke(self,operation):
        with tempfile.TemporaryDirectory() as directory:
            output=io.StringIO()
            with patch.object(runner.sys,'platform','darwin'),patch.object(runner.sys,'argv',['run_auval.py','--log',str(Path(directory)/'auval.log')]),patch.object(runner.subprocess,'run',side_effect=operation) as execute,contextlib.redirect_stdout(output):
                result=runner.main()
            self.assertEqual(execute.call_args.args[0],['/usr/bin/auval','-v','aumu','Sop3','LinP'])
            return result,json.loads(output.getvalue())

    def test_success_status_is_recorded(self):
        code,result=self.invoke(lambda *args,**kwargs:subprocess.CompletedProcess(args[0],0))
        self.assertEqual(code,0);self.assertTrue(result['passed'])

    def test_failure_status_cannot_be_treated_as_success(self):
        code,result=self.invoke(lambda *args,**kwargs:subprocess.CompletedProcess(args[0],2))
        self.assertNotEqual(code,0);self.assertFalse(result['passed']);self.assertEqual(result['exitcode'],2)

    def test_timeout_cannot_be_treated_as_success(self):
        def timeout(*args,**kwargs):raise subprocess.TimeoutExpired(args[0],180)
        code,result=self.invoke(timeout)
        self.assertNotEqual(code,0);self.assertFalse(result['passed']);self.assertTrue(result['timed_out']);self.assertEqual(result['exitcode'],124)

if __name__=='__main__':unittest.main()
