// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Define
#define nln '\n'
#define bits(x) std::bitset<10>(x)

// Typedef and Struct
typedef int64_t lo;

// Constant

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

bool one_bit_1_left_only(lo n, lo pos) {
    return n == (1 << pos);
}

bool is_bit_1(lo n, lo pos) {
    return n & (1 << pos);
}

void solve() {
    lo n;
    cin >> n;
    // cout << bits(10) << nln;
    // cout << bits(10 ^ (1 << 1)) << nln;
    // return;
    // change x -> 2^k
    vector<lo> ans = {n};
    for (lo i = 0; ; i++) {
        if (is_bit_1(n, i)) {
            if (one_bit_1_left_only(n, i))
                break;
            n ^= 1 << i;
            ans.push_back(n);
        }
    }
    // change 2^k - > 1
    while (n > 1) {
        n >>= 1;
        ans.push_back(n);
    }
    cout << ans.size() << nln;
    for (auto v : ans)
        cout << v << ' ';
    cout << nln;
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
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
