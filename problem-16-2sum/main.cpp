#include <iostream>
#include <sstream>
#include <bitset>
#include <string>

#define POWER 15

using namespace std;

typedef bitset<POWER> mybitset;

mybitset convert(string s);
int charToInt(char letter);

int main()
{
    string bin="1";
    for (int i=0;i<POWER; i++)
    {
        bin+="0";
    }
    cout << bin << endl;
    mybitset num=convert(bin);
    cout << num.to_string() << endl;
    return 0;
}

mybitset convert(string s)
{
    mybitset result;
    for (int loop = 0; s[loop]; ++loop) {
        if (s[loop] == '1') result[loop] = true;
    }
    return result;
}

int charToInt(char letter)
{
    stringstream ss;
    int inum;
    ss << letter;
    ss >> inum;
    return inum;
}
