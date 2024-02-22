	#include <bits/stdc++.h>

	using namespace std;

	typedef long long ll;
	#define nln '\n'

	void solve() {
		// Input
		ll n, m, k;	cin >> n >> m >> k;
		ll arr[n+1][m+1];
		for (int i = 1; i <= n; ++i) {
			string s;	cin >> s;
			for (int j = 1; j <= m; ++j)
				arr[i][j] = (s[j-1] == 'A') ? 1 : -1;
		}

		// Solve
		ll pfs[n+1][m+1];
		memset(pfs, 0, sizeof pfs);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				pfs[i][j] = pfs[i-1][j] + pfs[i][j-1] - pfs[i-1][j-1] + arr[i][j];	

		int res = 0;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				if ((n-i+1)*(m-j+1) <= res)
					break;
				for (int u = n; u >= i; --u)
					for (int v = m; v >= j; --v) {
						if ((u-i+1)*(v-j+1) <= res)
							break;
						ll t = abs(pfs[u][v] - pfs[u][j-1] - pfs[i-1][v] + pfs[i-1][j-1]);
						if (t <= k)
							res = max(res, (u-i+1)*(v-j+1));
					}
			}
		cout << res << nln;
	}

	int main() {
		cin.tie(0)->sync_with_stdio(0);
		ll tc;	cin >> tc;
		while (tc--) {
			solve();
		}

		return 0;
	}