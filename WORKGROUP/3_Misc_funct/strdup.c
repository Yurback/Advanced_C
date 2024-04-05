#include <stdio.h>
#include <string.h>

int main()
{
    char *p1 = "Yuriy";
    char *p2 = NULL;

    p2 = strdup(p1);

    printf("Duplicated string is : %s\n", p2);

    char *f1 = "Reshetov";
    char *f2 = NULL;

    f2 = strndup(f1, 4);
    printf("This is 4bytes from f1 : %s\n", f2);

    printf("size_t is %ld", sizeof(size_t));

    return 0;
}