# scrivere la soluzione qui...
.globl sub_array

sub_array:
    pushl %edi # 4
    pushl %ebx # 8 
    pushl %esi # 12
    subl $16, %esp

    xorl %edi, %edi
    movl 32(%esp), %ebx
    movl 36(%esp), %esi
    movl 40(%esp), %ecx
    movl 44(%esp), %edx

L: 
    addl %edi, %ecx
    cmpl %ecx, %edx
    jge F
    leal (%eax), %eax
    movl %edx, (%edx)
    movl %ecx, (%ecx)
    addl %edi, %esi
    movl %ebx, 4(%esp)
    movl %esi, 8(%esp)
    movl %ecx, 12(%esp)
    movl %eax, 16(%esp)
    movl %eax, (%eax)
    call is_prefix # modifica a c e d
    subl %edi, %esi
    cmpl $0, %eax
    je E
    incl %edi
    subl %edi, %ecx
    jmp L

E:
    movl $1, %eax
    addl $16, %esp
    popl %esi # 4
    popl %ebx # 8 
    popl %edi # 12
    ret

F:  movl $0, %eax
    addl $16, %esp
    popl %esi # 4
    popl %ebx # 8 
    popl %edi # 12
    ret

