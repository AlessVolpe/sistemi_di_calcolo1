# scrivere la soluzione qui...
.globl find

find:
    movl 4(%esp), %ecx         # int ecx = v
    movl 8(%esp), %edx         # int edx = n;
    movl 12(%esp), %eax        # int eax = x;

L:
    cmpl $0, %edx              # if (edx <= 0) goto E;
    jle E
    cmpl (%ecx, %edx, 4), %eax # if (eax == ecx[edx]) goto F;
    je F
    decl %edx                  # edx--
    jmp L                      # goto L
F:
    movl $1, %eax
    ret                        # return 1;

E:
    movl $0, %eax
    ret                        # return 0;
