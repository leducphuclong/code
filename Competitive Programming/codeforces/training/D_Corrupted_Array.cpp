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
    vector<lo> brr(n+2);
    for (auto &v : brr)
        cin >> v;

    sort(brr.begin(), brr.end());

    // THe sum (n+1 th) is only can second max or first max

    // Check if the n+1 th element is second max;
    if (accumulate(brr.begin(), brr.begin()+n, 0ll) == brr[n]) {
        for (lo i = 0; i < n; ++i)
            cout << brr[i] << ' ';
        cout << nln;
        return;
    }

    // Check if the n+1 the element is first max
    lo s = accumulate(brr.begin(), brr.begin()+n+1, 0ll);
    for (lo i = 0; i < n+1; ++i) {
        if (s - brr[i] == brr[n+1]) {
            for (lo j = 0; j < i; ++j)
                cout << brr[j] << ' ';

            for (lo j = i+1; j < n+1; ++j)
                cout << brr[j] << ' ';
            cout << nln;
            return;
        }
    }

    cout << -1 << endl;
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