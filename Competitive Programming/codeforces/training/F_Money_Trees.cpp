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
    lo n, k;    cin >> n >> k;
    vector<lo> a(n), h(n);
    for (auto &v : a) cin >> v;
    for (auto &v : h) cin >> v;
    // Solve
    // Find ID of all subarrays
    lo cnt = 1;
    vector<lo> id(n+1, 0);
    id[1] = 1;
    for (lo i = 1; i < n; ++i)
        if (h[i-1] % h[i] == 0)
            id[i+1] = id[i];
        else
            id[i+1] = ++cnt;
    // Build Prefix Sum
    vector<lo> p = {0};
    for (auto v : a)
        p.push_back(p.back()+v);
    // Sliding windows
    auto check = [&](lo len) {
        for (lo i = 1; i <= n-len+1; ++i) {
            lo sta = i, end = i+len-1;
            if (p[end]-p[sta-1] <= k && id[sta] == id[end])
                return true;
        }
        return false;
    };
    // Binary Search
    lo l = 1, r = n, ans = 0;    
    while (l <= r) {
        lo g = (l+r)>>1;
        if (check(g))
            ans = g, l = g+1;
        else
            r = g-1;
    }
    cout << r << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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