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
lo n; vector<lo> val; vector<pair<lo, lo>> edges;
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Input
    cin >> n;
    val.resize(n+1), edges.resize(n+1);
    set<lo> sav;
    vector<lo> val(n+1);
    for (lo i = 1; i <= n; ++i) {
        cin >> val[i];
        sav.insert(val[i]);
    }
    vector<pair<lo, lo>> edges(n-1);
    for (auto &p : edges)
        cin >> p.first >> p.second;
    // SOLVE
    // Special case
    if (val[1] == 1 and sav.size() == 1) {
        cout << 0 << nln;
        return;
    }
}

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
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