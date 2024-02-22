#include <bits/stdc++.h>

using namespace std;

#define int long long
#define nln '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n, k;	cin >> n >> k;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;

	map<int, int> cnt;
	set<int> s;

	int left = 0, right = 0, ans = 0;
	while (right < n) {
		if (cnt[arr[right]] != 0 || s.size() + 1 <= k) {
			ans += right - left + 1;
			s.insert(arr[right]);
			cnt[arr[right++]]++;
		} else {
			cnt[arr[left]]--;
			if (cnt[arr[left]] == 0)
				s.erase(arr[left]);
			left++;
		}
	}

	cout << ans << nln;

    return 0;
}