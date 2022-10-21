/*
 * EJEMPLO 1
 * Autor: Álvaro Rodríguez Carpintero
*/

#include<stdio.h>
#include<stddef.h>

const char *p;

char *funcion1(void){
    char array[10] = "MiCadena";
    /*Initialize array*/
    return array;
}

void funcion2(void){
    const char cstr[] = "Todovabien";
    p =  cstr;
} 

void funcion3(void){
    printf("%s\n",p);
}

int main(void) {

    p = funcion1();
    printf( "%s \n", p);
    funcion2();
    funcion3();
    printf("%s \n" , p);

    return 0;
}

/*
La regla que se incumple es: DCL30-C. Declare objects with appropriate storage durations.
Estamos declarando arrays y variables con una visibiidad local y luego queremos acceder a ellas 
desde otra parte del programa. Esto hace que el resultado sea erronéo y aparezca basura en la ejecución.
PRUEBA
*/