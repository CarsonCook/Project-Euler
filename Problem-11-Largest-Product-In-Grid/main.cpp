#include <iostream>
#include<fstream>
#include <sstream>

using namespace std;

int matrix[20][20];

bool makeMatrix();
void printMatrix();
void printRow(int row);
int stringToInt(string str);
int biggestProduct(int row, int col);
int left(int row,int col);
int leftUp(int row,int col);
int leftDown(int row,int col);
int right(int row,int col);
int rightUp(int row,int col);
int rightDown(int row,int col);
int up(int row,int col);
int down(int row,int col);

int main()
{
    if (!makeMatrix())
    {
        return -1;
    }
    int bigProd=-1000;
    for (int i=0; i<20; i++)
    {
        for (int j=0; j<20; j++)
        {
            int num=biggestProduct(i,j);
            if (num>bigProd)
            {
                bigProd=num;
            }
        }
    }
    cout << bigProd << endl;
    return 0;
}

bool makeMatrix()
{
    ifstream file ("numbers.txt");
    if (!file.is_open())
    {
        cout << "ERROR" << endl;
        return false;
    }
    string line;
    int lineNum=0;
    while (getline(file,line))
    {
        string oneNum;
        int num;
        int numCounter=0;
        for (int i=0; i<line.length(); i++)
        {
            while(line[i]!=' ' && i<line.length())
            {
                oneNum+=line[i];
                i++;
            }
            num=stringToInt(oneNum);
            oneNum="";
            matrix[lineNum][numCounter]=num;
            numCounter++;
        }
        lineNum++;
    }
    file.close();
    return true;
}

void printMatrix()
{
    for (int i=0; i<20; i++)
    {
        printRow(i);
    }
}

void printRow(int row)
{
    for(int i=0; i<20; i++)
    {
        cout << matrix[row][i] << " ";
    }
    cout << endl;
}

int stringToInt(string str)
{
    stringstream ss;
    ss << str;
    int num;
    ss >> num;
    return num;
}

int biggestProduct(int row, int col)
{
    int prod=-1000;
    if (col>=3)
    {
        int num=left(row,col);
        if (prod<num)
        {
            prod=num;
        }
        if (row>=3)
        {
            int num=leftUp(row,col);
            if (prod<num)
            {
                prod=num;
            }
        }
        if (row<18)
        {
            int num=leftDown(row,col);
            if (prod<num)
            {
                prod=num;
            }
        }
    }
    if (col<18)
    {
        int num=right(row,col);
        if (prod<num)
        {
            prod=num;
        }
        if (row>=3)
        {
            int num=rightUp(row,col);
            if (prod<num)
            {
                prod=num;
            }
        }
        if (row<18)
        {
            int num=rightDown(row,col);
            if (prod<num)
            {
                prod=num;
            }
        }
    }
    if (row>=3)
    {
        int num=up(row,col);
        if (prod<num)
        {
            prod=num;
        }
    }
    if (row<18)
    {
        int num=down(row,col);
        if (prod<num)
        {
            prod=num;
        }
    }
}

int left(int row, int col)
{
    int prod=1;
    for (int i=0; i<4; i++)
    {
        prod*=matrix[row][col-i];
    }
    return prod;
}

int leftUp(int row, int col)
{
    int prod=1;
    for (int i=0; i<4; i++)
    {
        prod*=matrix[row-1][col-i];
    }
    return prod;
}

int leftDown(int row, int col)
{
    int prod=1;
    for (int i=0; i<4; i++)
    {
        prod*=matrix[row+1][col-i];
    }
    return prod;
}

int right(int row, int col)
{
    int prod=1;
    for (int i=0; i<4; i++)
    {
        prod*=matrix[row][col+i];
    }
    return prod;
}

int rightUp(int row, int col)
{
    int prod=1;
    for (int i=0; i<4; i++)
    {
        prod*=matrix[row-i][col+i];
    }
    return prod;
}

int rightDown(int row, int col)
{
    int prod=1;
    for (int i=0; i<4; i++)
    {
        prod*=matrix[row+i][col+1];
    }
    return prod;
}

int up(int row, int col)
{
    int prod=1;
    for (int i=0; i<4; i++)
    {
        prod*=matrix[row-i][col];
    }
    return prod;
}

int down(int row, int col)
{
    int prod=1;
    for (int i=0; i<4; i++)
    {
        prod*=matrix[row+i][col];
    }
    return prod;
}
