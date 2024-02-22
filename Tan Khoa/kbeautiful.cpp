#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define nln '\n'

void solve() {
	ll n;	cin >> n;
	ll a[n+1];
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	ll dis[n+1], pos[n+1];
	memset(dis, -1, sizeof dis);
	memset(pos, 0, sizeof pos);
	for (int i = 1; i <= n; ++i) {
		dis[a[i]] = max(dis[a[i]], i - pos[a[i]]);
		pos[a[i]] = i;
	}

	for (int i = 1; i <= n; ++i)
		dis[i] = max(dis[i], n-pos[i]+1);

	ll val[n+1];
	memset(val, -1, sizeof val);
	for (ll i = 1; i <= n; ++i) {
		if (dis[i] != -1) {
			if (val[dis[i]] == -1)
				val[dis[i]] = i;
			else
				val[dis[i]] = min(val[dis[i]], i);
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (val[i-1] != -1) {
			if (val[i] == -1)
				val[i] = val[i-1];
			else
				val[i] = min(val[i], val[i-1]);
		}
		cout << val[i] << ' ';
	}
	cout << nln;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll tc;	cin >> tc;
	while (tc--) {
		solve();
	}

	return 0;
}