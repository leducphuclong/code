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

	ll min_price = LLONG_MAX, max_revenue = 0;
	for (int i = 0; i < n; ++i) {
		if (arr[i] * (n-i) > max_revenue) {
			max_revenue = arr[i] * (n-i);
			min_price = arr[i];
		}
	}

	cout << max_revenue << ' ' << min_price << endl;

	return 0;
}