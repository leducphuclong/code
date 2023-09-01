#include<iostream>
#include<vector>
#include<map>
#include<climits>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	freopen("ngamhoa.inp", "r", stdin);
	long n;
	cin >> n;
	vector<long> a(n+1, 0), b(n+1, 0);
	vector<long> pfs(n+1, 0);
	map<long, bool> sav;
	for (long i = 1; i <= n; ++i){
		cin >> a[i];
		pfs[i] = pfs[i-1];
		if (!sav[a[i]])
			pfs[i]++, b[i] =;
		sav[a[i]] = 1;
	}
	
	//cout << pfs[4]-pfs[1]+1 << nln; // 1 -> 4

	long lef = 1, rig = n, res = -1;
	while (lef <= rig){
		long mid = (lef+rig)/2;
		bool check = 0;
		for (long i = 1; i <= n-mid+1; ++i)
			if (pfs[i+mid-1]-pfs[i]+1 == pfs[n]){
				check = 1;
				break;
			}
		if (check){
			res = mid;
			rig = mid-1;
		}
		else{
			lef = mid+1;
		}
	}

	cout << res << nln;

	return 0;
}