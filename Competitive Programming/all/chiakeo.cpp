#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

#define long long long
#define nln '\n'

const long INF = LLONG_MAX;

using namespace std;

int main()
{
	// Input
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	//freopen("chiakeo.inp", "r", stdin);
	long T = 1;
	cin >> T;
	while (T--){
		long n;
		cin >> n;
		vector<long> a(n);
		long sum = 0;
		for (auto &i : a){
			cin >> i;
			sum += i;
		}
		// Dynamic planning
		vector<long> sav(sum/2+1, INF);
		sav[0] = -1;
		for (long i = 1; i <= sum/2; ++i){
			for (long j = 0; j < n; ++j)
				if (i >= a[j] && sav[i-a[j]] < j){
					sav[i] = j;
					break;
				}
		}
		// Trace
		vector<bool> tic(n+1, 0);
		long res = 0;
		long m = sum/2;
		while (m > 0){
			if (sav[m] == INF){
				--m;
				continue;
			}
			tic[sav[m]] = 1;
			res += a[sav[m]];
			m -= a[sav[m]];
		}
		// Output
		cout << sum-2*res << nln;	
		/*for (long i = 0; i < n; ++i)
			if (!tic[i])
				cout << a[i] << ' ';
		cout << nln;
		for (long i = 0; i < n; ++i)
			if (tic[i])
				cout << a[i] << ' ';*/
	}

	return 0;
}