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
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Input
    lo n;   cin >> n;
    char mtx[n][n];
    for (int i = 0; i < n; i++) {
        string s;   cin >> s;
        for (int j = 0; j < n; j++)
            mtx[i][j] = s[j];
    }
    // Solve
    char res[n][n];
    for (lo i = 1; i < n; ++i)
        res[0][i] = mtx[0][i-1], res[n-1][i-1] = mtx[n-1][i],
        res[i-1][0] = mtx[i][0], res[i][n-1] = mtx[i-1][n-1];
    // Output
    for (lo i = 0; i < n; ++i) {
        for (lo j = 0; j < n; ++j)
            if (i == 0 || j == 0 || i == n-1 || j == n-1)
                cout << res[i][j];
            else
                cout << mtx[i][j];
        cout << nln;
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