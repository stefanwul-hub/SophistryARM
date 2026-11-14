// Test-only hardware oracle. Never linked into a plugin or the ARM64 runtime.
#include <stdint.h>
#if (defined(__i386__) || defined(__x86_64__)) && defined(__unix__)
#include <signal.h>
#include <setjmp.h>
static sigjmp_buf divide_jump;
static void divide_signal(int){siglongjmp(divide_jump,1);}
extern "C" int sl_test_divide_oracle(uint32_t low,uint32_t high,uint32_t denominator,int is_signed,uint32_t* quotient,uint32_t* remainder){
    // Single-threaded test helper: real 32-bit DIV/IDIV operand semantics.
    struct sigaction action={},previous={};action.sa_handler=divide_signal;
    sigemptyset(&action.sa_mask);
    if(sigaction(SIGFPE,&action,&previous))return 77;
    if(sigsetjmp(divide_jump,1)){
        sigaction(SIGFPE,&previous,nullptr);*quotient=low;*remainder=high;return 9;
    }
    uint32_t a=low,d=high;
    if(is_signed)__asm__ volatile("idivl %2":"+a"(a),"+d"(d):"m"(denominator):"cc");
    else __asm__ volatile("divl %2":"+a"(a),"+d"(d):"m"(denominator):"cc");
    sigaction(SIGFPE,&previous,nullptr);*quotient=a;*remainder=d;return 0;
}
#else
extern "C" int sl_test_divide_oracle(uint32_t,uint32_t,uint32_t,int,uint32_t*,uint32_t*){return 77;}
#endif
