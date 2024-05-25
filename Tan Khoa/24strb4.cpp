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
typedef long long lo;
typedef long long ll;

// Constant

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo n, p;
    cin >> n >> p;
    lo arr[n];  // NOLINT
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    
    auto check = [&](ll g) {
    	ll s = 0;
    	...
    	if (s >= p) return true; return false;
    }

    lo left = 1, right = 1e18, ans = -1;
    while (left <= right) {
        lo mid = (left+right)>>1;
        if (check(arr, n, p, mid))
            ans = mid, right = mid-1;
        else
            left = mid+1;
    }
    cout << ans << nln;
}

int main(int argc, char* argv[]) {
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
