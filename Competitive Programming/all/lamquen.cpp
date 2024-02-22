#include<iostream>
#include<vector>
#include<set>

#define long long long
#define nln '\n'

using namespace std;

void show(long n, const vector<long> &a)
{
	for (long i = 1; i <= n; ++i)
		cout << a[i] << ' ';
	cout << nln;
}

void rc(long ps, const vector<set<long>> &mat, vector<long> &flg, long cnt, long &qlt)
{
	flg[ps] = cnt;
	for (auto nps : mat[ps])
		if (!flg[nps])
			rc(nps, mat, flg, cnt, ++qlt);
}

int main()
{
	// Input
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	long n;
	cin >> n;
	vector<set<long>> mat(n+1);
	for (long i = 1; i <= n-1; ++i)
		for (long j = 1; j <= n; ++j){
			bool x;
			cin >> x;
			if (x){
				mat[i].insert(j);
				mat[j].insert(i);
			}
		}
	// Thuật toán thuần DFS
	vector<long> flg(n+1, 0);
	long cnt = 0, mav = 0;
	for (long i = 1; i <= n; ++i)
		if (!flg[i]){
			long qlt = 1;
			rc(i, mat, flg, ++cnt, qlt);
			mav = (qlt > mav) ? qlt : mav;
		}
	cout << cnt << nln << mav << nln;
	return 0;
}