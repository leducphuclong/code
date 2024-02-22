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

struct  obj {
    lo weight, value;
};

// Constant

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Input
    lo n, w;
    cin >> n >> w;
    vector<obj> arr(n);
    lo all = 0;
    for (auto &v : arr) {
        cin >> v.weight >> v.value;
        all += v.value;
    }
    // Solve
    lo dp[all+1];
    memset(dp, 60, sizeof(dp));
    dp[0] = 0;
    for (lo i = 0; i < n; ++i) {
        for (lo v = all; v >= 1; --v)
            if (arr[i].value <= v) {
                // cout << "dp0: " << dp[v] << nln;
                dp[v] = min(dp[v], dp[v-arr[i].value] + arr[i].weight);
                // cout << "i: " << i << nln;
                // cout << "v: " << v << nln;
                // cout << "dp[v]: " << dp[v] << nln;
                // getch();
            }
    }

    // for (lo i = 1; i <= all; ++i)
    //     cout << i << " ~ " << dp[i] << nln;

    while (dp[all--] > w)
        continue;

    cout << all+1 << nln;        
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
