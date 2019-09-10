#include "e1.h"

int matsum(int** m, int n){
    int i, j, s = 0;
    for (i=0; i<n; ++i)
        for (j=0; j<n; ++j)
            s += m[i][j];
    return s;
}
