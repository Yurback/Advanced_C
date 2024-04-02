#include <malloc.h>

int numberOfCharactersInString(char *str, char searchCharacter)
{
    int sum = 0;
    while (*str != '\0')
    {
        if (*str == searchCharacter)
            sum++;
        *str++;
    }
    return sum;
}

int removeNonAlphaCharacters(char *source)
{
    int *pt = 0x0;
    pt = source;
    while (*source != '\0')
    {
        if (*source >= 'a' && *source <= 'z' || *source >= 'A' && *source <= 'Z')
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
    }
    return sum + 1;
}

int strConcat(char *str1, char *str2, char **str)
{
    int size = lengthOfString(str1) + lengthOfString(str2);
    *str = (char)malloc(size);
    while (*str1 != '\0')
    {
        **str = *str1;
        str1++;
        str++;
    }
    while (*str2 != '\0')
    {
        **str = *str2;
        str2++;
        str++;
    }
    **str = '\0';
    return 0;
}