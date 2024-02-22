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
    string s;   cin >> s;
    vector<lo> clrs(n);
    for (auto &v : clrs)
        cin >> v;
    // Solve
    map<lo, char> last;
    for (lo i = 0; i < n; ++i)
        last[clrs[i]] = s[i];
    
    map<lo, char> prev;
    for (lo i = 1; i <= m; ++i)
        prev[i] = last[i];
    
    string ans = "";
    for (lo i = 0; i < n; ++i) {
        ans += prev[clrs[i]];
        prev[clrs[i]] = s[i];
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