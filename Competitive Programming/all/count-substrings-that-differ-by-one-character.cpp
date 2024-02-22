#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define nln '\n'

vector<string> substrings(string s) {
	vector<string> res;
	int n = s.size();
	for (int i = 1; i <= n; ++i)
		for (int left = 0; left <= n-i; ++left) {
			res.push_back("");
			for (int k = left; k < left+i; ++k)
				res.back().push_back(s[k]);
		}
	return res;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	map<string, int> cnt;
	for (auto s : substrings(s1))
		for (int i = 0; i < static_cast<int>(s.size()); ++i) {
			string tmp = s;
			tmp.erase(tmp.begin()+i);
			cnt[tmp]++;
		}

	ll ans = 0;
	for (auto s : substrings(s2)) {
		cout << " ----------------- " << nln;
		cout << s << " ~ " << cnt[s] << nln;
		for (int i = 0; i < static_cast<int>(s.size()); ++i) {
			string tmp = s;
			tmp.erase(tmp.begin()+i);
			cout << tmp << " ~ " << cnt[tmp] << nln;
			ans += cnt[tmp];
		}
	}

	cout << ans << nln;

	return 0;
}