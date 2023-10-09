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
    lo n, m;    cin >> n >> m;
    lo c[m];    set<lo> s[m];
    for (lo i = 0; i < m; ++i) {
        cin >> c[i];
        for (lo j = 0; j < c[i]; ++j) {
            lo x;   cin >> x;
            s[i].insert(x);
        }
    }
    lo cnt = 0;
    for (lo p = 0; p < (1 << m); ++p) {
        set<lo> clt;
        for (lo i = 0; i < m; ++i) {
            if ((p>>i) & 1) {
                for (auto v : s[i])
                    clt.insert(v);
            }
        }
        if (clt.size() == n)
            cnt++;
    } 

    cout << cnt << nln;
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