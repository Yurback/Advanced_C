#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    srand(time(0));

    for (int i = 0; i < 10; i++)
    {
        printf(" %d ", rand());
    }

    printf("\n");

    return 0;
}
