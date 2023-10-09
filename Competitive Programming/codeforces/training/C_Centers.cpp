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
    lo n;   cin >> n;
    vector<lo> arr(3*n);
    for (auto &v : arr)
        cin >> v;
    // Output
    map<lo, lo> cnt;
    vector<pair<lo, lo>> prs;
    for (lo i = 0; i < 3*n; ++i) {
        cnt[arr[i]]++;
        if (cnt[arr[i]] == 2)
            prs.push_back({i, arr[i]});
    }

    sort(prs.begin(), prs.end());

    for (auto &v : prs)
        cout << v.second << ' ';
    cout << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
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