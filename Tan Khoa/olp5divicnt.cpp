// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>  // NOLINT
// #include <conio.h>

// Namespace
using namespace std;  // NOLINT

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t ll;

// Constant
const ll LIM = int(1e6)+5;

// Declare global variables.
vector<pair<ll, ll>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

// End of global variable declaration.

void precompute() {
}

ll f(ll n, const vector<ll>& prm) {
	ll i = 0, res = 1;
	while (n > 1) {
		ll val = prm[i];
		if (n % val == 0) {
			res *= val;
			while (n % val == 0)
				n /= val;
		} else {
			i++;
		}
	}
	return res;
}

void solve() {
	auto f_lambda = [](ll n, const vector<ll>& prm) -> ll {
    ll i = 0, res = 1;
    while (n > 1) {
        ll val = prm[i];
        if (n % val == 0) {
            res *= val;
            while (n % val == 0)
                n /= val;
        } else {
            i++;
        }
    }
    return res;
};
	ll n, a, b;		cin >> n >> a >> b;
	ll d[n+1];	fill(d, d + n + 1, 2);
	d[0] = 0, d[1] = 1;
	for (ll i = 2; i*i < LIM; ++i) {
		for (ll j = i*i; j < LIM; j += i)
			d[j] += 2;
		d[i*i] -= 1;
	}
	vector<ll> prm;
	for (ll i = 2; i < LIM; ++i)
		if (d[i] == 2)
			prm.push_back(i);

	ll cnt = 0;
	for (ll i = 1; i <= LIM; ++i)
		if (i*f(i, prm) <= n && a <= d[i] && d[i] <= b)
			cnt++;
	cout << cnt << nln;

}

int main(int argc, char* argv[]) {
	#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
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