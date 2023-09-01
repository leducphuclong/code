#include<iostream>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	freopen("tinhtien.inp", "r", stdin);
	long sum = 0;
	long x;
	while (cin >> x)
		sum += x;
	cout << sum << nln;
	return 0;
}