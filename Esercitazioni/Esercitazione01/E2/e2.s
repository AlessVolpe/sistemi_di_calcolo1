# scrivere la soluzione qui...
.globl f

f:
    movl 4(%esp), %eax  # int a = x;
    imull %eax, %eax    # a = a * a;
    imull $2, %eax      # a = a * 2;
    movl 4(%esp), %ebx  # int b = x;
    imull $7, %ebx      # b = x * 7;
    subl %ebx, %eax     # a = a - b;
    incl %eax           # a = a + 1;
    ret                 # return a;
