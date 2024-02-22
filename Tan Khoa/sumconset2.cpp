#include <bits/stdc++.h>

using namespace std;

#define int long long
#define nln '\n'''

signed main() {
	// Fast IO
	cin.tie(0)->sync_with_stdio(0);

	// Input
	int tc; cin >> tc;
	while (tc--) {
		string s;   cin >> s;
		int k;  cin >> k;
		int n = s.size();

		map<char, int> cnt;
		int left = 0, right = 0, ans = 0;
		while (...) {
			// TH1: Them duoc s[right]
			// C1: cnt[s[right]] + 1 <= k
			// C2: cnt[s[right]] < k
			if (...) {
				cnt[s[right]]...;
				ans += ...;
				...
			} else {
				// bo s[left] ra khoi doan
				...
			}
		}
	}
	
	return 0;
}
