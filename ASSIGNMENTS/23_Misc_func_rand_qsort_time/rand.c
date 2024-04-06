#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t seed = time(NULL);
    srand(seed);

    for (int i = 0; i < 50; printf("%f\n", (double)(rand() % 99 - 49) / 100), i++)
        ;

    return 0;
}