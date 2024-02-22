#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

#define int long long
#define nln '\n'

signed main() {
	// cin.tie(0)->sync_with_stdio(0);
	freopen("in", "r", stdin);
	int n, k; cin >> n >> k;
	int dp[n+1][k+1];
	for (int i = 0; i <= n; ++i)
		for (int j = 1; j <= k; ++j)
			dp[i][j] = i;

	for (int f = 2; f <= n; ++f)
		for (int e = 2; e <= k; ++e)
			for (int l = 1; l < f; ++l)
				dp[f][e] = min(dp[f][e], max(dp[l-1][e-1], dp[f-l][e])+1);


	cout << dp[n][k] << nln;

	return 0;
}