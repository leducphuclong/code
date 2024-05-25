// Le Duc Phuc Long, 2024
// You don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	vector<ll> arr;
	ll x;
	while (cin >> x) {
		arr.push_back(x);
	}

	ll ans = 1;
	ll cnt = 0;
	for (auto v : arr)
		if (v) {
			ans *= v;
			cnt++;
		}

	cout << ((cnt >= 2) ? ans : 0) << nln;

	return 0;
}