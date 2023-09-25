#include "Date.h"
#include <iostream>

Date::Date() {
    this->year = rand() % 5000;
    this->month = 1 + rand() % 12;
    this->day = 1 + rand() % 30;
    this->hour = rand() % 24;
    this->second = rand() % 59;
}


int Date::getYear(){
    return this->year;
}

void Date::setYear(int year) {
    year = year;
}

int Date::getMonth(){
    return 0;
}

void Date::setMonth(int month){
}

int Date::getDay(){
    return 0;
}

void Date::setDay(int day) {
}

int Date::getHour(){
    return 0;
}

void Date::setHour(int hour){
}

int Date::getMinute(){
    return 0;
}

void Date::setMinute(int minute)
{
}

int Date::getSecond()
{
    return 0;
}

void Date::setSecond(int second){
}

bool Date::check() {
    return true;
}

void Date::add(int years, int months, int days, int hours, int minutes, int seconds) {
    
}

void Date::subtract(int years, int months, int days, int hours, int minutes, int seconds) {
    
}

void Date::addSeconds(int seconds) {
    
}

void Date::addMinutes(int minutes)
{
}

void Date::addHours(int hours)
{
}

void Date::addDays(int days)
{
}

void Date::addMonths(int months)
{
}

void Date::addYears(int years)
{
}

int Date::calculateDayOfWeek() {
    return 0;
}