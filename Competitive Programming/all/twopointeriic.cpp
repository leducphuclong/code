#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define nln '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, s;	cin >> n >> s;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;

	int left = 0, right = 0, ans = 0, t = 0;
	while (right < n) {
		if (t + arr[right] <= s) {
			ans += right - left + 1;
			t += arr[right++];
		} else {
			t -= arr[left++];
		}
	}

	cout << ans << nln;

    return 0;
}