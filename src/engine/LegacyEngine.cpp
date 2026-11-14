#include "LegacyEngine.h"
#include "../lifter/LifterRuntime.h"
#include "LegacyImageData.h"
#include <algorithm>
#include <array>
#include <cctype>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <utility>
#ifdef __APPLE__
#include <CoreFoundation/CoreFoundation.h>
#endif

namespace sophistry {
namespace {
using U32 = std::uint32_t;
using U64 = std::uint64_t;
using I32 = std::int32_t;
constexpr U32 object = 0x200000, outer = object - 0xec, stop = 0x500100,
              stack = 0x70f000;
std::string jsonQuoted(const std::string &s) {
  std::ostringstream o;
  o << '"';
  for (unsigned char c : s) {
    if (c == '"' || c == '\\')
      o << '\\' << c;
    else if (c < 32)
      o << "\\u" << std::hex << std::setw(4) << std::setfill('0') << unsigned(c)
        << std::dec;
    else
      o << c;
  }
  o << '"';
  return o.str();
}
std::string lower(std::string s) {
  for (char &c : s)
    if (c >= 'A' && c <= 'Z')
      c += 32;
  return s;
}
std::string baseName(std::string s) {
  for (char &c : s)
    if (c == '\\' || c == ':')
      c = '/';
  auto n = s.rfind('/');
  return n == std::string::npos ? s : s.substr(n + 1);
}
template <class T> U32 bits32(T v) {
  static_assert(sizeof(T) == 4);
  U32 n;
  std::memcpy(&n, &v, 4);
  return n;
}
std::vector<std::uint8_t> readFile(const std::filesystem::path &path) {
  std::ifstream f(path, std::ios::binary | std::ios::ate);
  if (!f)
    throw std::runtime_error("Cannot open asset");
  const auto n = f.tellg();
  if (n < 0 || n > 512 * 1024 * 1024)
    throw std::runtime_error("Asset exceeds host limit");
  std::vector<std::uint8_t> out(static_cast<std::size_t>(n));
  f.seekg(0);
  if (n && !f.read(reinterpret_cast<char *>(out.data()), n))
    throw std::runtime_error("Cannot read asset");
  return out;
}

} // namespace

struct LegacyEngine::Impl {
  LegacyEngineConfig config;
  SlCpu *cpu = nullptr;
  U32 heap = 0x800000;
  std::map<U32, U32> allocations;
  std::set<U32> freed;
  std::multimap<U32, U32> reusable;
  std::map<U32, std::string> imports;
  std::map<std::string, U64> calls;
  std::string lastImport;
  std::map<U32, U32> attributes;
  struct Mutex {
    U32 type = 0, depth = 0;
  };
  std::map<U32, Mutex> mutexes;
  struct Value {
    std::string type, text;
    std::vector<U32> array;
    U32 refs = 1;
  };
  std::map<U32, Value> values;
  std::map<U32, U32> processKeys;
  std::set<U32> lockedKeys;
  std::array<U32, 31> randomState{};
  unsigned randomFront = 3, randomRear = 0;
  U32 randSeed = 1;
  U32 epoch = 1794675600;
  U64 ticks = 0;
  struct File {
    std::vector<std::uint8_t> data;
    U64 position = 0;
    bool eof = false, error = false;
  };
  std::map<U32, File> files;
  std::map<std::string, std::vector<std::filesystem::path>> assets;
  struct Timer {
    double delay = 0, interval = 0;
    U32 callback = 0, data = 0;
  };
  U32 eventLoop = 0;
  std::map<U32, U32> upps;
  std::map<U32, Timer> timers;
  struct Converter {
    bool bigEndian = false;
  };
  std::map<U32, Converter> converters;
  struct Conversion {
    U32 parentSp, converter, request, outCount, output, frames;
  };
  std::vector<Conversion> pendingConversions;
  U32 errnoPointer = 0;
  bool initialized = false, active = false;
  float sampleRate = 44100;
  U32 blockSize = 512;
  U32 inputTable = 0, outputTable = 0, event = 0, events = 0;
  std::vector<U32> outputBuffers;

