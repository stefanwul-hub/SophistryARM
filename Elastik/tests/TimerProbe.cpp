#include "../src/OriginalTimer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct Context {ElastikOriginalTimer* timer;int trace[2048][10],traces=0,handles=0,callback_behavior=0,dispatch_behavior=0;};
static void* object(int id){return reinterpret_cast<void*>(static_cast<uintptr_t>(id));}
static int token(Context* c,void* p){return p==c->timer?1:static_cast<int>(reinterpret_cast<uintptr_t>(p));}
static void record(Context* c,int kind,int a=0,int b=0,int d=0,int e=0,int f=0){
    if(c->traces>=2048) { abort(); } auto* t=c->timer;
    const int row[]{kind,a,b,d,e,f,t->active,t->repeating,token(c,t->action_name),token(c,t->action_handler)};memcpy(c->trace[c->traces++],row,sizeof(row));
}
static void callback(void*);
static void mutate(Context* c,int behavior,bool action){
    if(behavior==1)elastik_original_timer_cancel(c->timer);
    else if(behavior==2){c->timer->callback=action?callback:nullptr;c->timer->callback_context=action?c:nullptr;}
    else if(behavior==3)c->timer->action_handler=nullptr;
    else if(behavior==4)c->timer->action_name=nullptr;
}
static void callback(void* p){auto* c=static_cast<Context*>(p);record(c,10,9);mutate(c,c->callback_behavior,false);}
static void object_op(void* p,int op,void* value){auto* c=static_cast<Context*>(p);record(c,1,op,token(c,value));}
static void* install(void* p,ElastikOriginalTimer* t,double delay,double interval){
    auto* c=static_cast<Context*>(p);if(t!=c->timer)abort();int bits[4];memcpy(bits,&delay,8);memcpy(bits+2,&interval,8);
    int handle=100+(++c->handles);record(c,2,bits[0],bits[1],bits[2],bits[3],handle);return object(handle);
}
static void remove_timer(void* p,void* value){auto* c=static_cast<Context*>(p);record(c,3,token(c,value));}
static void register_cleanup(void* p,ElastikOriginalTimer* t){auto* c=static_cast<Context*>(p);record(c,4,token(c,t));}
static void unregister_cleanup(void* p,ElastikOriginalTimer* t){auto* c=static_cast<Context*>(p);record(c,5,token(c,t));}
static void* begin_pool(void* p,int capacity){auto* c=static_cast<Context*>(p);record(c,6,capacity,7);return object(7);}
static void end_pool(void* p,void* pool){auto* c=static_cast<Context*>(p);record(c,7,token(c,pool));}
static void* make_action(void* p,void* name){auto* c=static_cast<Context*>(p);record(c,8,token(c,name),6);return object(6);}
static void dispatch(void* p,void* handler,void* action){auto* c=static_cast<Context*>(p);record(c,9,token(c,handler),token(c,action));mutate(c,c->dispatch_behavior,true);}
static void after(void* p){record(static_cast<Context*>(p),11);}
static bool output(const void* p,size_t n){return fwrite(p,1,n,stdout)==n;}
static int run(const int* h){
    Context c{};c.callback_behavior=h[6];c.dispatch_behavior=h[7];
    const ElastikOriginalTimerPlatform platform{&c,object_op,install,remove_timer,register_cleanup,unregister_cleanup,begin_pool,end_pool,make_action,dispatch,after};
    ElastikOriginalTimer t{h[5]?object(100):nullptr,static_cast<unsigned char>(h[0]),static_cast<unsigned char>(h[1]),object(h[2]),object(h[3]),h[4]?callback:nullptr,h[4]?&c:nullptr,&platform};c.timer=&t;
    constexpr double times[]{0.0,0.2,0.125,1.0,3.75,1e-6};
    for(int i=0;i<h[8];++i){
        int op[6];if(fread(op,1,sizeof(op),stdin)!=sizeof(op))return 2;
        switch(op[0]){
        case 1:c.callback_behavior=op[3];elastik_original_timer_start_callback(&t,callback,&c,times[op[2]],op[1]);break;
        case 2:c.dispatch_behavior=op[5];elastik_original_timer_start_action(&t,object(op[1]),object(op[2]),times[op[4]],op[3]);break;
        case 3:elastik_original_timer_cancel(&t);break;
        case 4:elastik_original_timer_fire(&t);break;
        case 5:elastik_original_timer_event(&t,op[1]!=0);break;
        case 6:elastik_original_timer_dispose(&t);break;
        default:return 3;
        }
        const int state[]{token(&c,t.event_handle),t.active,t.repeating,token(&c,t.action_name),token(&c,t.action_handler),t.callback?1:0,t.callback_context?9:0};
        if(!output(state,sizeof(state)))return 4;
    }
    if(!output(&c.traces,4)||!output(c.trace,c.traces*40))return 4;
    return fflush(stdout)?4:0;
}
int main(){for(;;){int h[9];size_t n=fread(h,1,sizeof(h),stdin);if(!n&&feof(stdin))return 0;if(n!=sizeof(h))return 2;int e=run(h);if(e)return e;}}
