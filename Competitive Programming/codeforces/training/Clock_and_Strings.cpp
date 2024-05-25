// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>
// #include <conio.h>

// Namespace
using namespace std;

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t ll;

// Constant

// Declare global variables.
vector<pair<ll, ll>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
    
}

bool mid(ll a, ll b, ll c) {
    if (a < b && b < c) return true;
    return false;
}

void solve() {
    ll a, b, c, d;  cin >> a >> b >> c >> d;
    if (max(a, b) > max(c, d)) {
        if (mid(min(a, b), max(c, d), max(a, b))
        && !mid(min(a, b), min(c, d), max(a, b))) {
            cout << "YES" << nln;
        } else {
            cout << "NO" << nln;
        }
    } else {
        if (mid(min(c, d), max(a, b), max(c, d))
        && !mid(min(c, d), min(a, b), max(c, d))) {
            cout << "YES" << nln;
        } else {
            cout << "NO" << nln;
        }
    }
}

int main(int argc, char* argv[]) {
    #ifndef ONLINE_JUDGE
    //freopen("in", "r", stdin);
    #endif // ONLINE_JUDGE
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