#include<iostream>

#define long long
#define nln '\n'

using namespace std;

void rv(string &n, long l, long r)
{
	if (l > r)
		return;
	char tmp = n[l];
	n[l] = n[r];
	n[r] = tmp;
	rv(n, l+1, r-1);
}

int main()
{
	string n;
	cin >> n;
	rv(n, 0, n.size()-1);
	cout << n << nln;
	return 0;
}