#include<iostream>
#include<vector>
#include<algorithm>
#include<conio.h>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	//cin.tie(0)->sync_with_stdio(0);
	long n, dem = 0;
	cin >> n;
	vector<long> a(n+1);
	for (long i = n; i >= 1; --i)
		a[i] = n-i+1;
	bool stop = 0;
	while (!stop){
		++dem;
		// print
		cout << "dem: " << dem << nln;
		for (long i = 1; i <= n; ++i)
			cout << a[i] << ' ';
		cout << nln;
		// generate
		long i = n-1;
		while (i > 0 && a[i] < a[i+1])
			i--;
		if (i == 0)
			break;
		long j = n;
		while (a[i] < a[j])
			--j;
		swap(a[i], a[j]);
		reverse(a.begin()+i+1, a.end());
	}
	return 0;
}