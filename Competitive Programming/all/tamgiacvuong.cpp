#include<iostream>
#include<vector>

#define long long long
#define nln '\n'

using namespace std;

long sqr(long x)
{
	return x*x;
}

long dist(pair<long, long> a, pair<long, long> b)
{
	return sqr(a.first-b.first) + sqr(a.second-b.second);
}

bool pytago(long a, long b, long c)
{
	return a + b == c || a + c == b || b + c == a;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n;
	cin >> n;
	vector<pair<long, long>> pnt(n);
	for (auto &i : pnt)
		cin >> i.first >> i.second;

	long res = 0;
	for (long i = 0; i < n-2; ++i)
		for (long j = i+1; j < n-1; ++j)
			for (long k = j+1; k < n; ++k){
				long a = dist(pnt[i], pnt[j]);
				long b = dist(pnt[i], pnt[k]);
				long c = dist(pnt[j], pnt[k]);
				if (pytago(a, b, c))
					++res;
			}

	cout << res;

	return 0;
}