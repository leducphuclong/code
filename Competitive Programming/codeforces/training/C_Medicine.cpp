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
    lo n, k;
    cin >> n >> k;
    vector<pair<lo, lo>> mdc;
    for (lo i = 1; i <= n; ++i) {
        lo a, b;    cin >> a >> b;
        mdc.push_back({a, b});
    }

    sort(mdc.begin(), mdc.end());

    vector<pair<lo, lo>> pfs = {{0, 0}};

    for (auto p : mdc)
        pfs.push_back({p.first, pfs.back().second+p.second});

    lo ans = mdc.back().first+1;
    for (lo i = 1; i <= n; ++i) {
        if (pfs.back().second-pfs[i-1].second <= k) {
            ans = pfs[i-1].first+1;
            break;
        }
    }

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