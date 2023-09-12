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
    map<lo, lo> afraid;
    lo n;
    cin >> n;
    vector<lo> a(n+1);
    for (lo i = 1; i <= n; ++i) {
        cin >> a[i];
        afraid[i] = a[i];
    }
    vector<lo> c(n+1);
    for (lo i = 1; i <= n; ++i)
        cin >> c[i];
    // Solve
    // Sell all the animals that not afraid any other animal.
    for (lo i = 1; i <= n; ++i)
        if (afraid[i] == 0)
            cout << i << ' ';
           
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