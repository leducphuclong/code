#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

#define int long long
#define nln '\n'

int sum(int left, int right) {
    return (right - left + 1) * (left + right) / 2;
}

signed main() {
	// cin.tie(0)->sync_with_stdio(0);

	int n;	cin >> n;

	int l = 1, r = n;
	while (l < r) {
		int m = (l+r)>>1;
		if (sum(1, m) >= n)
			r = m;
		else
			l = m+1;
	}

	cout << r << nln;

	return 0;
}