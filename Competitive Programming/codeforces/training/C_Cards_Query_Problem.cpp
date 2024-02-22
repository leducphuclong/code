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
    lo q;   cin >> q;

    map<lo, map<lo, lo>> box;
    map<lo, map<lo, lo>> id;

    while (q--) {
        lo r; cin >> r;
        if (r == 1) {
            lo i, j;    cin >> i >> j;
            box[j][i]++;
            id[i][j]++;
        } else if (r == 2) {
            lo i; cin >> i;
            for (auto p : box[i])
                for (lo t = 0; t < p.second; ++t)
                    cout << p.first << ' ';
            cout << nln;
        } else {
            lo i;   cin >> i;
            for (auto p : id[i])
                cout << p.first << ' ';
            cout << nln;
        }
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