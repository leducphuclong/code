#include<iostream>

#define long long long
#define nln '\n'

using namespace std;

long n, cnt = 0;
int b[100];


void rc(long i)
{
	if (i > n){
		++cnt;
		for (long j = 1; j <= n; ++j)
			cout << b[j] << ' ';
		cout << nln;
		return;
	}
	b[i] = 0;
	rc(i+1);
	b[i] = 1;
	rc(i+1);
}

int main()
{
	cin >> n;
	for (long i = 1; i <= n; ++i)
		b[i] = 0;
	rc(1);
	cout << "qtt: " << cnt << nln;
	return 0;
}