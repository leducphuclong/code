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
    // Input
    lo n, k;   cin >> n >> k;
    vector<lo> plk(n);
    for (auto &v : plk) {
        cin >> v; v--;
    }
    // Solve the problem
    vector<pair<lo, lo>> col(k, {0, 0});
    map<lo, lo> last;
    for (lo i = 1; i <= n; ++i) {
        if (i-last[plk[i-1]]-1 > col[plk[i-1]].first)
            col[plk[i-1]].second = col[plk[i-1]].first,
            col[plk[i-1]].first = i-last[plk[i-1]]-1;
        else if (i-last[plk[i-1]]-1 > col[plk[i-1]].second)
            col[plk[i-1]].second = i-last[plk[i-1]]-1;
        last[plk[i-1]] = i;
    }
    for (lo c = 0; c < k; ++c) {
        lo last_step = n-last[c];
        if (last_step > col[c].first)
            col[c].second = col[c].first,
            col[c].first = last_step;
        else if (last_step > col[c].second)
            col[c].second = last_step;
    }
    lo ans = LLONG_MAX;
    for (auto p : col) {
        // cout << p.first << " " << p.second << endl;
        ans = min(ans, max(p.first/2, p.second));
    }
    // Output
    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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