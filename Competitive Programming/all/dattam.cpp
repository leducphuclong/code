#include<iostream>
#include<vector>
#include<climits>

#define long long long
#define nln '\n'

using namespace std;

void put(long idx, long n, vector<bool> &p, const vector<vector<long>> a, long cnt, long &res)
{
	if (idx > n){
		//check to take result
		bool chk = 1;
		for (long i = 1; i <= n; ++i){
			if (p[i])
				continue;
			chk = 0;
			for (auto j : a[i])
				if (p[j]){
					chk = 1;
					break;
				}
			if (!chk)
				break;
		}
		res = (chk && cnt < res) ? cnt : res;
		return;
	}
	put(idx+1, n, p, a, cnt, res);
	p[idx] = 1;
	put(idx+1, n, p, a, cnt+1, res);
	p[idx] = 0;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("dattam.inp", "r", stdin);
	freopen("dattam.out", "w", stdout);
	long n, m;
	cin >> n >> m;
	vector<vector<long>> a(n+1);
	for (long i = 0; i < m; ++i){
		long x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	vector<bool> p(n+1, 0);
	long res = n;
	put(1, n, p, a, 0, res);
	cout << res;
	return 0;
}