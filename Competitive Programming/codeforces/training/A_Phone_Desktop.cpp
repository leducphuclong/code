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

void solve() {
    ll x, y;    cin >> x >> y;

    ll sy = ceil(y / 2.0);
    x -= 7*sy;
    if (y % 2 == 1)
        x -= 4;
    ll sx;
    if (x <= 0)
        sx = 0;
    else
        sx = ceil(x / 15.0);


    ll ans = sy + sx;

    cout << ans << nln;


    
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