#include<iostream>
#include<vector>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n, m, q;
	cin >> n >> m >> q;
	vector<vector<long>> a(n+1);
	for (auto &i : a)
		i.resize(n+1, 0);

	vector<pair<long, long>> e(m+1);	
	for (long i = 1; i <= m; ++i){
		long cap;
		cin >> e[i].first >> e[i].second >> cap;
		a[e[i].first][e[i].second] = cap;
	}

	for (long i = 1; i <= q; ++i){
		char req;
		cin >> req;
		if (req == 'C'){
			long r, x;
			cin >> r >> x;
			a[e[r].first][e[r].second] = x;
		}
		else{	
			long x, y, w;
			cin >> x >> y >> w;
			if (a[x][y] >= w)
				cout << "YES" << nln;
			else
				cout << "NO" << nln;
		}
	}
	return 0;
}