#!/usr/bin/env python3
"""Back up and atomically replace only CronoX 3 ARM Test.component; retain every rollback.

The CLI requires macOS/root and has fixed system destinations. The implementation
accepts temporary paths and command adapters for unprivileged regression tests.
No component, backup, or rejected candidate is recursively deleted.
"""
import argparse
import contextlib
import fcntl
import hashlib
import json
import os
from pathlib import Path
import plistlib
import re
import stat
import subprocess
import sys

TARGET = Path('/Library/Audio/Plug-Ins/Components/CronoX 3 ARM Test.component')
BACKUPS = Path('/Library/Audio/Plug-Ins/CronoX3ARMTest-Rollback')


def exists(path):
    return path.exists() or path.is_symlink()


def file_hash(path):
    digest = hashlib.sha256()
    with path.open('rb') as source:
        for chunk in iter(lambda: source.read(1024 * 1024), b''):
            digest.update(chunk)
    return digest.hexdigest()


def tree_hash(path):
    """Include modes, symlinks, contents and extended attributes, without following links."""
    entries = {}

    def visit(item, name):
        mode = item.lstat().st_mode
        if stat.S_ISLNK(mode):
            entries[name] = {'type': 'link', 'destination': os.readlink(item)}
            return
        if not stat.S_ISREG(mode) and not stat.S_ISDIR(mode):
            raise RuntimeError('Unexpected special file in component')
        attrs = {}
        if hasattr(os, 'listxattr'):
            for key in sorted(os.listxattr(item, follow_symlinks=False)):
                attrs[key] = hashlib.sha256(os.getxattr(item, key, follow_symlinks=False)).hexdigest()
        record = {'type': 'directory' if stat.S_ISDIR(mode) else 'file',
                  'mode': stat.S_IMODE(mode), 'xattrs': attrs}
        if stat.S_ISREG(mode):
            record['sha256'] = file_hash(item)
        entries[name] = record
        if stat.S_ISDIR(mode):
            for child in sorted(item.iterdir()):
                visit(child, name + '/' + child.name)

    visit(path, '.')
    return hashlib.sha256(json.dumps(entries, sort_keys=True, ensure_ascii=False).encode()).hexdigest()


def validate_bundle(path, expected_hash):
    if path.is_symlink() or not path.is_dir():
        raise RuntimeError('Candidate must be a regular component bundle')
    for item in path.rglob('*'):
        if item.is_symlink() or (not item.is_dir() and not item.is_file()):
            raise RuntimeError('Candidate contains a link or special file')
    with (path / 'Contents/Info.plist').open('rb') as stream:
        info = plistlib.load(stream)
    components = info.get('AudioComponents', [])
    if info.get('CFBundleIdentifier') != 'com.linplug.au.CronoX3.ARMTest' or info.get('CFBundleExecutable') != 'CronoX3ARMTest' or len(components) != 1:
        raise RuntimeError('Unexpected component bundle identity')
    component = components[0]
    if (component.get('type'), component.get('subtype'), component.get('manufacturer'), component.get('factoryFunction')) != ('aumu', 'CrT3', 'LinP', 'CronoX3ARMTestAUFactory'):
        raise RuntimeError('Unexpected Audio Unit identity')
    if file_hash(path / 'Contents/MacOS/CronoX3ARMTest') != expected_hash:
        raise RuntimeError('Candidate binary changed after preflight')


