#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

class Solution {
public:
	bool stoneGame(const vector<int>& piles) {
		int n = piles.size(); int dp[n+2][n+2];
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n-j+1; ++j) {
				int l = j, r = j+i-1;
				if ((r-l) & 1)  // Alice's turn
					dp[l][r] = max(dp[l+1][r] + piles[l-1], dp[l][r-1] + piles[r-1]);
				else  // Bob's turn
					dp[l][r] = max(dp[l+1][r] - piles[l-1], dp[l][r-1] - piles[r-1]);
			}
		}
		return dp[1][n] > 0;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;	cin >> n;
	vector<int> piles(n);
	for (auto &v : piles)
		cin >> v;

	Solution S;
	cout << S.stoneGame(piles);

	return 0;
}