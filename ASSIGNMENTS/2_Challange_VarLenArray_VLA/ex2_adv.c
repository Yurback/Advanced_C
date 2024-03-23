#include <stdio.h>

int main(void)
{

    int elements = 0;
    printf("Please enter a number elements of the array\n");
    scanf("%d", &elements);
    // getchar();
    int arr[elements];
    // getchar();
    int count = 0;
    while (count < elements)
    {
        printf("Please eneter a %d-th element of this array: ", count + 1);
        scanf("%d", &arr[count]);
        count++;
    }
    int sum = 0;
    for (count = 0; count < elements; count++)
    {
        sum += arr[count];
    }

    printf("THe sum of elements of array is %d\n", sum);

    return 0;
}