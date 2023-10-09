// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo n;   cin >>n;
    vector<vector<lo>> drr(n, vector<lo>(n, 0));
    for (lo i = 0; i < n-1; ++i) {
        for (lo j = i+1; j < n; ++j)
            cin >> drr[i][j];
    }

    vector<lo> dp((1<<n), 0);
    for (lo i = 0; i < (1 << n); ++i) {
        lo j;
        for (j = 0; j < n; ++j)
            if (((i>>j) & 1) == 0)
                break;
        if (j == n) continue;
        for (lo k = j; k < n; ++k) {
                if (((i>>k) & 1) == 0) {
                    lo next_status = i | (1<<j) | (1<<k);
                    dp[next_status] = max(dp[next_status], dp[i]+drr[j][k]);
                }
            }
    }
    cout << dp.back();
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}