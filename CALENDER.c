#include <stdio.h>
#include <stdlib.h>

int get_1st_WDAY(int year) {
    int d;
    d = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return d;
}

int main() {
    int year, month, day, Daysofmonth, WDAY = 0, startingDay;

    printf("\nEnter your desired year: ");
    scanf("%d", &year);

    char *months[] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    int monthDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        monthDay[1] = 29;

    startingDay = get_1st_WDAY(year);

    for (month = 0; month < 12; month++) {
        Daysofmonth = monthDay[month];

        printf("\n\n-----------------%s-------------------\n", months[month]);
        printf("\n Sun Mon Tue Wed Thurs Fri Sat\n");

        for (WDAY = 0; WDAY < startingDay; WDAY++)
            printf(" ");

        for (day = 1; day <= Daysofmonth; day++) {
            printf("%5d", day);

            if (++WDAY > 6) {
                printf("\n");
                WDAY = 0;
            }

            startingDay = WDAY;
        }
    }

    return 0;
}
