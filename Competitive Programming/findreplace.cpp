#include<iostream>

#define lo long long
#define nln '\n'

using namespace std;

int main()
{
	long T;
	cin >> T;
	while (T--){
		long n, q;
		cin >> n >> q;
		int a[n+1], b[n+1] = {0};
		for (int i = 0; i < n; ++i){
			cin >> a[i];
			b[i+1] = b[i] + a[i];
		}
		long sum = b[n];
		while (q--){
			long l, r, x;
			cin >> l >> r >> x;
			if ((sum-(b[r]-b[l-1])+x*(r-l+1)) % 2)
				cout << "YES";
			else
				cout << "NO";
			cout << nln;
		}
	}
	return 0;
}