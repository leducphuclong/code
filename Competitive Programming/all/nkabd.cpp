// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// #include <conio.h>
#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

typedef int64_t lo;

#define nln '\n'

const lo L = 1e5+1;

// Declare global variables.

lo prime[L], pfs[L] = {0};


void precompute() {
    // The Sieve of Eratosthenes
    for (lo i = 0; i < L; ++i)
        prime[i] = 1;
    prime[1] = 1;
    for (lo i = 2; i <= L/2; ++i)
        for (lo j = 2*i; j < L; j += i)
            prime[j] += i;
    // Build Prefix Sum
    for (lo i = 1; i < L; ++i) {
        if (prime[i] > i)
            pfs[i] = 1;
        else
            pfs[i] = 0;
        pfs[i] += pfs[i-1];
    }
}

void solve() {
    lo L, R;
    cin >> L >> R;
    cout << pfs[R]-pfs[L-1] << nln;
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
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
