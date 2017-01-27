#include <iostream>

using namespace std;

bool works(int num);

int main()
{
    int num=3*5*7*11*13*17*19;
    while (!works(num))
    {
        num++;
    }
    cout << num << endl;
    return 0;
}

bool works(int num)
{
    for (int i=11; i<=20; i++)
    {
        if (num%i!=0)
        {
            return false;
        }
    }
    return true;
}
