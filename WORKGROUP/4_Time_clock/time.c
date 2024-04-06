#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <unistd.h>

int main(void)
{
    time_t calendar = time(NULL);
    struct tm *time_data;
    struct tm *time_data2;
    const char *days[] = {"Sunday",
                          "Monday",
                          "Tuesday",
                          "Wednesday",
                          "Thursday", "Friday", "Saturday"};
    const char *months[] = {"January", "February", "March", "Aprill", "May", "June", "July", "August", "September", "October", "November", "December"};

    time_data = localtime(&calendar);
    printf("Today is%d %s %s %d %d\n", time_data->tm_sec, days[time_data->tm_wday], months[time_data->tm_mon], time_data->tm_mday, time_data->tm_year + 1900);
    sleep(5);
    calendar = time(NULL);
    time_data2 = localtime(&calendar);

    printf("Today is%d %s %s %d %d\n", time_data->tm_sec, days[time_data->tm_wday], months[time_data->tm_mon], time_data->tm_mday, time_data->tm_year + 1900);
    printf("Today is%d %s %s %d %d\n", time_data2->tm_sec, days[time_data2->tm_wday], months[time_data2->tm_mon], time_data2->tm_mday, time_data2->tm_year + 1900);

    return 0;
}