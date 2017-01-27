#include <iostream>

using namespace std;

bool factorsGood(int num);

int main()
{
    int baseSix[3]={100001,10010,1100};
    for (int i=0; i<=9; i++)
    {
        for (int j=0; j<=9; j++)
        {
            for (int k=0; k<9; k++)
            {
                int num=999999-i*baseSix[0]-j*baseSix[1]-k*baseSix[2];
                if (factorsGood(num))
                {
                    cout << num << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}

bool factorsGood(int num)
{
    for (int i=100; i<=999; i++)
    {
        if (num%i==0 and (num/i>=100 and num/i<=999))
        {
            return true;
        }
    }
    return false;
}
