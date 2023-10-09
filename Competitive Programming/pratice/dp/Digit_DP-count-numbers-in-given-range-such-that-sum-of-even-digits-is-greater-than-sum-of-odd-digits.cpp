#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

#define int long long
#define nln '\n'

const int D = 19, S_ODD = 1e3, S_EVE = 1e3, TIGHT = 2;

// Global Variables
int dp[D][S_ODD][S_EVE][TIGHT];
// End Declaration

vector<int> get_digits(int n) {
    vector<int> dg;
    while (n > 0) {
        dg.push_back(n % 10);
        n /= 10;
    }
    return dg;
}

int recurse(int i, int o, int e, bool tight, const vector<int> &dg) {
    if (i < 0)
        return e > o;

    if (dp[i][o][e][tight] != -1)
        return dp[i][o][e][tight];

    int cnt = 0;
    int lim = (tight) ? dg[i] : 9;
    for (int v = 0; v <= lim; ++v) {
        bool next_tight = (v == lim) ? tight : false;
        if (v & 1)
            cnt += recurse(i-1, o+v, e, next_tight, dg);
        else
            cnt += recurse(i-1, o, e+v, next_tight, dg);
    }

    return dp[i][o][e][tight] = cnt;
}

int calculate(int n) {
    vector<int> dg = get_digits(n);
    memset(dp, -1, sizeof dp);
    return recurse(dg.size()-1, 0, 0, true, dg);
}

void solve() {
    int l, r;       cin >> l >> r;
    cout << calculate(r) - calculate(l-1) << nln;
}

signed main() {
    freopen("in", "r", stdin);
    int tc;     cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}