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
const lo N = 1e2+5, W = 1e5+2;

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
lo n, w;    
lo wei[N], val[N], dp[N][W];
// End of global variable declaration.

void precompute() {
}

void dping(lo idx, lo weight) {
    if (idx <= 0 || weight <= 0) {
        dp[idx][weight] = 0;
        return;
    }

    if (dp[idx][weight] != -1)
        return;
    
    dping(idx-1, weight);
    dp[idx][weight] = dp[idx-1][weight];
    if (weight >= wei[idx]) {
        dping(idx-1, weight - wei[idx]);
        dp[idx][weight] = max(dp[idx][weight], dp[idx-1][weight-wei[idx]] + val[idx]);
    }
}

void solve() {
    cin >> n >> w;
    for (lo i = 1; i <= n; ++i)
        cin >> wei[i] >> val[i];

    memset(dp, -1, sizeof dp);

    dping(n, w);
    
    cout << dp[n][w] << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
    //freopen("out.txt", "w", stdout);
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