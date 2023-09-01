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
    // Input
    lo n, k;
    cin >> n >> k;
    vector<lo> arr(n);
    lo total = 0;
    for (auto &i : arr) {
        cin >> i;
        total += i;
    }
    // check function
    auto work = [&](lo  x) {
        lo Ngroups = 1, sum = 0;
        for (const auto &v : arr) {
            if (v > x)
                return false;
            if (sum + v > x)
                Ngroups++, sum = 0;
            sum += v;
        }
        return Ngroups <= k;
    };
    // Binary Search
    lo bot = 1, top = total, ans = -1;
    while (bot <= top) {
        lo mid = (bot+top)>>1;
        if (work(mid))
            top = mid-1, ans = mid;
        else
            bot = mid+1;
    }
    cout << ans << nln;
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
