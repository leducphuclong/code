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
    lo n, m;    cin >> n >> m;
    vector<lo> arr(n);
    lo l = LLONG_MIN, r = 0;
    for (auto &v : arr) { 
        cin >> v;
        l = max(l, v); r += v+1;
    }
    r--;
    // Solve
    auto check = [&] (lo qtt) {
        lo cnt = 1, cur = 0; 
        for (auto v : arr) {
            if (cur + v <= qtt) {
                cur += v+1;
            } else {
                cnt++;
                cur = v+1;
            }
        }
        return cnt <= m;
    };

    lo ans = -1;
    while (l <= r) {
        lo g = (l+r)>>1;
        if (check(g))
            ans = g, r = g-1;
        else
            l = g+1;
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