#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	cin.tie(0)->sync_with_stdio(0);
	int arr[] = {0, 1, 2, 3, 4, 5, 4, 5};
	int n = sizeof(arr) / sizeof(int) - 1;
	int w = 10;

	vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

	dp[0][0] = 1;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= w; ++j)
			if (j >= arr[i])
				dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i]];
			else
				dp[i][j] = dp[i-1][j];

	cout << dp[n][w] << endl;

	return 0;
}