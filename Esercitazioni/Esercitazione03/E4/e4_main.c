#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tokenize(const char* text, char ***tokens);

int score, trials;

int equal(char** a, int na, char** b, int nb) {
    int i;
    if (na != nb) return 0;
    for (i=0; i<na; ++i)
        if (strcmp(a[i],b[i]) != 0) return 0;
    return 1;
}

void print(char* msg, char* tokens[], int n) {
    int i;
    printf("%s", msg);
    for (i=0; i<n; ++i) printf("[%s] ", tokens[i]);
    printf("\n");
}

void delete(char** tokens, int n) {
    int i;
    for (i=0; i<n; ++i) free(tokens[i]);
    free(tokens);
}

void test(char* text, char* sol[], int c) {
    trials++;
    char **tokens;
    int r = tokenize(text, &tokens);
    printf("Test %d: %d token [corretto: %d token]\n", trials, r, c);
    print(" - Calcolato: ", tokens, r);
    print(" - Corretto:  ", sol, c);
    score += equal(tokens, r, sol, c);
    delete(tokens, r);
}

int main() {

    char* s1[] = {"Under", "a", "Blood", "Red", "Sky"};
    char* s2[] = {"Seventh", "Son", "of", "a", "Seventh", "Son"};
    char* s3[] = {"Twenty", "Something"};
    char* s4[] = {"Beethoven", "Concerto", "fuer", "Violin", "Op.", "61"};

    test(" Under a Blood Red Sky ", s1, 5);
    test("Seventh Son of a Seventh Son ", s2, 6);
    test("Twenty Something", s3, 2);
    test("Beethoven Concerto fuer Violin  Op. 61", s4, 6);

    printf("Risultato: %d/%d\n", score, trials);

    return 0;
}
