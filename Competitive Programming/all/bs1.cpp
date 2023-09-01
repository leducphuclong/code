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
const long double eps = 1e-3;

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

bool check(vector<lo> arr, lo q, lo m) {
    lo cnt = 0;
    for (auto v : arr) {
        cnt += (static_cast<long double>(v)/m);
    }
    return cnt >= q;
}

void solve() {
    // Input
    lo n, q;
    cin >> n >> q;
    vector<lo> arr(n);
    for (auto &i : arr) {
        long double x;
        cin >> x;
        i = x*100;
    }
    // Binary Search
    lo l = 0, r = 1e8, res = 0;
    while (l <= r) {
        lo m = (l+r)/2;
        if (check(arr, q, m))
            l = m+1, res = m;
        else
            r = m-1;
    }
    cout << fixed << setprecision(2) << res/100.0 << nln;
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
