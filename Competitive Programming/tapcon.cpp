#include<iostream>
#include<vector>

#define long long long
#define nln '\n'

using namespace std;

long cnt = 0;

void enter(vector<long> &a, long &n);
void print(vector<long> &a, vector<bool> &b, long n);
void rc(vector<long> &a, vector<bool> &b, long n, long i);

int main()
{
	long n;
	vector<long> a;
	enter(a, n);

	vector<bool> b(n+1, 1);
	rc(a, b, n, 1);
	cout << "Quantity: " << cnt << nln;
	return 0;
}

void enter(vector<long> &a, long &n)
{
	cin >> n;
	a.resize(n+1);
	for (long i = 1; i <= n; ++i)
		cin >> a[i];
}

void print(vector<long> &a, vector<bool> &b, long n)
{
	++cnt;
	for (long i = 1; i <= n; ++i)
		if (b[i])
			cout << a[i] << ' ';
	cout << nln;
}

void rc(vector<long> &a, vector<bool> &b, long n, long i)
{
	if (i > n){
		print(a, b, n);
		return;
	}
	rc(a, b, n, i+1);
	b[i]= 0;
	rc(a, b, n, i+1);
	b[i] = 1;
}	