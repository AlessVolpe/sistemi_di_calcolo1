#include <stdio.h>

int f();

int main() {

    int x = f();
    printf("%d [corretto=16]\n", x);

    return 0;
}

