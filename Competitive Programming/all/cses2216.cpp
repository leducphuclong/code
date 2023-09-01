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
    map<lo, bool> cnt;
    lo n, x, res = 0;
    cin >> n;
    int a[n+1];
    for (lo i = 1; i <= n; ++i)
        cin >> a[i];
    for (lo i = 1; i <= n; ++i) {
        if (!cnt[a[i]-1])
    }
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    return 0;
}
