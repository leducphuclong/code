// Copyright (c) 2024, Le Duc Phuc Long

/*If you don't think twice, you have to code twice.*/

// Include
#include <bits/stdc++.h>
// #include <conio.h>

// Namespace
using namespace std;

// Define
#define nln '\n'

// Typedef and Struct
typedef int64_t ll;

// Constant

// Declare global variables.
vector<pair<ll, ll>> dir4 = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
// End of global variable declaration.

void precompute() {
	
}

ll getAns(ll n) {
	ll ans = 0;
	ans += n/15;
	n %= 15;
	ans += n/6;
	n %= 6;
	ans += n/3;
	n %= 3;
	ans += n;
	return ans;
}

void solve() {
	ll n; cin >> n;
	if (n < 10) {
		cout << getAns(n) << nln;
	} else if (n < 20) {
		cout << min(getAns(n), getAns(n-10) + 1) << nln;
	} else {
		ll ans = getAns(n);
		ans = min(ans, getAns(n-10)+1);
		ans = min(ans, getAns(n-20)+2);
		cout << ans << nln;
	}
}

int main(int argc, char* argv[]) {
	#ifndef ONLINE_JUDGE
	// freopen("in", "r", stdin);
	#endif // ONLINE_JUDGE
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	int T = 1;
	cin >> T;
	precompute();
	while (T--) {
		solve();
	}
	cerr << "It's ok Long, Good for now !!" << nln;
	return 0;
}