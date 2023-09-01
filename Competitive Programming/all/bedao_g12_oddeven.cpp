#include<iostream>
#include<vector>

#define long long long 
#define nln '\n'

using namespace std;

bool odd(long x)
{
	if (x % 2 == 1)
		return 1;
	return 0;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	long n;
	cin >> n;
	long le = 0, t = 0, cnt = 0, i = 0, run = n;
	while (run--){
		long x;
		cin >> x;
		if (odd(x)){
			cnt += abs(i-t);
			le++;
			t += 2;
		}
		++i;
	}
	if (le - (n-le) <= 1 && le - (n-le) >= 0)
		cout << cnt << nln;
	else
		cout << -1 << nln;	
	return 0;
}