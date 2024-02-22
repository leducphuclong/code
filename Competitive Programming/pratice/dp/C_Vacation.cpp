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
    lo n;   cin >> n;
    lo arr[n+1][4];
    for (lo i = 1; i <= n; ++i)
        for (lo j = 1; j <= 3; ++j)
            cin >> arr[i][j];
    
    lo dp[n+1][4];
    dp[1][1] = arr[1][1], dp[1][2] = arr[1][2], dp[1][3] = arr[1][3];
    for (lo i = 2; i <= n; ++i) {
        dp[i][1] = max(dp[i-1][2], dp[i-1][3]) + arr[i][1];
        dp[i][2] = max(dp[i-1][1], dp[i-1][3]) + arr[i][2];
        dp[i][3] = max(dp[i-1][1], dp[i-1][2]) + arr[i][3];
    }

    cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
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