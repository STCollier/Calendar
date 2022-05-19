#include <stdio.h>
#include <time.h>
#include <string.h>

struct tm tm;

int getYear() {
    return tm.tm_year + 1900;
}

int getMonth() {
    return tm.tm_mon + 1;
}

int getDay() {
    return tm.tm_mday;
}

int getWeekday(int d, int m, int y) {
    return (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7; //Monday = 1
}


int main() {
    char month[256];
    char weekday[256];
    char startMonthDay[256];
    char weekdayOrder[256];
    int daysInMonth;
    time_t t = time(NULL);
    tm = *localtime(&t);
    switch(getMonth()) {
        case 1:
            strcpy(month, "January");
            daysInMonth = 31;
            break;
        case 2:
            strcpy(month, "February");
            if (getYear() % 4 == 0) { //Leap year
                daysInMonth = 29;
            } else {
                daysInMonth = 28;
            }
            break;
        case 3:
            strcpy(month, "March");
            daysInMonth = 31;
            break;
        case 4:
            strcpy(month, "April");
            daysInMonth = 30;
            break;
        case 5:
            strcpy(month, "May");
            daysInMonth = 31;
            break;
        case 6:
            strcpy(month, "June");
            daysInMonth = 30;
            break;
        case 7:
            strcpy(month, "July");
            daysInMonth = 31;
            break;
        case 8:
            strcpy(month, "August");
            daysInMonth = 31;
            break;
        case 9:
            strcpy(month, "September");
            daysInMonth = 31;
            break;
        case 10:
            strcpy(month, "October");
            daysInMonth = 30;
            break;
        case 11:
            strcpy(month, "November");
            daysInMonth = 30;
            break;
        case 12:
            strcpy(month, "December");
            daysInMonth = 31;
            break;
    }

    switch(getWeekday(getDay(), getMonth(), getYear())) {
        case 1:
            strcpy(weekday, "Monday");
            break;
        case 2:
            strcpy(weekday, "Tuesday");
            break;
        case 3:
            strcpy(weekday, "Wednesday");
            break;
        case 4:
            strcpy(weekday, "Thursday");
            break;
        case 5:
            strcpy(weekday, "Friday");
            break;
        case 6:
            strcpy(weekday, "Saturday");
            break;
        case 7:
            strcpy(weekday, "Sunday");
            break;
    }

    int startDay = getWeekday(0, getMonth(), getYear());

    switch(startDay) {
        case 0:
            strcpy(startMonthDay, "Monday");
            strcpy(weekdayOrder, "Mon Tue Wed Thu Fri Sat Sun");
            break;
        case 1:
            strcpy(startMonthDay, "Tuesday");
            strcpy(weekdayOrder, "Tue Wed Thu Fri Sat Sun Mon");
            break;
        case 2:
            strcpy(startMonthDay, "Wednesday");
            strcpy(weekdayOrder, "Wed Thu Fri Sat Sun Mon Tue");
            break;
        case 3:
            strcpy(startMonthDay, "Thursday");
            strcpy(weekdayOrder, "Thu Fri Sat Sun Mon Tue Wed ");
            break;
        case 4:
            strcpy(startMonthDay, "Friday");
            strcpy(weekdayOrder, "Fri Sat Sun Mon Tue Wed Thu ");
            break;
        case 5:
            strcpy(startMonthDay, "Saturday");
            strcpy(weekdayOrder, "Sat Sun Mon Tue Wed Thu Fri ");
            break;
        case 6:
            strcpy(startMonthDay, "Sunday");
            strcpy(weekdayOrder, "Sun Mon Tue Wed Thu Fri Sat ");
            break;
    }

    /*printf("%02d-%02d-%d\n", getMonth(), getDay(), getYear());
    printf("Month: %s\n", &month);
    printf("Day: %s\n", &weekday);
    printf("Days in current month: %d\n", daysInMonth);
    printf("%s starts on a %s\n\n\n", &month, &startMonthDay);*/
    printf("%s", "\n\n-----------------------------\n");
    printf("          \033[0;32m%s\n\n", &month);
    printf("\033[0m");
    printf("%s\n", &weekdayOrder);
    for (int i = 1; i < daysInMonth; i++) {
        if (i == getDay()) {
            printf("\033[0;31m");
            printf(" %d ", getDay()); 
        }
        else if (i <= 7) {
            printf(" %d  ", i);
        } else if (i > 7 && i < 10) {
            printf(" %d  ", i);
        } else {
            printf("\033[0m");
            printf(" %d ", i);
        }
        if (i % 7 == 0) {
            printf("\n");
        }
    }
    printf("%s", "\n-----------------------------\n");
    printf("\n\n");
}
