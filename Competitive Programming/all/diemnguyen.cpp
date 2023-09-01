#include<iostream>
#include<algorithm>

#define long long long
#define nln '\n'

using namespace std;

long gcd(long x, long y)
{
	if (y % x == 0)
		return x;
	return gcd(y, y%x);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	//freopen("diemnguyen.inp", "r", stdin);
	long x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	long a = y1-y2, b = x2-x1;
	long tmp = gcd(a, b);
	a /= tmp, b /= tmp;
	long c = -(x1*a+y1*b);
	long res = 0;
	for (long x = x1+1; x <= x2-1; ++x)
		if (-c-a*x >= min(y1, y2) && -c-a*x <= max(y1, y2))
			++res;
	cout << res << nln;
	return 0;
}