#include "Date.hh"
#include <string>
#include <sstream>

Date::Date(int day, int month, int year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

std::string Date::toString()
{
    std::string sDate="";
    sDate+=(numToString(day)+"/");
    sDate+=(numToString(month)+"/");
    sDate+=numToString(year);
    return sDate;
}

void Date::incrementDate()
{
    if (day==getDaysInCurrentMonth()) //new month
    {
        setDay(1);
        if (month==12) //new year
        {
            setMonth(1);
            setYear(year+1);
        }
        else
        {
            setMonth(month+1);
        }
    }
    else
    {
        setDay(day+1);
    }
}

bool Date::isLeapYear()
{
    if (year%4==0)
    {
        if (year%100==0 and year%400!=0)
        {
            return false;
        }
        return true;
    }
    return false;
}

int Date::getDaysInCurrentMonth()
{
    switch(month)
    {
    case 2:
        return (isLeapYear()?29:28);
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
        return 31;
    }
}

std::string Date::numToString(int num)
{
    std::stringstream ss;
    ss << num;
    std::string sNum;
    ss >> sNum;
    return sNum;
}


/**
Setters and getters for class variables
*/

void Date::setDay(int day)
{
    this->day=day;
}

int Date::getDay()
{
    return this->day;
}

void Date::setMonth(int month)
{
    this->month=month;
}

int Date::getMonth()
{
    return this->month;
}

void Date::setYear(int year)
{
    this->year=year;
}

int Date::getYear()
{
    return this->year;
}
