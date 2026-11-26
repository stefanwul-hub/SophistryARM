// File-location regression only. No licence, private preferences or audio gate.
// Execute original translated Path/Disk code with its asset fallback disabled
// to reproduce Intel's relative-path failure, then open the same sample via
// temporary links. No parameter setter or bank-byte replacement is involved.
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
#include <unistd.h>
#define private public
#include "../src/engine/LegacyEngine.h"
#undef private
#include "../src/engine/LegacyEngine.cpp"
#include "../diagnostics/reverb-RV003/LegacySamplePaths.h"
using namespace sophistry;
namespace sample=cronox::samples;
namespace fs=std::filesystem;
void check(bool value,const char* why){if(!value)throw std::runtime_error(why);}
std::vector<unsigned char> read(const fs::path& p){std::ifstream f(p,std::ios::binary);check(bool(f),"Cannot read test file");return {(std::istreambuf_iterator<char>(f)),{}};}
struct Temporary {
  fs::path path,previous=fs::current_path();
  Temporary(){char pattern[]="/tmp/cronox-rv003-XXXXXX";char* p=mkdtemp(pattern);check(p,"Cannot create test directory");path=p;}
  ~Temporary(){std::error_code ec;fs::current_path(previous,ec);fs::remove_all(path,ec);}
};
int main(int argc,char** argv){try{
  check(argc==3,"Expected the public FXP and sample directory");
  const fs::path preset=fs::absolute(argv[1]),samples=fs::weakly_canonical(fs::absolute(argv[2]));
  const auto real=read(samples/"BT_cronox18.wav");auto fxp=read(preset);check(fxp.size()>60,"Missing public FXP");
  LegacyEngineConfig cfg;cfg.audioUnitMode=true;cfg.collectDiagnostics=false;cfg.recursiveAssetSearch=true;cfg.assetDirectories={samples.string()};
  LegacyEngine engine(cfg);engine.initialize();engine.restoreChunk({fxp.begin()+60,fxp.end()},true);auto& h=*engine.impl_;
  const auto bank=engine.saveBank();auto references=sample::framedPaths(bank.data(),bank.size());
  unsigned strings=0;for(unsigned tag:sample::samplePathTags){check(tag!=766&&completeControlReadable(tag),"Unexpected private or unavailable sample tag");auto p=h.run(0x1b16e,{0x1000000,tag});check(p&&h.word(h.word(p+0x10))==7,"Sample tag must be an original string parameter");auto s=engine.editorString(tag);if(!s.empty())references.insert(s);++strings;}
  check(engine.saveBank()==bank,"Reading sample paths changed the AU bank");
  std::set<std::string> opened;for(const auto& p:h.assetOpenResults){check(p.second,"Public fixture unexpectedly failed to load");opened.insert(sample::lower(p.first));}
  check(opened==std::set<std::string>{"bt_cronox18.wav"},"Unexpected active fixture samples");
  sample::AssetIndex index({samples});auto plan=sample::planAliases(references,opened,index);
  check(plan.unresolved.empty()&&plan.covered.size()==1&&plan.aliases.size()>=2,"Active Windows sample not covered");
  check(plan.inactiveReferences>=2,"Inactive unavailable AKAI references must not block the active preset");
  Temporary temporary;auto aliases=temporary.path/"aliases";fs::create_directory(aliases);sample::createAliases(aliases,plan);
  for(const auto& alias:plan.aliases)check(read(aliases/alias.relative)==real,"Temporary link differs from the original audio file");
  const auto requested=engine.editorString(738);check(sample::drivePath(requested),"Fixture must contain a Windows path");
  constexpr U32 text=0x5da000,pathObject=0x5db000,diskObject=0x5dc000;
  U32 dtor=0;for(const auto& entry:h.imports)if(entry.second=="__ZNSsD1Ev")dtor=entry.first;check(dtor,"Missing original string destructor");
  unsigned pathCases=0;
  for(const auto& input:std::vector<std::string>{requested,"c:/VSTPlugins/Sophistry/Samples/Space file.wav","D:\\Folder\\Sample.wav","C:/special*|\"?.wav","/Volumes/Sounds/sample.wav"}){
    h.string(text,input);h.run(0x1db0,{pathObject,text});auto actual=h.string(h.word(pathObject));auto normal=sample::originalPath(input);check(actual==normal||actual==sample::withoutColons(normal),"Executed original Path_c produced an uncovered alias spelling");h.run(dtor,{pathObject});++pathCases;
  }
  h.string(text,requested);h.run(0x1db0,{pathObject,text});h.put(diskObject,U32(0));
  // The original file routine now has only normal filesystem lookup. No
  // fallback asset index, registration edit or synthesis is used here.
  h.config.deterministicTestHost=false;h.indexAssets({});
  fs::current_path(temporary.path);check(!h.run(0xcbf4,{diskObject,pathObject,1,1}),"Legacy relative path unexpectedly existed without aliases");
  fs::current_path(aliases);check(h.run(0xcbf4,{diskObject,pathObject,1,1})==1,"Executed original Disk_c::open cannot use the private aliases");
  check(h.files.at(h.word(diskObject)).data==real,"Original Disk_c opened different sample bytes");h.run(dtor,{pathObject});
  check(engine.saveBank()==bank,"Original file opening changed serialized sound parameters");
  auto recallConfig=cfg;recallConfig.assetDirectories.clear();
  LegacyEngine recalled(recallConfig);recalled.initialize();auto& fresh=*recalled.impl_;
  check(fresh.assetOpenResults.empty(),"Fresh engine already contains a cached sample");
  fresh.config.deterministicTestHost=false;recalled.restoreChunk(bank,false);
  check(fresh.assetOpenResults.size()==1&&fresh.assetOpenResults.at("BT_cronox18.wav"),"Fresh complete bank recall failed without the fallback resolver");
  check(fresh.loadAlerts.empty(),"Fresh complete bank recall raised a sample-load alert");
  check(recalled.saveBank()==bank,"Fresh bank recall through aliases changed sound parameters");
  unsigned rejected=0;for(const auto& invalid:std::vector<std::string>{"c:/../escape.wav","/absolute.wav",std::string("c:/x\0y",6)}){bool threw=false;try{sample::safeAlias(invalid);}catch(const std::runtime_error&){threw=true;}check(threw,"Unsafe alias accepted");++rejected;}
  // Compare duplicate-name decisions with the actual unchanged ARM resolver.
  fs::current_path(temporary.path);auto a=temporary.path/"bank-a",b=temporary.path/"bank-b";fs::create_directories(a/"one");fs::create_directories(a/"two");fs::create_directories(b/"two");
  for(const auto& p:{a/"one/shared.wav",a/"two/shared.wav",b/"two/shared.wav"}){std::ofstream f(p);f<<p.string();}
  h.indexAssets({a.string(),b.string()});sample::AssetIndex duplicates({a,b});unsigned matched=0;
  for(const auto& name:{"c:/one/shared.wav","c:/two/shared.wav","c:/TWO/SHARED.WAV","c:/unknown/shared.wav"}){
    fs::path expected,actual;bool x=false,y=false;try{expected=h.resolveAsset(name);}catch(const std::runtime_error&){x=true;}try{actual=duplicates.resolve(name);}catch(const std::runtime_error&){y=true;}check(x==y&&(x||expected==actual),"Duplicate resolution differs from the unchanged ARM engine");++matched;
  }
  fs::current_path(temporary.previous);fs::remove_all(temporary.path);
  check(read(samples/"BT_cronox18.wav")==real,"Temporary cleanup changed a source audio file");
  std::cout<<"{\"passed\":true,\"original_translated_path_cases\":"<<pathCases<<",\"sample_string_tags_checked\":"<<strings<<",\"private_links\":"<<plan.aliases.size()<<",\"inactive_references_ignored\":"<<plan.inactiveReferences<<",\"original_disk_open_failed_without_alias_and_succeeded_with_alias\":true,\"full_bank_recall_without_asset_resolver_passed\":true,\"fresh_recall_has_no_cached_samples_or_resolver_roots\":true,\"temporary_cleanup_preserved_sample_targets\":true,\"full_sample_bytes_identical\":true,\"au_bank_bytes_unchanged\":true,\"unsafe_alias_inputs_rejected\":"<<rejected<<",\"native_duplicate_resolution_matches\":"<<matched<<",\"licence_or_audio_gate_changed\":false,\"macos_original_x86_64_au_executed\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
