#include <pthread.h>
#include <stdio.h>

#define NTHREAD 10

int counter = 0;

void *do_work(void *message)
{
    printf("message is %d, thread id = %ld modified the counter to %d\n", *(int *)message, pthread_self(), ++counter);
    printf("message is %d, thread id = %ld read the counter %d\n", *(int *)message, pthread_self(), counter);
    return NULL;
}

int main(void)
{
    pthread_t threads[NTHREAD];

    for (int i = 0; i < NTHREAD; i++)
    {
        pthread_create(&(threads[i]), NULL, do_work, (void *)&i);
    }

    for (int i = 0; i < NTHREAD; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}