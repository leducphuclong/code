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
const lo N = 2e5+2;

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void dfs(int u, vector<lo> adj[], vector<lo> &dp, vector<bool> &vst) {
    vst[u] = true;
    bool is_leave = true;
    for (auto v : adj[u])
        if (!vst[v]) {
            dfs(v, adj, dp, vst);
            dp[u] += dp[v];
            is_leave = false;
        }
    vst[u] = false;
    dp[u] += is_leave;
}

void solve() {
    // Solving
    lo n;  cin >> n;
    // Declare global variables
    vector<lo> adj[n+1];
    vector<lo> dp(n+1, 0);
    vector<bool> vst(n+1, 0);
    // Reset common variables
    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
        dp[i] = 0;
        vst[i] = false;
    }
    // Input
    for (int i = 0; i < n-1; ++i) {
        lo x, y; cin >> x; cin >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    // Precompute
    dfs(1, adj, dp, vst);
    // Proceed queries
    lo q; cin >> q;
    while (q--) {
        lo x, y; cin >> x; cin >> y;
        cout << dp[x]*dp[y] << nln;
    }
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