#include <bits/stdc++.h>

using namespace std;

#define nln '\n'

class Solution {
public:
	int check(string s1, string s2) {
		if (s1.size() != s2.size())
			return false;
		int cnt = 0;
		for (int i = 0; i < static_cast<int>(s1.size()); ++i)
			if (s1[i] != s2[i])
				cnt++;
		return cnt == 1;
	}
    int countSubstrings(string s, string t) {        
    	map<string, int> ms, mt;

    	int n = s.size(), k = min(s.size(), t.size());

    	for (int i = 0; i < n; ++i) {
    		string sub = "";
    		for (int j = i; (j-1+1) <= k && j < n; ++j) {
    			sub += s[j];
    			ms[sub]++;
    		}
    	}

    	int m = t.size();
    	for (int i = 0; i < m; ++i) {
    		string sub = "";
    		for (int j = i; (j-i+1) <= k && j < m ; ++j) {
    			sub += t[j];
    			mt[sub]++;
    		}
    	}

    	int res = 0;
    	for (auto &ss : ms)
    		for (auto &st : mt)
    			if (check(ss.first, st.first))
    				res += ss.second*st.second;
    	return res;
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s, t;
	cin >> s >> t;

	Solution S;

	cout << S.countSubstrings(s, t) << nln;

	return 0;
}