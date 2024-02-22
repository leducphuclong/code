#include<iostream>
#include<vector>
#include<map>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("sum.inp", "r", stdin);
	freopen("sum.out", "w", stdout);
	long n;
	cin >> n;
	vector<vector<long>> a;
	a.resize(n);
	for (long i = 0; i < n; ++i){
		a[i].resize(n, 0);
		for (long j = 0; j < n; ++j)
			cin >> a[i][j];
	}
	map<long, long> sum;
	for (long i = 0; i < n; ++i)
		for (long j = 0; j < n; ++j)
			sum[i-j] += a[i][j];

	long res = LLONG_MIN;
	for (auto i : sum)
		res = (i.second > res) ? i.second : res;
	cout << res << nln;
	return 0;
}