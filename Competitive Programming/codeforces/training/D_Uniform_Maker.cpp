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
    lo n, m;    cin >> n >> m;
    vector<string> s(n);
    for (auto &v : s) cin >> v;
    // Solve
    lo ans = 0;
    for (lo i = 0; i < m; i++) {
        map<char, lo> cnt;
        for (lo j = 0; j < n; j++)
            cnt[s[j][i]]++;
        lo mav = 0;
        for (auto v : cnt)
            if (v.second > mav)
                mav = v.second;
        ans += n-mav;
    }
    cout << ans << nln;
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