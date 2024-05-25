// Le Duc Phuc Long, 2024

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'



int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, k;	cin >> n >> k;
	vector<ll> arr(n);
	for (auto &v : arr)
		cin >> v;

	sort(arr.begin(), arr.end());

	auto girlfriends = [&] (ll diff) {
		ll cnt = 0;
		for (ll i = 0; i < n-1; ++i)
			if (arr[i+1] - arr[i] <= diff)
				cnt++, i++;
		return cnt;
	};

	ll l = 0, r = int(1e9), ans = -1;
	while (l <= r) {
		ll mid = (l+r)/2; // guess diff
		if (girlfriends(mid) >= k) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	cout << ans << nln;

	return 0;
}