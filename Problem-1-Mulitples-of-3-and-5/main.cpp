#include <iostream>

using namespace std;

int sum(int num);

int total=0;

int main()
{
    int temp=sum(3);
    cout << total << endl;
    return 0;
}

int sum(int num)
{
    if (num>=10)
    {
        do
        {
            num--;
        }
        while (num%3!=0 and num%5!=0);
        return num;
    }
        do
        {
            num++;
        }
        while (num%3!=0 and num%5!=0);
        num=sum(num);
        total+=num;
        do
        {
            num--;
        }
        while (num%3!=0 and num%5!=0);
        return num;
}
