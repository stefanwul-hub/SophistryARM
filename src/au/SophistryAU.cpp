#include "../engine/LegacyEngine.h"
#include <AudioUnitSDK/AUPlugInDispatch.h>
#include <AudioUnitSDK/MusicDeviceBase.h>
#include <algorithm>
#include <array>
#include <cstring>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

namespace {
constexpr AudioUnitPropertyID registrationProperty =
    0x53705267; // SpRg, write-only CFStringRef.
constexpr AudioUnitPropertyID errorProperty =
    0x53704572; // SpEr, retained CFStringRef.
constexpr AudioUnitPropertyID diagnosticsProperty =
    0x53704469; // SpDi, retained CFStringRef.
constexpr UInt32 sophistrySubtype = 0x536f7033, cronoSubtype = 0x43725833,
                 linplug = 0x4c696e50;
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
sophistry::LegacyEngineConfig configuration() {
  sophistry::LegacyEngineConfig c;
  c.audioUnitMode = true;
  c.useLocalMacPreferences = true;
  c.recycleFreedBlocks = true;
  c.collectDiagnostics = false;
  c.guestMemoryBytes = 256u * 1024u * 1024u;
  // Keep deterministic platform inputs until the AU comparison is verified;
  // tempo, sample positions and transport are supplied by actual host
  // callbacks.
  c.deterministicTestHost = true;
  if (CFBundleRef bundle =
          CFBundleGetBundleWithIdentifier(CFSTR("com.linplug.au.Sophistry"))) {
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
  CFPropertyListRef root = CFPreferencesCopyAppValue(
      CFSTR("SophistryARMSampleRoot"), CFSTR("com.linplug.Sophistry"));
  if (root) {
    if (CFGetTypeID(root) == CFStringGetTypeID())
      c.assetDirectories.push_back(text(static_cast<CFStringRef>(root)));
    CFRelease(root);
  }
  return c;
}
} // namespace

class SophistryAU final : public ausdk::MusicDeviceBase {
  using Base = ausdk::MusicDeviceBase;
  std::recursive_mutex mutex_;
  sophistry::LegacyEngine engine_;
  std::vector<UInt32> parameters_;
  std::map<UInt32, AudioUnitParameterInfo> metadata_;
  bool activated_ = false;
  double previousSample_ = 0;
  bool rendered_ = false;
  std::string lastError_;
  template <class F> OSStatus guarded(F &&f) {
    std::lock_guard<std::recursive_mutex> lock(mutex_);
    try {
      return f();
    } catch (const std::out_of_range &e) {
      lastError_ = e.what();
      return kAudioUnitErr_InvalidParameter;
    } catch (const std::exception &e) {
      lastError_ = e.what();
      return kAudioUnitErr_FailedInitialization;
    } catch (...) {
      lastError_ = "Unknown native exception";
      return kAudioUnitErr_FailedInitialization;
    }
  }

public:
  explicit SophistryAU(AudioComponentInstance instance)
      : Base(instance, 0, 1), engine_(configuration()) {
    CreateElements();
    engine_.initialize();
    parameters_ = engine_.auParameterIds();
    for (UInt32 id : parameters_)
      Globals()->SetParameter(id, engine_.auParameter(id));
  }
  ~SophistryAU() override {
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
    return guarded([&]() -> OSStatus {
      const auto &f = Output(0).GetStreamFormat();
      engine_.setAudioUnitOutputChannels(f.mChannelsPerFrame);
      engine_.setSampleRate(float(f.mSampleRate));
      engine_.setBlockSize(GetMaxFramesPerSlice());
      engine_.activate();
      activated_ = true;
      rendered_ = false;
      return noErr;
    });
  }
  void Cleanup() override {
    guarded([&]() -> OSStatus {
      engine_.deactivate();
      activated_ = false;
      return noErr;
    });
  }
  OSStatus Reset(AudioUnitScope scope, AudioUnitElement element) override {
    return guarded([&]() -> OSStatus {
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
    return guarded([&]() -> OSStatus {
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
    if (id == errorProperty || id == diagnosticsProperty) {
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
    if (id == errorProperty || id == diagnosticsProperty) {
      if (scope != kAudioUnitScope_Global || element || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]() -> OSStatus {
        std::string value =
            id == errorProperty ? lastError_ : engine_.diagnosticJson();
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
    if (id == registrationProperty) {
      if (scope != kAudioUnitScope_Global || element ||
          bytes != sizeof(CFStringRef) || !data)
        return kAudioUnitErr_InvalidPropertyValue;
      CFStringRef key = *static_cast<CFStringRef const *>(data);
      if (!key || CFGetTypeID(key) != CFStringGetTypeID())
        return kAudioUnitErr_InvalidPropertyValue;
      return guarded([&]() -> OSStatus {
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
      auto dict = static_cast<CFMutableDictionaryRef>(const_cast<void *>(base));
      auto bytes = engine_.saveBank();
      CFDataRef data =
          CFDataCreate(nullptr, bytes.data(), CFIndex(bytes.size()));
      if (!data) {
        CFRelease(base);
        return OSStatus(-108);
      }
      CFDictionaryRemoveValue(dict, CFSTR("data"));
      CFDictionarySetValue(dict, CFSTR("vstdata"), data);
      CFRelease(data);
      *out = base;
      return noErr;
    });
  }
  OSStatus RestoreState(CFPropertyListRef state) override {
    if (!state || CFGetTypeID(state) != CFDictionaryGetTypeID())
      return kAudioUnitErr_InvalidPropertyValue;
    return guarded([&]() -> OSStatus {
      auto dict = static_cast<CFDictionaryRef>(state);
      CFTypeRef value = CFDictionaryGetValue(dict, CFSTR("vstdata"));
      if (!value || CFGetTypeID(value) != CFDataGetTypeID())
        return OSStatus(kAudioUnitErr_InvalidPropertyValue);
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
          version != 0)
        return OSStatus(kAudioUnitErr_InvalidPropertyValue);
      CFDataRef data = static_cast<CFDataRef>(value);
      CFIndex n = CFDataGetLength(data);
      if (n <= 0 || n > 1048576)
        return OSStatus(kAudioUnitErr_InvalidPropertyValue);
      std::vector<std::uint8_t> chunk(CFDataGetBytePtr(data),
                                      CFDataGetBytePtr(data) + n);
      engine_.restoreChunk(chunk, false);
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
      OSStatus status = Base::RestoreState(copy);
      CFRelease(copy);
      if (!status)
        for (UInt32 id : parameters_)
          Globals()->SetParameter(id, engine_.auParameter(id));
      return status;
    });
  }
  OSStatus MIDIEvent(UInt32 status, UInt32 data1, UInt32 data2,
                     UInt32 offset) override {
    return guarded([&]() -> OSStatus {
      if (!activated_)
        return OSStatus(kAudioUnitErr_Uninitialized);
      engine_.midi(UInt8(status), UInt8(data1 & 127), UInt8(data2 & 127),
                   offset);
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
      flags &= ~kAudioUnitRenderAction_OutputIsSilence;
      previousSample_ = t.samplePosition + frames;
      rendered_ = true;
      return noErr;
    });
  }
};

AUSDK_COMPONENT_ENTRY(ausdk::AUMusicDeviceFactory, SophistryAU)
