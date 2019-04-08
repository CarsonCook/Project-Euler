#include <iostream>
#include <map>
#include <vector>

using namespace std;

int sumDivisors(int n);

int main() {
    vector<int> abunNums;
    for (int i = 1; i <= 28123; ++i) {
        if (sumDivisors(i) > i) {
            abunNums.emplace_back(i);
        }
    }
    bool writtenAsAbun[28123 + 1];
    for (int j = 0; j < abunNums.size(); ++j) {
        for (int k = j; k < abunNums.size(); ++k) {
            int n = abunNums[j] + abunNums[k];
            if (n <= 28123) {
                writtenAsAbun[n] = true;
            } else {
                break;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i < (28123 + 1); ++i) {
        if (!writtenAsAbun[i]) {
            sum += i;
        }
    }
    cout << sum << endl;
    return 0;
}

int sumDivisors(int n) {
    int sum = 0;
    int half = n / 2;
    for (int i = 1; i <= half; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}