/*
 * EJEMPLO 1
 * Autor: Álvaro Rodríguez Carpintero
*/


/**
#include<stdio.h>
#include<stddef.h>

const char *p;

char *funcion1(void){
    char array[10] = "MiCadena";
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

**/

/*
La regla que se incumple es: DCL30-C. Declare objects with appropriate storage durations.
Estamos declarando arrays y variables con una visibiidad local y luego queremos acceder a ellas 
desde otra parte del programa. Esto hace que el resultado sea erronéo y aparezca basura en la ejecución.
*/


//CORRECCIÓN

#include<stdio.h>
#include<stddef.h>

const char *p;
char array[10];
const char cstr[] = "Todo va bien";

char *funcion1(char *x){
    x = "Mi Cadena";
    return x;
}

void funcion2(void){
    p =  cstr;
} 

void funcion3(void){
    printf("%s\n",p); //Todo va bien
}

int main(void) {

    p = funcion1(array);
    printf( "%s \n", p); //MiCadena
    funcion2();
    funcion3();
    printf("%s \n" , p); //Todo va bien

    return 0;
}

/*
La solución propuesta es sacar todas las variables a una visibilidad global, asi se puede acceder a ella desde cualquier parte del 
programa que es lo que se quiere.
*/