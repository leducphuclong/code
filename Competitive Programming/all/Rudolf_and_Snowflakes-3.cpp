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

lo sum(lo k, lo p) {
    lo t = 1, o = k;
    for (lo i = 1; i <= p; ++i)
        t += o, o *= k;
    return t;
}

void solve() {
    lo n;
    cin >> n;
    for (lo p = 2; p <= 60; ++p) {
        lo k = powl(n, 1.0/p);
        if (k > 1 && sum(k, p) == n) {
            return;
        }
    }
    cout << "NO" << nln;
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
