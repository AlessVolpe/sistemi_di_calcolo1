#include <stdlib.h>
#include "e1.h"

void list_concat(node_t **l1, node_t *l2) {
	node_t **b = l1;	 	//node_t *p = *l1;
	node_t *a = *b;
    	if(a =! NULL) goto L;		//if (p==NULL) *l1 = l2;
	*l1 = l2;
	goto E;    	
L:	if((*a).next == NULL) goto T;	//else {
        a = (*a).next;			//while (p->next!=NULL) p = p->next;
        goto L;
T:	(*a).next = l2;			//p -> next = l2;
E:;    					//}
}
