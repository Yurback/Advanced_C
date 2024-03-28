#include <stdio.h>
//**************_1_TASK*****************************
int addRecursion(int num)
{
    if (num == 0)
        return 0;

    return num + addRecursion(num - 1);
}

//**************_2_TASK*****************************
int gcd(unsigned num1, unsigned num2)
{
    int tmp;
    while (num2 != 0)
    {
        tmp = num1 % num2;
        num1 = num2;
        num2 = tmp;
    }
    return num1;
}

int gcd_recusive(int num1, int num2)
{
    if (num2 == 0)
        return num1;
    int tmp = num1 % num2;

    return gcd_recusive(num2, tmp);
}

//***************_3_TASK********************************

void flipstring_recursive(char *str)
{
    printf("%c", *str);

    if (*str == '\0')
        printf("\n");

    if (*str != '\0')
    {
        flipstring_recursive(str + 1);
    }

    printf("%c", *str);
    return;
}

//*************** TEST Section *************************

int main(void)
{
    // 1 part
    printf("the sum 1...5 is %d\n", addRecursion(5));

    // 2 part
    int x = 15, y = 20;
    printf("gcd %d and %d is %d", x, y, gcd_recusive(x, y));

    // 3 part
    printf("\n");
    flipstring_recursive("153");
    printf("\n");
    return 0;
}