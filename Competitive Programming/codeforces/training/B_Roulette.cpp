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
    lo n;   cin >> n;
    map<lo, bool> bet[n+1];
    for (lo i = 1; i <= n; ++i) {
        lo k;   cin >> k;
        for (lo j = 1; j <= k; ++j) {
            lo c;   cin >> c;
            bet[i][c] = 1;
        }
    }
    lo x;   cin >> x;
    lo qtt = LLONG_MAX;
    for (lo i = 1; i <= n; ++i)
        if (bet[i][x] == 1 and bet[i].size() < qtt)
            qtt = bet[i].size();
    vector<lo> ans;
    for (lo i = 1; i <= n; ++i)
        if (bet[i][x] == 1 && bet[i].size() == qtt)
            ans.push_back(i);
    cout << ans.size() << nln;
    for (auto v : ans)
        cout << v << ' ';
    cout << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
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