#include<iostream>
#include<vector>
#include<algorithm>

#define long long long
#define nln '\n'

const long INF = 1e18;

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n;
	cin >> n;
	vector<long> a(n+1, 0);
	for (long i = 1; i <= n; ++i)
		cin >> a[i];
	vector<long> t(n, 0);
	for (long i = 1; i <= n-1; ++i)
		cin >> t[i];

	vector<long> dp(n+1, 0);
	dp[0] = 0;
	dp[1] = min(a[1], t[1]);

	for (long i = 2; i <= n; ++i)
		dp[i] = min(dp[i-1]+a[i], dp[i-2]+t[i-1]);

	cout << dp[n] << nln;

	return 0;
}