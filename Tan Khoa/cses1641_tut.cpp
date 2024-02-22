#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	
	ll n, s;
	cin >> n >> s;
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	vector<pair<int, int>> elm; // elm.first = value, elm.second = index;
	for (int i = 0; i < n; ++i)
		elm.push_back(make_pair(arr[i], i));

	sort(elm.begin(), elm.end());
	
	# Tim bo 3: a + b + c == s
	# ia la con tro cua so a
	# ib la con tro cua so b
	# ic la con tro cua so c
	
	for (int ia = 0; ia < ...; ia++) {
		int ib = ia+1, ic = n-1;
		int a = elm[ia].first;
		int b = ..., c = ...;
		while (...) {
			if (a + b + c < s) {
				ib++;
				b = elm[ib].first;
			} else if (a + b + c > s) {
				...
				...
			} else { // a + b + c == s
				cout << elm[ia].second << ' ' << ....;
				...
			}
		}
	}
	
 	cout << "IMPOSSIBLE" << nln;
	
	return 0;
}
