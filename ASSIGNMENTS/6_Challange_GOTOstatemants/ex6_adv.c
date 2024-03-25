#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

int main(int argc, char *argv[])
{
    int width = atoi(argv[1]);
    int indent = width - 2, cur = 1, mid = 2;
fstline:
    if (cur < width)
    {
        cur++;
        printf(" ");
        goto fstline;
    }
    printf("*\n");
    cur = 1;
centr:
    if (indent == 0)
        goto lsstr;
line:
    if (cur >= indent + 1 + mid)
    {
        mid += 2;
        indent -= 1;
        cur = 1;
        printf("*\n");
        goto centr;
    }
    if (cur == indent + 1)
    {
        cur++;
        printf("*");
        goto line;
    }
    if (cur <= indent)
    {
        cur++;
        printf(" ");
        goto line;
    }
    if (cur > indent + 1)
    {
        cur++;
        printf(" ");
        goto line;
    }

lsstr: // x*2 -1
    if (cur <= width * 2 - 1)
    {
        cur++;
        printf("*");
        goto lsstr;
    }
    printf("\n");

    printf("size wchar_t %ld", sizeof(char));

    printf("yuriy"),
        printf("reshetov");

    int counthouse = (100, 400);

    printf("\n%d", counthouse);

    return 0;
}