#include "../engine/LegacyEngine.h"
#include "BankAccess.h"
#include "SophistryProperties.h"
#include "OutputGain.h"
#include "CronoXPresetNames.h"
#include "CronoXIdentity.h"
#include <atomic>
#include <condition_variable>
#include <AudioUnitSDK/AUPlugInDispatch.h>
#include <AudioUnitSDK/MusicDeviceBase.h>
#include <algorithm>
#include <array>
#include <cmath>
#include <cstring>
#include <dlfcn.h>
#include <filesystem>
#include <map>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <type_traits>
#include <vector>

namespace {
constexpr AudioUnitPropertyID registrationProperty =
    0x53705267; // SpRg, write-only CFStringRef.
constexpr AudioUnitPropertyID errorProperty =
    0x53704572; // SpEr, retained CFStringRef.
constexpr AudioUnitPropertyID diagnosticsProperty =
    0x53704469; // SpDi, retained CFStringRef.
constexpr AudioUnitPropertyID wrapperVersionProperty = 0x53705672; // SpVr.
constexpr UInt32 sophistrySubtype = cronox::identity::subtype, cronoSubtype = cronox::identity::originalSubtype,
                 linplug = 0x4c696e50;
bool usablePresetName(const std::string& name) { return cronox::usablePresetName(name); }
struct EditorReadInterrupted {};
std::string jsonText(const std::string &text) {
  std::string result = "\"";
  for (unsigned char c : text) {
    if (c == '"' || c == '\\')
      result += '\\';
    if (c < 32)
      result += ' ';
    else
      result += char(c);
  }
  return result + '"';
}
CFURLRef editorBundleURL() {
  Dl_info info{};
  if (!dladdr(reinterpret_cast<const void *>(&editorBundleURL), &info) ||
      !info.dli_fname)
    return nullptr;
  const auto path = std::filesystem::path(info.dli_fname)
                        .parent_path()
                        .parent_path()
                        .parent_path()
                        .string();
  return CFURLCreateFromFileSystemRepresentation(
      nullptr, reinterpret_cast<const UInt8 *>(path.data()), path.size(), true);
}
std::string text(CFStringRef s) {
  if (!s)
    return {};
  CFIndex n = CFStringGetMaximumSizeForEncoding(CFStringGetLength(s),
                                                kCFStringEncodingUTF8) +
              1;
  if (n < 1 || n > 1048576)
    throw std::runtime_error("Invalid CFString length");
  std::vector<char> b(static_cast<std::size_t>(n));
  if (!CFStringGetCString(s, b.data(), n, kCFStringEncodingUTF8))
    throw std::runtime_error("Invalid UTF-8 string");
  return b.data();
}
struct HostedConfiguration {
  sophistry::LegacyEngineConfig engine;
  std::shared_ptr<sophistryMac::BankAccess> bankAccess;
};
HostedConfiguration configuration() {
  HostedConfiguration result;
  auto &c = result.engine;
  c.nativeCronoXReverb = true;
  c.audioUnitMode = true;
  c.preMasterGainDb = sophistry::outputGainDb;
  c.useLocalMacPreferences = true;
  c.recycleFreedBlocks = true;
  c.collectDiagnostics = false;
  c.recursiveAssetSearch = true;
  c.guestMemoryBytes = sophistry::productionGuestMemoryBytes;
  // Preserve the reference wall-clock/random inputs while supplying actual
  // monotonic time. The original AU timestamps retain the same Mach units.
  c.deterministicTestHost = true;
  c.nativeMonotonicClock = true;
  Dl_info location{};
  if (dladdr(reinterpret_cast<const void *>(&configuration), &location) &&
      location.dli_fname) {
    const auto root =
        std::filesystem::path(location.dli_fname).parent_path().parent_path() /
        "Resources";
    c.assetDirectories.push_back((root / "Samples").string());
    c.assetDirectories.push_back((root / "Presets").string());
  } else if (CFBundleRef bundle = CFBundleGetBundleWithIdentifier(
                 CFSTR("com.linplug.au.CronoX3.ARMTest"))) {
    if (CFURLRef url = CFBundleCopyResourcesDirectoryURL(bundle)) {
      std::array<UInt8, 4096> p{};
      if (CFURLGetFileSystemRepresentation(url, true, p.data(), p.size())) {
        std::string root(reinterpret_cast<char *>(p.data()));
        c.assetDirectories.push_back(root + "/Samples");
        c.assetDirectories.push_back(root + "/Presets");
      }
      CFRelease(url);
    }
  }
  CFPropertyListRef root = CFPreferencesCopyValue(
      CFSTR("CronoX3ARMSampleRoot"), CFSTR("com.linplug.CronoX3.ARMTest"),
      kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
  if (root) {
    if (CFGetTypeID(root) == CFStringGetTypeID()) {
      result.bankAccess =
          sophistryMac::storedBankAccess(text(static_cast<CFStringRef>(root)));
      c.assetDirectories.insert(c.assetDirectories.begin(),
                                text(static_cast<CFStringRef>(root)));
    }
    CFRelease(root);
  }
  return result;
}
} // namespace

class CronoX3ARMTestAU final : public ausdk::MusicDeviceBase {
  using Base = ausdk::MusicDeviceBase;
  std::recursive_mutex mutex_;
  std::mutex timerWaitMutex_;
  std::condition_variable timerWake_;
  std::atomic<bool> timerStop_{true};
  std::thread timerThread_;
  void startControlTimer() {
    if(timerThread_.joinable()) return;
    timerStop_.store(false);
    timerThread_=std::thread([this] {
      while(!timerStop_.load()) {
        {
          std::unique_lock<std::recursive_mutex> lock(mutex_,std::try_to_lock);
          if(lock.owns_lock() && !timerStop_.load()) {
            try { (void)engine_.serviceTimers(); }
            catch(const std::exception& error) { lastError_=error.what(); }
          }
        }
        std::unique_lock<std::mutex> wait(timerWaitMutex_);
        timerWake_.wait_for(wait,std::chrono::milliseconds(10),[this]{return timerStop_.load();});
      }
    });
  }
  void stopControlTimer() {
    timerStop_.store(true);timerWake_.notify_all();
    if(timerThread_.joinable()) timerThread_.join();
  }

