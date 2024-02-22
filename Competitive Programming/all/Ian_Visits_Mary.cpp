// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
#include <numeric>
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
    lo a, b;
    cin >> a >> b;
    if (gcd(a, b) == 1) {
        cout << 1 << nln << a << ' ' << b << nln;
    } else {
        cout << 2 << nln;
        cout << 1 << ' ' << b-1 << nln;
        cout << a << ' ' << b << nln; nln;
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
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
