#include <stdio.h>

_Bool isPrime(const int number)
{
    if (number < 0 || number == 0 || number == 1 || (number & 1) == 0)
    {
        return 0;
    }

    for (int i = 3; i * i <= number; i += 2)
    {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

_Bool isEven(const int number)
{
    return !(number & 1);
}

int main(int argc, char **argv)
{
    //**************************** TEST SECTION *****************************************
    int x = 27;
    printf("%d is %s\n", x, isPrime(x) ? "prime" : isEven(x) ? "even"
                                                             : "odd");
    //**************************** END TEST SECTION *************************************

    FILE *pf, *pfw;
    int buf = 0;

    pf = fopen("numbers.txt", "r");
    pfw = fopen("new.txt", "w");

    if (pf == NULL || pfw == NULL)
    {
        printf("ERROR with file open/write");
        return -1;
    }
    while (fscanf(pf, "%d", &buf) == 1)
    {
        fprintf(pfw, "%d is %s\n", buf, isPrime(buf) ? "prime" : isEven(buf) ? "even"
                                                                             : "odd");
    }
    fclose(pf), fclose(pfw);

    return 0;
}