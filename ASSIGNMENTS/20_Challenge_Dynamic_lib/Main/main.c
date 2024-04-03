#include <stdio.h>
#include <malloc.h>
#include "StringFunctions.h"

int main(void)
{
    char a[] = "Hello world Yura Hello world Hello world";
    char b[] = "World";
    char *pt = NULL;
    int from = 12; // start index
    int n = 3;     // length substring

    printf("Number of char is %d\n", numberOfCharactersInString(a, 'o')); // Test 1 pass V

    // removeNonAlphaCharacters(a);
    // printf("String with remove char is %s\n", a); // Test 2 pass V

    // printf("Length of the string a is %d\n", lengthOfString(a)); // Test 3 pass V

    // strConcat(a, b, &pt);
    // printf("Concatinating string of a and b is %s\n", removeNonAlphaCharacters(pt) ? "NULL" : pt); // Test 4 pass V

    // strCopy(b, &pt);
    // printf("Copy string: %s\n", pt);
    // printf("adress of pt is %p\n", pt);
    // printf("adress of b is %p\n", b);
    // printf("Size of byte hello: %ld\n", malloc_usable_size(pt));
    // free(pt);

    // strCopy(a, &pt);
    // printf("Copy string: %s\n", pt);
    // printf("adress of pt is %p\n", pt);
    // printf("adress of b is %p\n", a);
    // printf("Size of byte hello: %ld\n", malloc_usable_size(pt));
    // printf("Size of byte hello: %ld\n", sizeof(a));
    // free(pt); // Test 5 pass V

    // pt = malloc(n + 1);
    // substring(a, from, n, pt);
    // printf("Tht substring is %s\n", pt); // Test 6 pass V

    return 0;
}