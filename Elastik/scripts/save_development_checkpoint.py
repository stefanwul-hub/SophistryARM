#!/usr/bin/env python3
"""Save a committed public development snapshot, without nested checkpoints."""
import argparse
import fnmatch
import hashlib
import json
from pathlib import Path
import re
import subprocess
import zipfile


def save(checkpoint, output, report):
    if not re.fullmatch(r'ELA[0-9]{3}', checkpoint): raise ValueError('Expected ELA followed by three digits')
    root = Path(__file__).resolve().parents[1]
    def git(*args): return subprocess.check_output(['git', '-C', str(root), *args])
    head = git('rev-parse', 'HEAD').decode().strip()
    paths = git('ls-tree', '-r', '--name-only', '-z', head).decode().split('\0')
    paths = [p for p in paths if p and not fnmatch.fnmatch(p, 'Elastik-*-checkpoint.zip')
             and not fnmatch.fnmatch(p, 'checkpoints/*-download.json')]
    if 'PUBLICATION_AUTHORIZATION.json' not in paths: raise ValueError('Missing publication scope record')
    if any(p.startswith(('reference/', 'work/', '.git/')) or p.endswith('.bundle') or p == 'ElastikAU.pkg.zip' for p in paths):
        raise ValueError('Private input or backup unexpectedly tracked')
    blobs = [(p, git('show', head + ':' + p)) for p in sorted(paths)]
    status = json.loads(next(b for p, b in blobs if p == 'elastik-status.json'))
    if status['checkpoint'] != checkpoint: raise ValueError('Committed status checkpoint mismatch')
    manifest = {'checkpoint': checkpoint, 'package_kind': 'Complete public development checkpoint',
                'source_local_git_commit': head, 'native_audio_unit_available': status['native_arm64_audio_unit_available'],
                'standing_publication_consent': 'PUBLICATION_AUTHORIZATION.json',
                'excluded': ['Original installer', 'User banks, serials, activation data, private preferences and projects',
                             'Private Git bundles', 'Nested checkpoint ZIPs and download receipts'],
                'files': [{'path': p, 'bytes': len(b), 'sha256': hashlib.sha256(b).hexdigest()} for p, b in blobs]}
    output = output.resolve(); output.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(output, 'w', compression=zipfile.ZIP_DEFLATED, compresslevel=9) as archive:
        for p, b in blobs: archive.writestr('Elastik/' + p, b)
        archive.writestr('Elastik/' + checkpoint + '-CHECKPOINT.json', json.dumps(manifest, indent=2) + '\n')
        if archive.testzip() is not None: raise ValueError('Checkpoint ZIP failed integrity check')
    result = {'checkpoint': checkpoint, 'source_local_git_commit': head,
              'complete_public_archive': {'path': output.name, 'bytes': output.stat().st_size,
                                         'sha256': hashlib.sha256(output.read_bytes()).hexdigest(),
                                         'entries': len(blobs) + 1, 'zip_crc_verified': True},
              'contains_original_installer': False, 'contains_user_bank': False,
              'native_audio_unit_available': status['native_arm64_audio_unit_available']}
    report.parent.mkdir(parents=True, exist_ok=True); report.write_text(json.dumps(result, indent=2) + '\n')
    return result


if __name__ == '__main__':
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--checkpoint', required=True); p.add_argument('--output', type=Path, required=True)
    p.add_argument('--report', type=Path, required=True); a = p.parse_args()
    print(json.dumps(save(a.checkpoint, a.output, a.report), indent=2))
