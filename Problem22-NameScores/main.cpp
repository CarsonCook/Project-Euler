#include <iostream>
#include <vector>
#include <string>
#include "FileIO.hh"

using namespace std;

typedef vector<string> svec;

svec sortNames(svec names);
svec parseNames(FileInput file);
svec merge(svec namesL, svec namesR);
svec mergesort(svec names);
svec copyVec(int l, int r, svec vec);
int compString(string a, string b);

int main()
{
    FileInput nameFile("names.txt");
    svec names=parseNames(nameFile);
    names=mergesort(names);
    for (int i=0; i<names.size(); i++)
    {
        cout << names[i] << endl;
    }
    return 0;
}

svec parseNames(FileInput file)
{
    string namesString=file.fileToString();
    svec names;
    string oneName="";
    for (int i=0; i<namesString.length(); i++)
    {
        if (namesString[i]==',' || i>=namesString.length())
        {
            names.push_back(oneName);
            oneName="";
        }
        else if (namesString[i]!='"')
        {
            oneName+=namesString[i];
        }
    }
    return names;
}

svec merge(svec namesL, svec namesR)
{
    svec names;
    int lCounter=0;
    int rCounter=0;
    while(lCounter<namesL.size() && rCounter<namesR.size())
    {
        if (compString(namesL[lCounter],namesR[rCounter])>=0)
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





