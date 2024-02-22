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
    lo n;   cin >>n;
    vector<lo> adj[n+1], ind(n+1, 0);
    for (lo i = 1; i <= n; ++i) {
        lo v; cin >> v;
        adj[i].push_back(v);
        ind[v]++;
    }
    // Solve
    // Topological Sorting
    vector<bool> tked(n+1, false);
    queue<lo> q;
    for (lo i = 1; i <= n; ++i)
        if (!ind[i])
            q.push(i);

    while (!q.empty()) {
        lo u = q.front();
        for (auto v : adj[u])
            if (!--ind[v])
                q.push(v);
        tked[u] = true;
        q.pop();
    }

    lo sta = -1;
    for (lo i = 1; i <= n; ++i)
        if (tked[i] == false) {
            sta = i;
            break;
        }

    lo fin = -1;
    for (auto v : adj[sta])
        if (tked[v] == false) {
            fin = v;
            break;
        }

    swap(sta, fin);
    vector<lo> res = {sta};
    while (sta != fin) {
        for (auto v : adj[sta])
            if (!tked[v]) {
                sta = v;
                tked[v] = true;
                res.push_back(sta);
                break;
            }
    }
    
    cout << res.size() << nln;
    for (auto v : res)
        cout << v << ' ';
    cout << nln;
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