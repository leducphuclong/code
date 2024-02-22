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
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

bool check(lo h, vector<lo> arr) {
    lo n = arr.size();
    bool ans = false;
    for (lo i = 0; i < max(0ll, n-(2*h+1)+1); ++i) {
        for (lo )
    }
}

void solve() {
    lo n;       cin >> n;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;

    lo low = *min_element(arr.begin(), arr.end());
    lo high = *max_element(arr.begin(), arr.end());

    while (low <= high) {
        lo mid = (low + high) >> 1;
        
    }
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
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