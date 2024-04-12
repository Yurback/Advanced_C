#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game(int sig)
{

    printf("\nFinal score: %d\n", score);
    if (sig == SIGALRM)
        exit(0);
    if (sig == SIGINT)
    {
        alarm(20);
        char choice = '\0';
        printf("Do you want to continue?\n");
        // fgets(&choice, 1, stdin);
        scanf("%c", &choice);
        fflush(stdin);
        if (choice == 'y')
            signal(SIGINT, end_game);
        else
            exit(0);
    }
}

void error(char *msg)
{
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main()
{
    int arr[21] = {0};

    void (*hdl)(int);
    void (*hd2)(int);

    hdl = signal(SIGALRM, end_game);
    hd2 = signal(SIGINT, end_game);

    if (hdl == SIG_ERR || hd2 == SIG_ERR)
    {
        error("error");
    }

    srand(time(0));

    while (1)
    {
        alarm(10);
        int a = rand() % 11;
        int b = rand() % 11;

        char txt[4];

        if (arr[a + b] == 0)
        {
            arr[a + b] = 1;
            printf("\nWhat is %d plus %d: ", a, b);
            fgets(txt, 4, stdin);

            int answer = atoi(txt);

            if (answer == a + b)
                score++;
            else
                printf("\nWrong! %s Score: %d\n", txt, score);
        }

        if (score == 20)
        {
            printf("You win!");
            break;
        }
    }

    return 0;
}