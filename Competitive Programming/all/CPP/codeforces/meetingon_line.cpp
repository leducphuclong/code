#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<set>
#include<iomanip>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	freopen("meetingon_line.inp", "r", stdin);
	long T;
	cin >> T;
	while (T--){
		long n;
		cin >> n;
		vector<long> x(n+1, 0);
		set<long> cnt;`
		for (long i = 1; i <= n; ++i){
			cin >> x[i];
			cnt.insert(x[i]);
		}
		vector<long> t(n+1, 0);
		bool zro = 1;
		for (long i = 1; i <= n; ++i){
			cin >> t[i];
			if (t[i])
				zro = 0;
		}
		double res;
		// In case all t is zero
		if (zro){
			res = 0;
			for (long i = 1; i <= n; ++i)
				res += x[i];
			res /= n;
		}
		// In case t have at least a number different with zero
		if (!zro){
			long mav = LLONG_MIN, sav = 0;
			for (long i = 1; i <= n; ++i)
				if (t[i] > mav){
					mav = t[i];
					sav = i;
				}
			res = sav;
		}
		// If one person
		if (n == 1)
			res = x[n];
		if (cnt.size() == 1)
			res = x[1];
		cout << setprecision(6) << res << nln;
	}
	return 0;
}