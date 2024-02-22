#include <bits/stdc++.h>

using namespace std;

#define int long long
#define nln '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	
    string s;  cin >> s;
    int k;  cin >> k;
    
    set<char> sav;
    for (int i = 0; i < (int)s.size(); ++i)
		sav.insert(s[i]);

	int diff = sav.size();
	if (diff >= k)
	   cout << 0 << nln;
	else {
		if (s.size() < k)
		    cout << "impossible" << nln;
		else
			cout << k - diff << nln;
	}
	
	return 0;
}
