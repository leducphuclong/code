// Le Duc Phuc Long, 2024
// You don't think twice, you code twice

#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

typedef long long ll;

int main(int argc, char* argv[]) {
	cin.tie(0)->sync_with_stdio(0);
	ll n, k;		cin >> n >> k;
	vector<ll> arr(n);
	map<ll, ll> cnt;
	for (auto &v: arr) {
		cin >> v;
		cnt[v]++;
	}

	sort(arr.begin(), arr.end());
	
	ll l = 0, r = n-1, ans = 0;
	while (l < r) {
		if (arr[l] + arr[r] < k) {
			l++;
		} else if (arr[l] + arr[r] > k) {
			r--;
		} else {
			if (arr[l] == arr[r]) {
				ans += cnt[arr[l]]*(cnt[arr[l]]-1)/2;
				break;
			} else {
				ans += cnt[arr[r]];
				l++;
			}
		}
	}

	cout << ans << nln;

	return 0;
}