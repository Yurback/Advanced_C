#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;

    fp = fopen("somefile.txt", "r");

    if (fp == NULL)
    {
        printf("Going to abort the programm\n");
        abort();
    }

    printf("Going to close the file\n");
    fclose(fp);

    return 0;
}