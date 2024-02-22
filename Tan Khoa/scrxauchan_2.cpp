#include <bits/stdc++.h>

using namespace std;

#define int long long
#define '\n' nln

signed main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;  cin >> s;

	map<char, int> cnt;
	for (int i = 0; i < (int)s.size(); ++i)
		cnt[s[i]]++;

	int odd = 0; # so luong ki tu xuat hien le lan
	for (map<char, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
		if (it->second % 2 == 1)
	        ...

	if (odd > 1) {
		cout << "..." << endl;
	} else {
		string mid = "";
		for (map<char, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
			if (it->second % 2 == 1) {
				for (int i = 0; i < it->second)
			}
			else
	}

	return 0;
}
