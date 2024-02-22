#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

int main() {
	cin.tie(0)->sync_with_stdio(0);

	const ll len = int(1e6) + 1;
	ll road[len];
	memset(road, 0, sizeof road);
	ll n;	cin >> n;
	while (n--) {
		ll l, r;	cin >> l >> r;
		road[l]++, road[r]--;
	}

	ll cnt = 0;
	bool cover[len];
	for (int i = 0; i < len; ++i) {
		cnt += road[i];
		if (cnt > 0)
			cover[i] = true;
		else
			cover[i] = false;
	}

	ll max_len = 0, cur = 0;
	for (int i = 0; i < len; ++i) {
		if (cover[i] == true) {
			cur++;
			max_len = max(max_len, cur);
		} else {
			cur = 0;
		}
	}

	cout << max_len << nln;

	return 0;
}