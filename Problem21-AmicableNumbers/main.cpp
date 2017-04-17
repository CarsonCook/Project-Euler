#include <iostream>
#include <math.h>

#define SIZE 10000

using namespace std;

int sumDivisors(int a);

int main()
{
    int sum=0;
    for (int i=1; i<SIZE; i++)
    {
        int divisors=sumDivisors(i);
        if (divisors>i and sumDivisors(divisors)==i)
        {
            sum+=divisors+i;
        }
    }
    cout << sum << endl;
    return 0;
}

int sumDivisors(int a)
{
    int sum=1; //1 divides everything
    for (int i=2; i<=a/2; i++)
    {
        if (a%i==0)
        {
            sum+=i;
        }
    }
    return sum;
}
