#include<iostream>
using namespace std;

#define ll long long
#define YES cout << "YES\n"
#define NO cout << "NO\n"

ll a[31], coins[11] = {0, 1, 3, 6, 10, 15}, n, res;

void solve() {
	res = 1e18;
	
	cin >> n;
	res = n / 15 + a[n % 15];
	if (n > 15) res = min(res, n / 15 + a[n % 15 + 15] - 1);
	
	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);

	for (int i = 1; i <= 30; ++i) {
		a[i] = 1e18;
		for (int j = 1; j <= 5; ++j) {
			if (i - coins[j] < 0) break;
			a[i] = min(a[i], a[i - coins[j]]);
		}
		++a[i];
	}
	
//	for (int i = 1; i <= 30; ++i) cout << a[i] << " "; cout << "\n";

	ll tt; cin >> tt; while (tt--)
	solve();
    return 0;
}
