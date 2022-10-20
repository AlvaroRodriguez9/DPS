#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

void optionOne(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

void optionTwo(){
    char *s = (char *) malloc(100);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
}

void optionThree(){
    char *s = (char *) malloc(100);
    free(s);
    strcpy(s, "Welcome Sanitizer!");
    printf("string is: %s\n", s);
}

void optionFour(){
    char *s = (char *) malloc(18);
    strcpy(s,  "Welcome Sanitizer!");
    printf("string is: %s\n", s);
    free(s);
}

int main(int argc, const char *argv[]) {

    int expression;
    char* p;
    errno = 0; 
    
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <option>\n", argv[0]);
        exit(1);
    }

    long arg = strtol(argv[1], &p, 10);

    if (*p != '\0' || errno != 0) {
        return 1; 
    }

    if (arg < INT_MIN || arg > INT_MAX) {
        return 1;
    }

    expression = arg;
 

    switch (expression)
    {
        case 1:
            optionOne();
            break;
        case 2:
            optionTwo();
            break;
        case 3:
            optionThree();
            break;
        case 4:
            optionFour();
            break;
        default:
            printf("\n");
            break;
    }

    return 0;
}

/**
 * 
 * COMANDO USADO: gcc -g -fsanitize=address -fno-omit-frame-pointer ejemplo2.c
 * 
 * 
 * En la opción 3 el error es este:
 * 
 * ==22758==ERROR: AddressSanitizer: heap-use-after-free on address 0x60b0000000f0 at pc 0x7fdc7f75a2c3 bp 0x7fff4c96f400 sp 0x7fff4c96eba8
 * 
 * Es un uso de memoria desasignada. 
 * Liberas la memoria y luego usas esa memoria pero ya esta borrada.

 * 
 * En la opción 4 el error es este:
 * 
 * ==21937==ERROR: AddressSanitizer: heap-buffer-overflow on address 0x603000000052 at pc 0x7f2c5cdc72c3 bp 0x7ffddfc70720 sp 0x7ffddfc6fec8
 * 
 * Es un buffer overflow en el monticulo de datos. 
 * Reservas para 18 caracteres pero la frase tiene 19.
*/