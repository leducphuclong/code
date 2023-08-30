#include<iostream>
#include<vector>

#define long int
#define nln '\n'

const long MAV = 1e7+1;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	freopen("DISCOUNT.inp", "r", stdin);
	freopen("DISCOUNT.out", "w", stdout);
	long n;
	cin >> n;
	if (n == 1){
		cout << 0 << nln;
		return 0;
	}
	vector<long> sav(MAV, 0);
	long mav = 0;
	for (long i = 0; i < n; ++i){
		long x;
		cin >> x;
		sav[x]++;
		if (x > mav)
			mav = x;
	}
	//----------------
	for (long i = mav; i >= 2; --i){
		long cnt = 0;
		for (long j = i; j <= mav;  j += i)
			cnt += sav[j];
		if (cnt > 1){
			cout << i << nln;
			return 0;
		}
	}

	return 0;
}	