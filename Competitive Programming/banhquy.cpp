// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include<iostream>
#include<vector>

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

const int64_t MOD = 1e6+3;

// Declare global variables.

void precompute() {
}


lo banhquy(lo n) {
    if (n == 1)
        return 1;
    return 3*banhquy(n-1)%MOD;
}


lo fastpow(lo n, lo m) {
    if (m == 0)
        return 1;
    lo tmp = fastpow(n, m/2);
    if (m%2)
        return tmp*tmp*n%MOD;
    else
        return tmp*tmp%MOD;
}

void solve() {
    lo n;
    cin >> n;
    if (!n) {
        cout << 1 << nln;
        return;
    }
    cout << fastpow(3, n-1) <<  nln;
    // cout << banhquy(n) << nln;
    // for (lo i = 1; i <= 1000; ++i)
    //     if (fastpow(3, i-1) != banhquy(i))
    //         cout << "Sai" << nln;
}

int main() {
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
