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
    ll r;   cin >> r;

    auto largestSquare = [&](ll x) {
        if (sqrt(x) == ll(sqrt(x)))
            return ll(sqrt(x)) - 1;
        return ll(sqrt(x));
    };

    auto count = [&](ll r) {
        ll ans = 0;
        for (ll i = 0; i <= r; ++i)
            ans += largestSquare(r*r - i*i);
        return ans*4;
    };

    cout << count(r+1) - count(r) << nln;
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