#include <iostream>
#include "Date.hh"

using namespace std;

int main()
{
    Date d(1,1,1900);
    cout << "START: "+d.toString() << endl;
    for (int i=0; i<60; i++)
    {
        d.incrementDate();
        cout << d.toString() << endl;
    }
    return 0;
}
