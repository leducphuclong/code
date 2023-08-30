#include<iostream>
#include<vector>
#include<algorithm>

#define long long long
#define nln '\n'

using namespace std;

void enter(vector <long> &a, long &n);
void init(vector<long> &a, long n);
void gen(vector<long> &a, long n);
void out(vector<long> &b, vector<long> &a, long n);
bool is_last(vector<long> &a, long n);
void method(vector<long> &b, vector<long> &a, long n);

int main()
{
	vector<long> b;
	long n;
	enter(b, n);
	vector<long> a(n+1);
	method(b, a, n);
	return 0;
}

void enter(vector<long> &a, long &n)
{
	cin >> n;
	a.resize(n+1, 0);
	for (long i = 1; i <= n; ++i)
		cin >> a[i];
}
void init(vector<long> &a, long n)
{
	for (long i = 1; i <= n; ++i)
		a[i] = i;
}
void out(vector<long> &b, vector<long> &a, long n)
{
	for (long i = 1; i <= n; ++i)
		cout << b[a[i]] << ' ';
	cout << nln;
}
bool is_last(vector<long> &a, long n)
{
	for (long i = 1; i <= n; ++i)
		if (a[i] < n-i+1)
			return 0;
	return 1;
}
void gen(vector<long> &a, long n)
{
	long i = n-1;
	while (a[i] > a[i+1] and i > 1)
		i--;
	long j = n;
	while (a[i] > a[j] and j > 0)
		j--;
	swap(a[i], a[j]);
	reverse(a.begin()+i+1, a.end());
}
void method(vector<long> &b, vector<long> &a, long n)
{
	init(a, n);
	bool stop = is_last(a, n);
	long i = 1; 
	while (!stop){
		i++;
		out(b, a, n);
		stop = is_last(a, n);
		gen(a, n);
	}
}