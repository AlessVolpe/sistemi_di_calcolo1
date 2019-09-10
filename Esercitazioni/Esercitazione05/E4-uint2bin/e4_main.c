#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "e4.h"

int score, trials;

void to_string(char buf[32], char str[33]) {
    memcpy(str,buf,32);
    str[32]=0;
}

void test(unsigned x, char ok_buf[32]) {
    trials++;
    char* res = malloc(33); 
    uint2bin(x, res);
    res[32]=0;
        
    printf("Test %d: %s [corretto: %s]\n", trials, res, ok_buf);
        
    score += memcmp(res, ok_buf, 32) == 0;
    free (res);
}

int main() {

    test(0xFFFFFFFF, "11111111111111111111111111111111");
    test(0x0, "00000000000000000000000000000000");
    test(0xDEADBEEF, "11110111011111011011010101111011");
    test(0xCADEBABA, "01011101010111010111101101010011");

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
