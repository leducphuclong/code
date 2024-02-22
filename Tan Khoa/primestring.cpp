#include <bits/stdc++.h>

using namespace std;

#define int long long 
#define nln '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);

	int tc;	cin >> tc;
	while (tc--) {
		string s; cin >> s;
		map<char, int> cnt;
		for (auto c : s)
			cnt[c]++;
		int q = 0;
		for (auto p : cnt)
			if (p.second == 1)
				q += 1;
		bool check = true;
		if (q < 2)
			check = false;
		for (int i = 2; i*i <= q; ++i)
			if (q % i == 0) {
				check = false;
				break;
			}
		if (check)
			cout << "YES" << nln;
		else
			cout << "NO" << nln;
	}

	return 0;
}