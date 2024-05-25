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

ll enough(const ll& x) {
    return floor(log(x)/log(2));
}

ll rem(const ll& x) {
    ll y = 1;
    bool in = false;
    while (y*2 <= x) {
        y *= 2;
        in = true;
    }
    if (in)
        return x - y;
    else
        return 1;
}

ll full(const ll& x)  {
    if (x == 1)
        return 2;
    ll y = 1;
    while (y < x) {
        y *= 2;
    }
    return y;
}

void solve() {
    // Input
    ll n;   cin >>n;
    vector<ll> arr(n);
    for (auto& v : arr)
        cin >> v;    
    // Solve
    map<ll, ll> cnt;
    for (auto& v : arr)
        cnt[v]++;
    
    ll ans = 0;
    for (const auto& v : arr) {
        bool check = false;
        for (ll i = 0; i < 31; ++i) {
            ll p = 1 << i;
            if (p > v && cnt[p-v] > 0) {
                if (v == p-v) {
                    if (cnt[p-v] > 1)
                        check = true;
                } else {
                    check = true;
                }
            }
        }
        ans += check == false;
    }
    cout << ans << nln;
}

int main(int argc, char* argv[]) {
    #ifndef ONLINE_JUDGE
    //freopen("in", "r", stdin);
    #endif // ONLINE_JUDGE
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