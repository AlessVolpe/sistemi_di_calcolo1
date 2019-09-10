#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Scrivere in C una funzione tokenize che, data una stringa text, estrae
// tutti i token separati da spazi, li fa puntare da un array di
// stringhe nell'ordine in cui vengono incontrati in text, e
// restituisce in *tokens il puntatore all'array di stringhe. La funzione
// restituisce il numero di token trovati (che coincide con la
// lunghezza dell'array di token). Sia i token che l'array di token
// devono essere allocati dinamicamente. Si noti che non ci saranno
// mai più di n/2 token in un testo di lunghezza n.

int tokenize(const char* text, char ***tokens) {
    unsigned i;
    unsigned start;
    unsigned cnt = 0;
    unsigned n = strlen(text);
    char **vec = malloc(n/2*sizeof(short*));
    char *tok;
    assert(vec!=NULL);

    for (i=0; i<n; ++i)
        if (text[i]!=' '){
            if ((i==0   || text[i-1]==' '))  start = i;
            if ((i+1==n || text[i+1]==' ')) {
                tok = malloc(i-start+2);
                assert(tok!=NULL);
                memcpy(tok, text+start, i-start+2);
                tok[i-start+1]=0;
                vec[cnt++] = tok;
            }
        }

    *tokens = vec;
    return cnt;
}
