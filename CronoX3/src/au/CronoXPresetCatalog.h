#pragma once
#include <algorithm>
#include <cctype>
#include <filesystem>
#include <string>
#include <vector>
namespace cronox::catalog {
namespace fs=std::filesystem;
inline std::string lower(std::string s){for(char& c:s)c=char(std::tolower(static_cast<unsigned char>(c)));return s;}
// FileList_c::FLSortLessthan 0x302a0: bytewise case-insensitive lexical order.
inline bool less(const fs::path& a,const fs::path& b){return lower(a.filename().string())<lower(b.filename().string());}
inline std::string label(const fs::path& p){return p.stem().string();} // getFilenameDisplay 0x306d8
inline std::vector<fs::path> entries(const fs::path& folder,bool directories) {
 std::vector<fs::path> out;std::error_code ec;
 for(fs::directory_iterator it(folder,fs::directory_options::skip_permission_denied,ec),end;!ec&&it!=end;it.increment(ec)) {
  const auto& e=*it;std::error_code error;if(e.is_symlink(error))continue;
  auto name=e.path().filename().string();if(lower(name)=="z patterns arp")continue; // addItem 0x2fff6
  if(directories) {
   if(!name.empty()&&name[0]!='.'&&e.is_directory(error))out.push_back(e.path());
  } else if(e.is_regular_file(error)) {
   const auto ext=lower(e.path().extension().string());if(ext==".fxp"||ext==".aupreset")out.push_back(e.path());
  }
 }
 std::sort(out.begin(),out.end(),less);return out;
}
inline std::vector<fs::path> presets(const fs::path& p){return entries(p,false);}
inline std::vector<fs::path> banks(const fs::path& p){auto result=entries(p,true);if(!presets(p).empty())result.insert(result.begin(),p);return result;}
inline bool useful(const fs::path& p) {
 if(!presets(p).empty())return true;
 for(const auto& d:entries(p,true))if(!presets(d).empty())return true;
 return false;
}
inline fs::path root(const fs::path& configured,const fs::path& sampleRoot,const fs::path& current) {
 std::error_code error;if(!configured.empty()&&fs::is_directory(configured,error))return configured;
 std::vector<fs::path> candidates;
 if(!sampleRoot.empty()) {
  candidates.push_back(sampleRoot/"Presets");candidates.push_back(sampleRoot/"CronoXPresets");
  candidates.push_back(sampleRoot.parent_path()/"Presets");candidates.push_back(sampleRoot.parent_path()/"CronoXPresets");
  candidates.push_back(sampleRoot);
 }
 for(const auto& p:candidates)if(useful(p))return p;
 if(!current.empty()) {
  const auto folder=current.parent_path(),parent=folder.parent_path();
  unsigned siblingBanks=0;for(const auto& bank:entries(parent,true))if(!presets(bank).empty())++siblingBanks;
  const auto name=lower(parent.filename().string());
  if(parent!=parent.root_path()&&parent!=folder&&
     (siblingBanks>1||name=="presets"||name=="cronoxpresets"||name=="banks")&&useful(parent))return parent;
  if(useful(folder))return folder;
 }
 return {};
}
} // namespace cronox::catalog
