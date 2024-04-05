#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// in terminal comand   -    env | less

int main(void)
{
    char *str;

    assert((str = getenv("HOME")) != NULL);
    printf("Value of \"HOME Enviroment Variable\" : %s\n", str);

    assert((str = getenv("PATH")) != NULL);
    printf("Value of \"PATH Enviroment Variable\" : %s\n", str);

    assert((str = getenv("LOGNAME")) != NULL);
    printf("Value of \"LOGNAME Enviroment Variable\" : %s\n", str);

    assert((str = getenv("SYSTEMD_EXEC_PID")) != NULL);
    printf("Value of \"SYSTEMD_EXEC_PID Enviroment Variable\" : %s\n", str);

    assert((str = getenv("YURBACK")) != NULL);
    printf("Value of \"YURBACK Enviroment Variable\" : %s\n", str);

    return 0;
}