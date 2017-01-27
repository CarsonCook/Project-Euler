#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main()
{
    int sum=0;
    for (int i=1; i<1000; i++)
    {
        sum+=i;
        for (int j=i+1; j<1000; j++)
        {
            sum+=j;
            if (sum>=1000)
            {
                sum=0;
                break;
            }
            bool addedPythag=false;
            int pythag=sqrt(i*i+j*j);
            if (pythag*pythag==i*i+j*j) //check that pythag is actually a pythag, not a decimal lopped off by int
            {
                sum+=pythag;
                addedPythag=true;
            }
            if (sum==1000)
            {
                cout << i << " " << j << " " << pythag << endl;
                cout << i*j*pythag << endl;
                return 0;
            }
            if (addedPythag) //if found a triplet that doesn't add to 1000, remove pythag from sum
            {
                sum-=pythag;
            }
            sum-=j; //remove from sum whether or not found a triplet
        }
        sum=0;
    }
    return 0;
}
