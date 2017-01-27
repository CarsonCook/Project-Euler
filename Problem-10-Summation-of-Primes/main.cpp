#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int num);

int main()
{
    long long sum=2; //2 is prime
    for (int i=3; i<2000000; i+=2)
    {
        if (isPrime(i))
        {
            sum+=i;
        }
    }
    cout << sum << endl;
    return 0;
}

bool isPrime(int num)
{
    if ((int)sqrt(num)<3)
    {
        for (int i=2; i<num; i++)
        {
            if (num%i==0)
            {
                return false;
            }
        }
    }
    else if (num==3)
    {
        return true;
    }
    else
    {
        for (int i=3; i<=(int)sqrt(num); i+=2)
        {
            if (num%i==0)
            {
                return false;
            }
        }
    }
    return true;
}
