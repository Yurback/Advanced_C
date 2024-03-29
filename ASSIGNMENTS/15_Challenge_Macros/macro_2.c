#include <stdio.h>

#define SUM(a, b) a + b

int main(void)
{
    float n1 = 0.0;
    float n2 = 0.0;
    printf("Please enter the number 1...\n");
    scanf("%f", &n1), fflush(stdin);
    printf("Please enter the number 2...\n");
    scanf("%f", &n2), fflush(stdin);

    printf("THe sum is %.2f\n", SUM(n1, n2));

    return 0;
}