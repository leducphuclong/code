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

void dfs(lo u, vector<lo> adj[], vector<bool> &vst, vector<lo> &path) {
    path.push_back(u);
    vst[u] = true;
    for (auto v : adj[u])
        if (!vst[v]) {
            dfs(v, adj, vst, path);
            break;
        }
}

void solve() {
    lo n;   cin >> n;
    vector<lo> adj[n+1];
    vector<lo> in(n+1, 0);
    for (lo i = 1; i <= n; ++i) {
        lo v;   cin >> v;
        adj[v].push_back(i);
        if (v != i)
            in[i]++;
    }

    // Topological sort
    queue<lo> que;
    for (lo i = 1; i <= n; ++i)
        if (!in[i])
            que.push(i);
    vector<lo> arr;
    while (!que.empty()) {
        lo u = que.front();
        for (auto v : adj[u])
            if (!--in[v])
                que.push(v);
        arr.push_back(u);
        que.pop();
    }

    vector<bool> vst(n+1, false);
    lo cnt = 0;
    vector<vector<lo>> ans;
    for (auto v : arr) {
        if (!vst[v]) {
            vector<lo> path;
            dfs(v, adj, vst, path);
            ans.push_back(path);
            cnt++;
        }
    }

    cout << ans.size() << nln;
    for (auto path : ans) {
        cout << path.size() << nln;
        for (auto v : path)
            cout << v << ' ';
        cout << nln;
    }
    cout << nln;
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