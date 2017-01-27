#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num);

int main()
{
    long long num=600851475143;
    for (int i=2; i<=num/2; i++)
    {
        int temp=num/i;
        if (num%temp==0 and isPrime(temp))
        {
            cout << temp << endl;
            break;
        }
    }
    return 0;
}

bool isPrime(int num)
{
    if (num==2)
    {
        return true;
    }
    else if (num==1)
    {
        return false;
    }
    else if (num%2==0)
    {
        return false;
    }
    else
    {
        for (int i=3; i<num; i+=2)
        {
            if (num%i==0)
                return false;
        }
    }
    return true;
}
