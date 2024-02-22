#include<iostream>
#include<iomanip>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	double x;
	long n;
	cin >> x >> n;

	double sum = 1;
	for (long i = 1; i <= n; ++i){
		double s = 1;
		for (long j = 1; j <= i; ++j)
			s = s*x/j;
		sum += s;
	}

	cout << setprecision(2) << fixed << sum << nln;

	return 0;
}