#include "e1.h"
#include <stdlib.h>

int list_equal_array(const node_t *p, short *buf, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (p == NULL || p->elem != buf[i]) return 0;
        p = p->next;
    }
    return p == NULL;
}
