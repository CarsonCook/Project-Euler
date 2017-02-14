#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<int> vint;
typedef vector< vint > vmatrix;

///prints a vint
ostream &operator<<(ostream &os, vint v)
{
    for (int i=0; i<v.size(); i++)
    {
        os << v[i];
        os << " ";
    }
    os << endl;
    return os;
}

///prints a vmatrix
ostream &operator<<(ostream &os, vmatrix vm)
{
    for (int i=0; i<vm.size(); i++)
    {
        os << vm[i];
    }
    return os;
}

vmatrix getTriangleFromFile();
int stringToInt(string snum);

int main()
{
    vmatrix triangle = getTriangleFromFile();
    for (int row=triangle.size()-1; row>0; row--)
    {
        int upperCol=0;
        for (int i=0; i<triangle[row].size()-1; i++)
        {
            int upperVal=triangle[row-1][upperCol];
            if (upperVal+triangle[row][i]>upperVal+triangle[row][i+1])
            {
                triangle[row-1][upperCol]=upperVal+triangle[row][i];
            }
            else
            {
                triangle[row-1][upperCol]=upperVal+triangle[row][i+1];
            }
            upperCol++;
        }
    }
    ///now have answer at the top of the triangle
    cout << triangle[0][0];
    return 0;
}

vmatrix getTriangleFromFile()
{
    vmatrix triangle;

    ifstream inFile("triangle.txt");
    if (!inFile.is_open())
    {
        cout << "error" << endl;
        return triangle; ///check for null -> flag file failed (or is empty)
    }

    string input="";
    string oneLine="";
    while (getline(inFile,oneLine))
    {
        input+=(oneLine+"\n");
    }
    inFile.close();

    ///go through whole file and parse into a matrix
    for (int i=0; i<input.length(); i++)
    {
        int j=i;
        vint line;
        ///loop through one line
        while (j<input.length() and input[j]!='\n')
        {
            int k=j;
            ///get each integer
            string number="";
            while (k<input.length() and input[k]!=' ' and input[k]!='\n')
            {
                number+=input[k];
                k++;
            }
            line.push_back(stringToInt(number));
            j=k;
            if (input[k]=='\n')
            {
                break;
            }
            j++;
        }
        triangle.push_back(line);
        i=j;
    }

    return triangle;
}

int stringToInt(string snum)
{
    stringstream ss;
    ss << snum;
    int num;
    ss >> num;
    return num;
}











