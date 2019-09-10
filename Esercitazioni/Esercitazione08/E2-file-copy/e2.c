// Srivere la soluzione qui...
#include "e2.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define BUF_SIZE 100

int copy(const char* src, const char* dst) {
    int f_source = open(src, O_RDONLY);
    if (f_source == -1) {
        perror("Errore apertura sorgente");
        exit(EXIT_FAILURE);
    }    

    int f_dest = open(dst, O_WRONLY | O_TRUNC | O_CREAT, 0644);
    if (f_dest ==s -1) {
        perror("Errore apertura destinazione");
        exit(EXIT_FAILURE);
    }

    while(1){
        char* buffer = malloc(BUF_SIZE);
        ssize_t lect = read(f_source, buffer, BUF_SIZE);
        if (lect == -1) {
            perror("Errore nella lettura");
            exit(EXIT_FAILURE);
        } 
        else if (lect == 0) 
            break;

        int wrt = write(f_dest, buffer, lect);
        if (wrt == -1) {
            perror("Errore nella scrittura");
            exit(EXIT_FAILURE);
        }
    }

    int fd = close(f_source);
    if (fd == -1) {
        perror("Errore chiusura src");
        exit(EXIT_FAILURE);
    }
    
    fd = close(f_dest);
    if (fd == -1) {
        perror("Errore chiusura dst");
        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}