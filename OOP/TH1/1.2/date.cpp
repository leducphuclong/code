#include "date.h"

date::date(int day, int month, int year)
: day(day), month(month), year(year) {}

date::~date() {}

bool date::isLeapYear() {
    return (year % 4 == 0 && year % 100!= 0) || year % 400 == 0;
}

int date::current_monthDays() {
    static const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear())
        return 29;
    return days[month - 1];
}

void date::nextDay() {
    day++;

    if (day > current_monthDays()) {
        day = 1;  
        month++;  

        if (month > 12) {
            month = 1;  
            year++;   
        }
    }
}

void date::viewDay() {
    static string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    cout << "Today is: " << getDay() << " " << months[getMonth() - 1] << ", " << getYear() << endl;
}
