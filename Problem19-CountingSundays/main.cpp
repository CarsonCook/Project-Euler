#include <iostream>
#include "Date.hh"

using namespace std;

int main()
{
    Date d(1,1,1900,1); //day number, month, year, day type (monday)
    int sundaySum=0;
    while (d.getYear()!=2001) //go until the first day of 2001
    {
        if (d.getYear()>1900 and d.getDayType()==7 and d.getDay()==1)//7 is Sunday
        {
            sundaySum++;
        }
        d.incrementDate();
    }
    cout << sundaySum <<endl;
    return 0;
}
