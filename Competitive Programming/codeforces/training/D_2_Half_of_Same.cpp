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

set<lo> dvs_of(lo n) {
    set<lo> dvs;
    for (lo i = 1; i*i <= n; ++i)
        if (n % i == 0)
            dvs.insert(i), dvs.insert(n/i);
    return dvs;
}

void solve() {
    lo n;   cin >> n;
    vector<lo> arr(n);
    for (auto &v : arr)
        cin >> v;
    
    lo ans = 1;
    for (auto v : arr) {
        vector<lo> dif;
        lo same_cnt = 0;
        for (lo v2 : arr)
            if (v2 > v)
                dif.push_back(v2-v);
            else if (v2 == v)
                same_cnt++;
        if (same_cnt >= n/2)
            ans = LLONG_MAX;

        map<lo, lo> cnt;
        for (auto d : dif)
            for (auto dvs : dvs_of(d))
                cnt[dvs]++;
        
        for (auto p : cnt)
            if (p.second+same_cnt >= n/2)
                ans = max(ans, p.first);
    }

    cout << (ans == LLONG_MAX ? -1 : ans) << endl;
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