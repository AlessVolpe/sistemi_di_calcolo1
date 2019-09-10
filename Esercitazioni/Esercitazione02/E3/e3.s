// scrivere la soluzione qui...
.globl my_strcmp

my_strcmp:
	movl 4(%esp), %ecx   # const char ecx = s1;
    movl 8(%esp), %edx   # const char edx = s2;
    movb (%ecx), %ah     # char ah = *ecx;
    movb (%edx), %al     # char al = *edx;
L:
    cmpb $0, %ah
    je E                 # if (ah == 0) goto E;
    cmpb %al, %ah
    jne E                # if (ah != al) goto E;
    incl %ecx            # ecx++;
    incl %edx            # edx++;
    movb (%ecx), %ah     # ah = *ecx;
    movb (%edx), %al     # al = *edx;
    jmp L                # goto L;
E:
    movl (%ecx), %eax    # char* eax = ecx
    subl (%edx), %eax    # eax = eax - edx

    ret                  # return eax;
