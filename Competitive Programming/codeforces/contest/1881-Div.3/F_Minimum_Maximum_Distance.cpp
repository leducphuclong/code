// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
#include <conio.h>

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

void dfs(lo u, const vector<bool>& mrk, 
    vector<bool>& vst, vector<lo>& dp, vector<lo> adj[]) {
    vst[u] = true;
    for (auto v : adj[u]) {
        if (!vst[v]) {
            dfs(v, mrk, vst, dp, adj);
            if (dp[v] != LLONG_MIN)
                dp[u] = max(dp[u], dp[v]+1);
        }
    }
    if (mrk[u])
        dp[u] = max(dp[u], 0ll);
    vst[u] = false;
}

void dfs2(lo u, const vector<bool>& mrk, vector<bool>& vst, vector<lo> &dp, vector<lo>& dp2, vector<lo> adj[]) {
    vst[u] = true;
    lo mx1 = LLONG_MIN, mx2 = LLONG_MIN;
    for (auto v : adj[u])
        if (!vst[v]) {
            if (dp[v] >= mx1) {
                mx2 = mx1;
                mx1 = dp[v];
            } else if (dp[v] > mx2) {
                mx2 = dp[v];
            }
        }
    
    for (auto v : adj[u]) {
        if (!vst[v]) {
            if (dp[v] != mx1) {
                dp2[v] = max(1+dp2[u], 2+mx1);
            } else {
                dp2[v] = max(1+dp2[u], 2+mx2);
            }
            if (mrk[v])
                dp2[v] = max(dp2[v], 0ll);
            dfs2(v, mrk, vst, dp, dp2, adj);
        }
    }
}

void solve() {
    lo n, k;    cin >> n >> k;
    vector<lo> adj[n+1], dp(n+1, LLONG_MIN), dp2(n+1, LLONG_MIN);
    vector<bool> mrk(n+1, false), vst(n+1, false);
    for (int i = 0; i < k; ++i) {
        lo x;   cin >> x;
        mrk[x] = true;
    }
    for (int i = 0; i < n-1; ++i) {
        lo x, y;        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, mrk, vst, dp, adj);

    // for (lo i = 1; i <= n; ++i) {
    //     cout << i << ": ";
    //     if (dp[i] == LLONG_MIN)
    //         cout << "-INF";
    //     else
    //         cout << dp[i];
    //     cout << nln;
    // }
    // cout << "---------------------------" << nln;

    if (mrk[1])
        dp2[1] = 0;
    else
        dp2[1] = LLONG_MIN;
    dfs2(1, mrk, vst, dp, dp2, adj);

    // for (lo i = 1; i <= n; ++i) {
    //     cout << i << ": ";
    //     if (dp2[i] < 0)
    //         cout << "-INF";
    //     else
    //         cout << dp2[i];
    //     cout << nln;
    // }


    // // cout << "--------------------" << nln;

    vector<lo> f(n+1, 0);
    f[0] = LLONG_MAX;
    for (lo i = 1; i <= n; ++i)
        f[i] = max(dp[i], dp2[i]);
    
    for (lo i = 1; i <= n; ++i) {
        // cout << i << ": ";
        // if (f[i] == LLONG_MIN)
        //     cout << "-INF";
        // else
        //     cout << f[i] << ' ';
        // cout << nln;
    }    
    cout << *min_element(f.begin(), f.end());
    cout << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}