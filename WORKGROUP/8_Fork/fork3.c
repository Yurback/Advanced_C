#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <wait.h>

#define MAX_COUNT 10

void childProcess(void);
void parentProcess(void);

int main(void)
{
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        childProcess();
    }
    else if (pid > 0)
    {

        waitpid(pid, NULL, 0);
        parentProcess();
    }
    else
    {
        printf("fork() failed!\n");
        return 1;
    }
}

void childProcess(void)
{
    int i;

    for (i = 1; i <= MAX_COUNT; i++)
        printf("    This line is from child, value = %d\n", i);

    printf("     *** Child process is done ***\n");
}

void parentProcess(void)
{
    int i;

    for (i = 1; i <= MAX_COUNT; i++)
        printf("    This line is from parent, value = %d\n", i);

    printf("     *** Parent process is done ***\n");
}