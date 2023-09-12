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
    lo n;
    cin >> n;
    int arr[n+1][n+1];
    for (lo i = 1; i <= n; ++i)
        cin >> arr[1][i];
    // Digol
    for (lo i = 1; i <= n; ++i) {
        lo j = i;
        while (j <= n) {
            arr[j][j] = arr[1][i];
    }
    for (lo i = 1; i <= n; ++i) {
        for (lo j = 1; j <= n; ++j)
            cout << arr[i][j] << ' ';
        cout << nln;
    }
}

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
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