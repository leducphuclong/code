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
    lo n;
    cin >> n;
    for (lo p = 2; p <= 59; ++p) {
        lo l = 2, r = powl(n, 1.0/p);
        // cout << "r: " << r << nln;
        while (l <= r) {
            // cout << "k: " << nln;
            lo k = (l+r)/2, t = 1+k, opr = k*k;
            for (lo i = 2; i <= p; ++i) {
                t += opr, opr *=k;
                if (opr >= 1e18 || t > n)
                    break;
            }
            if (t == n) {
                cout << "YES" << nln;
                return;
            } else if (t > n) {
                r = k-1;
            } else {
                l = k+1;
            }
        }
    }
    cout << "NO" << nln;
}

int main(int argc, char* argv[]) {
    // freopen("Rudolf_and_Snowflakes-4.inp", "r", stdin);
    // freopen("Rudolf_and_Snowflakes-4.out", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
