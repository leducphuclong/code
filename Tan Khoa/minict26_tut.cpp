#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

signed main() {
	int k;    cin >> k;
	string s; cin >> s;
	
	int cnt[int(1e6) + 5], one = 0; // so luong so 1
	cnt[one] = 1;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == '0'])
		    cnt[one]++;
		else
			one++,
			cnt[one] = 1;

	int ans = 0;   // so luong xau con thoa man
	for (int i = k; i <= one; i++)
		ans += cnt[i-k];

	cout << ans << nln;

    return 0;
}
