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
lo n, m;    string nm1 = "snuke", nm2 = "ekuns";
vector<string> mtx;
// End of global variable declaration.

void precompute() {
}

bool ok(string s) {
    return s == nm1 || s == nm2;
}

lo chk(lo x, lo y) {
    // All in row
    string sr = "", sc = "", sd = "";
    for (int i = 0; i < 5; ++i) {
        // Row
        if (y+4 <= m-1)
            sr += mtx[x][y+i];
        // Column
        if (x+4 <= n-1)
            sc += mtx[x+i][y];
        // Diagonal
        if (x+4 <= n-1 && y+4 <= m-1)
            sd += mtx[x+i][y+i];
    }
    if (ok(sr))
        return 1;
    if (ok(sc))
        return 2;
    if (ok(sd))
        return 3;
    return 0;
}

void solve() {
    // Input
    cin >> n >> m;
    mtx.resize(n);
    for (auto &s : mtx)
        cin >> s;
    // Solve
    for (lo i = 0; i < n; ++i)
        for (lo j = 0; j < m; ++j) {
            vector<pair<lo, lo>> lr, lc, ld, ls;
            string sr = "", sc = "", sd = "", ss = "";
            for (int k = 0; k < 5; ++k) {
                // Row
                if (j+4 <= m-1) {
                    sr += mtx[i][j+k];
                    lr.push_back({i, j+k});
                }
                // Column
                if (i+4 <= n-1) {
                    sc += mtx[i+k][j];
                    lc.push_back({i+k, j});
                }
                // Diagonal
                if (i+4 <= n-1 && j+4 <= m-1) {
                    sd += mtx[i+k][j+k];
                    ld.push_back({i+k, j+k});
                }
                // Diagonal 2
                if (i-4 >= 0 && j+4 <= m-1) {
                    ss += mtx[i-k][j+k];
                    ls.push_back({i-k, j+k});
                }
            }
            if (ok(sr)) {
                if (sr == nm2)
                    reverse(lr.begin(), lr.end());
                for (auto v : lr)
                    cout << v.first+1 << ' ' << v.second+1 << nln;
                return;
            }
            if (ok(sc)) {
                if (sc == nm2)
                    reverse(lc.begin(), lc.end());
                for (auto v : lc)
                    cout << v.first+1 << ' ' << v.second+1 << nln;
                return;
            }
            if (ok(sd)) {
                if (sd == nm2)
                    reverse(ld.begin(), ld.end());
                for (auto v : ld)
                    cout << v.first+1 << ' ' << v.second+1 << nln;
                return;
            }
            if (ok(ss)) {
                if (ss == nm2)
                    reverse(ls.begin(), ls.end());
                for (auto v : ls)
                    cout << v.first+1 << ' ' << v.second+1 << nln;
            }
        }
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