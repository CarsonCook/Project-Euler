#include <iostream>
#include <string>
#include <vector>

#include "Number.h"

using namespace std;


int main() {
    int i = 2;
    Number f1 = 1, f2 = 1;
    do {
        Number t = f1;
        f1 = f2;
        f2 = t + f2;
        ++i;
    } while (f2.digits.size() < 1000);
    cout << i << endl;
    return 0;
}