// Copyright (c) 2023, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Define
#define nln '\n'

// Typedef and Struct
typedef int lo;

// Constant

// Namespace
using namespace std;  // NOLINT

// Declare global variables.
// End of global variable declaration.

void precompute() {
}

void submit(lo time, lo h, lo &hour_m0, lo &point_m0, lo  &pen_m0) {
    if (hour_m0 + time <= h) {
        hour_m0 += time;
        point_m0++;
        pen_m0 += hour_m0;
    }
}

bool compare(const pair<lo, lo>& a, const pair<lo, lo>& b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second >= b.second;
}

void solve() {
    // Input
    lo n, m, h;
    cin >> n >> m >> h;
    vector<vector<lo>> inf;
    for (lo i = 0; i < n; ++i) {
        vector<lo> tak(m);
        for (auto &i : tak)
            cin >> i;
        sort(tak.begin(), tak.end());
        inf.push_back(tak);
    }
    // Compute point and pen of member 0
    vector<pair<lo, lo>> rank;
    lo point_m0 = 0, pen_m0 = 0, hour_m0 = 0;
    for (lo i = 0; i < m; ++i)
        submit(inf[0][i], h, hour_m0, point_m0, pen_m0);
    cout << "m0: " << point_m0 << " ~ " << pen_m0 << nln;
    
    // compute rank for other player
    lo point = 0, pen = 0, hour = 0;
    for (lo i = 1; i < n; ++i) {
        point = 0, pen = 0, hour = 0;
        for (lo j = 0; j < m; ++j)
            submit(inf[i][j], h, hour, point, pen);
        rank.push_back({point, pen});
    }
    // find the rank of member 0
    sort(rank.begin(), rank.end(), compare);
    lo cnt = 0;
    for (lo i = 0; i < (lo)rank.size(); ++i) {
        if (rank[i].first < point_m0) {
            cout << "m: " << point << " ~ " << pen << nln;
            ++cnt;
            continue;
        } else if (rank[i].first == point_m0) {
            if (rank[i].second >= pen_m0) {
                cout << "m: " << point << " ~ " << pen << nln;
                ++cnt;
                continue;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    cout << n-cnt << nln;
}

int main(int argc, char* argv[]) {
    freopen("c.inp", "r", stdin);
    freopen("c.ans", "w", stdout);
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    int T = 1;
    cin >> T;
    precompute();
    while (T--) {
        solve();
    }
    // cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}
