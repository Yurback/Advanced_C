#include <stdio.h>

int main(void)
{

    printf("this line code is %d\n", __LINE__);
    printf("this filename is %s\n", __FILE__);
    printf("data of compaling is %s\n", __DATE__);
    printf("time of compaling is %s\n", __TIME__);
    printf("compaler can work with C code, it is %d\n", __STDC__);

    return 0;
}