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
typedef long double db;

// Constant

// Declare global variables.
vector<pair<lo, lo>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
}

lo sqr(lo x) {
    return x*x;
}

db distance(lo x1, lo y1, lo x2, lo y2) {
    return sqrt(sqr(x1-x2) + sqr(y1-y2));
}

void solve() {
    lo px, py;     cin >> px >> py;
    lo ax, ay;     cin >> ax >> ay;
    lo bx, by;     cin >> bx >> by;
    // First Case
    // The lantern A cover both house and position
    db ans = max(distance(ax, ay, 0, 0), distance(ax, ay, px, py));
    // Second Case
    // The lantern B cover both house and position
    ans = min(ans, max(distance(bx, by, 0, 0), distance(bx, by, px, py)));
    // Third Case
    // Each lantern will choose to cover nearer house or position
    // After that, they have to intersect others.
    db dist_a, dist_b;

    if (distance(ax, ay, 0, 0) < distance(bx, by, 0, 0)) {
        dist_a = distance(ax, ay, 0, 0);
        dist_b = distance(bx, by, px, py);
    } else {
        dist_b = distance(bx, by, 0, 0);
        dist_a = distance(ax, ay, px, py);
    }
    long double cover_b_and_a = max(dist_a, dist_b);
    long double inter = distance(ax, ay, bx, by)/2.0;
    long double case3 = max(cover_b_and_a, inter);
    // Find optimal way
    long double res = min(ans, case3);
    cout << setprecision(10) << fixed << res << nln;
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