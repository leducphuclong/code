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
    bool mtx[n][n];
    for (lo i = 0; i < n; ++i)
        for (lo j = 0; j < n; ++j)
            cin >> mtx[i][j];
    // Solve
    lo cnt = 0;
    for (lo i = 0; i < n; ++i)
        for (lo j = 0; j < n; ++j)
            if (mtx[i][j] != mtx[n-1-i][n-1-j])
                ++cnt;
    cnt /= 2;
    
    if (k < cnt) {
        cout << "NO" << nln;
    } else {
        lo o = k-cnt;
        if (n & 1) {
            cout << "YES" << nln;
        } else {
            if (o & 1)
                cout << "NO" << nln;
            else    
                cout << "YES" << nln;
        }
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