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

void find(lo idx, lo n, const vector<lo> &arr, vector<lo>& dp) {
    if (idx == n-1) {
        dp[idx] = 1;
        return;
    }
    if (dp[idx] != -1)
        return;
    find(idx+1, n, arr, dp);
    dp[idx] = dp[idx+1]+1;
    if (idx+arr[idx]+1 < n)
        dp[idx] = min(dp[idx], dp[idx+arr[idx]+1]);
    else if (idx+arr[idx]+1 == n)
        dp[idx] = 0;
}

void solve() {
    lo n;   cin >> n;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;

    vector<lo> dp(n, -1);
    find(0, n, arr, dp);
    cout << dp[0] << nln;
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