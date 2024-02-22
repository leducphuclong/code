#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define long long long
#define nln '\n'

using namespace std;

int main()
{
	//cin.tie(0)->sync_with_stdio(0);
	//freopen("atm.inp", "r", stdin);
	vector<long> mon{1, 5, 10, 50, 100, 500};
	map<long, long> qlt;
	for (auto i : mon)
		cin >> qlt[i];
	long x;
	cin >> x;

	long cnt = 0;
	while (x && mon.size()){
		long num = min(x/mon.back(), qlt[mon.back()]);
		cnt += num;
		x -= num*mon.back();
		mon.pop_back();
	}

	if (x)
		cout << -1 << nln;
	else
		cout << cnt << nln;

	return 0;
}