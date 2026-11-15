"""Exercise the actual installer failure handler with private temporary fixtures.

No Mac preferences, administrator commands or system components are accessed.
"""
import json
import os
from pathlib import Path
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]


class SettingsRetentionTests(unittest.TestCase):
    def failure(self, confirmed, committed=0, auval=0, audio=0, local_editor=0, remote_editor=0):
        source = (ROOT / 'Installer-ARM64.command').read_text()
        handler = 'collect(){' + source.split('collect(){', 1)[1].split('\ntrap collect EXIT', 1)[0]
        # Platform presentation/packaging only; the rollback decision and
        # ConfigureSophistry invocation remain the production handler.
        handler = handler.replace('/usr/bin/open', 'true').replace('/usr/bin/zip', 'true')
        with tempfile.TemporaryDirectory() as temp:
            base = Path(temp)
            (base / 'bin').mkdir()
            (base / 'report').mkdir()
            (base / 'Preferences-privees-avant-installation.plist').write_bytes(b'private fixture')
            setup = base / 'bin/ConfigureSophistry'
            setup.write_text('#!/bin/bash\nprintf restored > "$PRIVATE/called"\nprintf \'{"preferences_restored":true}\\n\'\n')
            setup.chmod(0o700)
            env = dict(os.environ, PRIVATE=temp, ROOT=temp, REPORT=str(base / 'report'),
                       CORE=str(base / 'core'), BUILD=str(base / 'build'))
            run = subprocess.run(
                ['bash', '-c',
                 f'settings_confirmed={confirmed};committed={committed};'
                 f'auval_passed={auval};registered_audio_passed={audio};'
                 f'editor_local_passed={local_editor};remote_host_passed={remote_editor};'
                 'installation_started=0;stage=test;STAMP=test;TRANSACTION=test;\n'
                 + handler + '\nfalse\ncollect\n'],
                env=env, capture_output=True, text=True)
            self.assertEqual(run.returncode, 1, run.stderr)
            result = json.loads((base / 'report/result.json').read_text())
            return (base / 'called').exists(), result

    def test_auval_failure_keeps_fresh_process_validated_settings(self):
        restored, result = self.failure(1)
        self.assertFalse(restored)
        self.assertTrue(result['validated_settings_retained'])
        self.assertFalse(result['system_installation_committed'])

    def test_unvalidated_configuration_is_restored(self):
        restored, result = self.failure(0)
        self.assertTrue(restored)
        self.assertFalse(result['validated_settings_retained'])
        self.assertTrue(result['rollback_completed_if_needed'])

    def test_committed_installation_keeps_settings(self):
        restored, result = self.failure(1, committed=1)
        self.assertFalse(restored)
        self.assertTrue(result['system_installation_committed'])

    def test_remote_editor_failure_reports_previous_successful_checks(self):
        restored, result = self.failure(1, auval=1, audio=1, local_editor=1)
        self.assertFalse(restored)
        self.assertFalse(result['system_installation_committed'])
        self.assertTrue(result['auval_and_registered_audio_passed'])
        self.assertTrue(result['local_editor_and_audio_passed'])
        self.assertFalse(result['remote_host_view_and_audio_passed'])
        self.assertEqual(result['script_exitcode'], 1)

    def test_preflight_failure_cannot_report_registered_audio_success(self):
        _, result = self.failure(1, local_editor=1)
        self.assertFalse(result['auval_and_registered_audio_passed'])


if __name__ == '__main__':
    unittest.main()
