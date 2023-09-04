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
    lo n;
    cin >> n;
    vector<lo> a(n), b(n);
    for (auto &v : a)
        cin >> v;
    for (auto &v : b)
        cin >> v;
    lo m;
    cin >> m;
    vector<lo> c(m), d(m);
    for (auto &v : c)
        cin >> v;
    for (auto &v : d) 
        cin >> v;
    // Solve
    map<lo, lo> max_exp;
    set<lo> primes;
    for (lo i = 0; i < n; ++i) {
        max_exp[a[i]] = b[i];
        primes.insert(a[i]);
    }
    map<lo, lo> min_exp;
    for (lo i = 0; i < m; ++i) {
        min_exp[c[i]] = d[i];
        primes.insert(c[i]);
    }
    for (auto v : primes) {
        cout << v << nln;
        cout << "min e: " << min_exp[v] << nln;
        cout << "max e: " << max_exp[v] << nln;
    }
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