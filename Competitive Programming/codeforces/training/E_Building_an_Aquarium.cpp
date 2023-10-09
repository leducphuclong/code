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
    // Input
    lo n, x;    cin >> n >> x;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;
    // Solve

    auto check = [&] (lo h) {
        lo w = 0;
        for (auto v : arr)
            if (v < h)
                w += h-v;
        return w <= x;
    };


    lo l = 1, r = 2e9, ans = -1;
    while (l <= r) {
        lo h = (l+r)>>1;
        if (check(h))
            ans = h, l = h+1;
        else
            r = h-1;
    }

    cout << r << nln;
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