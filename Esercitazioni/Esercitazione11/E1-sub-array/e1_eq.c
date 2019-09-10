// inserire il C equivalente qui...
#include "e1.h"
#include <stdio.h>

int sub_array(const short* a, unsigned na, const short* b, unsigned nb) {
    int edi = 0;
    const short* ebx = a;
    const short* esi = b;
    unsigned ecx = na;
    unsigned edx = nb;

L:  if (edi+ecx > edx) goto F;
    int eax;
    esi += edi;
    is_prefix(ebx, esi, ecx, &eax);
    esi -= edi;
    if (!eax) {
        edi++;
        goto L;
    } goto E;

F: return 0;
E: return 1;
}