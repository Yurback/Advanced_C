#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

void fillarray(double ar[], int size);

void dispayarr(const double ar[], int n);

int sortfunc(const void *p2, const void *p1);

int main(void)
{
    // creat array
    double arr[SIZE];
    fillarray(arr, SIZE);
    // display array
    printf("Original array: \n");
    dispayarr(arr, SIZE);
    // sort array
    qsort(arr, SIZE, sizeof(double), &sortfunc);
    // display sort array
    printf("\nSorted array: \n");
    dispayarr(arr, SIZE);

    return 0;
}

void fillarray(double ar[], int size)
{
    time_t seed = time(NULL);
    srand(seed);
    for (int i = 0; i < size; i++)
    {
        ar[i] = (double)(rand() % 200000) / 10000;
    }
    return;
}

void dispayarr(const double ar[], int n)
{
    printf("[\n");
    for (int i = 0; i < n; i++)
    {
        if (i % 10 == 0 && i != 0)
        {
            putc('\n', stdout);
        }
        printf(" %f", ar[i]);
    }
    printf("\n]\n");
}

int sortfunc(const void *p2, const void *p1)
{
    return *(const double *)p2 > *(const double *)p1;
}