#include "e1.h"

int matsum(int** m, int n){
    int i, j, s = 0;
    i=0;
L1: if (i>=n) goto E;
    j=0;
L2: if (j>=n) goto F;
    int* tmp = m[i];
    s += tmp[j];
    ++j;
    goto L2;
F:  ++i;
    goto L1;
E:  return s;
}