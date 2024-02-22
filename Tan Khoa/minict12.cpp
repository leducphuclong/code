#include <bits/stdc++.h>

#define int long long
#define nln '\n'

using namespace std;

struct twoPointers {
	int left, right;
};

int length(twoPointers cur) {
	return cur.right - cur.left + 1;
}

void compare(twoPointers cur, twoPointers &ans) {
	if (length(cur) > length(ans))
		ans = cur;
}

signed main() {
	// Fast IO
	cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);

	// Input
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (auto &v : arr)
		cin >> v;

	// Solve	
	map<int, int> cnt;

	set<int> sav;

	twoPointers cur = {0, 0}, ans = {0, 0};

	while (cur.right < n) {
		if (sav.size() + 1 <= k || sav.find(arr[cur.right]) != sav.end()) {
			compare(cur, ans);
			cnt[arr[cur.right]]++;
			sav.insert(arr[cur.right]);
			cur.right++;
		} else {
			cnt[arr[cur.left]]--;
			if (cnt[arr[cur.left]] == 0)
				sav.erase(arr[cur.left]);
			cur.left++;
		}
	}

	cout << ans.left + 1 << ' ' << ans.right + 1 << nln;

	return 0;
}
