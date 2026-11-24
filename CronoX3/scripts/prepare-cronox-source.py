#!/usr/bin/env python3
"""Verify and unpack only the pinned CronoX static C++ sources."""
from pathlib import Path
import hashlib,json,tarfile,sys
ROOT=Path(__file__).resolve().parents[1]
# Binary payloads are split to keep repository connector transfers bounded.
payloads=json.loads((ROOT/'sources/payload-parts.json').read_text())
for spec in payloads['files']:
 target=ROOT/spec['path']
 if not target.resolve().is_relative_to(ROOT):raise SystemExit('Chemin payload incorrect')
 if target.is_file() and hashlib.sha256(target.read_bytes()).hexdigest()==spec['sha256']:continue
 raw=bytearray()
 for part in spec['parts']:
  source=ROOT/part['path']
  if not source.resolve().is_relative_to(ROOT):raise SystemExit('Chemin fragment incorrect')
  data=source.read_bytes()
  if len(data)!=part['bytes'] or hashlib.sha256(data).hexdigest()!=part['sha256']:raise SystemExit('Fragment altéré')
  raw.extend(data)
 if len(raw)!=spec['bytes'] or hashlib.sha256(raw).hexdigest()!=spec['sha256']:raise SystemExit('Payload altéré')
 target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(raw)
report=json.loads((ROOT/'sources/cronox-kernel-cpp.json').read_text())
archive=ROOT/report['archive']
if hashlib.sha256(archive.read_bytes()).hexdigest()!=report['archive_sha256']:raise SystemExit('Archive C++ CronoX altérée')
expected={f['name']:f for f in report['generated_files']}
output=ROOT/'src/lifter/cronox';output.mkdir(parents=True,exist_ok=True)
with tarfile.open(archive,'r:gz') as source:
 members=source.getmembers()
 if len(members)!=len(expected) or {m.name for m in members}!=set(expected):raise SystemExit('Inventaire C++ incorrect')
 for member in members:
  if not member.isfile() or Path(member.name).name!=member.name:raise SystemExit('Chemin source interdit')
  raw=source.extractfile(member).read();spec=expected[member.name]
  if len(raw)!=spec['bytes'] or hashlib.sha256(raw).hexdigest()!=spec['sha256']:raise SystemExit('Source C++ altérée: '+member.name)
  target=output/member.name
  if not target.is_file() or target.read_bytes()!=raw:target.write_bytes(raw)
print('415 fichiers du noyau vérifiés ; 413 unités de traduction statique.')

from generate_legacy_image_cpp import generate
expected_image=json.loads((ROOT/'evidence/cronox-image-provenance.json').read_text())
actual_image=generate(ROOT/'reference/CronoX3.i386',ROOT/'src/engine')
if actual_image!=expected_image:raise SystemExit('Image et imports CronoX différents de la référence')
print('Image, imports et initialisateurs originaux vérifiés.')
