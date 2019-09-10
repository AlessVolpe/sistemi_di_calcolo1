# scrivere la soluzione qui...
.globl comp

comp:
    movl 4(%esp), %eax   # int* eax = x;
    movl 8(%esp), %ecx   # int* ecx = y;
    movl (%eax), %edx    # int* d = xv;
    subl (%ecx), %edx    # d = d - c;
    movl %edx, %eax      # a = d;
    ret                  # return a;
