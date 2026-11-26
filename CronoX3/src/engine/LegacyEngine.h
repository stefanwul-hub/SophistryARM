#pragma once
#include "CompleteEditorControls.h"
#include "GeneratorControls.h"
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <optional>
#include <string>
#include <vector>
namespace sophistry {

// A lazily backed address arena. Physical pages are used as samples load.
constexpr std::size_t productionGuestMemoryBytes = 1024u * 1024u * 1024u;

// Integration in progress: this host does not by itself implement an Audio
// Unit.
struct LegacyEngineConfig {
  std::vector<std::string> assetDirectories;
  bool deterministicTestHost = true;
  // Native monotonic ticks and timebase for an actual AU host. Kept separate
  // from deterministic wall-clock/random inputs used by existing references.
  bool nativeMonotonicClock = false;
  // Optional clock for deterministic run-loop callback tests (CF absolute seconds).
  std::function<double()> runLoopClock;
  bool useLocalMacPreferences = false;
  bool recycleFreedBlocks = false;
  bool audioUnitMode = false;
  // Direct, original-instruction-checked reverb loops. Unsupported objects
  // keep using the complete generated code, as do existing reference tests.
  bool nativeCronoXReverb = false;
  // Constant calibration before the original Master multiplication. Raw dB,
  // normalized automation and serialized presets remain original.
  float preMasterGainDb = 0;
  std::uint32_t audioUnitOutputChannels = 2;
  bool collectDiagnostics = true;
  bool recursiveAssetSearch = false;
  std::function<void(std::uint32_t, std::uint32_t)> parameterEvent;
  // Optional private input. Passed to the original SysGlo string setter;
  // the original registration check decides whether it is accepted.
  std::string privateRegistration;
  std::size_t guestMemoryBytes = 64u * 1024u * 1024u;
};

struct LegacyAUParameterInfo {
  std::uint32_t id = 0, flags = 0, unit = 0, clump = 0;
  std::string name, unitName;
  float minimum = 0, maximum = 0, defaultValue = 0;
  std::vector<std::string> valueStrings;
};
struct LegacyAUParameterText {
  std::int32_t status = 0;
  // A null string is a successful, documented request for the host to
  // display an ordinary numeric value (for example, a non-minimum dB value).
  std::optional<std::string> text;
};
struct LegacyTransport {
  double samplePosition = 0, tempo = 120, beat = 0, measureStartBeat = 0;
  double cycleStartBeat = 0, cycleEndBeat = 0;
  std::uint64_t hostTime = 0;
  float timeSignatureNumerator = 4;
  std::uint32_t timeSignatureDenominator = 4, samplesToNextBeat = 0;
  bool tempoValid = false, transportValid = false, musicalLocationValid = false;
  bool playing = false, changed = false, cycling = false;
};

class LegacyEngine {
public:
  explicit LegacyEngine(LegacyEngineConfig config);
  ~LegacyEngine();
  LegacyEngine(const LegacyEngine &) = delete;
  LegacyEngine &operator=(const LegacyEngine &) = delete;
  void initialize();
  // Caller serializes this with all engine calls; invoke on a control thread.
  std::uint32_t serviceTimers();
  // Executes the original destructor, then makes this instance unusable.
  void shutdown();
  void restoreChunk(const std::vector<std::uint8_t> &chunk, bool program);
  std::string presetName();
  // Rebuild the read-only asset index after a local bank selection. The
  // translated engine and current program are retained.
  void setAssetDirectories(const std::vector<std::string> &directories);
  std::vector<std::uint8_t> saveProgram();
  std::vector<std::uint8_t> saveBank();
  std::vector<std::uint32_t> auParameterIds();
  bool validAUParameter(std::uint32_t id);
  LegacyAUParameterInfo auParameterInfo(std::uint32_t id);
  LegacyAUParameterText
  auParameterText(std::uint32_t id, std::optional<float> value = std::nullopt);
  float auParameter(std::uint32_t id);
  void setAUParameter(std::uint32_t id, float value);
  GeneratorPanelState generatorPanel(unsigned pair);
  void setGeneratorControl(std::uint32_t tag, float normalized);
  EditorPanelState editorPanel(unsigned panel);
  void setEditorControl(std::uint32_t tag, float normalized);
  EditorDrawing editorDrawing(unsigned id);
  EditorDrawing editorDrawing(unsigned id,const std::function<void()> &betweenColumns);
  CompleteEditorState completeEditor(unsigned page);
  CompleteEditorState
  completeEditor(unsigned page, const std::function<void()> &betweenControls);
  EditorChoices editorChoices(std::uint32_t tag);
  std::string editorString(std::uint32_t tag);
  void setEditorString(std::uint32_t tag, const std::string &text);
  void editorAction(unsigned key);
  EditorKeyHit editorKeyHit(unsigned x, unsigned y);
  EditorKeyboardState editorKeyboardState();
  float editorKnob(unsigned key, int x, int y);
  EditorFileInfo editorFileInfo(std::uint32_t tag, unsigned operation);
  void editorFileOperation(std::uint32_t tag, unsigned operation,
                           const std::string &path);
  void setSampleRate(float rate);
  void setBlockSize(std::uint32_t frames);
  void activate();
  void deactivate();
  void resetAudioUnit(std::uint32_t scope = 0, std::uint32_t element = 0);
  void setAudioUnitOutputChannels(std::uint32_t channels);
  void setTransport(const LegacyTransport &transport);
  void setPrivateRegistration(const std::string &registration);
  // Uses the original SysGlo serializer and refuses to write unless the
  // original registration check has accepted this active instance.
  void persistValidatedRegistration();
  void midi(std::uint8_t status, std::uint8_t data1, std::uint8_t data2,
            std::uint32_t delta = 0);
  void process(float *const *outputs, std::uint32_t channels,
               std::uint32_t frames);
  std::uint32_t outputChannels() const;
  bool registrationAccepted() const;
  std::vector<std::uint8_t> objectSnapshot() const;
  std::vector<std::uint8_t> heapSnapshot() const;
  std::vector<std::uint8_t> globalSnapshot() const;
  std::string diagnosticJson() const;

private:
  struct Impl;
  std::unique_ptr<Impl> impl_;
};
} // namespace sophistry
