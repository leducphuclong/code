// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Namespace
using namespace std;  // NOLINT

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo n;   cin >> n;
    // Build 2D prefix sum
    lo mtx[n+1][n+1][n+1];
    memset(mtx, 0, sizeof(mtx));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k) {
                cin >> mtx[i][j][k];
                mtx[i][j][k] += mtx[i][j-1][k]+mtx[i][j][k-1]-mtx[i][j-1][k-1];
            }
    // Find the max
    lo sum[n+1][n+1][n+1][n+1];
    memset(sum, 0, sizeof(sum));
    for (lo size = 2; size <= n; ++size)
        for (lo h = 1; h <= n-size+1; ++h)
            for (lo i = h; i <= h+size-1; ++i)
                for (lo j = size; j <= n; ++j)
                    for (lo k = size; k <= n; ++k) {
                        // cout << "size: " << size << nln;
                        // cout << "h: " << h << nln;
                        // cout << "i: " << i << nln;
                        // cout << "j ~ k: " << j << " ~ " << k << nln;
                        sum[size][h][j][k] += mtx[i][j][k]
                            - mtx[i][j-size][k]
                            - mtx[i][j][k-size]
                            + mtx[i][j-size][k-size];
                        // cout << "sum: " << sum[size][h][j][k] << nln;
                        // cout << "---------------------" << nln;
                        // getch();
                    }
    // cout << "test sum: " << sum[2][1][2][2] << nln;
    lo mav = LLONG_MIN;
    for (lo size = 1; size <= n; ++size)
        for (lo h = 1; h <= n-size+1; ++h)
            for (lo j = size; j <= n; ++j)
                for (lo k = size; k <= n; ++k)
                    if (sum[size][h][j][k] > mav)
                        mav = sum[size][h][j][k];
    cout << mav << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    // freopen("in", "r", stdin);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
