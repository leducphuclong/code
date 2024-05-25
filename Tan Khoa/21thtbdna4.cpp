// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0)->sync_with_stdio(0);
    ll n, m; int k;
	cin >> n >> k >> m;
	ll g = n / k + 1;
	if (m < g) {
		cout << m*k;
	} else {
		if (n % k == 0)
			m -= 1, g -= 1;
		cout << m/g + m%g*k;
	}
    return 0;
}