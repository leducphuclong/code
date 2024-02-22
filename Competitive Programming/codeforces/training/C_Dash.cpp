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
    lo n, m, h, k;      cin >> n >> m >> h >> k;
    string s;   cin >> s;
    set<pair<lo, lo>> itms;
    for (lo i = 0; i < m; ++i) {
        lo x, y; cin >> x >> y;
        itms.insert({x, y});
    }

    map<char, pair<lo, lo>> move;
    move['R'] = {+1, 0};
    move['L'] = {-1, 0};
    move['U'] = {0, +1};
    move['D'] = {0, -1};

    lo i = 0, x = 0, y = 0;
    bool chk = true;
    while (i < n) {
        if (s[i] == 'R')
            x++;
        if (s[i] == 'L')
            x--;
        if (s[i] == 'U')
            y++;
        if (s[i] == 'D')
            y--;
        // cout << x << " " << y << endl;
        h--;
        if (h < 0) {
            chk = false;
        }

        if (itms.find({x, y}) != itms.end() && h < k) {
            h = k;
            itms.erase({x, y});
        }
        ++i;
    }
    if (chk)
        cout << "Yes" << nln;
    else
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