#include <iostream>
#include <vector>

#define BOUND 1000000

using namespace std;

long long collatz(long long num);

int main()
{
    long long longest=-1000;
    long long chain;
    for(long long i=1; i<BOUND; i++)
    {
        long long oneLength=collatz(i);
        if (longest<oneLength)
        {
            longest=oneLength;
            chain=i;
        }
    }
    cout << longest << " " << chain;
    return 0;
}

long long collatz(long long num)
{
    int length;
    if (num==1)
    {
        return 1;
    }
    else if (num%2==0)
    {
        length=collatz(num/2);
    }
    else
    {
        length=collatz(3*num+1);
    }
    return length+1;
}
