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
    // Input
    lo n, k;    cin >> n >> k;
    vector<lo> arr(n);
    for (auto &v : arr) cin >> v;
    // Solve
    set<lo> s;
    for (auto v : arr)
        s.insert(v);
    
    lo i = 0, mex = -1, last;
    for (auto v : s) {
        if (v != i) {
            mex = i;
            break;
        }
        if (i == k-1) {
            mex = k;
            break;
        }
        ++i;
        last = v;
    }
    if (mex == -1)
        mex = last+1;
    cout << mex << nln;
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