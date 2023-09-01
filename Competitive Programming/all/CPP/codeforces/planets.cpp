#include<iostream>
#include<vector>
#include<algorithm>

#define long long long 
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	//freopen("planets.inp", "r", stdin);
	long T;
	cin >> T;
	while (T--){
		long n, c;
		cin >> n >> c;
		vector<long> a(101, 0);
		for (long i = 1; i <= n; ++i){
			long x;
			cin >> x;
			a[x]++;
		}
		long res = 0;
		for (long i = 1; i <= 100; ++i)
			res += min(a[i], c);
		cout << res << nln;
	}
	return 0;
}