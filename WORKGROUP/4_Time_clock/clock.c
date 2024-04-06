#include <stdio.h>
#include <time.h>
#include <math.h>
// #include <ctype.h>

int main()
{
    time_t calendar_start = time(NULL);
    clock_t cpu_start = clock();
    int count = 0;

    int iterations = 2000000000;
    char answer = 'y';
    double x = 0.0;

    printf("Initia clock time = %lld Initial calendar time = %lld\n", (long long)cpu_start, (long long)calendar_start);
    // while (tolower(answer) == 'y')
    // {
    for (int i = -2000000000; i < iterations; ++i)
    {
        x = sqrt(20);
        // if (i == 1999999999)
        //     puts("I am done");
    }
    printf("%d square roots completed.\n", iterations * (++count));
    printf("Do you want to run some more(y or n)?\n");
    //     scanf("\n%c", &answer);
    // }

    clock_t cpu_end = clock();
    time_t calendar_end = time(NULL);

    printf("Final clock time = %lld Final calendar tim = %lld\n", (long long)cpu_end, (long long)calendar_end);
    printf("CPU time for %d iterations is %.2f seconds\n", count * iterations, ((double)(cpu_end - cpu_start) / CLOCKS_PER_SEC));
    printf("Elapsed calendar time to execute the programm is %8.2lf seconds.\n", difftime(calendar_end, calendar_start));

    return 0;
}