#include <iostream>

using namespace std;

int fib(int prev, int prevPrev, int &sum);

int main()
{
    int sum=0;
    fib(0,1,sum);
    cout << sum << endl;
    return 0;
}

int fib(int prev, int prevPrev, int &sum)
{
    int cur=prev+prevPrev;
    if (cur>4000000)
    {
        return 0;
    }
    int temp=fib(cur,prev,sum);
    if (temp%2==0)
    {
        sum+=temp;
    }
    if (prevPrev==0 and prev==1)
    {
        return 0;
    }
    return cur;
}
