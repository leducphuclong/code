#include<iostream>
#include<vector>

#define long long long
#define nln '\n'

using namespace std;

void rc(long r, long c, long n, long m, vector<vector<long>> &a, long cnt)
{
	a[r][c] = cnt;
	for (long i = r-1; i <= r+1; ++i)
		for (long j = c-1; j <= c+1; ++j)
			if (!a[i][j] && (i == r || j == c) && (i != r || j != c))
				rc(i, j, n, m, a, cnt);
}

void showa(long n, long m, const vector<vector<long>> &a)
{
	for (long i = 1; i <= n; ++i){
		for (long j = 1; j <= m; ++j)
			cout << a[i][j] << ' ';
		cout << nln;
	}
}

int main()
{
	// Input
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	long n, m;
	cin >> n >> m;
	vector<vector<long>> a(n+2, vector<long> (m+2, 1));
	for (long i = 1; i <= n; ++i)
		for (long j = 1; j <= m; ++j)
			cin >> a[i][j];
	// Thuật toán tương tự DFS	
	long cnt = 1;
	for (long i = 1; i <= n; ++i)
		for (long j = 1; j <= m; ++j)
			if (!a[i][j])
				rc(i, j, n, m, a, ++cnt);
	//showa(n, m, a);
	cout << cnt-1 << nln;
	//cout << "DONE" << nln;
	return 0;
}