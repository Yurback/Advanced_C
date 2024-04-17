#include <stdio.h>
#include <malloc.h>
#include <unistd.h>

int *func(int *pt)
{
    pt = malloc(sizeof(int));
    return pt;
}

int main(void)
{
    int *a = NULL;
    a = malloc(sizeof(int));
    *a = 2;
    printf("Old addres %p\n", a);
    sleep(1);
    free(a);
    a = NULL;
    a = func(a);
    printf("New addres %p\n", a);
    *a = 2;
    printf("The value of a is %d", *a);
    free(a);
    a = NULL;
    printf("The addres after free of a is %p", a);
    return 0;
}