// Host adapters for the obsolete Carbon Navigation Services ABI. The file
// dialog and every module serializer still execute the lifted original code.
// A native panel supplies one explicit path; guest writes are limited to it.
bool LegacyEngine::Impl::editorPlatformService(const std::string &name, U32 sp,
                                               U32 &result) {
  auto arg = [&](unsigned i) { return word(sp + 4 + 4 * i); };
  auto ref = [&](U32 address, const std::string &path) {
    U32 token = allocate(16);
    fileSystemRefs.emplace(token, path);
    zero(address, 80);
    put(address, token);
  };
  auto dialog = [&](bool save, U32 options, U32 context, U32 output) {
    if (!editorFileActive)
      throw std::runtime_error("No native editor file request");
    editorFileDescription.save = save;
    auto copy = [](char *target, std::size_t size, const std::string &s) {
      std::strncpy(target, s.c_str(), size - 1);
    };
    if (word(options + 14))
      copy(editorFileDescription.title, sizeof(editorFileDescription.title),
           cfString(word(options + 14)));
    if (word(options + 26))
      copy(editorFileDescription.suggestedName,
           sizeof(editorFileDescription.suggestedName),
           cfString(word(options + 26)));
    auto extensions = word(context);
    if (extensions)
      for (auto token : values.at(extensions).array) {
        auto text = lower(cfString(token));
        if (text.empty() || editorFileDescription.count ==
                                editorFileDescription.extensions.size())
          continue;
        auto &out =
            editorFileDescription.extensions[editorFileDescription.count++];
        copy(out.data(), out.size(), text);
      }
    U32 token = allocate(16);
    editorDialogs.insert(token);
    put(output, token);
  };
  result = 0;
  if (name == "_usleep") {
    if (monotonicClock.native() || !config.deterministicTestHost)
      std::this_thread::sleep_for(std::chrono::microseconds(arg(0)));
    monotonicClock.advanceDeterministicSleep(arg(0));
  } else if (name == "_GetDblTime")
    result = 30; // old Carbon ticks; Cocoa owns click timing
  else if (name == "_NewNavEventUPP" || name == "_NewNavObjectFilterUPP") {
    if (!editorFileActive)
      throw std::runtime_error("No native editor file request");
    result = allocate(16);
    editorUpps.insert(result);
  } else if (name == "_DisposeNavEventUPP" ||
             name == "_DisposeNavObjectFilterUPP") {
    if (editorUpps.erase(arg(0)))
      release(arg(0));
  } else if (name == "_NavGetDefaultDialogCreationOptions")
    zero(arg(0), 66);
  else if (name == "_NavCreateChooseFileDialog")
    dialog(false, arg(0), arg(5), arg(6));
  else if (name == "_NavCreatePutFileDialog")
    dialog(true, arg(0), arg(4), arg(5));
  else if (name == "_NavDialogRun") {
    if (!editorDialogs.count(arg(0)))
      throw std::runtime_error("Unknown native editor dialog");
  } else if (name == "_NavDialogGetReply") {
    if (!editorDialogs.count(arg(0)))
      throw std::runtime_error("Unknown native editor dialog");
    U32 reply = arg(1);
    zero(reply, 256);
    if (!editorFilePath.empty()) {
      put(reply + 2, std::uint8_t(1));
      put(reply + 3, std::uint8_t(1));
      const std::filesystem::path path(editorFilePath);
      constexpr U32 scratch = 0x5d1800;
      ref(scratch, editorFileDescription.save ? path.parent_path().string()
                                              : editorFilePath);
      put(reply + 6, U32(0x66737266));
      put(reply + 10, word(scratch));
      put(reply + 24, newString(path.filename().string()));
    }
  } else if (name == "_NavDialogDispose") {
    if (editorDialogs.erase(arg(0)))
      release(arg(0));
  } else if (name == "_AEGetNthPtr") {
    if (arg(1) != 1 || arg(2) != 0x66737266 || arg(6) < 80)
      throw std::runtime_error("Unsupported editor file selection");
    auto token = word(arg(0) + 4);
    if (!fileSystemRefs.count(token))
      throw std::runtime_error("Unknown editor file reference");
    zero(arg(5), 80);
    put(arg(5), token);
    if (arg(3))
      put(arg(3), U32(0));
    if (arg(4))
      put(arg(4), U32(0x66737266));
    if (arg(7))
      put(arg(7), U32(80));
  } else if (name == "_FSPathMakeRef") {
    const auto path = string(arg(0));
    std::error_code error;
    if (!std::filesystem::exists(path, error))
      result = U32(-43);
    else {
      ref(arg(1), path);
      if (arg(2))
        put(arg(2), std::uint8_t(std::filesystem::is_directory(path, error)));
    }
  } else if (name == "_AECreateDesc") {
    if (arg(0) != 0x66737266 || arg(2) != 80)
      throw std::runtime_error("Unsupported editor file descriptor");
    put(arg(3), arg(0));
    put(arg(3) + 4, word(arg(1)));
  } else if (name == "_AEDisposeDesc")
    zero(arg(0), 8);
  else if (name == "_FSRefMakePath") {
    auto text = fileSystemRefs.at(word(arg(0)));
    if (text.size() + 1 > arg(2))
      result = U32(-50);
    else
      string(arg(1), text);
  } else if (name == "_FSMakeFSRefUnicode" || name == "_FSCreateFileUnicode") {
    if (!editorFileActive || editorFilePath.empty())
      throw std::runtime_error("No selected editor output file");
    ref(arg(name == "_FSCreateFileUnicode" ? 5 : 4), editorFilePath);
  } else if (name == "_NavCompleteSave") {
  } else if (name == "_NavDisposeReply") {
    if (word(arg(0) + 24))
      releaseValue(word(arg(0) + 24));
    zero(arg(0), 256);
  } else if (name == "_CFURLCreateWithString")
    result = newString(cfString(arg(1)));
  else if (name == "_CFURLCreateCopyAppendingPathExtension")
    result = newString(cfString(arg(1)) + "." + cfString(arg(2)));
  else if (name == "_CFURLGetString")
    result = arg(0);
  else if (name == "_CFStringGetCharacters") {
    const auto text =
        std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}
            .from_bytes(cfString(arg(0)));
    if (U64(arg(1)) + arg(2) > text.size())
      throw std::runtime_error("Invalid editor UTF-16 range");
    for (U32 i = 0; i < arg(2); ++i)
      put(arg(3) + 2 * i, std::uint16_t(text[arg(1) + i]));
  } else if (name == "_CFPreferencesSetValue") {
    // CronoX 3.6.6 also remembers default paths during normal startup.
    // Actual Mac writes remain controlled by useLocalMacPreferences.
    const auto key = cfString(arg(0)), application = cfString(arg(2)),
               text = cfString(arg(1));
    editorPreferences[{key, application}] = text;
#ifdef __APPLE__
    if (config.useLocalMacPreferences) {
      auto k = CFStringCreateWithCString(nullptr, key.c_str(),
                                         kCFStringEncodingUTF8);
      const auto writeDomain = preferenceWriteDomain(application);
      auto app = CFStringCreateWithCString(nullptr, writeDomain.c_str(),
                                           kCFStringEncodingUTF8);
      auto v = CFStringCreateWithCString(nullptr, text.c_str(),
                                         kCFStringEncodingUTF8);
      if (k && app && v)
        CFPreferencesSetValue(k, v, app, kCFPreferencesCurrentUser,
                              kCFPreferencesAnyHost);
      if (k)
        CFRelease(k);
      if (app)
        CFRelease(app);
      if (v)
        CFRelease(v);
    }
#endif
  } else if (name == "_CFPreferencesSynchronize") {
    result = 1;
#ifdef __APPLE__
    if (config.useLocalMacPreferences) {
      const auto application = preferenceWriteDomain(cfString(arg(0)));
      auto app = CFStringCreateWithCString(nullptr, application.c_str(),
                                           kCFStringEncodingUTF8);
      if (app) {
        result = CFPreferencesSynchronize(app, kCFPreferencesCurrentUser,
                                          kCFPreferencesAnyHost);
        CFRelease(app);
      }
    }
#endif
  } else
    return false;
  return true;
}

