#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;



int main(int argc, char const *argv[])
{
	cin.tie(0)->sync_with_stdio(0);
	ll n;	cin >> n;
	ll i = (n*n)/2 + 1;

	auto check = [&] (ll x) {
		ll ans = 0;
		for (int i = 1; i <= n; ++i)
			ans += min(n, x/i);
		return ans;
	};


	// cout << check(3) << nln;

	ll l = 1, r = n*n, ans = -1;
	while (l <= r) {
		ll m = (l+r)/2;
		if (check(m) >= i) {
			ans = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}	

	cout << ans << nln;

	return 0;
}