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
    // Input
    lo n; cin >>n;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;
    // Solve
    lo t = 0;
    for (auto v : arr)
        t += v;
    lo p = t/n, r = t % n;
    vector<lo> brr;
    for (lo i = 0; i < n-r; ++i)
        brr.push_back(p);;
    for (lo i = 0; i < r; ++i)
        brr.push_back(p+1);
    
    nth_element(arr.begin(), arr.begin()+n-r-1, arr.end());
    lo ans = 0;
    for (lo i = 0; i < n; ++i)
        ans += abs(arr[i]-brr[i]);
    cout << ans/2 << nln;
}

int main(int argc, char* argv[]) {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
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