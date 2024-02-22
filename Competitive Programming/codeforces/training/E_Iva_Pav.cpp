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
const lo Nbit = 32;

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Input
    lo n;   cin >> n;
    vector<lo> a(n);
    for (auto &v : a) cin >> v;
    // Pre-processing
    int pfs[n+1][Nbit] = {0};
    for (lo i = 1; i <= n; ++i) {
        for (lo j = 0; j < Nbit; ++j)
            if (a[i-1] & (1 << j))
                pfs[i][j] = pfs[i-1][j]+1;
            else
                pfs[i][j] = pfs[i-1][j];
    }

    lo  q;  cin >> q;
    while (q--) {
        lo l, k;    cin >> l >> k;
        if (a[l-1] < k) {
            cout << -1 << ' ';
            continue;
        }
        lo low = l, hight = n;
        while (low <= hight) {
            lo ave = (low+hight) >> 1, f = 0;
            for (lo i = 0; i < Nbit; ++i)
                if (pfs[ave][i] - pfs[l-1][i] == ave-l+1)
                    f += (1 << i);
            if (f >= k)
                low = ave+1;
            else
                hight = ave-1;
        }
        cout << hight << ' ';
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