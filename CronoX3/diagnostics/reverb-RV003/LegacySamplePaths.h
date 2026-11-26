#pragma once
#include <algorithm>
#include <array>
#include <cstdint>
#include <filesystem>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

namespace cronox::samples {
namespace fs=std::filesystem;
inline constexpr std::array<unsigned,32> samplePathTags{{714,715,716,717,738,739,740,741,746,747,748,749,803,804,807,808,841,842,843,844,845,846,847,848,889,890,891,892,893,894,895,896}};
inline std::string lower(std::string s){for(char& c:s)if(c>='A'&&c<='Z')c+=32;return s;}
inline std::string leaf(std::string s){for(char& c:s)if(c=='\\'||c==':')c='/';auto p=s.rfind('/');return p==std::string::npos?s:s.substr(p+1);}
// Keep the drive-colon spelling observed while executing Path_c 0x1db0.
// Provide a colon-free alias too: neither spelling changes the AU bank.
inline std::string originalPath(std::string s){
  std::string result;for(char c:s){if(c=='\\')c='/';if(c=='*'||c=='|'||c=='"'||c=='?')c='_';result+=c;}return result;
}
inline std::string withoutColons(std::string s){s.erase(std::remove(s.begin(),s.end(),':'),s.end());return s;}
inline bool drivePath(const std::string& s){
  return s.size()>2&&((s[0]>='a'&&s[0]<='z')||(s[0]>='A'&&s[0]<='Z'))&&
    ((s[1]==':'&&(s[2]=='/'||s[2]=='\\'))||s[1]=='/');
}
inline fs::path safeAlias(const std::string& s){
  if(s.empty()||s.find('\0')!=std::string::npos)throw std::runtime_error("Unsupported legacy sample path");
  fs::path p(s);if(p.is_absolute())throw std::runtime_error("Legacy alias must be relative");
  for(const auto& part:p)if(part=="..")throw std::runtime_error("Parent traversal in legacy sample path");
  p=p.lexically_normal();if(p.empty()||p==".")throw std::runtime_error("Empty legacy alias");return p;
}
// Read-only candidates from the original padded string representation used
// by ParaSet_c::setChunk 0x1438c. This does not rewrite or reserialize a bank.
// Only candidates corresponding to assets actually opened by ARM are used.
inline std::set<std::string> framedPaths(const unsigned char* data,std::size_t size){
  std::set<std::string> out;if(!data)return out;
  for(std::size_t at=0;at+8<=size;at+=4){
    const auto* p=data+at;std::uint32_t n=std::uint32_t(p[0])|std::uint32_t(p[1])<<8|std::uint32_t(p[2])<<16|std::uint32_t(p[3])<<24;
    if(n<4||n>4096||n%4||n>size-at-4)continue;
    std::size_t length=0;while(length<n&&p[4+length])++length;
    if(length==n||((length+1+3)&~std::size_t(3))!=n)continue;
    std::string s(reinterpret_cast<const char*>(p+4),length);if(!drivePath(s)&&(s.empty()||s[0]!='/'))continue;
    bool valid=true;for(unsigned char c:s)if(c<32||c==127){valid=false;break;}
    if(valid)out.insert(std::move(s));
  }return out;
}
class AssetIndex {
  std::map<std::string,std::vector<fs::path>> files_;
  std::vector<fs::path> roots_;
  static std::vector<std::string> pieces(std::string s){
    for(char& c:s)if(c=='\\'||c==':')c='/';std::vector<std::string> r;std::size_t at=0;
    while(at<s.size()){auto end=s.find('/',at);if(end==s.npos)end=s.size();if(end>at)r.push_back(lower(s.substr(at,end-at)));at=end+1;}return r;
  }
public:
  explicit AssetIndex(const std::vector<fs::path>& directories){
    for(const auto& path:directories){
      std::error_code ec;if(!fs::is_directory(path,ec)||ec)continue;
      fs::directory_iterator access(path,ec);if(ec)continue;
      auto root=fs::weakly_canonical(path,ec);if(ec)continue;roots_.push_back(root);
      fs::recursive_directory_iterator it(root,fs::directory_options::skip_permission_denied,ec),end;
      if(ec)continue;
      for(;it!=end;it.increment(ec)){
        if(ec)throw std::runtime_error("Cannot enumerate the selected sample bank");
        if(!it->is_regular_file(ec)||ec)continue;
        auto p=fs::weakly_canonical(it->path(),ec);if(ec)continue;
        auto& list=files_[lower(it->path().filename().string())];if(std::find(list.begin(),list.end(),p)==list.end())list.push_back(p);
        if(files_.size()>200000)throw std::runtime_error("Selected sample bank contains too many files");
      }
    }
  }
  std::size_t names()const{return files_.size();}
  std::size_t roots()const{return roots_.size();}
  fs::path resolve(const std::string& requested)const{
    auto found=files_.find(lower(leaf(requested)));if(found==files_.end())return {};
    if(found->second.size()==1)return found->second.front();
    const auto wanted=pieces(requested);
    for(const auto& root:roots_){
      fs::path best;std::size_t score=0;bool tied=false;
      for(const auto& p:found->second){auto relative=p.lexically_relative(root);if(relative.empty()||*relative.begin()=="..")continue;
        auto actual=pieces(relative.generic_string());std::size_t n=0;
        while(n<actual.size()&&n<wanted.size()&&actual[actual.size()-n-1]==wanted[wanted.size()-n-1])++n;
        if(n>score){score=n;best=p;tied=false;}else if(n&&n==score)tied=true;
      }
      if(score){if(tied)throw std::runtime_error("Several samples share this name; select a more specific bank folder");return best;}
    }return {};
  }
};
struct Alias {fs::path relative,target;};
struct AliasPlan {std::vector<Alias> aliases;std::set<std::string> covered,unresolved;unsigned inactiveReferences=0;};
inline AliasPlan planAliases(const std::set<std::string>& references,const std::set<std::string>& opened,const AssetIndex& index){
  AliasPlan result;std::map<fs::path,fs::path> targets;
  for(const auto& raw:references){
    auto normalized=originalPath(raw);auto name=lower(leaf(normalized));if(!opened.count(name)){++result.inactiveReferences;continue;}
    std::error_code ec;
    if(fs::path(normalized).is_absolute()){
      if(fs::is_regular_file(normalized,ec)&&!ec)result.covered.insert(name);
      else result.unresolved.insert(name);
      continue;
    }
    auto target=index.resolve(normalized);if(target.empty()){result.unresolved.insert(name);continue;}
    std::set<std::string> variants{normalized,withoutColons(normalized)};
    auto colonVariant=raw;for(char& c:colonVariant)if(c=='\\')c='/';variants.insert(colonVariant);
    for(const auto& text:variants){
      auto alias=safeAlias(text);auto old=targets.find(alias);
      if(old!=targets.end()&&old->second!=target)throw std::runtime_error("Two sample files require the same legacy alias");
      targets[alias]=target;
    }result.covered.insert(name);
  }
  for(const auto& name:opened)if(!result.covered.count(name))result.unresolved.insert(name);
  for(const auto& pair:targets)result.aliases.push_back({pair.first,pair.second});return result;
}
inline void createAliases(const fs::path& directory,const AliasPlan& plan){
  std::error_code ec;if(!fs::is_directory(directory,ec)||ec||!fs::is_empty(directory,ec)||ec)throw std::runtime_error("Temporary alias directory must exist and be empty");
  for(const auto& alias:plan.aliases){
    auto relative=safeAlias(alias.relative.generic_string());auto path=directory/relative;
    fs::create_directories(path.parent_path(),ec);if(ec)throw std::runtime_error("Cannot create temporary legacy directories");
    auto existing=fs::symlink_status(path,ec);ec.clear();
    if(fs::is_symlink(existing)){
      auto resolved=fs::weakly_canonical(path,ec);if(!ec&&resolved==alias.target)continue;
      throw std::runtime_error("A conflicting temporary sample link already exists");
    }
    fs::create_symlink(alias.target,path,ec);if(ec)throw std::runtime_error("Cannot create a temporary sample link");
  }
}
} // namespace cronox::samples
