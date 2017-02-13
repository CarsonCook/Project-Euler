#include <iostream>
#include <sstream>

using namespace std;

typedef unsigned long long ulll;

string binConversion(unsigned int num);
ulll modExp(int base, string bin);

int main()
{
    cout << modExp(2,binConversion(1000));
}

string binConversion(unsigned int num)
{
    stringstream ss;
    string binReverse;
    int rem;
    do
    {
      rem = num%2;
      num /=2;
      ss << rem;
      char one;
      ss >> one;
      binReverse +=one;
    } while (num>0);
    string out;
    for (int i = binReverse.length(); i>=0; i--)
    {
        out+=binReverse[i];
    }
    return out;
}

ulll modExp(int base, string bin)
{
    int x=1;
    ulll power=base;
    for (int i=0; i<bin.length(); i++)
    {
        if (bin[bin.length()-1-i] == '1')
        {
            x=(x*power);
        }
        power=(power*power);
    }
    return x;
}
