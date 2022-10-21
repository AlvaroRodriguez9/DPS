/*
 * EJEMPLO 3
 * Autor: Álvaro Rodríguez Carpintero
*/


/*
1.-
    Entraria al switch e iria a la opción del 0 que asigna i=17 y al final lo mostraría porque 
    entraría al default ya que no hay ningún break.

2.- 
    La falta de break puede ser un problema. Entraria en la línea 27.
    Otro problema es que asingamos i = 4 dentro del switch antes del primer caso y a esa instrucción nunca se llega, línea 25.
    Este problema rompe la regla DCL41-C. Do not declare variables inside a switch statement before the first case label.
4.-
    SOLUCIÓN:

#include <stdio.h>
  
extern void f(int i);
  
int func(int expr) {
  
  int i = 4;
  f(i);
 
  switch (expr) {
    case 0:
      i = 17;
      
    default:
      printf("%d\n", i);
  }
  return 0;
}

5.- 
    A ) RATS:
        Rats no detecta nada malo en el código. 
    B) CPPCHECKER:
        Tampoco me detecta nada raro.
    C) SPLINT: 
        1-3.c: (in function func)
            1-3.c:58:10: Fall through case (no preceding break)
            Execution falls through from the previous case (use @fallthrough@ to mark
            fallthrough cases). (Use -casebreak to inhibit warning)
        1-3.c:60:13: Fall through case (no preceding break)
        1-3.c:56:15: Statement after switch is not a case: int i = 4
            The first statement after a switch is not a case. (Use -firstcase to inhibit
            warning)
        1-3.c:54:6: Function exported but not used outside 1-3: func
            A declaration is exported, but not used outside this module. Declaration can
            use static qualifier. (Use -exportlocal to inhibit warning)
            1-3.c:63:1: Definition of func

        Finished checking --- 4 code warnings
    
    D) VERA++:
        1-3.c:1: no copyright notice found
        1-3.c:9: trailing whitespace
        1-3.c:12: trailing whitespace
        1-3.c:14: line is longer than 100 characters
        1-3.c:15: line is longer than 100 characters
        1-3.c:20: trailing whitespace
        1-3.c:22: trailing whitespace
        1-3.c:24: trailing whitespace
        1-3.c:27: trailing whitespace
        1-3.c:38: trailing whitespace
        1-3.c:40: trailing whitespace
        1-3.c:43: trailing whitespace
        1-3.c:60: too many consecutive empty lines
        1-3.c:70: keyword 'switch' not followed by a single space
        1-3.c:76: comma should be followed by whitespace
        1-3.c:77: closing curly bracket not in the same line or column
        1-3.c:78: closing curly bracket not in the same line or column
        1-3.c:83: no newline at end of file
        1-3.c:83: closing curly bracket not in the same line or column

    E) VALGRIND
        ==19547== Memcheck, a memory error detector
        ==19547== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
        ==19547== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
        ==19547== Command: ./a.out
        ==19547== 
        17
        ==19547== 
        ==19547== HEAP SUMMARY:
        ==19547==     in use at exit: 0 bytes in 0 blocks
        ==19547==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
        ==19547== 
        ==19547== All heap blocks were freed -- no leaks are possible
        ==19547== 
        ==19547== For lists of detected and suppressed errors, rerun with: -s
        ==19547== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

*/


# include <stdio.h>

extern void f(int i);

void func(int expr){
    switch(expr){
        int i = 4;
        f(i);
        case 0:
            i = 17;
        default:
            printf("%d\n",i);
}
}

int main(void){
    func(0);
    return 0;
}