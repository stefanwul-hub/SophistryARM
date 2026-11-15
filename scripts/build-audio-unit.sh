#!/bin/bash
# Build an uninstalled candidate. No changes to /Library or AU caches.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
DEST="${1:-$ROOT/work/audio-unit}"
CORE="${2:-$ROOT/work/lifter-whole}"
if [[ "$(uname -s)" != Darwin || "$(uname -m)" != arm64 ]]; then
  echo 'Compiler depuis un Terminal natif Apple Silicon avec Xcode.' >&2
  exit 2
fi
mkdir -p "$DEST/sdk" "$DEST/host"
bash "$ROOT/scripts/build-native-engine.sh" "$DEST/host" "$CORE"
compiler=(/usr/bin/xcrun clang++)
flags=(-std=c++20 -arch arm64 -mmacosx-version-min=11.0 -O2 -g0 -fno-fast-math -ffp-contract=off
  -DAUSDK_HAVE_MIDI_MAPPING=0 -DAUSDK_HAVE_XML_NAMES=0 -DAUSDK_HAVE_MIDI2=0
  -I"$ROOT/third_party/AudioUnitSDK/include")
compiler_version="$("${compiler[@]}" --version)"
sdk_header_key="$(find "$ROOT/third_party/AudioUnitSDK/include" -type f -exec shasum -a 256 {} + | LC_ALL=C sort | shasum -a 256 | awk '{print $1}')"
sources=("$ROOT/third_party/AudioUnitSDK/src/AudioUnitSDK"/*.cpp "$ROOT/src/au/SophistryAU.cpp")
objects=()
for source in "${sources[@]}"; do
  object="$DEST/sdk/$(basename "$source" .cpp).o";objects+=("$object")
  key="$( { printf '%s\n' "${flags[*]}" "$compiler_version" "$sdk_header_key"; cat "$ROOT/src/engine/LegacyEngine.h" "$ROOT/src/au/SophistryProperties.h" "$ROOT/src/au/BankAccess.h" "$source"; } | shasum -a 256 | awk '{print $1}')"
  if [[ ! -s "$object" || ! -f "$object.compile.sha256" || "$(cat "$object.compile.sha256")" != "$key" ]]; then
    "${compiler[@]}" "${flags[@]}" -c "$source" -o "$object.pending" > "$object.compile.log" 2>&1
    mv "$object.pending" "$object"
    printf '%s\n' "$key" > "$object.compile.sha256"
  fi
done
editor="$DEST/sdk/SophistryEditor.o"
key="$( { printf '%s\n' "${flags[*]} -fobjc-arc" "$compiler_version"; cat "$ROOT/src/au/SophistryProperties.h" "$ROOT/src/au/BankAccess.h" "$ROOT/src/au/SophistryEditor.mm"; } | shasum -a 256 | awk '{print $1}')"
if [[ ! -s "$editor" || ! -f "$editor.compile.sha256" || "$(cat "$editor.compile.sha256")" != "$key" ]]; then
  "${compiler[@]}" "${flags[@]}" -fobjc-arc -c "$ROOT/src/au/SophistryEditor.mm" -o "$editor.pending" > "$editor.compile.log" 2>&1
  mv "$editor.pending" "$editor"
  printf '%s\n' "$key" > "$editor.compile.sha256"
fi
objects+=("$editor")
bundle="$DEST/Sophistry.component"
mkdir -p "$bundle/Contents/MacOS" "$bundle/Contents/Resources"
cp "$ROOT/src/au/Info.plist" "$bundle/Contents/Info.plist"
cp -R "$ROOT/reference/Samples" "$bundle/Contents/Resources/"
cp -R "$ROOT/reference/Presets" "$bundle/Contents/Resources/"
/usr/bin/ditto "$ROOT/reference/Resources" "$bundle/Contents/Resources/OriginalImages"
cp "$ROOT/third_party/AudioUnitSDK/LICENSE.txt" "$bundle/Contents/Resources/AudioUnitSDK-LICENSE.txt"
"${compiler[@]}" -arch arm64 -mmacosx-version-min=11.0 -bundle \
  "$DEST/host/LegacyEngine.o" "$DEST/host/LegacyImageData.o" "${objects[@]}" \
  "$CORE/LifterRuntime.o" "$CORE/Dispatch.o" "$CORE"/Unit*.o \
  -lobjc -framework AppKit -framework Foundation -framework AudioToolbox -framework CoreAudio -framework CoreFoundation -framework CoreMIDI \
  -o "$bundle/Contents/MacOS/Sophistry"
/usr/bin/plutil -lint "$bundle/Contents/Info.plist"
/usr/bin/lipo "$bundle/Contents/MacOS/Sophistry" -verify_arch arm64
/usr/bin/codesign --force --sign - --timestamp=none "$bundle"
# The installer uses a private umask for reports/preferences. The shared AU
# contains public code/resources and must remain readable by every Mac user.
/usr/bin/find "$bundle" -type d -exec /bin/chmod 755 {} +
/usr/bin/find "$bundle" -type f -exec /bin/chmod 644 {} +
/bin/chmod 755 "$bundle/Contents/MacOS/Sophistry"
/usr/bin/codesign --verify --strict "$bundle"
"${compiler[@]}" -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 \
  "$ROOT/tests/AudioUnitFactoryProbe.cpp" -framework AudioToolbox -framework CoreFoundation \
  -o "$DEST/AudioUnitFactoryProbe" > "$DEST/factory-probe.compile.log" 2>&1
/usr/bin/lipo "$DEST/AudioUnitFactoryProbe" -verify_arch arm64
"${compiler[@]}" -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -fobjc-arc \
  "$ROOT/tests/AudioUnitEditorProbe.mm" -lobjc -framework AppKit -framework Foundation -framework AudioToolbox -framework CoreFoundation \
  -o "$DEST/AudioUnitEditorProbe" > "$DEST/editor-probe.compile.log" 2>&1
/usr/bin/lipo "$DEST/AudioUnitEditorProbe" -verify_arch arm64
"${compiler[@]}" -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -fobjc-arc \
  "$ROOT/tests/AudioUnitRemoteHostProbe.mm" -lobjc -framework AppKit -framework Foundation -framework AudioToolbox \
  -o "$DEST/AudioUnitRemoteHostProbe" > "$DEST/remote-host-probe.compile.log" 2>&1
/usr/bin/lipo "$DEST/AudioUnitRemoteHostProbe" -verify_arch arm64
"${compiler[@]}" -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -fobjc-arc \
  "$ROOT/tests/InstalledAUInspector.mm" -framework Foundation -framework AudioToolbox \
  -o "$DEST/InstalledAUInspector" > "$DEST/inspector.compile.log" 2>&1
/usr/bin/lipo "$DEST/InstalledAUInspector" -verify_arch arm64
"${compiler[@]}" -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -fno-fast-math -ffp-contract=off \
  "$ROOT/tests/PcmConversionProbe.cpp" -framework AudioToolbox \
  -o "$DEST/PcmConversionProbe" > "$DEST/pcm-probe.compile.log" 2>&1
/usr/bin/lipo "$DEST/PcmConversionProbe" -verify_arch arm64
"${compiler[@]}" -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -fno-fast-math -ffp-contract=off \
  "$ROOT/tests/NativeAUBridgeProbe.cpp" "$DEST/host/LegacyEngine.o" "$DEST/host/LegacyImageData.o" \
  "$CORE/LifterRuntime.o" "$CORE/Dispatch.o" "$CORE"/Unit*.o -framework CoreFoundation \
  -o "$DEST/NativeAUBridgeProbe" > "$DEST/bridge-probe.compile.log" 2>&1
/usr/bin/lipo "$DEST/NativeAUBridgeProbe" -verify_arch arm64
"${compiler[@]}" -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -fno-fast-math -ffp-contract=off \
  "$ROOT/tests/NativeBankDiagnosticsProbe.cpp" "$DEST/host/LegacyEngine.o" "$DEST/host/LegacyImageData.o" \
  "$CORE/LifterRuntime.o" "$CORE/Dispatch.o" "$CORE"/Unit*.o -framework CoreFoundation \
  -o "$DEST/NativeBankDiagnosticsProbe" > "$DEST/bank-probe.compile.log" 2>&1
/usr/bin/lipo "$DEST/NativeBankDiagnosticsProbe" -verify_arch arm64
"${compiler[@]}" -std=c++17 -arch arm64 -mmacosx-version-min=11.0 -O2 -fno-fast-math -ffp-contract=off -fobjc-arc \
  "$ROOT/src/au/ConfigureSophistry.mm" "$DEST/host/LegacyEngine.o" "$DEST/host/LegacyImageData.o" \
  "$CORE/LifterRuntime.o" "$CORE/Dispatch.o" "$CORE"/Unit*.o \
  -lobjc -framework AppKit -framework Foundation -framework CoreFoundation \
  -o "$DEST/ConfigureSophistry" > "$DEST/configure.compile.log" 2>&1
/usr/bin/lipo "$DEST/ConfigureSophistry" -verify_arch arm64
/usr/bin/codesign --force --sign - --timestamp=none "$DEST/ConfigureSophistry"
printf '%s\n' "$bundle" "$DEST/AudioUnitFactoryProbe"
