# Scrivere la soluzione qui...

.globl list_equal_array

list_equal_array:
	pushl %ebp
	movl %esp, %ebp
	subl $16, %esp
	movl $0, -4(%ebp)
	jmp	A
E:
	cmpl $0, 8(%ebp)
	je B
	movl 8(%ebp), %eax
	movzwl (%eax), %edx
	movl -4(%ebp), %eax
	leal (%eax, %eax), %ecx
	movl 12(%ebp), %eax
	addl %ecx, %eax
	movzwl (%eax), %eax
	cmpw %ax, %dx
	je C
B:
	movl $0, %eax
	jmp	D
C:
	movl 8(%ebp), %eax
	movl 4(%eax), %eax
	movl %eax, 8(%ebp)
	addl $1, -4(%ebp)
A:
	movl -4(%ebp), %eax
	cmpl 16(%ebp), %eax
	jl E
	cmpl $0, 8(%ebp)
	sete %al
	movzbl %al, %eax
D:
    movl %ebp, %esp
    popl %ebp
	ret