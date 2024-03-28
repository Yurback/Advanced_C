#include <stdarg.h>
#include <stdio.h>

double addnumbers(int count, ...)
{
    va_list args;
    va_start(args, count);
    double sum = 0.0;

    while (count)
    {
        double num = va_arg(args, double);
        sum += num;
        count--;
    }

    va_end(args);

    return sum;
}

int main(void)
{
    double x = addnumbers(3, 10.0, 20.0, 30.0);
    double y = addnumbers(4, 1.0, 1.0, 1.0, 1.0);
    double z = addnumbers(5, 2.0, 2.0, 2.0, 2.0, 2.0);

    printf("%2.f\n", x);
    printf("%2.f\n", y);
    printf("%.2f\n", z);

    return 0;
}