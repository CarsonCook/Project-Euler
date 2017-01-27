#include <iostream>

using namespace std;

int main()
{
    int sum=0;
    int squaredSum=0;
    for (int i=1; i<=100; i++)
    {
        squaredSum+=i*i;
        sum+=i;
    }
    sum*=sum;
    cout << sum-squaredSum << endl;
    return 0;
}
