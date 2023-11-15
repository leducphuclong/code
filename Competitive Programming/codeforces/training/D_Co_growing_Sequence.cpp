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

    vector<lo> res, ans;
    res.push_back(arr[0]), ans.push_back(0);

    for (lo i = 1; i < n; ++i) {
        // cout << "arr i: " << arr[i] << endl;
        // cout << "res.back: " << res.back() << endl;

        // cout << "arr i | res.back: " << (arr[i] | res.back()) << endl;
        // cout << "arr.back ^ arr i: " << ((arr[i] | res.back()) ^ arr[i]) << endl;        
        res.push_back(arr[i] | res.back()),
        ans.push_back(res.back() ^ arr[i]);
        // cout << "ans.back: " << ans.back() << endl;
        // cout << "res.back: " << res.back() << endl;

        // cout << endl;
        // getch();

    }
    
    for (auto v : ans)
        cout << v << ' ';
    cout << endl;
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
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