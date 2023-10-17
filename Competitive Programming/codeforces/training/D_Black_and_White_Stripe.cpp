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
    lo n, k;        cin >> n >> k;
    string s;   cin >> s;
    vector<lo> pfs = {0};
    for (auto c : s)
        if (c == 'W')
            pfs.push_back(1+pfs.back());
        else
            pfs.push_back(pfs.back());
    lo mn = n;
    for (lo i = 0; i < n-k+1; ++i)
        mn = min(mn, pfs[i+k] - pfs[i]);

    cout << mn << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
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