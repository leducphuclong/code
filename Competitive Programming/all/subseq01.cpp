// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

// Declare global variables.

void precompute() {
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    vector<int> pfm(n+1, INT_MAX), pfs(n+1, 0);
    pfm[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pfs[i] = pfs[i-1]+a[i-1];
        pfm[i] = min(pfm[i-1], pfs[i]);
    }

    int res = 0, mav = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i-1] > 0)
            mav += a[i-1];
        res = max(res, pfs[i]-pfm[i]);
    }

    cout << mav << ' ' << res << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    return 0;
}
