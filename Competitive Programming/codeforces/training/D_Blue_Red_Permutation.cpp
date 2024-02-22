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
    lo n;       cin >>n;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;

    string col; cin >> col;
    vector<lo> blue, red;
    for (lo i = 0; i < n; ++i)
        ((col[i] == 'B') ? blue : red).push_back(arr[i]);
    
    bool chk = true;
    
    sort(blue.begin(), blue.end());
    for (lo i = 0; i < blue.size(); ++i)
        if (blue[i] < i+1)
            chk = false;
    
    sort(red.rbegin(), red.rend());
    for (lo i = 0; i < red.size(); ++i)
        if (red[i] > n-i)
            chk = false;

    cout << (chk ? "YES" : "NO") << endl;
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