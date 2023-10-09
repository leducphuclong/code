#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define nln '\n'

const int D = 19, R = 1e3, T = 2;

// Global Variables
int n, k, dp[D][R][R];
vector<int> digits;
// End declaration

void get_digits() {
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
}

int cal(int idx, int rem, int tight) {
    if (idx < 0)
        return rem == 0;


    if (dp[idx][rem][tight] != -1)
        return dp[idx][rem][tight];

    int way = 0;
    int lim = (tight) ? digits[idx] : 9;
    for (int d = 0; d <= lim; ++d) {
        int next_rem = (rem+d) % k;
        int next_tight = (d == lim) ? tight : false;
        way += cal(idx-1, next_rem, next_tight);
    }

    return dp[idx][rem][tight] = way;
}

int main() {
    cin >> n >> k;
    get_digits();
    memset(dp, -1, sizeof dp);
    cout << cal(digits.size()-1, 0, true);
    return 0;
}