#!/bin/bash
# Public fixtures only. This never asks for or imports the user's licence.
set -euo pipefail
if [[ "${GITHUB_ACTIONS:-}" != true || "$(uname -s)" != Darwin || "$(uname -m)" != arm64 ]]; then
  echo 'Ce script est réservé au runner CI macOS ARM64 éphémère.' >&2
  exit 2
fi
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
CORE="$ROOT/work/ci-core"
BUILD="$ROOT/work/ci-au"
REPORT="$ROOT/work/ci-report"
mkdir -p "$REPORT"
export SOPHISTRY_BUILD_JOBS="${SOPHISTRY_BUILD_JOBS:-3}"
bash scripts/build-audio-unit.sh "$BUILD" "$CORE"
sophistry_python="$(/usr/bin/xcrun --find python3)"
"$sophistry_python" -m unittest discover -s tests -p test_lifted_storage_analysis.py > "$REPORT/storage-analysis.txt" 2>&1
"$CORE/StorageOptimizationProbe" reference/Sophistry.i386 > "$REPORT/storage-state.json"
"$CORE/InstructionProbe" reference/Sophistry.i386 evidence/primitive-instructions.fixtures > "$REPORT/instruction-replay.json"
/usr/bin/gzip -dc evidence/recovered-code-cp032.fixtures.gz > work/ci-recovered.fixtures
"$CORE/InstructionProbe" reference/Sophistry.i386 work/ci-recovered.fixtures > "$REPORT/recovered-code.json"
"$CORE/LiftedProbe" reference/Sophistry.i386 evidence/static-lift-comparison.fixtures > "$REPORT/dsp-replay.json"
"$BUILD/NativeAUBridgeProbe" 'reference/Presets/lightgarden 02 BT.FXP' reference/Samples > "$REPORT/bridge.json"
"$BUILD/MasterVolumeProbe" 'reference/Presets/lightgarden 02 BT.FXP' reference/Samples > "$REPORT/master-state.json"
"$BUILD/FloatConversionProbe" > "$REPORT/float-conversions.json"
"$BUILD/AudioFloatModeProbe" > "$REPORT/float-mode.json"
"$BUILD/GuestAllocatorProbe" > "$REPORT/allocator.json"
"$BUILD/PcmConversionProbe" > "$REPORT/pcm-conversion.json"
"$BUILD/GeneratorLayoutProbe" "$BUILD/Sophistry.component/Contents/Resources/OriginalImages" > "$REPORT/generator-layout.json"
"$sophistry_python" -m venv work/ci-python
work/ci-python/bin/python3 -m pip --disable-pip-version-check install --only-binary=:all: -r requirements-analysis.txt
for kind in generator editor complete_editor; do
  case "$kind" in
    generator) program=compare_generator_controls.py;probe=NativeGeneratorProbe;;
    editor) program=compare_editor_controls.py;probe=NativeEditorProbe;;
    complete_editor) program=compare_complete_editor.py;probe=NativeCompleteEditorProbe;;
  esac
  work/ci-python/bin/python3 "tests/$program" --engine "$BUILD/$probe" --output "$ROOT/work/ci-$kind"
  cp "work/ci-$kind/comparison.json" "$REPORT/$kind-comparison.json"
done
"$sophistry_python" tests/generate_sample_formats.py work/ci-formats > "$REPORT/sample-formats.json"
"$BUILD/NativePresetCycleProbe" work/ci-formats > "$REPORT/preset-cycles.json"
# A/B uses identical release flags and the same fixture work in both programs.
mkdir -p work/ci-baseline
baseline_objects=("$CORE/LifterRuntime.o" "$CORE/Dispatch.o")
candidate_objects=("$CORE/LifterRuntime.o" "$CORE/Dispatch.o" "$CORE"/Unit*.o)
for object in "$CORE"/Unit*.o; do
  name="$(basename "$object" .o)"
  case "$name" in
    Unit0103|Unit0115|Unit0255|Unit0323)
      /usr/bin/xcrun clang++ -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -g0 -ffp-contract=off -fno-fast-math -fno-exceptions -fno-rtti -fPIC -Isrc/lifter -c "src/lifter/whole/$name.cpp" -o "work/ci-baseline/$name.o"
      baseline_objects+=("$ROOT/work/ci-baseline/$name.o");;
    *) baseline_objects+=("$object");;
  esac
