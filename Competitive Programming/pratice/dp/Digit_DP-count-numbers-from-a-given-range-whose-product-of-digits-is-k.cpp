#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
// #include <conio.h>

using namespace std;

#define nln '\n'

// Global Variables
int l, r, k, dp[19][9*19+1][2][2];
vector<int> digits;
// End Declaration

// First, Solve the problem count number whose product of digits = k 
// from 1 -> n

void get_digits(int &n) {
    memset(dp, -1, sizeof dp);
    digits.clear();
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
}

int calculate(int idx, int product, bool tight, bool leading_zero) {
    if (idx < 0)
        return product == k;

    if (dp[idx][product][tight][leading_zero] != -1)
        return dp[idx][product][tight][leading_zero];

    int way = 0, limit = (tight) ? digits[idx] : 9;
    for (int d = 0; d <= limit; ++d) {
        bool next_tight = (d == limit) ? tight : 0;
        int next_product = product*d;
        int next_idx = idx-1;
        bool next_leading_zero = leading_zero && d == 0;
        way += calculate(next_idx, (next_leading_zero) ? product :next_product, next_tight, next_leading_zero);
    }

    return dp[idx][product][tight][leading_zero] = way;
}

int main() {
    // freopen("in", "r", stdin);
    cin >> l >> r >> k;
    l--;    get_digits(l);
    int prefix = calculate(digits.size()-1, 1, 1, 1);
    get_digits(r);
    int sum = calculate(digits.size()-1, 1, 1, 1);
    cout << sum - prefix;
    return 0;
}