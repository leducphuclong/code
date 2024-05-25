#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, k;	cin >> n >> k;
	ll arr[n];
	for (auto& v : arr)
		cin >> v;

	sort(arr, arr+n, greater<int>());

	ll ans = 0;
	for (int i = 0; i < n-1; ++i) {
		if (k <= 0)
			break;
		ll t = (arr[i] - arr[i+1])*(i+1);
		ans += min(t, k)*arr[i];
		k -= min(t, k);
	}

	if (k > 0)
		ans += k*arr[n-1];

	cout << ans << nln;

	return 0;
}