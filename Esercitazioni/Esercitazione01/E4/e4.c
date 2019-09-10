#include <string.h>
char *my_strcat(char *dest, const char *src) {
    // scrivere la soluzione qui...
    char *temp = dest;
    while (*dest)
        dest++;
    while (*dest++ = *src++)
        ;
    return temp;
}
