#include<iostream>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long a, b, c;
	cin >> a >> b >> c;
	if (a % c == b % c)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}