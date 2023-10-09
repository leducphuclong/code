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
    lo n, m;    cin >> n >> m;
    vector<lo> adj[n+1];
    while (m--) {
        lo u, v;    cin >> u >> v;
        adj[u].push_back(v), adj[v].push_back(u);
    }

    // BSF
    lo cnt = 0;
    vector<bool> vst(n+1, false);
    for (lo i = 1; i <= n; ++i) {
        if (!vst[i]) {
            cnt++;
            queue<lo> q;
            q.push(i);
            vst[i] = true;
            while (!q.empty()) {
                lo v = q.front();
                for (auto u : adj[v])
                    if (!vst[u]) {
                        q.push(u);
                        vst[u] = true;
                    }
                q.pop();
            }
        }
    }
    // 10888869450418352160768000001

    cout << cnt << nln;
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