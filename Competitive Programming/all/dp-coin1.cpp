#include<iostream>
#include<vector>
#include<algorithm>

#define long long long
#define nln '\n'

const long INF = 1e18;

using namespace std;

int main()
{
	long n, s;
	cin >> n >> s;
	vector<long> a(n+1, 0);
	for (long i = 1; i <= n; ++i)
	cin >> a[i];
	vector<long> dp(s+1, INF);
	dp[0] = 0;
	for (long i = 1; i <= s; ++i)
		for (long j = 1; j <= n; ++j)
			if (a[j] <= i)
				dp[i] = min(dp[i-a[j]]+1, dp[i]);

	vector<long> f(s+1, INF);
	f[0] = 0;
	for (long i = 1; i <= n; ++i)
		for (long j = 1; j <= s; ++j)
			if (a[i] <= j)
				f[j] = min(f[j], f[j-a[i]]+1);

	for (long i = 1; i <= s; ++i)
		cout << i << " : " << f[i] << " ~ " << dp[i] << nln;
	return 0;
}