#include <stdio.h>

#define PRTINT(x) printf(#x " is a %d\n", x);

int main(void)
{
    int count = 10;
    PRTINT(count);

    return 0;
}