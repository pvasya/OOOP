#include "Date.h"
#include <iostream>

Date::Date() {
    srand(time(NULL)); // seed random
    this->year = rand() % 5000;
    this->month = 1 + rand() % 12;
    this->day = 1 + rand() % 30;
    this->hour = rand() % 24;
    this->minute = rand() % 60;
    this->second = rand() % 60;
}

Date::Date(int years, int months, int days, int hours,int minutes, int seconds): year(years), month(months), day(days), hour(hours),minute(minutes), second(seconds) {}

void Date::print(){
    std::cout <<"Date " << year << "." << month << "." << day << "  Time " << hour << ":" << minute << " " << second << std::endl;
}

int Date::getYear(){
    return this->year;
}

void Date::setYear(int year) {
    this->year = year;
}

int Date::getMonth(){
    return month;
}

void Date::setMonth(int month){
    this->month = month;
}

int Date::getDay(){
    return day;
}

void Date::setDay(int day) {
    this->day = day;
}

int Date::getHour(){
    return hour;
}

void Date::setHour(int hour){
    this->hour = hour;
}

int Date::getMinute(){
    return minute;
}

void Date::setMinute(int minute){
    this->minute = minute;
}

int Date::getSecond()
{
    return second;
}

void Date::setSecond(int second){
    this->second = second;
}

int getDaysInMonth(int year, int month) {
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29;
        }
        else {
            return 28;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

bool Date::check() {
    if (month < 1 || month > 12) return false;
    return (day >= 1 && day <= getDaysInMonth(year,month));
}


void Date::add(int year, int month, int day, int hour, int minute, int second) {
    this->second += second;
    this->minute += minute;
    this->hour += hour;
    this->day += day;
    this->month += month;
    this->year += year;

    while (this->second >= 60) {
        this->second -= 60;
        this->minute++;
    }
    while (this->minute >= 60) {
        this->minute -= 60;
        this->hour++;
    }
    while (this->hour >= 24) {
        this->hour -= 24;
        this->day++;
    }

    while (this->month > 12) {
        this->month -= 12;
        this->year++;
    }

    int daysInMonth = getDaysInMonth(this->year, this->month);

    while (this->day > daysInMonth) {
        this->day -= daysInMonth;
        this->month++;
        if (this->month > 12) {
            this->month -= 12;
            this->year++;
        }
        daysInMonth = getDaysInMonth(this->year, this->month);
    }
}

void Date::subtract(int year = 0, int month = 0, int day = 0, int hour = 0, int minute = 0, int second = 0) {
    this->second -= second;
    this->minute -= minute;
    this->hour -= hour;
    this->day -= day;
    this->month -= month;
    this->year -= year;

    while (this->second < 0) {
        this->second += 60;
        this->minute--;
    }
    while (this->minute < 0) {
        this->minute += 60;
        this->hour--;
    }
    while (this->hour < 0) {
        this->hour += 24;
        this->day--;
    }

    while (this->month <= 0) {
        this->month += 12;
        this->year--;
    }

    while (this->day <= 0) {
        this->month--;
        if (this->month <= 0) {
            this->month += 12;
            this->year--;
        }
        this->day += getDaysInMonth(this->year, this->month);
    }
}

int calculateDayWeek(int year, int month,int day) {
    if (month == 1 || month == 2) {
        year--;
        month += 10;
    }
    else month -= 2;
    int result = (day + (31 * month) / 12 + year + year / 4 - year / 100 + year / 400) % 7;
    if (result == 0) return 7;
    return result;
}

int Date::calculateDayOfWeek() { // Zeller's congruence 
    return calculateDayWeek(year,month,day);
}

int Date::weekNumberMonth(){
    int i = 7- calculateDayWeek(year, month, 1) + 1;
    int weekNumberMonth = 1;
    while (i < day) {
        i += 7;
        weekNumberMonth++;
    }
    return weekNumberMonth;
}

int Date::weekNumberYear(){
    int daysY = 0;
    for (int i = 1; i < month; i++) {
        daysY += getDaysInMonth(year, i);
    }
    return (daysY+day-1)/7+1;
}
