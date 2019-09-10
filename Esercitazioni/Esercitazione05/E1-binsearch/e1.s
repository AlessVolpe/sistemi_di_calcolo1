.globl binsearch

binsearch:
	pushl %edi
	pushl %esi
	pushl %ebx
	pushl %ebp
	movl 20(%esp), %edx	
	movl 24(%esp), %ebx	
	movl 28(%esp), %ebp
	xorl %esi, %esi			#int i = 0;		//int i=0, j=n;
	movl %ebx, %edi			#int j = n;
	movl $1, %eax			#int a = 1;
L:    	cmpl %edi, %esi			#if(i >= j) goto E0;	//while (i<j) {
	jge E0
	leal (%edi,%esi), %ecx
        sarl %ecx		 	#int m = (i+j) >> 1;	//int m = (i+j)/2;
        cmpl %ebp, (%edx,%ecx,4)	#if(v[m] == x) goto E1;	//if (v[m]==x) return 1;
	je E1
        cmpl %ebp, (%edx,%ecx,4)	#if(v[m] <= x) goto F;	//if (v[m]>x) j=m;
	jle F
	movl %ecx, %edi			#j = m;
	jmp L				#goto L;
E0:	xorl %eax, %eax			#a = 0;
E1:	popl %ebp
	popl %ebx	
	popl %esi
	popl %edi	
	ret				#return a;
F:	leal 1(%ecx), %esi		#i = m+1;
	jmp L				#goto L;//else i=m+1; //return 0;
