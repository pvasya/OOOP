#pragma once

class Date {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;

public:
    Date();

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

    void add(int years, int months, int days, int hours, int minutes, int seconds);
    void subtract(int years, int months, int days, int hours, int minutes, int seconds);

    void addSeconds(int seconds);
    void addMinutes(int minutes);
    void addHours(int hours);
    void addDays(int days);
    void addMonths(int months);
    void addYears(int years);

    int calculateDayOfWeek();
};