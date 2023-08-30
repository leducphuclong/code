// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Namespace
using namespace std;  // NOLINT

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo n, k;
    cin >> n >> k;
    cin.ignore();
    string m1;
    getline(cin, m1);
    lo ans = n;
    for (lo i = 1; i < n; ++i) {
        string m;
        getline(cin, m);
        // cout << "m1: " << m1 << nln;
        // cout << "m: " << m << nln;
        if (m != m1)
            --ans;
    }
    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
