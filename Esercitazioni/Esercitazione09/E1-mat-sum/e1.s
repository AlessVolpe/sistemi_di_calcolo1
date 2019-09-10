.globl matsum
matsum:
    pushl %ebx
    pushl %edi
    pushl %esi
    movl $0, %edx
    movl $0, %eax
    movl $-1, %ecx
    movl 16(%esp), %edi

L1:
    incl %ecx
    movl $0, %edx
    cmpl 20(%esp), %ecx
    jge E

L2:
    cmpl 20(%esp), %edx
    jge L1
    movl (%edi, %ecx, 4), %ebx
    movl (%ebx, %edx, 4), %esi
    addl %esi, %eax
    incl %edx
    jmp L2

E:
    popl %esi
    popl %edi
    popl %ebx
    ret