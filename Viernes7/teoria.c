#include <stdio.h>
#include <string.h>

int main()
{
    char a[16];
    char b[16];
    strncpy(a, "0123456789abcdef", sizeof(a));
    strncpy(b, a, strlen(a));
    printf("%s",a);
    printf("%s",b);

    return 0;
}