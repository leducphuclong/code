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
lo n, m;   vector<string> mtx;
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

lo cnt_surround(lo x, lo y) {
    lo cnt = 0;
    for (auto dir : dir4) {
        lo u = x+dir.first, v = y+dir.second;
        if (u < 0 || u > n-1 || v < 0 || v > m-1) continue;
        if (mtx[u][v] == '#')
            cnt++;
    }
    return cnt;
}

void solve() {
    cin >> n >> m;
    for (lo i = 0; i < n; ++i) {
        string s;   cin >> s;
        mtx.push_back(s);
    }

    for (lo x = 0; x < n; ++x)
        for (lo y = 0; y < m; ++y) {
            if (mtx[x][y] == '.' && cnt_surround(x, y) > 1) {
                cout << x+1 << ' ' << y+1 << nln;
                return;
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