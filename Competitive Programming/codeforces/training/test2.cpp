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
    lo n, m;   cin >> n >> m;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;
    vector<lo> brr(n);
    for (auto &v : brr)
        cin >> v;
    
    vector<pair<lo, lo>> in4;
    for (lo i = 0; i < n; i++)
        in4.push_back({arr[i], brr[i]});

    auto cmp = [&] (pair<lo, lo> l, pair<lo, lo> r) {
        return l.first*r.second < r.first*l.second;
    };

    sort(in4.begin(), in4.end(), cmp);

    for (auto v : in4)
        cout << v.first << ' ' << v.second << endl;
    cout << endl;

    lo take = 0, cost = 0;
    while (!in4.empty()) {
        take += in4.back().first;
        cost += in4.back().second;
        in4.pop_back();
        if (take >= m)
            break;
    }
    if (take >= m)
        cout << cost << endl;
    else
        cout << -1  << endl;
}

int main(int argc, char* argv[]) {
    freopen("in", "r", stdin);
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