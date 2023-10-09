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
    lo n;   cin >> n;
    lo arr[3][n+1];
    arr[1][1] = 2*n, arr[2][n] = 2*n-1;
    for (lo i = 2; i <= n; ++i)
        if (i % 2 == 0)
            arr[1][i] = i-1, arr[2][i-1] = i;
        else
            arr[1][i] = n+i-2, arr[2][i-1] = n+i-1;

    for (lo i = 1; i <= 2; ++i) {
        for (lo j = 1; j <= n; ++j)
            cout << arr[i][j] << ' ';
        cout << nln;
    }
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