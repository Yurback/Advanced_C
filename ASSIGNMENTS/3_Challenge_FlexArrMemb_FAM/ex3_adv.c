#include <stdio.h>
#include <malloc.h>

struct FAM
{
    int length;
    char arr[][10];
};

int main(void)
{
    struct FAM *ps;

    int arrsize = 0;
    printf("How much elements do you want?\n");
    scanf("%d", &arrsize);

    printf("Size of long 10 elements is %ld\n", sizeof(long[10]));

    ps = malloc(sizeof(struct FAM) + arrsize * sizeof(char[10]));

    ps->length = arrsize;

    printf("Please enter your 1-st word\n");
    scanf("%s", (ps->arr)[0]);

    printf("Please enter your 2-nd word\n");
    scanf("%s", (ps->arr)[1]);

    printf("Please enter your 3-rd word\n");
    scanf("%s", (ps->arr)[2]);

    printf("Please enter your 4-rd word\n");
    scanf("%s", (ps->arr)[4]);

    for (int i = 0; *((ps->arr)[i]) != '\0'; i++)
    {
        printf("The %d-th element is %s\n", i + 1, (ps->arr)[i]);
    }

    for (int i = 0; i < ps->length; i++)
    {
        printf("The %d-th element is %s\n", i + 1, (ps->arr)[i]);
    }

    printf("Total number of elemets is %d\n", ps->length);

    return 0;
}