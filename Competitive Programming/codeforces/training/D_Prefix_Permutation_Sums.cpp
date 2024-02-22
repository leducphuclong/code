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

vector<lo> prefixsum2arr(vector<lo> arr) {
    vector<lo> res = {arr[0]};
    int n = arr.size();
    for (int i = 1; i < n; ++i)
        res.push_back(arr[i]-arr[i-1]);
    return res;
}

bool is_permutation(vector<lo> arr, int n) {
    for (auto v : arr)
        if (v < 1 || v > n)
            return false;
    return set(arr.begin(), arr.end()).size() == n;
}

void solve() {
    lo n;  cin >> n;
    vector<lo> arr;
    for (lo i = 0; i < n-1; ++i) {
        lo x;   cin >> x;
        arr.push_back(x);
    }

    if (arr.back() != n*(n+1)/2) {
        arr.push_back(n*(n+1)/2);
        vector<lo> org = prefixsum2arr(arr);
        if (is_permutation(org, n))
            cout << "YES" << nln;
        else
            cout << "NO" << nln;
        return;
    }
    
    vector<bool> mark(n+1, false);
    vector<lo> org = prefixsum2arr(arr);
    for (auto v : org)
        if (v >= 1 && v <= n)
            mark[v] = true;
    
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        cnt += mark[i] == false;

    if (cnt == 2)
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