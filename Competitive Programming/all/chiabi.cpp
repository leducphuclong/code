#include<iostream>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	//freopen("chiabi.inp", "r", stdin);
	long n, m, M;
	cin >> n >> m >> M;
	long res = 0;
	while (--m){
	for (long i = 0; i <= n; ++i)
		for (long j = i; j <= n-i; ++j)
			if (n-i-j >= j){
				++res;
				if (res > M)
					res -= M;
			}
	cout << res << nln;
	return 0;
}