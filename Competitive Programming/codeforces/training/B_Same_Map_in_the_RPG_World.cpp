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
    lo n, m;    cin >> n >> m;
    vector<string> A(n), B(n);
    for (auto &s : A) cin >> s;
    for (auto &s : B) cin >> s;
    // Solve
    for (lo s = 0; s < n; ++s) {
        for (lo t = 0; t < m; ++t) {
            lo check = true;
            for (lo i = 0; i < n; ++i) {
                for (lo j = 0; j < m; ++j) {
                    if (A[(i+s)%n][(j+t)%m] != B[i][j])
                        check = false;
                }
            }
            if (check == true) {
                cout << "Yes" << nln;
                return;
            }
        }
    }
    cout << "No" << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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