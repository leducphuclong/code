// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
#include <conio.h>

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
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;

    lo left = 0, right = 1e9;
    for (lo i = 0; i < n-1; ++i) {
        if (arr[i] == arr[i+1])
            continue;
        lo tmp = arr[i]+arr[i+1];
        if (arr[i] < arr[i+1]) {
            left = max(left, arr[i]);
            right = min(tmp/2, right);
        } else {
            left = max(left, tmp/2 + tmp%2);
            right = min(arr[i], right);
        }
        cout << arr[i] << " ~ " << arr[i+1] << nln;
        cout << left << " ~ " << right << nln;
        getch();
    }
    if (left > right) {
        cout << -1 << nln;
    } else {
        cout << left << nln;
    }
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}