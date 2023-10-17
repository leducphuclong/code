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
    string s;   cin >> s;
    lo p;   cin >> p;
    /* 
    1. Sort s in ascending order (attached index)
    2. Pop back until sum <= n
    3. Sort according to index to output
     */

    vector<pair<char, int>> vp1;
    lo sum = 0, n = s.size();
    for (lo i = 0; i < n; ++i) {
        sum += (s[i]-'a'+1);
        vp1.push_back({(s[i]-'a'+1), i});
    }

    sort(vp1.begin(), vp1.end());

    while (sum > p) {
        sum -= vp1.back().first;
        vp1.pop_back();
    }

    vector<lo> idx;
    for (auto p : vp1)
        idx.push_back(p.second);

    sort(idx.begin(), idx.end());
    for (auto i : idx)
        cout << s[i];
    cout << nln;
}

int main(int argc, char* argv[]) {
    // freopen("in", "r", stdin);
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