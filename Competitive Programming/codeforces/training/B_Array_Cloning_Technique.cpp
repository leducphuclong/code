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
    vector<lo> a(n);
    for (auto &v : a)
        cin >> v;
    
    if (n == 1) {
        cout << 0 << nln;
        return;
    }

    map<lo, lo> cnt;
    lo s = 0;
    for (auto v : a) {
        cnt[v]++;
        s = max(s, cnt[v]);
    }
    
    lo cost = 0;
    while (s*2 <= n) {
        cost += 1 + s;
        s *= 2;
    }
    if (n-s > 0)
        cost += 1 + (n-s);
    
    cout << cost << endl;
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