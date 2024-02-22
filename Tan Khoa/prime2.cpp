// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Namespace
using namespace std;  // NOLINT

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    // Eratosthenes Sieve
    lo l, n;
    cin >> l >> n;
    vector<bool> prime(pow(10, 7)+1, 1);
    prime[0] = prime[1] = 0;
    for (lo i = 2; i <= round(sqrt(n)); ++i)
        for (lo j = 2*i; j <= n; j += i)
            prime[j] = 0;
    // Output
    for (lo i = l; i <= n; ++i)
        if (prime[i])
            cout << i << nln;
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
    cerr << nln << "It's ok Long, Good for now !!" << nln;
    return 0;
}
