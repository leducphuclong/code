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
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Input
    int n, s;
    cin >> n >> s;
    int arr[n+1][n+1];
    for (lo i = 1; i <= n; ++i)
        for (lo j = 1; j <= n; ++j)
            cin >> arr[i][j];
    // Solve
    int dp[n+1][n+1][s+1];
    memset(dp, 0, sizeof(dp));
    dp[1][1][arr[1][1]] = 1;
    for (lo i = 1; i <= n; ++i)
        for (lo j = 1; j <= n; ++j)
            for (lo k = s; k >= 1; --k)
                if ((i != 1 || j != 1) && k >= arr[i][j])
                    dp[i][j][k] = dp[i][j-1][k-arr[i][j]]
                                + dp[i-1][j][k-arr[i][j]];

    // cout << dp[2][3][] << nln;
    cout << dp[n][n][s] << nln;
}

int main(int argc, char* argv[]) {
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
