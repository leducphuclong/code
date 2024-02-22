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
    lo n, m;    
    cin >> n >> m;
    vector<vector<bool>> req(n, (vector<bool>(m, 0)));
    vector<lo> p(n), c(n);

    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> c[i];
        for (int j = 0; j < c[i]; ++j) {
            lo x;   cin >> x;
            req[i][x] = true;
        }
    }

    // Solve
    bool ans = false;
    for (lo i = 0; i < n; ++i) {
        for (lo j = 0; j < n; ++j) {
            if (i != j && p[i] >= p[j]) {
                bool check = true;
                for (int k = 1; k <= m; ++k)
                    if (req[i][k] == true and req[j][k] == false)
                        check = false;
                if (check == false)
                    continue;
                if (p[i] > p[j])
                    ans = true;
                for (int k = 1; k <= m; ++k)
                    if (req[i][k] == false and req[j][k] == true)
                        ans = true;
            }
        }
    }

    if (ans) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;z
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}