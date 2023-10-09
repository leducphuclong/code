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
vector<bool> vst;
lo n, a, b;
vector<lo> adj[N];

// End of global variable declaration.

void precompute() {
}

lo des_dfs(lo u, lo prev) {
    vst[u] = true;
    lo res = -1;
    for (auto v : adj[u]) {
        if (vst[v] == true) {
            if (v == prev)
                continue;
            else
                res = v;
        } else {
            lo go = des_dfs(v, u);
            if (go != -1)
                res = go;
        }
    }
    vst[u] = false;
    return res;
}

lo dist_dfs(lo u, lo des) {
    if (u == des)
        return 0;
    vst[u] = true;
    lo cost = LLONG_MAX;
    for (auto v : adj[u])
        if (vst[v] == false) {
            lo dist = dist_dfs(v, des);
            if (dist == LLONG_MAX)
                continue;
            cost = min(cost, dist+1);
        }
    vst[u] = false;
    return cost;
}

void solve() {
    cin >> n >> a >> b;
    for (lo i = 0; i < n; ++i) {
        lo u, v;    cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    vst.resize(n+1, false);
    lo des = des_dfs(b, b);
    if (dist_dfs(a, des) > dist_dfs(b, des))
        cout << "YES" << nln;
    else
        cout << "NO" << nln;    
        
    // reset data
    for (lo i = 1; i <= n; ++i)
        adj[i].clear();
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