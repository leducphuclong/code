// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
#include <conio.h>

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
    lo n;       cin >> n;
    vector<string> mtx(n+1);

    for (lo i = 1; i <= n; ++i) {
        cin >> mtx[i];
        mtx[i] = ' ' + mtx[i];
    }

    lo ans = 0;
    for (int i = 1; i <= n/2; ++i) {
        for (int j = i; j <= n-i; ++j) {
            lo x = i, y = j;
            char p1 = mtx[x][y], 
            p2 = mtx[y][n-x+1],
            p3 = mtx[n-x+1][n-y+1], 
            p4 = mtx[n-y+1][x];

            char pm = max(max(p1, p2), max(p3, p4));
            lo tmp = ans;
            ans += (pm-p1) + (pm-p2) + (pm-p3) + (pm-p4);
            // bool check_last = false;
            if (tmp != ans) {
                // check_last = true;
                // cout << "pm: " << pm << nln;
                // cout << i << " ~ " << j << nln;
                // cout << mtx[i][j] << nln;
                // getch();
            }
            if (i == n/2)
                break;
        }
    }

    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}