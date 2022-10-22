#include <stdio.h>
#include <stdarg.h>

enum{ va_eol = -1 };

unsigned int average(int first, ...){
    unsigned int count = 0;
    unsigned int sum = 0;
    int i = first;
    va_list args;

    va_start(args ,first);

    while(i != va_eol){
        sum += i;
        count++;
        i = va_arg(args, int);
    }

    va_end(args);
    return( count ? (sum / count) : 0);
}


int main(void){
    average(2,6);
    return 0;
}

/*
    1.- Este código lo que hace es calcular la media de una lista pasada. Suma los elementos que hay 
        y va incrementando el contador. Cuando se llega al final divide la suma total entre elnúmero
        de elementos que había.

    2.- Asignas a va_eol -1 para que mientras i no sea ese valor siga sumando los elementos y aumente el contador en 1
        pero cuando i valga -1 (end of the list) el bucle pare porque ya hemos llegado al final de la lista.

    3.-cc1: error: command-line option ‘-Wctor-dtor-privacy’ is valid for C++/ObjC++ but not for C [-Werror]
        cc1: error: command-line option ‘-Wnoexcept’ is valid for C++/ObjC++ but not for C [-Werror]
        cc1: error: command-line option ‘-Wold-style-cast’ is valid for C++/ObjC++ but not for C [-Werror]
        cc1: error: command-line option ‘-Woverloaded-virtual’ is valid for C++/ObjC++ but not for C [-Werror]
        cc1: error: command-line option ‘-Wsign-promo’ is valid for C++/ObjC++ but not for C [-Werror]
        cc1: error: command-line option ‘-Wstrict-null-sentinel’ is valid for C++/ObjC++ but not for C [-Werror]

*/