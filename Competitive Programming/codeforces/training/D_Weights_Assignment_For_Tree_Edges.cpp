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
    /* Idea:
    - If the permutation is not sorted by topological order, print -1
    - Else, we starting to find weight values
    - If we reach any node, so we add the max of currents sons of its
    parent + 1 (to have difference value)
        - We will use cur_max[i] to store max of currents sos of node i
     */

    lo n;   cin >> n;
    lo par[n+1], root = -1;
    for (lo i = 1; i <= n; ++i) {
        cin >> par[i];
        if (par[i] == i)
            root = i;
    }

    lo per[n+1];
    for (lo i = 1; i <= n; ++i)
        cin >> per[i];
    
    // This part to check the permutation whether valid
    if (per[1] != root) {
        cout << -1 << endl; 
        return;
    }
    set<lo> sav;    sav.insert(root);
    for (lo i = 2; i <= n; ++i) {
        lo v = per[i];
        if (sav.find(par[v]) != sav.end()) {
            sav.insert(v);
        } else {
            cout << -1 << endl;
            return;
        }
    }

    lo dist[n+1];   memset(dist, 0, sizeof dist);
    for (lo i = 2; i <= n; ++i)
        dist[per[i]] = dist[per[i-1]]+1;
    
    lo w[n+1];
    for (lo i = 1; i <= n; ++i)
        cout << dist[i] - dist[par[i]] << ' ';
    cout << endl;
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