  explicit Impl(LegacyEngineConfig c) : config(std::move(c)) {
    if (config.guestMemoryBytes < 64u * 1024u * 1024u ||
        config.guestMemoryBytes > 0x70000000u)
      throw std::runtime_error("Invalid guest memory size");
    cpu = sl_create(config.guestMemoryBytes);
    if (!cpu)
      throw std::bad_alloc();
    try {
      write(0, legacy_image_data, legacy_image_size);
      for (std::size_t i = 0; i < legacy_import_count; ++i)
        imports.emplace(legacy_imports[i].address, legacy_imports[i].name);
      imports.emplace(0x70000100, "<converter-input-return>");
      seedRandom(1);
      if (!config.deterministicTestHost)
        epoch = U32(std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now()));
      for (const auto &directory : config.assetDirectories) {
        const std::filesystem::path path(directory);
        std::error_code ec;
        if (!std::filesystem::is_directory(path, ec))
          continue;
        for (const auto &entry : std::filesystem::directory_iterator(path))
          if (entry.is_regular_file())
            assets[lower(entry.path().filename().string())].push_back(
                entry.path());
      }
    } catch (...) {
      sl_destroy(cpu);
      cpu = nullptr;
      throw;
    }
  }
  ~Impl() { sl_destroy(cpu); }
  void bounds(U32 at, std::size_t n) const {
    if (at > cpu->memory_size || n > cpu->memory_size - at)
      throw std::runtime_error("Guest memory range exceeded");
  }
  const std::uint8_t *data(U32 at, std::size_t n) const {
    bounds(at, n);
    return cpu->memory + at;
  }
  void write(U32 at, const void *p, std::size_t n) {
    bounds(at, n);
    if (n)
      std::memcpy(cpu->memory + at, p, n);
  }
  void zero(U32 at, std::size_t n) {
    bounds(at, n);
    std::memset(cpu->memory + at, 0, n);
  }
  template <class T> T read(U32 at) const {
    T v;
    std::memcpy(&v, data(at, sizeof(v)), sizeof(v));
    return v;
  }
  template <class T> void put(U32 at, T v) { write(at, &v, sizeof(v)); }
  U32 word(U32 at) const { return read<U32>(at); }
  U32 reg(U32 at) const {
    U32 v;
    std::memcpy(&v, cpu->reg + at, 4);
    return v;
  }
  void reg(U32 at, U32 v) { std::memcpy(cpu->reg + at, &v, 4); }
  U32 allocate(U32 n) {
    if (n > 0x2000000)
      throw std::runtime_error("Guest allocation exceeds limit");
    const U32 rounded = (std::max(n, U32(1)) + 15) & ~U32(15);
    U32 p = 0;
    if (config.recycleFreedBlocks) {
      auto found = reusable.lower_bound(rounded);
      if (found != reusable.end() && found->first == rounded) {
        p = found->second;
        reusable.erase(found);
        freed.erase(p);
      }
    }
    if (!p) {
      if (U64(heap) + rounded + 16 > cpu->memory_size - 0x200000)
        throw std::bad_alloc();
      p = heap;
      heap += rounded;
    }
    allocations[p] = n;
    return p;
  }
  void release(U32 p) {
    if (!p)
      return;
    auto found = allocations.find(p);
    if (found == allocations.end() || freed.count(p))
      throw std::runtime_error("Invalid guest allocation release");
    freed.insert(p);
    if (config.recycleFreedBlocks)
      reusable.emplace((std::max(found->second, U32(1)) + 15) & ~U32(15), p);
  }
  std::string string(U32 at, std::size_t limit = 65536) const {
    for (std::size_t n = 0; n < limit; ++n)
      if (!*data(at + U32(n), 1))
        return {reinterpret_cast<const char *>(data(at, n)), n};
    throw std::runtime_error("Unterminated guest string");
  }
  void string(U32 at, const std::string &s) {
    write(at, s.c_str(), s.size() + 1);
  }
  U32 newString(std::string text) {
    U32 p = allocate(16);
    Value v;
    v.type = "CFString";
    v.text = std::move(text);
    values.emplace(p, std::move(v));
    return p;
  }
  std::string cfString(U32 token) const {
    auto found = values.find(token);
    if (found != values.end() && found->second.type == "CFString")
      return found->second.text;
    if (!token)
      throw std::runtime_error("NULL CFString");
    U32 flags = word(token + 4), p = word(token + 8), length = word(token + 12);
    if (length > 65536 || flags != 0x7c8)
      throw std::runtime_error("Unsupported guest CFString representation");
    return {reinterpret_cast<const char *>(data(p, length)), length};
  }
  void retainValue(U32 p) {
    auto f = values.find(p);
    if (f != values.end())
      ++f->second.refs;
  }
  void releaseValue(U32 p) {
    auto f = values.find(p);
    if (f == values.end()) {
      cfString(p);
      return;
    }
    if (!--f->second.refs) {
      auto children = std::move(f->second.array);
      values.erase(f);
      for (U32 child : children)
        releaseValue(child);
    }
  }
  void seedRandom(U32 seed) {
    if (!seed)
      seed = 1;
    randomState[0] = seed;
    std::int64_t x = I32(seed);
    for (unsigned i = 1; i < 31; ++i) {
      x = (16807 * x) % 2147483647;
      if (x < 0)
        x += 2147483647;
      randomState[i] = U32(x);
    }
    randomFront = 3;
    randomRear = 0;
    for (unsigned i = 0; i < 310; ++i)
      nextRandom();
  }
  U32 nextRandom() {
    const U32 value = randomState[randomFront] + randomState[randomRear];
    randomState[randomFront] = value;
    randomFront = (randomFront + 1) % 31;
    randomRear = (randomRear + 1) % 31;
    return value >> 1;
  }
  U32 run(U32 entry, std::initializer_list<U32> args) {
    U32 at = stack;
    put(at, stop);
    for (U32 v : args) {
      at += 4;
      put(at, v);
    }
    reg(0x10, stack);
    U64 remaining = 30000000;
    for (;;) {
      int fault = sl_run(cpu, entry, stop, remaining);
      const U64 spent = sl_get_steps(cpu);
      if (spent > remaining)
        throw std::runtime_error("Guest instruction budget exceeded");
      remaining -= spent;
      if (!fault)
        return reg(0);
      if (fault != 3 || !imports.count(cpu->pc)) {
        std::ostringstream s;
        s << "Lifted fault " << fault << " at 0x" << std::hex << cpu->pc;
        throw std::runtime_error(s.str());
      }
      service(cpu->pc);
      entry = cpu->pc;
      if (!remaining)
        throw std::runtime_error("Guest instruction budget exceeded");
    }
  }
  U32 dispatch(U32 opcode, U32 index = 0, U32 value = 0, U32 pointer = 0,
               U32 opt = 0) {
    return run(word(object + 0x24),
               {object + 0x20, opcode, index, value, pointer, opt});
  }
  void service(U32 pc);
  std::string format(const std::string &fmt, U32 arguments);
  U32 preference(const std::string &key, const std::string &application);
  void initialize();
  void prepareBuffers();
};

