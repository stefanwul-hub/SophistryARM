#!/usr/bin/env python3
"""Enforce the comparison identity and native symbol isolation before install."""
from pathlib import Path
import argparse,json,plistlib,hashlib
p=argparse.ArgumentParser();p.add_argument('bundle',type=Path);p.add_argument('--exports',type=Path);o=p.parse_args()
root=Path(__file__).resolve().parents[1];expected=json.loads((root/'config/au-identity-test.json').read_text())
info=plistlib.loads((o.bundle/'Contents/Info.plist').read_bytes());components=info.get('AudioComponents',[])
if o.bundle.name!=expected['component_filename'] or info.get('CFBundleIdentifier')!=expected['bundle_identifier'] or info.get('CFBundleExecutable')!=expected['executable']:
 raise SystemExit('Le bundle ne correspond pas au profil de comparaison')
if len(components)!=1:raise SystemExit('Le bundle doit contenir un seul composant de comparaison')
c=components[0]
if (c.get('type'),c.get('subtype'),c.get('manufacturer'),c.get('factoryFunction'))!=('aumu','CrT3','LinP','CronoX3ARMTestAUFactory'):
 raise SystemExit('Identifiants du composant de comparaison incorrects')
if c['subtype']==expected['original_component_subtype'] or expected['original_replacement_allowed']:
 raise SystemExit('Le remplacement du composant original est désactivé')
manifest=json.loads((root/'sources/cronox-original-images.json').read_text())
for image in manifest['images']:
 data=(o.bundle/'Contents/Resources/OriginalImages'/image['name']).read_bytes()
 if len(data)!=image['bytes'] or hashlib.sha256(data).hexdigest()!=image['sha256']:
  raise SystemExit('Ressource graphique originale incorrecte: '+image['name'])
if o.exports:
 actual={line.split()[-1] for line in o.exports.read_text().splitlines() if line.split()}
 allowed={'_CronoX3ARMTestAUFactory','_OBJC_CLASS_$_CronoX3ARMTestCocoaFactory','_OBJC_METACLASS_$_CronoX3ARMTestCocoaFactory'}
 if actual!=allowed:raise SystemExit('Symboles natifs de comparaison incorrects : '+str(sorted(actual-allowed)))
print(json.dumps({'comparison_identity':'aumu/CrT3/LinP','original_identity_preserved':True,'bundle_identity_verified':True,'private_symbols_verified':bool(o.exports),'original_images_verified':len(manifest['images'])}))
