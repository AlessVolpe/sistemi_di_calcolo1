#include <stdio.h>
#include <string.h>

char *my_strcat(char *dest, const char *src);

int score, trials;

void test(char *x, const char *y, const char *c) {
    trials++;
    char* r = my_strcat(x, y);
    printf("Test %d: \"%s\" [corretto: \"%s\"]\n", trials, r, c);
    score += strcmp(r,c) == 0;
}

int main() {

    char s1[] = "hello-----------------";
    char s2[] = "ham-------------------";
    char s3[] = "up--------------------";
    char s4[] = "----------------------";
    s1[5] = s2[3] = s3[2] = s4[0] = 0;

    test(s1, " world", "hello world");
    test(s2, "burger",  "hamburger");
    test(s3, "", "up");
    test(s4, "computing systems", "computing systems");

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