U32 LegacyEngine::Impl::preference(const std::string &key,
                                   const std::string &application) {
#ifdef __APPLE__
  if (config.useLocalMacPreferences) {
    CFStringRef k =
        CFStringCreateWithCString(nullptr, key.c_str(), kCFStringEncodingUTF8);
    CFStringRef app = CFStringCreateWithCString(nullptr, application.c_str(),
                                                kCFStringEncodingUTF8);
    if (!k || !app) {
      if (k)
        CFRelease(k);
      if (app)
        CFRelease(app);
      throw std::runtime_error("Cannot construct local preference key");
    }
    CFPropertyListRef v = CFPreferencesCopyValue(
        k, app, kCFPreferencesCurrentUser, kCFPreferencesAnyHost);
    CFRelease(k);
    CFRelease(app);
    if (v) {
      if (CFGetTypeID(v) != CFStringGetTypeID()) {
        CFRelease(v);
        throw std::runtime_error("Unsupported non-string legacy preference");
      }
      CFStringRef text = static_cast<CFStringRef>(v);
      CFIndex size = CFStringGetMaximumSizeForEncoding(CFStringGetLength(text),
                                                       kCFStringEncodingUTF8) +
                     1;
      if (size < 1 || size > 65536) {
        CFRelease(v);
        throw std::runtime_error("Legacy preference exceeds limit");
      }
      std::vector<char> bytes(static_cast<std::size_t>(size));
      bool ok =
          CFStringGetCString(text, bytes.data(), size, kCFStringEncodingUTF8);
      CFRelease(v);
      if (!ok)
        throw std::runtime_error("Cannot decode legacy preference");
      return newString(bytes.data());
    }
  }
#else
  (void)key;
  (void)application;
  if (config.useLocalMacPreferences)
    throw std::runtime_error("Local Mac preferences require macOS");
#endif
  return 0;
}

// Parse guest varargs explicitly: a guest long/pointer is 32 bits on ARM64 too.
std::string LegacyEngine::Impl::format(const std::string &fmt, U32 arguments) {
  std::string out;
  auto take = [&]() {
    U32 n = word(arguments);
    arguments += 4;
    return n;
  };
  auto append = [&](const std::string &spec, auto value) {
    int n = std::snprintf(nullptr, 0, spec.c_str(), value);
    if (n < 0 || n > 1048576 || out.size() + std::size_t(n) > 1048576)
      throw std::runtime_error("Guest printf size/format error");
    std::vector<char> bytes(std::size_t(n) + 1);
    std::snprintf(bytes.data(), bytes.size(), spec.c_str(), value);
    out.append(bytes.data(), std::size_t(n));
  };
  for (std::size_t at = 0; at < fmt.size();) {
    if (fmt[at] != '%') {
      out += fmt[at++];
      continue;
    }
    ++at;
    if (at < fmt.size() && fmt[at] == '%') {
      out += '%';
      ++at;
      continue;
    }
    std::string spec = "%";
    while (at < fmt.size() && std::strchr("-+ #0", fmt[at]))
      spec += fmt[at++];
    if (at < fmt.size() && fmt[at] == '*') {
      I32 width = I32(take());
      ++at;
      if (width < 0) {
        spec += '-';
        width = -width;
      }
      spec += std::to_string(width);
    } else
      while (at < fmt.size() &&
             std::isdigit(static_cast<unsigned char>(fmt[at])))
        spec += fmt[at++];
    if (at < fmt.size() && fmt[at] == '.') {
      ++at;
      if (at < fmt.size() && fmt[at] == '*') {
        I32 n = I32(take());
        ++at;
        if (n >= 0)
          spec += '.' + std::to_string(n);
      } else {
        spec += '.';
        while (at < fmt.size() &&
               std::isdigit(static_cast<unsigned char>(fmt[at])))
          spec += fmt[at++];
      }
    }
    std::string length;
    while (at < fmt.size() && std::strchr("hlztjL", fmt[at]))
      length += fmt[at++];
    if (at == fmt.size())
      throw std::runtime_error("Truncated guest printf format");
    char kind = fmt[at++];
    if (std::strchr("diuoxX", kind)) {
      const bool wide = length == "ll" || length == "j";
      U64 n = take();
      if (wide)
        n |= U64(take()) << 32;
      spec += "ll";
      spec += kind;
      if (kind == 'd' || kind == 'i')
        append(spec, wide ? static_cast<long long>(n)
                          : static_cast<long long>(I32(n)));
      else
        append(spec, static_cast<unsigned long long>(n));
    } else if (std::strchr("fFeEgG", kind)) {
      if (length == "L")
        throw std::runtime_error("Guest long-double printf unsupported");
      double v = read<double>(arguments);
      arguments += 8;
      append(spec + kind, v);
    } else if (kind == 's') {
      std::string v = string(take());
      append(spec + kind, v.c_str());
    } else if (kind == 'c')
      append(spec + kind, int(take() & 255));
    else if (kind == 'p')
      append(spec + kind, reinterpret_cast<void *>(std::uintptr_t(take())));
    else
      throw std::runtime_error("Guest printf conversion unsupported");
  }
  return out;
}

