#include <iostream>
#include <fstream>
#include <sstream>

#define myRowSize 100
#define colSize 50

using namespace std;

void stringToIntArr(string str, int row);
int numDigits(int num);

int nums[rowSize][colSize];
int sum[colSize];

int main()
{
    int rowSize=myRowSize;
    if (myRowSize%2!=0)
    {
        rowSize++;
    }
    ifstream file("numbers.txt");
    if (!file.is_open())
    {
        cout << "error opening file" << endl;
        return -1;
    }
    string line;
    int row=0;
    while (getline(file,line))
    {
        stringToIntArr(line,row);
        row++;
    }
    for (int i=0; i<colSize; i++)
    {
        sum[i]=0;
    }
    for (int i=0; i<rowSize-1; i+=2) //get sm without carrying over
    {
        for (int j=colSize-1; j>=0; j--)
        {
            sum[j]+=nums[i][j]+nums[i+1][j];
        }
    }
    //carry over now
    int extra=0; //for carry that goes past last palceholder in sum[]
    for (int i=colSize-1; i>=1; i--)
    {
        sum[i-1]+=sum[i]/10;
        sum[i]%=10;
    }
    sum[0]+=sum[1]/10;
    sum[1]%=10;
    extra+=sum[0]/10;
    sum[0]%=10;
    //print
    if (extra>0)
    {
        cout << extra;
    }
    for (int i=0; i<10-numDigits(extra); i++)
    {
        cout << sum[i];
    }
    return 0;
}

void stringToIntArr(string str, int row)
{
    for (int i=0; i<str.length(); i++)
    {
        stringstream ss;
        ss << str[i];
        ss >> nums[row][i];
    }
}

int numDigits(int num)
{
    int digits=0;
    while (num>0)
    {
        digits++;
        num/=10;
    }
    return digits;
}
