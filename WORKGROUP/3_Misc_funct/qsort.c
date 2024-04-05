#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int data[5] = {54, 3, 12, 9, 24};
    int func(const void *p2, const void *p1)
    {

        const int x = *(const int *)p2;
        const int y = *(const int *)p1;
        return x > y;
    };

    qsort(data, 5, sizeof(int), &func);

    for (int i = 0; i < 5; i++)
        printf("%d\n", data[i]);

    return 0;
}