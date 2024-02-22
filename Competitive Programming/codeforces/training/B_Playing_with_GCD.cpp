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

lo __lcm(lo a, lo b) {
    return a*b/__gcd(a, b);
}

void solve() {
    lo n;   cin >>n;
    vector<lo> a(n+2, 1);
    for (lo i = 1; i <= n; ++i)
        cin >> a[i];

    vector<lo> b(n+2, 1);
    for (lo i = 1; i <= n+1; ++i)
        b[i] = __lcm(a[i], a[i-1]);
    
    bool chk = true;
    for (lo i = 1; i <= n; ++i)
        if (__gcd(b[i], b[i+1]) != a[i])
            chk = false;
    
    if (chk)
        cout << "YES" << nln;
    else
        cout << "NO" << nln;
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