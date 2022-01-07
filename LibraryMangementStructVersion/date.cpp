#define _CRT_SECURE_NO_WARNINGS
#include "date.h"
#include <ctime>

// Check leap year
bool isLeapYear(int year) {
    if (year % 4 == 0 && year % 100 != 0) {
        return true;
    }
    return false;
}

// Find the next day
void next_day(Date &date) {
    switch (date.month) {
        case 12:
            if (date.day == 31) {
                date.day = 1;
                date.month = 1;
                date.year++;
            } else {
                date.day++;
            }
            break;

        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
            if (date.day == 31) {
                date.day = 1;
                date.month++;
            } else {
                date.day++;
            }
            break;

        case 2:
            if (isLeapYear(date.year)) {
                if (date.day == 29) {
                    date.day = 1;
                    date.month++;
                } else {
                    date.day++;
                }
            } else {
                if (date.day == 28) {
                    date.day = 1;
                    date.month++;
                } else {
                    date.day++;
                }
            }
            break;

        default:
            if (date.day == 30) {
                date.day = 1;
                date.month++;
            } else {
                date.day++;
            }
    }
}

int rdn(Date date) {
    if (date.month < 3)
        date.year--, date.month += 12;

    return 365 * date.year + (date.year / 4) - (date.year / 100) 
           + (date.year / 400) + (153 * date.month - 457) / 5 + date.day - 306;
}

int distance(Date d1, Date d2) {
    int dd1 = rdn(d1);
    int dd2 = rdn(d2);

    return (dd1 <= dd2) ? 0 : (dd1 - dd2);
}

Date get_today() {
    Date new_date;
    time_t now = time(0);

    tm* ltm = localtime(&now);

    new_date.year = 1900 + ltm->tm_year;
    new_date.month = 1 + ltm->tm_mon;
    new_date.day = ltm->tm_mday;

    return new_date;
}