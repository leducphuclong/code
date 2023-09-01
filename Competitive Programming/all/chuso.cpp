#include<iostream>
#include<algorithm>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	freopen("chuso.inp", "r", stdin);
	freopen("chuso.out", "w", stdout);
	string str;
	getline(cin, str, nln);
	long n, m;
	cin >> n >> m;
	for (long i = 0; i < n; ++i){
		string tmp = str;
		reverse(tmp.begin(), tmp.end());
		str += tmp;
	}
	
	if (m > str.size())
		cout << -1 << nln;
	else
		cout << str[m-1] << nln;

	return 0;
}