#include <stdio.h>
#include <malloc.h>

void *foo(void *ptr)
{
    char arr[5] = {'a', 'b', 'c', 'd', 'e'};

    ptr = (char *)arr;
    return ptr;
}

int main()
{
    void *ptr = NULL;
    ptr = (int *)malloc(sizeof(int));
    *(int *)ptr = 10;
    ptr = foo(ptr);

    printf("%c\n", *(char *)ptr);

    return 0;
}