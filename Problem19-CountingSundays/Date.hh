#ifndef Date_hh
#define Date_hh

#include <string>

class Date{
public:
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    int getYear();
    int getMonth();
    int getDay();
    std::string toString();
    void incrementDate(); //increase day by one, nad handle any chnage in month/year
    Date(int day, int month, int year); //constructor for given date

private:
    int year;
    int month;
    int day;
    bool isLeapYear();
    int getDaysInCurrentMonth();
    std::string numToString(int num);
};

#endif // Date_hh
