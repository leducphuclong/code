#include<iostream>
#include<vector>

#define long long long
#define nln '\n'

using namespace std;

long take(long r1, long c1, long r2, long c2, const vector<vector<long>> &psa)
{
	return psa[r2][c2] - psa[r2][c1-1] - psa[r1-1][c2] + psa[r1-1][c1-1];
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n, m;
	cin >> n >> m;
	vector<vector<long>> a(n+1);
	for (auto &i : a)
		i.resize(m+1, 0);
	vector<vector<long>> res = a;
	for (long i = 1 ; i <= n; ++i)
		for (long j = 1; j <= m; ++j){
			cin >> a[i][j];
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	for (long i = 1; i <= n; ++i)
		for (long j = 1; j <= m; ++j)
			for (long u = 1; u <= n-i+1; u++)
				for (long v = 1; v <= m-j+1; ++v)
					if (take(u, v, u+i-1, v+j-1, a) == 0)
						res[i][j]++;

	for (long i = 1; i <= n; ++i){
		for (long j = 1; j <= m; ++j)
			cout << res[i][j] << ' ';
		cout << nln;
	}

	return 0;	
}