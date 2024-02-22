#include <bits/stdc++.h>

using namespace std;

#define long long int
#define nln '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, x;
	cin >> n >> x;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;

	map<int, int> cnt;
	for (auto v : arr)
		cnt[v]++;

	sort(arr.begin(), arr.end());

	int left = 0, right = n-1, ans = 0;
	bool stop = false;
	while (left < right && !stop) {
		if (arr[left] + arr[right] > x) {
			right -= 1;
		} else if (arr[left] + arr[right] < x) {
			left += 1;
		} else {
			if (arr[left] == arr[right]) {
				ans += cnt[arr[left]]*(cnt[arr[left]]-1)/2;
				stop = true;
			} else
				ans += cnt[arr[right]];
			left += 1;
		}
		if (stop == true)
			break;
	}

	cout << ans << nln;

	return 0;
}
