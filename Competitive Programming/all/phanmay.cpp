#include<iostream>
#include<algorithm>
#include<vector>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	freopen("phanmay.inp", "r", stdin);
	freopen("phanmay.out", "w", stdout);
	long n, m;
	cin >> n >> m;
	vector<pair<long, long>> a(n);
	for (long i = 1; i <= n; ++i){
		cin >> a[i-1].first;
		a[i-1].second = i;
	}
	vector<pair<long, long>> b(m);
	for (long i = 1; i <= m; ++i){
		cin >> b[i-1].first;
		b[i-1].second = i;
	} 

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<pair<long, long>> res;
	vector<bool> pic(m+1, 0);
	for (auto i : a)
		for (auto j : b)
			if (j.first >= i.first+1 && !pic[j.second]){
				pic[j.second] = 1;
				res.push_back({i.second, j.second});
				break;
			}

	cout << res.size();

	return 0;
}