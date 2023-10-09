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
    lo n;   cin >> n;
    vector<lo> a(n), b(n);
    for (auto &v : a)   cin >> v;
    for (auto &v : b)   cin >> v;

    map<lo, lo> cnt_a;
    lo cur = 1;
    for (lo i = 1; i < n; ++i) {
        if (a[i] == a[i-1]) {
            cur++;
        } else {
            cnt_a[a[i-1]] = max(cnt_a[a[i-1]], cur);
            cur = 1;
        }
    }
    cnt_a[a.back()] = max(cnt_a[a.back()], cur);

    map<lo, lo> cnt_b;
    cur = 1;
    for (lo i = 1; i < n; ++i) {
        if (b[i] == b[i-1]) {
            cur++;
        } else {
            cnt_b[b[i-1]] = max(cnt_b[b[i-1]], cur);
            cur = 1;
        }
    }
    cnt_b[b.back()] = max(cnt_b[b.back()], cur);

    lo ans = 1;
    for (auto p : cnt_a)
        ans = max(ans, p.second + cnt_b[p.first]);
    for (auto p : cnt_b)
        ans = max(ans, p.second + cnt_a[p.first]);
    cout << ans << nln;
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