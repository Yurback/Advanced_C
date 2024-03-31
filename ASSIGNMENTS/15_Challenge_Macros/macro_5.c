#include <stdio.h>
#include <math.h>

#define IS_LOWER(x) (x >= 'a' && x <= 'z')

#define IS_UPPER(x) (x >= 'A' && x <= 'Z')

int main(void)
{
    double i = 5.05;
    i = pow(i, 3);
    printf("Power is %f\n", i);

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