#include <stdio.h>
#include <stdlib.h>

// int atoi (char const *s);
// long int atof(char const *s);
// lonf atol(char const *s);
// double strtod(const char *str, char **str_end);
// long int strtol(char const *s,char **end, int base);

int main(void)
{
    char a[] = "      00111.898   200dream";
    int value = atoi(a);
    float value2 = atof(a);
    long value3 = atol(a);
    double value4 = 0;
    double value5 = 0;
    long value6 = 0;

    char *end = NULL;
    char *ptr = NULL;

    printf("Value = %d\n", value);
    printf("Value = %f\n", value2);
    printf("Value = %ld\n", value3);

    value4 = strtod(a, &end);
    printf("Value4 = %lf\n", value4);
    value5 = strtod(end, NULL);
    printf("Value5 = %lf\n", value5);

    value6 = strtol(a, &ptr, 10);
    printf("THe number (unsigned long integer) is %ld\n", value6);
    printf("String part is |%s\n", ptr);

    return 0;
}