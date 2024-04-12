#include <stdio.h>
#include <pthread.h>

void *calls(void *ptr)
{
    printf("In function \nthread id = %ld\n", pthread_self());
    pthread_exit(NULL);
    return NULL;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, calls, NULL);
    printf("In main \nthread id = %ld\n", thread);
    pthread_join(thread, NULL);
    puts("In main again");
    return 0;
}