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
    lo n, m;   cin >> n >> m;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;
    
    vector<lo> a, b;
    for (auto v : arr) {
        lo x;   cin >> x;
        (x == 1 ? a : b).push_back(v);
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());

    lo sumA = 0;
    lo sumB = accumulate(b.begin(), b.end(), 0ll);
    lo r = b.size();

    lo ans = INT_MAX;
    for (lo l = 0; l <= static_cast<int>(a.size()); l++) {
        while (r > 0 && sumA + sumB - b[r-1] >= m) {
            sumB -= b[r-1];
            r--;
        }
        if (sumA + sumB >= m)
            ans = min(ans, 2*r + l);
        if (l < static_cast<int>(a.size()))
            sumA += a[l];
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;
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