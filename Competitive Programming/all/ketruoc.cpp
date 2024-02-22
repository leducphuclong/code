#include<iostream>
#include<vector>
#include<algorithm>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	//cin.tie(0)->sync_with_stdio(0);
	freopen("ketruoc.inp", "r", stdin);
	long t;
	cin >> t;
	t++;
	while (t--){
		cout << t << nln;
		string str;
		getline(cin, str, nln);
		cout << str << nln;
		long n = str.size();
		vector<long> a(1, 0);
		for (auto i : str)
			a.push_back(i-'0');
		for (auto i : a)
			cout << i << ' ';
		cout << nln;
		// process
		long i = n-1;
		while (i > 0 && a[i] < a[i+1])
			i--;
		if (i == 0){
			cout << -1 << nln;
			//continue;
		}
		long j = n;
		while (a[i] < a[j])
			--j;
		swap(a[i], a[j]);
		reverse(a.begin()+i+1, a.end());
		// print result
		for (long i = 1; i <= n; ++i)
			cout << a[i] << nln;
		cout << nln;
	}
	return 0;
}