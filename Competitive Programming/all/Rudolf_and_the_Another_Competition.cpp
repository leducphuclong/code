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

bool submit(lo time, lo h, lo &hour_m0, lo &point_m0, lo  &pen_m0) {
    if (hour_m0 + time <= h) {
        hour_m0 += time;
        point_m0++;
        pen_m0 += hour_m0;
        return true;
    }
    return false;
}

bool compare(const pair<lo, lo>& a, const pair<lo, lo>& b) {
    if (a.first != b.first)
        return a.first > b.first;
    return a.second <= b.second;
}

void solve() {
    // Input
    lo n, m, h;
    cin >> n >> m >> h;
    // Compute point and pen of member 0
    lo point_m0 = 0, pen_m0 = 0, hour_m0 = 0;
    vector<lo> mem0;
    for (lo i = 0; i < m; ++i) {
        lo time;
        cin >> time;
        mem0.push_back(time);
    }
    sort(mem0.begin(), mem0.end());
    for (auto time : mem0)
        if (submit(time, h, hour_m0, point_m0, pen_m0))
            continue;
    // compute rank for other player
    lo point, pen, hour, cnt = 1;
    for (lo i = 1; i < n; ++i) {
        vector<lo> tak(m);
        for (auto &i : tak)
            cin >> i;
        sort(tak.begin(), tak.end());

        point = 0, pen = 0, hour = 0;
        for (auto time : tak)
            if (submit(time, h, hour, point, pen))
                continue;
        if (point_m0 == point && pen_m0 == pen)
            ++cnt;
        else if (compare(make_pair(point_m0, pen_m0), make_pair(point, pen)))
            ++cnt;
    }
    cout << n-cnt+1 << nln;
}

int main(int argc, char* argv[]) {
    freopen("Rudolf_and_the_Another_Competition.inp", "r", stdin);
    freopen("Rudolf_and_the_Another_Competition.out", "w", stdout);
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