void LegacyEngine::Impl::service(U32 pc) {
  const std::string name = imports.at(pc);
  lastImport = name;
  ++calls[name];
  const U32 sp = reg(0x10);
  auto arg = [&](unsigned i) { return word(sp + 4 + 4 * i); };
  U32 result = 0;
  bool hasFloat = false;
  double fp = 0;
  bool has64 = false;
  U64 integer64 = 0;
  if (name == "__Znwm" || name == "__Znam" || name == "_malloc")
    result = allocate(arg(0));
  else if (name == "_calloc") {
    U64 n = U64(arg(0)) * arg(1);
    if (n > 0x2000000)
      throw std::runtime_error("Guest calloc exceeds limit");
    result = allocate(U32(n));
    zero(result, U32(n));
  } else if (name == "_realloc") {
    U32 p = arg(0), n = arg(1);
    result = allocate(n);
    if (p) {
      if (!allocations.count(p) || freed.count(p))
        throw std::runtime_error("Invalid guest realloc");
      write(result, data(p, std::min(n, allocations.at(p))),
            std::min(n, allocations.at(p)));
      release(p);
    }
  } else if (name == "__ZdlPv" || name == "__ZdaPv" || name == "_free")
    release(arg(0));
  else if (name == "_memcpy" || name == "_memmove") {
    result = arg(0);
    bounds(result, arg(2));
    bounds(arg(1), arg(2));
    std::memmove(cpu->memory + result, cpu->memory + arg(1), arg(2));
  } else if (name == "_memset" || name == "_bzero") {
    result = arg(0);
    U32 n = name == "_memset" ? arg(2) : arg(1);
    if (n > 0x2000000)
      throw std::runtime_error("Guest memset exceeds limit");
    bounds(result, n);
    std::memset(cpu->memory + result, name == "_memset" ? int(arg(1) & 255) : 0,
                n);
  } else if (name == "_memcmp") {
    auto a = data(arg(0), arg(2)), b = data(arg(1), arg(2));
    for (U32 i = 0; i < arg(2); ++i)
      if (a[i] != b[i]) {
        result = U32(int(a[i]) - int(b[i]));
        break;
      }
  } else if (name == "_atol" || name == "_atoi") {
    auto text = string(arg(0));
    long long n = std::strtoll(text.c_str(), nullptr, 10);
    if (n > std::numeric_limits<I32>::max() ||
        n < std::numeric_limits<I32>::min()) {
      if (!errnoPointer)
        errnoPointer = allocate(4);
      put(errnoPointer, U32(34));
      n = n < 0 ? std::numeric_limits<I32>::min()
                : std::numeric_limits<I32>::max();
    }
    result = U32(I32(n));
  } else if (name == "_strlen")
    result = U32(string(arg(0)).size());
  else if (name == "_strcpy") {
    result = arg(0);
    string(result, string(arg(1)));
  } else if (name == "_strdup") {
    auto s = string(arg(0));
    result = allocate(U32(s.size() + 1));
    string(result, s);
  } else if (name == "_strncpy") {
    result = arg(0);
    U32 n = arg(2);
    if (n > 1048576)
      throw std::runtime_error("Guest strncpy exceeds limit");
    bounds(arg(1), n);
    U32 length = 0;
    while (length < n && cpu->memory[arg(1) + length])
      ++length;
    write(result, data(arg(1), length), length);
    zero(result + length, n - length);
  } else if (name == "_strcmp" || name == "_strncmp" || name == "_strcasecmp" ||
             name == "_strncasecmp") {
    U32 n = (name == "_strncmp" || name == "_strncasecmp") ? arg(2) : 65536;
    if (n > 65536)
      throw std::runtime_error("Guest comparison exceeds limit");
    auto a = string(arg(0)), b = string(arg(1));
    if (name == "_strcasecmp" || name == "_strncasecmp") {
      a = lower(a);
      b = lower(b);
    }
    for (U32 i = 0; i < n; ++i) {
      unsigned char x = i < a.size() ? a[i] : 0, y = i < b.size() ? b[i] : 0;
      if (x != y) {
        result = U32(int(x) - int(y));
        break;
      }
      if (!x)
        break;
    }
  } else if (name == "_strstr") {
    auto a = string(arg(0));
    auto n = a.find(string(arg(1)));
    result = n == std::string::npos ? 0 : arg(0) + U32(n);
  } else if (name == "_strchr" || name == "_strrchr") {
    auto a = string(arg(0));
    a += '\0';
    auto n = name == "_strchr" ? a.find(char(arg(1))) : a.rfind(char(arg(1)));
    result = n == std::string::npos ? 0 : arg(0) + U32(n);
  } else if (name == "_sprintf" || name == "_snprintf" || name == "_vsprintf" ||
             name == "_vsnprintf") {
    bool bounded = name == "_snprintf" || name == "_vsnprintf",
         variable = name == "_vsprintf" || name == "_vsnprintf";
    unsigned index = bounded ? 2 : 1;
    auto raw = format(string(arg(index)),
                      variable ? arg(index + 1) : sp + 4 * (index + 2));
    result = U32(raw.size());
    if (!bounded)
      string(arg(0), raw);
    else if (arg(1))
      string(arg(0), raw.substr(0, arg(1) - 1));
  } else if (name == "_OSAtomicAdd32Barrier") {
    result = arg(0) + word(arg(1));
    put(arg(1), result);
  } else if (name == "___cxa_atexit" || name == "_atexit") {
    // Global teardown registration is not reached with the
    // unavailable-libSystem test scenario.
    throw std::runtime_error(
        "Global destructor registration needs lifecycle integration");
  } else if (name == "_pthread_mutexattr_init")
    attributes[arg(0)] = 0;
  else if (name == "_pthread_mutexattr_settype") {
    if (!attributes.count(arg(0)) || arg(1) > 2)
      result = 22;
    else
      attributes[arg(0)] = arg(1);
  } else if (name == "_pthread_mutexattr_destroy") {
    if (!attributes.erase(arg(0)))
      result = 22;
  } else if (name == "_pthread_mutex_init") {
    if (arg(1) && !attributes.count(arg(1)))
      result = 22;
    else
      mutexes[arg(0)] = {arg(1) ? attributes.at(arg(1)) : 0, 0};
  } else if (name == "_pthread_mutex_lock" ||
             name == "_pthread_mutex_trylock") {
    auto m = mutexes.find(arg(0));
    if (m == mutexes.end())
      result = 22;
    else if (m->second.depth && m->second.type != 2) {
      if (name == "_pthread_mutex_trylock")
        result = 16;
      else if (m->second.type == 1)
        result = 11;
      else
        throw std::runtime_error("Blocking mutex in single-CPU host");
    } else
      ++m->second.depth;
  } else if (name == "_pthread_mutex_unlock") {
    auto m = mutexes.find(arg(0));
    if (m == mutexes.end())
      result = 22;
    else if (!m->second.depth)
      result = 1;
    else
      --m->second.depth;
  } else if (name == "_pthread_mutex_destroy") {
    auto m = mutexes.find(arg(0));
    if (m == mutexes.end())
      result = 22;
    else if (m->second.depth)
      result = 16;
    else
      mutexes.erase(m);
  } else if (name == "__keymgr_get_and_lock_processwide_ptr_2") {
    if (!lockedKeys.insert(arg(0)).second)
      throw std::runtime_error("Guest process key already locked");
    put(arg(1), processKeys[arg(0)]);
  } else if (name == "__keymgr_set_and_unlock_processwide_ptr") {
    if (!lockedKeys.erase(arg(0)))
      result = 22;
    else
      processKeys[arg(0)] = arg(1);
  } else if (name == "_dlopen") {
    if (string(arg(0)) != "/usr/lib/libSystem.B.dylib")
      throw std::runtime_error("Unsupported guest dynamic library");
    result = 0;
  } else if (name == "_random")
    result = nextRandom();
  else if (name == "_srandom")
    seedRandom(arg(0));
  else if (name == "_srand")
    randSeed = arg(0);
  else if (name == "_rand") {
    randSeed = U32((U64(randSeed ? randSeed : 123459876) * 16807) % 2147483647);
    result = randSeed;
  } else if (name == "_time") {
    result = epoch;
    if (arg(0))
      put(arg(0), result);
  } else if (name == "_gettimeofday") {
    if (arg(0)) {
      put(arg(0), epoch);
      put(arg(0) + 4, U32(0));
    }
    if (arg(1))
      zero(arg(1), 8);
  } else if (name == "_mach_timebase_info") {
    put(arg(0), U32(1));
    put(arg(0) + 4, U32(1));
  } else if (name == "_mach_absolute_time") {
    ticks += 1000;
    integer64 = ticks;
    has64 = true;
  } else if (name == "_GetMainEventLoop") {
    if (!eventLoop)
      eventLoop = allocate(16);
    result = eventLoop;
  } else if (name == "_NewEventLoopTimerUPP") {
    result = allocate(16);
    upps[result] = arg(0);
  } else if (name == "_InstallEventLoopTimer") {
    if (arg(0) != eventLoop || !upps.count(arg(5)))
      throw std::runtime_error("Invalid guest timer arguments");
    U32 token = allocate(16);
    timers[token] = {read<double>(sp + 8), read<double>(sp + 16),
                     upps.at(arg(5)), arg(6)};
    put(arg(7), token);
  } else if (name == "_RemoveEventLoopTimer") {
    if (!timers.erase(arg(0)))
      result = U32(-50);
  } else if (name == "_DisposeEventLoopTimerUPP") {
    if (!upps.erase(arg(0)))
      throw std::runtime_error("Unknown guest timer UPP");
  } else if (name == "_SetEventLoopTimerNextFireTime") {
    if (!timers.count(arg(0)))
      result = U32(-50);
    else
      timers.at(arg(0)).delay = read<double>(sp + 8);
  } else if (name == "_CMOpenProfile") {
    put(arg(0), U32(0));
    result = U32(-4200);
  } else if (name == "_CGColorSpaceCreateDeviceRGB") {
    result = allocate(16);
    Value v;
    v.type = "CGColorSpace";
    values.emplace(result, std::move(v));
  } else if (name == "_CFBundleGetBundleWithIdentifier") {
    if (cfString(arg(0)) != "com.apple.CoreGraphics")
      throw std::runtime_error("Unsupported guest bundle lookup");
    result = 0;
  } else if (name == "_FSFindFolder") {
    if (arg(3))
      zero(arg(3), 80);
    result = U32(-43);
  } else if (name == "_opendir") {
    if (!errnoPointer)
      errnoPointer = allocate(4);
    put(errnoPointer, U32(2));
    result = 0;
  } else if (name == "___error") {
    if (!errnoPointer)
      errnoPointer = allocate(4);
    result = errnoPointer;
  } else if (name == "_CFStringCreateWithCString") {
    const U32 encoding = arg(2);
    auto s = string(arg(1));
    if (encoding != 0x08000100 && encoding != 0 && encoding != 0x600)
      throw std::runtime_error("Unsupported CFString encoding");
    if (encoding != 0x08000100 &&
        std::any_of(s.begin(), s.end(),
                    [](unsigned char c) { return c > 127; }))
      throw std::runtime_error("Non-ASCII legacy encoding needs native codec");
    result = newString(std::move(s));
  } else if (name == "_CFStringCreateCopy")
    result = newString(cfString(arg(1)));
  else if (name == "_CFStringGetLength") {
    auto text = cfString(arg(0));
    U32 n = 0;
    for (unsigned char c : text)
      if ((c & 0xc0) != 0x80)
        n += c >= 0xf0 ? 2 : 1;
    result = n;
  } else if (name == "_CFStringGetCString") {
    auto text = cfString(arg(0));
    U32 encoding = arg(3);
    if (encoding != 0x08000100 && encoding != 0 && encoding != 0x600)
      throw std::runtime_error("Unsupported CFString output encoding");
    if (encoding != 0x08000100 &&
        std::any_of(text.begin(), text.end(),
                    [](unsigned char c) { return c > 127; }))
      result = 0;
    else if (text.size() + 1 <= arg(2)) {
      string(arg(1), text);
      result = 1;
    }
  } else if (name == "_CFStringGetCStringPtr")
    result = 0;
  else if (name == "_CFStringCompare") {
    auto a = cfString(arg(0)), b = cfString(arg(1));
    if (arg(2) & 1) {
      a = lower(a);
      b = lower(b);
    }
    result = U32((a > b) - (a < b));
  } else if (name == "_CFStringGetSystemEncoding")
    result = 0;
  else if (name == "_CFStringGetTypeID")
    result = 7;
  else if (name == "_CFGetTypeID") {
    cfString(arg(0));
    result = 7;
  } else if (name == "_CFRetain") {
    result = arg(0);
    retainValue(result);
  } else if (name == "_CFRelease")
    releaseValue(arg(0));
  else if (name == "_CFArrayCreateMutable") {
    result = allocate(16);
    Value v;
    v.type = "CFArray";
    values.emplace(result, std::move(v));
  } else if (name == "_CFArrayAppendValue") {
    auto &v = values.at(arg(0));
    if (v.type != "CFArray")
      throw std::runtime_error("Expected CFArray");
    v.array.push_back(arg(1));
    retainValue(arg(1));
  } else if (name == "_CFArrayGetValueAtIndex")
    result = values.at(arg(0)).array.at(arg(1));
  else if (name == "_CFArrayGetCount")
    result = U32(values.at(arg(0)).array.size());
  else if (name == "_CFArrayCreateCopy") {
    Value v = values.at(arg(1));
    v.refs = 1;
    for (U32 p : v.array)
      retainValue(p);
    result = allocate(16);
    values.emplace(result, std::move(v));
  } else if (name == "_CFPreferencesCopyValue" ||
             name == "_CFPreferencesCopyAppValue")
    result = preference(cfString(arg(0)), cfString(arg(1)));
  else if (name == "_CFPreferencesGetAppBooleanValue" ||
           name == "_CFPreferencesGetAppIntegerValue") {
    if (arg(2))
      put(arg(2), std::uint8_t(0));
    result = 0;
  } else if (name == "_CFPreferencesAppSynchronize")
    result = 1;
  else if (name == "_fopen" || name == "_fclose" || name == "_fread" ||
           name == "_fseek" || name == "_ftell" || name == "_rewind" ||
           name == "_feof" || name == "_ferror" || name == "_clearerr" ||
           name == "_fflush" || name == "_fgetc" || name == "_getc" ||
           name == "_fgets" || name == "_fgetpos" || name == "_fsetpos") {
    // Native FILE pointers are never narrowed into the guest address space.
    if (name == "_fopen") {
      auto path = string(arg(0)), mode = string(arg(1));
      if (mode != "r" && mode != "rb")
        throw std::runtime_error("Host exposes read-only assets");
      std::filesystem::path resolved;
      if (!config.deterministicTestHost &&
          std::filesystem::is_regular_file(path))
        resolved = path;
      else {
        auto found = assets.find(lower(baseName(path)));
        if (found != assets.end() && found->second.size() == 1)
          resolved = found->second.front();
      }
      if (!resolved.empty()) {
        File f;
        f.data = readFile(resolved);
        result = allocate(256);
        files.emplace(result, std::move(f));
      }
    } else if (name == "_fclose") {
      if (!files.erase(arg(0)))
        result = U32(-1);
      else
        release(arg(0));
    } else if (name == "_fflush" && !arg(0))
      result = 0;
    else {
      U32 token = name == "_fgets"   ? arg(2)
                  : name == "_fread" ? arg(3)
                                     : arg(0);
      auto &f = files.at(token);
      if (name == "_fread") {
        U64 n = U64(arg(1)) * arg(2);
        if (n > 0x2000000)
          throw std::runtime_error("Guest fread exceeds limit");
        U64 count = std::min(n, f.position < f.data.size()
                                    ? U64(f.data.size()) - f.position
                                    : 0);
        if (count)
          write(arg(0), f.data.data() + f.position, std::size_t(count));
        f.position += count;
        f.eof = count < n;
        result = arg(1) ? U32(count / arg(1)) : 0;
      } else if (name == "_fseek" || name == "_rewind" || name == "_fsetpos") {
        std::int64_t position = 0;
        if (name == "_fsetpos")
          position = read<std::int64_t>(arg(1));
        else if (name == "_fseek") {
          U32 origin = arg(2);
          if (origin > 2)
            throw std::runtime_error("Invalid guest seek origin");
          position = I32(arg(1)) + (origin == 1   ? std::int64_t(f.position)
                                    : origin == 2 ? std::int64_t(f.data.size())
                                                  : 0);
        }
        if (position < 0)
          result = U32(-1);
        else {
          f.position = U64(position);
          f.eof = false;
        }
      } else if (name == "_ftell")
        result = U32(f.position);
      else if (name == "_fgetpos")
        put(arg(1), f.position);
      else if (name == "_feof")
        result = f.eof;
      else if (name == "_ferror")
        result = f.error;
      else if (name == "_clearerr") {
        f.eof = false;
        f.error = false;
      } else if (name == "_fgetc" || name == "_getc") {
        if (f.position >= f.data.size()) {
          result = U32(-1);
          f.eof = true;
        } else
          result = f.data[std::size_t(f.position++)];
      } else if (name == "_fgets") {
        U32 n = arg(1);
        if (!n || f.position >= f.data.size()) {
          result = 0;
          f.eof = true;
        } else {
          std::string line;
          while (line.size() < n - 1 && f.position < f.data.size()) {
            char c = char(f.data[std::size_t(f.position++)]);
            line += c;
            if (c == '\n')
              break;
          }
          string(arg(0), line);
          result = arg(0);
        }
      }
    }
  }
  // Conversion and floating ABI services follow in the final branches.
  else if (name == "_AudioConverterNew") {
    U32 a = arg(0), b = arg(1);
    if (word(a + 8) != 0x6c70636d || word(b + 8) != 0x6c70636d ||
        read<double>(a) != read<double>(b) || word(a + 28) != 2 ||
        word(b + 28) != 2 || word(a + 32) != 16 || !(word(a + 12) & 4) ||
        (word(a + 12) & 1) || word(a + 16) != 4 || word(a + 24) != 4 ||
        word(a + 20) != 1 || word(b + 12) != 0x29 || word(b + 32) != 32 ||
        word(b + 16) != 4 || word(b + 24) != 4 || word(b + 20) != 1)
      throw std::runtime_error("Unsupported PCM converter format");
    const U32 token = allocate(32);
    converters[token] = {bool(word(a + 12) & 2)};
    put(arg(2), token);
  } else if (name == "_AudioConverterDispose") {
    if (!converters.erase(arg(0)))
      throw std::runtime_error("Unknown converter");
  } else if (name == "_AudioConverterFillComplexBuffer") {
    if (!pendingConversions.empty() || !converters.count(arg(0)))
      throw std::runtime_error("Invalid converter operation");
    U32 request = allocate(64), count = word(arg(3));
    put(request, count);
    put(request + 4, U32(1));
    put(request + 20, U32(0));
    pendingConversions.push_back({sp, arg(0), request, arg(3), arg(4), count});
    const std::array<U32, 6> args = {0x70000100,  arg(0),       request,
                                     request + 4, request + 20, arg(2)};
    write(sp - 0x1000, args.data(), 24);
    reg(0x10, sp - 0x1000);
    cpu->pc = arg(1);
    return;
  } else if (name == "<converter-input-return>") {
    if (pendingConversions.empty())
      throw std::runtime_error("Unexpected converter continuation");
    auto c = pendingConversions.back();
    pendingConversions.pop_back();
    result = reg(0);
    if (!result) {
      U32 count =
              std::min({c.frames, word(c.request), word(c.request + 12) / 4}),
          p = word(c.request + 16);
      if (word(c.output) != 2)
        throw std::runtime_error("Invalid converter output count");
      const bool big = converters.at(c.converter).bigEndian;
      bounds(p, std::size_t(count) * 4);
      for (U32 channel = 0; channel < 2; ++channel) {
        U32 entry = c.output + 4 + channel * 12, dst = word(entry + 8);
        if (word(entry) != 1 || word(entry + 4) < U64(count) * 4)
          throw std::runtime_error("Invalid converter output buffer");
        bounds(dst, std::size_t(count) * 4);
        for (U32 i = 0; i < count; ++i) {
          U32 at = p + 4 * i + 2 * channel;
          std::uint16_t v =
              big ? (U32(cpu->memory[at]) << 8) | cpu->memory[at + 1]
                  : U32(cpu->memory[at]) | (U32(cpu->memory[at + 1]) << 8);
          put(dst + 4 * i, float(std::int16_t(v)) / 32768.0f);
        }
        put(entry + 4, count * 4);
      }
      put(c.outCount, count);
    }
    reg(0x10, c.parentSp);
  } else {
    const bool f32 = name.size() > 2 && name.back() == 'f';
    const U32 width = f32 ? 4 : 8;
    auto number = [&](U32 i) {
      return f32 ? double(read<float>(sp + 4 + width * i))
                 : read<double>(sp + 4 + width * i);
    };
    std::string op = name.substr(1, f32 ? name.size() - 2 : name.size() - 1);
    hasFloat = true;
    const double a = number(0);
    if (op == "sin")
      fp = f32 ? double(std::sin(float(a))) : std::sin(a);
    else if (op == "cos")
      fp = f32 ? double(std::cos(float(a))) : std::cos(a);
    else if (op == "tan")
      fp = f32 ? double(std::tan(float(a))) : std::tan(a);
    else if (op == "atan")
      fp = f32 ? double(std::atan(float(a))) : std::atan(a);
    else if (op == "asin")
      fp = f32 ? double(std::asin(float(a))) : std::asin(a);
    else if (op == "acos")
      fp = f32 ? double(std::acos(float(a))) : std::acos(a);
    else if (op == "log")
      fp = f32 ? double(std::log(float(a))) : std::log(a);
    else if (op == "log10")
      fp = f32 ? double(std::log10(float(a))) : std::log10(a);
    else if (op == "exp")
      fp = f32 ? double(std::exp(float(a))) : std::exp(a);
    else if (op == "pow")
      fp = f32 ? double(std::pow(float(a), float(number(1))))
               : std::pow(a, number(1));
    else if (op == "sqrt")
      fp = f32 ? double(std::sqrt(float(a))) : std::sqrt(a);
    else if (op == "floor")
      fp = f32 ? double(std::floor(float(a))) : std::floor(a);
    else if (op == "ceil")
      fp = f32 ? double(std::ceil(float(a))) : std::ceil(a);
    else if (op == "fabs")
      fp = std::fabs(a);
    else if (op == "atan2")
      fp = f32 ? double(std::atan2(float(a), float(number(1))))
               : std::atan2(a, number(1));
    else if (op == "fmod")
      fp = f32 ? double(std::fmod(float(a), float(number(1))))
               : std::fmod(a, number(1));
    else
      throw std::runtime_error("Unimplemented host import " + name);
  }
  if (has64) {
    result = U32(integer64);
    reg(8, U32(integer64 >> 32));
  }
  if (hasFloat)
    sl_push_double_return(cpu, fp);
  reg(0, result);
  const U32 currentSp = reg(0x10);
  cpu->pc = word(currentSp);
  reg(0x10, currentSp + 4);
}
void LegacyEngine::Impl::initialize() {
  if (initialized)
    return;
  for (std::size_t i = 0; i < legacy_initializer_count; ++i)
    run(legacy_initializers[i], {});
  run(0x4e876, {object, 0x273c});
  dispatch(0);
  initialized = true;
  if (!config.privateRegistration.empty()) {
    if (config.useLocalMacPreferences)
      throw std::runtime_error(
          "Choose local preferences or private registration input");
    if (config.privateRegistration.size() > 319)
      throw std::runtime_error(
          "Registration input exceeds original field capacity");
    // Before the first activation, SysGlo has not enabled preference writes.
    // Refuse a changed lifecycle instead of unexpectedly persisting a key.
    if (*data(object + 0xb4 + 0x315, 1))
      throw std::runtime_error("Registration setter would persist preferences");
    string(0x5e0000, config.privateRegistration);
    run(0x12c66, {object + 0xb4, 0, 1, 0x5e0000});
    zero(0x5e0000, config.privateRegistration.size() + 1);
  }
}
void LegacyEngine::Impl::prepareBuffers() {
  if (outputTable)
    return;
  if (!active)
    throw std::runtime_error("Audio engine is not active");
  const U32 channels = word(object + 0x40);
  if (channels < 1 || channels > 16 || word(object + 0x3c))
    throw std::runtime_error("Unsupported engine audio topology");
  inputTable = allocate(4);
  outputTable = allocate(channels * 4);
  for (U32 c = 0; c < channels; ++c) {
    U32 p = allocate(blockSize * 4);
    outputBuffers.push_back(p);
    put(outputTable + c * 4, p);
  }
  event = allocate(32);
  events = allocate(16);
  put(events, U32(1));
  put(events + 4, U32(0));
  put(events + 8, event);
  put(events + 12, U32(0));
}

