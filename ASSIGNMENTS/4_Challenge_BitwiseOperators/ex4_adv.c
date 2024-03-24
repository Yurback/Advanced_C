#include <stdio.h>

int main(void)
{
    unsigned int value = 0;
    unsigned int bit = 0;
    printf("Enter the number\n");
    scanf("%d", &value);
    printf("Enter the number of bit to check and then flip it\n");
    scanf("%d", &bit);
    printf("the %d-th bit is %d\n", bit, (value >> bit) & 1);
    value |= 1 << bit;
    printf("After conversing the %d-th bit is %d\n", bit, (value >> bit) & 1);
    printf("The final value is %d\n", value);

    return 0;
}