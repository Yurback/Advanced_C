#include <stdio.h>
#include <malloc.h>

void func(int **pt)
{
    *pt = malloc(sizeof(int));
}

int main(void)
{
    int *a = NULL;
    func(&a);
    *a = 2;
    printf("The value of a is %d", *a);
    free(a);
    a = NULL;

    return 0;
}