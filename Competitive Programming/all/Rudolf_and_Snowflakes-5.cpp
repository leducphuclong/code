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
const double eps = 1e-9;

// Declare global variables.
set<lo> sav;
// End of global variable declaration.

void precompute() {
    for (lo k = 2; k < 1e6; ++k) {
        lo t = 1+k+k*k, o = k*k*k;
        sav.insert(t);
        for (lo p = 3; p <= 60; ++p) {
            if (t > 1e18)
                break;
            t += o;
            sav.insert(t);
            if (o > (lo)1e18/k)
                break;
            o *= k;
        }
    }
}

void solve() {
    lo n;
    cin >> n;
    if (sav.count(n)) {
        cout << "YES" << nln;
    } else {
        // Shree Dharacharya formula
        double delta = 1-4*(1-n);
        double x0 = (-1+sqrt(delta))/2;
        lo k = x0;
        if (k > 1 && abs(k-x0) <= eps && k*k+k+1 == n)
            cout << "YES" << nln;
        else
            cout << "NO" << nln;
    }
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
