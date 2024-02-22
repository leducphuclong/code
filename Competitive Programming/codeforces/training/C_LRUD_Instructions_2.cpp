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
    string str; cin >> str;

    lo x = 0, y = 0;
    map<pair<lo, lo>, bool> vst;
    vst[{x, y}] = true;
    for (auto c : str) {
        if (c == 'U')
            y++;
        if (c == 'D')
            y--;
        if (c == 'L')
            x--;
        if (c == 'R')
            x++;
        if (vst[{x, y}] == true) {
            cout << "Yes" << nln;
            return;
        }
        vst[{x, y}] = true;
    }
    cout << "No" << nln;
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