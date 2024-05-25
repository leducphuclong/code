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
    ll n;   cin >> n;
    vector<ll> arr(n);
    for (auto &v : arr)
        cin >> v;
    
    map<pair<pair<ll, ll>, ll>, pair<ll, map<ll, ll>>> rec;
    // first is to save total of numbers 
    // seocnd to save the frequency of each number
    for (ll i = 0; i < n-2; ++i) {
        ll a = arr[i], b = arr[i+1], c = arr[i+2];
        rec[{{a, b}, 1}].first += 1;
        rec[{{a, b}, 1}].second[c] += 1;

        rec[{{a, c}, 2}].first += 1;
        rec[{{a, c}, 2}].second[b] += 1;

        rec[{{b, c}, 3}].first += 1;
        rec[{{b, c}, 3}].second[a] += 1;
    }

    // cout << rec[{{3, 2}, 2}].first << nln;
    // cout << rec[{{3, 2}, 2}].second[2] << nln;

    ll ans = 0;
    for (ll i = 0; i < n-2; ++i) {
        ll a = arr[i], b = arr[i+1], c = arr[i+2];
        // cout << a << " ~ " << b << nln;
        ans += rec[{{a, b}, 1}].first - rec[{{a, b}, 1}].second[c];
        // cout << "(1): " << rec[{{a, b}, 1}].first - rec[{{a, b}, 1}].second[c] << nln;

        // cout << a << " ~ " << c << nln;
        ans += rec[{{a, c}, 2}].first - rec[{{a, c}, 2}].second[b];
        // cout << "(2): " << rec[{{a, c}, 2}].first - rec[{{a, c}, 2}].second[b] << nln;

        // cout << b << " ~ " << c << nln;
        ans += rec[{{b, c}, 3}].first - rec[{{b, c}, 3}].second[a];
        // cout << "(3): " << rec[{{b, c}, 3}].first - rec[{{b, c}, 3}].second[a] << nln;

        // cout << nln;
    }

    cout << ans/2 << nln;
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