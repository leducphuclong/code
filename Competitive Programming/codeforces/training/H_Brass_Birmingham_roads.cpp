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
struct player {
    lo No_buildings, No_road;
    vector<lo> buildings;
    vector<pair<lo, lo>> roads;
};


// Constant

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void solve() {
    lo n;
    cin >> n;
    player p[4];
    for (lo k = 0; k < 4; ++k) {
        cin >> p[k].No_buildings >> p[k].No_road;
        for (lo i = 0; i < p[k].No_buildings; ++i) {
            lo tmp;  cin >> tmp;
            p[k].buildings.push_back(tmp);
        }
        for (lo i = 0; i < p[k].No_road; ++i) {
            lo u, v;  cin >> u >> v;
            p[k].roads.push_back({u, v});
        }
    }
    map<lo, lo> city;
    for (lo k = 0; k < 4; ++k) {
        for (auto v : p[k].buildings)
            city[v]++;
    }
    vector<lo> ans(4, 0);
    for (lo k = 0; k < 4; ++k) {
        for (auto v : p[k].roads)
            ans[k] += city[v.first]+city[v.second];
    }
    for (auto v : ans)
        cout << v << ' ';
    cout << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    // cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}