#include <stdio.h>
#include <stdlib.h>
#include <search.h>

#define SIZE_ARR(arr) sizeof(arr) / sizeof(arr[0])

int func_search(const void *arg1, const void *arg2)
{
    return (*(const int *)arg1 == *(const int *)arg2) ? 0 : 1;
}

int func_qsort(const void *p2, const void *p1)
{
    const int x = *(const int *)p2;
    const int y = *(const int *)p1;
    return y - x;
}

int main(int argc, char **argv)
{
    // lfind()
    // void * lfind (const void *key, const void *base, size_t *nmemb, size_t size, comparison_fn_t compar)
    int *el = NULL;
    int arr[20] = {1, 5, 10};
    int key = 15;
    long unsigned int size = SIZE_ARR(arr);
    printf("length of array is %ld\n", size);
    el = (int *)lfind(&key, arr, &size, sizeof(arr[0]), func_search);
    if (el != NULL)
    {
        printf("Search element is %d\n", *el);
        printf("Index of element is %ld\n", (el - arr) % sizeof(arr[0]));
    }
    else
    {
        printf("Element not found\n");
    }

    // lsearch()
    // void * lsearch (const void *key, void *base, size_t *nmemb, size_t size, comparison_fn_t compar)
    int *el2 = NULL;
    int arr2[20] = {2, 11, 7, 2, 5, 11, 11};
    int key2 = 12;
    long unsigned int size2 = 7;
    long unsigned int size3 = SIZE_ARR(arr2);
    printf("length of array is %ld\n", size);
    el2 = lsearch(&key2, arr2, &size2, sizeof(arr2[0]), func_search);
    if (el2 != NULL)
    {
        printf("Search element is %d\n", *el2);
        printf("Index of element is %ld\n", (el2 - arr2));
        printf("Size of element is %ld\n", size2); // size 2 raizing by 1
    }
    else
    {
        printf("Element not found\n");
    }

    for (int i = 0; i < 20; i++)
    {
        printf("%d ", arr2[i]);
    }
    // 1)qsort() and then 2)bsearch(
    // void qsort(void *base,size_t number,size_t width,int (*compare )(const void *, const void *)
    // void * bsearch (const void *key, const void *array, size_t count, size_t size, comparison_fn_t compare)

    qsort(arr2, size3, sizeof(arr2[0]), func_qsort);
    printf("After sorting...\n");
    for (int i = 0; i < 20; i++)
    {
        printf("%d ", arr2[i]);
    };

    int key3 = 11;
    int *el3 = NULL;
    el3 = (int *)bsearch(&key3, arr2, size3, sizeof(arr2[0]), func_qsort);
    if (el3 != NULL)
    {
        printf("\n\nthe value %d find at position %ld\n", *el3, (el3 - arr2));
    }
    else
    {
        printf("\n not found\n");
    }

    //

    return 0;
}