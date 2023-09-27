#include "date.h"

Date::Date() {
    srand(time(NULL)); // seed random
    this->year = rand() % 5000;
    this->month = 1 + rand() % 12;
    this->day = 1 + rand() % 30;
    this->hour = rand() % 24;
    this->minute = rand() % 60;
    this->second = rand() % 60;
    this->is_grigorian = true;
}

Date::Date(int years, int months, int days, int hours,int minutes, int seconds): year(years), month(months), day(days), hour(hours),minute(minutes), second(seconds),is_grigorian(true) {}

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

bool Date::ifDateInterval(int year1, int month1,int day1,int year2, int month2, int day2){
    if ((year1 > year || year > year2) ||
        ((year == year1 && month < month1) 
            || (year == year2 && month > month2)) || ((year == year1 && month == month1 && day<day1)
                || (year == year2 && month == month2 && day>day2))) return false;
    return true;
}

int Date::calculateDayOfWeek(int year, int month, int day){
    if (month == 1 || month == 2) {
        year--;
        month += 10;
    }
    else month -= 2;
    int result = (day + (31 * month) / 12 + year + year / 4 - year / 100 + year / 400) % 7;
    if (result == 0) return 7;
    return result;
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

    int days_in_month = getDaysInMonth(this->year, this->month);

    while (this->day > days_in_month) {
        this->day -= days_in_month;
        this->month++;
        if (this->month > 12) {
            this->month -= 12;
            this->year++;
        }
        days_in_month = getDaysInMonth(this->year, this->month);
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
    int temp_year = year;
    int temp_month = month;
    if (temp_month == 1 || temp_month == 2) {
        temp_year--;
        temp_month += 10;
    }
    else temp_month -= 2;
    int result = (day + (31 * temp_month) / 12 + temp_year + temp_year / 4 - temp_year / 100 + temp_year / 400) % 7;
    if (result == 0) return 7;
    return result;
}

int Date::weekNumberMonth(){
    return (day-1)/7+1;
}

int Date::weekNumberYear(){
    int days_year = 0;
    for (int i = 1; i < month; i++) {
        days_year += getDaysInMonth(year,i);
    }
    days_year += day-1;
    return days_year/7+1;
}

int Date::weekNumberMonth2(){
    return (day - 2 + calculateDayOfWeek(year,month,1)) / 7 + 1;
}

int Date::weekNumberYear2(){
    int days_year = day;
    for (int i = 1; i < month; i++) {
        days_year += getDaysInMonth(year, i);
    }
    return (days_year - 2 + calculateDayOfWeek(year, 1, 1)) / 7 + 1;
}

void Date::GregorianToJulian() {
    if (is_grigorian == true) {
        if (ifDateInterval(1, 3,1, 100, 2,29)) add(0, 0, 2, 0, 0, 0);
        else if (ifDateInterval(100, 3 , 1, 200, 2,29)) add(0, 0, 1, 0, 0, 0);
        else if (ifDateInterval(300, 3,1, 500, 2,29)) subtract(0, 0, 1, 0, 0, 0);
        else if (ifDateInterval(500, 3,1, 600, 2,29)) subtract(0, 0, 2, 0, 0, 0);
        else if (ifDateInterval(600, 3,1, 700, 2,29)) subtract(0, 0, 3, 0, 0, 0);
        else if (ifDateInterval(700, 3,1, 900, 2,29)) subtract(0, 0, 4, 0, 0, 0);
        else if (ifDateInterval(900, 3,1, 1000, 2,29)) subtract(0, 0, 5, 0, 0, 0);
        else if (ifDateInterval(1000, 3,1, 1100, 2,29)) subtract(0, 0, 6, 0, 0, 0);
        else if (ifDateInterval(1100, 3,1, 1300, 2,29)) subtract(0, 0, 7, 0, 0, 0);
        else if (ifDateInterval(1300, 3,1, 1400, 2,29)) subtract(0, 0, 8, 0, 0, 0);
        else if (ifDateInterval(1400, 3,1, 1500, 2,29)) subtract(0, 0, 9, 0, 0, 0);
        else if (ifDateInterval(1500, 3,1, 1700, 2,29)) subtract(0, 0, 10, 0, 0, 0);
        else if (ifDateInterval(1700, 3,1, 1800, 2,29)) subtract(0, 0, 11, 0, 0, 0);
        else if (ifDateInterval(1800, 3,1, 1900, 2,29)) subtract(0, 0, 12, 0, 0, 0);
        else if (ifDateInterval(1900, 3,1, 2100, 2,29)) subtract(0, 0, 13, 0, 0, 0);
        else if (ifDateInterval(2100, 3,1, 2200, 2,29)) subtract(0, 0, 14, 0, 0, 0);
        is_grigorian = false;
    }
}

void Date::JulianToGregorian() {
    if (is_grigorian == false) {
        if (ifDateInterval(1, 3, 1, 100, 2, 29)) subtract(0, 0, 2, 0, 0, 0);
        else if (ifDateInterval(100, 3, 1, 200, 2, 29)) subtract(0, 0, 1, 0, 0, 0);
        else if (ifDateInterval(300, 3, 1, 500, 2, 29)) add(0, 0, 1, 0, 0, 0);
        else if (ifDateInterval(500, 3, 1, 600, 2, 29)) add(0, 0, 2, 0, 0, 0);
        else if (ifDateInterval(600, 3, 1, 700, 2, 29)) add(0, 0, 3, 0, 0, 0);
        else if (ifDateInterval(700, 3, 1, 900, 2, 29)) add(0, 0, 4, 0, 0, 0);
        else if (ifDateInterval(900, 3, 1, 1000, 2, 29)) add(0, 0, 5, 0, 0, 0);
        else if (ifDateInterval(1000, 3, 1, 1100, 2, 29)) add(0, 0, 6, 0, 0, 0);
        else if (ifDateInterval(1100, 3, 1, 1300, 2, 29)) add(0, 0, 7, 0, 0, 0);
        else if (ifDateInterval(1300, 3, 1, 1400, 2, 29)) add(0, 0, 8, 0, 0, 0);
        else if (ifDateInterval(1400, 3, 1, 1500, 2, 29)) add(0, 0, 9, 0, 0, 0);
        else if (ifDateInterval(1500, 3, 1, 1700, 2, 29)) add(0, 0, 10, 0, 0, 0);
        else if (ifDateInterval(1700, 3, 1, 1800, 2, 29)) add(0, 0, 11, 0, 0, 0);
        else if (ifDateInterval(1800, 3, 1, 1900, 2, 29)) add(0, 0, 12, 0, 0, 0);
        else if (ifDateInterval(1900, 3, 1, 2100, 2, 29)) add(0, 0, 13, 0, 0, 0);
        else if (ifDateInterval(2100, 3, 1, 2200, 2, 29)) add(0, 0, 14, 0, 0, 0);
        is_grigorian = true;
    }
}

void Date::printAlternative(){
    std::string days[7] = { "понеділок", "вівторок", "середа", "четвер", "п'ятниця", "субота", "неділя" };
    std::string numbers[5] = { "перш", "друг", "трет", "четверт", "п'ят" };
    std::string months[12] = { "січня", "лютого", "березня", "квітня", "травня", "червня", "липня", "серпня", "вересня", "жовтня", "листопада", "грудня" };
    int i = 0;
    int day_of_week = calculateDayOfWeek()-1;
    while (day-i*7-7>0) {
        i++;
    }
    if (day_of_week == 0 || day_of_week == 1 || day_of_week == 3) {
        if (i == 2) {
            std::cout<<numbers[i]<<"ій "<<days[day_of_week]<<" "<<months[month-1] << std::endl;
        }
        else std::cout << numbers[i] << "ий " << days[day_of_week] << " " << months[month-1] << std::endl;
    }
    else {
        if (i == 2) {
            std::cout << numbers[i] << "я " << days[day_of_week] << " " << months[month-1] << std::endl;
        }
        else std::cout << numbers[i] << "а " << days[day_of_week] << " " << months[month-1] << std::endl;
    }
}
