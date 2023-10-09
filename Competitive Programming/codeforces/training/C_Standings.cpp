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
const double eps = 1e-18;

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo n;  cin >> n;
    vector<pair<lo, lo>> prb = {{0, 0}};
    for (lo i = 1; i <= n; i++) {
        lo a, b;    cin >> a >> b;
        prb.push_back({a, (a+b)});
    }

    vector<lo> idx(n);
    iota(idx.begin(), idx.end(), 1);
    auto cmp = [&] (lo l, lo r) {
        auto [l_f, l_s] = prb[l];
        auto [r_f, r_s] = prb[r];
        return l_f*r_s > r_f*l_s;
    };

    stable_sort(idx.begin(), idx.end(), cmp);
    
    for (lo i = 0; i < n; ++i)
        cout << idx[i] << " \n"[i == n-1];
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