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

bool cmp(pair<lo, lo> a, pair<lo, lo> b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

void solve() {
    lo n;   cin >> n;
    vector<pair<lo, lo>> arr(n);
    for (auto &v : arr)
        cin >> v.first >> v.second;
    
    sort(arr.begin(), arr.end(), cmp);
    map<lo, vector<lo>> ftr;
    for (auto p : arr)
        if (ftr[p.first].size() < p.first)
            ftr[p.first].push_back(p.second);
    
    lo ans = 0;
    for (auto p : ftr)
        if (p.second.empty() == false)
            for (auto v : p.second)
                ans += v;
    
    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
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