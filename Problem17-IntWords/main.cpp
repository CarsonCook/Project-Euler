#include <iostream>

using namespace std;

string turnToWords(int num);
string getOnesWord(int num);
string getTensWord(int num);
string getHundredsWord(int num);
string getTeensWord(int num);

int main()
{
    string allNums="";
    for (int i=1; i<=1000; i++)
    {
        allNums+=turnToWords(i);
    }
    cout << allNums.length()<< endl;
    return 0;
}

string turnToWords(int num)
{
    if (num>=10 and num<20)
    {
        return getTeensWord(num);
    }
    if (num==1000)
    {
        return "onethousand";
    }
    string word="";
    int hundreds = num/100;
    if (hundreds!=0)
    {
        word+=getHundredsWord(hundreds);
    }
    int tens=num/10%10;
    int ones = num%100%10;
    if (hundreds!=0 and (tens!=0 or ones!=0)) ///special case for 100, 200 etc. no and after 100
    {
        word+="and";
    }
    if (tens==1) ///special case for teens
    {
        word+=getTeensWord(tens*10+num%10); ///get the last two digits (e.g. get eleven part of 211)
    }
    else
    {
        if (tens!=0)
        {
            word+=getTensWord(tens);
        }
        if (ones!=0)
        {
            word+=getOnesWord(ones);
        }
    }
    return word;
}

string getOnesWord(int num)
{
    switch(num)
    {
    case 1:
        return "one";
    case 2:
        return "two";
    case 3:
        return "three";
    case 4:
        return "four";
    case 5:
        return "five";
    case 6:
        return "six";
    case 7:
        return "seven";
    case 8:
        return "eight";
    case 9:
        return "nine";
    }
}

string getTensWord(int num)
{
    switch(num)
    {
    case 2:
        return "twenty";
    case 3:
        return "thirty";
    case 4:
        return "forty";
    case 5:
        return "fifty";
    case 6:
        return "sixty";
    case 7:
        return "seventy";
    case 8:
        return "eighty";
    case 9:
        return "ninety";
    }
}

string getHundredsWord(int num)
{
    switch(num)
    {
    case 1:
        return getOnesWord(num)+"hundred";
    case 2:
        return getOnesWord(num)+"hundred";
    case 3:
        return getOnesWord(num)+"hundred";
    case 4:
        return getOnesWord(num)+"hundred";
    case 5:
        return getOnesWord(num)+"hundred";
    case 6:
        return getOnesWord(num)+"hundred";
    case 7:
        return getOnesWord(num)+"hundred";
    case 8:
        return getOnesWord(num)+"hundred";
    case 9:
        return getOnesWord(num)+"hundred";
    }
}

string getTeensWord(int num)
{
    switch(num)
    {
    case 10:
        return "ten";
    case 11:
        return "eleven";
    case 12:
        return "twelve";
    case 13:
        return "thirteen";
    case 14:
        return "fourteen";
    case 15:
        return "fifteen";
    case 16:
        return "sixteen";
    case 17:
        return "seventeen";
    case 18:
        return "eighteen";
    case 19:
        return "nineteen";
    }
}
