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
    char mtx[n+1][m+1];
    cin.ignore();
    for (lo i = 1; i <= n; ++i) {
        string str;
        getline(cin, str, nln);
        for (lo j = 1; j <= m; ++j)
            mtx[i][j] = str[j-1];
    }
    // Solve;

    // Check row
    bool check = 1;
    for (lo i = 1; i <= n; ++i) {
        lo cnt = 0;
        for (lo j = 1; j <= m; ++j)
            if (mtx[i][j] == 'U' || mtx[i][j] == 'D')
                cnt++;
        if (cnt % 2) {
            check = 0;
            break;
        }
    }

    // Check col
    for (lo i = 1; i <= m; ++i) {
        lo cnt = 0;
        for (lo j = 1; j <= n; ++j)
            if (mtx[j][i] == 'L' || mtx[j][i] == 'R')
                cnt++;
        if (cnt % 2) {
            check = 0;
            break;
        }
    }

    if (check == false) {
        cout << -1 << nln;
        return;
    }

    for (lo i = 1; i <= n; ++i) {
        for (lo j = 1; j <= m; ++j)
            cout << mtx[i][j];
        cout << nln;
    }
    cout << "----------------------1" << nln;


    bool black = 1;
    // Pain the row
    for (lo i = 1; i <= n; ++i)
        for (lo j = 1; j <= m; ++j)
            if (mtx[i][j] == 'U' || mtx[i][j] == 'D') {
                cout << i << " ~ " << j << nln;
                if (black) 
                {
                    if (mtx[i][j] == 'U')
                        mtx[i+1][j] = 'W';
                    else
                        mtx[i-1][j] = 'W';
                    mtx[i][j] = 'B'; black = 0;
                } else {
                    if (mtx[i][j] == 'U')
                        mtx[i+1][j] = 'B';
                    else
                        mtx[i-1][j] = 'B';
                    mtx[i][j] = 'W'; black = 1;
                }
            }


    // Pain the collum
    for (lo i = 1; i <= n; ++i) {
        for (lo j = 1; j <= m; ++j)
            cout << mtx[i][j];
        cout << nln;
    }            
    cout << "--------------------" << nln;
    return;
    for (lo i = 1; i <= m; ++i)
        for (lo j = 1; j <= n; ++j)
            if (mtx[j][i] == 'L' || mtx[j][i] == 'R') {
                if (black)
                    mtx[j][i] = 'B', black = 0;
                else
                    mtx[j][i] = 'W', black = 1;
            }

    // Print the product
    for (lo i = 1; i <= n; ++i) {
        for (lo j = 1; j <= m; ++j)
            cout << mtx[i][j];
        cout << nln;
    }
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    freopen("in", "r", stdin);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
