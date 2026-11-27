#include "../src/OriginalSoundbank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node{int id;};
struct Context{
    int h[32],trace[4096][6],traces=0,refs[128]{},constructs=0;float number;Node nodes[128];
    ElastikOriginalSoundbank bank;ElastikOriginalSoundbankPlatform platform;
    void event(int a,int b=0,int c=0,int d=0,int e=0){if(traces==4096)abort();int row[]{a,b,c,d,e,0};memcpy(trace[traces++],row,sizeof(row));}
    void* ptr(int id){return id?nodes+id:nullptr;}
};
static int id(void* p){return p?static_cast<Node*>(p)->id:0;}
static void reference(void* p,int op,void* node){auto* c=static_cast<Context*>(p);c->event(1,op,id(node));c->refs[id(node)]+=op==1?1:-1;}
static bool mutable_node(void* p,void* node){auto* c=static_cast<Context*>(p);int n=id(node);bool yes=n<32&&(static_cast<unsigned>(c->h[25])&(1u<<n));c->event(2,n,yes);return yes;}
static void* copy(void* p,void* node){auto* c=static_cast<Context*>(p);c->event(3,id(node),id(node)+64);return c->ptr(id(node)+64);}
static int length(void* p,void* node){auto* c=static_cast<Context*>(p);c->event(4,id(node),c->h[8]);return c->h[8];}
static void* system_path(void* p,void* node){auto* c=static_cast<Context*>(p);c->event(5,id(node),c->h[9]);return c->ptr(c->h[9]);}
static bool exists(void* p,void* node){auto* c=static_cast<Context*>(p);int n=id(node);bool yes=c->h[n==41?10:n==42?12:16]!=0;c->event(6,n,yes);return yes;}
static void* component(void* p,void* node){auto* c=static_cast<Context*>(p);c->event(7,id(node),50);return c->ptr(50);}
static void* resource(void* p,void* node){auto* c=static_cast<Context*>(p);c->event(8,id(node),c->h[11]);return c->ptr(c->h[11]);}
static void* posix(void* p,void* node){auto* c=static_cast<Context*>(p);c->event(9,id(node),c->h[13]);return c->ptr(c->h[13]);}
static void* name(void* p,void* node){auto* c=static_cast<Context*>(p);c->event(10,id(node),c->h[14]);return c->ptr(c->h[14]);}
static void* construct(void* p){auto* c=static_cast<Context*>(p);int n=100+(++c->constructs);if(n>=128)abort();for(int event=11;event<=13;++event)c->event(event,n);return c->ptr(n);}
static int open_archive(void* p,void* archive,void* path){auto* c=static_cast<Context*>(p);c->event(15,id(archive),id(path),c->h[24]);return c->h[24];}
static void* member(void* p,void* archive,const char* path){auto* c=static_cast<Context*>(p);if(strcmp(path,"/Info.plist"))abort();c->event(16,id(archive),c->h[15]);return c->ptr(c->h[15]);}
static void* parse(void* p,void* path){auto* c=static_cast<Context*>(p);c->event(17,id(path),c->h[17]);return c->ptr(c->h[17]);}
static void* description(void* p,void* object){auto* c=static_cast<Context*>(p);c->event(18,id(object),c->h[23]);return c->ptr(c->h[23]);}
static void* get(void* p,void* object,const char* key){auto* c=static_cast<Context*>(p);const char* keys[]{"identifier","title","serial","color","gracePeriode"};for(int i=0;i<5;++i)if(!strcmp(keys[i],key)){c->event(19,id(object),i+1,c->h[18+i]);return c->ptr(c->h[18+i]);}abort();}
static float number(void* p,void* node){auto* c=static_cast<Context*>(p);int bits;memcpy(&bits,&c->number,4);c->event(20,id(node),bits);return c->number;}
static void diagnostic(void* p,int code,void* node){auto* c=static_cast<Context*>(p);c->event(21,code,id(node));}
static bool output(const void* p,size_t n){return !n||fwrite(p,1,n,stdout)==n;}
static int run(const int* h){Context storage{};auto* c=&storage;memcpy(c->h,h,128);for(int i=0;i<128;++i)c->nodes[i].id=i;
    c->platform={c,reference,mutable_node,copy,length,system_path,exists,component,resource,posix,name,construct,open_archive,member,parse,description,get,number,diagnostic};
    c->bank={c->ptr(h[0]),c->ptr(h[1]),c->ptr(h[2]),c->ptr(h[3]),c->ptr(h[4]),c->ptr(h[5]),c->ptr(h[6]),c->ptr(h[7]),0,0};
    if(fread(&c->bank.mounted_at,8,1,stdin)!=1||fread(&c->bank.grace_period,8,1,stdin)!=1||fread(&c->number,4,1,stdin)!=1)return 2;
    bool ok=true;
    for(int i=0;i<h[28];++i){int op[3];if(fread(op,4,3,stdin)!=3)return 2;void* result=nullptr;
        if(op[0]==1)elastik_original_bank_set(&c->bank,static_cast<ElastikSoundbankField>(op[1]),c->ptr(op[2]),&c->platform);
        else if(op[0]==2)elastik_original_bank_set_file(&c->bank,c->ptr(op[1]),&c->platform);
        else if(op[0]==3)result=elastik_original_bank_source(&c->bank,&c->platform);
        else if(op[0]==4)result=elastik_original_bank_archive(&c->bank,&c->platform);
        else if(op[0]==5)elastik_original_bank_clear(&c->bank,&c->platform);
        else if(op[0]==6)c->h[op[1]]=op[2];
        else if(op[0]==7)memcpy(&c->number,op+1,4);
        else return 3;
        const auto& b=c->bank;int record[]{id(result),id(b.title),id(b.identifier),id(b.serial),id(b.response),id(b.source_path),id(b.root_path),id(b.archive),id(b.color),c->constructs};
        ok=ok&&output(record,sizeof(record))&&output(&b.mounted_at,8)&&output(&b.grace_period,8);
    }
    ok=ok&&output(c->refs,sizeof(c->refs))&&output(&c->traces,4)&&output(c->trace,c->traces*24);return ok&&!fflush(stdout)?0:4;
}
int main(){for(;;){int h[32];size_t n=fread(h,1,sizeof(h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(h))return 2;int e=run(h);if(e)return e;}}
