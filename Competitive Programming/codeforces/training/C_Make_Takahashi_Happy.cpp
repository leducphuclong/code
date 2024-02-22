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
    lo n, m;    cin >> n >> m;
    lo  arr[n][m];
    for (lo i = 0; i < n; ++i)
        for (lo j = 0; j < m; ++j)
            cin >> arr[i][j];
    // Solve
    vector<bool> mvs;
    for (lo i = 0; i < n-1; ++i)
        mvs.push_back(false);
    for (lo j = 0; j < m-1; ++j)
        mvs.push_back(true);
        
    lo cnt = 0;
    do {
        lo x = 0, y = 0;
        map<lo, bool> exs;
        exs[arr[x][y]] = true;
        bool chk = true;
        for (auto v : mvs) {
            if (v == false)
                x++;
            else
                y++;
            if (exs[arr[x][y]])
                chk = false;
            exs[arr[x][y]] = true;
        }
        if (chk)
            cnt++;
    } while (next_permutation(mvs.begin(), mvs.end()));
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