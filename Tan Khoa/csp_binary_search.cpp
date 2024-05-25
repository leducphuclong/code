// Le Duc Phuc Long 2024
// If you don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

ll binarySearch(ll left, ll right, vector<ll> arr, ll value) {	
	// this function return the index of largest element in
	// vector arr that less or equal than value
	ll ans = -1;
	while (left <= right) {
		ll mid = (left + right)/2;
		if (arr[mid] <= value) {
			ans = mid;
			left = mid+1;
		} else {
			right = mid-1;
		}
	}
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m;	cin >> n >> m;
	vector<ll> arr(n);
	for (auto &v : arr)
		cin >> v;

	sort(arr.begin(), arr.end());

	if (arr[n-2] + arr[n-1] < m) {
		cout << 0 << nln;
		return 0;
	}



	ll ans = 0;
	for (ll i = 0; i < n-1; ++i) {
		if (arr[i] >= m)
			break;
		ll j = binarySearch(i+1, n-1, arr, m - arr[i]);
		if (j != -1)
			ans += (j-i);
	}

	cout << ans << nln;

	return 0;
}