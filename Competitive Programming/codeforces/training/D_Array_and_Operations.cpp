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
    lo n, k;     cin >> n >> k;
    vector<lo> arr(n+1);
    for (lo i = 1; i <= n; ++i)
        cin >> arr[i];
    
    sort(arr.begin()+1, arr.end());

    lo ans = 0;
    for (lo i = 1; i <= n-2*k; ++i) {
        // cout << i << ' ';
        ans += arr[i];
    }

    // for (lo i = 1; i <= n; ++i)
    //     cout << arr[i] << ' ';
    // cout << endl;

    for (lo i = 1; i <= k; ++i) {
        // cout << arr[n-2*k+i] << ' ' << arr[n-k+i] << endl;
        ans += (arr[n-2*k+i] == arr[n-k+i]);
        // cout << ans << endl << " ----------- " << endl;
    }

    cout << ans << endl;
}

int main(int argc, char* argv[]) {
// /    freopen("in", "r", stdin);
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