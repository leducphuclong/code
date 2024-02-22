#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll n;	cin >> n;
	ll arr[n+1];
	for (ll i = 1; i <= n; ++i)
		cin >> arr[i];

	ll left[n+1];
	for (int i = 0; i <= n; ++i)
		left[i] = INT_MIN;
	for (ll i = 3; i <= n; i += 1)
		left[i] = arr[i] + arr[i-1] + arr[i-2] + max(0ll, left[i-3]);
	for (int i = 1; i <= n; ++i)
		left[i] = max(left[i], left[i-1]); 
	// for (int i = 1; i <= n; ++i)
		// cout << i << " : " << left[i] << nln;

	ll right[n+2];
	for (ll i = 0; i <= n+1; ++i)
		right[i] = INT_MIN;
	for (ll i = n-2; i >= 1; i -= 1)
		right[i] = arr[i] + arr[i+1] + arr[i+2] + max(0ll, right[i+3]);
	for (int i = n; i >= 1; i--)
		right[i] = max(right[i], right[i+1]);
	// cout << nln;
	// for (int i = 1; i <= n; ++i)
		// cout << i << " : " << right[i] << nln;

	ll ans = INT_MIN;
	for (ll i = 2; i <= n; ++i) {
		ans = max(ans, left[i-1] + right[i]);
	}

	cout << ans << nln;

	return 0;
}