// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t lo;

// Constant

// Namespace
using namespace std;  // NOLINT

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

bool check(lo n) {
    vector<lo> a;

    while (n > 0) {
        a.push_back(n%10);
        n /= 10;
    }
    lo l = a.size();
    for (lo i = 1 ; i <= ceil((double)l/2)-1; ++i)
        if (a[i] <= a[i-1])
            return false;
    vector<lo> b = a;
    reverse(b.begin(), b.end());
    for (lo i = 0; i < l; ++i)
        if (b[i] != a[i])
        return false;
    return true;
}

void solve() {
    lo n;
    cin >> n;
    lo cnt = 0;
    for (lo i = 1; i <= n; ++i)
        if (check(i)) {
            // cout << i << nln;
            ++cnt;
        }
    cout << cnt << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    freopen("23kvbna4.inp", "r", stdin);
    freopen("23kvbna4.ans", "w", stdout);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
