#include <bits/stdc++.h>

using namespace std;

#define int long long
#define nln '\n'

signed main() {
	// Fast IO
	cin.tie(0)->sync_with_stdio(0);
	// Input
	int n, t;
	cin >> n >> t;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;
	// Solve
	int cur = 0, left = 0, right = 0, max_length = 0;
	while (right < n) {
		if (cur + arr[right] <= t) {
			cur += arr[right];
			max_length = max(max_length, right - left + 1);
			right++;
		} else {
			cur -= arr[left];
			left++;
		}
	}
	// Output
	cout << max_length << nln;
	return 0;
}
