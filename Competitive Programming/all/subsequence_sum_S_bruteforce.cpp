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
    lo n, l, r, s;
    cin >> n >> l >> r >> s;
    vector<lo> arr(n);
    vector<lo> pfs = {0};
    for (auto &i : arr) {
        cin >> i;
        pfs.push_back(pfs.back() + i);
    }

    for (lo size = l; size <= r; ++size) {
        for (lo i = size; i <= n; ++i)
            if (pfs[i] - pfs[i-size] == s) {
                cout << "YES" << nln;
                return;
            }
    }
    cout << "NO" << nln;
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
