import importlib.util
import os
from pathlib import Path
import plistlib
import shutil
import tempfile
import unittest
from unittest.mock import patch

MODULE = Path(__file__).resolve().parents[1] / 'scripts/cronox_component_transaction.py'
spec = importlib.util.spec_from_file_location('cronox_component_transaction', MODULE)
transaction = importlib.util.module_from_spec(spec)
spec.loader.exec_module(transaction)


class ComponentTransactionTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        self.target = self.root / 'Components/CronoX 3 ARM Test.component'
        self.target.parent.mkdir()
        self.source = self.root / 'Build/CronoX 3 ARM Test.component'
        self.bundle(self.source, b'new native binary')
        self.checksum = transaction.file_hash(self.source / 'Contents/MacOS/CronoX3ARMTest')
        self.identifier = 'a' * 32
        self.manager = transaction.Transactions(self.target, self.root / 'Rollback', self.copy, lambda path: None, lambda path:None)

    def bundle(self, path, content):
        (path / 'Contents/MacOS').mkdir(parents=True)
        (path / 'Contents/MacOS/CronoX3ARMTest').write_bytes(content)
        (path / 'Contents/MacOS/CronoX3ARMTest').chmod(0o755)
        info = {'CFBundleIdentifier': 'com.linplug.au.CronoX3.ARMTest', 'CFBundleExecutable': 'CronoX3ARMTest',
                'AudioComponents': [{'type': 'aumu', 'subtype': 'CrT3', 'manufacturer': 'LinP', 'factoryFunction': 'CronoX3ARMTestAUFactory'}]}
        (path / 'Contents/Info.plist').write_bytes(plistlib.dumps(info))

    @staticmethod
    def copy(source, destination):
        if source.is_symlink():
            os.symlink(os.readlink(source), destination)
        else:
            shutil.copytree(source, destination, symlinks=True, copy_function=shutil.copy2)

    def install(self):
        return self.manager.install(self.source, self.checksum, self.identifier)

    def test_original_crx3_bundle_is_preserved_during_install_and_rollback(self):
        original=self.root/'Components/CronoX 3.component'
        self.bundle(original,b'original Intel CronoX 3')
        before=transaction.tree_hash(original)
        self.install()
        self.assertEqual(transaction.tree_hash(original),before)
        self.manager.rollback(self.identifier)
        self.assertEqual(transaction.tree_hash(original),before)

    def test_original_identity_is_rejected_as_comparison_candidate(self):
        path=self.source/'Contents/Info.plist'
        info=plistlib.loads(path.read_bytes())
        info['AudioComponents'][0]['subtype']='CrX3'
        path.write_bytes(plistlib.dumps(info))
        with self.assertRaisesRegex(RuntimeError,'identity'):
            self.install()
        self.assertFalse(self.target.exists())

    def test_verified_backup_commit_and_later_restore(self):
        self.bundle(self.target, b'old Intel component')
        before = transaction.tree_hash(self.target)
        result = self.install()
        self.assertTrue(result['backup_verified'])
        self.assertEqual(transaction.tree_hash(self.manager.folder(self.identifier) / 'Backup.component'), before)
        self.manager.commit(self.identifier)
        self.assertIsNone(self.manager.active())
        self.manager.rollback(self.identifier)
        self.assertEqual(transaction.tree_hash(self.target), before)
        self.assertTrue((self.manager.folder(self.identifier) / 'Rejected.component').exists())
        self.assertTrue(self.manager.rollback(self.identifier)['already_restored'])

    def test_without_previous_component_rollback_retains_candidate_outside_components(self):
        self.install()
        self.manager.rollback(self.identifier)
        self.assertFalse(self.target.exists())
        self.assertTrue((self.manager.folder(self.identifier) / 'Rejected.component').exists())
        self.manager.rollback(self.identifier)

    def test_copy_failure_preserves_existing_component(self):
        self.bundle(self.target, b'old')
        before = transaction.tree_hash(self.target)
        self.manager.copy = lambda source, destination: (_ for _ in ()).throw(RuntimeError('simulated copy failure'))
        with self.assertRaisesRegex(RuntimeError, 'simulated copy'):
            self.install()
        self.assertEqual(transaction.tree_hash(self.target), before)
        self.assertTrue(self.manager.rollback(self.identifier)['no_component_change_was_recorded'])

    def test_failure_after_moving_previous_component_restores_it(self):
        self.bundle(self.target, b'old')
        before = transaction.tree_hash(self.target)
        replace = os.replace

        def fail_candidate_move(source, destination):
            if Path(source).name == 'Staged.component' and Path(destination) == self.target:
                raise OSError('simulated atomic candidate move failure')
            return replace(source, destination)

        with patch.object(transaction.os, 'replace', side_effect=fail_candidate_move):
            with self.assertRaisesRegex(OSError, 'simulated atomic'):
                self.install()
        self.assertEqual(transaction.tree_hash(self.target), before)
        self.assertIsNone(self.manager.active())

    def test_changed_current_component_is_never_overwritten_by_rollback(self):
        self.bundle(self.target, b'old')
        self.install()
        binary = self.target / 'Contents/MacOS/CronoX3ARMTest'
        binary.write_bytes(b'changed independently')
        with self.assertRaisesRegex(RuntimeError, 'changed since installation'):
            self.manager.rollback(self.identifier)
        self.assertEqual(binary.read_bytes(), b'changed independently')
        self.assertTrue((self.manager.folder(self.identifier) / 'Previous.component').exists())

    def test_journal_failure_after_candidate_move_restores_previous_component(self):
        self.bundle(self.target,b'old')
        before=transaction.tree_hash(self.target)
        write=self.manager.write
        def fail_installed_journal(path,value):
            if path.name=='state.json' and value.get('phase')=='installed':
                raise OSError('simulated journal failure after replacement')
            return write(path,value)
        self.manager.write=fail_installed_journal
        with self.assertRaisesRegex(OSError,'journal failure'):
            self.install()
        self.assertEqual(transaction.tree_hash(self.target),before)
        self.assertTrue((self.manager.folder(self.identifier)/'Rejected.component').exists())

    def test_recovery_from_backup_when_previous_slot_is_missing(self):
        self.bundle(self.target, b'old')
        before = transaction.tree_hash(self.target)
        self.install()
        shutil.rmtree(self.manager.folder(self.identifier) / 'Previous.component')
        self.manager.rollback(self.identifier)
        self.assertEqual(transaction.tree_hash(self.target), before)
        self.assertTrue((self.manager.folder(self.identifier) / 'Backup.component').exists())

    def test_corrupt_only_recovery_copy_stops_rollback(self):
        self.bundle(self.target, b'old')
        self.install()
        folder = self.manager.folder(self.identifier)
        shutil.rmtree(folder / 'Previous.component')
        (folder / 'Backup.component/Contents/MacOS/CronoX3ARMTest').write_bytes(b'corrupted')
        with self.assertRaisesRegex(RuntimeError, 'integrity verification'):
            self.manager.rollback(self.identifier)
        self.assertEqual(transaction.file_hash(self.target / 'Contents/MacOS/CronoX3ARMTest'), self.checksum)

    def test_existing_symlink_is_restored_as_symlink(self):
        elsewhere = self.root / 'Old.component'
        self.bundle(elsewhere, b'old external')
        self.target.symlink_to(elsewhere, target_is_directory=True)
        self.install()
        self.assertFalse(self.target.is_symlink())
        self.manager.rollback(self.identifier)
        self.assertTrue(self.target.is_symlink())
        self.assertEqual(self.target.resolve(), elsewhere)
        self.assertEqual((elsewhere / 'Contents/MacOS/CronoX3ARMTest').read_bytes(), b'old external')

    def test_wrong_identity_checksum_and_links_cannot_be_installed(self):
        with self.assertRaisesRegex(RuntimeError, 'checksum|changed after preflight'):
            self.manager.install(self.source, 'b' * 64, self.identifier)
        (self.source / 'Contents/linked').symlink_to('/tmp')
        with self.assertRaisesRegex(RuntimeError, 'link or special file'):
            self.install()
        (self.source / 'Contents/linked').unlink()
        info_path = self.source / 'Contents/Info.plist'
        info = plistlib.loads(info_path.read_bytes())
        info['CFBundleIdentifier'] = 'another.plugin'
        info_path.write_bytes(plistlib.dumps(info))
        with self.assertRaisesRegex(RuntimeError, 'bundle identity'):
            self.install()
        self.assertFalse(self.target.exists())

    def test_path_traversal_and_concurrent_transaction_are_rejected(self):
        with self.assertRaisesRegex(RuntimeError, 'Invalid transaction'):
            self.manager.rollback('../elsewhere')
        self.install()
        with self.assertRaisesRegex(RuntimeError, 'already pending'):
            self.manager.install(self.source, self.checksum, 'b' * 32)
        with self.assertRaisesRegex(RuntimeError, 'Another CronoX ARM Test transaction'):
            self.manager.rollback('b' * 32)

    def test_plain_file_at_component_destination_is_preserved(self):
        self.target.write_bytes(b'not a component')
        with self.assertRaisesRegex(RuntimeError, 'not a bundle'):
            self.install()
        self.assertEqual(self.target.read_bytes(), b'not a component')


if __name__ == '__main__':
    unittest.main()
