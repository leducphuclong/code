#include<iostream>
#include<set>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	long m, n, k;
	cin >> m >> n >> k;
	set<long> col, row;
	while (k--){
		long x, y;
		cin >> x >> y;
		row.insert(x), col.insert(y);
	}
	cout << (m-row.size())*(n-col.size());
	return 0;
}