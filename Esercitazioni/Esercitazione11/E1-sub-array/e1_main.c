#include "e1.h"
#include <stdlib.h>
#include <stdio.h>

void is_prefix(const short *a, const short *b, unsigned na, int* res) {
    int i;
    for (i=0; i<na; ++i)
        if (a[i] != b[i]) {
            *res = 0;
            return;
        }
    *res = 1;
}

int score, trials;

void test(const short* a, unsigned na, const short* b, unsigned nb, int ok){
    trials++;
    int res = sub_array(a, na, b, nb);
    printf("Test %d: risultato=%d [corretto=%d]\n", trials, res, ok);
    score += res == ok;
}

int main() {
    short a1[] = { 1, 7, 9 };
    short a2[] = { 1, 7, 4 };
    short a3[] = { };
    short a4[] = { 2, 5, 1, 7, 9, 4 };
    short a5[] = { 6 };
    short b[] = { 2, 5, 1, 7, 9, 4 };

    test(a1, 3, b, 6, 1);
    test(a2, 3, b, 6, 0);
    test(a3, 0, b, 6, 1);
    test(a4, 6, b, 6, 1);
    test(a5, 1, b, 6, 0);

    printf("Risultato: %d/%d\n", score, trials);

    return EXIT_SUCCESS;
}
