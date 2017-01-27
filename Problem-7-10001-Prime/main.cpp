#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int num);

int main()
{
    int numbers=1;
    int i=0;
    while (i<10001)
    {
        if (isPrime(numbers))
        {
            i++;
        }
        numbers++;
    }
    cout << numbers-1 << endl;
    return 0;
}

bool isPrime(int num)
{
    if (num<=1)
    {
        return false;
    }
    else if (num==2)
    {
        return true;
    }
    else if (num%2==0)
    {
        return false;
    }
    else if (num==3)
    {
        return true;
    }
    int sqrtNum=sqrt(num);
    for (int i=3; i<=sqrtNum; i+=2)
    {
        if (num%i==0)
        {
            return false;
        }
    }
    return true;
}
