#include <stdio.h>

void tocountchar(FILE *pf)
{
    char buf; // Если просто выбрать CHAR то МОБ б
    _Bool isword = 0;
    int countwords = 0;
    int countletters = 0;
    while ((buf = getc(pf)) != EOF)
    {
        if (buf == ' ' && countletters == 0) // Если первый символ пробел то только прибавляем символ и продолжаем
        {
            countletters++;
            continue;
        }
        if (((unsigned char)(buf) >> 7) == 1)
        {

            // eprintf("First bit is %0b", (unsigned char)(buf) >> 7); // конвертируем Буфер чтобы корректно делать проверку с 1
            getc(pf);
            countletters++;
            isword = 1;
            continue;
        }

        countletters++;

        if (buf != ' ')
            isword = 1;

        if ((buf == ' ' || buf == '\n') && isword == 1)
        {
            isword = 0;
            countwords++;
        }
    }

    if (isword == 1)
        countwords++;

    printf("\nFinal score: w - %d; l - %d\n", countwords, countletters);
    return;
}

int main(int argc, char *argv[])
{
    FILE *pf;

    if (argv[1])
    {
        char *pfilename = NULL;
        pfilename = argv[1];
        pf = fopen(pfilename, "r");
        if (pf == NULL)
        {
            printf("ERROR%c", ' ');
            return -1;
        }

        tocountchar(pf);
    }
    else
    {
        pf = stdin;
        printf("Please enter your text...\n");
        tocountchar(pf);
    }

    int v = 8;
    int r = v + 2;
    int vsego = v + r;
    printf("Ответ: %d\n", vsego);

    return 0;
}