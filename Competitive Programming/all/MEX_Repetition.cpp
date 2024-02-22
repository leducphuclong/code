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
    lo n, k;
    cin >> n >> k;
    lo a[n+1];  // NOLINT
    map<lo, bool> mark;
    for (lo i = 1; i <= n; ++i) {
        cin >> a[i];
        mark[a[i]] = 1;
    }
    for (lo i = 0; i <= n; ++i)
        if (!mark[i]) {
            a[0] = i;
            break;
        }

    lo b[n+1];  // NOLINT
    for (lo i = 0; i <= n; ++i) {
        // cout << (i+(k%(n+1)))%(n+1) << " := " << i << nln;
        b[(i+(k%(n+1)))%(n+1)] = a[i];
    }

    for (lo i = 1; i <= n; ++i)
        cout << b[i] << ' ';
    cout << nln;
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
