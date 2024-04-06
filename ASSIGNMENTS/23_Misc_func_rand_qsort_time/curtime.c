#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

    time_t now = time(NULL);

    char *lt = NULL;

    lt = ctime(&now);

    if (lt == NULL)
    {
        printf("Exception is arised, caused by timehanlding\n");
        exit(-1);
    }

    printf("%s\n", lt);

    return 0;
}