done
for mode in baseline candidate; do
  if [[ "$mode" == baseline ]]; then selected_objects=("${baseline_objects[@]}");else selected_objects=("${candidate_objects[@]}");fi
  /usr/bin/xcrun clang++ -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -g0 -ffp-contract=off -fno-fast-math -Isrc/lifter "${selected_objects[@]}" tests/SelectedDspCost.cpp -o "work/ci-$mode-cost"
done
"$sophistry_python" scripts/measure_selected_dsp.py --baseline "$ROOT/work/ci-baseline-cost" --candidate "$ROOT/work/ci-candidate-cost" --original "$ROOT/reference/Sophistry.i386" --fixtures "$ROOT/evidence/static-lift-comparison.fixtures" --output "$REPORT"
# Register only in the disposable runner's user directory, never the system.
ci_component="$HOME/Library/Audio/Plug-Ins/Components/Sophistry.component"
if [[ -e "$ci_component" ]]; then echo 'Composant inattendu dans le runner éphémère.' >&2;exit 1;fi
mkdir -p "$(dirname "$ci_component")"
/usr/bin/ditto "$BUILD/Sophistry.component" "$ci_component"
/usr/bin/killall -u "$(id -u)" AudioComponentRegistrar >/dev/null 2>&1 || true
"$sophistry_python" - "$REPORT" "$BUILD/Sophistry.component" <<'PY'
from pathlib import Path
import json,subprocess,sys,hashlib,plistlib,os
report=Path(sys.argv[1]);bundle=Path(sys.argv[2])
with (report/'auval.txt').open('w') as log:
    result=subprocess.run(['/usr/bin/auval','-v','aumu','Sop3','LinP'],stdout=log,stderr=subprocess.STDOUT,timeout=180)
auval={'passed':result.returncode==0,'exitcode':result.returncode,'scope':'Native macOS ARM64 AU validation in disposable runner, without user licence or bank'}
(report/'auval.json').write_text(json.dumps(auval,indent=2)+'\n')
if result.returncode:raise SystemExit(result.returncode)
subprocess.run(['/usr/bin/lipo','-verify_arch','arm64',str(bundle/'Contents/MacOS/Sophistry')],check=True)
subprocess.run(['/usr/bin/codesign','--verify','--strict',str(bundle)],check=True)
paths=['src/lifter/LifterRuntime.h','src/lifter/LifterRuntime.cpp','src/lifter/OptimizedLifter.h','scripts/optimize_lifted_cpp.py','scripts/build-lifter-chunks.sh','scripts/build-audio-unit.sh','src/au/SophistryAU.cpp','src/au/SophistryEditor.mm','src/au/SophistryProperties.h','src/au/Info.plist','src/engine/LegacyEngine.cpp','tests/AudioUnitFactoryProbe.cpp','tests/StorageOptimizationProbe.cpp','scripts/compare_au_cpu.py','tests/SelectedDspCost.cpp','scripts/measure_selected_dsp.py']
with (bundle/'Contents/Info.plist').open('rb') as f:info=plistlib.load(f)
summary={'checkpoint':'CP-033','tested_commit':os.environ['GITHUB_SHA'],'native_architecture':subprocess.check_output(['uname','-m'],text=True).strip(),'macos':subprocess.check_output(['sw_vers','-productVersion'],text=True).strip(),'bundle_build':info['CFBundleVersion'],'au_identity':'aumu/Sop3/LinP','source_sha256':{p:hashlib.sha256(Path(p).read_bytes()).hexdigest() for p in paths},'complete_optimized_core_compiled':True,'original_pcode_sha256':json.loads(Path('work/ci-core/optimized/manifest.json').read_text())['original_pcode_sha256'],'auval_passed':True,'ad_hoc_signature_verified':True,'private_licence_or_bank_used':False,'licensed_musical_full_engine_tested':False,'all_configured_checks_passed':True}
(report/'ci-summary.json').write_text(json.dumps(summary,indent=2)+'\n')
PY
cp "$CORE/storage-optimization.json" "$REPORT/storage-optimization.json"
