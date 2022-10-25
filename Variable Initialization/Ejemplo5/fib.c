//fib.c

#include <stdio.h>
#include <stdlib.h>

int fib(int x){
    if (x == 0) return 0;
    else if(x == 1) return 1;
    return fib(x-1) + fib(x-2);
}

int main (int argc , char *argv[]){
    for(size_t i = 0 ; i < 30 ; ++i){
        printf( "%d\n",fib(i));
}
return 0;
}

/*
La instrucción que mas tiempo requiere es la 14 ya que es la que llama a fib por primera vez,
y no acaba hasta que recursivamente acabe de todas las llamadas "hijas" a fib -1 y fib -2 que a 
su vez vuelven a llamar a fib.
*/