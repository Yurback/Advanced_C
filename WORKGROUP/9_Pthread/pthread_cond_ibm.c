
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* For safe condition variable usage, must use a boolean predicate and  */
/* a mutex with the condition.                                          */
int workToDo = 0;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

#define NTHREADS 3

void *threadfunc(void *parm)
{
    int rc;

    while (1)
    {
        /* Usually worker threads will loop on these operations */
        rc = pthread_mutex_lock(&mutex);

        if (!workToDo)
        {
            printf("Thread %ld blocked\n", pthread_self());
            rc = pthread_cond_wait(&cond, &mutex);
        }
        printf("Thread %ld awake, finish work!\n", pthread_self());

        /* Under protection of the lock, complete or remove the work     */
        /* from whatever worker queue we have. Here it is simply a flag  */
        workToDo = 0;
        // sleep(20);
        rc = pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char **argv)
{
    int rc = 0;
    int i;
    pthread_t threadid[NTHREADS];

    printf("Enter Testcase - %s\n", argv[0]);

    printf("Create %d threads\n", NTHREADS);
    for (i = 0; i < NTHREADS; ++i)
    {
        rc = pthread_create(&threadid[i], NULL, threadfunc, NULL);
    }

    sleep(2); /* Sleep is not a very robust way to serialize threads   */

    for (i = 0; i < 5; ++i)
    {
        printf("Wake up a worker, work to do...\n");

        rc = pthread_mutex_lock(&mutex);

        /* In the real world, all the threads might be busy, and        */
        /* we would add work to a queue instead of simply using a flag  */
        /* In that case the boolean predicate might be some boolean     */
        /* statement like: if (the-queue-contains-work)                 */
        if (workToDo)
        {
            printf("Work already present, likely threads are busy\n");
        }
        workToDo = 1;
        rc = pthread_cond_signal(&cond);

        rc = pthread_mutex_unlock(&mutex);

        sleep(5); /* Sleep is not a very robust way to serialize threads */
    }

    printf("Main completed\n");
    exit(0);
    return 0;
}

/* OUTPUT
Enter Testcase - ./pthread_cond_ibm
Create 2 threads
Thread blocked
Thread blocked
Wake up a worker, work to do...
Thread awake, finish work!
Thread blocked
Wake up a worker, work to do...
Thread awake, finish work!
Thread blocked
Wake up a worker, work to do...
Thread awake, finish work!
Thread blocked
Wake up a worker, work to do...
Thread awake, finish work!
Thread blocked
Wake up a worker, work to do...
Thread awake, finish work!
Thread blocked
Main completed
*/