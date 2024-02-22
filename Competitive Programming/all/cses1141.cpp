#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define nln '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int n;	cin >> n;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;

	map<int, int> cnt;

	int left = 0, right = 0, max_length = 0;
	while (right < n) {
		if (cnt[arr[right]] == 0) {
			if (right - left + 1 > max_length)
				max_length = right - left + 1;
			cnt[arr[right++]]++;
		} else {
			cnt[arr[left++]]--;
		}
	}

	cout << max_length << nln;

    return 0;
}