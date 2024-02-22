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

lo left_index(const std::vector<lo>& arr, lo k) {
    auto it = std::lower_bound(arr.begin(), arr.end(), k);
    if (it != arr.end())
        return std::distance(arr.begin(), it)+1;
    return -1;  // No element found in the vector >= k
}

lo right_index(const std::vector<lo>& arr, lo k) {
    auto it = std::upper_bound(arr.begin(), arr.end(), k);
    if (it != arr.begin())
        return std::distance(arr.begin(), std::prev(it))+1;
    return -1;  // No element found
}

void precompute() {
}

void solve() {
    map<lo, bool> exist;
    lo n, q;
    cin >> n >> q;
    vector<lo> arr(n);
    for (auto &v : arr) {
        cin >> v;
        exist[v] = 1;
    }
    sort(arr.begin(), arr.end());
    while (q--) {
        lo r;
        cin >> r;
        if (r == 1) {
            lo k;
            cin >> k;
            if (k > arr.back()) {
                arr.push_back(k);
                exist[k] = 1;
            } else if (!exist[k]) {
                auto it = upper_bound(arr.begin(), arr.end(), k);
                exist[*it] = 0;
                exist[k] = 1;
                *it = k;
            }
        } else {
            lo l, r;
            cin >> l >> r;
            lo left = left_index(arr, l);
            lo right = right_index(arr, r);
            if (left == -1 || right == -1)
                cout << 0 << nln;
            else
                cout << right-left+1 << nln;
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
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
