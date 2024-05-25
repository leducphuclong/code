#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;	cin >> s;
	ll ans = 0;

	ll left = 0, right = s.size()-1;
	while (left <= right) {
		ll mid = (left+right)/2;
		if (s[mid] == '1') {
			right = mid-1;
		} else {
			if (s[mid+1] == '1') {
				ans = mid+1;
				break;
			} else {
				left = mid+1;
			}
		}
	}

	cout << ans;

	return 0;
}
