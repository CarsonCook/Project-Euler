#include <iostream>
#include <string>
#include <sstream>
#include "BigIntegerLibrary.hh"

#define POWER 1000

using namespace std;

int charToInt(char c);

int main()
{
    BigInteger num=2;
    for (int i=0; i<POWER-1; i++)
    {
        num*=2;
    }
    string digits=bigIntegerToString(num);
    int sum=0;
    for (int i=0; i<digits.length(); i++)
    {
        sum+=charToInt(digits[i]);
    }
    cout << sum << endl;
}

int charToInt(char c)
{
    stringstream ss;
    ss << c;
    int i;
    ss >> i;
    return i;
}