LegacyEngine::LegacyEngine(LegacyEngineConfig config)
    : impl_(new Impl(std::move(config))) {}
LegacyEngine::~LegacyEngine() = default;
void LegacyEngine::initialize() { impl_->initialize(); }
void LegacyEngine::restoreChunk(const std::vector<std::uint8_t> &chunk,
                                bool program) {
  impl_->initialize();
  if (chunk.empty() || chunk.size() > 0x100000)
    throw std::runtime_error("Invalid legacy state size");
  impl_->write(0x600000, chunk.data(), chunk.size());
  const auto n =
      impl_->dispatch(24, program ? 1 : 0, U32(chunk.size()), 0x600000);
  if (n != chunk.size())
    throw std::runtime_error(
        "Original engine did not accept the complete state");
}
std::vector<std::uint8_t> LegacyEngine::saveProgram() {
  impl_->initialize();
  impl_->zero(0x5f0100, 256);
  impl_->dispatch(5, 0, 0, 0x5f0100);
  impl_->put(0x5f0000, U32(0));
  U32 n = impl_->dispatch(23, 1, 0, 0x5f0000), p = impl_->word(0x5f0000);
  if (n > 0x2000000 || (n && !p))
    throw std::runtime_error("Invalid serialized legacy program");
  const auto *bytes = impl_->data(p, n);
  return {bytes, bytes + n};
}
void LegacyEngine::setSampleRate(float rate) {
  impl_->initialize();
  if (!std::isfinite(rate) || rate < 8000 || rate > 384000)
    throw std::runtime_error("Unsupported sample rate");
  impl_->dispatch(10, 0, 0, 0, bits32(rate));
  impl_->sampleRate = rate;
}
void LegacyEngine::setBlockSize(U32 frames) {
  impl_->initialize();
  if (frames < 1 || frames > 65536 || impl_->outputTable)
    throw std::runtime_error(
        "Block size cannot be changed after buffer allocation");
  impl_->dispatch(11, 0, frames);
  impl_->blockSize = frames;
}
void LegacyEngine::activate() {
  impl_->initialize();
  impl_->dispatch(12, 0, 1);
  impl_->active = true;
}
void LegacyEngine::midi(std::uint8_t status, std::uint8_t data1,
                        std::uint8_t data2, U32 delta) {
  impl_->prepareBuffers();
  if (delta >= impl_->blockSize)
    throw std::runtime_error("MIDI offset exceeds block");
  impl_->zero(impl_->event, 32);
  impl_->put(impl_->event, U32(1));
  impl_->put(impl_->event + 4, U32(32));
  impl_->put(impl_->event + 8, delta);
  const std::array<std::uint8_t, 4> message = {status, data1, data2, 0};
  impl_->write(impl_->event + 24, message.data(), 4);
  impl_->dispatch(25, 0, 0, impl_->events);
}
void LegacyEngine::process(float *const *outputs, U32 channels, U32 frames) {
  impl_->prepareBuffers();
  if (!outputs || channels != outputChannels() || frames < 1 ||
      frames > impl_->blockSize)
    throw std::runtime_error("Invalid audio buffers");
  for (U32 p : impl_->outputBuffers)
    impl_->zero(p, impl_->blockSize * 4);
  impl_->run(impl_->word(object + 0x70),
             {object + 0x20, impl_->inputTable, impl_->outputTable, frames});
  for (U32 c = 0; c < channels; ++c) {
    if (!outputs[c])
      throw std::runtime_error("NULL output buffer");
    std::memcpy(outputs[c], impl_->data(impl_->outputBuffers[c], frames * 4),
                frames * 4);
  }
}
U32 LegacyEngine::outputChannels() const { return impl_->word(object + 0x40); }
bool LegacyEngine::registrationAccepted() const {
  return impl_->active && *impl_->data(object + 0xcfc8, 1) != 0;
}
std::vector<std::uint8_t> LegacyEngine::objectSnapshot() const {
  if (impl_->config.useLocalMacPreferences ||
      !impl_->config.privateRegistration.empty())
    throw std::runtime_error("Private input mode disables memory snapshots");
  auto p = impl_->data(object, 0x340000);
  return {p, p + 0x340000};
}
std::vector<std::uint8_t> LegacyEngine::heapSnapshot() const {
  if (impl_->config.useLocalMacPreferences ||
      !impl_->config.privateRegistration.empty())
    throw std::runtime_error("Private input mode disables memory snapshots");
  auto p = impl_->data(0x800000, impl_->heap - 0x800000);
  return {p, p + impl_->heap - 0x800000};
}
std::vector<std::uint8_t> LegacyEngine::globalSnapshot() const {
  if (impl_->config.useLocalMacPreferences ||
      !impl_->config.privateRegistration.empty())
    throw std::runtime_error("Private input mode disables memory snapshots");
  auto p = impl_->data(0xe2000, 0x22000);
  return {p, p + 0x22000};
}
std::string LegacyEngine::diagnosticJson() const {
  std::ostringstream o;
  o << "{\"scope\":\"Native C++ host integration in progress; no Audio "
       "Unit\",\"heap_bytes_reserved\":"
    << impl_->heap - 0x800000
    << ",\"initialized\":" << (impl_->initialized ? "true" : "false")
    << ",\"active\":" << (impl_->active ? "true" : "false")
    << ",\"registration_check_exercised\":"
    << (impl_->active ? "true" : "false") << ",\"registration_accepted\":"
    << (registrationAccepted() ? "true" : "false")
    << ",\"private_local_preferences\":"
    << (impl_->config.useLocalMacPreferences ? "true" : "false")
    << ",\"private_registration_input\":"
    << (!impl_->config.privateRegistration.empty() ? "true" : "false")
    << ",\"last_import\":" << jsonQuoted(impl_->lastImport)
    << ",\"stopped_pc\":" << impl_->cpu->pc << ",\"host_import_calls\":{";
  bool first = true;
  for (const auto &call : impl_->calls) {
    if (!first)
      o << ',';
    first = false;
    o << jsonQuoted(call.first) << ':' << call.second;
  }
  o << "}}";
  return o.str();
}

} // namespace sophistry
