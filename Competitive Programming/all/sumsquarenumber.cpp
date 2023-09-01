#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>

#define long long long
#define nln '\n'

const long MAX = 7e6;

using namespace std;

int main()
{
	long n = MAX;
	cin >> n;
	vector<long> sqr{0};
	while (sqr.size()*sqr.size() <= n){
		sqr.push_back(sqr.size()*sqr.size());
	}

	vector<long> dp(n+1, MAX);
	dp[0] = 0;

	for (long i = 0; i <= n; ++i)
		for (long j = 1; j <= (long)sqrt(i); ++j)
			if (sqr[j] <= i)
				dp[i] = min(dp[i], dp[i-sqr[j]]+1);


	vector<long> res;

	while (n > 0){
		for (long i = (long)sqrt(n); i >= 1; --i)
			if (dp[n] == dp[n-sqr[i]]+1){
				res.push_back(i);
				n -= sqr[i];
				break;
			}
	}

	for (long i = res.size()-1; i > 0; --i)
		cout << res[i] << "^2 + ";
	cout << res[0] << "^2"1;

	return 0;
}