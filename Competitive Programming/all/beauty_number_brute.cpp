#include<iostream>

#define long long long
#define nln '\n'

using namespace std;

long mul(long x)
{
	long m = 1;
	while (x > 0)
		m *= x%10, x /= 10;
	return m;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	//freopen("beauty_number.inp", "r", stdin);
	//freopen("beauty_number.ans", "w", stdout);
	long l, r;
	cin >> l >> r;
	long mav = 0, res;
	for (long i = l; i <= r; ++i)
		if (mul(i) > mav){
			mav = mul(i);
			res = i;
		}
	cout << res << nln;
	return 0;
	cout << mav << nln;
	return 0;
}