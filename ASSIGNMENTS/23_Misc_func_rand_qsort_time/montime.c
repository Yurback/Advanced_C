#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    const char *months[12] = {"January", "February", "March", "Aprill", "May", "June", "July", "August", "September", "October", "November", "December"};

    time_t now = time(NULL);

    struct tm *start = NULL;

    start = localtime(&now);

    printf("month %s\n", months[start->tm_mon]);

    start->tm_mday = 1;
    start->tm_hour = 0;
    start->tm_min = 0;
    start->tm_sec = 0;

    time_t startsec = mktime(start);

    int passec = (int)(now - startsec);

    printf("It's been a %d seconds since begging of this month %s\n", passec, months[start->tm_mon]);

    return 0;
}