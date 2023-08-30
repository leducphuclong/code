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
    lo n;
    cin >> n;
    vector<lo> arr(n);
    for (auto &i : arr)
        cin >> i;
    // compress
    set<lo> tmp_set(arr.begin(), arr.end());
    vector<lo> tmp_vector(tmp_set.begin(), tmp_set.end());
    for (auto &v : arr)
        v = lower_bound(tmp_vector.begin(), tmp_vector.end(), v)-tmp_vector.begin()+1;
    // Solve
    vector<lo> val(n+1, LLONG_MAX);
    val[0] = LLONG_MIN;
    lo res = LLONG_MIN;
    for (const auto &v : arr) {
        lo k = lower_bound(val.begin(), val.end(), v)-val.begin();
        val[k] = v;
        res = max(res, k);
    }
    cout << res << nln;
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
