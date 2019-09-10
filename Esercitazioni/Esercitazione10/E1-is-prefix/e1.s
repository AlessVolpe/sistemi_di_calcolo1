# scrivere la soluzione qui...
.globl is_prefix

is_prefix:
        movl 4(%esp), %ecx
        movl 8(%esp), %edx
        movl $0, %eax

L:
        movb (%ecx), %al
        cmpb $0, %al
        je F
        cmpb %al, (%edx)
        jne E
        incl %ecx
        incl %edx
        jmp L

F: 
        movl $1, %eax
        ret
E:
        movl $0, %eax
        ret
        