  std::uint64_t editorGeneration_ = 0;
  HostedConfiguration config_;
  sophistry::LegacyEngine engine_;
  std::vector<UInt32> parameters_;
  std::map<UInt32, AudioUnitParameterInfo> metadata_;
  bool activated_ = false;
  double previousSample_ = 0;
  bool rendered_ = false;
  std::string lastError_;
  std::string lastKnownPresetName_,lastKnownBankName_,lastKnownPresetSource_;
  std::vector<std::uint8_t> lastRestoredChunk_;
  bool lastRestoredProgram_ = false, stateLoaded_ = false;
  std::uint64_t restoreAttempts_ = 0, notesReceived_ = 0, renderCalls_ = 0;
  std::uint64_t nonfiniteSamples_ = 0;
  UInt32 lastMidiChannel_ = 0, lastMidiNote_ = 0, lastMidiOffset_ = 0;
  OSStatus lastRestoreStatus_ = noErr;
  double maximumOutput_ = 0;
  void syncPresetLabel() {
    if (!usablePresetName(lastKnownPresetName_))
      return;
    CFStringRef name = CFStringCreateWithCString(
        nullptr, lastKnownPresetName_.c_str(), kCFStringEncodingUTF8);
    if (!name)
      name = CFStringCreateWithBytes(
          nullptr, reinterpret_cast<const UInt8 *>(lastKnownPresetName_.data()),
          CFIndex(lastKnownPresetName_.size()), kCFStringEncodingMacRoman,
          false);
    if (!name)
      throw std::runtime_error("Cannot encode AU preset name");
    lastKnownPresetName_ = text(name);
    const OSStatus status = Base::NewCustomPresetSet(AUPreset{-1, name});
    CFRelease(name);
    if (status)
      throw std::runtime_error("Cannot update AU preset name");
    PropertyChanged(kAudioUnitProperty_PresentPreset, kAudioUnitScope_Global,
                    0);
  }
  void syncParameters() {
    for (UInt32 id : parameters_)
      Globals()->SetParameter(id, engine_.auParameter(id));
  }
  void loadChunk(const std::vector<std::uint8_t> &bytes, bool program,
                 bool countAttempt = true) {
    ++editorGeneration_;
    const auto previousLabel =
        bytes == lastRestoredChunk_ && program == lastRestoredProgram_
            ? lastKnownPresetName_
            : std::string();
    const auto previousBank=bytes==lastRestoredChunk_&&program==lastRestoredProgram_?lastKnownBankName_:std::string();
    const auto previousSource=bytes==lastRestoredChunk_&&program==lastRestoredProgram_?lastKnownPresetSource_:std::string();
    lastRestoredChunk_ = bytes;
    lastRestoredProgram_ = program;
    if (countAttempt)
      ++restoreAttempts_;
    lastError_.clear();
    stateLoaded_ = false;
    lastRestoreStatus_ = kAudioUnitErr_InvalidPropertyValue;
    engine_.restoreChunk(bytes, program);
    syncParameters();
    lastKnownPresetName_ = engine_.presetName();
    lastKnownBankName_=previousBank;
    lastKnownPresetSource_=previousSource;
    if (!usablePresetName(lastKnownPresetName_) &&
        !previousLabel.empty())
      lastKnownPresetName_ = previousLabel;
    syncPresetLabel();
    stateLoaded_ = true;
    lastRestoreStatus_ = noErr;
    notesReceived_ = renderCalls_ = 0;
    maximumOutput_ = 0;
    nonfiniteSamples_ = 0;
    lastError_.clear();
  }
  std::string runtimeStatus() {
    std::ostringstream out;
    out << "{\"wrapper_version\":" << jsonText(sophistry::wrapperVersion)
        << ",\"preset_name\":" << jsonText(lastKnownPresetName_)
        << ",\"preset_bank_name\":" << jsonText(lastKnownBankName_)
        << ",\"state_loaded\":" << (stateLoaded_ ? "true" : "false")
        << ",\"restore_attempts\":" << restoreAttempts_
        << ",\"restore_status\":" << lastRestoreStatus_
        << ",\"restored_bytes\":" << lastRestoredChunk_.size()
        << ",\"notes_received\":" << notesReceived_ << ",\"last_midi_channel\":"
        << (notesReceived_ ? std::to_string(lastMidiChannel_ + 1) : "null")
        << ",\"last_midi_note\":"
        << (notesReceived_ ? std::to_string(lastMidiNote_) : "null")
        << ",\"last_midi_offset\":"
        << (notesReceived_ ? std::to_string(lastMidiOffset_) : "null")
        << ",\"sample_rate\":" << Output(0).GetStreamFormat().mSampleRate
        << ",\"maximum_frames\":" << GetMaxFramesPerSlice()
        << ",\"render_calls\":" << renderCalls_
        << ",\"maximum_output\":" << maximumOutput_
        << ",\"master_volume_db\":" << engine_.auParameter(134)
        << ",\"output_compensation_db\":" << sophistry::outputGainDb
        << ",\"nonfinite_samples\":" << nonfiniteSamples_
        << ",\"bank_bookmark_available\":"
        << (config_.bankAccess ? "true" : "false")
        << ",\"bank_security_scope_started\":"
        << (config_.bankAccess && config_.bankAccess->granted ? "true"
                                                              : "false")
        << ",\"error\":" << jsonText(lastError_)
        << ",\"engine\":" << engine_.diagnosticJson() << '}';
    return out.str();
  }
  template <class F> OSStatus guarded(F &&f) {
    std::unique_lock<std::recursive_mutex> lock(mutex_);
    try {
      if constexpr (std::is_invocable_v<F, decltype(lock) &>)
        return f(lock);
      else
        return f();
    } catch (const EditorReadInterrupted &) {
      return kAudioUnitErr_CannotDoInCurrentContext;
    } catch (const std::out_of_range &e) {
      if (lastError_.empty())
        lastError_ = e.what();
      return kAudioUnitErr_InvalidParameter;
    } catch (const std::exception &e) {
      if (lastError_.empty())
        lastError_ = e.what();
      return kAudioUnitErr_FailedInitialization;
    } catch (...) {
      if (lastError_.empty())
        lastError_ = "Unknown native exception";
      return kAudioUnitErr_FailedInitialization;
    }
  }
  template <class F> OSStatus edited(F &&f) {
    return guarded([&]() -> OSStatus {
      ++editorGeneration_;
      return f();
    });
  }

public:
  OSStatus NewCustomPresetSet(const AUPreset &preset) override {
    return guarded([&]() -> OSStatus {
      if (!preset.presetName)
        return kAudioUnitErr_InvalidPropertyValue;
      const auto incoming = text(preset.presetName);
      if (usablePresetName(incoming)) {
        const auto status = Base::NewCustomPresetSet(preset);
        if (!status)
          lastKnownPresetName_ = incoming;
        return status;
      }
      // Some hosts assign a generic custom-preset label after restoring the
      // bank. Keep the original label in both the view and standard AU API.
      if (usablePresetName(lastKnownPresetName_)) {
        syncPresetLabel();
        return noErr;
      }
      return Base::NewCustomPresetSet(preset);
    });
  }
  explicit CronoX3ARMTestAU(AudioComponentInstance instance)
      : Base(instance, 0, 1), config_(configuration()),
        engine_(config_.engine) {
    CreateElements();
    engine_.initialize();
    parameters_ = engine_.auParameterIds();
    for (UInt32 id : parameters_)
      Globals()->SetParameter(id, engine_.auParameter(id));
    lastKnownPresetName_ = engine_.presetName();
    syncPresetLabel();
  }
  ~CronoX3ARMTestAU() override {
    stopControlTimer();
    try { engine_.shutdown(); } catch(...) { }

    for (auto &item : metadata_) {
      if (item.second.cfNameString)
        CFRelease(item.second.cfNameString);
      if (item.second.unitName)
        CFRelease(item.second.unitName);
    }
  }
  bool CanScheduleParameters() const override { return false; }
  bool StreamFormatWritable(AudioUnitScope scope,
                            AudioUnitElement element) override {
    return (scope == kAudioUnitScope_Global ||
            scope == kAudioUnitScope_Output) &&
           element == 0;
  }
  UInt32 SupportedNumChannels(const AUChannelInfo **info) override {
    static const AUChannelInfo formats[] = {{0, 2}, {0, 6}};
    if (info)
      *info = formats;
    return 2;
  }
  bool ValidFormat(AudioUnitScope scope, AudioUnitElement element,
                   const AudioStreamBasicDescription &f) override {
    return (scope == kAudioUnitScope_Global ||
            scope == kAudioUnitScope_Output) &&
           element == 0 && f.mFormatID == kAudioFormatLinearPCM &&
           f.mFramesPerPacket == 1 && f.mBytesPerFrame == 4 &&
           f.mBytesPerPacket == 4 && f.mBitsPerChannel == 32 &&
           (f.mFormatFlags & kAudioFormatFlagIsFloat) &&
           (f.mFormatFlags & kAudioFormatFlagIsNonInterleaved) &&
           !(f.mFormatFlags & kAudioFormatFlagIsBigEndian) &&
           (f.mChannelsPerFrame == 2 || f.mChannelsPerFrame == 6) &&
           f.mSampleRate >= 8000 && f.mSampleRate <= 384000;
  }
  OSStatus Initialize() override {
    return edited([&]() -> OSStatus {
      const auto &f = Output(0).GetStreamFormat();
      engine_.setAudioUnitOutputChannels(f.mChannelsPerFrame);
      engine_.setSampleRate(float(f.mSampleRate));
      engine_.setBlockSize(GetMaxFramesPerSlice());
      engine_.activate();
      activated_ = true;
      startControlTimer();
      rendered_ = false;
      return noErr;
    });
  }
  void Cleanup() override {
    stopControlTimer();
    edited([&]() -> OSStatus {
      engine_.deactivate();
      activated_ = false;
      return noErr;
    });
  }
  OSStatus Reset(AudioUnitScope scope, AudioUnitElement element) override {
    return edited([&]() -> OSStatus {
      if (scope != kAudioUnitScope_Global && scope != kAudioUnitScope_Output)
        return OSStatus(kAudioUnitErr_InvalidScope);
      if (element)
        return OSStatus(kAudioUnitErr_InvalidElement);
      if (activated_)
        engine_.resetAudioUnit(scope, element);
      rendered_ = false;
      return noErr;
    });
  }
  OSStatus GetParameterList(AudioUnitScope scope, AudioUnitParameterID *ids,
                            UInt32 &count) override {
    if (scope != kAudioUnitScope_Global) {
      count = 0;
      return noErr;
    }
    count = UInt32(parameters_.size());
    if (ids)
      std::copy(parameters_.begin(), parameters_.end(), ids);
    return noErr;
  }
  OSStatus GetParameterInfo(AudioUnitScope scope, AudioUnitParameterID id,
                            AudioUnitParameterInfo &info) override {
    if (scope != kAudioUnitScope_Global)
      return kAudioUnitErr_InvalidScope;
    return guarded([&]() -> OSStatus {
      auto found = metadata_.find(id);
      if (found == metadata_.end()) {
        auto p = engine_.auParameterInfo(id);
        AudioUnitParameterInfo v{};
        std::strncpy(v.name, p.name.c_str(), sizeof(v.name) - 1);
        v.cfNameString = CFStringCreateWithCString(nullptr, p.name.c_str(),
                                                   kCFStringEncodingUTF8);
        if (!p.unitName.empty())
          v.unitName = CFStringCreateWithCString(nullptr, p.unitName.c_str(),
                                                 kCFStringEncodingUTF8);
        v.clumpID = p.clump;
        v.unit = AudioUnitParameterUnit(p.unit);
        v.minValue = p.minimum;
        v.maxValue = p.maximum;
        v.defaultValue = p.defaultValue;
        v.flags = AudioUnitParameterOptions(
            p.flags & ~UInt32(kAudioUnitParameterFlag_CFNameRelease));
        found = metadata_.emplace(id, v).first;
      }
      info = found->second;
      return noErr;
    });
  }
  OSStatus GetParameter(AudioUnitParameterID id, AudioUnitScope scope,
                        AudioUnitElement element,
                        AudioUnitParameterValue &value) override {
    if (scope != kAudioUnitScope_Global)
      return kAudioUnitErr_InvalidScope;
    if (element)
      return kAudioUnitErr_InvalidElement;
    return guarded([&]() -> OSStatus {
      value = engine_.auParameter(id);
      return noErr;
    });
  }
  OSStatus SetParameter(AudioUnitParameterID id, AudioUnitScope scope,
                        AudioUnitElement element, AudioUnitParameterValue value,
                        UInt32) override {
    if (scope != kAudioUnitScope_Global)
      return kAudioUnitErr_InvalidScope;
    if (element)
      return kAudioUnitErr_InvalidElement;
    return edited([&]() -> OSStatus {
      engine_.setAUParameter(id, value);
      Globals()->SetParameter(id, engine_.auParameter(id));
      return noErr;
    });
  }
  OSStatus GetParameterValueStrings(AudioUnitScope scope,
                                    AudioUnitParameterID id,
                                    CFArrayRef *out) override {
    if (scope != kAudioUnitScope_Global)
      return kAudioUnitErr_InvalidScope;
    return guarded([&]() -> OSStatus {
      auto p = engine_.auParameterInfo(id);
      if (p.valueStrings.empty())
        return OSStatus(kAudioUnitErr_InvalidProperty);
      if (!out)
        return noErr;
      CFMutableArrayRef array =
          CFArrayCreateMutable(nullptr, 0, &kCFTypeArrayCallBacks);
      if (!array)
        return OSStatus(-108);
      for (const auto &label : p.valueStrings) {
        CFStringRef s = CFStringCreateWithCString(nullptr, label.c_str(),
                                                  kCFStringEncodingUTF8);
        if (!s) {
          CFRelease(array);
          return OSStatus(kAudioUnitErr_InvalidPropertyValue);
        }
        CFArrayAppendValue(array, s);
        CFRelease(s);
      }
      *out = array;
      return noErr;
    });
  }
  OSStatus GetPropertyInfo(AudioUnitPropertyID id, AudioUnitScope scope,
                           AudioUnitElement element, UInt32 &bytes,
                           bool &writable) override {
    if(id==sophistry::keyboardStateProperty || id==sophistry::presetSourceProperty) {
      if(scope!=kAudioUnitScope_Global||element)return kAudioUnitErr_InvalidScope;
      writable=id==sophistry::presetSourceProperty;
      bytes=writable?sophistry::presetSourceBytes:sizeof(sophistry::EditorKeyboardState);return noErr;
    }
    if(id==sophistry::presetBankNameProperty) {
      if(scope!=kAudioUnitScope_Global||element)return kAudioUnitErr_InvalidScope;
      bytes=sophistry::presetBankNameBytes;writable=true;return noErr;
    }
    if (id == sophistry::editorPanelProperty || id == sophistry::generatorPanelProperty || id == sophistry::generatorEditProperty) return kAudioUnitErr_InvalidProperty;
    if (id == sophistry::editorKnobProperty) {
      const auto key = element & 2047;
      if (scope != kAudioUnitScope_Global || element >> 31 ||
          key >= sophistry::recoveredControls().size() ||
          !sophistry::originalPointerKind(
              sophistry::recoveredControls()[key].kind))
        return kAudioUnitErr_InvalidPropertyValue;
      bytes = sizeof(float);
      writable = false;
      return noErr;
    }
    if (id == sophistry::editorFileInfoProperty ||
        id == sophistry::editorFileProperty) {
      if (scope != kAudioUnitScope_Global)
        return kAudioUnitErr_InvalidScope;
      writable = id == sophistry::editorFileProperty;
      if (writable
              ? element != 0
              : !sophistry::editorFileCommand(element & 65535, element >> 16))
        return kAudioUnitErr_InvalidElement;
      bytes = writable ? sizeof(sophistry::EditorFileRequest) + 256
                       : sizeof(sophistry::EditorFileInfo);
      return noErr;
    }
    if (id == sophistry::editorKeyHitProperty) {
      if (scope != kAudioUnitScope_Global || (element & 1023) >= 648 ||
          (element >> 10) >= 95)
        return kAudioUnitErr_InvalidPropertyValue;
      bytes = sizeof(sophistry::EditorKeyHit);
      writable = false;
      return noErr;
    }
    if (id == sophistry::completeEditorProperty ||
        id == sophistry::editorChoicesProperty ||
        id == sophistry::editorStringProperty ||
        id == sophistry::editorTextEditProperty ||
        id == sophistry::editorActionProperty) {
      if (scope != kAudioUnitScope_Global)
        return kAudioUnitErr_InvalidScope;
      writable = id == sophistry::editorTextEditProperty ||
                 id == sophistry::editorActionProperty;
      if ((id == sophistry::completeEditorProperty && element > 9) ||
          (writable && element) ||
          (!writable && id != sophistry::completeEditorProperty &&
           !sophistry::completeControlReadable(element)))
        return kAudioUnitErr_InvalidElement;
      bytes = id == sophistry::completeEditorProperty
                  ? sizeof(sophistry::CompleteEditorState)
              : id == sophistry::editorChoicesProperty
                  ? sizeof(sophistry::EditorChoices)
              : id == sophistry::editorActionProperty
                  ? sizeof(sophistry::EditorAction)
                  : sophistry::editorStringBytes;
      return noErr;
    }
    if (id == sophistry::editorPanelProperty ||
        id == sophistry::editorDrawingProperty ||
        id == sophistry::editorEditProperty) {
      if (scope != kAudioUnitScope_Global)
        return kAudioUnitErr_InvalidScope;
      if (element > (id == sophistry::editorPanelProperty     ? 1u
                     : id == sophistry::editorDrawingProperty ? 9u
                                                              : 0u))
        return kAudioUnitErr_InvalidElement;
      writable = id == sophistry::editorEditProperty;
      bytes = writable ? sizeof(sophistry::GeneratorControlEdit)
              : id == sophistry::editorPanelProperty
                  ? sizeof(sophistry::EditorPanelState)
                  : sizeof(sophistry::EditorDrawing);
      return noErr;
    }
    if (id == sophistry::generatorPanelProperty ||
        id == sophistry::generatorEditProperty) {
      if (scope != kAudioUnitScope_Global)
        return kAudioUnitErr_InvalidScope;
      if (element > (id == sophistry::generatorPanelProperty ? 1u : 0u))
        return kAudioUnitErr_InvalidElement;
      writable = id == sophistry::generatorEditProperty;
      bytes = writable ? sizeof(sophistry::GeneratorControlEdit)
                       : sizeof(sophistry::GeneratorPanelState);
      return noErr;
    }
    if (id == kAudioUnitProperty_CocoaUI ||
        id == sophistry::runtimeStatusProperty ||
        id == sophistry::importProgramProperty ||
        id == sophistry::sampleRootProperty ||
        id == sophistry::reloadStateProperty) {
      if (scope != kAudioUnitScope_Global || element)
        return kAudioUnitErr_InvalidScope;
      bytes = id == kAudioUnitProperty_CocoaUI ? sizeof(AudioUnitCocoaViewInfo)
              : id == sophistry::reloadStateProperty ? sizeof(UInt32)
              : id == sophistry::runtimeStatusProperty
                  ? sophistry::runtimeStatusBytes
                  : 1;
      writable = id == sophistry::importProgramProperty ||
                 id == sophistry::sampleRootProperty ||
                 id == sophistry::reloadStateProperty;
      return noErr;
    }
    if (id == kAudioUnitProperty_ParameterStringFromValue) {
      if (scope != kAudioUnitScope_Global)
        return kAudioUnitErr_InvalidScope;
      if (element)
        return kAudioUnitErr_InvalidElement;
      bytes = sizeof(AudioUnitParameterStringFromValue);
      writable = false;
      return noErr;
    }
    if (id == errorProperty || id == diagnosticsProperty ||
        id == wrapperVersionProperty) {
      if (scope != kAudioUnitScope_Global || element)
        return kAudioUnitErr_InvalidScope;
      bytes = sizeof(CFStringRef);
      writable = false;
      return noErr;
    }
    if (id == registrationProperty) {
      if (scope != kAudioUnitScope_Global || element)
        return kAudioUnitErr_InvalidScope;
      bytes = sizeof(CFStringRef);
      writable = true;
      return noErr;
    }
    return Base::GetPropertyInfo(id, scope, element, bytes, writable);
  }
  OSStatus GetProperty(AudioUnitPropertyID id, AudioUnitScope scope,
                       AudioUnitElement element, void *data) override {
    if(id==sophistry::keyboardStateProperty || id==sophistry::presetSourceProperty) {
      if(scope!=kAudioUnitScope_Global||element||!data)return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]()->OSStatus {
        if(id==sophistry::keyboardStateProperty)*static_cast<sophistry::EditorKeyboardState*>(data)=engine_.editorKeyboardState();
        else {std::memset(data,0,sophistry::presetSourceBytes);std::memcpy(data,lastKnownPresetSource_.data(),std::min<std::size_t>(lastKnownPresetSource_.size(),sophistry::presetSourceBytes-1));}
        return noErr;
      });
    }
    if(id==sophistry::presetBankNameProperty) {
      if(scope!=kAudioUnitScope_Global||element||!data)return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]()->OSStatus {
        std::memset(data,0,sophistry::presetBankNameBytes);
        std::memcpy(data,lastKnownBankName_.data(),std::min<std::size_t>(lastKnownBankName_.size(),sophistry::presetBankNameBytes-1));return noErr;
      });
    }
    if (id == sophistry::editorPanelProperty || id == sophistry::generatorPanelProperty || id == sophistry::generatorEditProperty) return kAudioUnitErr_InvalidProperty;
    if (id == sophistry::editorKnobProperty) {
      if (scope != kAudioUnitScope_Global || !data || element >> 31)
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]() -> OSStatus {
        *static_cast<float *>(data) = engine_.editorKnob(
            element & 2047, int((element >> 11) & 1023) - 512,
            int((element >> 21) & 1023) - 512);
        return noErr;
      });
    }
    if (id == sophistry::editorFileInfoProperty) {
      if (scope != kAudioUnitScope_Global || !data ||
          !sophistry::editorFileCommand(element & 65535, element >> 16))
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]() -> OSStatus {
        *static_cast<sophistry::EditorFileInfo *>(data) =
            engine_.editorFileInfo(element & 65535, element >> 16);
        return noErr;
      });
    }
    if (id == sophistry::editorKeyHitProperty) {
      if (scope != kAudioUnitScope_Global || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]() -> OSStatus {
        *static_cast<sophistry::EditorKeyHit *>(data) =
            engine_.editorKeyHit(element & 1023, element >> 10);
        return noErr;
      });
    }
    if (id == sophistry::completeEditorProperty) {
      if (scope != kAudioUnitScope_Global || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded(
          [&](std::unique_lock<std::recursive_mutex> &lock) -> OSStatus {
            const auto generation = editorGeneration_;
            const auto snapshot = engine_.completeEditor(element, [&] {
              // Never retain the engine across the entire panel's getter loop.
              // Audio can run only after each original getter has fully
              // returned.
              lock.unlock();
              std::this_thread::yield();
              lock.lock();
              if (generation != editorGeneration_)
                throw EditorReadInterrupted{};
            });
            *static_cast<sophistry::CompleteEditorState *>(data) = snapshot;
            return noErr;
          });
    }
    if (id == sophistry::editorChoicesProperty ||
        id == sophistry::editorStringProperty) {
      if (scope != kAudioUnitScope_Global || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]() -> OSStatus {
        if (id == sophistry::editorChoicesProperty)
          *static_cast<sophistry::EditorChoices *>(data) =
              engine_.editorChoices(element);
        else {
          const auto value = engine_.editorString(element);
          std::memset(data, 0, sophistry::editorStringBytes);
          std::memcpy(data, value.data(),
                      std::min<std::size_t>(value.size(),
                                            sophistry::editorStringBytes - 1));
        }
        return noErr;
      });
    }
    if (id == sophistry::editorPanelProperty ||
        id == sophistry::editorDrawingProperty) {
      if (scope != kAudioUnitScope_Global || !data ||
          element > (id == sophistry::editorPanelProperty ? 1u : 9u))
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&](std::unique_lock<std::recursive_mutex>& lock) -> OSStatus {
        if (id == sophistry::editorPanelProperty)
          *static_cast<sophistry::EditorPanelState *>(data) =
              engine_.editorPanel(element);
        else
          *static_cast<sophistry::EditorDrawing *>(data) =
              engine_.editorDrawing(element,[&,generation=editorGeneration_] {
                lock.unlock();std::this_thread::yield();lock.lock();
                if(generation!=editorGeneration_)throw EditorReadInterrupted{};
              });
        return noErr;
      });
    }
    if (id == sophistry::generatorPanelProperty) {
      if (scope != kAudioUnitScope_Global || element > 1 || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]() -> OSStatus {
        *static_cast<sophistry::GeneratorPanelState *>(data) =
            engine_.generatorPanel(element);
        return noErr;
      });
    }
    if (id == kAudioUnitProperty_CocoaUI) {
      if (scope != kAudioUnitScope_Global || element || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      auto &info = *static_cast<AudioUnitCocoaViewInfo *>(data);
      info.mCocoaAUViewBundleLocation = editorBundleURL();
      if (!info.mCocoaAUViewBundleLocation)
        return kAudioUnitErr_InvalidPropertyValue;
      info.mCocoaAUViewClass[0] = CFSTR("CronoX3ARMTestCocoaFactory");
      CFRetain(info.mCocoaAUViewClass[0]);
      return noErr;
    }
    if (id == sophistry::runtimeStatusProperty) {
      if (scope != kAudioUnitScope_Global || element || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]() -> OSStatus {
        const auto json = runtimeStatus();
        if (json.size() >= sophistry::runtimeStatusBytes)
          return kAudioUnitErr_InvalidPropertyValue;
        std::memset(data, 0, sophistry::runtimeStatusBytes);
        std::memcpy(data, json.data(), json.size());
        return noErr;
      });
    }
    if (id == kAudioUnitProperty_ParameterStringFromValue) {
      if (scope != kAudioUnitScope_Global)
        return kAudioUnitErr_InvalidScope;
      if (element)
        return kAudioUnitErr_InvalidElement;
      if (!data)
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]() -> OSStatus {
        auto &request = *static_cast<AudioUnitParameterStringFromValue *>(data);
        request.outString = nullptr;
        auto result = engine_.auParameterText(
            request.inParamID, request.inValue
                                   ? std::optional<float>(*request.inValue)
                                   : std::nullopt);
        if (result.status)
          return result.status;
        if (result.text) {
          request.outString = CFStringCreateWithCString(
              nullptr, result.text->c_str(), kCFStringEncodingUTF8);
          if (!request.outString)
            return OSStatus(-108);
        }
        return noErr;
      });
    }
    if (id == errorProperty || id == diagnosticsProperty ||
        id == wrapperVersionProperty) {
      if (scope != kAudioUnitScope_Global || element || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]() -> OSStatus {
        std::string value =
            id == wrapperVersionProperty
                ? sophistry::wrapperVersion
                : (id == errorProperty ? lastError_ : engine_.diagnosticJson());
        CFStringRef s = CFStringCreateWithCString(nullptr, value.c_str(),
                                                  kCFStringEncodingUTF8);
        if (!s)
          return -108;
        *static_cast<CFStringRef *>(data) = s;
        return noErr;
      });
    }
    return Base::GetProperty(id, scope, element, data);
  }
  OSStatus SetProperty(AudioUnitPropertyID id, AudioUnitScope scope,
                       AudioUnitElement element, const void *data,
                       UInt32 bytes) override {
    if(id==sophistry::presetSourceProperty) {
      if(scope!=kAudioUnitScope_Global||element||!data||!bytes||bytes>sophistry::presetSourceBytes)return kAudioUnitErr_InvalidPropertyValue;
      const auto path=static_cast<const char*>(data);
      if(path[bytes-1]||std::memchr(path,0,bytes-1))return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]()->OSStatus{lastKnownPresetSource_.assign(path,bytes-1);PropertyChanged(kAudioUnitProperty_ClassInfo,kAudioUnitScope_Global,0);return noErr;});
    }
    if(id==sophistry::presetBankNameProperty) {
      if(scope!=kAudioUnitScope_Global||element||!data||!bytes||bytes>sophistry::presetBankNameBytes)return kAudioUnitErr_InvalidPropertyValue;
      const auto label=static_cast<const char*>(data);
      if(label[bytes-1]||std::memchr(label,0,bytes-1))return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]()->OSStatus {
        lastKnownBankName_.assign(label,bytes-1);return noErr;
      });
    }
    if (id == sophistry::editorPanelProperty || id == sophistry::generatorPanelProperty || id == sophistry::generatorEditProperty) return kAudioUnitErr_InvalidProperty;
    if (id == sophistry::editorFileProperty) {
      if (scope != kAudioUnitScope_Global || element || !data ||
          bytes < sizeof(sophistry::EditorFileRequest) + 2)
        return kAudioUnitErr_InvalidPropertyValue;
      sophistry::EditorFileRequest h;
      std::memcpy(&h, data, sizeof(h));
      const char *path = static_cast<const char *>(data) + sizeof(h);
      if (h.version != 1 || !sophistry::editorFileCommand(h.tag, h.operation) ||
          h.pathBytes < 2 || h.pathBytes > 256 ||
          sizeof(h) + h.pathBytes != bytes || path[h.pathBytes - 1] ||
          std::memchr(path, 0, h.pathBytes - 1))
        return kAudioUnitErr_InvalidPropertyValue;
      return edited([&]() -> OSStatus {
        engine_.editorFileOperation(h.tag, h.operation,
                                    {path, h.pathBytes - 1});
        syncParameters();
        PropertyChanged(kAudioUnitProperty_ClassInfo, kAudioUnitScope_Global,
                        0);
        return noErr;
      });
    }
    if (id == sophistry::editorTextEditProperty ||
        id == sophistry::editorActionProperty) {
      if (scope != kAudioUnitScope_Global || element || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      return edited([&]() -> OSStatus {
        if (id == sophistry::editorActionProperty) {
          if (bytes != sizeof(sophistry::EditorAction))
            return kAudioUnitErr_InvalidPropertyValue;
          const auto action =
              *static_cast<const sophistry::EditorAction *>(data);
          if (action.version != 1)
            return kAudioUnitErr_InvalidPropertyValue;
          engine_.editorAction(action.key);
        } else {
          if (bytes < sizeof(sophistry::EditorTextEditHeader) + 1)
            return kAudioUnitErr_InvalidPropertyValue;
          sophistry::EditorTextEditHeader header;
          std::memcpy(&header, data, sizeof(header));
          const auto *text = static_cast<const char *>(data) + sizeof(header);
          if (header.version != 1 || header.bytes < 1 ||
              header.bytes > sophistry::editorStringBytes ||
              std::uint64_t(sizeof(header)) + header.bytes != bytes ||
              text[header.bytes - 1] || std::memchr(text, 0, header.bytes - 1))
            return kAudioUnitErr_InvalidPropertyValue;
          engine_.setEditorString(header.tag, {text, header.bytes - 1});
        }
        syncParameters();
        PropertyChanged(kAudioUnitProperty_ClassInfo, kAudioUnitScope_Global,
                        0);
        return noErr;
      });
    }
    if (id == sophistry::editorEditProperty) {
      if (scope != kAudioUnitScope_Global || element || !data ||
          bytes != sizeof(sophistry::GeneratorControlEdit))
        return kAudioUnitErr_InvalidPropertyValue;
      auto edit = *static_cast<const sophistry::GeneratorControlEdit *>(data);
      if (edit.version != 1)
        return kAudioUnitErr_InvalidPropertyValue;
      return edited([&]() -> OSStatus {
        engine_.setEditorControl(edit.tag, edit.normalized);
        auto au = sophistry::recoveredAUParameter(edit.tag);
        if (edit.tag >= 213 && edit.tag <= 218)
          syncParameters(); // choosing an FX type can exchange another slot
        else if (au != sophistry::noAUParameter)
          Globals()->SetParameter(au, engine_.auParameter(au));
        else if (edit.tag == 783 || edit.tag == 784 ||
                 sophistry::generatorForTypeTag(edit.tag) < 4 ||
                 (edit.tag >= 639 && edit.tag <= 647) || edit.tag == 610)
          syncParameters();
        PropertyChanged(kAudioUnitProperty_ClassInfo, kAudioUnitScope_Global,
                        0);
        return noErr;
      });
    }
    if (id == sophistry::generatorEditProperty) {
      if (scope != kAudioUnitScope_Global || element || !data ||
          bytes != sizeof(sophistry::GeneratorControlEdit))
        return kAudioUnitErr_InvalidPropertyValue;
      const auto edit =
          *static_cast<const sophistry::GeneratorControlEdit *>(data);
      if (edit.version != 1)
        return kAudioUnitErr_InvalidPropertyValue;
      return edited([&]() -> OSStatus {
        engine_.setGeneratorControl(edit.tag, edit.normalized);
        const auto au = sophistry::generatorAUParameter(edit.tag);
        if (au != sophistry::noAUParameter)
          Globals()->SetParameter(au, engine_.auParameter(au));
        else if (edit.tag == 766 || edit.tag == 767 || edit.tag == 774 ||
                 edit.tag == 775)
          syncParameters();
        PropertyChanged(kAudioUnitProperty_ClassInfo, kAudioUnitScope_Global,
                        0);
        return noErr;
      });
    }
    if (id == sophistry::importProgramProperty ||
        id == sophistry::sampleRootProperty ||
        id == sophistry::reloadStateProperty) {
      if (scope != kAudioUnitScope_Global || element || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      return edited([&]() -> OSStatus {
        if (id == sophistry::reloadStateProperty) {
          if (bytes != sizeof(UInt32) ||
              *static_cast<const UInt32 *>(data) != 1 ||
              lastRestoredChunk_.empty())
            return kAudioUnitErr_InvalidPropertyValue;
          const auto chunk = lastRestoredChunk_;
          loadChunk(chunk, lastRestoredProgram_);
          return noErr;
        }
        if (id == sophistry::importProgramProperty) {
          if (bytes == 0 || bytes > 1048576)
            return kAudioUnitErr_InvalidPropertyValue;
          const auto *raw = static_cast<const std::uint8_t *>(data);
          loadChunk({raw, raw + bytes}, true);
          PropertyChanged(kAudioUnitProperty_ClassInfo, kAudioUnitScope_Global,
                          0);
          return noErr;
        }
        if (bytes < sizeof(sophistry::BankLocationHeader) || bytes > 131072)
          return kAudioUnitErr_InvalidPropertyValue;
        sophistry::BankLocationHeader header;
        std::memcpy(&header, data, sizeof(header));
        if (header.version != 1 || header.pathBytes < 2 ||
            header.pathBytes > 4096 ||
            std::uint64_t(sizeof(header)) + header.pathBytes +
                    header.bookmarkBytes !=
                bytes)
          return kAudioUnitErr_InvalidPropertyValue;
        const auto *path = static_cast<const char *>(data) + sizeof(header);
        if (path[header.pathBytes - 1] ||
            std::memchr(path, 0, header.pathBytes - 1))
          return kAudioUnitErr_InvalidPropertyValue;
        std::unique_ptr<const void, decltype(&CFRelease)> value(
            CFStringCreateWithBytes(
                nullptr, reinterpret_cast<const UInt8 *>(path),
                header.pathBytes - 1, kCFStringEncodingUTF8, false),
            &CFRelease);
        if (!value)
          return kAudioUnitErr_InvalidPropertyValue;
        const std::string directory(path, header.pathBytes - 1);
        std::unique_ptr<const void, decltype(&CFRelease)> bookmark(
            header.bookmarkBytes ? CFDataCreate(nullptr,
                                                reinterpret_cast<const UInt8 *>(
                                                    path + header.pathBytes),
                                                header.bookmarkBytes)
                                 : nullptr,
            &CFRelease);
        auto access = sophistryMac::openBankBookmark(
            static_cast<CFDataRef>(bookmark.get()), directory);
        std::error_code ec;
        if (!std::filesystem::is_directory(directory, ec)) {
          lastError_ = "Selected sample bank is not an accessible directory";
          return kAudioUnitErr_InvalidPropertyValue;
        }
        std::filesystem::directory_iterator readable(directory, ec);
        if (ec) {
          lastError_ =
              "The AU hosting process cannot read the selected sample bank";
          return kAudioUnitErr_InvalidPropertyValue;
        }
        auto directories = config_.engine.assetDirectories;
        auto previous = CFPreferencesCopyValue(
            CFSTR("CronoX3ARMSampleRoot"), CFSTR("com.linplug.CronoX3.ARMTest"),
            kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
        if (previous && CFGetTypeID(previous) == CFStringGetTypeID() &&
            !directories.empty() &&
            directories.front() == text(static_cast<CFStringRef>(previous)))
          directories.erase(directories.begin());
        directories.insert(directories.begin(), directory);
        try {
          engine_.setAssetDirectories(directories);
        } catch (...) {
          if (previous)
            CFRelease(previous);
          throw;
        }
        CFPreferencesSetValue(CFSTR("CronoX3ARMSampleRoot"), value.get(),
                              CFSTR("com.linplug.CronoX3.ARMTest"),
                              kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
        CFPropertyListRef previousBookmark = CFPreferencesCopyValue(
            CFSTR("CronoX3ARMSampleBookmark"), CFSTR("com.linplug.CronoX3.ARMTest"),
            kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
        CFPreferencesSetValue(CFSTR("CronoX3ARMSampleBookmark"),
                              bookmark.get(), CFSTR("com.linplug.CronoX3.ARMTest"),
                              kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
        bool saved = CFPreferencesSynchronize(CFSTR("com.linplug.CronoX3.ARMTest"),
                                              kCFPreferencesCurrentUser,
                                              kCFPreferencesAnyHost);
        if (!saved) {
          CFPreferencesSetValue(CFSTR("CronoX3ARMSampleRoot"), previous,
                                CFSTR("com.linplug.CronoX3.ARMTest"),
                                kCFPreferencesCurrentUser,
                                kCFPreferencesAnyHost);
          CFPreferencesSetValue(
              CFSTR("CronoX3ARMSampleBookmark"), previousBookmark,
              CFSTR("com.linplug.CronoX3.ARMTest"), kCFPreferencesCurrentUser,
              kCFPreferencesAnyHost);
          CFPreferencesSynchronize(CFSTR("com.linplug.CronoX3.ARMTest"),
                                   kCFPreferencesCurrentUser,
                                   kCFPreferencesAnyHost);
          engine_.setAssetDirectories(config_.engine.assetDirectories);
          if (previousBookmark)
            CFRelease(previousBookmark);
          if (previous)
            CFRelease(previous);
          throw std::runtime_error("Cannot save the selected bank location");
        }
        if (previous)
          CFRelease(previous);
        if (previousBookmark)
          CFRelease(previousBookmark);
        config_.engine.assetDirectories = std::move(directories);
        config_.bankAccess = std::move(access);
        if (!lastRestoredChunk_.empty()) {
          const auto chunk = lastRestoredChunk_;
          loadChunk(chunk, lastRestoredProgram_);
        }
        return noErr;
      });
    }
    if (id == registrationProperty) {
      if (scope != kAudioUnitScope_Global || element ||
          bytes != sizeof(CFStringRef) || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      CFStringRef key = *static_cast<CFStringRef const *>(data);
      if (!key || CFGetTypeID(key) != CFStringGetTypeID())
        return kAudioUnitErr_InvalidPropertyValue;
      return edited([&]() -> OSStatus {
        engine_.setPrivateRegistration(text(key));
        return noErr;
      });
    }
    return Base::SetProperty(id, scope, element, data, bytes);
  }
  OSStatus SaveState(CFPropertyListRef *out) override {
    if (!out)
      return kAudio_ParamError;
    return guarded([&]() -> OSStatus {
      CFPropertyListRef base = nullptr;
      OSStatus status = Base::SaveState(&base);
      if (status)
        return status;
      std::unique_ptr<const void, decltype(&CFRelease)> owned(base, &CFRelease);
      auto dict = static_cast<CFMutableDictionaryRef>(const_cast<void *>(base));
      auto bytes = engine_.saveBank();
      CFDataRef data =
          CFDataCreate(nullptr, bytes.data(), CFIndex(bytes.size()));
      if (!data) {
        return OSStatus(-108);
      }
      CFDictionaryRemoveValue(dict, CFSTR("data"));
      CFDictionarySetValue(dict, CFSTR("vstdata"), data);
      CFRelease(data);
      if (usablePresetName(lastKnownPresetName_)) {
        CFStringRef label = CFStringCreateWithCString(
            nullptr, lastKnownPresetName_.c_str(), kCFStringEncodingUTF8);
        if (!label)
          return OSStatus(-108);
        CFDictionarySetValue(dict, CFSTR("name"), label);
        CFDictionarySetValue(dict, CFSTR("CronoX3ARMPresetName"), label);
        CFRelease(label);
      }
      if(!lastKnownBankName_.empty()) {
        CFStringRef bank=CFStringCreateWithCString(nullptr,lastKnownBankName_.c_str(),kCFStringEncodingUTF8);
        if(!bank)return OSStatus(-108);
        CFDictionarySetValue(dict,CFSTR("CronoX3ARMBankName"),bank);CFRelease(bank);
      }
      if(!lastKnownPresetSource_.empty()) {
        CFStringRef source=CFStringCreateWithCString(nullptr,lastKnownPresetSource_.c_str(),kCFStringEncodingUTF8);
        if(!source)return OSStatus(-108);
        CFDictionarySetValue(dict,CFSTR("CronoX3ARMPresetSource"),source);CFRelease(source);
      }
      // A small vendor metadata field in the standard AU state identifies the
      // code loaded by a remote host without relying on a private property.
      // No runtime status, private settings or bookmark is serialized here.
      CFStringRef build = CFStringCreateWithCString(
          nullptr, sophistry::wrapperVersion, kCFStringEncodingUTF8);
      if (!build)
        return OSStatus(-108);
      CFDictionarySetValue(dict, CFSTR("CronoX3ARMVersion"), build);
      CFRelease(build);
      *out = owned.release();
      return noErr;
    });
  }
  OSStatus RestoreState(CFPropertyListRef state) override {
    return edited([&]() -> OSStatus {
      ++restoreAttempts_;
      stateLoaded_ = false;
      lastRestoreStatus_ = kAudioUnitErr_InvalidPropertyValue;
      if (!state || CFGetTypeID(state) != CFDictionaryGetTypeID()) {
        lastError_ = "The project did not provide an AU state dictionary";
        lastRestoreStatus_ = kAudioUnitErr_InvalidPropertyValue;
        return lastRestoreStatus_;
      }
      auto dict = static_cast<CFDictionaryRef>(state);
      CFTypeRef value = CFDictionaryGetValue(dict, CFSTR("vstdata"));
      if (!value || CFGetTypeID(value) != CFDataGetTypeID()) {
        lastError_ = "The project state contains no legacy vstdata bank";
        lastRestoreStatus_ = kAudioUnitErr_InvalidPropertyValue;
        return lastRestoreStatus_;
      }
      auto number = [&](CFStringRef key, SInt32 &v) {
        CFTypeRef n = CFDictionaryGetValue(dict, key);
        return n && CFGetTypeID(n) == CFNumberGetTypeID() &&
               CFNumberGetValue(static_cast<CFNumberRef>(n),
                                kCFNumberSInt32Type, &v);
      };
      SInt32 sub = 0, mfr = 0, version = 0;
      if (!number(CFSTR("subtype"), sub) ||
          !number(CFSTR("manufacturer"), mfr) ||
          !number(CFSTR("version"), version) || UInt32(mfr) != linplug ||
          (UInt32(sub) != sophistrySubtype && UInt32(sub) != cronoSubtype) ||
          version != 0) {
        lastError_ =
            "The project's AU identity or state version is incompatible";
        lastRestoreStatus_ = kAudioUnitErr_InvalidPropertyValue;
        return lastRestoreStatus_;
      }
      CFDataRef data = static_cast<CFDataRef>(value);
      CFIndex n = CFDataGetLength(data);
      if (n <= 0 || n > 1048576) {
        lastError_ = "The project bank has an invalid size";
        return OSStatus(kAudioUnitErr_InvalidPropertyValue);
      }
      std::vector<std::uint8_t> chunk(CFDataGetBytePtr(data),
                                      CFDataGetBytePtr(data) + n);
      loadChunk(chunk, false, false);
      auto savedName = [&](CFStringRef key) {
        CFTypeRef name = CFDictionaryGetValue(dict, key);
        return name && CFGetTypeID(name) == CFStringGetTypeID()
                   ? text(static_cast<CFStringRef>(name))
                   : std::string();
      };
      const auto originalLabel = savedName(CFSTR("CronoX3ARMPresetName"));
      lastKnownBankName_=savedName(CFSTR("CronoX3ARMBankName"));
      lastKnownPresetSource_=savedName(CFSTR("CronoX3ARMPresetSource"));
      const auto hostLabel = savedName(CFSTR("name"));
      if (usablePresetName(originalLabel))
        lastKnownPresetName_ = originalLabel;
      else if (!usablePresetName(lastKnownPresetName_) &&
               usablePresetName(hostLabel))
        lastKnownPresetName_ = hostLabel;
      CFMutableDictionaryRef copy =
          CFDictionaryCreateMutableCopy(nullptr, 0, dict);
      if (!copy)
        return OSStatus(-108);
      SInt32 target = SInt32(sophistrySubtype);
      CFNumberRef targetNumber =
          CFNumberCreate(nullptr, kCFNumberSInt32Type, &target);
      CFDictionarySetValue(copy, CFSTR("subtype"), targetNumber);
      CFRelease(targetNumber);
      CFDictionaryRemoveValue(copy, CFSTR("data"));
      CFDictionaryRemoveValue(copy, CFSTR("element_name"));
      if (usablePresetName(lastKnownPresetName_)) {
        CFStringRef label = CFStringCreateWithCString(
            nullptr, lastKnownPresetName_.c_str(), kCFStringEncodingUTF8);
        if (!label) {
          CFRelease(copy);
          return OSStatus(-108);
        }
        CFDictionarySetValue(copy, CFSTR("name"), label);
        CFRelease(label);
      }
      OSStatus status = Base::RestoreState(copy);
      CFRelease(copy);
      lastRestoreStatus_ = status;
      stateLoaded_ = status == noErr;
      if (!status) {
        syncParameters();
        syncPresetLabel();
      } else
        lastError_ = "The host AU metadata could not be restored";
      return status;
    });
  }
  OSStatus MIDIEvent(UInt32 status, UInt32 data1, UInt32 data2,
                     UInt32 offset) override {
    return guarded([&]() -> OSStatus {
      if ((status & 0xf0) != 0x80 && (status & 0xf0) != 0x90)
        ++editorGeneration_;
      if (!activated_)
        return OSStatus(kAudioUnitErr_Uninitialized);
      engine_.midi(UInt8(status), UInt8(data1 & 127), UInt8(data2 & 127),
                   offset);
      if ((status & 0xf0) == 0x90 && (data2 & 127)) {
        ++notesReceived_;
        lastMidiChannel_ = status & 15;
        lastMidiNote_ = data1 & 127;
        lastMidiOffset_ = offset;
      }
      return noErr;
    });
  }
  OSStatus Render(AudioUnitRenderActionFlags &flags,
                  const AudioTimeStamp &timestamp, UInt32 frames) override {
    return guarded([&]() -> OSStatus {
      if (!activated_)
        return OSStatus(kAudioUnitErr_Uninitialized);
      auto &buffers = Output(0).GetBufferList();
      if (buffers.mNumberBuffers != engine_.outputChannels())
        return OSStatus(kAudioUnitErr_FormatNotSupported);
      sophistry::LegacyTransport t;
      t.samplePosition = (timestamp.mFlags & kAudioTimeStampSampleTimeValid)
                             ? timestamp.mSampleTime
                             : previousSample_;
      t.hostTime = (timestamp.mFlags & kAudioTimeStampHostTimeValid)
                       ? timestamp.mHostTime
                       : 0;
      auto &host = GetHostCallbackInfo();
      if (host.beatAndTempoProc)
        t.tempoValid = host.beatAndTempoProc(host.hostUserData, &t.beat,
                                             &t.tempo) == noErr;
      if (host.musicalTimeLocationProc)
        t.musicalLocationValid =
            host.musicalTimeLocationProc(
                host.hostUserData, &t.samplesToNextBeat,
                &t.timeSignatureNumerator, &t.timeSignatureDenominator,
                &t.measureStartBeat) == noErr;
      if (host.transportStateProc) {
        Boolean playing = false, changed = false, cycling = false;
        double pos = t.samplePosition;
        t.transportValid =
            host.transportStateProc(host.hostUserData, &playing, &changed, &pos,
                                    &cycling, &t.cycleStartBeat,
                                    &t.cycleEndBeat) == noErr;
        t.playing = playing;
        t.changed = changed;
        t.cycling = cycling;
      }
      engine_.setTransport(t);
      std::array<float *, 6> output{};
      for (UInt32 c = 0; c < buffers.mNumberBuffers; ++c) {
        if (buffers.mBuffers[c].mDataByteSize < frames * 4)
          return OSStatus(kAudioUnitErr_InvalidPropertyValue);
        output[c] = static_cast<float *>(buffers.mBuffers[c].mData);
      }
      engine_.process(output.data(), buffers.mNumberBuffers, frames);
      ++renderCalls_;
      for (UInt32 c = 0; c < buffers.mNumberBuffers; ++c)
        for (UInt32 i = 0; i < frames; ++i) {
          output[c][i] = sophistry::compensatedOutput(output[c][i]);
          const double sample = output[c][i];
          if (std::isfinite(sample))
            maximumOutput_ = std::max(maximumOutput_, std::fabs(sample));
          else
            ++nonfiniteSamples_;
        }
      flags &= ~kAudioUnitRenderAction_OutputIsSilence;
      previousSample_ = t.samplePosition + frames;
      rendered_ = true;
      return noErr;
    });
  }
};

AUSDK_COMPONENT_ENTRY(ausdk::AUMusicDeviceFactory, CronoX3ARMTestAU)
