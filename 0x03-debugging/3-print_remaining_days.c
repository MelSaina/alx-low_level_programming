#include <stdio.h>
#include "main.h"

/**
* print_remaining_days - takes a date and prints how many days are
* left in the year, taking leap years into account
* @month: month in number format
* @day: day of month
* @year: year
* Return: void
*/
void print_remaining_days(int month, int day, int year)
{
    int days_in_feb = 28;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        days_in_feb = 29;
    }

    if (month < 1 || month > 12)
    {
        printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
        return;
    }

    if (day < 1 || day > 31)
    {
        printf("Invalid date: %02d/%02d/%04d\n", month, day, year);
        return;
    }

    switch (month)
    {
        case 2:
            day += 31;
            break;
        case 3:
            day += 31 + days_in_feb;
            break;
        case 4:
            day += 31 + days_in_feb + 31;
            break;
        case 5:
            day += 31 + days_in_feb + 31 + 30;
            break;
        case 6:
            day += 31 + days_in_feb + 31 + 30 + 31;
            break;
        case 7:
            day += 31 + days_in_feb + 31 + 30 + 31 + 30;
            break;
        case 8:
            day += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31;
            break;
        case 9:
            day += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31 + 31;
            break;
        case 10:
            day += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31 + 31 + 30;
            break;
        case 11:
            day += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
            break;
        case 12:
            day += 31 + days_in_feb + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
            break;
    }

    if (month == 2 && day == 60 + days_in_feb)
    {
        printf("Invalid date: %02d/%02d/%04d\n", month, day - 31 - days_in_feb, year);
        return;
    }

    printf("Day of the year: %d\n", day);
    printf("Remaining days: %d\n", 365 + (days_in_feb == 29) - day);
}

