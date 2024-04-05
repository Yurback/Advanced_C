#include <stdlib.h>
#include <string.h>

int main(void)
{
    char command[50];

    system("ls -l");

    strcpy(command, "./stdlib_exit");
    system(command);

    printf("Before exit from main-programm\n");

    return 0;
}