#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "e1.h"

int score, trials;

void test(const node_t *p, short *buf, int n, int ok){
    trials++;
    int res = list_equal_array(p, buf, n);
    printf("Test %d: risultato=%d [corretto=%d]\n", trials, res, ok);
    score += res == ok;
}

int main() {

    node_t *p;
    short buf[]  = { 1, 1, 2, 3, 5, 8, 13, 21 };
    short buf2[] = { 9, 1, 2, 3, 5, 8, 13, 21 };
    int n = sizeof(buf) / sizeof(short);

    assert(!list_new_from_buffer(&p, buf, n));
    
    test(p, buf, n, 1);            // 1
    test(p, buf, n - 1, 0);        // 0
    test(p, buf+1, n - 1, 0);      // 0

    assert(!list_delete_first(&p, NULL));
    test(p, buf+1, n - 1, 1);      // 1
    
    assert(!list_add_first(&p, 9));
    test(p, buf2, n, 1);           // 1

    printf("Risultato: %d/%d\n", score, trials);
    return 0;
}

int list_new_from_buffer(node_t **l, short* buf, int n){
    *l = NULL;
    while (--n >= 0)
        if (list_add_first(l, buf[n])) return 1;
    return 0;
}

void list_delete(node_t **l) {
    node_t *p = *l;
    for (;p != NULL; p=p->next) {
        node_t *dead = p;
        p = p->next;
        free(dead);
    }
    *l = NULL;
}

int list_add_first(node_t **l, short elem) {
    node_t *p = *l;
    node_t *n = malloc(sizeof(node_t));
    if (n == NULL) return -1;           // allocation error
    n->elem = elem;
    n->next = p;
    *l = n;
    return 0;
}

int list_delete_first(node_t **l, short *elem){
    node_t *p = *l;
    if (p == NULL) return -1;
    if (elem != NULL) *elem = p->elem;

    node_t *dead = p;
    p = p->next;
    free(dead);

    *l = p;

    return 0;
}
