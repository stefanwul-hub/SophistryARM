#include "../src/OriginalFileArchive.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef ELASTIK_ARCHIVE_TRACE_CAPACITY
#define ELASTIK_ARCHIVE_TRACE_CAPACITY 4096
#endif

struct Context;
struct StreamContext {Context* c;int index;};
struct Data {unsigned char* bytes;int size;bool locked;};
struct Context {
    int h[24],pos[3],reads=0,maximum=-1,read_ok=1,fail=-1,trace[ELASTIK_ARCHIVE_TRACE_CAPACITY][6],traces=0;
    unsigned char* raw;ElastikOriginalArchive archive{};ElastikOriginalArchiveStream streams[3];StreamContext stream_contexts[3];
    ElastikOriginalArchiveEntry* entries=nullptr;int capacity=0,names=0;
    Data data[128];int data_count=0;
    void event(int a,int b=0,int c=0,int d=0,int e=0,int f=0){if(traces>=ELASTIK_ARCHIVE_TRACE_CAPACITY){abort();}const int row[]{a,b,c,d,e,f};memcpy(trace[traces++],row,24);}
};
static bool output(const void* p,size_t n){return !n||fwrite(p,1,n,stdout)==n;}
static void seek(void* p,int at){auto* s=static_cast<StreamContext*>(p);s->c->pos[s->index]=at;if(s->index!=2)s->c->event(1,s->index,at);}
static bool read(void* p,unsigned char* out,int* count){
    auto* s=static_cast<StreamContext*>(p);auto* c=s->c;const int wanted=*count,at=c->pos[s->index];int actual=0;
    if(wanted<0)actual=wanted;
    else if(c->maximum<-1)actual=c->maximum+1;
    else if(at>=0&&at<c->h[0]){actual=c->h[0]-at;if(actual>wanted)actual=wanted;if(c->maximum>=0&&actual>c->maximum)actual=c->maximum;}
    if(actual>0)memcpy(out,c->raw+at,actual);
    const bool ok=c->read_ok&&c->reads!=c->fail;c->event(2,s->index,at,wanted,actual,ok);++c->reads;
    c->pos[s->index]=static_cast<int>(static_cast<unsigned>(at)+static_cast<unsigned>(actual));*count=actual;return ok;
}
static int position(void* p){auto* s=static_cast<StreamContext*>(p);s->c->event(3,s->index,s->c->pos[s->index]);return s->c->pos[s->index];}
static void retain(void* p){auto* s=static_cast<StreamContext*>(p);s->c->event(4,s->index);}
static bool can_clone(void* p){auto* s=static_cast<StreamContext*>(p);s->c->event(14,s->index,s->c->h[10]);return s->c->h[10]!=0;}
static void* path(void* p){auto* s=static_cast<StreamContext*>(p);s->c->event(15,s->index);return reinterpret_cast<void*>(1);}
static ElastikOriginalArchiveStream* open_path(void* p,void* path){auto* s=static_cast<StreamContext*>(p);if(path!=reinterpret_cast<void*>(1))abort();s->c->event(16,s->index,s->c->h[11]);return s->c->h[11]?s->c->streams+1:nullptr;}
static int end(void* p){auto* s=static_cast<StreamContext*>(p);s->c->pos[s->index]=s->c->h[0];return s->c->h[0];}
static ElastikOriginalArchiveEntry* allocate_entries(void* p,uint32_t n){auto* c=static_cast<Context*>(p);c->event(5,n);c->capacity=n;c->entries=static_cast<ElastikOriginalArchiveEntry*>(malloc(sizeof(ElastikOriginalArchiveEntry)*n));if(!c->entries)abort();return c->entries;}
static void* create_name(void* p,const uint16_t*,int n){auto* c=static_cast<Context*>(p);c->event(6,n);return reinterpret_cast<void*>(static_cast<uintptr_t>(++c->names));}
static void lock(void* p){static_cast<Context*>(p)->event(7);}
static void unlock(void* p){static_cast<Context*>(p)->event(8);}
static void resolve(void* p,ElastikOriginalArchivePath* path){static_cast<Context*>(p)->event(10,path->index,path->unresolved?1:0);}
static Data* data(void* p,void* object){auto* c=static_cast<Context*>(p);for(int i=0;i<c->data_count;++i)if(c->data+i==object)return c->data+i;abort();}
static void* allocate_data(void* p,int n){auto* c=static_cast<Context*>(p);if(c->data_count>=128||n<0)abort();auto* d=c->data+c->data_count++;d->bytes=static_cast<unsigned char*>(malloc(n+1));memset(d->bytes,0xa5,n);d->size=n;d->locked=false;c->event(11,n,c->data_count);return d;}
static void data_lock(void* p,void* v){auto* c=static_cast<Context*>(p);auto* d=data(p,v);d->locked=true;c->event(12,d-c->data+1);}
static unsigned char* data_bytes(void* p,void* v){return data(p,v)->bytes;}
static void data_unlock(void* p,void* v){auto* c=static_cast<Context*>(p);auto* d=data(p,v);d->locked=false;c->event(13,d-c->data+1);}
static void* decode(void* p,void* value,void* name,uint32_t f7,uint32_t f6){auto* c=static_cast<Context*>(p);c->event(17,static_cast<int>(data(p,value)-c->data)+1,static_cast<int>(reinterpret_cast<uintptr_t>(name)),f7,f6,c->h[13]);return c->h[13]==2?nullptr:value;}
static bool write_entry(const ElastikOriginalArchiveEntry& e){
    const uint32_t words[]{e.record_bytes,e.flags,static_cast<uint32_t>(e.length_bits),static_cast<uint32_t>(e.length_bits>>32),static_cast<uint32_t>(e.storage),static_cast<uint32_t>(e.storage>>32),e.field6,e.field7,e.parent};
    const uint32_t tail[]{static_cast<uint32_t>(e.timestamp),static_cast<uint32_t>(e.timestamp>>32),static_cast<uint32_t>(e.record_offset),static_cast<uint32_t>(e.record_offset>>32),static_cast<uint32_t>(e.data_offset),static_cast<uint32_t>(e.data_offset>>32),static_cast<uint32_t>(reinterpret_cast<uintptr_t>(e.name))};
    return output(words,36)&&output(e.name_units,512)&&output(tail,28);
}
static int run(Context* c){
    const int* h=c->h;c->raw=static_cast<unsigned char*>(malloc(h[0]+1));if(fread(c->raw,1,h[0],stdin)!=static_cast<size_t>(h[0]))return 2;
    c->maximum=h[5];c->fail=h[6];c->read_ok=h[7];c->pos[0]=h[8];c->pos[1]=h[9];c->pos[2]=h[8];
    for(int i=0;i<3;++i){c->stream_contexts[i]={c,i};c->streams[i]={c->stream_contexts+i,seek,read,position,retain,can_clone,path,open_path,end};}
    c->archive={static_cast<uint32_t>(h[14]),static_cast<uint32_t>(h[15]),static_cast<uint32_t>(h[16]),0,nullptr,static_cast<uint32_t>(h[2])|(static_cast<uint64_t>(static_cast<uint32_t>(h[3]))<<32),h[4]!=0,h[12]!=0,c->streams,c,allocate_entries,create_name,lock,unlock};
    const auto parsed=elastik_original_archive_parse(&c->archive);auto& a=c->archive;
    const uint32_t header[]{static_cast<uint32_t>(parsed),a.header_bytes,a.version,a.directory_layout,a.entry_count,a.entries?1u:0u,a.read_only?1u:0u,static_cast<uint32_t>(c->capacity)};
    bool ok=output(header,sizeof(header))&&output(&a.file_bytes,8);for(int i=0;i<c->capacity;++i)ok=ok&&write_entry(c->entries[i]);
    const int operations=parsed==ElastikArchiveOk?h[17]:0;if(!output(&operations,4))return 4;
    ElastikOriginalArchivePath file_path{&a,1,nullptr,c,resolve};
    ElastikOriginalArchiveMember m{&file_path,nullptr,c->streams+2,static_cast<uint32_t>(h[19])|(static_cast<uint64_t>(static_cast<uint32_t>(h[20]))<<32),h[21]!=0};
    const ElastikOriginalArchiveData data_platform{c,allocate_data,data_lock,data_bytes,data_unlock,h[13]?decode:nullptr};
    for(int i=0;i<h[17];++i){
        int op[4];if(fread(op,1,sizeof(op),stdin)!=sizeof(op))return 2;if(parsed!=ElastikArchiveOk)continue;
        ElastikArchiveStatus status=ElastikArchiveOk;int value=0,count=0,payload_size=0;unsigned char* payload=nullptr;bool free_payload=false;
        switch(op[0]){
        case 1:status=elastik_original_archive_bind_member(&m,c->streams);break;
        case 2:{count=op[1];if(count<0||count>1048576)abort();payload_size=(count>h[0]?count:h[0])+32;payload=static_cast<unsigned char*>(malloc(payload_size));memset(payload,0xa5,payload_size);free_payload=true;value=elastik_original_archive_read_member(&m,payload+16,&count,&status);break;}
        case 3:status=elastik_original_archive_seek_member(&m,op[1]);break;
        case 4:value=elastik_original_archive_end_member(&m,&status);break;
        case 5:file_path.index=op[1];value=elastik_original_archive_is_file(&file_path);break;
        case 6:file_path.index=op[1];value=elastik_original_archive_file_size(&file_path);break;
        case 7:{void* result=elastik_original_archive_read_data(&a,op[1],&data_platform,&status);if(result){value=1;auto* d=data(c,result);payload=d->bytes;payload_size=d->size;}break;}
        case 8:c->maximum=op[1];c->read_ok=op[2];c->fail=op[3]<0?-1:c->reads+op[3];break;
        case 9:file_path.index=op[1];file_path.unresolved=op[2]?reinterpret_cast<void*>(1):nullptr;break;
        case 10:m.backing=op[1]?c->streams+op[1]-1:nullptr;m.shared=op[2]!=0;break;
        case 11:m.position=static_cast<uint32_t>(op[1])|(static_cast<uint64_t>(static_cast<uint32_t>(op[2]))<<32);break;
        case 12:a.stream=op[1]?c->streams:nullptr;break;
        default:return 3;
        }
        const uint32_t record[]{static_cast<uint32_t>(status),static_cast<uint32_t>(value),static_cast<uint32_t>(count),file_path.index,file_path.unresolved?1u:0u,m.backing?static_cast<uint32_t>(m.backing-c->streams+1):0u,m.shared?1u:0u,static_cast<uint32_t>(m.position),static_cast<uint32_t>(m.position>>32),static_cast<uint32_t>(c->pos[0]),static_cast<uint32_t>(c->pos[1]),static_cast<uint32_t>(c->pos[2]),static_cast<uint32_t>(payload_size)};
        ok=ok&&output(record,sizeof(record))&&output(payload,payload_size);if(free_payload)free(payload);
    }
    ok=ok&&output(&c->data_count,4);for(int i=0;i<c->data_count;++i){const int state[]{c->data[i].size,c->data[i].locked};ok=ok&&output(state,8)&&output(c->data[i].bytes,c->data[i].size);free(c->data[i].bytes);}
    ok=ok&&output(&c->traces,4)&&output(c->trace,c->traces*24);free(c->entries);free(c->raw);return ok&&!fflush(stdout)?0:4;
}
int main(){for(;;){Context c{};size_t n=fread(c.h,1,sizeof(c.h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(c.h))return 2;int e=run(&c);if(e)return e;}}
