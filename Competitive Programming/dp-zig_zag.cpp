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
const lo N = 51;

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Input
    lo n;
    cin >> n;
    lo arr[n+1];
    for (lo i = 1; i <= n; ++i)
        cin >> arr[i];
    // Solve
    if (n <= 2) {
        cout << 1 << nln;
        return;
    }
    lo res = LLONG_MIN;
    lo dp[n+1], prev[n+1];
    prev[2] = arr[1];
    dp[2] = 2;
    for (lo i = 3; i <= n; ++i) {
        // cout << "i: " << i << nln;
        dp[i] = 2;
        lo loc = -1;
        for (lo j = 2; j < i; ++j)
            if (prev[j] != -1 && (arr[i]-arr[j])*(arr[j]-prev[j]) < 0 && dp[j]+1 > dp[i]) {
                // cout << "j: " << j << nln;
                dp[i] = dp[j]+1;
                loc = j;
            }
        if (loc != -1)
            prev[i] = arr[loc];
        else
            prev[i] = -1;

        // cout << "dpi: " << dp[i] << nln;
        res = max(res, dp[i]);
    }
    cout << res << nln;
}

int main(int argc, char* argv[]) {
    freopen("dp-zig_zag.inp", "r", stdin);
    freopen("dp-zig_zag.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
