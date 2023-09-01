#include<iostream>

#define long long long
#define nln '\n';

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n;
	cin >> n;
	long res = 1;
	for (long i = 2; i <= n; ++i)
		res *= i;
	cout << res << nln;
	return 0;
}