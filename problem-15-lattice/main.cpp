#include <iostream>
#include <math.h>

#define SIZE 20 //grid is size x size boxes
#define VERTICES SIZE+1 //number of vertices for one line bewteen boxes

using namespace std;

long long pathsDebug=0;

void debugAnswer();
void initLatticeDebug(bool latticeDebug[VERTICES][VERTICES]);
void findPathsDebug(int x, int y,bool latticeDebug[VERTICES][VERTICES]);

long long findPaths(int x, int y, long long lattice[VERTICES][VERTICES]);
void printLattice(int x, int y, long long lattice[VERTICES][VERTICES]);

int main()
{
    long long lattice[VERTICES][VERTICES]= {0}; //fills with 0s -> flag for not reached position yet, works because each spot WILL ahve at least 1 path to end point
    lattice[VERTICES-1][VERTICES-1]=-2; //flag for end point

    //debugAnswer();

    cout << "ANSWER: " << findPaths(0,0,lattice) << endl;
    //printLattice(0,0,lattice);
    return 0;
}

long long findPaths(int x, int y, long long lattice[VERTICES][VERTICES])
{
    //printLattice(x,y);
    if (x==VERTICES-1 or y==VERTICES-1) //will reach end with just direct x or y propogation
    {
        lattice[x][y]=1;
        return 1;
    }
    else if (lattice[x][y]!=0)
    {
        return lattice[x][y];
    }

    if (x<VERTICES-1)
    {
        lattice[x][y]+=findPaths(x+1,y,lattice);
    }
    if (y<VERTICES-1)
    {
        lattice[x][y]+=findPaths(x,y+1,lattice);
    }
    return lattice[x][y];
}

void printLattice(int x, int y, long long lattice[VERTICES][VERTICES])
{
    cout << "X: " << x << " Y: " << y << endl;
    for (int i=0; i<VERTICES; i++)
    {
        for (int j=0; j<VERTICES; j++)
        {
            if (i==x and j==y)
            {
                cout <<"H:";
            }
            else
            {
                cout << "0:";
            }
            cout << lattice[i][j] << "   ";
        }
        cout << endl;
    }
    cout << endl << endl << endl;
}

void debugAnswer()
{
    bool latticeDebug[VERTICES][VERTICES];
    initLatticeDebug(latticeDebug);
    findPathsDebug(0,0,latticeDebug);
    cout << "DEBUG:  " << pathsDebug << endl;
}

void initLatticeDebug(bool latticeDebug[VERTICES][VERTICES])
{
    for (int i=0; i<VERTICES; i++)
    {
        for (int j=0; j<VERTICES; j++)
        {
            latticeDebug[i][j]=false; //flag for not reached that spot yet -> can never have negative number of paths so this works as flag
        }
    }
    latticeDebug[VERTICES-1][VERTICES-1]=true; //flag for end point
}

void findPathsDebug(int x, int y, bool latticeDebug[VERTICES][VERTICES]) //know this works, but too slwo for 20x20, use to check small cases
{

    if (latticeDebug[x][y] or x==VERTICES-1 or y==VERTICES-1) //if on same x/y axis as the answer, would just call down to the end eventually
    {
        pathsDebug++;
        return;
    }
    if (x<VERTICES-1)
    {
        findPathsDebug(x+1,y,latticeDebug);
    }
    if (y<VERTICES-1)
    {
        findPathsDebug(x,y+1,latticeDebug);
    }
}





