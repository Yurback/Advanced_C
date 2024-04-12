#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    alarm(5);

    for (int i = 1; i < 10; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }

    return 0;
}