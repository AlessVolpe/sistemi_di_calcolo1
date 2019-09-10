.globl fib

fib:
	pushl %edi
	pushl %ebx
	subl $4, %esp	
	movl 16(%esp), %edi	#int di = n;	//if (n<2) return 1;
	movl $1, %eax		#int a = i;
	cmpl $2, %edi		#if(di<2) goto E;
	jl E
	decl %edi		#di--;
	movl %edi, %eax
	movl %eax, (%esp)	#a = fib(di);
	call fib
	movl %eax, %ebx		#int b = a;
	decl %edi		#di--;
	movl %edi, %eax
	movl %eax, (%esp)
	call fib		#a = fib(di);
	addl %ebx, %eax		#a = a + b;
E:	addl $4, %esp
	popl %ebx
	popl %edi    	
	ret			#return a;//return fib(n-1)+fib(n-2);
