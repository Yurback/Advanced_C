#include <stdio.h>

int main(void)
{
    int normal = 2;
    int *pt = NULL;
    int **ppt = NULL;

    pt = &normal;
    ppt = &pt;

    printf("1 var value of normal is %d\n", normal);
    printf("2 var value of normal is %d\n", *pt);
    printf("3 var value of normal is %d\n", **ppt);

    printf("\n1 var adress of normal is %p\n", &normal);
    printf("2 var adress of normal is %p\n", pt);
    printf("3 var adress of normal is %p\n", *ppt);

    printf("\n1 var value of pt is %p\n", pt);
    printf("2 var value of pt is %p\n", *ppt);

    printf("\n1 var adress of pt is %p\n", &pt);
    printf("2 var adress of pt is %p\n", ppt);

    printf("\n1 var value of ppt is %p\n", &pt);
    printf("2 var value of ppt is %p\n", ppt);

    printf("\n1 var adress of ppt is %p\n", &ppt);

    return 0;
}