#include "OriginalSoundbankInternal.h"
static void replace(void*& old,void* value,const ElastikOriginalSoundbankPlatform* p) noexcept {
    if(old!=value){if(old)p->reference(p->context,2,old);old=value;if(value)p->reference(p->context,1,value);}
}
static void invalidate(ElastikOriginalSoundbank* b,const ElastikOriginalSoundbankPlatform* p) noexcept {
    if(b->archive)p->reference(p->context,2,b->archive);
    b->archive=nullptr;
}
static void* immutable(void* value,const ElastikOriginalSoundbankPlatform* p) noexcept {
    return value&&p->is_mutable(p->context,value)?p->immutable_copy(p->context,value):value;
}
extern "C" void elastik_original_bank_set(ElastikOriginalSoundbank* b,
    ElastikSoundbankField field,void* value,const ElastikOriginalSoundbankPlatform* p) noexcept {
    switch(field){
    case ElastikBankIdentifier:replace(b->identifier,immutable(value,p),p);break;
    case ElastikBankSource:invalidate(b,p);replace(b->source_path,value,p);break;
    case ElastikBankRoot:replace(b->root_path,value,p);break;
    case ElastikBankTitle:replace(b->title,value,p);break;
    case ElastikBankColor:replace(b->color,value,p);break;
    case ElastikBankSerial:replace(b->serial,value,p);break;
    case ElastikBankResponse:replace(b->response,value,p);break;
    default:break; // Only the seven original public setters are in contract.
    }
}
extern "C" void elastik_original_bank_set_file(ElastikOriginalSoundbank* b,
    void* path,const ElastikOriginalSoundbankPlatform* p) noexcept {
    void* value=path?p->path_posix(p->context,path):nullptr;
    invalidate(b,p);replace(b->source_path,value,p);
}
extern "C" void elastik_original_bank_clear(ElastikOriginalSoundbank* b,
    const ElastikOriginalSoundbankPlatform* p) noexcept {
    void** fields[]{&b->color,&b->response,&b->serial,&b->identifier,&b->source_path,
        &b->root_path,&b->archive,&b->title};
    for(auto field:fields){if(*field)p->reference(p->context,2,*field);*field=nullptr;}
}
extern "C" void* elastik_original_bank_source(ElastikOriginalSoundbank* b,
    const ElastikOriginalSoundbankPlatform* p) noexcept {
    if(b->source_path&&p->string_length(p->context,b->source_path)!=0){
        void* path=p->system_path(p->context,b->source_path);
        if(path){if(p->path_is_file(p->context,path))return path;
            return p->resource_path(p->context,p->last_component(p->context,b->source_path));}
    }
    return nullptr;
}
namespace elastik_soundbank_detail {

void path_diagnostic(const ElastikOriginalSoundbankPlatform* p,int code,void* path) noexcept {
    void* name=p->path_name(p->context,path);if(name)name=p->path_name(p->context,path);
    p->diagnostic(p->context,code,name);
}

void apply_metadata(ElastikOriginalSoundbank* b, const ElastikOriginalSoundbankPlatform* p,
                    void* info) noexcept {
    void* name=p->description(p->context,info);if(name)name=p->description(p->context,info);
    p->diagnostic(p->context,3,name);
    replace(b->identifier,immutable(p->dictionary_get(p->context,info,"identifier"),p),p);
    replace(b->title,p->dictionary_get(p->context,info,"title"),p);
    replace(b->serial,p->dictionary_get(p->context,info,"serial"),p);
    replace(b->color,p->dictionary_get(p->context,info,"color"),p);
    void* grace=p->dictionary_get(p->context,info,"gracePeriode");
    if(grace)b->grace_period=static_cast<double>(p->number_float(p->context,grace));
}

void* load(ElastikOriginalSoundbank* b, const ElastikOriginalSoundbankPlatform* p,
           const ArchiveReader& reader) {
    void* path=elastik_original_bank_source(b,p); // Also runs for cached archives.
    if(!b->archive&&path&&p->path_is_file(p->context,path)){
        if(b->identifier){p->reference(p->context,2,b->identifier);b->identifier=nullptr;}
        b->archive=p->construct_archive(p->context);
        if(reader.open(reader.context,b->archive,path)!=ElastikArchiveOk){
            invalidate(b,p);
            return nullptr;
        }
        reader.read_metadata(reader.context,b,p,path);
        if(!b->identifier)replace(b->identifier,immutable(p->path_posix(p->context,path),p),p);
        if(!b->title)replace(b->title,p->path_name(p->context,path),p);
    }
    return b->archive;
}

} // namespace elastik_soundbank_detail

static int open_legacy(const void* context, void* archive, void* source) noexcept {
    const auto* p = static_cast<const ElastikOriginalSoundbankPlatform*>(context);
    return p->open_archive(p->context, archive, source);
}

static void read_legacy(const void*, ElastikOriginalSoundbank* bank,
                        const ElastikOriginalSoundbankPlatform* p, void* source) noexcept {
    void* member = p->archive_member(p->context, bank->archive, "/Info.plist");
    if (!member || !p->path_is_file(p->context, member)) {
        elastik_soundbank_detail::path_diagnostic(p, 1, source);
        return;
    }
    void* info = p->parse_plist(p->context, member);
    if (!info) {
        elastik_soundbank_detail::path_diagnostic(p, 2, source);
        return;
    }
    elastik_soundbank_detail::apply_metadata(bank, p, info);
}

extern "C" void* elastik_original_bank_archive(ElastikOriginalSoundbank* b,
    const ElastikOriginalSoundbankPlatform* p) noexcept {
    // The shared loader only calls the original nonthrowing callbacks here.
    return elastik_soundbank_detail::load(b,p,{p,open_legacy,read_legacy});
}
