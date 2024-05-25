// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

#include <bits/stdc++.h>  // NOLINT

using namespace std;  // NOLINT

#define nln '\n'

typedef int64_t ll;

ll fastmul(ll a, ll b, ll p) {
	ll res = 0;
	a %= p;
	while (b) {
		if (b & 1)
			res += a, res %= p;
		a += a, a %= p;
		b >>= 1;
	}
	return res;
}

ll fastpow(ll a, ll n, ll p) {
	ll res = 1;
	a %= p;
	while (n) {
		if (n & 1)
			res *= a, res %= p;
		a *= a, a %= p;
		n >>= 1;
	}
	return res;
}

bool single_test(ll a, ll n, ll exp) {
    ll tmp = fastpow(a, exp, n);
    if (tmp == 1)
        return true;
    while (exp != n - 1) {
        if (tmp == n - 1)
            return true;
        exp <<= 1;
        tmp = fastmul(tmp, tmp, n);
    }
    return false;
}

bool miller_rabin(ll n, ll t = 5) {
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0)
        return false;

    ll exp = n - 1;
    while (!(exp & 1))
        exp >>= 1;

	for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
        if (n == a)
            return true;
        if (single_test(a, n, exp) == false)
            return false;
    }
    return true;
}

ll palinize(ll n) {
	ll res = n; 
	n /= 10;
	while (n > 0)
		res = res*10 + n % 10, n /= 10;
	return res;
}

void solve() {
	ll n, cnt = 0, MAX = ll(1e5);	cin >> n;

	cnt += (11  < n);

	for (ll i = 10; i < MAX; ++i) {
		ll palin = palinize(i);
		if (palin >= n)
			break;
		cnt += miller_rabin(palin);
	}

	cout << cnt << nln;
}

int main(int argc, char* argv[]) {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);

    freopen("NTDX.INP", "r", stdin);
    freopen("NTDX.OUT", "w", stdout);

    solve();
        
    cerr << "It's ok Long, Good for now !!" << nln;
    return 0;
}