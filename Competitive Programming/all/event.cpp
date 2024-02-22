#include<iostream>
#include<vector>
#include<algorithm>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0)
	long n, q;
	cin >> n >> q;
	vector<par> a(n+1, 0);
	 for (long i = 1; i <= n; ++i)
		 cin >> a[i];
	sort(a.begin()+1, a.end());

	return 0;
}