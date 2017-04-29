#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

typedef vector<string> svec;

svec merge(svec namesL, svec namesR);
svec mergesort(svec names);
svec copyVec(int l, int r, svec vec);
int compString(string a, string b);

int main()
{
    svec names;
    ifstream input("names.txt");
    string tempName;
    while (getline(input, tempName, ',')){
        tempName.erase(tempName.begin());
        tempName.pop_back();
        names.push_back(tempName);
    }
    names=mergesort(names);
    unsigned long long sum=0;
    for (int i=0; i<names.size(); i++)
    {
        int wordScore=0;
        for (int j=0; j<names[i].length(); j++)
        {
            wordScore+=((int)names[i][j]-64);//all names are upper case
        }
        sum+=(wordScore*(i+1));
    }
    cout << sum << endl;
    return 0;
}

svec merge(svec namesL, svec namesR)
{
    svec names;
    int lCounter=0;
    int rCounter=0;
    while(lCounter<namesL.size() && rCounter<namesR.size())
    {
        if (namesL[lCounter].compare(namesR[rCounter])<=0)
        {
            names.push_back(namesL[lCounter]);
            lCounter++;
        }
        else
        {
            names.push_back(namesR[rCounter]);
            rCounter++;
        }
    }
    while (lCounter<namesL.size())
    {
        names.push_back(namesL[lCounter]);
        lCounter++;
    }
    while (rCounter<namesR.size())
    {
        names.push_back(namesR[rCounter]);
        rCounter++;
    }
    return names;
}

svec mergesort(svec names)
{
    if (names.size()<=1)
    {
        return names;
    }
    svec left=copyVec(0,names.size()/2,names);
    svec right=copyVec(names.size()/2,names.size(),names);
    left=mergesort(left);
    right=mergesort(right);
    return merge(left,right);
}

svec copyVec(int l,int r,svec vec)
{
    svec newVec;
    for (int i=l; i<r; i++)
    {
        newVec.push_back(vec[i]);
    }
    return newVec;
}

int compString(string a, string b)
{
    for (int i=0; i<a.length(); i++)
    {
        if ((int)a[i]<(int)b[i])
        {
            return 1;
        }
        if ((int)a[i]>(int)b[i])
        {
            return -1;
        }
    }
    if (a.length()<b.length())
    {
        return 1;
    }
    return 0;
}





