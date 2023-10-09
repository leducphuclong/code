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
    lo n, m;    cin >> n >> m;
    vector<lo> arr(n*m);
    for (auto &v : arr)
        cin >> v;

    sort(arr.begin(), arr.end());
    // Case minimum in (0, 0)
    lo op1 = (arr[arr.size()-2]-arr[0])*min(n-1, m-1) + (arr.back()-arr[0])*(m*n-min(n, m));
    reverse(arr.begin(), arr.end());
    lo op2 = abs(arr[arr.size()-2]-arr[0])*min(n-1, m-1) + abs(arr.back()-arr[0])*(m*n-min(n, m));
    cout << max(op1, op2) << nln;
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