EditorFileInfo LegacyEngine::Impl::performEditorFile(U32 tag,
                                                     unsigned operation,
                                                     const std::string &path) {
  if (!editorFileCommand(tag, operation))
    throw std::out_of_range("Unknown original editor file command");
  if (path.find('\0') != std::string::npos || path.size() >= 256 ||
      (!path.empty() && !std::filesystem::path(path).is_absolute()))
    throw std::out_of_range(
        "Original editor requires an absolute path shorter than 256 bytes");
  if (editorFileActive)
    throw std::runtime_error("Nested editor file operation");
  initialize();
  editorFileActive = true;
  editorFilePath = path;
  editorFileDescription = EditorFileInfo{};
  editorModuleRead = false;
  struct Scope {
    Impl &self;
    ~Scope() {
      self.editorFileActive = false;
      self.editorFilePath.clear();
      for (auto i = self.files.begin(); i != self.files.end();) {
        if (!i->second.output.empty() || i->second.selectedModule) {
          self.release(i->first);
          i = self.files.erase(i);
        } else
          ++i;
      }
      for (auto token : self.editorDialogs)
        self.release(token);
      self.editorDialogs.clear();
      for (auto token : self.editorUpps)
        self.release(token);
      self.editorUpps.clear();
      for (auto &entry : self.fileSystemRefs)
        self.release(entry.first);
      self.fileSystemRefs.clear();
    }
  } scope{*this};
  // The original persists the last File IO menu choice in its program chunk.
  // An information query must restore that choice without executing it again.
  const U32 parameter = path.empty() ? run(0x1b16e, {object, tag}) : 0;
  const U32 previousChoice = parameter ? word(parameter + 0x14) : 0;
  const auto alerts = loadAlerts.size();
  editorParameter(tag, float(operation) / (tag == 610 ? 6 : 4));
  if (parameter) put(parameter + 0x14, previousChoice);
  if (!path.empty()) {
    if (loadAlerts.size() != alerts)
      throw std::runtime_error(
          "The original module loader rejected the selected file");
    if (editorFileDescription.save && !std::filesystem::is_regular_file(path))
      throw std::runtime_error("The original module writer produced no file");
    if (!editorFileDescription.save && !editorModuleRead)
      throw std::runtime_error(
          "The original module loader rejected the file type or size");
    ++editorRevision;
    if (!editorFileDescription.save) ++waveformRevision;
  }
  return editorFileDescription;
}

void LegacyEngine::Impl::editorParameter(U32 tag, float value) {
  U32 module = 0, part = 0;
  if (tag == 647) {
    constexpr U32 out = 0x5d1b00;
    run(0x1acac, {object, tag, out, out+4, out+8});
    module = word(out); part = word(out+8);
  }
  const bool previous = editorConfirmation;
  editorConfirmation = tag == 610 && (value == .5f || value == 1.f);
  try {
    run(0x22066, {object, tag, bits32(value)});
    // StepSeq suppresses this callback without its old editor. Forward the
    // explicit menu gesture to its original ModuleManager, with the resolved part.
    if (module && !read<std::uint8_t>(module+0x168)) {
      constexpr U32 name = 0x5d1a00; string(name,"Arpeggiator");
      run(0xd37f4, {object+0x3fc4,module,part,run(0x1ade8,{object,tag}),name});
    }
  } catch (...) { editorConfirmation = previous; throw; }
  editorConfirmation = previous;
  ++editorRevision;
}
