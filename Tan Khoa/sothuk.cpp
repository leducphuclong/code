#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

ll bruteforce(ll n, ll k) {
	if (n == 1)
		return 0;
	if (k == 1)
		return 1;
	ll i = 0, d = 0;
	while (d < k) {
		i += 1;
		if (i % n != 0) {
			// cout << i << ' ';
			d += 1;
		}
	}
	// cout << nln;
	return i;
}

ll solve(ll n, ll k) {
	if (n == 1)
		return 0;
	if (k == 1)
		return 1;
	ll res = k;
	while (k >= n) {
		res += k / n;
		k = k%n + k/n; 
	}
	return res;
}

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	ll n = 3, k = 2;
	for (ll n = 1; n <= 100; ++n)
		for (ll k = 1; k <= 1000; ++k) {
			cout << n << " ~ " << k << nln;
			if (bruteforce(n, k) != solve(n, k)) {
				cout << "WA: " << n << " " << k << nln;
				cin.get();
			}
		}
	cout << "AC" << nln;
	// cout << bruteforce(n, k) << ' ' << solve(n, k) << nln;
	
	return 0;
}