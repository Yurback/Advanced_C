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
    char *pt = NULL;
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
    char *str = NULL; // Дополнительный указатель с ним начинаем работать, основную ссылку *x не трогаем(не смещаем)
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

int main(void)
{
    char a[] = "Hello";
    char b[] = "World123123123                   123123        Yura";
    char *ppt = NULL;

    // printf("Number of char is %d\n", numberOfCharactersInString(a, 'e')); // Test 1 pass V

    // removeNonAlphaCharacters(a);
    // printf("String with remove char is %s\n", a); // Test 2 pass V

    // printf("Length of the string a is %d\n", lengthOfString(a)); // Test 3 pass V

    // strConcat(a, b, &ppt);
    // printf("Concatinating string of a and b is %s\n", removeNonAlphaCharacters(ppt) ? "NULL" : ppt); // Test 4 pass V
    return 0;
}