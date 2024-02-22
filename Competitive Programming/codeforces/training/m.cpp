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

lo find(vector<lo> arr, lo x) {
    auto itr = lower_bound(arr.begin(), arr.end(), x);
    if (itr == arr.end() || *itr != x)
        return -1;
    return itr-arr.begin()+1;
}

void solve() {
    lo n;
    cin >> n;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;

    lo q;   cin >> q;
    lo s = 0;
    while (q--) {
        char r; lo x;
        cin >> r >> x;
        if (r == 's') {
            s += x;
        } else {
            lo pos = find(arr, x);
            if (pos != -1) {
                if (s % x > 0) {
                    pos = (pos+s%n)%n;
                } else if (s % x < 0)
                    pos = (pos+s%n+n);
            }
        }
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
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
