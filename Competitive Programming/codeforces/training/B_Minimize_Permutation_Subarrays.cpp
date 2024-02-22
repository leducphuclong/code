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

void solve() {
    // Input
    lo n;   cin >>n;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;
    // Build idx array
    vector<lo> idx(n+1, 0);
    for (lo i = 0; i < n; ++i)
        idx[arr[i]] = i+1;

    if (min(idx[1], idx[2]) <= idx[n] && idx[n] <= max(idx[1], idx[2]))
        cout << min(idx[1], idx[2]) << ' ' << max(idx[1], idx[2]) << nln;
    else if (idx[n] < min(idx[1], idx[2]))
        cout << idx[n] << ' ' << min(idx[1], idx[2]) << nln;
    else
        cout << max(idx[1], idx[2]) << ' ' << idx[n] << nln;
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