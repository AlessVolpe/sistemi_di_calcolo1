#include "e1.h"

int sub_array(const short *a, unsigned na, const short *b, unsigned nb) {
    int i;
    for (i=0; i+na <= nb; ++i) {
        int res;
        is_prefix(a, b+i, na, &res);
        if (res) return 1;
    }
    return 0;
}
