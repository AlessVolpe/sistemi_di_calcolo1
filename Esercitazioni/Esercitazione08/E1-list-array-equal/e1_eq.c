#include "../e1.h"
#include <stdlib.h>

int list_equal_array(const node_t *p, short *buf, int n) {

    const node_t *edx = p;
    short *ebx = buf;
    int edi = n;

    // Registers; i<->ecx, p<->edx, tmp<->eax, buf <-> ebx, n <->edi

    int ecx=0;
L:  if (ecx >= edi) goto E;
    if (edx == NULL) goto F;
    int eax = edx->elem;
    if (eax != ebx[ecx]) goto F;
    edx = edx->next;
    ecx++;
    goto L;
E:  return edx == NULL;
F:  return 0;
}