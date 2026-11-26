#!/usr/bin/env python3
"""Run the pinned effect instructions on an x86 CPU, with a Linux I/O shell.

The ELF64 I/O shell switches to the processor’s 32-bit compatibility segment
for the unchanged i386 DSP instructions, then returns to 64-bit Linux syscalls.
No synthesizer initialization or licensing routines are entered. The only
platform adapter is memcpy. This oracle covers FTZ/DAZ that Unicorn 2.1.4
does not consistently reproduce on subnormal SSE test inputs.
"""
from pathlib import Path
import argparse
import hashlib
import subprocess
import sys

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'scripts'))
from legacy_image import LegacyImage


def build(destination):
    destination.mkdir(parents=True,exist_ok=True)
    raw=(ROOT/'reference/CronoX3.i386').read_bytes()
    assert hashlib.sha256(raw).hexdigest()=='fe5f50d2213cfdd072c98cd4083d92bf24d9dc5ea8115b25a64cc8df08ed9969'
    image=LegacyImage(raw)
    data=destination/'original-from-10000.bin'
    data.write_bytes(bytes(image.mapped())[0x10000:])
    stub=next(s['address'] for s in image.stubs if s['name']=='_memcpy')
    source=r'''
.section .original,"awx",@progbits
.incbin "IMAGE_PATH"
.section .text
.global _start
.code64
_start:
    movb $0xe9, MEMCPY_STUB
    movl $copy_bytes-MEMCPY_NEXT, MEMCPY_OFFSET
    movl $0x302800, 0x11c078
    movl $0x70f008,%esp
    movw $0x2b,%ax
    movw %ax,%ds
    movw %ax,%es
    movl $header,%esi
    movl $16,%edx
    call read_exact
    movl $0x300000,%esi
    movl $0x20000,%edx
    call read_exact
    ldmxcsr header+8
render_next:
    pushq $0x23
    pushq $render32
    lretq
.code32
render32:
    fninit
    pushl header+4
    pushl $0x300000
    call *header
    addl $8,%esp
    pushl $0x33
    pushl $back64
    lret
.code64
back64:
    movl $0x300000,%esi
    movl $0x20000,%edx
write_next:
    movl $1,%eax
    movl $1,%edi
    syscall
    testq %rax,%rax
    jle failed
    addq %rax,%rsi
    subq %rax,%rdx
    jne write_next
    decl header+12
    jne render_next
    movl $60,%eax
    xorl %edi,%edi
    syscall
read_exact:
    xorl %eax,%eax
    xorl %edi,%edi
    syscall
    testq %rax,%rax
    jle failed
    addq %rax,%rsi
    subq %rax,%rdx
    jne read_exact
    ret
failed:
    movl $60,%eax
    movl $42,%edi
    syscall
.code32
copy_bytes:
    pushl %esi
    pushl %edi
    movl 12(%esp),%edi
    movl %edi,%eax
    movl 16(%esp),%esi
    movl 20(%esp),%ecx
    cld
    rep movsb
    popl %edi
    popl %esi
    ret
.section .bss
.balign 16
header: .skip 16
'''
    source=source.replace('IMAGE_PATH',str(data.resolve()).replace('\\','\\\\').replace('"','\\"'))
    for key,value in [('MEMCPY_STUB',stub),('MEMCPY_NEXT',stub+5),('MEMCPY_OFFSET',stub+1)]:
        source=source.replace(key,hex(value))
    assembly=destination/'i386-effect-oracle.S';assembly.write_text(source)
    script=destination/'i386-effect-oracle.ld'
    script.write_text('''ENTRY(_start)
SECTIONS {
 . = 0x10000; .original : { *(.original) }
 . = 0x300000; .fixture (NOLOAD) : { . += 0x20000; }
 . = 0x700000; .stack (NOLOAD) : { . += 0x10000; }
 . = 0x800000; .text : { *(.text) } .bss : { *(.bss) }
}
''')
    obj=destination/'i386-effect-oracle.o';exe=destination/'i386-effect-oracle'
    subprocess.run(['as','--64',str(assembly),'-o',str(obj)],check=True)
    subprocess.run(['ld','-m','elf_x86_64','-T',str(script),str(obj),'-o',str(exe)],check=True)
    return exe


if __name__=='__main__':
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('destination',type=Path)
    print(build(parser.parse_args().destination))
