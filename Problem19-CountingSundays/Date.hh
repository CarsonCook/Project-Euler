#ifndef Date_hh
#define Date_hh

#include <string>

class Date{
public:
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    void setDayType(int dayType);
    int getYear();
    int getMonth();
    int getDay();
    int getDayType();
    std::string toString();
    void incrementDate(); //increase day by one, nad handle any chnage in month/year
    Date(int day, int month, int year, int dayType); //constructor for given date

private:
    int year;
    int month;
    int day;
    int dayType; //monday=1, tuesday=2...
    int getDaysInCurrentMonth();
    bool isLeapYear();
    std::string numToString(int num);
    std::string dayTypeToString();
};

#endif // Date_hh
