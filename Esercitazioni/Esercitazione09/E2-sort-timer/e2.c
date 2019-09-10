#include "e2.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int i = 0;
int MAX;

void handler (int signo) {
    printf("%f %%\n", 100.0*i/MAX);
    ualarm(50000000U, 0);
}

static void do_sort(int *v, int n) {
    int i, j;
    for (i=0; i<n; ++i)
        for (j=1; j<n; ++j)
            if (v[j-1] > v[j]) {
                int tmp = v[j-1];
                v[j-1] = v[j];
                v[j] = tmp;
            }
}

void sort(int *v, int n) {
    struct sigaction act = {0};
    act.sa_handler = handler;
    if (sigaction(SIGALRM, &act, NULL) == -1) exit(EXIT_FAILURE);
    ualarm(50000000U, 50000000U);
    do_sort(v, n);
}

