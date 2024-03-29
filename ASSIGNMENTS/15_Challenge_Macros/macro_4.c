#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define IS_LOWER(x)                       \
    ((islower(x)) ? 1 : (isdigit(x)) ? -1 \
                                     : 0)

#define IS_UPPER(x)                       \
    ((isupper(x)) ? 1 : (isdigit(x)) ? -1 \
                                     : 0)

int main(void)
{
    char c = '\0';

    printf("Please enter the the letter ...\n");
    scanf("%c", &c), fflush(stdin);

    if (IS_LOWER(c) == 1)
    {
        printf("The char %c is lower\n", c);
    }
    else if (IS_UPPER(c) == 1)
    {
        printf("The char %c is upper\n", c);
    }
    else
    {
        printf("The char %c is not alphabetical\n", c);
    }

    return 0;
}