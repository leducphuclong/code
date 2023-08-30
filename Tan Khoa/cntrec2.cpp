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
    // Input
    lo n, m;
    cin >> n >> m;
    vector<vector<char>> mtx(n+1, vector<char>(m+1, ' '));
    vector<vector<lo>> mark(n+1, vector<lo>(m+1, 0));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mtx[i][j];
    // Solve
    lo cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mtx[i][j] == '*') {
                if (i > 0 && mtx[i-1][j] == '*')
                    mark[i][j] = mark[i-1][j];
                else if (j > 0 && mtx[i][j-1] == '*')
                    mark[i][j] = mark[i][j-1];
                else mark[i][j] = ++cnt;
            }
            
    // Output 
    cout << cnt << nln;
}

int main(int argc, char* argv[]) {
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
