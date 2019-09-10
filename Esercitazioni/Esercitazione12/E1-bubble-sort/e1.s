# inserire la soluzione qui...
.globl bubble_sort

bubble_sort:
    pushl %ebx
    pushl %esi
    pushl %edi
    subl $8, %esp
    movl 24(%esp), %edi

L: 
    xorl %esi, %esi
    movl $1, %ebx

LI:
    cmpl 28(%esp), %ebx
    jge E
    movl %ebx, %eax
    decl %eax
    movw (%edi, %eax, 2), %dx
    movw (%edi, %ebx, 2), %cx
    cmpw %cx, %dx
    jle F
    leal (%edi, %eax, 2), %eax
    leal (%edi, %ebx, 2), %edx
    movl %eax, (%esp)
    movl %edx, 4(%esp)
    call swap
    movl $1, %esi

F:
    incl %ebx
    jmp LI

E:
    testl %esi, %esi
    jne L
    addl $8, %esp
    popl %edi
    popl %esi
    popl %ebx
    ret