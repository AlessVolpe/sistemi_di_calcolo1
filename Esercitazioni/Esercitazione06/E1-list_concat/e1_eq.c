#include <stdlib.h>
#include "../e1.h"

void list_concat(node_t **l1, node_t *l2) {
	node_t **c = l1;		//node_t *p = *l1;
	node_t *a = *c;
	if(c != NULL) goto L;		//if (p==NULL) *l1 = l2;
	*l1 = l2;
	goto E;
					//else {
L:      if((*c).next == NULL) goto F;	//while (p->next!=NULL) p = p->next;
	c = (*c).next;
	goto L;
F      (*c).next = l2;			//p -> next = l2;
E:;    					//}		
}
					// Scrivere il C equivalente qui...
