// inserire il C equivalente qui...
#include "e1.h"

int is_prefix(const char* s1, const char* s2) {
    const char* ecx = s1;
    const char* edx = s2;

L:  if (*ecx == 0) goto F;
    if (*ecx != *edx) goto E;
    ecx++;
    edx++;
    goto L;

F: return 1;
E: return 0;
} 