#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define nln '\n'

// Function to calculate fast exponentiation
int fastpow(int n, int m, int p) {
    int res = 1;
    while (m > 0) {
        n %= p;
        if (m & 1) {
            res = (res * n) % p;
        }
        m /= 2;
        n = (n * n) % p;
        
    }
    return res;
}

signed main() {
    // IO
	cin.tie(0)->sync_with_stdio(0);
    int x, y, n, m, k;
    cin >> x >> y >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    // Calculate x^i
    vector<int> xp(n, 1);
    for (int i = 1; i < n; ++i) {
        xp[i] = (xp[i - 1] * x) % k;
    }

    // Calculate ta
    int ta = 0;
    for (int i = 0; i < n; ++i) {
        ta += ((a[i] % k) * (xp[i] % k)) % k;
        ta %= k;
    }

    // Calculate tmp
    vector<int> tmp(m, 1);
    for (int i = 0; i < m; ++i) {
        tmp[i] = fastpow(ta, b[i], k);
    }

    // Calculate p
    vector<int> p(m + 1, 1);
    for (int i = m - 1; i >= 0; --i) {
        p[i] = (p[i + 1] * tmp[i]) % k;
    }

    // Special case
    if (ta == 0 && p[0] == 0) {
    	cout << 1 << '\n';
    	return 0;
    }

    // Calculate ans
    int ans = 1;
    for (int i = 0; i < m; ++i) {
        ans = (ans * p[i]) % k;
    }

    cout << ans << endl;
    cerr << "Program finished" << '\n';

    return 0;
}