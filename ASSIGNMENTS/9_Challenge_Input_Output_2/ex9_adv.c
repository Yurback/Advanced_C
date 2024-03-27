#include <wctype.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

void UppertoFILE(FILE *pr)
{
    char ch;
    //    wchar_t wch;
    char str[1000];
    wchar_t buf[1000];
    int count = 0;

    FILE *pw;
    pw = fopen("Home_task_copy", "w");
    //    setlocale(LC_ALL, "ru_RU.UTF-8");
    while ((ch = getc(pr)) != EOF)
    {
        str[count] = ch;
        count++;
    }
    str[count] = '\0';

    setlocale(LC_ALL, "ru_RU.UTF-8");
    mbstowcs(buf, str, 1000);
    for (int i = 0; buf[i] != '\0'; i++)
    {
        buf[i] = towupper(buf[i]);
        putwc(buf[i], pw);
    }
    fclose(pr);
    fclose(pw);
    pr = pw = NULL;
    wprintf(L"my string is %ls", buf);

    return;
}

int main(int argc, char **argv)
{
    if (argv[1])
    {
        FILE *pr;
        char *filename = argv[1];
        pr = fopen(filename, "r");
        if (pr == NULL)
        {
            printf("ERROR");
            return -1;
        }

        UppertoFILE(pr);
    }
    else
    {
        printf("Please enter the text....\n");
        UppertoFILE(stdin);
    }

    remove("Home_task");
    rename("Home_task_copy", "Home_Task");

    //    printf("Буква А - %d, буква а - %d length %d\n", 'А', 'а', (int)'а' - (int)'А');
    // Буква А - 53392, буква а - 53424 length 32
    printf("\n%d\n", 1 ^ (1 << 1));
    int ва = 5;
    printf("my var %d", ва);
    return 0;
}