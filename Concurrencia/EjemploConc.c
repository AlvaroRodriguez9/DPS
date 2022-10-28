/**
 * Ejemplo de regla de concurrencia. 
 * Autor: Álvaro Rodrñiguez Carpintero
 * 
 * Regla que vamos a tratar: CON40-C Do not refer to an atomic variable twice in an expression
 * 
 * Esta regla nos dice que no escribas/uses a una variable atomica dos veces en la misma expresión.
 * 
 * Al realizar cualquier operación sobre una variable atómica esta operación se considera una 
 * operación atómica de lectura y escritura y esta operación es segura en términos de hilos.
 * 
 * Al hacer dos operaciones atómicas en la misma sentencia hacemos que el par de operaciones no
 * sean seguras para los hilos ya que un hilo puede cambiar la variable en el tiempo entre medias de 
 * las dos operaciones.
*/


    //EJEMPLO ERRÓNEO QUE NO SE DEBERÍA USAR


/*
#include<stdio.h>
#include <stdatomic.h>

   

int main(void){

static atomic_int n= 5;
   
n = n + 4;

printf("El valor de n es: %u", n);

return 0;

}

*/

//La solución a esto es guardar en una variable el antiguo valor de n y asi nos ahorramos usar dos atomic en la misma expresión.

#include<stdio.h>
#include <stdatomic.h>


int main(void){

static atomic_int n= 5;

int nVieja = n;
   
n = nVieja + 4;

printf("El valor de n es: %u", n);

return 0;

}

