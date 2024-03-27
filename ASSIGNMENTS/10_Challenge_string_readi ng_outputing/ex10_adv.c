#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <stdlib.h>
// for function mbstowcsJ()

int main(int argc, char **argv)
{
    char buf[256];
    // char *ptrbuf = buf;
    char *namefile;
    int l;
    FILE *pf;

    if (argc < 3)
    {
        printf("Require 4 arguments: name_prog, char, name_file, [wc]\n");
        return -1;
    }

    namefile = argv[2];
    l = *argv[1];
    pf = fopen(namefile, "r");
    if (pf == NULL)
    {
        printf("Error, can not open file\n");
        return -1;
    }

    while (fgets(buf, sizeof(buf), pf))
    {
        if (argv[3] && strcmp(argv[3], "wc") == 0) // Руско-английская проверка
        {
            setlocale(LC_ALL, "ru_RU.UTF-8");
            wchar_t wbuf[256];
            wchar_t wl;
            mbstowcs(wbuf, buf, 256);
            mbstowcs(&wl, argv[1], 4);

            if (wcschr(wbuf, wl))
            {
                int i = 0;
                while (wbuf[i] != L'\n' && wbuf[i] != L'\0')
                {
                    putwc(wbuf[i], stdout);
                    i++;
                }
                putwc(L'\n', stdout);
            }
        }
        else // English char 1 byte
        {
            if (strchr(buf, l))
            {
                int i = 0;
                while (buf[i] != '\n' && buf[i] != '\0')
                {
                    putc(buf[i], stdout);
                    i++;
                }
                putc('\n', stdout);
            }
        }
    }
    fclose(pf);
    pf = NULL;

    return 0;
}
