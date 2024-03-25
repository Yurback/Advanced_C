#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void errinformer(void)
{
    printf("Now in errinformer\n");
    longjmp(buf, 1);
    printf("This text never be read");
    return;
}

int main(void)
{
    int number = 10;
    int check = setjmp(buf);
    while (1)
    {
        if (check)
        {
            printf("Hello from main func\n");
            break;
        }
        else
        {
            number = 11;
            errinformer();
        }
    }

    printf("number is %d", number);
    return 0;
}