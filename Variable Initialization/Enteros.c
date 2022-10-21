/**
 * Ejemplos de incumplimiento de reglas con ENTEROS
 * 
 * Autor: Álvaro Rodríguez Carpintero
*/

#include <stdio.h>
#include <limits.h>

//INT32-C. Ensure that operations on signed integers do not result in overflow

//Non-compilant Unary negation

/*
void func(signed long s_a) {
  signed long result = -s_a;
  printf("El negativo de %li es: %li", s_a, result);
}
*/

//Compilant solution

void func(signed long s_a) {
  signed long result;
  if (s_a == LONG_MIN) {
    printf("Error the operand is equal to the minimum (negative) value for the signed integer type.");
  } else {
    result = -s_a;
  }
  
}


//INT31-C. Ensure that integer conversions do not result in lost or misinterpreted data

//Non-compilant
/*

void funcion31C(void) {
  unsigned long int u_a = ULONG_MAX;
  signed char sc;
  sc = (signed char)u_a;  Cast eliminates warning 
 
}
*/


//Compilant

void funcion31C(void) {
  unsigned long int u_a = ULONG_MAX;
  signed char sc;
  if (u_a <= SCHAR_MAX) {
    sc = (signed char)u_a;  /* Cast eliminates warning */
  } else {
    printf("ERROR posible perdida de datos");
  }
}



int main(void){
    func(3887);
    return 0;
}
 

