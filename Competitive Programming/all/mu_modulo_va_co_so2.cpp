#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
#define nln '\n'

// Function to calculate fast exponentiation
ll fastpow(ll n, ll m, ll p) {
    ll res = 1;
    while (m > 0) {
        if (m & 1) {
            res = (res * n) % p;
        }
        m /= 2;
        n = (n % p * n % p) % p;
        
    }
    return res;
}

signed main() {
    // IO
    cin.tie(0)->sync_with_stdio(0);
    ll x, y, n, m, k;
    cin >> x >> y >> n >> m >> k;

    vector<ll> a(n), b(m);
    bool chk_a = false, chk_b = false;
    for (auto &v : a) { 
        cin >> v;
        if (v)
            chk_a = true;
    }   
    for (auto &v : b) {
        cin >> v;
        if (v)
            chk_b = true;
    }

    // Special case
    if (!chk_a && !chk_b) {
        cout << 1 << nln;
        return 0;
    }

    if (!chk_a) {
        cout << 0 << nln;
        return 0;
    }

    if (!chk_b) {
        cout << 1 << nln;
        return 0;
    }

    // Calculate x^i
    vector<ll> xp(1, 1);
    for (ll i = 1; i < n; ++i)
        xp.push_back(xp.back()*x%k);

    // Calculate ta
    ll ta = 0;
    for (ll i = 0; i < n; ++i) {
        ta += (a[i]*xp[i] % k);
        ta %= k;
    }

    // Calculate tmp
    vector<ll> tmp(m, 1);
    for (ll i = 0; i < m; ++i) {
        tmp[i] = fastpow(ta, b[i], k);
    }

    // Calculate p
    vector<ll> p(m + 1, 1);
    for (ll i = m - 1; i >= 0; --i) {
        p[i] = (p[i + 1] * tmp[i]) % k;
    }

    // Calculate ans
    ll ans = 1;
    for (ll i = 0; i < m; ++i) {
        ans = (ans * p[i]) % k;
    }

    cout << ans << endl;
    cerr << "Program finished" << '\n';

    return 0;
}

// WA: 3->9, 14, 19