def native_verify(path):
    binary = path / 'Contents/MacOS/CronoX3ARMTest'
    for args in [ ['/usr/bin/lipo', str(binary), '-verify_arch', 'arm64'],
                  ['/usr/bin/codesign', '--verify', '--strict', str(path)] ]:
        result = subprocess.run(args, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        if result.returncode:
            raise RuntimeError('Candidate ARM64/signature verification failed')


def native_copy(source, destination):
    if source.is_symlink():
        os.symlink(os.readlink(source), destination)
        return
    result = subprocess.run(['/usr/bin/ditto', '--rsrc', '--extattr', str(source), str(destination)], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if result.returncode:
        raise RuntimeError('Component copy failed; existing component has not been removed')


def native_prepare_candidate(path):
    for item in [path] + list(path.rglob('*')):
        os.chown(item, 0, 0, follow_symlinks=False)


class Transactions:
    def __init__(self, target=TARGET, backups=BACKUPS, copier=native_copy, verifier=native_verify, preparer=native_prepare_candidate):
        self.target, self.backups = Path(target), Path(backups)
        self.copy, self.verify = copier, verifier
        self.prepare=preparer

    def folder(self, transaction):
        if not re.fullmatch(r'[0-9a-f]{32}', transaction):
            raise RuntimeError('Invalid transaction identifier')
        return self.backups / transaction

    @contextlib.contextmanager
    def lock(self):
        if self.backups.is_symlink():
            raise RuntimeError('Rollback location must not be a link')
        self.backups.mkdir(mode=0o700, parents=True, exist_ok=True)
        if os.geteuid() == 0 and self.backups.stat().st_uid != 0:
            raise RuntimeError('Rollback location is not owned by root')
        # Only the pending transaction ID is public. Saved bundles and journals
        # are below per-transaction directories with mode 0700.
        self.backups.chmod(0o755)
        with (self.backups / '.lock').open('a') as stream:
            fcntl.flock(stream, fcntl.LOCK_EX | fcntl.LOCK_NB)
            yield

    def write(self, path, value):
        temporary = path.with_suffix('.pending')
        with temporary.open('w') as stream:
            os.chmod(temporary, 0o644 if path.name == 'active.json' else 0o600)
            json.dump(value, stream, sort_keys=True)
            stream.write('\n')
            stream.flush()
            os.fsync(stream.fileno())
        os.replace(temporary, path)

    def state(self, transaction):
        folder = self.folder(transaction)
        if folder.is_symlink():
            raise RuntimeError('Invalid rollback directory')
        with (folder / 'state.json').open() as stream:
            value = json.load(stream)
        if value.get('id') != transaction or value.get('schema') != 1 or not re.fullmatch(r'[0-9a-f]{64}', value.get('candidate_sha256', '')):
            raise RuntimeError('Invalid transaction journal')
        return value

    def active(self):
        path = self.backups / 'active.json'
        return json.loads(path.read_text())['id'] if path.exists() else None

    def clear_active(self, transaction):
        if self.active() == transaction:
            (self.backups / 'active.json').unlink()

    def install(self, source, expected_hash, transaction):
        source = Path(source)
        folder = self.folder(transaction)
        if not re.fullmatch(r'[0-9a-f]{64}', expected_hash):
            raise RuntimeError('Invalid expected binary checksum')
        with self.lock():
            if self.active():
                raise RuntimeError('A CronoX ARM Test installation transaction is already pending')
            validate_bundle(source, expected_hash)
            self.verify(source)
            parent_existed=self.target.parent.exists()
            self.target.parent.mkdir(parents=True, exist_ok=True)
            if not parent_existed:self.target.parent.chmod(0o755)
            if self.target.parent.stat().st_dev != self.backups.stat().st_dev:
                raise RuntimeError('Component and rollback locations must share a filesystem for atomic replacement')
            if exists(self.target) and not self.target.is_dir() and not self.target.is_symlink():
                raise RuntimeError('Existing component path is not a bundle or link')
            folder.mkdir(mode=0o700)
            staged, previous, backup = (folder / name for name in ['Staged.component', 'Previous.component', 'Backup.component'])
            self.copy(source, staged)
            validate_bundle(staged, expected_hash)
            self.prepare(staged)
            self.verify(staged)
            if tree_hash(source) != tree_hash(staged):
                raise RuntimeError('Staged candidate differs from preflight bundle')
            old_present = exists(self.target)
            old_hash = tree_hash(self.target) if old_present else None
            if old_present:
                self.copy(self.target, backup)
                if tree_hash(backup) != old_hash or tree_hash(self.target) != old_hash:
                    raise RuntimeError('Previous component backup does not match; replacement cancelled')
            value = {'schema': 1, 'id': transaction, 'phase': 'prepared', 'old_present': old_present,
                     'previous_tree_sha256': old_hash, 'candidate_sha256': expected_hash,
                     'backup_verified': old_present}
            self.write(folder / 'state.json', value)
            self.write(self.backups / 'active.json', {'id': transaction})
            try:
                if old_present:
                    os.replace(self.target, previous)
                    value['phase'] = 'previous-moved'
                    self.write(folder / 'state.json', value)
                os.replace(staged, self.target)
                value['phase'] = 'installed'
                self.write(folder / 'state.json', value)
            except BaseException:
                self._rollback(transaction)
                raise
            return {'installed': True, 'transaction': transaction, 'previous_component_present': old_present,
                    'backup_verified': old_present, 'awaiting_validation': True}

    def _rollback(self, transaction):
        if self.active() not in [None, transaction]:
            raise RuntimeError('Another CronoX ARM Test transaction is active')
        folder = self.folder(transaction)
        if not (folder / 'state.json').exists():
            if exists(folder / 'Previous.component') or self.active() == transaction:
                raise RuntimeError('Recovery journal is missing; previous component retained for manual recovery')
            return {'rollback_completed': True, 'no_component_change_was_recorded': True}
        value = self.state(transaction)
        previous, backup, rejected = (folder / name for name in ['Previous.component', 'Backup.component', 'Rejected.component'])
        old_hash = value['previous_tree_sha256']
        if value['old_present'] and exists(self.target) and tree_hash(self.target) == old_hash:
            value['phase'] = 'rolled-back'
            self.write(folder / 'state.json', value)
            self.clear_active(transaction)
            return {'rollback_completed': True, 'previous_component_restored': True, 'already_restored': True}
        candidate_present = exists(self.target)
        if candidate_present:
            if self.target.is_symlink() or not self.target.is_dir() or file_hash(self.target / 'Contents/MacOS/CronoX3ARMTest') != value['candidate_sha256']:
                raise RuntimeError('Current component changed since installation; automatic overwrite refused')
            if exists(rejected):
                raise RuntimeError('Rejected candidate already exists; no backup overwritten')
        if value['old_present']:
            restore = previous if exists(previous) else backup
            if not exists(restore) or tree_hash(restore) != old_hash:
                raise RuntimeError('Previous component recovery copy failed integrity verification')
            # The fallback backup is retained even after a recovery.
            if restore == backup:
                restore = folder / 'Recovered.component'
                if exists(restore):
                    raise RuntimeError('A recovery copy already exists')
                self.copy(backup, restore)
                if tree_hash(restore) != old_hash:
                    raise RuntimeError('Recovery copy differs from the previous component')
            if candidate_present:
                os.replace(self.target, rejected)
            os.replace(restore, self.target)
        elif candidate_present:
            os.replace(self.target, rejected)
        value['phase'] = 'rolled-back'
        self.write(folder / 'state.json', value)
        self.clear_active(transaction)
        return {'rollback_completed': True, 'previous_component_restored': bool(value['old_present']),
                'new_candidate_retained_outside_components': candidate_present}

    def rollback(self, transaction):
        self.folder(transaction)
        with self.lock():
            return self._rollback(transaction)

    def commit(self, transaction):
        self.folder(transaction)
        with self.lock():
            if self.active() != transaction:
                raise RuntimeError('Transaction is not pending validation')
            value = self.state(transaction)
            validate_bundle(self.target, value['candidate_sha256'])
            self.verify(self.target)
            value['phase'] = 'committed'
            self.write(self.folder(transaction) / 'state.json', value)
            self.clear_active(transaction)
            return {'installation_committed': True, 'rollback_copies_retained': True, 'transaction': transaction}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('action', choices=['install', 'rollback', 'commit'])
    parser.add_argument('--transaction', required=True)
    parser.add_argument('--source', type=Path)
    parser.add_argument('--expected-sha256')
    args = parser.parse_args()
    try:
        if sys.platform != 'darwin' or os.geteuid() != 0:
            raise RuntimeError('System component transactions require macOS and administrator privileges')
        manager = Transactions()
        if args.action == 'install':
            if args.source is None or args.expected_sha256 is None:
                raise RuntimeError('A verified candidate and checksum are required')
            result = manager.install(args.source, args.expected_sha256, args.transaction)
        elif args.action == 'rollback':
            result = manager.rollback(args.transaction)
        else:
            result = manager.commit(args.transaction)
        print(json.dumps(result, sort_keys=True))
        return 0
    except BaseException as error:
        print(json.dumps({'action': args.action, 'error': str(error), 'operation_completed': False}))
        return 1


if __name__ == '__main__':
    sys.exit(main())
