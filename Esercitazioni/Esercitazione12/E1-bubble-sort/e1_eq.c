#include "e1.h"
// inserire il C equivalente qui...
void bubble_sort(short* v, unsigned n) {
    unsigned edx, ecx; unsigned ebx = n; short* edi = v;

DL: ecx = 0;
    edx = 1;

FL: if (edx > ebx) goto T;
    unsigned eax = edx - 1;
    short dx = *(edi + eax);
    short cx = v[edx];
    if (dx <= cx) goto F;
    short* ax = edi + eax;
    short* d_x = edi + edx;
    swap(ax, d_x);
    ecx = 1; 

F:  edx++; goto FL;

T:  if (ecx == 0) return;
    goto DL;
}