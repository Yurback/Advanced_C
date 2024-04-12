#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int thstatus;

void *thread(void *arg)
{
    while (1)
    {
        puts("thread has started. now sleeping");
        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    pthread_t thid;
    void *status;

    if (pthread_create(&thid, NULL, thread, NULL) != 0)
    {
        perror("pthread_create failed");
        exit(2);
    }

    if (pthread_cancel(thid) == -1)
    {
        perror("pthread_cancel failed");
        exit(3);
    }

    if (pthread_join(thid, &status) == -1)
    {
        perror("pthread_join failed");
        exit(4);
    }

    if (status == (int *)-1)
        puts("thread was cancelled");
    else
        puts("thread was not cancelled");

    exit(0);
    return 0;
}