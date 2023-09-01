#include<iostream>
#include<vector>

#define long long
#define nln '\n'

using namespace std;

long n, m, cnt = 0;
vector<vector<char>> a;
vector<vector<long>> p;

void dfs(long x, long y)
{
	for (long i = x-1; i <= x+1; ++i)
		for (long j = y-1; j <= y+1; ++j)
			if (i > 0 && j > 0 && i <= n && j <= m && !p[i][j] && a[i][j] == 'W'){
				p[i][j] = cnt;
				dfs(i, j);
			}
}

int main()
{	
	cin.tie(0)->sync_with_stdio(0);
	//freopen("garden.inp", "r", stdin);
	cin >> n >> m;
	a.resize(n+1);
	p.resize(n+1);
	for (long i = 1; i <= n; ++i){
		a[i].resize(m+1);
		p[i].resize(m+1, 0);
		string str;
		cin.ignore();
		cin >> str;
		for (long j = 1; j <= m; ++j)
			a[i][j] = str[j-1];
	}

	for (long i = 1; i <= n; ++i)
		for (long j = 1; j <= m ; ++j)
			if (a[i][j] == 'W' && !p[i][j]){
				++cnt;
				dfs(i, j);
			}

	cout << cnt << nln;

	return 0;
}