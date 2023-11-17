#include <iostream>

using namespace std;

class date {
    int day, month, year;
    public:
        explicit date(int day = 1, int month = 1, int year = 1);
        ~date();
        int getDay() { return day; }
        int getMonth() { return month; }
        int getYear() { return year; }
        void setDay(int day) { this->day = day; }
        void setMonth(int month) { this->month = month; }
        void setYear(int year) { this->year = year; }
        bool isLeapYear();
        int current_monthDays();
        void nextDay();
        void viewDay();
};