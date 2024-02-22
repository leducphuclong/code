#include <bits/stdc++.h> 

using namespace std;

#define int long long
#define nln '\n'

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	
	string s;	
	cin >> s;
	int n;
	cin >> n;
	
	set<char> unq;
	for (string::iterator itr = s.begin(); itr < s.end(); itr++)
		unq.insert(*itr);
	
	if (unq.size() >= n)
	    cout << 0 << endl;
	else
		if (s.size() > n)
		    cout << n-unq.size() << nln;
		else
			cout << "impossible" << nln;

	
	return 0;
}
