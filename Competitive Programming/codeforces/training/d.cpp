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
lo const N = 1e3;

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
lo arr[N][N], vst[N][N];
// End of global variable declaration.

void precompute() {
}

void dfs(lo x, lo y) {
    vst[x][y] = true;
    
}

void solve() {
    lo t;   cin >> t;
    if (t == 1) {
        // INPUT
        lo n, m;    cin >> n >> m;
        memset(arr, 0, sizeof arr);
        memset(vst, false, sizeof vst);

        for (lo i = 1; i <= n; ++i)
            for (lo j = 1; j <= m; ++j)
                cin >> arr[i][j];
        /* Idea:
        - Call dp[i][j] is the min dangerous to came i, j
        dfs()
         */
        dfs(1, 1);
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