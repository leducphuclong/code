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
vector<bool> ift;
lo n, d;
vector<pair<lo, lo>> coo;
// End of global variable declaration.

void precompute() {
}

lo sqr(lo x) {
    return (x*x);
}

lo distance(pair<lo, lo> p1, pair<lo, lo> p2) {
    return sqr(p1.first-p2.first) + sqr(p1.second-p2.second); 
}

void dfs(lo p) {
    ift[p] = true;
    for (lo a = 0; a < n; ++a)
        if (!ift[a] && distance(coo[p], coo[a]) <= d)
            dfs(a);
}

void solve() {
    // Input
    cin >> n >> d;       d *= d;
    coo.resize(n);
    for (auto &p : coo)
        cin >> p.first >> p.second;
    // SOLVE
    ift.resize(n, false);
    dfs(0);
    // Output
    for (lo i = 0; i < n; ++i)
        if (ift[i])
            cout << "Yes" << nln;
        else
            cout << "No" << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
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