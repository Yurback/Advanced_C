#include <malloc.h>

int numberOfCharactersInString(char *str, char searchCharacter)
{
    int sum = 0;
    while (*str != '\0')
    {
        if (*str == searchCharacter)
            sum++;
        str++;
    }
    return sum;
}

int removeNonAlphaCharacters(char *source)
{
    char *pt = 0x0;
    pt = source;
    while (*source != '\0')
    {
        if ((*source >= 'a' && *source <= 'z') || (*source >= 'A' && *source <= 'Z'))
        {
            *pt = *source;
            pt++;
            source++;
        }
        else
        {
            source++;
        }
    }
    *pt = '\0';
    return 0;
}

int lengthOfString(char *source)
{
    int sum = 0;
    while (*source != '\0')
    {
        sum++;
        source++;
    }
    return sum + 1;
}

int strConcat(char *str1, char *str2, char **x)
{
    int size = lengthOfString(str1) + lengthOfString(str2);
    printf("size is %d\n", size);
    char *str = 0x0; // Дополнительный указатель с ним начинаем работать, основную ссылку *x не трогаем(не смещаем)
    *x = (char *)malloc(size);
    str = *x;
    while (*str1 != '\0')
    {
        *str = *str1;
        str1++;
        str++;
    }
    while (*str2 != '\0')
    {
        *str = *str2;
        str2++;
        str++;
    }
    *str = '\0';
    return 0;
}

int strCopy(char *source, char **destination)
{
    int size = lengthOfString(source);
    *destination = (char *)malloc(size * sizeof(char));
    char *start = *destination;
    while (*source != '\0')
    {
        **destination = *source;
        source++;
        (*destination)++;
    }
    **destination = '\0';
    *destination = start;
    return 0;
}

int substring(char *source, int from, int n, char *target)
{
    source += from;
    while (*source != '\0' && n > 0)
    {
        *target = *source;
        target++;
        source++;
        n--;
    }
    *target = '\0';
    return 0;
}