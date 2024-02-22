#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll n, s;
	cin >> n >> s;
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
		
	vector<pair<ll, ll>> elm; // elements : phan tu
	for (int i = 0; i < n; ++i)
		elm.push_back(make_pair(arr[i], i+1));

	// sap xep elm tang dan
	sort(elm.begin(), elm.end());
	
	// Tim bo 3 so: a + b + c == s
	// ia: con tro chi vao so a
	// ib: ...
	// ic: ...
	
	for (int ia = 0; ia < n-2; ia++) {
		ll a = elm[ia].first;
		ll ib = ia + 1, ic = ...;
		ll b = ..., c = ...;
		while (ib < ic) {
			if (a + b + c < s) {
				...;
				b = elm[ib].first;
			} else if (a + b + c > s) {
				...;
				...;
			} else { // ok
				cout << elm[ia].second << ' ' << ...;
				return 0;
			}
		}
	}
	
	cout << "IMPOSSIBLE" << nln;
	
	return 0;
}
