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

class Disjoint_Set {
    lo *rnk, *par, n;
    public:
        lo cnt_del;
        Disjoint_Set(lo n) {
            cnt_del = 0;
            rnk = new lo[n+1];
            par = new lo[n+1];
            for (lo i = 1; i <= n; ++i)
                rnk[i] = 0, par[i] = i;
        }

        ~Disjoint_Set() {
            delete[] rnk, delete[] par;
        }

        lo Find(lo u) {
            if (par[u] == u)
                return u;
            lo p = Find(par[u]);
            par[u] = p;
            return p;
        }

        void Union(lo u, lo v) {
            lo pu = Find(u), pv = Find(v);
            if (pu == pv) {
                ++cnt_del;
                return;
            }
            if (rnk[pu] < rnk[pv]) {
                par[pu] = pv;
            } else {
                par[pv] = pu;
                if (rnk[pu] == rnk[pv])
                    rnk[pu]++;
            }
        }
};

void solve() {
    lo n, m; cin >> n >> m;
    Disjoint_Set dsu(n);
    while (m--) {
        lo u, v;    cin >> u >> v;
        dsu.Union(u, v);
    }

    cout << dsu.cnt_del << nln;
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