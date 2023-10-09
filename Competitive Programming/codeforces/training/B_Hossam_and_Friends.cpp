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
    lo n, q;    cin >> n >> q;
    vector<lo> mn(n+1, n);
    while (q--) {
        lo x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        mn[x] = min(mn[x], y-1);
    }

    for (lo i = n-1; i >= 1; --i)
        mn[i] = min(mn[i], mn[i+1]);

    lo ans = 0;
    for (lo i = 1; i <= n; ++i)
        ans += mn[i]-i+1;
        // cout << i << " " << mn[i] << endl;
    
    cout << ans << nln;

}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
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