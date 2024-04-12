// #define _POSIX_C_SOURCE 200809L
#define _XOPEN_SOURCE 700 // for troubleshoot undefine siginfo_t

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//
// #define si_pid _sifields._kill.si_pid
// #define si_uid _sifields._kill.si_uid

static void hdl1(int sig, siginfo_t *siginfo, void *context)
{
    // in Linux siginfo has limited implementation

    printf("Sending PID: %d, UID: %d\n", getpid(), getuid());
    alarm(15);
}

int main(int argc, char *argv[])
{
    alarm(3);
    struct sigaction act;

    memset(&act, '\0', sizeof(act));

    act.sa_sigaction = &hdl1;
    act.sa_flags = SA_SIGINFO;

    if (sigaction(SIGALRM, &act, NULL) < 0)
    {
        perror("sigaction");
        return 1;
    }

    while (1)
    {
        sleep(10);
        printf("hello there\n");
    }

    return 0;
}