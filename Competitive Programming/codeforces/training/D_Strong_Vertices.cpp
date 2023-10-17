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

void solve() {
    // Ipput
    lo n;   cin >> n;
    lo a[n], b[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    // Solving
    lo mx = LLONG_MIN;
    for (int i = 0; i < n; ++i)
        mx = max(mx, a[i]-b[i]);

    vector<lo> ans;
    for (int i = 0; i < n; ++i) {
        if (a[i]-b[i] == mx)
            ans.push_back(i+1);
    }
        
    cout << ans.size() << nln;
    for (auto v : ans)
        cout << v << ' ';
    cout << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
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
