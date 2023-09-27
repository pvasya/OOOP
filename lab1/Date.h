#pragma once

class Date {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    bool isGrigorian;
    int zone;

    int getDaysInMonth(int year, int month);
    bool ifDateInterval(int year1, int month1, int year2, int month2);

public:
    Date();
    Date(int years, int months, int days, int hours,int minutes, int seconds);

    void print();

    int getYear();
    void setYear(int year);
    int getMonth();
    void setMonth(int month);
    int getDay();
    void setDay(int day);
    int getHour();
    void setHour(int hour);
    int getMinute();
    void setMinute(int minute);
    int getSecond();
    void setSecond(int second);

    bool check();

    void add(int year, int month, int day, int hour, int minute, int second);
    void subtract(int year, int month, int day, int hour, int minute, int second);

    int calculateDayOfWeek();

    int weekNumberMonth();
    int weekNumberYear();
    void GregorianToJulian();
    void JulianToGregorian();
};