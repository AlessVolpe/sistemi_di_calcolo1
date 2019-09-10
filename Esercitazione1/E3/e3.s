# scrivere la soluzione qui...
.globl f

f:
    movl 4(%esp), %eax  # int a = x;
    movl 8(%esp), %ebx  # int b = y;
    addl %ebx, %eax     # a = a + b
    movl 4(%esp), %ebx  # int b = x;
    movl 8(%esp), %ecx  # int c = y;
    subl %ecx, %ebx     # b = b - c;
    imull %ebx, %eax    # a = a * b;
    ret                 # return a;
