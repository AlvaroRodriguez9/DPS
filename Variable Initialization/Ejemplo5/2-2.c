#include <stdio.h>

unsigned long long int factorial(unsigned int i){
    if(i <= 1){
        return 1;
    }
    return i * factorial(i-1); //INT30-C
}


int main(int argc, char *argv[]){
    int i = 12, j= 3, f=0; //DCL04-C, DCL00-C, DCL01-C

    if(argc == 1){
        printf("Factorial of %d is %11d\n", i, factorial(i));
    }
    else{
        j = atoi(argv[1]);
        for(f=0;f<j;f++){
            printf("Factorial of %d is %11d\n",f,factorial(f));
        }
    }
    return 0;
}


/*
    1.- Este código te calcula el factorial del numero que le pases por parametro.
        Por defecto si no le pasas ningun numero te calcula el factorial de 12.

    2.- INT30-C Ensure that unsigned integer operations do not wrap. (No contemplamos nunca que el
        numero introducido este dentro de unos limites)
        DCL04-C. Do not declare more than one variable per declaration
        DCL00-C. Const-qualify immutable objects (La i en este caso nunca deberia cambiar) 
        DCL01-C. Do not reuse variable names in subscopes 
        INT08-C. Verify that all integer values are in range
    
    3.- En esta carpeta dejo adjuntado las capturas de pantalla de las instrucciones en ensamblador. 
        También se adjuntas capturas de las estadisticas que nos da perf y capturas de uso de 
        valgrind y kcachegrind. 

    4.- La instrucción que más tiempo de CPU requiere es el printf de la línea 20 ya que es la que más consume 
        como se puede ver en la captura. Esto es así porque es la línea que llama a factorial y no acaba hasta que ha calculado 
        todos los factoriales anteriores. 

*/