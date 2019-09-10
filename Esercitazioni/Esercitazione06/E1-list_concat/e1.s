.globl list_concat

list_concat:
	movl 8(%esp), %ecx	#node_t **c = l1;		//node_t *p = *l1;
	movl 4(%esp), %edx	#node_t *a = l2;
	movl (%edx), %eax	
	cmpl $0, %eax		#if(p != NULL) goto L;		//if (p==NULL) *l1 = l2;
	jnz L
	movl %ecx, (%edx)	#*c = a;
	jmp E			#goto E;
				#				//else {
L:      cmpl $0, 4(%eax)	#if((*p).next == NULL) goto F;	//while (p->next!=NULL) p = p->next;
	jz F
	movl 4(%eax), %eax	#p = (*).next;
	jmp L			#goto L;
F:      movl %ecx, 4(%eax)	#(*p).next = a;			//p -> next = l2;
E:				#;    			
