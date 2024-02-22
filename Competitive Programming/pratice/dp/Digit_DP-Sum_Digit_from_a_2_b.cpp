#include <iostream>
#include <vector>
#include <climits>
#include <conio.h>
#include <cstring>

using namespace std;

#define nln '\n'

const int N = 1000000 + 2;
const int D = 7;
const int S = 7*9;

// Global Variables Declaration
vector<int> digits;
// End Declaration

void get_digits(int n) {
    digits.clear();
    while (n > 0) {
        digits.push_back(n%10);
        n /= 10;
    }
}

int dp[D][S][2];
int calculate(int idx, int sum, bool tight) {
    if (idx < 0) return sum;

    if (dp[idx][sum][tight] != -1) return dp[idx][sum][tight];

    int limit = tight ? digits[idx] : 9;
    int res = 0;
    for (int v = 0; v <= limit; v++)
        res += calculate(idx-1, sum+v, (v == limit) ? tight : 0);
    return dp[idx][sum][tight] = res;
}

int main() {
    int n = 98765;
    get_digits(n);
    memset(dp, -1, sizeof(dp));
    cout << "Answer: " <<  calculate(digits.size()-1, 0, 1) << nln;
    return 0;
}