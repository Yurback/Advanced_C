#include <stdio.h>

_Bool isPrime(const int number)
{
    if (number < 0 || number == 0 || number == 1 || (number & 1) == 0)
    {
        return 0;
    }
    int mid = number / 2;
    for (int i = 3; i <= mid; i += 2)
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
    int x = 31;
    int y = 30;
    int z = 27;
    printf("Start the test section\n");
    printf("%d is %s\n", x, isPrime(x) ? "prime" : isEven(x) ? "even"
                                                             : "odd");
    printf("%d is %s\n", y, isPrime(y) ? "prime" : isEven(y) ? "even"
                                                             : "odd");
    printf("%d is %s\n", z, isPrime(z) ? "prime" : isEven(z) ? "even"
                                                             : "odd");
    printf("End of the test section\n");
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