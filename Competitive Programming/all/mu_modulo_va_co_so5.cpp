#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
#define nln '\n'

// Function to calculate fast exponentiation
ll fastpow(ll n, ll m, ll p) {
    n %= p;
    ll res = 1;
    while (m > 0) {
        if (m & 1) {
            res = (res * n) % p;
        }
        m /= 2;
        n *= n;
        n %= p;
        
    }
    return res;
}

signed main() {
    // IO
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);

    ll x, y, n, m, k;
    cin >> x >> y >> n >> m >> k;

    vector<ll> a, b;
    bool chk_a = false, chk_b = false;

    ll ta = 0, p = 1;
    for (ll i = 0; i < n; ++i) {
        ll v;
        cin >> v;
        if (v != 0)
            chk_a = true;
        a.push_back(v);

        ta += (a[i]*p % k);
        ta %= k;
        p *= x, p %= k;
    }

    for (ll i = 0; i < m; ++i) {
        ll v;
        cin >> v;
        if (v)
            chk_b = true;
        b.push_back(v);
    }
    
    // // Special case
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
    
    // Calculate ans

    ll ans = 1, fac = 1;
    for (ll i = m-1; i >= 1; --i) {
        ans *= fastpow(ta, b[i], k), ans %= k;
        ans = fastpow(ans, y, k);
    }
    ans *= fastpow(ta, b[0], k), ans %= k;

    cout << ans << endl;
    // cerr << "OK" << nln;
    return 0;
}

// TLE: 8->9
// We still couldn't handle the special case