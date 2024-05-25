// Le Duc Phuc Long, 2024
// If you don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n;	cin >> n;
	vector<ll> arr(n);
	for (auto &v : arr)
		cin >> v;

	sort(arr.begin(), arr.end());


	auto answer = [&] (ll price) {
		// find the most expensive box cheaper than
		// "price"
		ll l = 0, r = n-1, ans = 0;
		while (l <= r) {
			ll mid = (l+r)/2;
			if (arr[mid] < price) {
				ans = mid+1;
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		return ans;
	};

	ll m;	cin >> m;
	while (m--) {
		ll price;	cin >> price;
		cout << answer(price) << nln;
	}

	return 0;
}