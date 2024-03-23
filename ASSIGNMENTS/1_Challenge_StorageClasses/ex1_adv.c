#include <stdio.h>

void printlocal(int var);

void sum(int num);

void registerfunc(void);

extern char C[];

// extern char B[]; // Проверка Таск 2 не компилируются если в файле 2 переменная static

// void innerfunction(void);  // Don`t work because innerfunc is static and located in file2

// Final 3 step with loop
int counter = 5;
void display(void);

int main(void)
{
    char a[] = "I am a scope variable A";

    printf("1 ---- task is ---- %s\n", a);

    printlocal(2);

    // printf("Error cant get access to B %s\n", B); // Проверка Таск 2 не компилируются если в файле 2 переменная static

    printf("3 from main - C %s\n", C);

    printlocal(3);

    sum(35);
    sum(35);
    sum(30);

    registerfunc();
    registerfunc();

    // innerfunction();// Don`t work because innerfunc is static and located in file2

    printlocal(6);

    // Final 3 step with loop
    for (; counter > 0; counter--)
    {
        display();
    }

    return 0;
}