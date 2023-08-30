#include<iostream>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long T;
	cin >> T;
	while (T--){
		long x;
		cin >> x;
		bool check = 0;
		for (long i = 1; i*i*i <= x; ++i)
			if (i*i*i == x){
				check = 1;
			}
		if (check == 1)
			cout << "YES" << nln;
		else
			cout << "NO" << nln;
	}
	return 0;
}