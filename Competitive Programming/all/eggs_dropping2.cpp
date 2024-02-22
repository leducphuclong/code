#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

#define int long long
#define nln '\n'

signed main() {
	// cin.tie(0)->sync_with_stdio(0);
	int n; cin >> n;
	int dp[n+1][3];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= 2; ++j)
			dp[i][j] = i;

	// dp[1][1] = 1;
	// dp[1][2] = 1;
	// dp[2][2] = 2;
	// dp[2][2] = 2;
	
	for (int i = 2; i <= n; ++i)
		for (int j = 1; j < i; ++j) {
			// cout << "floor: " << j << nln;

			dp[i][2] = min(dp[i][2], max(dp[j-1][1], dp[i-j][2]) + 1);
			// cout << j-1 << " ~ " << 1 << " : " << dp[j-1][1] << nln;
			// cout << i-j << " ~ " << 2 << " : " << dp[i-j][2] << nln;
			// cout << i << " ~ " << 2 << " : " << dp[i][2] << nln;
			// cout << nln;
			// getch();
		}


	cout << dp[n][2] << nln;

	return 0;
}