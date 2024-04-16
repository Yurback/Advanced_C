#include <pthread.h>
#include <stdio.h>

#define NTHREAD 10

pthread_mutex_t simophor = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t con_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t con_check = PTHREAD_COND_INITIALIZER;

int counter = 0;

void *do_work(void *message)
{
    pthread_mutex_lock(&simophor);
    if (*(int *)message % 2 != 0)
        pthread_cond_wait(&con_check, &simophor);

    printf("message is %d, thread id = %ld modified the counter to %d\n", *(int *)message, pthread_self(), ++counter);
    printf("message is %d, thread id = %ld read the counter %d\n", *(int *)message, pthread_self(), counter);

    if (counter == 5)
        pthread_cond_broadcast(&con_check);

    pthread_mutex_unlock(&simophor);
    return NULL;
}

int main(void)
{
    pthread_t threads[NTHREAD];
    int arr[10] = {0};

    for (int i = 0; i < NTHREAD; i++)
        arr[i] = i + 1;

    for (int i = 0; i < NTHREAD; i++)
    {
        pthread_create(&(threads[i]), NULL, do_work, (void *)&arr[i]);
    }

    for (int i = 0; i < NTHREAD; i++)
    {
        pthread_join(threads[i], NULL);
    }

    return 0;
}