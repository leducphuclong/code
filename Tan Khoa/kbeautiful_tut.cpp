#include <bits/stdc++.h>

using namespace std;

#define nln '\n'
typedef long long ll;

void solve() {
	ll n;    cin >> n;
	ll arr[n+1];
	for (ll i = 1; i <= n; ++i)
		cin >> arr[i];

	// dis[i] la khoang cach dai nhat ma gia tri i
	// xuat hien
	// gia tri trong mang di tu 1 -> n
	// tuc la phai co dis[1], dis[2], ... dis[n]
	
	vector<ll> dis(n+1, INT_MIN);
	vector<ll> pos(n+1, 0);
    for (ll i = 1; i <= n; ++i) {
    	// value la gia tri cua phan tu thu i
    	ll value = arr[i];
    	// i : vi tri hien tai cua value
    	// pos[value] : vi tri truoc do cua value
		// khoang cach giua 2 so value
		ll kc = i - pos[value];
		dis[value] = max(dis[value], kc);
		pos[value] = i;
	}
	
	for (ll value = 1; i <= n; ++i) {
		ll kc_cc = n - pos[value] + 1;
		dis[value] = max(dis[value], kc_cc);
	}

	// val[i] la gia tri nho nhat luon xuat hien trong
	// khoang i
	// dis[value] la khoang cach dai nhat ma vallue
	// xuat hien
	// cu dis[value] so la co mot so value
	vector<ll> val(n+1, INT_MAX);
	for (ll i = 1; i <=n; ++i) {
		ll value = arr[i];
		val[dis[value]] = min(val[dis[value]], value);
	}

    for (ll i = 1; i <= n; ++i)
		val[i] = min(val[i],  val[i-1]);

	for (ll i = 1; i <= n; ++i)
		if (val[i] == INT_MAX)
		    cout << -1 << ' ';
		else
			cout << val[i] << ' ';

	cout << nln;
	

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll tc;    cin >> tc;
	while (tc--) {
		solve();
	}
	return 0;
}
