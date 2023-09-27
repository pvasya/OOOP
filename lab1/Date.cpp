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
    this->isGrigorian = true;
    this->zone = 0;
}

Date::Date(int years, int months, int days, int hours,int minutes, int seconds): year(years), month(months), day(days), hour(hours),minute(minutes), second(seconds),isGrigorian(true),zone(0) {}

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

int Date::getDaysInMonth(int year, int month) {
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

bool Date::ifDateInterval(int year1, int month1,int year2, int month2){
    if (year1 > year || year > year2) return false;
    if(month1 > month || month > month2) return false;
    else return true;
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

int Date::calculateDayOfWeek() { // Zeller's congruence 
    if (month == 1 || month == 2) {
        year--;
        month += 10;
    }
    else month -= 2;
    int result = (day + (31 * month) / 12 + year + year / 4 - year / 100 + year / 400) % 7;
    if (result == 0) return 7;
    return result;
}

int Date::weekNumberMonth(){
    return (day-1)/7+1;
}

int Date::weekNumberYear(){
    int daysY = 0;
    for (int i = 1; i < month; i++) {
        daysY += getDaysInMonth(year,i);
    }
    daysY += day-1;
    return daysY/7+1;
}

void Date::GregorianToJulian() {
    if (isGrigorian == true) {
        if (ifDateInterval(1, 3, 100, 2)) subtract(0, 0, 2, 0, 0, 0);
        else if (ifDateInterval(100, 3, 200, 2)) subtract(0, 0, 1, 0, 0, 0);
        else if (ifDateInterval(300, 3, 500, 2)) add(0, 0, 1, 0, 0, 0);
        else if (ifDateInterval(500, 3, 600, 2)) add(0, 0, 2, 0, 0, 0);
        else if (ifDateInterval(600, 3, 700, 2)) add(0, 0, 3, 0, 0, 0);
        else if (ifDateInterval(700, 3, 900, 2)) add(0, 0, 4, 0, 0, 0);
        else if (ifDateInterval(900, 3, 1000, 2)) add(0, 0, 5, 0, 0, 0);
        else if (ifDateInterval(1000, 3, 1100, 2)) add(0, 0, 6, 0, 0, 0);
        else if (ifDateInterval(1100, 3, 1300, 2)) add(0, 0, 7, 0, 0, 0);
        else if (ifDateInterval(1300, 3, 1400, 2)) add(0, 0, 8, 0, 0, 0);
        else if (ifDateInterval(1400, 3, 1500, 2)) add(0, 0, 9, 0, 0, 0);
        else if (ifDateInterval(1500, 3, 1700, 2)) add(0, 0, 10, 0, 0, 0);
        else if (ifDateInterval(1700, 3, 1800, 2)) add(0, 0, 11, 0, 0, 0);
        else if (ifDateInterval(1800, 3, 1900, 2)) add(0, 0, 12, 0, 0, 0);
        else if (ifDateInterval(1900, 3, 2100, 2)) add(0, 0, 13, 0, 0, 0);
        else if (ifDateInterval(2100, 3, 2200, 2)) add(0, 0, 14, 0, 0, 0);
        isGrigorian = false;
    }
}

void Date::JulianToGregorian() {
    if (isGrigorian == false) {
        if (ifDateInterval(1, 3, 100, 2)) add(0, 0, 2, 0, 0, 0);
        else if (ifDateInterval(100, 3, 200, 2)) add(0, 0, 1, 0, 0, 0);
        else if (ifDateInterval(300, 3, 500, 2)) subtract(0, 0, 1, 0, 0, 0);
        else if (ifDateInterval(500, 3, 600, 2)) subtract(0, 0, 2, 0, 0, 0);
        else if (ifDateInterval(600, 3, 700, 2)) subtract(0, 0, 3, 0, 0, 0);
        else if (ifDateInterval(700, 3, 900, 2)) subtract(0, 0, 4, 0, 0, 0);
        else if (ifDateInterval(900, 3, 1000, 2)) subtract(0, 0, 5, 0, 0, 0);
        else if (ifDateInterval(1000, 3, 1100, 2)) subtract(0, 0, 6, 0, 0, 0);
        else if (ifDateInterval(1100, 3, 1300, 2)) subtract(0, 0, 7, 0, 0, 0);
        else if (ifDateInterval(1300, 3, 1400, 2)) subtract(0, 0, 8, 0, 0, 0);
        else if (ifDateInterval(1400, 3, 1500, 2)) subtract(0, 0, 9, 0, 0, 0);
        else if (ifDateInterval(1500, 3, 1700, 2)) subtract(0, 0, 10, 0, 0, 0);
        else if (ifDateInterval(1700, 3, 1800, 2)) subtract(0, 0, 11, 0, 0, 0);
        else if (ifDateInterval(1800, 3, 1900, 2)) subtract(0, 0, 12, 0, 0, 0);
        else if (ifDateInterval(1900, 3, 2100, 2)) subtract(0, 0, 13, 0, 0, 0);
        else if (ifDateInterval(2100, 3, 2200, 2)) subtract(0, 0, 14, 0, 0, 0);
        isGrigorian = true;
    }
}