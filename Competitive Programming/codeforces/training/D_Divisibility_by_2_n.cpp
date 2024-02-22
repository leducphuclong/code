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
    // First we call
    lo n;   cin >> n;
    vector<lo> arr(n);
    for (auto &v: arr)
        cin >> v;

    lo tol = 0;
    vector<lo> p2i;
    for (int i = n; i >= 1; i--) {
        if (i & 1)
            continue;

        p2i.push_back(0);
        lo tmp = i;
        while (tmp % 2 == 0)
            tmp /= 2, p2i.back()++;

        tol += p2i.back();
    } // p2i is the list of factor 2 of idx

    lo cnt_2v = 0;
    for (auto v : arr) {
        while (v % 2 == 0)
            v /= 2, cnt_2v++;
    }

    if (cnt_2v + tol < n) {
        cout << -1 << nln;
    } else {
        sort(p2i.rbegin(), p2i.rend());
        lo i = 0;
        lo ans = 0;
        while (cnt_2v < n) {
            cnt_2v += p2i[i];
            ans++, i++;
        }
        cout << ans << nln;
    }
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
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