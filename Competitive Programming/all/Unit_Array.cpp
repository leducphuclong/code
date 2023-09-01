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
    lo n, tmp;
    cin >> n;
    tmp = n;
    lo neg = 0;
    while (tmp--) {
        lo x;
        cin >> x;
        if (x < 0)
            neg++;
    }

    lo res = 0;
    if (neg > n-neg)
        res += ceil(double(neg-(n-neg))/2), neg += res;
    if (neg % 2)
        res++;
    cout << res << nln;
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
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
