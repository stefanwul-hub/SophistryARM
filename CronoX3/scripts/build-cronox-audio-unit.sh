#!/bin/bash
# Comparison candidate only; no /Library changes and no original IDs.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DEST="${1:-$ROOT/work/cronox-audio-unit}"
CORE="${2:-$ROOT/work/cronox-core}"
[[ "$(uname -s)" == Darwin && "$(uname -m)" == arm64 ]] || { echo 'Utilisez un Terminal natif Apple Silicon avec Xcode.' >&2;exit 2; }
/usr/bin/python3 "$ROOT/scripts/generate-cronox-au-identity.py"
bash "$ROOT/scripts/build-cronox-engine.sh" "$ROOT/work/cronox-engine" "$CORE"
mkdir -p "$DEST/sdk" "$DEST/host"
compiler=(/usr/bin/xcrun clang++)
flags=(-std=c++20 -arch arm64 -mmacosx-version-min=11.0 -O2 -g0 -fno-fast-math -ffp-contract=off
 -DAUSDK_HAVE_MIDI_MAPPING=0 -DAUSDK_HAVE_XML_NAMES=0 -DAUSDK_HAVE_MIDI2=0
 -I"$ROOT/third_party/AudioUnitSDK/include")
version="$("${compiler[@]}" --version)"
headers="$(find "$ROOT/third_party/AudioUnitSDK/include" "$ROOT/src/au" "$ROOT/src/engine" -type f -name '*.h' -exec shasum -a 256 {} + | LC_ALL=C sort | shasum -a 256 | awk '{print $1}')"
objects=()
for source in "$ROOT/third_party/AudioUnitSDK/src/AudioUnitSDK/"*.cpp "$ROOT/src/au/CronoX3ARMTestAU.cpp" "$ROOT/src/au/CronoX3ARMTestEditor.mm"; do
 name="$(basename "$source")";name="${name%.*}"
 object="$DEST/sdk/$name.o";objects+=("$object")
 # macOS /bin/bash 3.2 treats an empty array as unset under `set -u`.
 # Keep a populated argument array for both C++ and Objective-C++ sources.
 source_flags=("${flags[@]}")
 if [[ "$source" == *.mm ]]; then source_flags+=(-fobjc-arc);fi
 key="$( { printf '%s\n' "${compiler[*]}" "${source_flags[*]}" "$version" "$headers";cat "$source"; } | shasum -a 256 | awk '{print $1}')"
 if [[ ! -s "$object" || ! -f "$object.compile.sha256" || "$(cat "$object.compile.sha256")" != "$key" ]]; then
  "${compiler[@]}" "${source_flags[@]}" -c "$source" -o "$object.pending" > "$object.compile.log" 2>&1
  mv "$object.pending" "$object";printf '%s\n' "$key" > "$object.compile.sha256"
 fi
done
bundle="$DEST/CronoX 3 ARM Test.component"
mkdir -p "$bundle/Contents/MacOS" "$bundle/Contents/Resources"
cp "$ROOT/src/au/Info.plist" "$bundle/Contents/Info.plist"
/usr/bin/ditto "$ROOT/reference/Samples" "$bundle/Contents/Resources/Samples"
/usr/bin/ditto "$ROOT/reference/Presets" "$bundle/Contents/Resources/Presets"
/usr/bin/ditto "$ROOT/reference/CronoX3Images" "$bundle/Contents/Resources/OriginalImages"
cp "$ROOT/third_party/AudioUnitSDK/LICENSE.txt" "$bundle/Contents/Resources/AudioUnitSDK-LICENSE.txt"
# Keep sl_*, LegacyEngine and SDK weak definitions private to this image so
# that Sophistry CP038 and this AU can coexist without symbol coalescing.
"${compiler[@]}" -arch arm64 -mmacosx-version-min=11.0 -bundle \
 "$ROOT/work/cronox-engine/LegacyEngine.o" "$ROOT/work/cronox-engine/LegacyImageData.o" "${objects[@]}" \
 "$CORE/LifterRuntime.o" "$CORE/Dispatch.o" "$CORE"/Unit*.o \
 -Wl,-exported_symbols_list,"$ROOT/src/au/CronoX3ARMTest.exports" \
 -lobjc -framework AppKit -framework CoreText -framework Foundation -framework AudioToolbox -framework CoreAudio -framework CoreFoundation -framework CoreMIDI \
 -o "$bundle/Contents/MacOS/CronoX3ARMTest.pending"
mv "$bundle/Contents/MacOS/CronoX3ARMTest.pending" "$bundle/Contents/MacOS/CronoX3ARMTest"
/usr/bin/plutil -lint "$bundle/Contents/Info.plist"
/usr/bin/lipo "$bundle/Contents/MacOS/CronoX3ARMTest" -verify_arch arm64
/usr/bin/nm -gU "$bundle/Contents/MacOS/CronoX3ARMTest" > "$DEST/exports.txt"
/usr/bin/python3 "$ROOT/scripts/verify-cronox-bundle.py" "$bundle" --exports "$DEST/exports.txt"
/usr/bin/codesign --force --sign - --timestamp=none "$bundle"
/usr/bin/find "$bundle" -type d -exec /bin/chmod 755 {} +
/usr/bin/find "$bundle" -type f -exec /bin/chmod 644 {} +
/bin/chmod 755 "$bundle/Contents/MacOS/CronoX3ARMTest"
/usr/bin/codesign --verify --strict "$bundle"
"${compiler[@]}" "${flags[@]}" -fobjc-arc "$ROOT/tests/CronoXComparisonProbe.mm" \
 -framework AppKit -framework CoreText -framework Foundation -framework AudioToolbox -framework CoreFoundation \
 -o "$DEST/CronoXComparisonProbe" > "$DEST/comparison-probe.compile.log" 2>&1
/usr/bin/lipo "$DEST/CronoXComparisonProbe" -verify_arch arm64
"${compiler[@]}" "${flags[@]}" "$ROOT/tests/CronoXRegistrationProbe.cpp" \
 -framework AudioToolbox -framework CoreFoundation -o "$DEST/CronoXRegistrationProbe" \
 > "$DEST/registration-probe.compile.log" 2>&1
/usr/bin/lipo "$DEST/CronoXRegistrationProbe" -verify_arch arm64
for probe in CronoXRunLoopProbe CronoXControlThreadProbe CronoXEditorProbe; do
 "${compiler[@]}" -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -g0 -ffp-contract=off -fno-fast-math \
  "$ROOT/tests/$probe.cpp" "$ROOT/work/cronox-engine/LegacyEngine.o" "$ROOT/work/cronox-engine/LegacyImageData.o" \
  "$CORE/LifterRuntime.o" "$CORE/Dispatch.o" "$CORE"/Unit*.o -framework CoreFoundation \
  -o "$DEST/$probe" > "$DEST/$probe.compile.log" 2>&1
 /usr/bin/lipo "$DEST/$probe" -verify_arch arm64
done
for probe in CronoXCorrectionsProbe CronoXLoopSamplerProbe; do
"${compiler[@]}" -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -g0 -ffp-contract=off -fno-fast-math \
 "$ROOT/tests/$probe.cpp" "$ROOT/work/cronox-engine/LegacyImageData.o" \
 "$CORE/LifterRuntime.o" "$CORE/Dispatch.o" "$CORE"/Unit*.o -framework CoreFoundation \
 -o "$DEST/$probe" > "$DEST/$probe.compile.log" 2>&1
/usr/bin/lipo "$DEST/$probe" -verify_arch arm64
done
printf '%s\n' "$bundle" "$DEST/CronoXComparisonProbe"
