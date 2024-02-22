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

	map<ll, ll> cnt;
	map<ll, bool> exist;

	ll l = 0, r = 0, ans = 0;
	while (r < n) {
		if (exist.size() + 1 <= k || exist.find(arr[r]) != exist.end()) {
			cnt[arr[r]]++;
			exist[arr[r]] = true;
			ans += r-l+1;
			r++;
		} else {
			cnt[arr[l]]--;
			if (cnt[arr[l]] == 0)
				exist.erase(arr[l]);
			l++;
		}
	}

	cout << ans << nln;

	return 0;
}