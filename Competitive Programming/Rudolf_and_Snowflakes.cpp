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
long double eps = 0.00000000217265;

// Declare global variables.
map<lo, lo> ans;
// End of global variable declaration.

long double my_log(long double a, long double b) {
    return log(b)/log(a);
}

void precompute() {
}

void solve() {
    lo n;
    cin >> n;
    for (lo k = 2; k <= round(sqrt(n)); ++k) {
        long double p = my_log(k, n*(k-1)+1)-1;
        if (abs(p-round(p)) <= eps && p > 1) {
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
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
