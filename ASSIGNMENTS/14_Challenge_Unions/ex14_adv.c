#include <stdio.h>

union ex14_adv
{
    char leter_grad;
    int rounded_grad;
    float exact_grad;
};

int main(void)
{
    union ex14_adv var1, var2;
    var1.leter_grad = 'A';
    var1.exact_grad = 98.88;
    var1.rounded_grad = 99;

    printf("str is %c\n", var1.leter_grad);
    printf("int is %d\n", var1.rounded_grad);
    printf("int is %.2f\n", var1.exact_grad);

    var2.leter_grad = 'B';
    printf("str is %c\n", var2.leter_grad);
    var2.exact_grad = 78.25;
    printf("int is %.2f\n", var2.exact_grad);
    var2.rounded_grad = 78;
    printf("int is %d\n", var2.rounded_grad);

    return 0;
}
