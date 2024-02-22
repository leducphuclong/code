#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define nln '\n'

const ll MOD = 1e9 + 7;

ll power(ll n, ll m) {
    ll res = 1;
    n %= MOD;
    while (m > 0) {
        if (m & 1)
            res *= n, res %= MOD;
        m >>= 1;
        n *= n, n %= MOD;
    }
    return res;
}

ll modulo_inverse(ll x) {
    return power(x, MOD-2);
}

ll multi(ll x, ll y) {
    return x % MOD * y % MOD;
}

ll devide(ll x, ll y) {
    return multi(x, modulo_inverse(y)) % MOD;
}

ll nCr(ll n, ll r) {
    if (r > n-r)
        return nCr(n, n-r);
    ll res = 1;
    while (r > 0)
        res = devide(multi(res, n--), r--);
    return res;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cout << nCr(20, 3) << nln;

    return 0;
}