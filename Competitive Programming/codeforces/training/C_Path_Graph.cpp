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
vector<lo> adj[N]; bool vst[N];
// End of global variable declaration.

void precompute() {
}

void dfs(lo u) {
    vst[u] = true;
    for (auto v : adj[u])
        if (!vst[v])
            dfs(v);
}

void solve() {
    lo n, m;    cin >> n >> m;
    lo deg[n+1];    memset(deg, 0, sizeof(deg));
    while (m--) {
        lo u, v;    cin >> u >> v;
        deg[u]++, deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    map<lo, lo> cnt;
    for (lo i = 1; i <= n; ++i)
        cnt[deg[i]]++;
    
    if (cnt[1] == 2 && cnt[2] == n-2) {
        lo sta = -1;
        for (lo i = 1; i <= n; ++i)
            if (deg[i] == 1)
                sta = i;
        dfs(sta);
        
        bool chk = true;
        for (lo i = 1; i <= n; ++i)
            if (!vst[i])
                chk = false;
        
        if (chk)
            cout << "Yes" << nln;
        else
            cout << "No" << nln;
    } else {
        cout << "No" << nln;
    }
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