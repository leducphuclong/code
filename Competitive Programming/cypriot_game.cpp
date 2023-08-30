#include<iostream>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n;
	cin >> n;
	if (!(n % 2)){
		cout << n/2 << nln;
		cout << n/2*n/2*2 << nln;
		cout << n/2 << nln;
	}
	else{
		cout << n/2+1 << nln;
		cout << n/2*(n/2+1) << nln;
		cout << n/2 << nln;
	}
	return 0;
}