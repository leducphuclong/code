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
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo n, k, g; cin >> n >> k >> g;
    lo p = floor((g-1)/2.0);
    // cout << "p: " << p << nln;
    if (g*k <= n*p) {
        cout << g*k << nln;
    } else {
        lo l = (g*k-n*p);
        lo r = (g*k-n*p)%g;
        lo s = n*p;
        s -= p;
        lo add = (p+r)%g;
        if (add <= p)
            s += add;
        else
            s -= (g-add);
        cout << s << nln;            
    }
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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