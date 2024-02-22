#include <iostream>
#include <cstring>
#include <vector>
#include <bitset>

using namespace std;

#define nln '\n'

const int BITSET = 32, TIGHT = 2, K_ONE = 2;

// Global Variables
int l, r, k, dp[BITSET][BITSET][K_ONE][TIGHT];
string b_l, b_r;
// End Declaration

int calculate(const string &b, int idx, int cnt_1, bool k_1, bool tight) {
    if (idx == BITSET)
        return k_1;
    if (dp[idx][cnt_1][k_1][tight] != -1)
        return dp[idx][cnt_1][k_1][tight];

    char lim = (tight) ? b[idx] : '1';
    int cnt = 0;
    for (char d = '0'; d <= lim; d++) {
        int next_cnt_1 = (d == '0') ? 0 : (cnt_1+1);
        bool next_k_1 = (next_cnt_1 >= k) ? true : k_1;
        bool next_tight = (d == lim) ? tight : false;
        cnt += calculate(b, idx+1, next_cnt_1, next_k_1, next_tight);
    }

    return dp[idx][cnt_1][k_1][tight] = cnt;
}

void solve() {
    cin >> l >> r >> k;

    l--;    b_l = bitset<32>(l).to_string();
    memset(dp, -1, sizeof dp);
    int prefix = calculate(b_l, 0, 0, false, true);

    b_r = bitset<32>(r).to_string();
    memset(dp, -1, sizeof dp);
    int sum_up = calculate(b_r, 0, 0, false, true);

    cout << sum_up - prefix << nln;
}

int main() {
    freopen("in", "r", stdin);
    int tc; cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}