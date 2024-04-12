#define _OPEN_THREADS
#include <stdio.h>
#include <pthread.h>
#include <malloc.h>
#include <unistd.h>

int pthread_cancel(pthread_t thread);

void *my_function(void *ptr)
{
    sleep(0.001);

    printf("Hello World\n");
    // pthread_cancel(pthread_self());
    int *ptrnum = (int *)malloc(4);
    *ptrnum = 100;
    return (void *)ptrnum;
}

int main()
{
    void *pn = NULL;
    pthread_t thread = 0L;

    pthread_create(&thread, NULL, my_function, NULL);
    pthread_cancel(thread);
    pthread_join(thread, &pn);
    if (pn == (int *)-1)
    {
        printf("THread was canceled\n");
    }
    else
    {
        printf("The value taken from thread 1 is %d\n", *(int *)pn);
    }

    return 0;
}