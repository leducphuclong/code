#include<iostream>
#include<vector>

#define long long long
#define nln '\n'

using namespace std;

long res = 0;
void build(const vector<vector<long>> &mtx, vector<bool> &put, long n, long qlt, long i, long cnt)
{
	if (res)
		return;

	if (i > n || qlt == 0){
		bool ok = 1;
		for (long j = 1; j <= n; ++j){
			if (put[j])
				continue;
			bool cnt = 0;
			for (auto k : mtx[j])
				if (put[k]){
					cnt = 1;
					break;
				}
			if (!cnt){
				ok = 0;
				break;
			}
		}
		if (ok){
			res = cnt;
		}
		return;
	}

	put[i] = 1;
	build(mtx, put, n, qlt-1, i+1, cnt+1);
	put[i] = 0;
	if (qlt >= n-i)
		return;
	build(mtx, put, n, qlt, i+1, cnt);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	//freopen("ttbh.inp", "r", stdin);
	long n, m;
	cin >> n >> m;
	vector<vector<long>> mtx(n+1);
	for (long i = 0; i < m; ++i){
		long x, y;
		cin >> x >> y;
		mtx[x].push_back(y);
		mtx[y].push_back(x);
	}

	vector<bool> put(n+1, 0);
	for (long qlt = 1; qlt <= n; ++qlt){
		build(mtx, put, n, qlt, 1, 0);
		if (res)
			break;
	}

	cout << res << nln;

	return 0;
}
