#include "ArchiveNameFixture.h"
static int run(const int* h){
    using namespace ArchiveNameFixture;auto* c=static_cast<Context*>(calloc(1,sizeof(Context)));c->raw=static_cast<unsigned char*>(malloc(h[0]+1));c->path_units=static_cast<uint16_t*>(calloc(h[1]+1,2));
    if(fread(c->raw,1,h[0],stdin)!=static_cast<size_t>(h[0])||fread(c->path_units,2,h[1],stdin)!=static_cast<size_t>(h[1]))return 2;
    const auto parsed=prepare(c,h);const int prefix[]{parsed,static_cast<int>(c->archive.entry_count),c->archive.read_only};bool ok=output(prefix,sizeof(prefix));
    for(int i=0;i<h[9];++i){
        int op[4];if(fread(op,1,sizeof(op),stdin)!=sizeof(op))return 2;ElastikArchiveStatus status=ElastikArchiveOk;bool skipped=false;int value=0,count=0,payload_size=0;unsigned char* payload=nullptr;
        File* file=c->current?c->files[c->current-1]:nullptr;
        if(op[0]==1)ArchiveNameFixture::resolve(static_cast<ArchiveNameBase::Context*>(c),&c->path);
        else if(op[0]==2){auto* f=elastik_original_archive_open_file(&c->path,&c->factory,&status);c->current=value=file_id(c,f);}
        else if(op[0]==3)c->current=op[1];
        else if(op[0]==4){count=op[1];payload_size=(count>h[0]?count:h[0])+32;payload=static_cast<unsigned char*>(malloc(payload_size));memset(payload,0xa5,payload_size);if(file){file->last_error=ElastikArchiveOk;value=elastik_original_archive_read_member(&file->value.member,payload+16,&count,&status);if(file->last_error!=ElastikArchiveOk)status=file->last_error;}else skipped=true;}
        else if(op[0]==5){if(file)status=elastik_original_archive_seek_member(&file->value.member,op[1]);else skipped=true;}
        else if(op[0]==6){if(file)value=elastik_original_archive_end_member(&file->value.member,&status);else skipped=true;}
        else if(op[0]==7){if(file)value=elastik_original_archive_open_file_position(&file->value,&c->byte_platform,&status);else skipped=true;}
        else if(op[0]==8)value=elastik_original_archive_is_file(&c->path);
        else if(op[0]==9)value=elastik_original_archive_file_size(&c->path);
        else if(op[0]==10){c->path.index=op[1];c->path.unresolved=op[2]?reinterpret_cast<void*>(1000):nullptr;}
        else if(op[0]==11)c->archive.stream=op[1]?c->streams:nullptr;
        else if(op[0]==12){c->maximum=op[1];c->read_ok=op[2];c->fail=op[3]<0?-1:c->reads+op[3];}
        else if(op[0]==13)c->archive.read_only=op[1]!=0;
        else return 3;
        const int record[]{skipped?-1:static_cast<int>(status),value,count,static_cast<int>(c->path.index),c->path.unresolved?1:0,c->depth,c->current,c->file_count,c->path_releases,c->path_retains,payload_size};
        ok=ok&&output(record,sizeof(record))&&output(payload,payload_size);free(payload);
    }
    const int tail[]{c->pos[0],c->pos[1]};ok=ok&&output(tail,8)&&snapshot(c);cleanup(c);return ok&&!fflush(stdout)?0:4;
}
int main(){for(;;){int h[16];size_t n=fread(h,1,sizeof(h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(h))return 2;int e=run(h);if(e)return e;}}
