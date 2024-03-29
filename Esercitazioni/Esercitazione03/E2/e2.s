.globl counteq

counteq:
	pushl %edi	
	pushl %esi
	pushl %ebx	
	movl 16(%esp), %edi	#short* di = v1;
	movl 20(%esp), %esi	#short* si = v2;
	movl 24(%esp), %edx	#int d = n;
	xorl %eax, %eax		#int a = 0;		//int i, cnt = 0;
	decl %edx		#d--;
L:    	testl %edx, %edx	#if(d < 0) goto E;	//for (i=0; i<n; ++i) cnt += (v1[i]==v2[i]);
	jl E
	movw (%edi,%edx,2), %cx	#short c = di[d];
	movw (%esi,%edx,2), %bx	#short b = si[d];
	cmpw %cx, %bx		#char cl = c == b ? 1:0;
	sete %cl		#int cc = (int) cl;
	movsbl %cl, %ecx
	addl %ecx, %eax		#a = a + cc;
	decl %edx
	jmp L			#goto L;
E:	popl %ebx
	popl %esi
	popl %edi
	ret			#return a;
