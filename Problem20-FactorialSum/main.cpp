#include <iostream>
#include <string>
#include <sstream>

#include "BigIntegerLibrary.hh"

#define FACTORIAL 100

using namespace std;

int charToInt(char c);

int main()
{
    BigInteger num=FACTORIAL;
    for (int i=FACTORIAL-1; i>=1; i--)
    {
        num*=i;
    }
    string digits=bigIntegerToString(num);
    int sum=0;
    for (int i=0; i<digits.length(); i++)
    {
        sum+=charToInt(digits[i]);
    }
    cout << sum;
    return 0;
}

int charToInt(char c)
{
    int num;
    stringstream ss;
    ss << c;
    ss >> num;
    return num;
}
