#include <stdio.h>

static char B[] = "I an a global static variabal B being accesed only here";

char C[] = "I am C with access everywhere";

static void innerfunction(void);

// Final 3 step with loop
extern int counter;

void printlocal(int var)
{
    if (var == 2)
        printf("2 task ---- %s\n", B);
    if (var == 3)
        printf("3 task from file2 ---- %s\n", C);
    if (var == 6)
        innerfunction();

    return;
}

void sum(int num)
{
    static float localstorage = 0;
    localstorage += (float)num;
    printf("Task 4-----hey, you call me again, here I go....%f\n", localstorage);
    return;
}

void registerfunc(void)
{
    register int reg = 100;
    reg += 200;
    printf("5 Task ---- I am a register variabal %d work so fast as you could does't imagined\n", reg);
    return;
}

static void innerfunction(void)
{
    printf("I am inner function, you can call me only here\n");
    return;
}

void display(void)
{
    printf("Counter is %d\n", counter);
    return;
}