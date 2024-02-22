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
    lo n;       cin >> n;
    lo arr[n+1];
    for (lo i = 1; i <= n; ++i)
        cin >> arr[i];
    
    lo dp[n+1];
    dp[1] = 0;
    dp[2] = abs(arr[1]-arr[2]);

    for (lo i = 3; i <= n; ++i)
        dp[i] = min(dp[i-1]+abs(arr[i]-arr[i-1]), dp[i-2] + abs(arr[i-2]-arr[i]));

    cout << dp[n] << endl;
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