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

	multiset<int> s;
	s.insert(arr[0]);
	
	map<int, int> idx;

	int left = 0, right = 1, ans = 0;
	idx[arr[0]] = 0;

	while (right < n) {
		if (*s.rbegin() - *s.begin() == k) {
			ans += min(idx[*s.rbegin()], idx[*s.begin()]) - left + 1;
			idx[arr[right]] = right;
			s.insert(arr[right]);
			right += 1;
		} else if (*s.rbegin() - *s.begin() < k) {
			idx[arr[right]] = right;
			s.insert(arr[right]);
			right += 1;
		} else {
			s.erase(s.find(arr[left]));
			left += 1;
		}
	}

	
	if (*s.rbegin() - *s.begin() == k)
		ans += min(idx[*s.rbegin()], idx[*s.begin()]) - left + 1;

	cout << ans << nln;

	return 0;
}
