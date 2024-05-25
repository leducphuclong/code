// Le Duc Phuc Long, 2024

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

ll cal(ll n, ll m, ll value) {
	ll res = 0;
	for (ll i = 1; i <= n; ++i) {
		res += min(m, value / i);
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m, k;	cin >> n >> m >> k;
	ll left = 1, right = n*m, ans = 0;
	while (left <= right) {
		ll mid = (left + right)/2;
		if (cal(n, m, mid) >= k) {
			ans = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	cout << ans;

	return 0;
}