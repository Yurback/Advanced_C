#include <stdio.h>

#define SQUARE(i) i *i
#define CUBE(i) i *i *i

int main(void)
{
    float n1 = 0.0;
    printf("Please enter the number 1...\n");
    scanf("%f", &n1);

    printf("THe square of %.2f is %.2f\n", n1, SQUARE(n1));
    printf("THe cube of %.2f is %.2f\n", n1, CUBE(n1));

    return 0;
}