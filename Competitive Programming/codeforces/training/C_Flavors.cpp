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
    lo n;   cin >> n;
    vector<pair<lo, lo>> cups(n);
    for (auto &p : cups)
        cin >> p.first >> p.second;
    // Solve
    map<lo, priority_queue<lo>> clt;
    for (auto p : cups)
        clt[p.first].push(p.second);
    // Take two cups with the same flavor
    lo op1 = 0;
    for (auto e : clt) {
        if (e.second.size() < 2) continue;
        vector<lo> tke;
        for (lo i = 0; i < 2; ++i) {
            tke.push_back(e.second.top());
            e.second.pop();
        }
        op1 = max(op1, tke[0]+tke[1]/2);
    }
    // Take two cups with different flavors
    lo op2 = 0;
    vector<lo> tke;
    for (auto e : clt)
        tke.push_back(e.second.top());
    sort(tke.rbegin(), tke.rend());
    op2 = tke[0]+tke[1];
    cout << max(op1, op2) << nln;
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