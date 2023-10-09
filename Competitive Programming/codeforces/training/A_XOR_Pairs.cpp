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

lo log_2(lo x) {
    return log(x)/log(2);
}

void solve() {
    lo n, m;    cin >> n >> m;
    map<lo, bool> mrk;
    while (m--) {
        lo x; cin >> x;
        mrk[x] = true;
    }
    lo pow2[64];
    // cout << pow2[63] << nln;
    pow2[0] = 1;
    for (lo i = 1; i < 64; ++i)
        pow2[i] = pow2[i-1]*2;


    lo ans = 0;
    for (lo x = 2; x <= n; ++x)
        if (mrk[x] == false)
            ans += x-pow2[log_2(x)];
    cout << ans*2 << nln;
}

int main(int argc, char* argv[]) {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // cout << "hi" << nln;
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}