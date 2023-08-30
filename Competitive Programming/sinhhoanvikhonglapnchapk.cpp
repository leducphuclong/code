#include<iostream>
#include<vector>
#include<conio.h>

#define long long long
#define nln '\n'

using namespace std;

void init(vector<long> &a, long n, long k);
void gen(vector<long> &a, long n, long k);
void out(vector<long> &a, long n, long k);
bool is_last(vector<long> &a, long n, long k);
void method(vector<long> &a, long n, long k);

int main()
{
	long n, k;
	cin >> n >> k;
	vector<long> a(k+1, 0);
	method(a, n, k);
	return 0;
}

void init(vector<long> &a, long n, long k)
{
	for (long i = 1; i <= k; ++i)
		a[i] = i;
}

void out(vector<long> &a, long n, long k)
{
	for (long i = 1; i <= k; ++i)
		cout << a[i] << ' ';
	cout << nln;
}

bool is_last(vector<long> &a, long n, long k)
{
	for (long i = 1; i <= k; ++i)
		if (a[i] < i+(n-k))
			return 0;
	return 1;
}

void gen(vector<long> &a, long n, long k)
{
	long i = k;
	while (a[i] == i+(n-k) and i > 0){
		i--;
	}
	a[i]++;
	for (long j = i+1; j <= k; ++j)
		a[j] = a[j-1]+1;
}

void method(vector<long> &a, long n, long k)
{
	init(a, n, k);
	bool stop = is_last(a, n, k);
	int cnt = 0;
	while (!stop){
		out(a, n, k);
		stop = is_last(a, n, k);
		gen(a, n, k);
		++cnt;
	}
	cout << "so luong: " << cnt << nln;
}