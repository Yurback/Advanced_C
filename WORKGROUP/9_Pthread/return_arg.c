#include <stdio.h>
#include <pthread.h>
#include <string.h>

void *hello_return(void *args)
{
    char *hello = strdup("Hello World!\n");
    return (void *)hello;
}

int main(void)
{
    char *str;
    pthread_t thread;

    pthread_create(&thread, NULL, hello_return, NULL);

    pthread_join(thread, (void **)&str);
    printf("%s", str);
    pthread_exit(NULL);

    return 0;
}