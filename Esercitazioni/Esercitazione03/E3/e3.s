.globl clone

clone:
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $12, %esp	
	movl 28(%esp), %esi	#const void* si = src;
	movl 32(%esp), %ebx	#int b = n;
	movl %ebx, (%esp)
	call malloc		#void* a = malloc(n);	//void* des = malloc(n);
	movl %eax, %edi		#void* di = a;
    	testl %edi, %edi	#if(di == 0) goto N;	//if (des==0) return 0;
	je N
	movl %edi,(%esp)
	movl %esi,4(%esp)
	movl %ebx,8(%esp)
    	call memcpy		#memcpy(des, src, n);	//memcpy(des, src, n);
	movl %edi, %eax		#int a = di;
				#return a;		//return des;
N:	addl $12, %esp
	popl %ebx
	popl %esi
	popl %edi		#a = 0;
	ret			#return a;
