#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	string s;
 	getline(cin, s);  // stdin = standard input, stdout
	
	// Dem so lan xuat hien cua cac phan tu
	map<char, int> cnt;
	for (int i = 0; i < static_cast<int>(s.size()); ++i)
		...

	ll le = 0;
    for (map<char, int>::iterator it = cnt.begin(), it != cnt.end(); ++it) {
    	if (it->second % 2)
		   le++;
	}
	if (...) {
		cout << "NO SOLUTION";
		return 0;
	}
	// Xay dung xau palindrome
	string left = "", mid = "";
	for (map<char, int>::iterator it = cnt.begin(), it != cnt.end(); ++it) {
		if (it->second % 2) {
			for (int i = 0; i < ...; ++i)
				mid += ...
		} else {
			for (int i = 0; i < ...; ++i)
				left += ...
		}
	}
	
	string right = left;
	reverse(right.begin(), right.end());
	
	cout << ...
	
	return 0;
}
