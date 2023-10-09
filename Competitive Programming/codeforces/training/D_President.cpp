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
    // Input
    lo n;   cin >>n;
    vector<lo> c(n), v(n);
    for (lo i = 0; i < n; i++) {
        lo x, y;    cin >> x >> y;
        c[i] =  x < y ? ceil((y-x)/2.0) : 0;
        cin >> v[i];
    }

    lo t = 0;
    for (auto val : v)
        t += val;

    vector<lo> dp(t+1, LLONG_MAX);
    dp[0] = 0;
    for (lo j = 0; j < n; ++j)
        for (lo i = t; i >= v[j]; --i)
            if (dp[i-v[j]] != LLONG_MAX)
                dp[i] = min(dp[i], dp[i-v[j]]+c[j]);

    lo ans = LLONG_MAX;
    for (lo i = ceil(t/2.0); i <= t; ++i)
        ans = min(ans, dp[i]);
    
    cout << ans << nln;
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