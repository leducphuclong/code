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

lo sum_sequence(lo l, lo r, lo s) {
    return (l+r)*((r-l)/s+1)/2ll;
}

lo __lcm(lo x, lo y) {
    return x*y/__gcd(x, y);
}

void solve() {
    lo n, x, y; cin >> n >> x >> y;
    lo q_c = n/__lcm(x, y), q_x = n/x - q_c, q_y = n/y - q_c; 
    cout << sum_sequence(n-q_x+1, n, 1) - sum_sequence(1, q_y, 1) << nln;
    // cout << "OK" << nln;
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