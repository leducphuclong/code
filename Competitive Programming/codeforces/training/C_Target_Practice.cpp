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

lo point(lo x, lo y) {
    return min(min(x, 10-x+1), min(y, 10-y+1));
}

void precompute() {
}

void solve() {
    lo cnt = 0;
    vector<string> mtx;
    for (lo i = 0; i < 10; ++i) {
        string s;   cin >> s;
        mtx.push_back(s);
        for (lo j = 0; j < 10; ++j)
            if (mtx[i][j] == 'X')
                cnt += point(i+1, j+1);
    }
    cout << cnt << nln;
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