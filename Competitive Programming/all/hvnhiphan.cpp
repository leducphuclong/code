#include<iostream>
#include<cmath>
#include<vector>

#define long long long
#define nln '\n'

using namespace std;

bool is_square_number(long n)
{
	return (double)sqrt(n) == (long)sqrt(n);
}

long cnt = 0;

void rc(long i, long n, vector<long> a, vector<long> b)
{
	if (i > n){
		long mul = 1, zro = 1;
		for (long j = 1; j <= n; ++j)
			if (b[j]){
				zro = 0;
				mul *= a[j]; 
			}
		if (is_square_number(mul) && !zro)
			++cnt;
		return;
	}
	b[i] = 1;
	rc(i+1, n, a, b);
	b[i] = 0;
	rc(i+1, n, a, b);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n;
	cin >> n;
	vector<long> a(n+1, 0), b(n+1, 0);
	for (long i = 1; i <= n; ++i)
		cin >> a[i];
	rc(1, n, a, b);
	cout << cnt << nln;
	return 0;
}