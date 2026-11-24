#!/usr/bin/env python3
"""Materialize only the coexistence identity selected for comparison tests."""
from pathlib import Path
import json,plistlib
ROOT=Path(__file__).resolve().parents[1]
c=json.loads((ROOT/'config/au-identity-test.json').read_text())
if c['profile']!='comparison' or c['original_replacement_allowed']:
 raise SystemExit('Seul le profil de comparaison est activé à ce stade')
for key in ('component_type','component_subtype','manufacturer','original_component_subtype','legacy_vst_state_uid'):
 if len(c[key])!=4 or not c[key].isascii():raise SystemExit('FourCC incorrect')
if c['component_subtype']==c['original_component_subtype'] or c['bundle_identifier']==c['original_bundle_identifier'] or c['component_filename']==c['original_component_filename']:
 raise SystemExit('Le composant de comparaison doit cohabiter avec l’original')
component={'name':'LinPlug: '+c['display_name'],'description':'CronoX 3 ARM64 comparison build',
 'manufacturer':c['manufacturer'],'type':c['component_type'],'subtype':c['component_subtype'],
 'version':0x30606,'factoryFunction':c['factory_function']}
info={'CFBundleDevelopmentRegion':'English','CFBundleExecutable':c['executable'],
 'CFBundleIdentifier':c['bundle_identifier'],'CFBundleInfoDictionaryVersion':'6.0',
 'CFBundleName':c['bundle_name'],'CFBundlePackageType':'BNDL',
 'CFBundleShortVersionString':'3.6.6','CFBundleVersion':c.get('build_version','1001'),
 'LSMinimumSystemVersion':'11.0','AudioComponents':[component]}
(ROOT/'src/au/Info.plist').write_bytes(plistlib.dumps(info,sort_keys=False))
def fourcc(value):return hex(int.from_bytes(value.encode('ascii'),'big'))+'u'
header='''#pragma once
// Comparison AU identity. The original CrX3 identifier is reserved until validation.
namespace cronox::identity {
'''
for name,key in [('type','component_type'),('subtype','component_subtype'),('manufacturer','manufacturer'),('originalSubtype','original_component_subtype')]:
 header+='inline constexpr unsigned '+name+' = '+fourcc(c[key])+';\n'
for name,key in [('name','display_name'),('bundleIdentifier','bundle_identifier'),('componentFilename','component_filename'),('cocoaFactory','cocoa_factory_class'),('factory','factory_function')]:
 header+='inline constexpr const char* '+name+' = '+json.dumps(c[key])+';\n'
header+='inline constexpr bool mayReplaceOriginal = false;\n} // namespace cronox::identity\n'
(ROOT/'src/au/CronoXIdentity.h').write_text(header)
print('Identité de comparaison vérifiée : aumu/CrT3/LinP ; original CrX3 conservé.')
