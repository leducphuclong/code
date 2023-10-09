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

bool ok(string s1, string s2) {
    lo cnt = 0;
    for (lo i = 0; i < s1.size(); ++i)
        cnt += s1[i] != s2[i];
    return cnt == 1;
}

void solve() {
    // Input
    lo n, m;
    cin >> n >> m;
    vector<string> clt(n);
    for (auto &v : clt) cin >> v;
    // SOLVE
    sort(clt.begin(), clt.end());
    do {
        bool chk = true;
        for (lo i = 0; i < n-1; ++i)
            if (!ok(clt[i], clt[i+1]))
                chk = false;
        if (chk) {
            cout << "Yes" << nln;
            return;
        }
    } while (next_permutation(clt.begin(), clt.end()));

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