.globl charfreq

charfreq:
	pushl %edi
	pushl %esi
	pushl %ebx
	subl $1036, %esp	
	leal 12(%esp), %ebx		#unsigned freq[256];
	movl %ebx, (%esp)
	movl $0, 4(%esp)
	movl $1024, 8(%esp)
	call memset			#memset(freq, 0, 256*sizeof(unsigned));
	movl 1052(%esp), %esi
L1:	movb (%esi), %cl		#char c = *s;
	movzbl %cl, %ecx	
	testl %ecx, %ecx		#if(c == 0) goto F;
	jz F
	incl (%ebx,%ecx,4)		#freq[c]++;
	incl %esi			#s++;
	jmp L1				#goto L1;
F:	xorl %eax, %eax			#unsigned maxi = 0;
	movl (%ebx), %edx		#unsigned maxf = freq[0];
	movl $1, %edi			#int i = 1;
L2:	cmpl $256, %edi			#if(i >= 256) goto E;
	jge E
	cmpl %edx, (%ebx,%edi,4)	#if(freq[i]>maxf) maxi = i;
	cmovgl %edi, %eax
					#if(freq[i]>maxf) maxf = freq[i];
	cmovgl (%ebx,%edi,4), %edx
	incl %edi			#++i;
	jmp L2				#goto L2;
E:	addl $1036, %esp		
	popl %ebx
	popl %esi
	popl %edi
	ret				#return maxi;
