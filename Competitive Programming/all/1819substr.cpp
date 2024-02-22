#include <bits/stdc++.h>

using namespace std;

#define int long long
#define nln '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int k;	cin >> k;
	cin.ignore();
	string s; 
	getline(cin, s);

	map<int, int> cnt;

	int ones = 0;
	cnt[ones] = 1;
	for (int i = 0; i < (int)s.size(); ++i)
		if (s[i] == '0')
			cnt[ones]++;
		else
			ones++, cnt[ones] = 1;

	for (int i = 0; i < ones; ++i)
		...


    return 0;
}