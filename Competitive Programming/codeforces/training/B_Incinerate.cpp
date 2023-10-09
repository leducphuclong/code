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
    lo n, k;    cin >> n >> k;
    vector<pair<lo, lo>> m(n);
    for (auto &p : m)
        cin >> p.second;
    for (auto &p : m)
        cin >> p.first;
    
    sort(m.begin(), m.end());

    bool ok = true;
    lo t = k;
    for (auto p : m) {
        while (p.second - t > 0) {
            if (k <= 0) {
                ok = false;
                break;
            }
            k -= p.first;
            t += k;
        }
        if (k <= 0)
            break;
    }
    if (ok)
        cout << "YES" << nln;
    else
        cout << "NO" << nln;
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