#include <iostream>
#include <math.h>

using namespace std;

bool enoughDivisors(int num);
int numDivisors(int num);

int main()
{
    int num=1;
    int prev=1;
    while (!enoughDivisors(num))
    {
        prev++;
        num+=prev;
    }
    cout << num << endl;
    return 0;
}

bool enoughDivisors(int num)
{
    return numDivisors(num)>500;
}

int numDivisors(int num)
{
    int counter=0;
    for (int i=1; i<sqrt(num); i++)
    {
        if (num%i==0)
            counter+=2;
    }
    counter++; //for the sqrt of num
    return counter;
}
