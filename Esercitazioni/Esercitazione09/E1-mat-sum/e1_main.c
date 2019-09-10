#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "e1.h"

int score, trials;

int** new_matrix(int n) {
    int i, j, **m = malloc(n*sizeof(int*));
    assert(m!=NULL);
    for (i=0; i<n; ++i) {
        m[i] = malloc(n*sizeof(int));
        assert(m[i]!=NULL);
        for (j=0; j<n; ++j)
            m[i][j] = 2+i+j;
    }
    return m;
}

void delete_matrix(int** m, int n) {
    int i;
    for (i=0; i<n; ++i) free(m[i]);
    free(m);
}

void test(int n, int ok){
    trials++;
    int** m = new_matrix(n);
    int res = matsum(m, n);
    delete_matrix(m, n);
    printf("Test %d: risultato=%d [corretto=%d]\n", trials, res, ok);
    score += res == ok;
}

int main() {
    
    test(1, 2);
    test(10, 1100);
    test(100, 1010000);

    printf("Risultato: %d/%d\n", score, trials);
    return EXIT_SUCCESS;
}
