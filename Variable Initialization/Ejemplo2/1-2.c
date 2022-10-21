#include<stdlib.h>

struct flexArrayStruct{
int num;
int data[1];
};

void func(size_t array_size){
/*Space is allocated for the struct*/
struct flexArrayStruct *structP = (struct flexArrayStruct *)malloc(sizeof(struct flexArrayStruct)+sizeof(int)*(array_size - 1));
if(structP == NULL){
/*Handle malloc failure */
}

structP -> num = array_size;

/*
*Accessdata[] as if it had been allocated as data[arraysize].
*/

for(size_t i=0; i<array_size; ++i){
structP -> data[i] = 1;
}
}


//SOLUCION (Mirar https://wiki.sei.cmu.edu/confluence/display/c/DCL38-C.+Use+the+correct+syntax+when+declaring+a+flexible+array+member)

/*
1.-
     Este trozo de código lo que hace es declarar un array flexible y rellenarlo. Un array flexible es un tipo de array cuyo 
ultimo elemento tiene un tipo incompleto de array, es decir, que no tiene un tamaño especificado.  En este caso es erroneo porque el
último miembro de la estructura si tiene un tamaño que es de 1, con lo cual, el programa tiene un comportamiento indefinido al colocar 
elementos a partir del primero.

2.- 
    El error se encuentra en la linea 5 donde colocamos el 1. 

3.-
    La regla incumplida es: DCL38-C. Use the correct syntax when declaring a flexible array member-

    La solución es  la del final del documento.

*/



#include <stdlib.h>
  
struct flexArrayStruct{
  int num;
  int data[]; //VEMOS QUE SE HA QUITADO EL 1
};
 
void func(size_t array_size) {
  /* Space is allocated for the struct */
  struct flexArrayStruct *structP
    = (struct flexArrayStruct *)
    malloc(sizeof(struct flexArrayStruct)
         + sizeof(int) * array_size); //YA NO SE RESTA 1
  if (structP == NULL) {
    /* Handle malloc failure */
  }
 
  structP->num = array_size;
 
  /*
   * Access data[] as if it had been allocated
   * as data[array_size].
   */
  for (size_t i = 0; i < array_size; ++i) {
    structP->data[i] = 1;
  }
}