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
    lo arr[n][m];
    for (lo i = 0; i < n; ++i)
        for (lo j = 0; j < m; ++j)
            cin >> arr[i][j];

    vector<vector<lo>> col(m);
    for (lo j = 0; j < m; ++j)
        for (lo i = 0; i < n; ++i)
            col[j].push_back(arr[i][j]);
    
    for (auto &v : col)
        sort(v.begin(), v.end());
    
    lo ans = 0;
    for (lo j = 0; j < m; ++j) {
        lo sum = col[j][0];
        for (lo i = 1; i < n; ++i) {
            ans +=  col[j][i]*i - sum;
            sum += col[j][i];   
        }
    }
    
    cout << ans << nln;
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