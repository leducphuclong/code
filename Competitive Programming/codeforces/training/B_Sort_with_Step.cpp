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
    lo n, k;    cin >> n >> k;
    vector<pair<lo, lo>> wp;
    for (lo i = 1; i <= n; ++i) {
        lo x; cin >> x;
        if (abs(i-x) % k != 0)
            wp.push_back({x, i});
    }

    if (wp.size() == 0) {
        cout << 0 << nln;
    } else if (wp.size() == 2) {
        lo u = wp[0].first, pu = wp[0].second;
        lo v = wp[1].first, pv = wp[1].second;
        swap(pu, pv);
        if (abs(u-pu) % k == 0 && abs(v-pv) % k == 0)
            cout << 1 << nln;
        else
            cout << -1 << nln;
    } else {
        cout << -1 << nln;
    }
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