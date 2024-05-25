#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

class Solution {
public:
    int countSubstrings(string s, string t) {        
		int n = s.size(), m = t.size();
		int dp[n+1][m+1], dpd[n+1][m+1];

		memset(dp, 0, sizeof dp);
		memset(dpd, 0, sizeof dpd);

		int res = 0;

		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if (s[i-1] == t[j-1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
					dpd[i][j] = dpd[i-1][j-1];
				} else {
					dp[i][j] = 0;
					dpd[i][j] = dp[i-1][j-1] + 1;
				}
				res += dpd[i][j];
			}

		return res;
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s, t;
	cin >> s >> t;

	Solution S;

	cout << S.countSubstrings(s, t) << nln;

	return 0;
}