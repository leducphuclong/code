// Le Duc Phuc Long, 2024
// You don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	for (auto &v : arr)
		cin >> v;
	sort(arr.begin(), arr.end());
	// for (auto v : arr)
	// 	cout << v << ' ';
	// cout << nln;

	auto binarySearch = [&](ll x) {
		// cout << "x: " << x << nln;
		ll l = 0, r = n-1;
		while (l <= r) {
			ll m = (l+r)/2;
			// cout << arr[m] << nln;
			if (arr[m] == x) {
				return true;
			}
			else if (arr[m] < x) {
				l = m+1;
			} else {
				r = m-1;
			}
		}
		return false;
	};

	while (k--) {
		ll x;	cin >> x;
		if (binarySearch(x)) {
			cout << "YES" << nln;
		} else {
			cout << "NO" << nln;
		}
	}

	return 0;
}