#include<iostream>
#include<cmath>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n;
	cin >> n;
	bool check = 1;
	for (long i = 2; i <= round(sqrt(n)); ++i)
		if (!(n % i))
			check = 0;
	if (n < 2)
		check = 0;
	if (check)
		cout << "YES" << nln;
	else
		cout << "NO" << nln;
	return 0;
}