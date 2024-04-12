#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main()
{
    printf("Testing SIGSTOP\n");
    raise(SIGSTOP);
    printf("I am back\n\n");
    return 0;
}

// в терминале узнаем PID through command ps
// than run command - kill -s SIGCONT 4176* *-PID