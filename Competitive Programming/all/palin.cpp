#include<iostream>
#include<algorithm>
#include<vector>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1, nln);
	s2 = s1;
	reverse(s2.begin(), s2.end());



	long n = s1.size(), m = s2.size();
	s1 = ' ' + s1;
	s2 = ' ' + s2;

	vector<vector<long>> dp(n+1);
	for (auto &i : dp)
		i.resize(m+1, 0);

	for (long i = 1; i <= n; ++i)
		for (long j = 1; j <= m; ++j)
			if (s1[i] == s2[j])
				dp[i][j] = dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

	long i = n, j = m;
	string res = "";
	while (i > 0 && j > 0){
		if (s1[i] == s2[j]){
			res += s1[i];
			--i, --j;
		}
		else{
			if (dp[i-1][j] > dp[i][j-1])
				--i;
			else
				--j;
		}
	}
	cout << dp[n][m] << nln;
	reverse(res.begin(), res.end());
	cout << res << nln;
	return 0;
}