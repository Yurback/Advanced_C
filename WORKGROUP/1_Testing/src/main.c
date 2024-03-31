#include <stdio.h>

#include "../headers/other.h"

int main(void)
{
    char *str = "ABC";

    str[2] = 'D';

    printf("%d\n", getfavouritnum());
    return 0;
}