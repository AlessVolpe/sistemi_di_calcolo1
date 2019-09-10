.globl lcm

lcm:	
	pushl %esi
	pushl %edi
	pushl %ebx
	movl 16(%esp), %esi	#int si = x;
	movl 20(%esp), %edi	#int di = y;
	movl %edi, %ecx		#int c = di;		//int greater = y;
    	cmpl %edi, %esi		#if(si <= di)
	cmovg %esi, %ecx	#c = si;
				#int a;			//if (x > y)
L:      movl %ecx, %eax		#a = c;			//greater = x;
	movl %eax, %edx		#int d = a % si;
	sarl $31, %edx		
	idivl %esi
	testl %edx, %edx	#char bl = d == 0;
	setzb %bl
	movl %ecx, %eax		#a = c;
	movl %eax, %edx
	sarl $31, %edx		
	idivl %edi		#d = a % di;
	testl %edx, %edx
	setzb %bh		#char bh = d == 0;
    	andb %bh, %bl		#bl = bl & bh;		//while (1) {
        jz F			#if(bl == 0) goto F;//if ((greater % x == 0) && (greater % y == 0))
	movl %ecx, %eax		#a = c;
	popl %ebx
	popl %edi
	popl %esi
	ret			#return a;		//return greater;
F:	incl %ecx		#c++;
	jmp L			#goto L;		        //greater++;
