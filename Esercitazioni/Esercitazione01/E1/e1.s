# scrivere la soluzione qui...
.globl f

f:
	movl $2, %eax     # int a = 2;
	addl $3, %eax     # a = a + 3;
	movl $4, %ebx     # int b = 4;
	subl $2, %ebx     # b = b - 2;
	imull %ebx, %eax  # a = a * b;
	movl $2, %ecx     # int c = 2;
	addl $3, %ecx     # c = c + 3;
	addl %ecx, %eax   # a = a + c;
	incl %eax         # a = a + 1;
	ret               # return a;
