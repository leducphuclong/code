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

void show(vector<lo> arr, lo n) {
    for (lo i = 1; i <= n; ++i)
        cout << arr[i] << ' ';
    cout << nln;
}

void solve() {
    // Input
    lo n;   cin >> n;
    vector<lo> arr(n);
    for (auto &v : arr) cin >> v;
    // Build Prefix Sum Left to Right
    vector<lo> pfs_l2r = {0};
    for (auto v : arr)
        pfs_l2r.push_back(pfs_l2r.back()+v);
    // Build Prefix Min, Max from Prefix Sum left to right
    vector<lo> pfm_l2r = {0}, pfM_l2r = {0};
    for (lo i = 1; i <= n; ++i) {
        pfm_l2r.push_back(min(pfm_l2r.back(), pfs_l2r[i]));
        pfM_l2r.push_back(max(pfM_l2r.back(), pfs_l2r[i]));
    }
    // Build Prefix Sum Right to Left
    vector<lo> pfs_r2l(n+2, 0);
    for (lo i = n; i >= 1; --i)
        pfs_r2l[i] = pfs_r2l[i+1] + arr[i-1];
    // Build Prefix Min, Max fromo Prefix Sum Right to Left
    vector<lo> pfm_r2l(n+2, 0), pfM_r2l(n+2, 0);
    for (lo i = n ; i >= 1; --i)
        pfm_r2l[i] = min(pfm_r2l[i+1], pfs_r2l[i]),
        pfM_r2l[i] = max(pfM_r2l[i+1], pfs_r2l[i]);
    // List all we have
    // cout << "pfs_l2r: " << nln;
    // show(pfs_l2r, n);
    // cout << "pfm_l2r: " << nln;
    // show(pfm_l2r, n);
    // cout << "pfM_l2r: " << nln;
    // show(pfM_l2r, n);
    // cout << nln;
    // cout << "pfs_r2l: " << nln;
    // show(pfs_r2l, n);
    // cout << "pfm_r2l: " << nln;
    // show(pfm_r2l, n);
    // cout << "pfM_r2l: " << nln;
    // show(pfM_r2l, n);
    // Solve
    lo ans = 0;
    for (lo i = 1; i <= n-1; ++i) {
        // Left is Max, Right is Min
        lo left_M = pfs_l2r[i] - pfm_l2r[i-1];
        // cout << "left_M: " << left_M << endl;
        lo right_m = pfs_r2l[i+1] - pfM_r2l[i+2];
        // Left is Min, Right is Max
        lo left_m = pfs_l2r[i] - pfM_l2r[i-1];
        lo right_M = pfs_r2l[i+1] - pfm_r2l[i+2];
        // Compare with ans
        ans = max(abs(left_M-right_m), ans);
        ans = max(abs(right_M-left_m), ans);

    }
    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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