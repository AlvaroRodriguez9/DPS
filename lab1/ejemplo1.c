/**
 *  
 * The student needs to compile, test and comment the source code file.
 * 
 * Enumerate those Rules and Recommendation associated that are broken in the 
 *     previous source code file.
 * Enumerate he compilation tools and paramenters (gcc vs g++ ), -Wall ...
 * Enumerate the standard associated  -std=c99, -std=c11
 * 
 * There are several variants. You should choose at least two. You can also try clang.
 * At the end the source code  should compile without warnings to the variant 
 *     selected (you can remove/change instructions).
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
char array1[] = "Foo" "bar";
char array2[] = { 'F', 'o', 'o', 'b', 'a', 'r', '\0' };
 
enum { BUFFER_MAX_SIZE = 1024 };
 
const char* s1 = "foo(Hello World)foo"; 
const char* s2 = "\nHello\nWorld\n";

void gets_example_func(void) {
  char buf[BUFFER_MAX_SIZE];
 
  if (fgets(buf, sizeof(buf), stdin) == NULL) {
        return;
  }
  buf[strlen(buf) - 1] = '\0';
}

char *get_dirname(const char *pathname, char *dirname, size_t size) {
  const char *slash;
  slash = strrchr(pathname, '/');
  if (slash) {
    ptrdiff_t slash_idx = slash - pathname;
    if ((size_t)slash_idx < size) {
      memcpy(dirname, pathname, slash_idx);
      dirname[slash_idx] = '\0';     
      return dirname;
    }
  }
  return 0;
}

void get_y_or_n(void) {  
	char response[8];

	printf("Continue? [y] n: ");  
	fgets(response, 2,stdin); //MSC34-C

	if (response[0] == 'n') 
		exit(0);  

	return;
}

 
int main(int argc, char *argv[])
{
    (void)argc;
    char key[24];
    char response[8];
    char array3[16];
    char array4[16];
    char array5 []  = "01234567890123456";
    char ptr_char[]  = "new string literal";
    //int size_array1 = strlen("аналитик");
    //int size_array2 = 100;
    
   // char analitic1[size_array1]="аналитик"; //STR38-C
   // char analitic2[size_array2]="аналитик";
   //char analitic3[100]="аналитик"; STR11-C

    char dirname[260];
    if (get_dirname(__FILE__, dirname, sizeof(dirname))) {
        puts(dirname);
    }

        
    strcpy(key, argv[1]);  
    strcat(key, " = ");  
    strcat(key, argv[2]);


    fgets(response,sizeof(response),stdin);
    
    get_y_or_n();

    printf ("%s",array1); //STR35-C
    printf ("\n");
    printf ("%s",array2);
    printf ("\n");
 
    puts (s1);
    printf ("\n");
    puts (s2);
    printf ("\n");
    
    strncpy(array3, array5, sizeof(array3));  //STR32-C
    strncpy(array4, array3, strlen(array3));
    
    array5 [0] = 'M';
    ptr_char [0] = 'N'; //STR30-C
    
    array3[sizeof(array3)-1]='\0';
    
    
    return 0;
}

/**
Resolución de ejercicios 
1.- se rompe la regla STR30-C "Do not attempt to modify string literals".
    se rompe la regla STR11-C "Do not specify the bound of a character array initialized with a string literal"
    se rompe la regla MSC34-C "Do not use deeprecated or obsolescent functions"
    se rompe la regla STR35-C "Do not copy data from an unbounded source to a fixed length array"
    se rompe la regla STR32-C "Do not pass a non-null-terminated character sequence to a library function that expects a string"
    se rompe la regla STR38-C "Do not confuse narrow and wide character strings and functions"
2.- gcc -Wall -pedantic -std=c11 ejemplo1.c
    gcc -Wall -pedantic -std=c99 ejemplo1.c
*/


