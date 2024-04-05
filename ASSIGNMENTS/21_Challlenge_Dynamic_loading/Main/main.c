#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <dlfcn.h>

int main(void)
{
    int (*numchar)(char *, char) = NULL;
    int (*rmNONalph)(char *) = NULL;
    int (*lntstr)(char *) = NULL;
    int (*constr)(char *, char *, char **) = NULL;
    int (*cpystr)(char *, char **) = NULL;
    int (*substr)(char *, int, int, char *) = NULL;

    void *handle = dlopen("/home/yurback/C_projects/Advanced_C/ASSIGNMENTS/21_Challlenge_Dynamic_loading/D_lib/lib_stringfunctions.so", RTLD_LAZY);
    if (!handle)
    {
        fputs(dlerror(), stderr);
        exit(1);
    }

    dlerror();
    numchar = dlsym(handle, "numberOfCharactersInString");
    rmNONalph = dlsym(handle, "removeNonAlphaCharacters");
    lntstr = dlsym(handle, "lengthOfString");
    constr = dlsym(handle, "strConcat");
    cpystr = dlsym(handle, "strCopy");
    substr = dlsym(handle, "substring");

    if (dlerror() != NULL)
    {
        fputs(dlerror(), stderr);
        exit(1);
    }

    char a[] = "Hello world Yura Hello world Hello world";
    char b[] = "World";
    char *pt = NULL;
    int from = 12; // start index
    int n = 3;     // length substring

    printf("Number of char is %d\n", (*numchar)(a, 'o')); // Test 1 pass V

    rmNONalph(a);
    printf("String with remove char is %s\n", a); // Test 2 pass V

    printf("Length of the string a is %d\n", lntstr(a)); // Test 3 pass V

    constr(a, b, &pt);
    printf("Concatinating string of a and b is %s\n", rmNONalph(pt) ? "NULL" : pt); // Test 4 pass V

    cpystr(b, &pt);
    printf("Copy string: %s\n", pt);
    printf("adress of pt is %p\n", pt);
    printf("adress of b is %p\n", b);
    printf("Size of byte hello: %ld\n", malloc_usable_size(pt));
    free(pt);

    cpystr(a, &pt);
    printf("Copy string: %s\n", pt);
    printf("adress of pt is %p\n", pt);
    printf("adress of b is %p\n", a);
    printf("Size of byte hello: %ld\n", malloc_usable_size(pt));
    printf("Size of byte hello: %ld\n", sizeof(a));
    free(pt); // Test 5 pass V

    pt = malloc(n + 1);
    substr(a, from, n, pt);
    printf("Tht substring is %s\n", pt); // Test 6 pass V

    dlclose(handle);
    return 0;
}